#pragma once

#ifndef _UNIHEADER_BUILD_
#include <concepts>
#include <format>
#include <iostream>
#include <limits>
#include <string>
#include <string_view>
#include <type_traits>
#include <variant>

#include <glaze/core/context.hpp>
#include <glaze/core/opts.hpp>
#include <glaze/core/read.hpp>
#include <glaze/glaze.hpp>
#include <glaze/json/json_t.hpp>
#include <glaze/json/ptr.hpp>

#include <nlohmann/json.hpp>
#include <nlohmann/json_fwd.hpp>
#endif

#include <falutez/falutez-types-std.hpp>

namespace XSON {

template <typename R>
concept aggregate_container = requires(R &r) { // no maps or other composites
  std::ranges::begin(r);
  std::ranges::end(r);
  *std::ranges::begin(r) == r[0];
} && (!std::is_scalar<std::decay_t<R>>::value);

template <typename R> struct is_aggregate_container : std::false_type {};

template <aggregate_container R>
struct is_aggregate_container<R> : std::true_type {};

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

  TXSONImpl{std::unordered_map<std::string, int>{}};
  TXSONImpl{std::map<std::string, int>{}};

  TXSONImpl::parse(std::string_view{});

  typename TXSONImpl::object_t;
  typename TXSONImpl::array_t;
};

struct NLH : public nlohmann::json {
  using object_t = nlohmann::json::object_t;
  using array_t = nlohmann::json::array_t;

  NLH() : nlohmann::json() {}

  NLH(nlohmann::json const &other) : nlohmann::json(other) {}

  NLH(nlohmann::json &&other) : nlohmann::json(std::move(other)) {}

  template <typename T, typename... Ts> NLH(std::variant<T, Ts...> &&other) {
    std::visit(
        [this](auto &&arg) {
          using U = std::decay_t<decltype(arg)>;
          *static_cast<nlohmann::json *>(this) = std::move(arg);
        },
        std::move(other));
  }

  template <typename T, typename... Ts>
  NLH(std::variant<T, Ts...> const &other) {
    std::visit(
        [this](auto &&arg) {
          using U = std::decay_t<decltype(arg)>;
          *static_cast<nlohmann::json *>(this) = arg;
        },
        other);
  }

  template <typename K, typename T, typename... Ts>
  NLH(std::unordered_map<K, std::variant<T, Ts...>> &&other) {}

  template <typename K, typename T, typename... Ts>
  NLH(std::map<K, std::variant<T, Ts...>> &&other) {
    for (auto &element : other) {
      std::visit(
          [this, element = std::move(element)](auto &&arg) {
            auto &self = *static_cast<nlohmann::json *>(this);
            using E = std::decay_t<decltype(arg)>;
            self[element.first] = std::move(std::get<E>(
                element.second)); // std::forward<decltype(arg)>(arg);
          },
          element.second);
    }
  }

  NLH(auto &&other) {
    using data_type = std::decay_t<decltype(other)>;

    if constexpr (std::is_same_v<data_type, NLH>) {
      auto &other_nlh = static_cast<NLH &>(other);

      if (other_nlh.is_object()) {
        *static_cast<nlohmann::json *>(this) =
            std::move(static_cast<object_t>(other_nlh.get_ref<object_t &>()));
      } else if (other_nlh.is_array()) {
        *static_cast<nlohmann::json *>(this) =
            std::move(static_cast<array_t>(other_nlh.get_ref<array_t &>()));
      } else {
        *static_cast<nlohmann::json *>(this) =
            std::move(static_cast<nlohmann::json &>(other));
      }
    } else {
      *static_cast<nlohmann::json *>(this) = std::move(other);
    }
  }

  NLH &operator=(auto &&other)
    requires(std::is_scalar_v<std::decay_t<decltype(other)>>)
  {
    *static_cast<nlohmann::json *>(this) = std::move(other);
    return *this;
  }

  NLH &operator=(HTTP::int128_t other) {
    *static_cast<nlohmann::json *>(this) = static_cast<double>(other);
    return *this;
  }

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

  NLH &operator[](std::integral auto idx) {
    return static_cast<NLH &>(nlohmann::json::operator[](idx));
  }

  NLH const &operator[](std::integral auto idx) const {
    return static_cast<NLH const &>(nlohmann::json::operator[](idx));
  }

  NLH &at(std::string_view key) {
    return static_cast<NLH &>(nlohmann::json::at(key));
  }

  NLH const &at(std::string_view key) const {
    return static_cast<NLH const &>(nlohmann::json::at(key));
  }

  NLH &at(std::integral auto idx) {
    return static_cast<NLH &>(nlohmann::json::at(idx));
  }

  NLH const &at(std::integral auto idx) const {
    return static_cast<NLH const &>(nlohmann::json::at(idx));
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

  bool operator==(aggregate_container auto const &other) const {
    if (this->is_array()) {
      auto const &self_arr = this->get_array();
      return std::equal(self_arr.begin(), self_arr.end(), other.begin(),
                        other.end());
    } else {
      return false;
    }
  }
};

struct GLZ : public glz::json_t {

  GLZ() = default;
  GLZ(GLZ const &other) : glz::json_t(other) {}
  GLZ(GLZ &&other) : glz::json_t(std::move(other)) {}

  template <std::convertible_to<glz::json_t> J>
  GLZ(J &&other) : glz::json_t(std::move(other)) {}

  template <typename T, typename... Ts> GLZ(std::variant<T, Ts...> &&other) {
    std::visit(
        [this](auto &&arg) {
          using U = std::decay_t<decltype(arg)>;
          *static_cast<glz::json_t *>(this) = std::move(arg);
        },
        std::move(other));
  }

  template <typename T, typename... Ts>
  GLZ(std::variant<T, Ts...> const &other) {
    std::visit(
        [this](auto &&arg) {
          using U = std::decay_t<decltype(arg)>;
          *static_cast<glz::json_t *>(this) = arg;
        },
        other);
  }

  // unordered_maps
  template <std::convertible_to<std::string_view> K, std::convertible_to<GLZ> U>
  GLZ(std::unordered_map<K, U> &&other) {
    *static_cast<json_t *>(this) = std::move(object_t{});
    for (auto &[key, value] : other) {
      (static_cast<json_t *>(this))->operator[](std::move(key)) =
          std::move(value);
    }
  }

  template <std::convertible_to<std::string_view> K, std::convertible_to<GLZ> U>
  GLZ(std::unordered_map<K, U> const &other) {
    *static_cast<json_t *>(this) = std::move(object_t{});
    for (auto &[key, value] : other) {
      (static_cast<json_t *>(this))->operator[](key) = value;
    }
  }

  // maps
  template <std::convertible_to<std::string_view> K, std::convertible_to<GLZ> U>
  GLZ(std::map<K, U> &&other) {
    *static_cast<json_t *>(this) = std::move(object_t{});
    for (auto &[key, value] : other) {
      this->operator[](std::move(key)) = std::move(value);
    }
  }

  template <std::convertible_to<std::string_view> K, std::convertible_to<GLZ> U>
  GLZ(std::map<K, U> const &other) {
    *static_cast<json_t *>(this) = std::move(object_t{});
    for (auto &[key, value] : other) {
      (static_cast<json_t *>(this))->operator[](key) = value;
    }
  }

  // map-like initializer lists
  GLZ(std::initializer_list<std::pair<
          std::string_view,
          std::variant<int64_t, uint64_t, int32_t, uint32_t, double, float,
                       bool, std::string_view, std::string, const char *, GLZ>>>
          &&other) {
    *static_cast<json_t *>(this) = std::move(object_t{});
    auto &self = *static_cast<json_t *>(this);

    for (auto &element : other) {
      auto content = std::move(element.second);
      auto key = std::move(element.first);

      if (std::holds_alternative<GLZ>(content)) {
        self[std::move(key)] = std::move(std::get<GLZ>(content));
      } else if (std::holds_alternative<std::string>(content)) {
        self[std::move(key)] = std::move(std::get<std::string>(content));
      } else {
        std::visit(
            [&self, &key](auto &&arg) {
              using T = std::decay_t<decltype(arg)>;
              if constexpr (std::is_same_v<T, const char *>) {
                self[std::move(key)] = std::string_view{arg};
              } else {
                self[std::move(key)] = std::forward<decltype(arg)>(arg);
              }
            },
            content);
      }
    }
  }

  template <typename T>
    requires(std::is_scalar_v<T>)
  GLZ(std::initializer_list<std::initializer_list<T>> &&other) {
    *static_cast<json_t *>(this) = std::move(array_t{});

    if (other.size() == 1) {
      for (auto &elm : *other.begin()) {
        (static_cast<json_t *>(this))->get_array().emplace_back(std::move(elm));
      }
    } else {
      auto new_subarray = array_t{};

      for (auto &v : other) {
        for (auto &elm : v) {
          new_subarray.emplace_back(std::move(elm));
        }

        (static_cast<json_t *>(this))
            ->get_array()
            .emplace_back(std::move(new_subarray));
      }
    }
  }

  GLZ(aggregate_container auto &&other) {
    *static_cast<json_t *>(this) = std::move(array_t{});
    for (auto const &val : other) {
      (static_cast<json_t *>(this))->get_array().emplace_back(std::move(val));
    }
  }

  template <aggregate_container A> GLZ(std::initializer_list<A> &&other) {
    *static_cast<json_t *>(this) = std::move(array_t{});

    auto new_array = array_t{};

    for (auto &v : other) {
      auto new_subarray = array_t{};
      for (auto &elm : v) {
        new_subarray.emplace_back(std::move(elm));
      }
      new_array.emplace_back(std::move(new_subarray));
    }

    *(static_cast<json_t *>(this)) =
        other.size() > 1 ? std::move(new_array) : std::move(new_array[0]);
  }

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

  static GLZ parse(std::string_view str) {
    GLZ json;
    json.deserialize(str);
    return json;
  }

  template <std::integral T> T get() const {
    return static_cast<T>(glz::json_t::get<double>());
  }

  template <std::floating_point F> F get() const {
    return static_cast<F>(glz::json_t::get<double>());
  }

  template <typename T>
    requires((!std::integral<T>) && (!std::floating_point<T>))
  T const &get() const {
    return glz::json_t::get<T>();
  }

  template <typename T>
    requires((!std::integral<T>) && (!std::floating_point<T>))
  T &get() {
    return glz::json_t::get<T>();
  }

  template <typename S>
    requires(std::convertible_to<S, std::string_view> && !std::integral<S>)
  GLZ &operator[](S &&key) {

    if (is_null()) {
      *static_cast<json_t *>(this) = glz::json_t::object_t{};
    }

    if (!is_object())
      throw std::runtime_error{
          std::format("{}:{}:{}: not an object; self={}; key={}", __FILE__,
                      __LINE__, __func__, serialize(), key)};

    using object_t = std::map<std::string, GLZ, std::less<>>;
    auto &self_obj = *reinterpret_cast<object_t *>(this);
    return self_obj[std::string{key}];
  }
  template <typename S>
    requires(std::convertible_to<S, std::string_view> && !std::integral<S>)
  GLZ const &operator[](S &&key) const {
    using object_t = std::map<std::string, GLZ, std::less<>>;
    if (!is_object())
      throw std::runtime_error{
          std::format("{}:{}:{}: not an object", __FILE__, __LINE__, __func__)};
    auto const &self_obj = *reinterpret_cast<object_t const *>(this);
    return self_obj.at(std::string{key});
  }

  GLZ const &operator[](std::integral auto idx) const {
    if (!is_array())
      throw std::runtime_error{
          std::format("{}:{}:{}: not an array", __FILE__, __LINE__, __func__)};
    using array_t = std::vector<GLZ>;
    auto const &self_arr = *reinterpret_cast<array_t const *>(this);
    return self_arr.at(idx);
  }

  GLZ &operator[](std::integral auto idx) {
    if (is_null()) {
      *static_cast<json_t *>(this) = array_t{};
    }
    if (!is_array())
      throw std::runtime_error{
          std::format("{}:{}:{}: not an array", __FILE__, __LINE__, __func__)};
    using array_t = std::vector<GLZ>;
    auto &self_arr = *reinterpret_cast<array_t *>(this);
    return self_arr.at(idx);
  }

  GLZ &at(std::string_view key) {
    using object_t = std::map<std::string, GLZ, std::less<>>;
    if (!is_object())
      throw std::runtime_error{
          std::format("{}:{}:{}: not an object", __FILE__, __LINE__, __func__)};
    auto &self_obj = *reinterpret_cast<object_t *>(this);
    return self_obj.at(std::string{key});
  }

  GLZ const &at(std::string_view key) const {
    using object_t = std::map<std::string, GLZ, std::less<>>;
    if (!is_object())
      throw std::runtime_error{
          std::format("{}:{}:{}: not an object", __FILE__, __LINE__, __func__)};
    auto const &self_obj = *reinterpret_cast<object_t const *>(this);
    return self_obj.at(std::string{key});
  }

  GLZ &at(std::integral auto idx) {
    if (!is_array())
      throw std::runtime_error{
          std::format("{}:{}:{}: not an array", __FILE__, __LINE__, __func__)};
    using array_t = std::vector<GLZ>;
    auto &self_arr = *reinterpret_cast<array_t *>(this);
    return self_arr.at(idx);
  }

  GLZ const &at(std::integral auto idx) const {
    if (!is_array())
      throw std::runtime_error{
          std::format("{}:{}:{}: not an array", __FILE__, __LINE__, __func__)};
    using array_t = std::vector<GLZ>;
    auto const &self_arr = *reinterpret_cast<array_t const *>(this);
    return self_arr.at(idx);
  }

  GLZ &operator=(const GLZ &other) {
    *static_cast<glz::json_t *>(this) = other;
    return *this;
  }

  GLZ &operator=(GLZ &&other) {
    *static_cast<glz::json_t *>(this) = std::move(other);
    return *this;
  }

  GLZ &operator=(glz::json_t const &other) {
    *static_cast<glz::json_t *>(this) = other;
    return *this;
  }

  GLZ &operator=(glz::json_t &&other) {
    *static_cast<glz::json_t *>(this) = std::move(other);
    return *this;
  }

  GLZ &operator=(glz::json_t::object_t const &other) {
    *static_cast<glz::json_t *>(this) = other;
    return *this;
  }

  GLZ &operator=(glz::json_t::object_t &&other) {
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

  template <typename T, typename... Ts>
  GLZ &operator=(std::variant<T, Ts...> &&other) {
    std::visit(
        [this](auto &&arg) {
          using U = std::decay_t<decltype(arg)>;
          *static_cast<glz::json_t *>(this) = std::move(arg);
        },
        std::move(other));
    return *this;
  }

  template <typename T, typename... Ts>
  GLZ &operator=(std::variant<T, Ts...> const &other) {
    std::visit(
        [this](auto &&arg) {
          using U = std::decay_t<decltype(arg)>;
          *static_cast<glz::json_t *>(this) = arg;
        },
        other);
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

  bool operator==(aggregate_container auto const &other) const {
    if (this->is_array() && other.size() == this->size()) {
      using array_t = std::vector<GLZ>;

      auto const &self_arr = *static_cast<const array_t *>(
          reinterpret_cast<const void *>(&this->get_array()));

      for (auto idx = 0; idx < self_arr.size(); ++idx) {
        auto const &my_elm = self_arr.at(idx);
        auto const &other_elm = other.at(idx);

        if (my_elm != other_elm)
          return false;
      }
      return true;
    } else {
      return false;
    }
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

  /// @TODO: re-enable once upstream deals with issue/PR
  // template <std::floating_point F> operator F() const {
  //   if (!is_number())
  //     throw std::runtime_error{
  //         std::format("{}:{}:{}: not a number", __FILE__, __LINE__,
  //         __func__)};
  //   return get_number();
  // }

  // template <std::integral I> operator I() const {
  //   if (!is_number())
  //     throw std::runtime_error{
  //         std::format("{}:{}:{}: not a number", __FILE__, __LINE__,
  //         __func__)};
  //   return get_number();
  // }

  // explicit operator std::string_view() const {
  //   if (!is_string())
  //     throw std::runtime_error{
  //         std::format("{}:{}:{}: not a string", __FILE__, __LINE__,
  //         __func__)};
  //   return get_string();
  // }

  // explicit operator std::string() const {
  //   if (!is_string())
  //     throw std::runtime_error{
  //         std::format("{}:{}:{}: not a string", __FILE__, __LINE__,
  //         __func__)};
  //   return get_string();
  // }

  // explicit operator std::pair<std::nullptr_t, std::nullptr_t>() const {
  //   if (!is_null())
  //     throw std::runtime_error{
  //         std::format("{}:{}:{}: not null", __FILE__, __LINE__, __func__)};
  //   return {nullptr, nullptr};
  // }

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
