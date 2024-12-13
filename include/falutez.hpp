// Auto-generated unified header
// Do not edit manually

#pragma once

#include <chrono>
#include <compare>
#include <concepts>
#include <cstdint>
#include <cstring>
#include <exec/task.hpp>
#include <expected>
#include <format>
#include <glaze/core/context.hpp>
#include <glaze/core/opts.hpp>
#include <glaze/core/read.hpp>
#include <glaze/glaze.hpp>
#include <glaze/json/json_t.hpp>
#include <glaze/json/ptr.hpp>
#include <glaze/util/expected.hpp>
#include <iostream>
#include <memory>
#include <nlohmann/json.hpp>
#include <restclient-cpp/connection.h>
#include <restclient-cpp/restclient.h>
#include <sstream>
#include <stdexec/execution.hpp>
#include <string>
#include <string_view>
#include <unordered_map>
#include <variant>


namespace HTTP {

struct STATUS {

  enum Code : int16_t {
    NONE,

    CONTINUE = 100,
    SWITCHING_PROTOCOLS = 101,
    PROCESSING = 102,
    EARLY_HINTS = 103,

    OK = 200,
    CREATED = 201,
    ACCEPTED = 202,
    NON_AUTHORITATIVE_INFORMATION = 203,
    NO_CONTENT = 204,
    RESET_CONTENT = 205,
    PARTIAL_CONTENT = 206,
    MULTI_STATUS = 207,
    ALREADY_REPORTED = 208,
    IM_USED = 226,

    MULTIPLE_CHOICES = 300,
    MOVED_PERMANENTLY = 301,
    FOUND = 302,
    SEE_OTHER = 303,
    NOT_MODIFIED = 304,
    USE_PROXY = 305,
    SWITCH_PROXY = 306,
    TEMPORARY_REDIRECT = 307,
    PERMANENT_REDIRECT = 308,

    BAD_REQUEST = 400,
    UNAUTHORIZED = 401,
    PAYMENT_REQUIRED = 402,
    FORBIDDEN = 403,
    NOT_FOUND = 404,
    METHOD_NOT_ALLOWED = 405,
    NOT_ACCEPTABLE = 406,
    PROXY_AUTHENTICATION_REQUIRED = 407,
    REQUEST_TIMEOUT = 408,
    CONFLICT = 409,
    GONE = 410,
    LENGTH_REQUIRED = 411,
    PRECONDITION_FAILED = 412,
    PAYLOAD_TOO_LARGE = 413,
    URI_TOO_LONG = 414,
    UNSUPPORTED_MEDIA_TYPE = 415,
    RANGE_NOT_SATISFIABLE = 416,
    EXPECTATION_FAILED = 417,
    IM_A_TEAPOT = 418,
    MISDIRECTED_REQUEST = 421,
    UNPROCESSABLE_ENTITY = 422,
    LOCKED = 423,
    FAILED_DEPENDENCY = 424,
    TOO_EARLY = 425,
    UPGRADE_REQUIRED = 426,
    PRECONDITION_REQUIRED = 428,
    TOO_MANY_REQUESTS = 429,
    REQUEST_HEADER_FIELDS_TOO_LARGE = 431,
    UNAVAILABLE_FOR_LEGAL_REASONS = 451,

    INTERNAL_SERVER_ERROR = 500,
    NOT_IMPLEMENTED = 501,
    BAD_GATEWAY = 502,
    SERVICE_UNAVAILABLE = 503,
    GATEWAY_TIMEOUT = 504,
    HTTP_VERSION_NOT_SUPPORTED = 505,
    VARIANT_ALSO_NEGOTIATES = 506,
    INSUFFICIENT_STORAGE = 507,
    LOOP_DETECTED = 508,
    NOT_EXTENDED = 510,
    NETWORK_AUTHENTICATION_REQUIRED = 511
  };

  explicit operator bool() const noexcept {
    return code >= OK && code < MULTIPLE_CHOICES;
  }

  bool error() const noexcept { return !operator bool(); }

  bool is_errno() const noexcept { return code < NONE; }

  auto operator->() const noexcept {
    struct Info {
      int16_t code;
      std::string_view str;
    };

    if (code < NONE) {
      return Info{
          .code = code,
          .str = strerror(code),
      };
    }

    static std::unordered_map<int16_t, Info> infos = {
        {NONE, {NONE, "<NONE>"}},

        {CONTINUE, {CONTINUE, "Continue"}},
        {SWITCHING_PROTOCOLS, {SWITCHING_PROTOCOLS, "Switching Protocols"}},
        {PROCESSING, {PROCESSING, "Processing"}},
        {EARLY_HINTS, {EARLY_HINTS, "Early Hints"}},
        {OK, {OK, "OK"}},
        {CREATED, {CREATED, "Created"}},
        {ACCEPTED, {ACCEPTED, "Accepted"}},
        {NON_AUTHORITATIVE_INFORMATION,
         {NON_AUTHORITATIVE_INFORMATION, "Non-Authoritative Information"}},
        {NO_CONTENT, {NO_CONTENT, "No Content"}},
        {RESET_CONTENT, {RESET_CONTENT, "Reset Content"}},
        {PARTIAL_CONTENT, {PARTIAL_CONTENT, "Partial Content"}},
        {MULTI_STATUS, {MULTI_STATUS, "Multi-Status"}},
        {ALREADY_REPORTED, {ALREADY_REPORTED, "Already Reported"}},
        {IM_USED, {IM_USED, "IM Used"}},
        {MULTIPLE_CHOICES, {MULTIPLE_CHOICES, "Multiple Choices"}},
        {MOVED_PERMANENTLY, {MOVED_PERMANENTLY, "Moved Permanently"}},
        {FOUND, {FOUND, "Found"}},
        {SEE_OTHER, {SEE_OTHER, "See Other"}},
        {NOT_MODIFIED, {NOT_MODIFIED, "Not Modified"}},
        {USE_PROXY, {USE_PROXY, "Use Proxy"}},
        {SWITCH_PROXY, {SWITCH_PROXY, "Switch Proxy"}},
        {TEMPORARY_REDIRECT, {TEMPORARY_REDIRECT, "Temporary Redirect"}},
        {PERMANENT_REDIRECT, {PERMANENT_REDIRECT, "Permanent Redirect"}},
        {BAD_REQUEST, {BAD_REQUEST, "Bad Request"}},
        {UNAUTHORIZED, {UNAUTHORIZED, "Unauthorized"}},
        {PAYMENT_REQUIRED, {PAYMENT_REQUIRED, "Payment Required"}},
        {FORBIDDEN, {FORBIDDEN, "Forbidden"}},
        {NOT_FOUND, {NOT_FOUND, "Not Found"}},
        {METHOD_NOT_ALLOWED, {METHOD_NOT_ALLOWED, "Method Not Allowed"}},
        {NOT_ACCEPTABLE, {NOT_ACCEPTABLE, "Not Acceptable"}},
        {PROXY_AUTHENTICATION_REQUIRED,
         {PROXY_AUTHENTICATION_REQUIRED, "Proxy Authentication Required"}},
        {REQUEST_TIMEOUT, {REQUEST_TIMEOUT, "Request Timeout"}},
        {CONFLICT, {CONFLICT, "Conflict"}},
        {GONE, {GONE, "Gone"}},
        {LENGTH_REQUIRED, {LENGTH_REQUIRED, "Length Required"}},
        {PRECONDITION_FAILED, {PRECONDITION_FAILED, "Precondition Failed"}},
        {PAYLOAD_TOO_LARGE, {PAYLOAD_TOO_LARGE, "Payload Too Large"}},
        {URI_TOO_LONG, {URI_TOO_LONG, "URI Too Long"}},
        {UNSUPPORTED_MEDIA_TYPE,
         {UNSUPPORTED_MEDIA_TYPE, "Unsupported Media Type"}},
        {RANGE_NOT_SATISFIABLE,
         {RANGE_NOT_SATISFIABLE, "Range Not Satisfiable"}},
        {EXPECTATION_FAILED, {EXPECTATION_FAILED, "Expectation Failed"}},
        {IM_A_TEAPOT, {IM_A_TEAPOT, "I'm a teapot"}},
        {MISDIRECTED_REQUEST, {MISDIRECTED_REQUEST, "Misdirected Request"}},
        {UNPROCESSABLE_ENTITY, {UNPROCESSABLE_ENTITY, "Unprocessable Entity"}},
        {LOCKED, {LOCKED, "Locked"}},
        {FAILED_DEPENDENCY, {FAILED_DEPENDENCY, "Failed Dependency"}},
        {TOO_EARLY, {TOO_EARLY, "Too Early"}},
        {UPGRADE_REQUIRED, {UPGRADE_REQUIRED, "Upgrade Required"}},
        {PRECONDITION_REQUIRED,
         {PRECONDITION_REQUIRED, "Precondition Required"}},
        {TOO_MANY_REQUESTS, {TOO_MANY_REQUESTS, "Too Many Requests"}},
        {REQUEST_HEADER_FIELDS_TOO_LARGE,
         {REQUEST_HEADER_FIELDS_TOO_LARGE, "Request Header Fields Too Large"}},
        {UNAVAILABLE_FOR_LEGAL_REASONS,

         {UNAVAILABLE_FOR_LEGAL_REASONS, "Unavailable For Legal Reasons"}},
        {INTERNAL_SERVER_ERROR,
         {INTERNAL_SERVER_ERROR, "Internal Server Error"}},
        {NOT_IMPLEMENTED, {NOT_IMPLEMENTED, "Not Implemented"}},
        {BAD_GATEWAY, {BAD_GATEWAY, "Bad Gateway"}},
        {SERVICE_UNAVAILABLE, {SERVICE_UNAVAILABLE, "Service Unavailable"}},
        {GATEWAY_TIMEOUT, {GATEWAY_TIMEOUT, "Gateway Timeout"}},
        {HTTP_VERSION_NOT_SUPPORTED,
         {HTTP_VERSION_NOT_SUPPORTED, "HTTP Version Not Supported"}},
        {VARIANT_ALSO_NEGOTIATES,
         {VARIANT_ALSO_NEGOTIATES, "Variant Also Negotiates"}},
        {INSUFFICIENT_STORAGE, {INSUFFICIENT_STORAGE, "Insufficient Storage"}},
        {LOOP_DETECTED, {LOOP_DETECTED, "Loop Detected"}},
        {NOT_EXTENDED, {NOT_EXTENDED, "Not Extended"}},
        {NETWORK_AUTHENTICATION_REQUIRED,
         {NETWORK_AUTHENTICATION_REQUIRED, "Network Authentication Required"}},
    };

    return infos.at(code);
  }

  STATUS &operator=(int16_t code) noexcept {
    this->code = code;
    return *this;
  }

  operator int16_t() const noexcept { return code; }

  std::strong_ordering operator<=>(int16_t code) const noexcept {
    return this->code <=> code;
  }

  std::strong_ordering operator<=>(STATUS const &other) const noexcept {
    return code <=> other.code;
  }

  bool operator==(int16_t code) const noexcept { return this->code == code; }
  bool operator==(STATUS const &other) const noexcept {
    return code == other.code;
  }

  std::string_view str() const noexcept { return operator->().str; }

private:
  int16_t code = NONE;
};

} // namespace HTTP

namespace HTTP {

template <typename T, typename E> using expected = glz::expected<T, E>;

using int128_t = __uint128_t;

} // namespace HTTP

namespace XSON {

template <typename TXSONImpl>
concept XSON = requires(TXSONImpl obj) {
  { obj.serialize() } -> std::convertible_to<std::string>;

  { obj.serialize(true) } -> std::convertible_to<std::string>;

  {

    obj.deserialize(std::string_view{})
  } -> std::common_reference_with<TXSONImpl>;

  { obj[std::string_view{}] } -> std::common_reference_with<TXSONImpl>;

  { obj.at(std::string_view{}) } -> std::common_reference_with<TXSONImpl>;

  {
    std::decay_t<decltype(obj.template get<int8_t>())>{}
  } -> std::same_as<int8_t>;
  {
    std::decay_t<decltype(obj.template get<int16_t>())>{}
  } -> std::same_as<int16_t>;
  {
    std::decay_t<decltype(obj.template get<int32_t>())>{}
  } -> std::same_as<int32_t>;
  {
    std::decay_t<decltype(obj.template get<int64_t>())>{}
  } -> std::same_as<int64_t>;
  {
    std::decay_t<decltype(obj.template get<uint8_t>())>{}
  } -> std::same_as<uint8_t>;
  {
    std::decay_t<decltype(obj.template get<uint16_t>())>{}
  } -> std::same_as<uint16_t>;
  {
    std::decay_t<decltype(obj.template get<uint32_t>())>{}
  } -> std::same_as<uint32_t>;
  {
    std::decay_t<decltype(obj.template get<uint64_t>())>{}
  } -> std::same_as<uint64_t>;
  { std::decay_t<decltype(obj.template get<bool>())>{} } -> std::same_as<bool>;
  {
    std::decay_t<decltype(obj.template get<float>())>{}
  } -> std::floating_point;
  {
    std::decay_t<decltype(obj.template get<double>())>{}
  } -> std::floating_point;

  {
    std::decay_t<decltype(obj.template get<std::string>())>{}
  } -> std::same_as<std::string>;

  obj[std::string_view{}] == int32_t{};
  obj[std::string_view{}] == double{};
  obj[std::string_view{}] == std::string{};
  obj[std::string_view{}] == bool{};

  obj.items();
  obj.items().begin();
  obj.items().end();

  obj.size();

  obj.empty();

  obj.contains(std::string_view{});
};

struct NLH : public nlohmann::json {
  std::string serialize(bool pretty = false) const {
    return dump(pretty ? 2 : -1);
  }

  NLH &deserialize(std::string_view str) {
    *static_cast<nlohmann::json *>(this) = parse(str);
    return *this;
  }
};

struct GLZ : public glz::json_t {

  GLZ() = default;
  GLZ(GLZ const &other) : glz::json_t(other) {}
  GLZ(GLZ &&other) : glz::json_t(std::move(other)) {}

  GLZ(glz::json_t const &other) : glz::json_t(other) {}
  GLZ(glz::json_t &&other) : glz::json_t(std::move(other)) {}

  GLZ &deserialize(std::string_view str) {
    if (auto ec = glz::read_json<glz::json_t>(str); !ec.has_value()) {
      throw std::runtime_error{
          std::format("{}:{}:{}: {} at position {}; dump: {}; source: {}",
                      "/home/deb/src/falutez/include/falutez/falutez-serio.hpp",
                      127, __func__, glz::format_error(ec), ec.error().location,
                      dump().value_or("<DUMP-UNAVAILABLE>"), str)};
    } else {
      *(static_cast<glz::json_t *>(this)) = ec.value();
    }

    return *this;
  }

  std::string serialize(bool pretty = false) const {
    return glz::write_json(*this).value();
  }

  template <std::integral T> T get() const {
    return static_cast<T>(glz::json_t::get<double>());
  }

  template <typename T>
    requires((!std::integral<T>))
  T const &get() const {
    return glz::json_t::get<T>();
  }

  template <typename T>
    requires((!std::integral<T>))
  T &get() {
    return glz::json_t::get<T>();
  }

  GLZ &operator[](std::string_view key) {
    return static_cast<GLZ &>(glz::json_t::operator[](key));
  }

  GLZ const &operator[](std::string_view key) const {
    return static_cast<GLZ const &>(glz::json_t::operator[](key));
  }

  GLZ &at(std::string_view key) {
    return static_cast<GLZ &>(glz::json_t::at(key));
  }

  GLZ const &at(std::string_view key) const {
    return static_cast<GLZ const &>(glz::json_t::at(key));
  }

  GLZ &operator=(const GLZ &other) {
    *static_cast<glz::json_t *>(this) = other;
    return *this;
  }

  GLZ &operator=(GLZ &&other) {
    *static_cast<glz::json_t *>(this) = std::move(other);
    return *this;
  }

  GLZ &operator=(const char *other) {
    *static_cast<glz::json_t *>(this) = std::string_view{other};
    return *this;
  }

  GLZ &operator=(HTTP::int128_t other) {
    *static_cast<glz::json_t *>(this) = static_cast<double>(other);
    return *this;
  }

  GLZ &operator=(auto const &other) {
    *static_cast<glz::json_t *>(this) = other;
    return *this;
  }

  GLZ &operator=(auto &&other) {
    *static_cast<glz::json_t *>(this) = other;
    return *this;
  }

  bool operator==(const char *other) const {
    return this->is_string() && this->get<std::string>() == other;
  }

  bool operator==(std::string_view other) const {
    return this->is_string() && this->get<std::string>() == other;
  }

  bool operator==(std::integral auto other) const {
    return this->is_number() && static_cast<std::decay_t<decltype(other)>>(
                                    this->get<double>()) == other;
  }

  bool operator==(std::floating_point auto other) const {
    return this->is_number() && this->get<double>() == other;
  }

  bool operator==(bool other) const {
    return this->is_boolean() && this->get<bool>() == other;
  }

  struct unpacked_items {
    std::unordered_map<glz::sv, XSON::GLZ> items;
  };

  auto &items() {
    if (this->is_object()) {
      using object_t = std::map<std::string, GLZ, std::less<>>;
      return reinterpret_cast<object_t &>(this->get_object());
    } else {
      throw std::runtime_error{
          std::format("{}:{}:{}: items() called on elelment that does not "
                      "support enumeration",
                      "/home/deb/src/falutez/include/falutez/falutez-serio.hpp",
                      235, __func__)};
    }
  }

} __attribute__((packed));

static_assert(sizeof(GLZ) == sizeof(glz::json_t));

using JSON = GLZ;

} // namespace XSON

template <> struct glz::meta<XSON::GLZ::unpacked_items> {
  using T = XSON::GLZ::unpacked_items;
  static constexpr auto unknown_read{&T::items};
  static constexpr auto unknown_write{&T::items};
};

namespace HTTP {
struct Headers {

  Headers(std::unordered_map<std::string, std::string> const &headers)
      : headers{headers} {}
  Headers(std::unordered_map<std::string, std::string> &&headers)
      : headers{std::move(headers)} {}
  Headers(std::map<std::string, std::string> const &headers)
      : headers{headers.begin(), headers.end()} {}
  Headers(
      std::initializer_list<std::pair<std::string, std::string>> const &headers)
      : headers{headers.begin(), headers.end()} {}
  Headers() = default;
  Headers(Headers const &other) = default;
  Headers(Headers &&other) = default;
  Headers(XSON::XSON auto &json) { merge(json); }

  Headers &operator=(Headers const &other) = default;
  Headers &operator=(Headers &&other) = default;

  std::string &operator[](std::string const &key) { return headers.at(key); }
  std::string &operator[](std::string &&key) { return headers.at(key); }
  template <class K> std::string &at(K &&key) {
    return headers.at(std::forward<K>(key));
  }

  std::string &at(std::string &&key) { return headers.at(key); }
  std::string const &at(std::string const &key) const {
    return headers.at(key);
  }
  template <class K> std::string const &at(K &&key) const {
    return headers.at(std::forward<K>(key));
  }

  auto begin() { return headers.begin(); }
  auto end() { return headers.end(); }
  auto cbegin() const { return headers.cbegin(); }
  auto cend() const { return headers.cend(); }
  auto size() const { return headers.size(); }
  auto empty() const { return headers.empty(); }
  auto contains(std::string const &key) const { return headers.contains(key); }
  auto clear() { headers.clear(); }
  auto erase(std::string const &key) { return headers.erase(key); }

  void merge(XSON::XSON auto &json) {
    for (auto &[key, value] : json.items()) {
      if (value.is_string()) {
        headers[key] = value.template get<std::string>();
      } else if (value.is_number()) {
        headers[key] = std::to_string(value.template get<double>());
      } else if (value.is_boolean()) {
        headers[key] = value.template get<bool>() ? "true" : "false";
      } else {
        headers[key] = value.serialize();
      }
    }
  }

  void merge(std::unordered_map<std::string, std::string> const &other) {
    for (auto &[key, value] : other) {
      headers[key] = value;
    }
  }

  void merge(Headers const &other) { merge(other.headers); }

  Headers &operator+=(Headers const &other) {
    merge(other);
    return *this;
  }

  Headers operator+(Headers const &other) const {
    Headers result{*this};
    result += other;
    return result;
  }

  bool operator==(Headers const &other) const {
    return headers == other.headers;
  }

  friend std::ostream &operator<<(std::ostream &os, Headers const &headers) {
    for (auto &[key, value] : headers.headers) {
      os << key << ": " << value << "\n";
    }
    return os;
  }

  operator std::map<std::string, std::string>() const {
    return std::map<std::string, std::string>{headers.begin(), headers.end()};
  }

  operator std::unordered_map<std::string, std::string>() const {
    return headers;
  }

private:
  std::unordered_map<std::string, std::string> headers;
};

} // namespace HTTP

namespace HTTP {
struct Parameters {
  using value_type =
      std::unordered_map<std::string_view,
                         std::variant<int128_t, double, std::string, bool>>;

  value_type data() const { return params; }

  Parameters() = default;
  Parameters(Parameters const &other) = default;
  Parameters(Parameters &&other) = default;
  Parameters(value_type const &params) : params{params} {}
  Parameters(value_type &&params) : params{std::move(params)} {}

  Parameters &operator=(Parameters const &other) = default;
  Parameters &operator=(Parameters &&other) = default;

  void merge(value_type const &other) {
    for (auto &[key, value] : other) {
      params[key] = value;
    }
  }

  void merge(Parameters const &other) { merge(other.params); }

  Parameters &operator+=(Parameters const &other) {
    merge(other);
    return *this;
  }

  Parameters operator+(Parameters const &other) const {
    Parameters result{*this};
    result += other;
    return result;
  }

  bool operator==(Parameters const &other) const {
    return params == other.params;
  }

  std::string &operator[](std::string_view const &key) {
    return std::get<std::string>(params.at(key));
  }

  std::string &operator[](std::string_view &&key) {
    return std::get<std::string>(params.at(key));
  }

  std::string &at(std::string_view const &key) {
    return std::get<std::string>(params.at(key));
  }

  std::string &at(std::string_view &&key) {
    return std::get<std::string>(params.at(key));
  }

  std::string const &at(std::string_view const &key) const {
    return std::get<std::string>(params.at(key));
  }

  std::string const &at(std::string_view &&key) const {
    return std::get<std::string>(params.at(key));
  }

  auto begin() { return params.begin(); }
  auto end() { return params.end(); }
  auto cbegin() const { return params.cbegin(); }
  auto cend() const { return params.cend(); }
  auto size() const { return params.size(); }
  auto empty() const { return params.empty(); }
  auto contains(std::string const &key) const { return params.contains(key); }
  auto clear() { params.clear(); }
  auto erase(std::string const &key) { return params.erase(key); }

  void merge(XSON::XSON auto &json) {
    for (auto &[key, value] : json.items()) {
      if (value.is_string()) {
        params[key] = value.template get<std::string>();
      } else if (value.is_number()) {
        params[key] = value.template get<double>();
      } else if (value.is_boolean()) {
        params[key] = value.template get<bool>();
      } else {
        params[key] = value.serialize();
      }
    }
  }

  void to_json(XSON::XSON auto &json) const {
    for (auto &[key, value] : params) {
      if (std::holds_alternative<int128_t>(value)) {
        json[key] = std::get<int128_t>(value);
      } else if (std::holds_alternative<double>(value)) {
        json[key] = std::get<double>(value);
      } else if (std::holds_alternative<std::string>(value)) {
        json[key] = std::get<std::string>(value);
      } else if (std::holds_alternative<bool>(value)) {
        json[key] = std::get<bool>(value);
      }
    }
  }

  XSON::JSON to_json() const {
    auto json = XSON::JSON{};
    to_json(json);
    return json;
  }

  friend std::ostream &operator<<(std::ostream &os, Parameters const &params) {
    for (auto &[key, value] : params.params) {
      os << key << ": ";
      if (std::holds_alternative<int128_t>(value)) {
        os << std::format("{}", std::get<int128_t>(value));
      } else if (std::holds_alternative<double>(value)) {
        os << std::get<double>(value);
      } else if (std::holds_alternative<std::string>(value)) {
        os << std::get<std::string>(value);
      } else if (std::holds_alternative<bool>(value)) {
        os << std::get<bool>(value);
      }
      os << "\n";
    }
    return os;
  }

  std::string get_url_component() const {
    std::string url_component;
    for (auto &[key, value] : params) {
      if (url_component.empty()) {
        url_component += "?";
      } else {
        url_component += "&";
      }
      url_component += std::string{key};
      url_component += "=";
      if (std::holds_alternative<int128_t>(value)) {
        url_component += std::format("{}", std::get<int128_t>(value));
      } else if (std::holds_alternative<double>(value)) {
        url_component += std::format("{}", std::get<double>(value));
      } else if (std::holds_alternative<std::string>(value)) {
        url_component += std::get<std::string>(value);
      } else if (std::holds_alternative<bool>(value)) {
        url_component += std::get<bool>(value) ? "true" : "false";
      }
    }
    return url_component;
  }

private:
  value_type params;
};

} // namespace HTTP

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
struct RequestInfo {
  const METHOD method;
  const std::string path;

  HTTP::STATUS status;
  std::optional<Headers> headers;
  std::optional<Body> body;

  friend std::ostream &operator<<(std::ostream &os, RequestInfo const &req) {
    os << req.method << " " << req.path << " -> " << req.status;
    return os;
  }
};

using Request = exec::task<HTTP::expected<RequestInfo, HTTP::STATUS>>;

struct RequestSpec {
  std::string_view path;
  std::optional<Parameters> params;
  std::optional<Headers> headers;
  std::optional<Body> body;
};

template <typename TImpl>
concept ClientImpl = requires(TImpl impl) {
  impl.set_base_url(std::string_view{});
  impl.set_timeout(std::chrono::milliseconds{});
  impl.set_keepalive(std::make_pair<bool, std::chrono::milliseconds>(
      true, std::chrono::milliseconds{1000}));
  impl.set_headers(Headers{});

  { impl.base_url() } -> std::convertible_to<std::string_view>;
  { impl.timeout() } -> std::convertible_to<std::chrono::milliseconds>;
  {
    impl.keepalive()
  } -> std::convertible_to<std::pair<bool, std::chrono::milliseconds>>;
  { impl.headers() } -> std::convertible_to<Headers>;

  impl.request(METHOD::GET, RequestSpec{});
};

} // namespace HTTP

namespace HTTP {

struct GenericClientConfig {
  std::string base_url;
  std::chrono::milliseconds timeout;
  std::pair<bool, std::chrono::milliseconds> keepalive;
  Headers headers;
};

template <typename TConfig = GenericClientConfig> struct GenericClient {

  virtual ~GenericClient() {
    if (config) {
      config.reset();
    }
  }

  GenericClient() = delete;

  GenericClient(TConfig params) : config{std::make_shared<TConfig>(params)} {}

  GenericClient(std::shared_ptr<TConfig> params) : config{std::move(params)} {}

  virtual void set_base_url(std::string_view base_url) {
    config->base_url = base_url;
  }

  virtual void set_timeout(std::chrono::milliseconds timeout) {
    config->timeout = timeout;
  }

  virtual void
  set_keepalive(std::pair<bool, std::chrono::milliseconds> keepalive) {
    config->keepalive = keepalive;
  }

  virtual void set_headers(Headers headers) {
    config->headers = std::move(headers);
  }

  virtual std::string base_url() const { return config->base_url; }

  virtual std::chrono::milliseconds timeout() const { return config->timeout; }

  virtual std::pair<bool, std::chrono::milliseconds> keepalive() const {
    return config->keepalive;
  }

  virtual Headers const &headers() const { return config->headers; }

  virtual std::function<Request()> request(METHOD method,
                                           RequestSpec reqParams) {
    throw std::runtime_error{std::format(
        "{}:{}:{}: request() not implemented",
        "/home/deb/src/falutez/include/falutez/falutez-generic-client.hpp", 67,
        __func__)};
  }

protected:
  std::shared_ptr<TConfig> config;
};

namespace _internal {
template <ClientImpl TImpl> struct StaticCheck {
  static constexpr inline auto value = true;
};

static_assert(StaticCheck<GenericClient<GenericClientConfig>>::value,
              "GenericClient does not match ClientImpl concept");

} // namespace _internal

} // namespace HTTP

namespace HTTP {

struct Client {

  Client() = default;

  template <ClientImpl TImpl>
  Client(std::shared_ptr<TImpl> impl)
      : impl{std::dynamic_pointer_cast<GenericClient<GenericClientConfig>>(
            impl)} {}

  template <ClientImpl TImpl>
  Client(TImpl &&client)
      : impl{std::dynamic_pointer_cast<GenericClient<GenericClientConfig>>(
            std::make_shared<TImpl>(std::move(client)))} {}

  template <ClientImpl TImpl> Client &operator=(std::shared_ptr<TImpl> impl) {
    this->impl =
        std::dynamic_pointer_cast<GenericClient<GenericClientConfig>>(impl);
    return *this;
  }

private:
  std::shared_ptr<GenericClient<GenericClientConfig>> impl;
};

} // namespace HTTP
