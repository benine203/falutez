#pragma once

#ifndef _UNIHEADER_BUILD_
#include <concepts>
#include <format>
#include <limits>

#include <glaze/core/context.hpp>
#include <glaze/core/opts.hpp>
#include <glaze/core/read.hpp>
#include <glaze/glaze.hpp>
#include <glaze/json/json_t.hpp>
#include <glaze/json/ptr.hpp>

#include <string_view>

#include <nlohmann/json.hpp>
#endif

#include <falutez/falutez-types-std.hpp>

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

  /// @brief refs returned by operator[] should directly comparable to
  /// at least these types.
  obj[std::string_view{}] == int32_t{};
  obj[std::string_view{}] == double{};
  obj[std::string_view{}] == std::string{};
  obj[std::string_view{}] == bool{};

  /// @brief enumerating
  obj.items();
  obj.items().begin();
  obj.items().end();

  /// @brief size
  obj.size();

  /// @brief empty
  obj.empty();

  /// @brief contains
  obj.contains(std::string_view{});

  obj.has_boolean_field(std::string_view{});

  obj.has_double_field(std::string_view{});

  obj.has_number_field(std::string_view{});

  obj.has_string_field(std::string_view{});

  obj.is_array();

  obj.get_array();
};

struct NLH : public nlohmann::json {
  NLH() = default;
  NLH(NLH const &other) : nlohmann::json(other) {}
  NLH(NLH &&other) : nlohmann::json(std::move(other)) {}

  NLH(nlohmann::json const &other) : nlohmann::json(other) {}
  NLH(nlohmann::json &&other) : nlohmann::json(std::move(other)) {}

  std::string serialize(bool pretty = false) const {
    return dump(pretty ? 2 : -1);
  }

  NLH &deserialize(std::string_view str) {
    *static_cast<nlohmann::json *>(this) = parse(str);
    return *this;
  }

  bool has_boolean_field(std::string_view key) const {
    return this->contains(key) && this->at(key).is_boolean();
  }

  bool has_double_field(std::string_view key) const {
    return this->contains(key) && this->at(key).is_number_float();
  }

  bool has_number_field(std::string_view key) const {
    return this->contains(key) && this->at(key).is_number();
  }

  bool has_string_field(std::string_view key) const {
    return this->contains(key) && this->at(key).is_string();
  }

  NLH &get_array() {
    if (!this->is_array())
      throw std::runtime_error{
          std::format("{}:{}:{}: not an array", __FILE__, __LINE__, __func__)};
    return *this;
  }

  NLH const &get_array() const {
    if (!this->is_array())
      throw std::runtime_error{
          std::format("{}:{}:{}: not an array", __FILE__, __LINE__, __func__)};
    return *this;
  }

  NLH &operator[](const char *key) {
    return static_cast<NLH &>(nlohmann::json::operator[](key));
  }

  NLH const &operator[](const char *key) const {
    return static_cast<NLH const &>(nlohmann::json::operator[](key));
  }

  NLH &operator[](std::string_view key) {
    return static_cast<NLH &>(nlohmann::json::operator[](key));
  }

  NLH const &operator[](std::string_view key) const {
    return static_cast<NLH const &>(nlohmann::json::operator[](key));
  }

  NLH &at(std::string_view key) {
    return static_cast<NLH &>(nlohmann::json::at(key));
  }

  NLH const &at(std::string_view key) const {
    return static_cast<NLH const &>(nlohmann::json::at(key));
  }

  NLH &operator=(const NLH &other) {
    *static_cast<nlohmann::json *>(this) = nlohmann::json(other);
    return *this;
  }

  NLH &operator=(NLH &&other) {
    *static_cast<nlohmann::json *>(this) = nlohmann::json(std::move(other));
    return *this;
  }

  NLH &operator=(const char *other) {
    *static_cast<nlohmann::json *>(this) = std::string_view{other};
    return *this;
  }

  NLH &operator=(HTTP::int128_t other) {
    *static_cast<nlohmann::json *>(this) = static_cast<double>(other);
    return *this;
  }

  NLH &operator=(auto const &other) {
    *static_cast<nlohmann::json *>(this) = nlohmann::json(other);
    return *this;
  }

  NLH &operator=(auto &&other) {
    *static_cast<nlohmann::json *>(this) = nlohmann::json(other);
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

  GLZ &operator=(HTTP::int128_t other) {
    *static_cast<glz::json_t *>(this) = static_cast<double>(other);
    return *this;
  }

  // range based operator=()'s
  template <std::ranges::range T> GLZ &operator=(T const &other) {
    *static_cast<glz::json_t *>(this) =
        glz::json_t::array_t{other.begin(), other.end()};
    return *this;
  }

  // range based operator=()'s
  template <std::ranges::range T> GLZ &operator=(T &&other) {
    *static_cast<glz::json_t *>(this) =
        glz::json_t::array_t{other.begin(), other.end()};
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

  bool has_boolean_field(std::string_view key) const {
    return this->contains(key) && this->at(key).is_boolean();
  }

  bool has_double_field(std::string_view key) const {
    if (!this->contains(key))
      return false;

    auto const &val = this->at(key);

    return val.is_number() && std::fabs(std::fmod(val.get<double>(), 1.0)) >
                                  std::numeric_limits<double>::epsilon();
  }

  bool has_number_field(std::string_view key) const {
    return this->contains(key) && this->at(key).is_number();
  }

  bool has_string_field(std::string_view key) const {
    return this->contains(key) && this->at(key).is_string();
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
                      __FILE__, __LINE__, __func__)};
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
