#pragma once

#ifndef _UNIHEADER_BUILD_
#include <string>
#include <unordered_map>
#endif

#include <falutez/falutez-serio.hpp>

namespace HTTP {
struct Headers {

  /// construct from maps, other headers, or JSON

  Headers(std::unordered_map<std::string, std::string> const &headers)
      : headers_{headers} {}
  Headers(std::unordered_map<std::string, std::string> &&headers)
      : headers_{std::move(headers)} {}
  Headers(std::map<std::string, std::string> const &headers)
      : headers_{headers.begin(), headers.end()} {}
  Headers(
      std::initializer_list<std::pair<std::string, std::string>> const &headers)
      : headers_{headers.begin(), headers.end()} {}
  Headers() = default;
  Headers(Headers const &other) = default;
  Headers(Headers &&other) = default;
  Headers(XSON::XSON auto &json) { merge(json); }

  Headers &operator=(Headers const &other) = default;
  Headers &operator=(Headers &&other) = default;

  /// operator[] to access/mutate by key
  std::string &operator[](std::string const &key) { return headers_[key]; }
  template <class K> std::string &at(K &&key) {
    return headers_.at(std::forward<K>(key));
  }

  /// at() mutating or read-only access
  std::string &at(std::string &&key) { return headers_.at(key); }
  std::string const &at(std::string const &key) const {
    return headers_.at(key);
  }
  template <class K> std::string const &at(K &&key) const {
    return headers_.at(std::forward<K>(key));
  }

  auto &set_content_length(size_t length) {
    headers_["Content-Length"] = std::to_string(length);
    return *this;
  }

  auto content_length() const {
    return headers_.contains("Content-Length")
               ? std::stoul(headers_.at("Content-Length"))
               : 0;
  }

  auto &set_content_type(std::string const &type) {
    headers_["Content-Type"] = type;
    return *this;
  }

  auto content_type() const {
    return headers_.contains("Content-Type") ? headers_.at("Content-Type") : "";
  }

  /// other std::unordered_map methods
  auto begin() { return headers_.begin(); }
  auto end() { return headers_.end(); }
  auto cbegin() const { return headers_.cbegin(); }
  auto cend() const { return headers_.cend(); }
  auto size() const { return headers_.size(); }
  auto empty() const { return headers_.empty(); }
  auto contains(std::string const &key) const { return headers_.contains(key); }
  auto clear() { headers_.clear(); }
  auto erase(std::string const &key) { return headers_.erase(key); }

  decltype(auto) emplace(auto &&...args) {
    return headers_.emplace(std::forward<decltype(args)>(args)...);
  }

  decltype(auto) insert(auto &&arg) {
    return headers_.insert(std::forward<decltype(arg)>(arg));
  }

  /// ingest JSON object into headers
  void merge(XSON::XSON auto &json) {
    for (auto &[key, value] : json.items()) {
      if (value.is_string()) {
        headers_[key] = value.template get<std::string>();
      } else if (value.is_number()) {
        headers_[key] = std::to_string(value.template get<double>());
      } else if (value.is_boolean()) {
        headers_[key] = value.template get<bool>() ? "true" : "false";
      } else {
        headers_[key] = value.serialize();
      }
    }
  }

  /// ingest from raw maps headers
  void merge(std::unordered_map<std::string, std::string> const &other) {
    for (const auto &[key, value] : other) {
      headers_[key] = value;
    }
  }

  void merge(std::map<std::string, std::string> const &other) {
    for (const auto &[key, value] : other) {
      headers_[key] = value;
    }
  }

  void merge(
      std::initializer_list<std::pair<std::string, std::string>> const &other) {
    for (const auto &[key, value] : other) {
      headers_[key] = value;
    }
  }

  void merge(std::unordered_map<std::string, std::string> &&other) {
    for (auto &[key, value] : other) {
      headers_[std::move(key)] = std::move(value);
    }
  }

  void merge(std::map<std::string, std::string> &&other) {
    for (auto &[key, value] : other) {
      headers_[std::move(key)] = std::move(value);
    }
  }

  /// merge from other Headers
  void merge(Headers const &other) { merge(other.headers_); }

  void merge(Headers &&other) { merge(std::move(other.headers_)); }

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

  bool operator==(Headers const &other) const {
    return headers_ == other.headers_;
  }

  XSON::JSON to_json() const {
    auto json = XSON::JSON{};
    for (const auto &[key, value] : headers_) {
      json[key] = value;
    }
    return json;
  }

  friend std::ostream &operator<<(std::ostream &ost, Headers const &headers) {
    ost << headers.to_json().dump().value_or("undefined");
    return ost;
  }

  std::string str() const { return to_json().dump().value_or("undefined"); }

  // conversion
  operator std::map<std::string, std::string>() const {
    return std::map<std::string, std::string>{headers_.begin(), headers_.end()};
  }

  operator std::unordered_map<std::string, std::string>() const {
    return headers_;
  }

private:
  std::unordered_map<std::string, std::string> headers_;
};

} // namespace HTTP