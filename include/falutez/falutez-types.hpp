#pragma once

#ifndef _UNIHEADER_BUILD_
#include <chrono>
#include <exec/task.hpp>
#include <sstream>
#include <stdexec/execution.hpp>
#include <string>
#endif

#include <falutez/falutez-http-status.hpp>
#include <falutez/falutez-types-headers.hpp>
#include <falutez/falutez-types-parameters.hpp>
#include <falutez/falutez-types-std.hpp>

namespace HTTP {

enum class METHOD {

  GET,
  POST,
  PUT,
  DELETE,
  PATCH,
  HEAD,
  OPTIONS,
  TRACE,
};

inline std::ostream &operator<<(std::ostream &os, METHOD const &method) {
  static constexpr auto method_names = std::array<std::string_view, 8>{
      "GET", "POST", "PUT", "DELETE", "PATCH", "HEAD", "OPTIONS", "TRACE"};
  assert(static_cast<int>(method) < method_names.size());
  os << method_names[static_cast<int>(method)];
  return os;
}

inline auto to_string(METHOD m) {
  ::std::ostringstream ost;
  ost << m;
  return ost.str();
}

struct Body {
  std::string content_type;

  std::string data;

  Body(std::string_view const &raw) { data = raw; }

  Body() = default;
};

/**
 * @brief Response - A pipelined request that may be:
 *  -  completed (body and headers are populated):
       -  status.is_errno() == false
       -  body.has_value() if status::operator bool() == true
          (even if body is empty)
       -  headers.has_value()
    -  errored (status.is_errno() == true)
       indicates a system-level error before the HTTP layer (e.g. caught
       exception or failed malloc)
 */
struct Response {
  const METHOD method;
  const std::string path;

  const std::chrono::system_clock::time_point init_time =
      std::chrono::system_clock::now();

  std::chrono::system_clock::time_point start_time;

  HTTP::STATUS status;
  std::optional<Headers> headers;
  std::optional<Body> body;

  std::chrono::system_clock::time_point end_time;

  operator bool() const {
    if (!status.error() && end_time.time_since_epoch().count() == 0)
      throw std::logic_error{std::format("{}:{}:{}: inconsistent state; timing "
                                         "metadata not set by implementation",
                                         __FILE__, __LINE__, __func__)};
    return !!status;
  }

  friend std::ostream &operator<<(std::ostream &os, Response const &req) {
    os << req.method << " " << req.path << " -> " << req.status;
    return os;
  }
};

// using Request = std::packaged_task<HTTP::expected<RequestInfo,
// HTTP::STATUS>>;

// using AsyncResponse = exec::task<HTTP::expected<Response, HTTP::STATUS>>;

struct AsyncResponse
    : public exec::task<HTTP::expected<Response, HTTP::STATUS>> {
  using exec::task<HTTP::expected<Response, HTTP::STATUS>>::task;

  AsyncResponse(exec::task<HTTP::expected<Response, HTTP::STATUS>> &&task)
      : exec::task<HTTP::expected<Response, HTTP::STATUS>>{std::move(task)} {}
};

/**
 * @brief RequestSpec - holds all the information needed to construct
 * requests
 * @note  holds non-owning references to parameters where possible
 */
struct RequestSpec {
  HTTP::METHOD method;
  std::string_view path;
  std::optional<Parameters> params;
  std::optional<Headers> headers;
  std::optional<Body> body;

  XSON::JSON to_json() const {
    auto json = XSON::JSON{};
    json["method"] = to_string(method);
    json["path"] = std::string{path};
    if (params.has_value())
      json["params"] = params.value().to_json();
    if (headers.has_value())
      json["headers"] = headers.value().to_json();
    if (body.has_value())
      json["body"] = body.value().data;
    return json;
  }

  friend std::ostream &operator<<(std::ostream &os, RequestSpec const &req) {
    os << req.to_json().dump().value_or("undefined");
    return os;
  }

  std::string str() const { return to_json().dump().value_or("undefined"); }
};

/**
 * @brief ClientImpl concept - all implementation should abide by the interface
 *        GenericClient is statically checked at compile time  against this
 *        concept to reduce the chance of definitions going out of sync
 */
template <typename TImpl>
concept ClientImpl = requires(TImpl impl) {
  // setters
  impl.set_base_url(std::string_view{});
  impl.set_timeout(std::chrono::milliseconds{});
  impl.set_keepalive(std::make_pair<bool, std::chrono::milliseconds>(
      true, std::chrono::milliseconds{1000}));
  impl.set_headers(Headers{});

  // getters
  { impl.base_url() } -> std::convertible_to<std::string_view>;
  { impl.timeout() } -> std::convertible_to<std::chrono::milliseconds>;
  {
    impl.keepalive()
  } -> std::convertible_to<std::pair<bool, std::chrono::milliseconds>>;
  { impl.headers() } -> std::convertible_to<Headers>;

  // requests
  impl.request(RequestSpec{});
};

} // namespace HTTP