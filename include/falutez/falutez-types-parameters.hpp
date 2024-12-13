#pragma once

#ifndef _UNIHEADER_BUILD_
#include <string_view>
#include <unordered_map>
#include <variant>
#endif

#include <falutez/falutez-serio.hpp>
#include <falutez/falutez-types-std.hpp>

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