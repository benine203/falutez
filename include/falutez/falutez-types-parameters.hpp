#pragma once

#ifndef _UNIHEADER_BUILD_
#include <string_view>
#include <unordered_map>
#include <variant>
#endif

#include <falutez/falutez-serio.hpp>
#include <falutez/falutez-types-std.hpp>

namespace HTTP {

/**
 * @brief Parameters - path-based parameters for a request URL
 */
struct Parameters {
  using value_type = std::unordered_map<
      std::string_view, std::variant<FLZ::int128_t, double, std::string, bool>>;

  value_type data() const { return params_; }

  Parameters() = default;
  Parameters(Parameters const &other) = default;
  Parameters(Parameters &&other) = default;
  Parameters(value_type const &params) : params_{params} {}
  Parameters(value_type &&params) : params_{std::move(params)} {}

  Parameters &operator=(Parameters const &other) = default;
  Parameters &operator=(Parameters &&other) = default;

  void merge(value_type const &other) {
    for (const auto &[key, value] : other) {
      params_[key] = value;
    }
  }

  void merge(value_type &&other) {
    for (auto &[key, value] : other) {
      params_[std::move(key)] = std::move(value);
    }
  }

  void merge(Parameters const &other) { merge(other.params_); }

  void merge(Parameters &&other) { merge(std::move(other.params_)); }

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
    return params_ == other.params_;
  }

  std::string &operator[](std::string_view const &key) {
    return std::get<std::string>(params_.at(key));
  }

  std::string &operator[](std::string_view &&key) {
    return std::get<std::string>(params_.at(key));
  }

  std::string &at(std::string_view const &key) {
    return std::get<std::string>(params_.at(key));
  }

  std::string &at(std::string_view &&key) {
    return std::get<std::string>(params_.at(key));
  }

  std::string const &at(std::string_view const &key) const {
    return std::get<std::string>(params_.at(key));
  }

  std::string const &at(std::string_view &&key) const {
    return std::get<std::string>(params_.at(key));
  }

  auto begin() { return params_.begin(); }
  auto end() { return params_.end(); }
  auto cbegin() const { return params_.cbegin(); }
  auto cend() const { return params_.cend(); }
  auto size() const { return params_.size(); }
  auto empty() const { return params_.empty(); }
  auto contains(std::string const &key) const { return params_.contains(key); }
  auto clear() { params_.clear(); }
  auto erase(std::string const &key) { return params_.erase(key); }

  void merge(XSON::XSON auto &json) {
    for (auto &[key, value] : json.items()) {
      if (value.is_string()) {
        params_[key] = value.template get<std::string>();
      } else if (value.is_number()) {
        params_[key] = value.template get<double>();
      } else if (value.is_boolean()) {
        params_[key] = value.template get<bool>();
      } else {
        params_[key] = value.serialize();
      }
    }
  }

  void to_json(XSON::XSON auto &json) const {
    for (const auto &[key, value] : params_) {
      if (std::holds_alternative<FLZ::int128_t>(value)) {
        json[key] = std::get<FLZ::int128_t>(value);
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

  friend std::ostream &operator<<(std::ostream &ost, Parameters const &params) {
    ost << params.to_json().dump().value_or("undefined");
    return ost;
  }

  std::string str() const { return to_json().dump().value_or("undefined"); }

  std::string get_url_component() const {
    std::string url_component;
    for (const auto &[key, value] : params_) {
      if (url_component.empty()) {
        url_component += "?";
      } else {
        url_component += "&";
      }
      url_component += std::string{key};
      url_component += "=";
      if (std::holds_alternative<FLZ::int128_t>(value)) {
        url_component += std::format("{}", std::get<FLZ::int128_t>(value));
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
  value_type params_;
};

} // namespace HTTP