#pragma once

#include <chrono>
#include <string>
#include <unordered_map>

#include "falutez/serio.hpp"

#include "falutez/falutez-types.hpp"

namespace HTTP {

enum class METHOD { GET, POST, PUT, DELETE };

struct Headers {

  /// construct from maps, other headers, or JSON

  Headers(std::unordered_map<std::string, std::string> const &headers)
      : headers{headers} {}
  Headers(std::unordered_map<std::string, std::string> &&headers)
      : headers{std::move(headers)} {}
  Headers() = default;
  Headers(Headers const &other) = default;
  Headers(Headers &&other) = default;
  Headers(XSON::XSON auto &json) { merge(json); }

  Headers &operator=(Headers const &other) = default;
  Headers &operator=(Headers &&other) = default;

  /// operator[] to access/mutate by key
  std::string &operator[](std::string const &key) { return headers.at(key); }
  std::string &operator[](std::string &&key) { return headers.at(key); }
  template <class K> std::string &at(K &&key) {
    return headers.at(std::forward<K>(key));
  }

  /// at() mutating or read-only access
  std::string &at(std::string &&key) { return headers.at(key); }
  std::string const &at(std::string const &key) const {
    return headers.at(key);
  }
  template <class K> std::string const &at(K &&key) const {
    return headers.at(std::forward<K>(key));
  }

  /// other std::unordered_map methods
  auto begin() { return headers.begin(); }
  auto end() { return headers.end(); }
  auto cbegin() const { return headers.cbegin(); }
  auto cend() const { return headers.cend(); }
  auto size() const { return headers.size(); }
  auto empty() const { return headers.empty(); }
  auto contains(std::string const &key) const { return headers.contains(key); }
  auto clear() { headers.clear(); }
  auto erase(std::string const &key) { return headers.erase(key); }

  /// ingest JSON object into headers
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

  /// ingest from raw maps headers
  void merge(std::unordered_map<std::string, std::string> const &other) {
    for (auto &[key, value] : other) {
      headers[key] = value;
    }
  }

  /// merge from other Headers
  void merge(Headers const &other) { merge(other.headers); }

  /// operator shortcuts
  Headers &operator+=(Headers const &other) {
    merge(other);
    return *this;
  }

  /// e.g.: `auto new_headers = base_headers + request_headers;`
  Headers operator+(Headers const &other) const {
    Headers result{*this};
    result += other;
    return result;
  }

private:
  std::unordered_map<std::string, std::string> headers;
};

/**
 * @brief ClientImpl concept - all implementation should abide by the interface
 *        GenericClient is statically checked at compile time  against this
 *        concept to reduce the chance of definitions going out of sync
 */
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
};

struct Request {
  METHOD method;

  std::string path;

  Headers headers;

  // BODY body;
};
} // namespace HTTP