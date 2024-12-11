#pragma once

#include <concepts>
#include <format>
#include <glaze/json/json_t.hpp>
#include <string_view>

#include <nlohmann/json.hpp>

#include <glaze/glaze.hpp>

namespace XSON {

template <typename TXSONImpl>
concept XSON = requires(TXSONImpl obj) {
  /// @brief needs a serialize method to return a owned string
  { obj.serialize() } -> std::convertible_to<std::string>;

  /// @brief serialize should take a defaulted argument (or be overloaded) for
  /// pretty-printing
  { obj.serialize(true) } -> std::convertible_to<std::string>;

  {
    /// @brief must supply a deserialize() method that returns ref to self
    obj.deserialize(std::string_view{})
  } -> std::common_reference_with<TXSONImpl>;

  /// @brief supports [] indexing (returns refs)
  { obj[std::string_view{}] } -> std::common_reference_with<TXSONImpl>;

  /// @brief supports at() lookup (returns refs)
  /// no stipulation on throwing or not throwing
  { obj.at(std::string_view{}) } -> std::common_reference_with<TXSONImpl>;

  /// @brief templated get<> methods
  { obj.template get<int64_t>() } -> std::same_as<int64_t>;
  { obj.template get<uint64_t>() } -> std::same_as<uint64_t>;
  { obj.template get<int32_t>() } -> std::same_as<int32_t>;
  { obj.template get<uint32_t>() } -> std::same_as<uint32_t>;
  { obj.template get<int16_t>() } -> std::same_as<int16_t>;
  { obj.template get<uint16_t>() } -> std::same_as<uint16_t>;
  { obj.template get<int8_t>() } -> std::same_as<int8_t>;
  { obj.template get<uint8_t>() } -> std::same_as<uint8_t>;
  { obj.template get<bool>() } -> std::same_as<bool>;
  { obj.template get<float>() } -> std::same_as<float>;
  { obj.template get<double>() } -> std::same_as<double>;
  { obj.template get<std::string>() } -> std::same_as<std::string>;

  /// @brief refs returned by operator[] should directly comparable to
  /// at least these types.
  obj[std::string_view{}] == int32_t{};
  obj[std::string_view{}] == double{};
  obj[std::string_view{}] == std::string{};
  obj[std::string_view{}] == bool{};
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
      throw std::runtime_error{std::format(
          "{}:{}:{}: {} at position {}; dump: {}; source: {}", __FILE__,
          __LINE__, __func__, glz::format_error(ec), ec.error().location,
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

} __attribute__((packed));

} // namespace XSON
