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


namespace std {
typedef long unsigned int size_t;
typedef long int ptrdiff_t;

typedef decltype(nullptr) nullptr_t;

extern "C++" __attribute__((__noreturn__, __always_inline__)) inline void
__terminate() noexcept {
  void terminate() noexcept __attribute__((__noreturn__, __cold__));
  terminate();
}
} // namespace std
namespace std {
inline namespace __cxx11 __attribute__((__abi_tag__("cxx11"))) {}
} // namespace std
namespace __gnu_cxx {
inline namespace __cxx11 __attribute__((__abi_tag__("cxx11"))) {}
} // namespace __gnu_cxx
namespace std {

__attribute__((__always_inline__)) constexpr inline bool
__is_constant_evaluated() noexcept {

  return __builtin_is_constant_evaluated();
}
} // namespace std
namespace std {

extern "C++" __attribute__((__noreturn__)) void
__glibcxx_assert_fail(const char *__file, int __line, const char *__function,
                      const char *__condition) noexcept;
}
namespace std {
__attribute__((__always_inline__, __visibility__("default"))) inline void
__glibcxx_assert_fail() {}
} // namespace std

namespace __gnu_cxx {
typedef __decltype(0.0bf16) __bfloat16_t;
}

namespace std __attribute__((__visibility__("default"))) {

  template <class _E> class initializer_list {
  public:
    typedef _E value_type;
    typedef const _E &reference;
    typedef const _E &const_reference;
    typedef size_t size_type;
    typedef const _E *iterator;
    typedef const _E *const_iterator;

  private:
    iterator _M_array;
    size_type _M_len;

    constexpr initializer_list(const_iterator __a, size_type __l)
        : _M_array(__a), _M_len(__l) {}

  public:
    constexpr initializer_list() noexcept : _M_array(0), _M_len(0) {}

    constexpr size_type size() const noexcept { return _M_len; }

    constexpr const_iterator begin() const noexcept { return _M_array; }

    constexpr const_iterator end() const noexcept { return begin() + size(); }
  };

  template <class _Tp>
  constexpr const _Tp *begin(initializer_list<_Tp> __ils) noexcept {
    return __ils.begin();
  }

  template <class _Tp>
  constexpr const _Tp *end(initializer_list<_Tp> __ils) noexcept {
    return __ils.end();
  }
} // namespace std

namespace std __attribute__((__visibility__("default"))) {

  template <typename _Tp> class reference_wrapper;
  template <typename _Tp, _Tp __v> struct integral_constant {
    static constexpr _Tp value = __v;
    using value_type = _Tp;
    using type = integral_constant<_Tp, __v>;
    constexpr operator value_type() const noexcept { return value; }

    constexpr value_type operator()() const noexcept { return value; }
  };
  template <bool __v> using __bool_constant = integral_constant<bool, __v>;

  using true_type = __bool_constant<true>;

  using false_type = __bool_constant<false>;

  template <bool __v> using bool_constant = __bool_constant<__v>;

  template <bool, typename _Tp = void> struct enable_if {};

  template <typename _Tp> struct enable_if<true, _Tp> {
    using type = _Tp;
  };

  template <bool _Cond, typename _Tp = void>
  using __enable_if_t = typename enable_if<_Cond, _Tp>::type;

  template <bool> struct __conditional {
    template <typename _Tp, typename> using type = _Tp;
  };

  template <> struct __conditional<false> {
    template <typename, typename _Up> using type = _Up;
  };

  template <bool _Cond, typename _If, typename _Else>
  using __conditional_t =
      typename __conditional<_Cond>::template type<_If, _Else>;

  template <typename _Type> struct __type_identity {
    using type = _Type;
  };

  template <typename _Tp>
  using __type_identity_t = typename __type_identity<_Tp>::type;

  namespace __detail {

  template <typename _Tp, typename...> using __first_t = _Tp;

  template <typename... _Bn>
  auto __or_fn(int)
      -> __first_t<false_type, __enable_if_t<!bool(_Bn::value)>...>;

  template <typename... _Bn> auto __or_fn(...) -> true_type;

  template <typename... _Bn>
  auto __and_fn(int)
      -> __first_t<true_type, __enable_if_t<bool(_Bn::value)>...>;

  template <typename... _Bn> auto __and_fn(...) -> false_type;
  } // namespace __detail

  template <typename... _Bn>
  struct __or_ : decltype(__detail::__or_fn<_Bn...>(0)) {};

  template <typename... _Bn>
  struct __and_ : decltype(__detail::__and_fn<_Bn...>(0)) {};

  template <typename _Pp> struct __not_ : __bool_constant<!bool(_Pp::value)> {};

  template <typename... _Bn>
  inline constexpr bool __or_v = __or_<_Bn...>::value;
  template <typename... _Bn>
  inline constexpr bool __and_v = __and_<_Bn...>::value;

  namespace __detail {
  template <typename, typename _B1, typename... _Bn> struct __disjunction_impl {
    using type = _B1;
  };

  template <typename _B1, typename _B2, typename... _Bn>
  struct __disjunction_impl<__enable_if_t<!bool(_B1::value)>, _B1, _B2,
                            _Bn...> {
    using type = typename __disjunction_impl<void, _B2, _Bn...>::type;
  };

  template <typename, typename _B1, typename... _Bn> struct __conjunction_impl {
    using type = _B1;
  };

  template <typename _B1, typename _B2, typename... _Bn>
  struct __conjunction_impl<__enable_if_t<bool(_B1::value)>, _B1, _B2, _Bn...> {
    using type = typename __conjunction_impl<void, _B2, _Bn...>::type;
  };
  } // namespace __detail

  template <typename... _Bn>
  struct conjunction : __detail::__conjunction_impl<void, _Bn...>::type {};

  template <> struct conjunction<> : true_type {};

  template <typename... _Bn>
  struct disjunction : __detail::__disjunction_impl<void, _Bn...>::type {};

  template <> struct disjunction<> : false_type {};

  template <typename _Pp> struct negation : __not_<_Pp>::type {};

  template <typename... _Bn>
  inline constexpr bool conjunction_v = conjunction<_Bn...>::value;

  template <typename... _Bn>
  inline constexpr bool disjunction_v = disjunction<_Bn...>::value;

  template <typename _Pp>
  inline constexpr bool negation_v = negation<_Pp>::value;

  template <typename> struct is_reference;
  template <typename> struct is_function;
  template <typename> struct is_void;
  template <typename> struct remove_cv;
  template <typename> struct is_const;

  template <typename> struct __is_array_unknown_bounds;

  template <typename _Tp, size_t = sizeof(_Tp)>
  constexpr true_type __is_complete_or_unbounded(__type_identity<_Tp>) {
    return {};
  }

  template <typename _TypeIdentity,
            typename _NestedType = typename _TypeIdentity::type>
  constexpr typename __or_<is_reference<_NestedType>, is_function<_NestedType>,
                           is_void<_NestedType>,
                           __is_array_unknown_bounds<_NestedType>>::type
  __is_complete_or_unbounded(_TypeIdentity) {
    return {};
  }

  template <typename _Tp> using __remove_cv_t = typename remove_cv<_Tp>::type;

  template <typename _Tp> struct is_void : public false_type {};

  template <> struct is_void<void> : public true_type {};

  template <> struct is_void<const void> : public true_type {};

  template <> struct is_void<volatile void> : public true_type {};

  template <> struct is_void<const volatile void> : public true_type {};

  template <typename> struct __is_integral_helper : public false_type {};

  template <> struct __is_integral_helper<bool> : public true_type {};

  template <> struct __is_integral_helper<char> : public true_type {};

  template <> struct __is_integral_helper<signed char> : public true_type {};

  template <> struct __is_integral_helper<unsigned char> : public true_type {};

  template <> struct __is_integral_helper<wchar_t> : public true_type {};

  template <> struct __is_integral_helper<char8_t> : public true_type {};

  template <> struct __is_integral_helper<char16_t> : public true_type {};

  template <> struct __is_integral_helper<char32_t> : public true_type {};

  template <> struct __is_integral_helper<short> : public true_type {};

  template <> struct __is_integral_helper<unsigned short> : public true_type {};

  template <> struct __is_integral_helper<int> : public true_type {};

  template <> struct __is_integral_helper<unsigned int> : public true_type {};

  template <> struct __is_integral_helper<long> : public true_type {};

  template <> struct __is_integral_helper<unsigned long> : public true_type {};

  template <> struct __is_integral_helper<long long> : public true_type {};

  template <>
  struct __is_integral_helper<unsigned long long> : public true_type {};

  __extension__ template <>
  struct __is_integral_helper<__int128> : public true_type {};

  __extension__ template <>
  struct __is_integral_helper<unsigned __int128> : public true_type {};
  template <typename _Tp>
  struct is_integral : public __is_integral_helper<__remove_cv_t<_Tp>>::type {};

  template <typename> struct __is_floating_point_helper : public false_type {};

  template <> struct __is_floating_point_helper<float> : public true_type {};

  template <> struct __is_floating_point_helper<double> : public true_type {};

  template <>
  struct __is_floating_point_helper<long double> : public true_type {};
  template <>
  struct __is_floating_point_helper<__float128> : public true_type {};

  template <typename _Tp>
  struct is_floating_point
      : public __is_floating_point_helper<__remove_cv_t<_Tp>>::type {};

  template <typename _Tp>
  struct is_array : public __bool_constant<__is_array(_Tp)> {};
  template <typename> struct __is_pointer_helper : public false_type {};

  template <typename _Tp>
  struct __is_pointer_helper<_Tp *> : public true_type {};

  template <typename _Tp>
  struct is_pointer : public __is_pointer_helper<__remove_cv_t<_Tp>>::type {};

  template <typename> struct is_lvalue_reference : public false_type {};

  template <typename _Tp>
  struct is_lvalue_reference<_Tp &> : public true_type {};

  template <typename> struct is_rvalue_reference : public false_type {};

  template <typename _Tp>
  struct is_rvalue_reference<_Tp &&> : public true_type {};

  template <typename _Tp>
  struct is_member_object_pointer
      : public __bool_constant<__is_member_object_pointer(_Tp)> {};
  template <typename _Tp>
  struct is_member_function_pointer
      : public __bool_constant<__is_member_function_pointer(_Tp)> {};
  template <typename _Tp>
  struct is_enum : public __bool_constant<__is_enum(_Tp)> {};

  template <typename _Tp>
  struct is_union : public __bool_constant<__is_union(_Tp)> {};

  template <typename _Tp>
  struct is_class : public __bool_constant<__is_class(_Tp)> {};

  template <typename _Tp>
  struct is_function : public __bool_constant<__is_function(_Tp)> {};
  template <typename _Tp> struct is_null_pointer : public false_type {};

  template <> struct is_null_pointer<std::nullptr_t> : public true_type {};

  template <>
  struct is_null_pointer<const std::nullptr_t> : public true_type {};

  template <>
  struct is_null_pointer<volatile std::nullptr_t> : public true_type {};

  template <>
  struct is_null_pointer<const volatile std::nullptr_t> : public true_type {};

  template <typename _Tp> struct __is_nullptr_t : public is_null_pointer<_Tp> {
  } __attribute__((__deprecated__("use '"
                                  "std::is_null_pointer"
                                  "' instead")));

  template <typename _Tp>
  struct is_reference : public __bool_constant<__is_reference(_Tp)> {};
  template <typename _Tp>
  struct is_arithmetic
      : public __or_<is_integral<_Tp>, is_floating_point<_Tp>>::type {};

  template <typename _Tp>
  struct is_fundamental : public __or_<is_arithmetic<_Tp>, is_void<_Tp>,
                                       is_null_pointer<_Tp>>::type {};

  template <typename _Tp>
  struct is_object : public __bool_constant<__is_object(_Tp)> {};
  template <typename> struct is_member_pointer;

  template <typename _Tp>
  struct is_scalar
      : public __or_<is_arithmetic<_Tp>, is_enum<_Tp>, is_pointer<_Tp>,
                     is_member_pointer<_Tp>, is_null_pointer<_Tp>>::type {};

  template <typename _Tp>
  struct is_compound : public __bool_constant<!is_fundamental<_Tp>::value> {};

  template <typename _Tp>
  struct is_member_pointer : public __bool_constant<__is_member_pointer(_Tp)> {
  };
  template <typename, typename> struct is_same;

  template <typename _Tp, typename... _Types>
  using __is_one_of = __or_<is_same<_Tp, _Types>...>;

  __extension__ template <typename _Tp>
  using __is_signed_integer =
      __is_one_of<__remove_cv_t<_Tp>, signed char, signed short, signed int,
                  signed long, signed long long

                  ,
                  signed __int128>;

  __extension__ template <typename _Tp>
  using __is_unsigned_integer =
      __is_one_of<__remove_cv_t<_Tp>, unsigned char, unsigned short,
                  unsigned int, unsigned long, unsigned long long

                  ,
                  unsigned __int128>;

  template <typename _Tp>
  using __is_standard_integer =
      __or_<__is_signed_integer<_Tp>, __is_unsigned_integer<_Tp>>;

  template <typename...> using __void_t = void;

  template <typename> struct is_const : public false_type {};

  template <typename _Tp> struct is_const<_Tp const> : public true_type {};

  template <typename> struct is_volatile : public false_type {};

  template <typename _Tp>
  struct is_volatile<_Tp volatile> : public true_type {};

  template <typename _Tp>
  struct is_trivial : public __bool_constant<__is_trivial(_Tp)> {
    static_assert(
        std::__is_complete_or_unbounded(__type_identity<_Tp>{}),
        "template argument must be a complete class or an unbounded array");
  };

  template <typename _Tp>
  struct is_trivially_copyable
      : public __bool_constant<__is_trivially_copyable(_Tp)> {
    static_assert(
        std::__is_complete_or_unbounded(__type_identity<_Tp>{}),
        "template argument must be a complete class or an unbounded array");
  };

  template <typename _Tp>
  struct is_standard_layout
      : public __bool_constant<__is_standard_layout(_Tp)> {
    static_assert(
        std::__is_complete_or_unbounded(__type_identity<_Tp>{}),
        "template argument must be a complete class or an unbounded array");
  };

  template <typename _Tp>
  struct __attribute__((__deprecated__("use '"
                                       "is_standard_layout && is_trivial"
                                       "' instead"))) is_pod
      : public __bool_constant<__is_pod(_Tp)> {
    static_assert(
        std::__is_complete_or_unbounded(__type_identity<_Tp>{}),
        "template argument must be a complete class or an unbounded array");
  };

  template <typename _Tp>
  struct [[__deprecated__]] is_literal_type
      : public __bool_constant<__is_literal_type(_Tp)> {
    static_assert(
        std::__is_complete_or_unbounded(__type_identity<_Tp>{}),
        "template argument must be a complete class or an unbounded array");
  };

  template <typename _Tp>
  struct is_empty : public __bool_constant<__is_empty(_Tp)> {};

  template <typename _Tp>
  struct is_polymorphic : public __bool_constant<__is_polymorphic(_Tp)> {};

  template <typename _Tp>
  struct is_final : public __bool_constant<__is_final(_Tp)> {};

  template <typename _Tp>
  struct is_abstract : public __bool_constant<__is_abstract(_Tp)> {};

  template <typename _Tp, bool = is_arithmetic<_Tp>::value>
  struct __is_signed_helper : public false_type {};

  template <typename _Tp>
  struct __is_signed_helper<_Tp, true>
      : public __bool_constant<_Tp(-1) < _Tp(0)> {};

  template <typename _Tp>
  struct is_signed : public __is_signed_helper<_Tp>::type {};

  template <typename _Tp>
  struct is_unsigned
      : public __and_<is_arithmetic<_Tp>, __not_<is_signed<_Tp>>>::type {};

  template <typename _Tp, typename _Up = _Tp &&> _Up __declval(int);

  template <typename _Tp> _Tp __declval(long);

  template <typename _Tp>
  auto declval() noexcept -> decltype(__declval<_Tp>(0));

  template <typename> struct remove_all_extents;

  template <typename _Tp> struct __is_array_known_bounds : public false_type {};

  template <typename _Tp, size_t _Size>
  struct __is_array_known_bounds<_Tp[_Size]> : public true_type {};

  template <typename _Tp>
  struct __is_array_unknown_bounds : public false_type {};

  template <typename _Tp>
  struct __is_array_unknown_bounds<_Tp[]> : public true_type {};
  struct __do_is_destructible_impl {
    template <typename _Tp, typename = decltype(declval<_Tp &>().~_Tp())>
    static true_type __test(int);

    template <typename> static false_type __test(...);
  };

  template <typename _Tp>
  struct __is_destructible_impl : public __do_is_destructible_impl {
    using type = decltype(__test<_Tp>(0));
  };

  template <typename _Tp,
            bool = __or_<is_void<_Tp>, __is_array_unknown_bounds<_Tp>,
                         is_function<_Tp>>::value,
            bool = __or_<is_reference<_Tp>, is_scalar<_Tp>>::value>
  struct __is_destructible_safe;

  template <typename _Tp>
  struct __is_destructible_safe<_Tp, false, false>
      : public __is_destructible_impl<
            typename remove_all_extents<_Tp>::type>::type {};

  template <typename _Tp>
  struct __is_destructible_safe<_Tp, true, false> : public false_type {};

  template <typename _Tp>
  struct __is_destructible_safe<_Tp, false, true> : public true_type {};

  template <typename _Tp>
  struct is_destructible : public __is_destructible_safe<_Tp>::type {
    static_assert(
        std::__is_complete_or_unbounded(__type_identity<_Tp>{}),
        "template argument must be a complete class or an unbounded array");
  };

  struct __do_is_nt_destructible_impl {
    template <typename _Tp>
    static __bool_constant<noexcept(declval<_Tp &>().~_Tp())> __test(int);

    template <typename> static false_type __test(...);
  };

  template <typename _Tp>
  struct __is_nt_destructible_impl : public __do_is_nt_destructible_impl {
    using type = decltype(__test<_Tp>(0));
  };

  template <typename _Tp,
            bool = __or_<is_void<_Tp>, __is_array_unknown_bounds<_Tp>,
                         is_function<_Tp>>::value,
            bool = __or_<is_reference<_Tp>, is_scalar<_Tp>>::value>
  struct __is_nt_destructible_safe;

  template <typename _Tp>
  struct __is_nt_destructible_safe<_Tp, false, false>
      : public __is_nt_destructible_impl<
            typename remove_all_extents<_Tp>::type>::type {};

  template <typename _Tp>
  struct __is_nt_destructible_safe<_Tp, true, false> : public false_type {};

  template <typename _Tp>
  struct __is_nt_destructible_safe<_Tp, false, true> : public true_type {};

  template <typename _Tp>
  struct is_nothrow_destructible : public __is_nt_destructible_safe<_Tp>::type {
    static_assert(
        std::__is_complete_or_unbounded(__type_identity<_Tp>{}),
        "template argument must be a complete class or an unbounded array");
  };

  template <typename _Tp, typename... _Args>
  using __is_constructible_impl =
      __bool_constant<__is_constructible(_Tp, _Args...)>;

  template <typename _Tp, typename... _Args>
  struct is_constructible : public __is_constructible_impl<_Tp, _Args...> {
    static_assert(
        std::__is_complete_or_unbounded(__type_identity<_Tp>{}),
        "template argument must be a complete class or an unbounded array");
  };

  template <typename _Tp>
  struct is_default_constructible : public __is_constructible_impl<_Tp> {
    static_assert(
        std::__is_complete_or_unbounded(__type_identity<_Tp>{}),
        "template argument must be a complete class or an unbounded array");
  };

  template <typename _Tp, typename = void>
  struct __add_lvalue_reference_helper {
    using type = _Tp;
  };

  template <typename _Tp>
  struct __add_lvalue_reference_helper<_Tp, __void_t<_Tp &>> {
    using type = _Tp &;
  };

  template <typename _Tp>
  using __add_lval_ref_t = typename __add_lvalue_reference_helper<_Tp>::type;

  template <typename _Tp>
  struct is_copy_constructible
      : public __is_constructible_impl<_Tp, __add_lval_ref_t<const _Tp>> {
    static_assert(
        std::__is_complete_or_unbounded(__type_identity<_Tp>{}),
        "template argument must be a complete class or an unbounded array");
  };

  template <typename _Tp, typename = void>
  struct __add_rvalue_reference_helper {
    using type = _Tp;
  };

  template <typename _Tp>
  struct __add_rvalue_reference_helper<_Tp, __void_t<_Tp &&>> {
    using type = _Tp &&;
  };

  template <typename _Tp>
  using __add_rval_ref_t = typename __add_rvalue_reference_helper<_Tp>::type;

  template <typename _Tp>
  struct is_move_constructible
      : public __is_constructible_impl<_Tp, __add_rval_ref_t<_Tp>> {
    static_assert(
        std::__is_complete_or_unbounded(__type_identity<_Tp>{}),
        "template argument must be a complete class or an unbounded array");
  };

  template <typename _Tp, typename... _Args>
  using __is_nothrow_constructible_impl =
      __bool_constant<__is_nothrow_constructible(_Tp, _Args...)>;

  template <typename _Tp, typename... _Args>
  struct is_nothrow_constructible
      : public __is_nothrow_constructible_impl<_Tp, _Args...> {
    static_assert(
        std::__is_complete_or_unbounded(__type_identity<_Tp>{}),
        "template argument must be a complete class or an unbounded array");
  };

  template <typename _Tp>
  struct is_nothrow_default_constructible
      : public __is_nothrow_constructible_impl<_Tp> {
    static_assert(
        std::__is_complete_or_unbounded(__type_identity<_Tp>{}),
        "template argument must be a complete class or an unbounded array");
  };

  template <typename _Tp>
  struct is_nothrow_copy_constructible
      : public __is_nothrow_constructible_impl<_Tp,
                                               __add_lval_ref_t<const _Tp>> {
    static_assert(
        std::__is_complete_or_unbounded(__type_identity<_Tp>{}),
        "template argument must be a complete class or an unbounded array");
  };

  template <typename _Tp>
  struct is_nothrow_move_constructible
      : public __is_nothrow_constructible_impl<_Tp, __add_rval_ref_t<_Tp>> {
    static_assert(
        std::__is_complete_or_unbounded(__type_identity<_Tp>{}),
        "template argument must be a complete class or an unbounded array");
  };

  template <typename _Tp, typename _Up>
  using __is_assignable_impl = __bool_constant<__is_assignable(_Tp, _Up)>;

  template <typename _Tp, typename _Up>
  struct is_assignable : public __is_assignable_impl<_Tp, _Up> {
    static_assert(
        std::__is_complete_or_unbounded(__type_identity<_Tp>{}),
        "template argument must be a complete class or an unbounded array");
  };

  template <typename _Tp>
  struct is_copy_assignable
      : public __is_assignable_impl<__add_lval_ref_t<_Tp>,
                                    __add_lval_ref_t<const _Tp>> {
    static_assert(
        std::__is_complete_or_unbounded(__type_identity<_Tp>{}),
        "template argument must be a complete class or an unbounded array");
  };

  template <typename _Tp>
  struct is_move_assignable
      : public __is_assignable_impl<__add_lval_ref_t<_Tp>,
                                    __add_rval_ref_t<_Tp>> {
    static_assert(
        std::__is_complete_or_unbounded(__type_identity<_Tp>{}),
        "template argument must be a complete class or an unbounded array");
  };

  template <typename _Tp, typename _Up>
  using __is_nothrow_assignable_impl =
      __bool_constant<__is_nothrow_assignable(_Tp, _Up)>;

  template <typename _Tp, typename _Up>
  struct is_nothrow_assignable : public __is_nothrow_assignable_impl<_Tp, _Up> {
    static_assert(
        std::__is_complete_or_unbounded(__type_identity<_Tp>{}),
        "template argument must be a complete class or an unbounded array");
  };

  template <typename _Tp>
  struct is_nothrow_copy_assignable
      : public __is_nothrow_assignable_impl<__add_lval_ref_t<_Tp>,
                                            __add_lval_ref_t<const _Tp>> {
    static_assert(
        std::__is_complete_or_unbounded(__type_identity<_Tp>{}),
        "template argument must be a complete class or an unbounded array");
  };

  template <typename _Tp>
  struct is_nothrow_move_assignable
      : public __is_nothrow_assignable_impl<__add_lval_ref_t<_Tp>,
                                            __add_rval_ref_t<_Tp>> {
    static_assert(
        std::__is_complete_or_unbounded(__type_identity<_Tp>{}),
        "template argument must be a complete class or an unbounded array");
  };

  template <typename _Tp, typename... _Args>
  using __is_trivially_constructible_impl =
      __bool_constant<__is_trivially_constructible(_Tp, _Args...)>;

  template <typename _Tp, typename... _Args>
  struct is_trivially_constructible
      : public __is_trivially_constructible_impl<_Tp, _Args...> {
    static_assert(
        std::__is_complete_or_unbounded(__type_identity<_Tp>{}),
        "template argument must be a complete class or an unbounded array");
  };

  template <typename _Tp>
  struct is_trivially_default_constructible
      : public __is_trivially_constructible_impl<_Tp> {
    static_assert(
        std::__is_complete_or_unbounded(__type_identity<_Tp>{}),
        "template argument must be a complete class or an unbounded array");
  };

  template <typename _Tp>
  constexpr bool __is_implicitly_default_constructible_v =
      requires(void (&__f)(_Tp)) { __f({}); };

  template <typename _Tp>
  struct __is_implicitly_default_constructible
      : __bool_constant<__is_implicitly_default_constructible_v<_Tp>> {};
  template <typename _Tp>
  struct is_trivially_copy_constructible
      : public __is_trivially_constructible_impl<_Tp,
                                                 __add_lval_ref_t<const _Tp>> {
    static_assert(
        std::__is_complete_or_unbounded(__type_identity<_Tp>{}),
        "template argument must be a complete class or an unbounded array");
  };

  template <typename _Tp>
  struct is_trivially_move_constructible
      : public __is_trivially_constructible_impl<_Tp, __add_rval_ref_t<_Tp>> {
    static_assert(
        std::__is_complete_or_unbounded(__type_identity<_Tp>{}),
        "template argument must be a complete class or an unbounded array");
  };

  template <typename _Tp, typename _Up>
  using __is_trivially_assignable_impl =
      __bool_constant<__is_trivially_assignable(_Tp, _Up)>;

  template <typename _Tp, typename _Up>
  struct is_trivially_assignable
      : public __is_trivially_assignable_impl<_Tp, _Up> {
    static_assert(
        std::__is_complete_or_unbounded(__type_identity<_Tp>{}),
        "template argument must be a complete class or an unbounded array");
  };

  template <typename _Tp>
  struct is_trivially_copy_assignable
      : public __is_trivially_assignable_impl<__add_lval_ref_t<_Tp>,
                                              __add_lval_ref_t<const _Tp>> {
    static_assert(
        std::__is_complete_or_unbounded(__type_identity<_Tp>{}),
        "template argument must be a complete class or an unbounded array");
  };

  template <typename _Tp>
  struct is_trivially_move_assignable
      : public __is_trivially_assignable_impl<__add_lval_ref_t<_Tp>,
                                              __add_rval_ref_t<_Tp>> {
    static_assert(
        std::__is_complete_or_unbounded(__type_identity<_Tp>{}),
        "template argument must be a complete class or an unbounded array");
  };

  template <typename _Tp>
  struct is_trivially_destructible
      : public __and_<__is_destructible_safe<_Tp>,
                      __bool_constant<__has_trivial_destructor(_Tp)>>::type {
    static_assert(
        std::__is_complete_or_unbounded(__type_identity<_Tp>{}),
        "template argument must be a complete class or an unbounded array");
  };

  template <typename _Tp>
  struct has_virtual_destructor
      : public __bool_constant<__has_virtual_destructor(_Tp)> {
    static_assert(
        std::__is_complete_or_unbounded(__type_identity<_Tp>{}),
        "template argument must be a complete class or an unbounded array");
  };

  template <typename _Tp>
  struct alignment_of : public integral_constant<std::size_t, alignof(_Tp)> {
    static_assert(
        std::__is_complete_or_unbounded(__type_identity<_Tp>{}),
        "template argument must be a complete class or an unbounded array");
  };

  template <typename> struct rank : public integral_constant<std::size_t, 0> {};

  template <typename _Tp, std::size_t _Size>
  struct rank<_Tp[_Size]>
      : public integral_constant<std::size_t, 1 + rank<_Tp>::value> {};

  template <typename _Tp>
  struct rank<_Tp[]>
      : public integral_constant<std::size_t, 1 + rank<_Tp>::value> {};

  template <typename, unsigned _Uint = 0>
  struct extent : public integral_constant<size_t, 0> {};

  template <typename _Tp, size_t _Size>
  struct extent<_Tp[_Size], 0> : public integral_constant<size_t, _Size> {};

  template <typename _Tp, unsigned _Uint, size_t _Size>
  struct extent<_Tp[_Size], _Uint> : public extent<_Tp, _Uint - 1>::type {};

  template <typename _Tp>
  struct extent<_Tp[], 0> : public integral_constant<size_t, 0> {};

  template <typename _Tp, unsigned _Uint>
  struct extent<_Tp[], _Uint> : public extent<_Tp, _Uint - 1>::type {};

  template <typename _Tp, typename _Up>
  struct is_same : public __bool_constant<__is_same(_Tp, _Up)> {};
  template <typename _Base, typename _Derived>
  struct is_base_of : public __bool_constant<__is_base_of(_Base, _Derived)> {};

  template <typename _From, typename _To>
  struct is_convertible : public __bool_constant<__is_convertible(_From, _To)> {
  };
  template <typename _ToElementType, typename _FromElementType>
  using __is_array_convertible =
      is_convertible<_FromElementType(*)[], _ToElementType(*)[]>;

  template <typename _From, typename _To>
  inline constexpr bool is_nothrow_convertible_v =
      __is_nothrow_convertible(_From, _To);

  template <typename _From, typename _To>
  struct is_nothrow_convertible
      : public bool_constant<is_nothrow_convertible_v<_From, _To>> {};
  template <typename _Tp, typename... _Args>
  struct __is_nothrow_new_constructible_impl
      : __bool_constant<noexcept(::new (std::declval<void *>())
                                     _Tp(std::declval<_Args>()...))> {};

  template <typename _Tp, typename... _Args>
  inline constexpr bool __is_nothrow_new_constructible =
      __and_<is_constructible<_Tp, _Args...>,
             __is_nothrow_new_constructible_impl<_Tp, _Args...>>::value;

  template <typename _Tp> struct remove_const {
    using type = _Tp;
  };

  template <typename _Tp> struct remove_const<_Tp const> {
    using type = _Tp;
  };

  template <typename _Tp> struct remove_volatile {
    using type = _Tp;
  };

  template <typename _Tp> struct remove_volatile<_Tp volatile> {
    using type = _Tp;
  };

  template <typename _Tp> struct remove_cv {
    using type = __remove_cv(_Tp);
  };
  template <typename _Tp> struct add_const {
    using type = _Tp const;
  };

  template <typename _Tp> struct add_volatile {
    using type = _Tp volatile;
  };

  template <typename _Tp> struct add_cv {
    using type = _Tp const volatile;
  };

  template <typename _Tp>
  using remove_const_t = typename remove_const<_Tp>::type;

  template <typename _Tp>
  using remove_volatile_t = typename remove_volatile<_Tp>::type;

  template <typename _Tp> using remove_cv_t = typename remove_cv<_Tp>::type;

  template <typename _Tp> using add_const_t = typename add_const<_Tp>::type;

  template <typename _Tp>
  using add_volatile_t = typename add_volatile<_Tp>::type;

  template <typename _Tp> using add_cv_t = typename add_cv<_Tp>::type;

  template <typename _Tp> struct remove_reference {
    using type = __remove_reference(_Tp);
  };
  template <typename _Tp> struct add_lvalue_reference {
    using type = __add_lval_ref_t<_Tp>;
  };

  template <typename _Tp> struct add_rvalue_reference {
    using type = __add_rval_ref_t<_Tp>;
  };

  template <typename _Tp>
  using remove_reference_t = typename remove_reference<_Tp>::type;

  template <typename _Tp>
  using add_lvalue_reference_t = typename add_lvalue_reference<_Tp>::type;

  template <typename _Tp>
  using add_rvalue_reference_t = typename add_rvalue_reference<_Tp>::type;

  template <typename _Unqualified, bool _IsConst, bool _IsVol>
  struct __cv_selector;

  template <typename _Unqualified>
  struct __cv_selector<_Unqualified, false, false> {
    using __type = _Unqualified;
  };

  template <typename _Unqualified>
  struct __cv_selector<_Unqualified, false, true> {
    using __type = volatile _Unqualified;
  };

  template <typename _Unqualified>
  struct __cv_selector<_Unqualified, true, false> {
    using __type = const _Unqualified;
  };

  template <typename _Unqualified>
  struct __cv_selector<_Unqualified, true, true> {
    using __type = const volatile _Unqualified;
  };

  template <typename _Qualified, typename _Unqualified,
            bool _IsConst = is_const<_Qualified>::value,
            bool _IsVol = is_volatile<_Qualified>::value>
  class __match_cv_qualifiers {
    using __match = __cv_selector<_Unqualified, _IsConst, _IsVol>;

  public:
    using __type = typename __match::__type;
  };

  template <typename _Tp> struct __make_unsigned { using __type = _Tp; };

  template <> struct __make_unsigned<char> { using __type = unsigned char; };

  template <> struct __make_unsigned<signed char> {
    using __type = unsigned char;
  };

  template <> struct __make_unsigned<short> { using __type = unsigned short; };

  template <> struct __make_unsigned<int> { using __type = unsigned int; };

  template <> struct __make_unsigned<long> { using __type = unsigned long; };

  template <> struct __make_unsigned<long long> {
    using __type = unsigned long long;
  };

  __extension__ template <> struct __make_unsigned<__int128> {
    using __type = unsigned __int128;
  };
  template <typename _Tp, bool _IsInt = is_integral<_Tp>::value,
            bool _IsEnum = __is_enum(_Tp)>
  class __make_unsigned_selector;

  template <typename _Tp> class __make_unsigned_selector<_Tp, true, false> {
    using __unsigned_type =
        typename __make_unsigned<__remove_cv_t<_Tp>>::__type;

  public:
    using __type = typename __match_cv_qualifiers<_Tp, __unsigned_type>::__type;
  };

  class __make_unsigned_selector_base {
  protected:
    template <typename...> struct _List {};

    template <typename _Tp, typename... _Up>
    struct _List<_Tp, _Up...> : _List<_Up...> {
      static constexpr size_t __size = sizeof(_Tp);
    };

    template <size_t _Sz, typename _Tp, bool = (_Sz <= _Tp::__size)>
    struct __select;

    template <size_t _Sz, typename _Uint, typename... _UInts>
    struct __select<_Sz, _List<_Uint, _UInts...>, true> {
      using __type = _Uint;
    };

    template <size_t _Sz, typename _Uint, typename... _UInts>
    struct __select<_Sz, _List<_Uint, _UInts...>, false>
        : __select<_Sz, _List<_UInts...>> {};
  };

  template <typename _Tp>
  class __make_unsigned_selector<_Tp, false, true>
      : __make_unsigned_selector_base {

    using _UInts = _List<unsigned char, unsigned short, unsigned int,
                         unsigned long, unsigned long long>;

    using __unsigned_type = typename __select<sizeof(_Tp), _UInts>::__type;

  public:
    using __type = typename __match_cv_qualifiers<_Tp, __unsigned_type>::__type;
  };

  template <> struct __make_unsigned<wchar_t> {
    using __type =
        typename __make_unsigned_selector<wchar_t, false, true>::__type;
  };

  template <> struct __make_unsigned<char8_t> {
    using __type =
        typename __make_unsigned_selector<char8_t, false, true>::__type;
  };

  template <> struct __make_unsigned<char16_t> {
    using __type =
        typename __make_unsigned_selector<char16_t, false, true>::__type;
  };

  template <> struct __make_unsigned<char32_t> {
    using __type =
        typename __make_unsigned_selector<char32_t, false, true>::__type;
  };

  template <typename _Tp> struct make_unsigned {
    using type = typename __make_unsigned_selector<_Tp>::__type;
  };

  template <> struct make_unsigned<bool>;
  template <> struct make_unsigned<bool const>;
  template <> struct make_unsigned<bool volatile>;
  template <> struct make_unsigned<bool const volatile>;

  template <typename _Tp> struct __make_signed { using __type = _Tp; };

  template <> struct __make_signed<char> { using __type = signed char; };

  template <> struct __make_signed<unsigned char> {
    using __type = signed char;
  };

  template <> struct __make_signed<unsigned short> {
    using __type = signed short;
  };

  template <> struct __make_signed<unsigned int> { using __type = signed int; };

  template <> struct __make_signed<unsigned long> {
    using __type = signed long;
  };

  template <> struct __make_signed<unsigned long long> {
    using __type = signed long long;
  };

  __extension__ template <> struct __make_signed<unsigned __int128> {
    using __type = __int128;
  };
  template <typename _Tp, bool _IsInt = is_integral<_Tp>::value,
            bool _IsEnum = __is_enum(_Tp)>
  class __make_signed_selector;

  template <typename _Tp> class __make_signed_selector<_Tp, true, false> {
    using __signed_type = typename __make_signed<__remove_cv_t<_Tp>>::__type;

  public:
    using __type = typename __match_cv_qualifiers<_Tp, __signed_type>::__type;
  };

  template <typename _Tp> class __make_signed_selector<_Tp, false, true> {
    using __unsigned_type = typename __make_unsigned_selector<_Tp>::__type;

  public:
    using __type = typename __make_signed_selector<__unsigned_type>::__type;
  };

  template <> struct __make_signed<wchar_t> {
    using __type =
        typename __make_signed_selector<wchar_t, false, true>::__type;
  };

  template <> struct __make_signed<char8_t> {
    using __type =
        typename __make_signed_selector<char8_t, false, true>::__type;
  };

  template <> struct __make_signed<char16_t> {
    using __type =
        typename __make_signed_selector<char16_t, false, true>::__type;
  };

  template <> struct __make_signed<char32_t> {
    using __type =
        typename __make_signed_selector<char32_t, false, true>::__type;
  };

  template <typename _Tp> struct make_signed {
    using type = typename __make_signed_selector<_Tp>::__type;
  };

  template <> struct make_signed<bool>;
  template <> struct make_signed<bool const>;
  template <> struct make_signed<bool volatile>;
  template <> struct make_signed<bool const volatile>;

  template <typename _Tp> using make_signed_t = typename make_signed<_Tp>::type;

  template <typename _Tp>
  using make_unsigned_t = typename make_unsigned<_Tp>::type;

  template <typename _Tp> struct remove_extent {
    using type = _Tp;
  };

  template <typename _Tp, std::size_t _Size> struct remove_extent<_Tp[_Size]> {
    using type = _Tp;
  };

  template <typename _Tp> struct remove_extent<_Tp[]> {
    using type = _Tp;
  };

  template <typename _Tp> struct remove_all_extents {
    using type = _Tp;
  };

  template <typename _Tp, std::size_t _Size>
  struct remove_all_extents<_Tp[_Size]> {
    using type = typename remove_all_extents<_Tp>::type;
  };

  template <typename _Tp> struct remove_all_extents<_Tp[]> {
    using type = typename remove_all_extents<_Tp>::type;
  };

  template <typename _Tp>
  using remove_extent_t = typename remove_extent<_Tp>::type;

  template <typename _Tp>
  using remove_all_extents_t = typename remove_all_extents<_Tp>::type;

  template <typename _Tp> struct remove_pointer {
    using type = __remove_pointer(_Tp);
  };
  template <typename _Tp, typename = void> struct __add_pointer_helper {
    using type = _Tp;
  };

  template <typename _Tp> struct __add_pointer_helper<_Tp, __void_t<_Tp *>> {
    using type = _Tp *;
  };

  template <typename _Tp>
  struct add_pointer : public __add_pointer_helper<_Tp> {};

  template <typename _Tp> struct add_pointer<_Tp &> {
    using type = _Tp *;
  };

  template <typename _Tp> struct add_pointer<_Tp &&> {
    using type = _Tp *;
  };

  template <typename _Tp>
  using remove_pointer_t = typename remove_pointer<_Tp>::type;

  template <typename _Tp> using add_pointer_t = typename add_pointer<_Tp>::type;

  template <std::size_t _Len> struct __aligned_storage_msa {
    union __type {
      unsigned char __data[_Len];
      struct __attribute__((__aligned__)) {
      } __align;
    };
  };
  template <std::size_t _Len, std::size_t _Align = __alignof__(
                                  typename __aligned_storage_msa<_Len>::__type)>
  struct

      aligned_storage {
    union type {
      unsigned char __data[_Len];
      struct __attribute__((__aligned__((_Align)))) {
      } __align;
    };
  };

  template <typename... _Types> struct __strictest_alignment {
    static const size_t _S_alignment = 0;
    static const size_t _S_size = 0;
  };

  template <typename _Tp, typename... _Types>
  struct __strictest_alignment<_Tp, _Types...> {
    static const size_t
        _S_alignment = alignof(_Tp) >
                               __strictest_alignment<_Types...>::_S_alignment
                           ? alignof(_Tp)
                           : __strictest_alignment<_Types...>::_S_alignment;
    static const size_t
        _S_size = sizeof(_Tp) > __strictest_alignment<_Types...>::_S_size
                      ? sizeof(_Tp)
                      : __strictest_alignment<_Types...>::_S_size;
  };

  template <size_t _Len, typename... _Types>
  struct

      aligned_union {
  private:
    static_assert(sizeof...(_Types) != 0, "At least one type is required");

    using __strictest = __strictest_alignment<_Types...>;
    static const size_t _S_len =
        _Len > __strictest::_S_size ? _Len : __strictest::_S_size;

  public:
    static const size_t alignment_value = __strictest::_S_alignment;

    using type = typename aligned_storage<_S_len, alignment_value>::type;
  };

  template <size_t _Len, typename... _Types>
  const size_t aligned_union<_Len, _Types...>::alignment_value;

  template <typename _Up>
  struct __decay_selector : __conditional_t<is_const<const _Up>::value,
                                            remove_cv<_Up>, add_pointer<_Up>> {
  };

  template <typename _Up, size_t _Nm> struct __decay_selector<_Up[_Nm]> {
    using type = _Up *;
  };

  template <typename _Up> struct __decay_selector<_Up[]> {
    using type = _Up *;
  };

  template <typename _Tp> struct decay {
    using type = typename __decay_selector<_Tp>::type;
  };

  template <typename _Tp> struct decay<_Tp &> {
    using type = typename __decay_selector<_Tp>::type;
  };

  template <typename _Tp> struct decay<_Tp &&> {
    using type = typename __decay_selector<_Tp>::type;
  };

  template <typename _Tp> struct __strip_reference_wrapper {
    using __type = _Tp;
  };

  template <typename _Tp>
  struct __strip_reference_wrapper<reference_wrapper<_Tp>> {
    using __type = _Tp &;
  };

  template <typename _Tp> using __decay_t = typename decay<_Tp>::type;

  template <typename _Tp>
  using __decay_and_strip = __strip_reference_wrapper<__decay_t<_Tp>>;

  template <typename... _Cond>
  using _Require = __enable_if_t<__and_<_Cond...>::value>;

  template <typename _Tp>
  using __remove_cvref_t =
      typename remove_cv<typename remove_reference<_Tp>::type>::type;

  template <bool _Cond, typename _Iftrue, typename _Iffalse>
  struct conditional {
    using type = _Iftrue;
  };

  template <typename _Iftrue, typename _Iffalse>
  struct conditional<false, _Iftrue, _Iffalse> {
    using type = _Iffalse;
  };

  template <typename... _Tp> struct common_type;
  template <typename _Tp> struct __success_type {
    using type = _Tp;
  };

  struct __failure_type {};

  struct __do_common_type_impl {
    template <typename _Tp, typename _Up>
    using __cond_t = decltype(true ? std::declval<_Tp>() : std::declval<_Up>());

    template <typename _Tp, typename _Up>
    static __success_type<__decay_t<__cond_t<_Tp, _Up>>> _S_test(int);

    template <typename _Tp, typename _Up>
    static __success_type<__remove_cvref_t<__cond_t<const _Tp &, const _Up &>>>
    _S_test_2(int);

    template <typename, typename> static __failure_type _S_test_2(...);

    template <typename _Tp, typename _Up>
    static decltype(_S_test_2<_Tp, _Up>(0)) _S_test(...);
  };

  template <> struct common_type<> {};

  template <typename _Tp0>
  struct common_type<_Tp0> : public common_type<_Tp0, _Tp0> {};

  template <typename _Tp1, typename _Tp2, typename _Dp1 = __decay_t<_Tp1>,
            typename _Dp2 = __decay_t<_Tp2>>
  struct __common_type_impl {

    using type = common_type<_Dp1, _Dp2>;
  };

  template <typename _Tp1, typename _Tp2>
  struct __common_type_impl<_Tp1, _Tp2, _Tp1, _Tp2>
      : private __do_common_type_impl {

    using type = decltype(_S_test<_Tp1, _Tp2>(0));
  };

  template <typename _Tp1, typename _Tp2>
  struct common_type<_Tp1, _Tp2> : public __common_type_impl<_Tp1, _Tp2>::type {
  };

  template <typename...> struct __common_type_pack {};

  template <typename, typename, typename = void> struct __common_type_fold;

  template <typename _Tp1, typename _Tp2, typename... _Rp>
  struct common_type<_Tp1, _Tp2, _Rp...>
      : public __common_type_fold<common_type<_Tp1, _Tp2>,
                                  __common_type_pack<_Rp...>> {};

  template <typename _CTp, typename... _Rp>
  struct __common_type_fold<_CTp, __common_type_pack<_Rp...>,
                            __void_t<typename _CTp::type>>
      : public common_type<typename _CTp::type, _Rp...> {};

  template <typename _CTp, typename _Rp>
  struct __common_type_fold<_CTp, _Rp, void> {};

  template <typename _Tp, bool = __is_enum(_Tp)> struct __underlying_type_impl {
    using type = __underlying_type(_Tp);
  };

  template <typename _Tp> struct __underlying_type_impl<_Tp, false> {};

  template <typename _Tp>
  struct underlying_type : public __underlying_type_impl<_Tp> {};

  template <typename _Tp> struct __declval_protector {
    static const bool __stop = false;
  };

  template <typename _Tp>
  auto declval() noexcept -> decltype(__declval<_Tp>(0)) {
    static_assert(__declval_protector<_Tp>::__stop,
                  "declval() must not be used!");
    return __declval<_Tp>(0);
  }

  template <typename _Signature> struct result_of;

  struct __invoke_memfun_ref {};
  struct __invoke_memfun_deref {};
  struct __invoke_memobj_ref {};
  struct __invoke_memobj_deref {};
  struct __invoke_other {};

  template <typename _Tp, typename _Tag>
  struct __result_of_success : __success_type<_Tp> {
    using __invoke_type = _Tag;
  };

  struct __result_of_memfun_ref_impl {
    template <typename _Fp, typename _Tp1, typename... _Args>
    static __result_of_success<
        decltype((std::declval<_Tp1>().*
                  std::declval<_Fp>())(std::declval<_Args>()...)),
        __invoke_memfun_ref>
    _S_test(int);

    template <typename...> static __failure_type _S_test(...);
  };

  template <typename _MemPtr, typename _Arg, typename... _Args>
  struct __result_of_memfun_ref : private __result_of_memfun_ref_impl {
    using type = decltype(_S_test<_MemPtr, _Arg, _Args...>(0));
  };

  struct __result_of_memfun_deref_impl {
    template <typename _Fp, typename _Tp1, typename... _Args>
    static __result_of_success<
        decltype(((*std::declval<_Tp1>()).*
                  std::declval<_Fp>())(std::declval<_Args>()...)),
        __invoke_memfun_deref>
    _S_test(int);

    template <typename...> static __failure_type _S_test(...);
  };

  template <typename _MemPtr, typename _Arg, typename... _Args>
  struct __result_of_memfun_deref : private __result_of_memfun_deref_impl {
    using type = decltype(_S_test<_MemPtr, _Arg, _Args...>(0));
  };

  struct __result_of_memobj_ref_impl {
    template <typename _Fp, typename _Tp1>
    static __result_of_success<decltype(std::declval<_Tp1>().*
                                        std::declval<_Fp>()),
                               __invoke_memobj_ref>
    _S_test(int);

    template <typename, typename> static __failure_type _S_test(...);
  };

  template <typename _MemPtr, typename _Arg>
  struct __result_of_memobj_ref : private __result_of_memobj_ref_impl {
    using type = decltype(_S_test<_MemPtr, _Arg>(0));
  };

  struct __result_of_memobj_deref_impl {
    template <typename _Fp, typename _Tp1>
    static __result_of_success<decltype((*std::declval<_Tp1>()).*
                                        std::declval<_Fp>()),
                               __invoke_memobj_deref>
    _S_test(int);

    template <typename, typename> static __failure_type _S_test(...);
  };

  template <typename _MemPtr, typename _Arg>
  struct __result_of_memobj_deref : private __result_of_memobj_deref_impl {
    using type = decltype(_S_test<_MemPtr, _Arg>(0));
  };

  template <typename _MemPtr, typename _Arg> struct __result_of_memobj;

  template <typename _Res, typename _Class, typename _Arg>
  struct __result_of_memobj<_Res _Class::*, _Arg> {
    using _Argval = __remove_cvref_t<_Arg>;
    using _MemPtr = _Res _Class::*;
    using type = typename __conditional_t<
        __or_<is_same<_Argval, _Class>, is_base_of<_Class, _Argval>>::value,
        __result_of_memobj_ref<_MemPtr, _Arg>,
        __result_of_memobj_deref<_MemPtr, _Arg>>::type;
  };

  template <typename _MemPtr, typename _Arg, typename... _Args>
  struct __result_of_memfun;

  template <typename _Res, typename _Class, typename _Arg, typename... _Args>
  struct __result_of_memfun<_Res _Class::*, _Arg, _Args...> {
    using _Argval = typename remove_reference<_Arg>::type;
    using _MemPtr = _Res _Class::*;
    using type = typename __conditional_t<
        is_base_of<_Class, _Argval>::value,
        __result_of_memfun_ref<_MemPtr, _Arg, _Args...>,
        __result_of_memfun_deref<_MemPtr, _Arg, _Args...>>::type;
  };

  template <typename _Tp, typename _Up = __remove_cvref_t<_Tp>>
  struct __inv_unwrap {
    using type = _Tp;
  };

  template <typename _Tp, typename _Up>
  struct __inv_unwrap<_Tp, reference_wrapper<_Up>> {
    using type = _Up &;
  };

  template <bool, bool, typename _Functor, typename... _ArgTypes>
  struct __result_of_impl {
    using type = __failure_type;
  };

  template <typename _MemPtr, typename _Arg>
  struct __result_of_impl<true, false, _MemPtr, _Arg>
      : public __result_of_memobj<__decay_t<_MemPtr>,
                                  typename __inv_unwrap<_Arg>::type> {};

  template <typename _MemPtr, typename _Arg, typename... _Args>
  struct __result_of_impl<false, true, _MemPtr, _Arg, _Args...>
      : public __result_of_memfun<__decay_t<_MemPtr>,
                                  typename __inv_unwrap<_Arg>::type, _Args...> {
  };

  struct __result_of_other_impl {
    template <typename _Fn, typename... _Args>
    static __result_of_success<
        decltype(std::declval<_Fn>()(std::declval<_Args>()...)), __invoke_other>
    _S_test(int);

    template <typename...> static __failure_type _S_test(...);
  };

  template <typename _Functor, typename... _ArgTypes>
  struct __result_of_impl<false, false, _Functor, _ArgTypes...>
      : private __result_of_other_impl {
    using type = decltype(_S_test<_Functor, _ArgTypes...>(0));
  };

  template <typename _Functor, typename... _ArgTypes>
  struct __invoke_result
      : public __result_of_impl<
            is_member_object_pointer<
                typename remove_reference<_Functor>::type>::value,
            is_member_function_pointer<
                typename remove_reference<_Functor>::type>::value,
            _Functor, _ArgTypes...>::type {};

  template <typename _Fn, typename... _Args>
  using __invoke_result_t = typename __invoke_result<_Fn, _Args...>::type;

  template <typename _Functor, typename... _ArgTypes>
  struct result_of<_Functor(_ArgTypes...)>
      : public __invoke_result<_Functor, _ArgTypes...> {
  } __attribute__((__deprecated__("use '"
                                  "std::invoke_result"
                                  "' instead")));

  template <size_t _Len, size_t _Align = __alignof__(
                             typename __aligned_storage_msa<_Len>::__type)>
  using aligned_storage_t = typename aligned_storage<_Len, _Align>::type;

  template <size_t _Len, typename... _Types>
  using aligned_union_t = typename aligned_union<_Len, _Types...>::type;

  template <typename _Tp> using decay_t = typename decay<_Tp>::type;

  template <bool _Cond, typename _Tp = void>
  using enable_if_t = typename enable_if<_Cond, _Tp>::type;

  template <bool _Cond, typename _Iftrue, typename _Iffalse>
  using conditional_t = typename conditional<_Cond, _Iftrue, _Iffalse>::type;

  template <typename... _Tp>
  using common_type_t = typename common_type<_Tp...>::type;

  template <typename _Tp>
  using underlying_type_t = typename underlying_type<_Tp>::type;

  template <typename _Tp> using result_of_t = typename result_of<_Tp>::type;

  template <typename...> using void_t = void;
  template <typename _Def, template <typename...> class _Op, typename... _Args>
  struct __detected_or {
    using type = _Def;
    using __is_detected = false_type;
  };

  template <typename _Def, template <typename...> class _Op, typename... _Args>
    requires requires { typename _Op<_Args...>; }
  struct __detected_or<_Def, _Op, _Args...> {
    using type = _Op<_Args...>;
    using __is_detected = true_type;
  };
  template <typename _Default, template <typename...> class _Op,
            typename... _Args>
  using __detected_or_t = typename __detected_or<_Default, _Op, _Args...>::type;
  template <typename _Tp> struct __is_swappable;

  template <typename _Tp> struct __is_nothrow_swappable;

  template <typename> struct __is_tuple_like_impl : false_type {};

  template <typename _Tp>
  struct __is_tuple_like
      : public __is_tuple_like_impl<__remove_cvref_t<_Tp>>::type {};

  template <typename _Tp>
  constexpr inline _Require<__not_<__is_tuple_like<_Tp>>,
                            is_move_constructible<_Tp>, is_move_assignable<_Tp>>
  swap(_Tp &, _Tp &) noexcept(__and_<is_nothrow_move_constructible<_Tp>,
                                     is_nothrow_move_assignable<_Tp>>::value);

  template <typename _Tp, size_t _Nm>
  constexpr inline __enable_if_t<__is_swappable<_Tp>::value> swap(
      _Tp(&__a)[_Nm],
      _Tp(&__b)[_Nm]) noexcept(__is_nothrow_swappable<_Tp>::value);

  namespace __swappable_details {
  using std::swap;

  struct __do_is_swappable_impl {
    template <typename _Tp, typename = decltype(swap(std::declval<_Tp &>(),
                                                     std::declval<_Tp &>()))>
    static true_type __test(int);

    template <typename> static false_type __test(...);
  };

  struct __do_is_nothrow_swappable_impl {
    template <typename _Tp>
    static __bool_constant<noexcept(swap(std::declval<_Tp &>(),
                                         std::declval<_Tp &>()))>
    __test(int);

    template <typename> static false_type __test(...);
  };

  } // namespace __swappable_details

  template <typename _Tp>
  struct __is_swappable_impl
      : public __swappable_details::__do_is_swappable_impl {
    using type = decltype(__test<_Tp>(0));
  };

  template <typename _Tp>
  struct __is_nothrow_swappable_impl
      : public __swappable_details::__do_is_nothrow_swappable_impl {
    using type = decltype(__test<_Tp>(0));
  };

  template <typename _Tp>
  struct __is_swappable : public __is_swappable_impl<_Tp>::type {};

  template <typename _Tp>
  struct __is_nothrow_swappable
      : public __is_nothrow_swappable_impl<_Tp>::type {};

  template <typename _Tp>
  struct is_swappable : public __is_swappable_impl<_Tp>::type {
    static_assert(
        std::__is_complete_or_unbounded(__type_identity<_Tp>{}),
        "template argument must be a complete class or an unbounded array");
  };

  template <typename _Tp>
  struct is_nothrow_swappable : public __is_nothrow_swappable_impl<_Tp>::type {
    static_assert(
        std::__is_complete_or_unbounded(__type_identity<_Tp>{}),
        "template argument must be a complete class or an unbounded array");
  };

  template <typename _Tp>
  inline constexpr bool is_swappable_v = is_swappable<_Tp>::value;

  template <typename _Tp>
  inline constexpr bool is_nothrow_swappable_v =
      is_nothrow_swappable<_Tp>::value;

  namespace __swappable_with_details {
  using std::swap;

  struct __do_is_swappable_with_impl {
    template <
        typename _Tp, typename _Up,
        typename = decltype(swap(std::declval<_Tp>(), std::declval<_Up>())),
        typename = decltype(swap(std::declval<_Up>(), std::declval<_Tp>()))>
    static true_type __test(int);

    template <typename, typename> static false_type __test(...);
  };

  struct __do_is_nothrow_swappable_with_impl {
    template <typename _Tp, typename _Up>
    static __bool_constant<
        noexcept(swap(std::declval<_Tp>(), std::declval<_Up>())) &&
        noexcept(swap(std::declval<_Up>(), std::declval<_Tp>()))>
    __test(int);

    template <typename, typename> static false_type __test(...);
  };

  } // namespace __swappable_with_details

  template <typename _Tp, typename _Up>
  struct __is_swappable_with_impl
      : public __swappable_with_details::__do_is_swappable_with_impl {
    using type = decltype(__test<_Tp, _Up>(0));
  };

  template <typename _Tp>
  struct __is_swappable_with_impl<_Tp &, _Tp &>
      : public __swappable_details::__do_is_swappable_impl {
    using type = decltype(__test<_Tp &>(0));
  };

  template <typename _Tp, typename _Up>
  struct __is_nothrow_swappable_with_impl
      : public __swappable_with_details::__do_is_nothrow_swappable_with_impl {
    using type = decltype(__test<_Tp, _Up>(0));
  };

  template <typename _Tp>
  struct __is_nothrow_swappable_with_impl<_Tp &, _Tp &>
      : public __swappable_details::__do_is_nothrow_swappable_impl {
    using type = decltype(__test<_Tp &>(0));
  };

  template <typename _Tp, typename _Up>
  struct is_swappable_with : public __is_swappable_with_impl<_Tp, _Up>::type {
    static_assert(std::__is_complete_or_unbounded(__type_identity<_Tp>{}),
                  "first template argument must be a complete class or an "
                  "unbounded array");
    static_assert(std::__is_complete_or_unbounded(__type_identity<_Up>{}),
                  "second template argument must be a complete class or an "
                  "unbounded array");
  };

  template <typename _Tp, typename _Up>
  struct is_nothrow_swappable_with
      : public __is_nothrow_swappable_with_impl<_Tp, _Up>::type {
    static_assert(std::__is_complete_or_unbounded(__type_identity<_Tp>{}),
                  "first template argument must be a complete class or an "
                  "unbounded array");
    static_assert(std::__is_complete_or_unbounded(__type_identity<_Up>{}),
                  "second template argument must be a complete class or an "
                  "unbounded array");
  };

  template <typename _Tp, typename _Up>
  inline constexpr bool is_swappable_with_v =
      is_swappable_with<_Tp, _Up>::value;

  template <typename _Tp, typename _Up>
  inline constexpr bool is_nothrow_swappable_with_v =
      is_nothrow_swappable_with<_Tp, _Up>::value;
  template <typename _Result, typename _Ret, bool = is_void<_Ret>::value,
            typename = void>
  struct __is_invocable_impl : false_type {
    using __nothrow_conv = false_type;
  };

  template <typename _Result, typename _Ret>
  struct __is_invocable_impl<_Result, _Ret, true,
                             __void_t<typename _Result::type>> : true_type {
    using __nothrow_conv = true_type;
  };

  template <typename _Result, typename _Ret>
  struct __is_invocable_impl<_Result, _Ret, false,
                             __void_t<typename _Result::type>> {
  private:
    using _Res_t = typename _Result::type;

    static _Res_t _S_get() noexcept;

    template <typename _Tp>
    static void _S_conv(__type_identity_t<_Tp>) noexcept;

    template <typename _Tp, bool _Nothrow = noexcept(_S_conv<_Tp>(_S_get())),
              typename = decltype(_S_conv<_Tp>(_S_get())),

              bool _Dangle = __reference_converts_from_temporary(_Tp, _Res_t)

              >
    static __bool_constant<_Nothrow && !_Dangle> _S_test(int);

    template <typename _Tp, bool = false> static false_type _S_test(...);

  public:
    using type = decltype(_S_test<_Ret, true>(1));

    using __nothrow_conv = decltype(_S_test<_Ret>(1));
  };

  template <typename _Fn, typename... _ArgTypes>
  struct __is_invocable
      : __is_invocable_impl<__invoke_result<_Fn, _ArgTypes...>, void>::type {};

  template <typename _Fn, typename _Tp, typename... _Args>
  constexpr bool __call_is_nt(__invoke_memfun_ref) {
    using _Up = typename __inv_unwrap<_Tp>::type;
    return noexcept(
        (std::declval<_Up>().*std::declval<_Fn>())(std::declval<_Args>()...));
  }

  template <typename _Fn, typename _Tp, typename... _Args>
  constexpr bool __call_is_nt(__invoke_memfun_deref) {
    return noexcept(((*std::declval<_Tp>()).*
                     std::declval<_Fn>())(std::declval<_Args>()...));
  }

  template <typename _Fn, typename _Tp>
  constexpr bool __call_is_nt(__invoke_memobj_ref) {
    using _Up = typename __inv_unwrap<_Tp>::type;
    return noexcept(std::declval<_Up>().*std::declval<_Fn>());
  }

  template <typename _Fn, typename _Tp>
  constexpr bool __call_is_nt(__invoke_memobj_deref) {
    return noexcept((*std::declval<_Tp>()).*std::declval<_Fn>());
  }

  template <typename _Fn, typename... _Args>
  constexpr bool __call_is_nt(__invoke_other) {
    return noexcept(std::declval<_Fn>()(std::declval<_Args>()...));
  }

  template <typename _Result, typename _Fn, typename... _Args>
  struct __call_is_nothrow : __bool_constant<std::__call_is_nt<_Fn, _Args...>(
                                 typename _Result::__invoke_type{})> {};

  template <typename _Fn, typename... _Args>
  using __call_is_nothrow_ =
      __call_is_nothrow<__invoke_result<_Fn, _Args...>, _Fn, _Args...>;

  template <typename _Fn, typename... _Args>
  struct __is_nothrow_invocable
      : __and_<__is_invocable<_Fn, _Args...>,
               __call_is_nothrow_<_Fn, _Args...>>::type {};

  struct __nonesuchbase {};
  struct __nonesuch : private __nonesuchbase {
    ~__nonesuch() = delete;
    __nonesuch(__nonesuch const &) = delete;
    void operator=(__nonesuch const &) = delete;
  };

  template <typename _Functor, typename... _ArgTypes>
  struct invoke_result : public __invoke_result<_Functor, _ArgTypes...> {
    static_assert(std::__is_complete_or_unbounded(__type_identity<_Functor>{}),
                  "_Functor must be a complete class or an unbounded array");
    static_assert(
        (std::__is_complete_or_unbounded(__type_identity<_ArgTypes>{}) && ...),
        "each argument type must be a complete class or an unbounded array");
  };

  template <typename _Fn, typename... _Args>
  using invoke_result_t = typename invoke_result<_Fn, _Args...>::type;

  template <typename _Fn, typename... _ArgTypes>
  struct is_invocable
      : __is_invocable_impl<__invoke_result<_Fn, _ArgTypes...>, void>::type {
    static_assert(std::__is_complete_or_unbounded(__type_identity<_Fn>{}),
                  "_Fn must be a complete class or an unbounded array");
    static_assert(
        (std::__is_complete_or_unbounded(__type_identity<_ArgTypes>{}) && ...),
        "each argument type must be a complete class or an unbounded array");
  };

  template <typename _Ret, typename _Fn, typename... _ArgTypes>
  struct is_invocable_r
      : __is_invocable_impl<__invoke_result<_Fn, _ArgTypes...>, _Ret>::type {
    static_assert(std::__is_complete_or_unbounded(__type_identity<_Fn>{}),
                  "_Fn must be a complete class or an unbounded array");
    static_assert(
        (std::__is_complete_or_unbounded(__type_identity<_ArgTypes>{}) && ...),
        "each argument type must be a complete class or an unbounded array");
    static_assert(std::__is_complete_or_unbounded(__type_identity<_Ret>{}),
                  "_Ret must be a complete class or an unbounded array");
  };

  template <typename _Fn, typename... _ArgTypes>
  struct is_nothrow_invocable
      : __and_<__is_invocable_impl<__invoke_result<_Fn, _ArgTypes...>, void>,
               __call_is_nothrow_<_Fn, _ArgTypes...>>::type {
    static_assert(std::__is_complete_or_unbounded(__type_identity<_Fn>{}),
                  "_Fn must be a complete class or an unbounded array");
    static_assert(
        (std::__is_complete_or_unbounded(__type_identity<_ArgTypes>{}) && ...),
        "each argument type must be a complete class or an unbounded array");
  };

  template <typename _Result, typename _Ret>
  using __is_nt_invocable_impl =
      typename __is_invocable_impl<_Result, _Ret>::__nothrow_conv;

  template <typename _Ret, typename _Fn, typename... _ArgTypes>
  struct is_nothrow_invocable_r
      : __and_<__is_nt_invocable_impl<__invoke_result<_Fn, _ArgTypes...>, _Ret>,
               __call_is_nothrow_<_Fn, _ArgTypes...>>::type {
    static_assert(std::__is_complete_or_unbounded(__type_identity<_Fn>{}),
                  "_Fn must be a complete class or an unbounded array");
    static_assert(
        (std::__is_complete_or_unbounded(__type_identity<_ArgTypes>{}) && ...),
        "each argument type must be a complete class or an unbounded array");
    static_assert(std::__is_complete_or_unbounded(__type_identity<_Ret>{}),
                  "_Ret must be a complete class or an unbounded array");
  };
  template <typename _Tp> inline constexpr bool is_void_v = is_void<_Tp>::value;
  template <typename _Tp>
  inline constexpr bool is_null_pointer_v = is_null_pointer<_Tp>::value;
  template <typename _Tp>
  inline constexpr bool is_integral_v = is_integral<_Tp>::value;
  template <typename _Tp>
  inline constexpr bool is_floating_point_v = is_floating_point<_Tp>::value;

  template <typename _Tp> inline constexpr bool is_array_v = __is_array(_Tp);
  template <typename _Tp>
  inline constexpr bool is_pointer_v = is_pointer<_Tp>::value;
  template <typename _Tp> inline constexpr bool is_lvalue_reference_v = false;
  template <typename _Tp>
  inline constexpr bool is_lvalue_reference_v<_Tp &> = true;
  template <typename _Tp> inline constexpr bool is_rvalue_reference_v = false;
  template <typename _Tp>
  inline constexpr bool is_rvalue_reference_v<_Tp &&> = true;

  template <typename _Tp>
  inline constexpr bool is_member_object_pointer_v =
      __is_member_object_pointer(_Tp);

  template <typename _Tp>
  inline constexpr bool is_member_function_pointer_v =
      __is_member_function_pointer(_Tp);

  template <typename _Tp> inline constexpr bool is_enum_v = __is_enum(_Tp);
  template <typename _Tp> inline constexpr bool is_union_v = __is_union(_Tp);
  template <typename _Tp> inline constexpr bool is_class_v = __is_class(_Tp);

  template <typename _Tp>
  inline constexpr bool is_reference_v = __is_reference(_Tp);
  template <typename _Tp>
  inline constexpr bool is_arithmetic_v = is_arithmetic<_Tp>::value;
  template <typename _Tp>
  inline constexpr bool is_fundamental_v = is_fundamental<_Tp>::value;

  template <typename _Tp> inline constexpr bool is_object_v = __is_object(_Tp);

  template <typename _Tp>
  inline constexpr bool is_scalar_v = is_scalar<_Tp>::value;
  template <typename _Tp>
  inline constexpr bool is_compound_v = !is_fundamental_v<_Tp>;

  template <typename _Tp>
  inline constexpr bool is_member_pointer_v = __is_member_pointer(_Tp);

  template <typename _Tp> inline constexpr bool is_const_v = false;
  template <typename _Tp> inline constexpr bool is_const_v<const _Tp> = true;

  template <typename _Tp>
  inline constexpr bool is_function_v = __is_function(_Tp);
  template <typename _Tp> inline constexpr bool is_volatile_v = false;
  template <typename _Tp>
  inline constexpr bool is_volatile_v<volatile _Tp> = true;

  template <typename _Tp>
  inline constexpr bool is_trivial_v = __is_trivial(_Tp);
  template <typename _Tp>
  inline constexpr bool is_trivially_copyable_v = __is_trivially_copyable(_Tp);
  template <typename _Tp>
  inline constexpr bool is_standard_layout_v = __is_standard_layout(_Tp);
  template <typename _Tp>
  __attribute__((__deprecated__("use '"
                                "is_standard_layout_v && is_trivial_v"
                                "' instead"))) inline constexpr bool is_pod_v =
      __is_pod(_Tp);
  template <typename _Tp>
  [[__deprecated__]]
  inline constexpr bool is_literal_type_v = __is_literal_type(_Tp);
  template <typename _Tp> inline constexpr bool is_empty_v = __is_empty(_Tp);
  template <typename _Tp>
  inline constexpr bool is_polymorphic_v = __is_polymorphic(_Tp);
  template <typename _Tp>
  inline constexpr bool is_abstract_v = __is_abstract(_Tp);
  template <typename _Tp> inline constexpr bool is_final_v = __is_final(_Tp);

  template <typename _Tp>
  inline constexpr bool is_signed_v = is_signed<_Tp>::value;
  template <typename _Tp>
  inline constexpr bool is_unsigned_v = is_unsigned<_Tp>::value;

  template <typename _Tp, typename... _Args>
  inline constexpr bool is_constructible_v = __is_constructible(_Tp, _Args...);
  template <typename _Tp>
  inline constexpr bool is_default_constructible_v = __is_constructible(_Tp);
  template <typename _Tp>
  inline constexpr bool is_copy_constructible_v =
      __is_constructible(_Tp, __add_lval_ref_t<const _Tp>);
  template <typename _Tp>
  inline constexpr bool is_move_constructible_v =
      __is_constructible(_Tp, __add_rval_ref_t<_Tp>);

  template <typename _Tp, typename _Up>
  inline constexpr bool is_assignable_v = __is_assignable(_Tp, _Up);
  template <typename _Tp>
  inline constexpr bool is_copy_assignable_v =
      __is_assignable(__add_lval_ref_t<_Tp>, __add_lval_ref_t<const _Tp>);
  template <typename _Tp>
  inline constexpr bool is_move_assignable_v =
      __is_assignable(__add_lval_ref_t<_Tp>, __add_rval_ref_t<_Tp>);

  template <typename _Tp>
  inline constexpr bool is_destructible_v = is_destructible<_Tp>::value;

  template <typename _Tp, typename... _Args>
  inline constexpr bool is_trivially_constructible_v =
      __is_trivially_constructible(_Tp, _Args...);
  template <typename _Tp>
  inline constexpr bool is_trivially_default_constructible_v =
      __is_trivially_constructible(_Tp);
  template <typename _Tp>
  inline constexpr bool is_trivially_copy_constructible_v =
      __is_trivially_constructible(_Tp, __add_lval_ref_t<const _Tp>);
  template <typename _Tp>
  inline constexpr bool is_trivially_move_constructible_v =
      __is_trivially_constructible(_Tp, __add_rval_ref_t<_Tp>);

  template <typename _Tp, typename _Up>
  inline constexpr bool is_trivially_assignable_v =
      __is_trivially_assignable(_Tp, _Up);
  template <typename _Tp>
  inline constexpr bool is_trivially_copy_assignable_v =
      __is_trivially_assignable(__add_lval_ref_t<_Tp>,
                                __add_lval_ref_t<const _Tp>);
  template <typename _Tp>
  inline constexpr bool is_trivially_move_assignable_v =
      __is_trivially_assignable(__add_lval_ref_t<_Tp>, __add_rval_ref_t<_Tp>);

  template <typename _Tp>
  inline constexpr bool is_trivially_destructible_v = false;

  template <typename _Tp>
    requires(!is_reference_v<_Tp>) && requires(_Tp &__t) { __t.~_Tp(); }
  inline constexpr bool is_trivially_destructible_v<_Tp> =
      __has_trivial_destructor(_Tp);
  template <typename _Tp>
  inline constexpr bool is_trivially_destructible_v<_Tp &> = true;
  template <typename _Tp>
  inline constexpr bool is_trivially_destructible_v<_Tp &&> = true;
  template <typename _Tp, size_t _Nm>
  inline constexpr bool is_trivially_destructible_v<_Tp[_Nm]> =
      is_trivially_destructible_v<_Tp>;

  template <typename _Tp, typename... _Args>
  inline constexpr bool is_nothrow_constructible_v =
      __is_nothrow_constructible(_Tp, _Args...);
  template <typename _Tp>
  inline constexpr bool is_nothrow_default_constructible_v =
      __is_nothrow_constructible(_Tp);
  template <typename _Tp>
  inline constexpr bool is_nothrow_copy_constructible_v =
      __is_nothrow_constructible(_Tp, __add_lval_ref_t<const _Tp>);
  template <typename _Tp>
  inline constexpr bool is_nothrow_move_constructible_v =
      __is_nothrow_constructible(_Tp, __add_rval_ref_t<_Tp>);

  template <typename _Tp, typename _Up>
  inline constexpr bool is_nothrow_assignable_v =
      __is_nothrow_assignable(_Tp, _Up);
  template <typename _Tp>
  inline constexpr bool is_nothrow_copy_assignable_v = __is_nothrow_assignable(
      __add_lval_ref_t<_Tp>, __add_lval_ref_t<const _Tp>);
  template <typename _Tp>
  inline constexpr bool is_nothrow_move_assignable_v =
      __is_nothrow_assignable(__add_lval_ref_t<_Tp>, __add_rval_ref_t<_Tp>);

  template <typename _Tp>
  inline constexpr bool is_nothrow_destructible_v =
      is_nothrow_destructible<_Tp>::value;

  template <typename _Tp>
  inline constexpr bool has_virtual_destructor_v =
      __has_virtual_destructor(_Tp);

  template <typename _Tp>
  inline constexpr size_t alignment_of_v = alignment_of<_Tp>::value;

  template <typename _Tp> inline constexpr size_t rank_v = 0;
  template <typename _Tp, size_t _Size>
  inline constexpr size_t rank_v<_Tp[_Size]> = 1 + rank_v<_Tp>;
  template <typename _Tp>
  inline constexpr size_t rank_v<_Tp[]> = 1 + rank_v<_Tp>;

  template <typename _Tp, unsigned _Idx = 0>
  inline constexpr size_t extent_v = 0;
  template <typename _Tp, size_t _Size>
  inline constexpr size_t extent_v<_Tp[_Size], 0> = _Size;
  template <typename _Tp, unsigned _Idx, size_t _Size>
  inline constexpr size_t extent_v<_Tp[_Size], _Idx> = extent_v<_Tp, _Idx - 1>;
  template <typename _Tp> inline constexpr size_t extent_v<_Tp[], 0> = 0;
  template <typename _Tp, unsigned _Idx>
  inline constexpr size_t extent_v<_Tp[], _Idx> = extent_v<_Tp, _Idx - 1>;

  template <typename _Tp, typename _Up>
  inline constexpr bool is_same_v = __is_same(_Tp, _Up);

  template <typename _Base, typename _Derived>
  inline constexpr bool is_base_of_v = __is_base_of(_Base, _Derived);

  template <typename _From, typename _To>
  inline constexpr bool is_convertible_v = __is_convertible(_From, _To);

  template <typename _Fn, typename... _Args>
  inline constexpr bool is_invocable_v = is_invocable<_Fn, _Args...>::value;
  template <typename _Fn, typename... _Args>
  inline constexpr bool is_nothrow_invocable_v =
      is_nothrow_invocable<_Fn, _Args...>::value;
  template <typename _Ret, typename _Fn, typename... _Args>
  inline constexpr bool is_invocable_r_v =
      is_invocable_r<_Ret, _Fn, _Args...>::value;
  template <typename _Ret, typename _Fn, typename... _Args>
  inline constexpr bool is_nothrow_invocable_r_v =
      is_nothrow_invocable_r<_Ret, _Fn, _Args...>::value;

  template <typename _Tp>
  struct has_unique_object_representations
      : bool_constant<__has_unique_object_representations(
            remove_cv_t<remove_all_extents_t<_Tp>>)> {
    static_assert(
        std::__is_complete_or_unbounded(__type_identity<_Tp>{}),
        "template argument must be a complete class or an unbounded array");
  };

  template <typename _Tp>
  inline constexpr bool has_unique_object_representations_v =
      has_unique_object_representations<_Tp>::value;

  template <typename _Tp>
  struct is_aggregate : bool_constant<__is_aggregate(remove_cv_t<_Tp>)> {};

  template <typename _Tp>
  inline constexpr bool is_aggregate_v = __is_aggregate(remove_cv_t<_Tp>);
  template <typename _Tp> struct remove_cvref {
    using type = __remove_cvref(_Tp);
  };
  template <typename _Tp>
  using remove_cvref_t = typename remove_cvref<_Tp>::type;
  template <typename _Tp> struct type_identity {
    using type = _Tp;
  };

  template <typename _Tp>
  using type_identity_t = typename type_identity<_Tp>::type;
  template <typename _Tp> struct unwrap_reference {
    using type = _Tp;
  };

  template <typename _Tp> struct unwrap_reference<reference_wrapper<_Tp>> {
    using type = _Tp &;
  };

  template <typename _Tp>
  using unwrap_reference_t = typename unwrap_reference<_Tp>::type;

  template <typename _Tp> struct unwrap_ref_decay {
    using type = unwrap_reference_t<decay_t<_Tp>>;
  };

  template <typename _Tp>
  using unwrap_ref_decay_t = typename unwrap_ref_decay<_Tp>::type;
  template <typename _Tp>
  inline constexpr bool is_bounded_array_v = __is_bounded_array(_Tp);
  template <typename _Tp> inline constexpr bool is_unbounded_array_v = false;

  template <typename _Tp>
  inline constexpr bool is_unbounded_array_v<_Tp[]> = true;

  template <typename _Tp>
  struct is_bounded_array : public bool_constant<is_bounded_array_v<_Tp>> {};

  template <typename _Tp>
  struct is_unbounded_array : public bool_constant<is_unbounded_array_v<_Tp>> {
  };

  template <typename _Tp, typename _Up>
  struct is_layout_compatible
      : bool_constant<__is_layout_compatible(_Tp, _Up)> {};

  template <typename _Tp, typename _Up>
  constexpr bool is_layout_compatible_v = __is_layout_compatible(_Tp, _Up);

  template <typename _S1, typename _S2, typename _M1, typename _M2>
  constexpr bool is_corresponding_member(_M1 _S1::*__m1,
                                         _M2 _S2::*__m2) noexcept {
    return __builtin_is_corresponding_member(__m1, __m2);
  }

  template <typename _Base, typename _Derived>
  struct is_pointer_interconvertible_base_of
      : bool_constant<__is_pointer_interconvertible_base_of(_Base, _Derived)> {
  };

  template <typename _Base, typename _Derived>
  constexpr bool is_pointer_interconvertible_base_of_v =
      __is_pointer_interconvertible_base_of(_Base, _Derived);
  template <typename _Tp, typename _Mem>
  constexpr bool is_pointer_interconvertible_with_class(
      _Mem _Tp::*__mp) noexcept {
    return __builtin_is_pointer_interconvertible_with_class(__mp);
  }
  constexpr inline bool is_constant_evaluated() noexcept {

    return __builtin_is_constant_evaluated();
  }

  template <typename _From, typename _To>
  using __copy_cv = typename __match_cv_qualifiers<_From, _To>::__type;

  template <typename _Xp, typename _Yp>
  using __cond_res =
      decltype(false ? declval<_Xp (&)()>()() : declval<_Yp (&)()>()());

  template <typename _Ap, typename _Bp, typename = void>
  struct __common_ref_impl {};

  template <typename _Ap, typename _Bp>
  using __common_ref = typename __common_ref_impl<_Ap, _Bp>::type;

  template <typename _Xp, typename _Yp>
  using __condres_cvref =
      __cond_res<__copy_cv<_Xp, _Yp> &, __copy_cv<_Yp, _Xp> &>;

  template <typename _Xp, typename _Yp>
  struct __common_ref_impl<_Xp &, _Yp &, __void_t<__condres_cvref<_Xp, _Yp>>>
      : enable_if<is_reference_v<__condres_cvref<_Xp, _Yp>>,
                  __condres_cvref<_Xp, _Yp>> {};

  template <typename _Xp, typename _Yp>
  using __common_ref_C = remove_reference_t<__common_ref<_Xp &, _Yp &>> &&;

  template <typename _Xp, typename _Yp>
  struct __common_ref_impl<
      _Xp &&, _Yp &&,
      _Require<is_convertible<_Xp &&, __common_ref_C<_Xp, _Yp>>,
               is_convertible<_Yp &&, __common_ref_C<_Xp, _Yp>>>> {
    using type = __common_ref_C<_Xp, _Yp>;
  };

  template <typename _Xp, typename _Yp>
  using __common_ref_D = __common_ref<const _Xp &, _Yp &>;

  template <typename _Xp, typename _Yp>
  struct __common_ref_impl<
      _Xp &&, _Yp &,
      _Require<is_convertible<_Xp &&, __common_ref_D<_Xp, _Yp>>>> {
    using type = __common_ref_D<_Xp, _Yp>;
  };

  template <typename _Xp, typename _Yp>
  struct __common_ref_impl<_Xp &, _Yp &&> : __common_ref_impl<_Yp &&, _Xp &> {};

  template <typename _Tp, typename _Up, template <typename> class _TQual,
            template <typename> class _UQual>
  struct basic_common_reference {};

  template <typename _Tp> struct __xref {
    template <typename _Up> using __type = __copy_cv<_Tp, _Up>;
  };

  template <typename _Tp> struct __xref<_Tp &> {
    template <typename _Up> using __type = __copy_cv<_Tp, _Up> &;
  };

  template <typename _Tp> struct __xref<_Tp &&> {
    template <typename _Up> using __type = __copy_cv<_Tp, _Up> &&;
  };

  template <typename _Tp1, typename _Tp2>
  using __basic_common_ref = typename basic_common_reference<
      remove_cvref_t<_Tp1>, remove_cvref_t<_Tp2>, __xref<_Tp1>::template __type,
      __xref<_Tp2>::template __type>::type;

  template <typename... _Tp> struct common_reference;

  template <typename... _Tp>
  using common_reference_t = typename common_reference<_Tp...>::type;

  template <> struct common_reference<> {};

  template <typename _Tp0> struct common_reference<_Tp0> {
    using type = _Tp0;
  };

  template <typename _Tp1, typename _Tp2, int _Bullet = 1, typename = void>
  struct __common_reference_impl
      : __common_reference_impl<_Tp1, _Tp2, _Bullet + 1> {};

  template <typename _Tp1, typename _Tp2>
  struct common_reference<_Tp1, _Tp2> : __common_reference_impl<_Tp1, _Tp2> {};

  template <typename _Tp1, typename _Tp2>
  struct __common_reference_impl<_Tp1 &, _Tp2 &, 1,
                                 void_t<__common_ref<_Tp1 &, _Tp2 &>>> {
    using type = __common_ref<_Tp1 &, _Tp2 &>;
  };

  template <typename _Tp1, typename _Tp2>
  struct __common_reference_impl<_Tp1 &&, _Tp2 &&, 1,
                                 void_t<__common_ref<_Tp1 &&, _Tp2 &&>>> {
    using type = __common_ref<_Tp1 &&, _Tp2 &&>;
  };

  template <typename _Tp1, typename _Tp2>
  struct __common_reference_impl<_Tp1 &, _Tp2 &&, 1,
                                 void_t<__common_ref<_Tp1 &, _Tp2 &&>>> {
    using type = __common_ref<_Tp1 &, _Tp2 &&>;
  };

  template <typename _Tp1, typename _Tp2>
  struct __common_reference_impl<_Tp1 &&, _Tp2 &, 1,
                                 void_t<__common_ref<_Tp1 &&, _Tp2 &>>> {
    using type = __common_ref<_Tp1 &&, _Tp2 &>;
  };

  template <typename _Tp1, typename _Tp2>
  struct __common_reference_impl<_Tp1, _Tp2, 2,
                                 void_t<__basic_common_ref<_Tp1, _Tp2>>> {
    using type = __basic_common_ref<_Tp1, _Tp2>;
  };

  template <typename _Tp1, typename _Tp2>
  struct __common_reference_impl<_Tp1, _Tp2, 3,
                                 void_t<__cond_res<_Tp1, _Tp2>>> {
    using type = __cond_res<_Tp1, _Tp2>;
  };

  template <typename _Tp1, typename _Tp2>
  struct __common_reference_impl<_Tp1, _Tp2, 4,
                                 void_t<common_type_t<_Tp1, _Tp2>>> {
    using type = common_type_t<_Tp1, _Tp2>;
  };

  template <typename _Tp1, typename _Tp2>
  struct __common_reference_impl<_Tp1, _Tp2, 5, void> {};

  template <typename _Tp1, typename _Tp2, typename... _Rest>
  struct common_reference<_Tp1, _Tp2, _Rest...>
      : __common_type_fold<common_reference<_Tp1, _Tp2>,
                           __common_type_pack<_Rest...>> {};

  template <typename _Tp1, typename _Tp2, typename... _Rest>
  struct __common_type_fold<common_reference<_Tp1, _Tp2>,
                            __common_type_pack<_Rest...>,
                            void_t<common_reference_t<_Tp1, _Tp2>>>
      : public common_reference<common_reference_t<_Tp1, _Tp2>, _Rest...> {};

} // namespace std
namespace std __attribute__((__visibility__("default"))) {

  template <typename _Tp>
  inline constexpr _Tp *__addressof(_Tp & __r) noexcept {
    return __builtin_addressof(__r);
  }
  template <typename _Tp>
  [[__nodiscard__]]
  constexpr _Tp &&forward(typename std::remove_reference<_Tp>::type &
                          __t) noexcept {
    return static_cast<_Tp &&>(__t);
  }

  template <typename _Tp>
  [[__nodiscard__]]
  constexpr _Tp &&forward(typename std::remove_reference<_Tp>::type &&
                          __t) noexcept {
    static_assert(
        !std::is_lvalue_reference<_Tp>::value,
        "std::forward must not be used to convert an rvalue to an lvalue");
    return static_cast<_Tp &&>(__t);
  }
  template <typename _Tp>
  [[__nodiscard__]]
  constexpr
      typename std::remove_reference<_Tp>::type &&move(_Tp && __t) noexcept {
    return static_cast<typename std::remove_reference<_Tp>::type &&>(__t);
  }

  template <typename _Tp>
  struct __move_if_noexcept_cond
      : public __and_<__not_<is_nothrow_move_constructible<_Tp>>,
                      is_copy_constructible<_Tp>>::type {};
  template <typename _Tp>
  [[__nodiscard__]]
  constexpr __conditional_t<__move_if_noexcept_cond<_Tp>::value, const _Tp &,
                            _Tp &&> move_if_noexcept(_Tp & __x) noexcept {
    return std::move(__x);
  }
  template <typename _Tp>
  [[__nodiscard__]]
  inline constexpr _Tp *addressof(_Tp & __r) noexcept {
    return std::__addressof(__r);
  }

  template <typename _Tp> const _Tp *addressof(const _Tp &&) = delete;

  template <typename _Tp, typename _Up = _Tp>
  constexpr inline _Tp __exchange(_Tp & __obj, _Up && __new_val) {
    _Tp __old_val = std::move(__obj);
    __obj = std::forward<_Up>(__new_val);
    return __old_val;
  }
  template <typename _Tp>
  constexpr inline

      typename enable_if<
          __and_<__not_<__is_tuple_like<_Tp>>, is_move_constructible<_Tp>,
                 is_move_assignable<_Tp>>::value>::type

      swap(_Tp & __a,
           _Tp & __b) noexcept(__and_<is_nothrow_move_constructible<_Tp>,
                                      is_nothrow_move_assignable<_Tp>>::value)

  {

    _Tp __tmp = std::move(__a);
    __a = std::move(__b);
    __b = std::move(__tmp);
  }

  template <typename _Tp, size_t _Nm>
  constexpr inline

      typename enable_if<__is_swappable<_Tp>::value>::type

      swap(_Tp(&__a)[_Nm],
           _Tp(&__b)[_Nm]) noexcept(__is_nothrow_swappable<_Tp>::value) {
    for (size_t __n = 0; __n < _Nm; ++__n)
      swap(__a[__n], __b[__n]);
  }

} // namespace std

namespace std __attribute__((__visibility__("default"))) {

  template <typename _Tp> struct tuple_size;

  template <typename _Tp, typename _Up = typename remove_cv<_Tp>::type,
            typename = typename enable_if<is_same<_Tp, _Up>::value>::type,
            size_t = tuple_size<_Tp>::value>
  using __enable_if_has_tuple_size = _Tp;

  template <typename _Tp>
  struct tuple_size<const __enable_if_has_tuple_size<_Tp>>
      : public tuple_size<_Tp> {};

  template <typename _Tp>
  struct tuple_size<volatile __enable_if_has_tuple_size<_Tp>>
      : public tuple_size<_Tp> {};

  template <typename _Tp>
  struct tuple_size<const volatile __enable_if_has_tuple_size<_Tp>>
      : public tuple_size<_Tp> {};

  template <typename _Tp>
  inline constexpr size_t tuple_size_v = tuple_size<_Tp>::value;

  template <size_t __i, typename _Tp> struct tuple_element;

  template <size_t __i, typename _Tp>
  using __tuple_element_t = typename tuple_element<__i, _Tp>::type;

  template <size_t __i, typename _Tp> struct tuple_element<__i, const _Tp> {
    using type = const __tuple_element_t<__i, _Tp>;
  };

  template <size_t __i, typename _Tp> struct tuple_element<__i, volatile _Tp> {
    using type = volatile __tuple_element_t<__i, _Tp>;
  };

  template <size_t __i, typename _Tp>
  struct tuple_element<__i, const volatile _Tp> {
    using type = const volatile __tuple_element_t<__i, _Tp>;
  };

  template <typename _Tp, typename... _Types>
  constexpr size_t __find_uniq_type_in_pack() {
    constexpr size_t __sz = sizeof...(_Types);
    constexpr bool __found[__sz] = {__is_same(_Tp, _Types)...};
    size_t __n = __sz;
    for (size_t __i = 0; __i < __sz; ++__i) {
      if (__found[__i]) {
        if (__n < __sz)
          return __sz;
        __n = __i;
      }
    }
    return __n;
  }
  template <size_t __i, typename _Tp>
  using tuple_element_t = typename tuple_element<__i, _Tp>::type;

  template <size_t... _Indexes> struct _Index_tuple {};

  template <size_t _Num> struct _Build_index_tuple {
    using __type = _Index_tuple<__integer_pack(_Num)...>;
  };

  template <typename _Tp, _Tp... _Idx> struct integer_sequence {

    static_assert(is_integral_v<_Tp>);

    typedef _Tp value_type;
    static constexpr size_t size() noexcept { return sizeof...(_Idx); }
  };

  template <typename _Tp, _Tp _Num>
  using make_integer_sequence

      = integer_sequence<_Tp, __integer_pack(_Num)...>;

  template <size_t... _Idx>
  using index_sequence = integer_sequence<size_t, _Idx...>;

  template <size_t _Num>
  using make_index_sequence = make_integer_sequence<size_t, _Num>;

  template <typename... _Types>
  using index_sequence_for = make_index_sequence<sizeof...(_Types)>;

  struct in_place_t {
    explicit in_place_t() = default;
  };

  inline constexpr in_place_t in_place{};

  template <typename _Tp> struct in_place_type_t {
    explicit in_place_type_t() = default;
  };

  template <typename _Tp> inline constexpr in_place_type_t<_Tp> in_place_type{};

  template <size_t _Idx> struct in_place_index_t {
    explicit in_place_index_t() = default;
  };

  template <size_t _Idx>
  inline constexpr in_place_index_t<_Idx> in_place_index{};

  template <typename> inline constexpr bool __is_in_place_type_v = false;

  template <typename _Tp>
  inline constexpr bool __is_in_place_type_v<in_place_type_t<_Tp>> = true;

  template <typename _Tp>
  using __is_in_place_type = bool_constant<__is_in_place_type_v<_Tp>>;

  template <typename> inline constexpr bool __is_in_place_index_v = false;

  template <size_t _Nm>
  inline constexpr bool __is_in_place_index_v<in_place_index_t<_Nm>> = true;

  template <size_t _Np, typename... _Types> struct _Nth_type {
    using type = __type_pack_element<_Np, _Types...>;
  };
  namespace ranges::__detail {
  template <typename _Range> inline constexpr bool __is_subrange = false;
  }

} // namespace std

namespace std __attribute__((__visibility__("default"))) {

  namespace __detail {
  template <typename _Tp, typename _Up>
  concept __same_as = std::is_same_v<_Tp, _Up>;
  }

  template <typename _Tp, typename _Up>
  concept same_as =
      __detail::__same_as<_Tp, _Up> && __detail::__same_as<_Up, _Tp>;

  namespace __detail {
  template <typename _Tp, typename _Up>
  concept __different_from = !same_as<remove_cvref_t<_Tp>, remove_cvref_t<_Up>>;
  }

  template <typename _Derived, typename _Base>
  concept derived_from =
      __is_base_of(_Base, _Derived) &&
      is_convertible_v<const volatile _Derived *, const volatile _Base *>;

  template <typename _From, typename _To>
  concept convertible_to = is_convertible_v<_From, _To> && requires {
    static_cast<_To>(std::declval<_From>());
  };

  template <typename _Tp, typename _Up>
  concept common_reference_with =
      same_as<common_reference_t<_Tp, _Up>, common_reference_t<_Up, _Tp>> &&
      convertible_to<_Tp, common_reference_t<_Tp, _Up>> &&
      convertible_to<_Up, common_reference_t<_Tp, _Up>>;

  template <typename _Tp, typename _Up>
  concept common_with =
      same_as<common_type_t<_Tp, _Up>, common_type_t<_Up, _Tp>> &&
      requires {
        static_cast<common_type_t<_Tp, _Up>>(std::declval<_Tp>());
        static_cast<common_type_t<_Tp, _Up>>(std::declval<_Up>());
      } &&
      common_reference_with<add_lvalue_reference_t<const _Tp>,
                            add_lvalue_reference_t<const _Up>> &&
      common_reference_with<
          add_lvalue_reference_t<common_type_t<_Tp, _Up>>,
          common_reference_t<add_lvalue_reference_t<const _Tp>,
                             add_lvalue_reference_t<const _Up>>>;

  template <typename _Tp>
  concept integral = is_integral_v<_Tp>;

  template <typename _Tp>
  concept signed_integral = integral<_Tp> && is_signed_v<_Tp>;

  template <typename _Tp>
  concept unsigned_integral = integral<_Tp> && !signed_integral<_Tp>;

  template <typename _Tp>
  concept floating_point = is_floating_point_v<_Tp>;

  namespace __detail {
  template <typename _Tp> using __cref = const remove_reference_t<_Tp> &;

  template <typename _Tp>
  concept __class_or_enum =
      is_class_v<_Tp> || is_union_v<_Tp> || is_enum_v<_Tp>;

  template <typename _Tp> constexpr bool __destructible_impl = false;
  template <typename _Tp>
    requires requires(_Tp &__t) {
      { __t.~_Tp() } noexcept;
    }
  constexpr bool __destructible_impl<_Tp> = true;

  template <typename _Tp>
  constexpr bool __destructible = __destructible_impl<_Tp>;
  template <typename _Tp> constexpr bool __destructible<_Tp &> = true;
  template <typename _Tp> constexpr bool __destructible<_Tp &&> = true;
  template <typename _Tp, size_t _Nm>
  constexpr bool __destructible<_Tp[_Nm]> = __destructible<_Tp>;

  } // namespace __detail

  template <typename _Lhs, typename _Rhs>
  concept assignable_from =
      is_lvalue_reference_v<_Lhs> &&
      common_reference_with<__detail::__cref<_Lhs>, __detail::__cref<_Rhs>> &&
      requires(_Lhs __lhs, _Rhs &&__rhs) {
        { __lhs = static_cast<_Rhs &&>(__rhs) } -> same_as<_Lhs>;
      };

  template <typename _Tp>
  concept destructible = __detail::__destructible<_Tp>;

  template <typename _Tp, typename... _Args>
  concept constructible_from =
      destructible<_Tp> && is_constructible_v<_Tp, _Args...>;

  template <typename _Tp>
  concept default_initializable = constructible_from<_Tp> && requires {
    _Tp{};
    (void)::new _Tp;
  };

  template <typename _Tp>
  concept move_constructible =
      constructible_from<_Tp, _Tp> && convertible_to<_Tp, _Tp>;

  template <typename _Tp>
  concept copy_constructible =
      move_constructible<_Tp> && constructible_from<_Tp, _Tp &> &&
      convertible_to<_Tp &, _Tp> && constructible_from<_Tp, const _Tp &> &&
      convertible_to<const _Tp &, _Tp> && constructible_from<_Tp, const _Tp> &&
      convertible_to<const _Tp, _Tp>;

  namespace ranges {

  namespace __swap {
  template <typename _Tp> void swap(_Tp &, _Tp &) = delete;

  template <typename _Tp, typename _Up>
  concept __adl_swap =
      (std::__detail::__class_or_enum<remove_reference_t<_Tp>> ||
       std::__detail::__class_or_enum<remove_reference_t<_Up>>) &&
      requires(_Tp &&__t, _Up &&__u) {
        swap(static_cast<_Tp &&>(__t), static_cast<_Up &&>(__u));
      };

  struct _Swap {
  private:
    template <typename _Tp, typename _Up> static constexpr bool _S_noexcept() {
      if constexpr (__adl_swap<_Tp, _Up>)
        return noexcept(swap(std::declval<_Tp>(), std::declval<_Up>()));
      else
        return is_nothrow_move_constructible_v<remove_reference_t<_Tp>> &&
               is_nothrow_move_assignable_v<remove_reference_t<_Tp>>;
    }

  public:
    template <typename _Tp, typename _Up>
      requires __adl_swap<_Tp, _Up> ||
               (same_as<_Tp, _Up> && is_lvalue_reference_v<_Tp> &&
                move_constructible<remove_reference_t<_Tp>> &&
                assignable_from<_Tp, remove_reference_t<_Tp>>)
    constexpr void operator()(_Tp &&__t, _Up &&__u) const
        noexcept(_S_noexcept<_Tp, _Up>()) {
      if constexpr (__adl_swap<_Tp, _Up>)
        swap(static_cast<_Tp &&>(__t), static_cast<_Up &&>(__u));
      else {
        auto __tmp = static_cast<remove_reference_t<_Tp> &&>(__t);
        __t = static_cast<remove_reference_t<_Tp> &&>(__u);
        __u = static_cast<remove_reference_t<_Tp> &&>(__tmp);
      }
    }

    template <typename _Tp, typename _Up, size_t _Num>
      requires requires(const _Swap &__swap, _Tp &__e1, _Up &__e2) {
        __swap(__e1, __e2);
      }
    constexpr void operator()(_Tp (&__e1)[_Num], _Up (&__e2)[_Num]) const
        noexcept(noexcept(std::declval<const _Swap &>()(*__e1, *__e2))) {
      for (size_t __n = 0; __n < _Num; ++__n)
        (*this)(__e1[__n], __e2[__n]);
    }
  };
  } // namespace __swap

  inline namespace _Cpo {
  inline constexpr __swap::_Swap swap{};
  }
  } // namespace ranges

  template <typename _Tp>
  concept swappable = requires(_Tp &__a, _Tp &__b) { ranges::swap(__a, __b); };

  template <typename _Tp, typename _Up>
  concept swappable_with =
      common_reference_with<_Tp, _Up> && requires(_Tp &&__t, _Up &&__u) {
        ranges::swap(static_cast<_Tp &&>(__t), static_cast<_Tp &&>(__t));
        ranges::swap(static_cast<_Up &&>(__u), static_cast<_Up &&>(__u));
        ranges::swap(static_cast<_Tp &&>(__t), static_cast<_Up &&>(__u));
        ranges::swap(static_cast<_Up &&>(__u), static_cast<_Tp &&>(__t));
      };

  template <typename _Tp>
  concept movable = is_object_v<_Tp> && move_constructible<_Tp> &&
                    assignable_from<_Tp &, _Tp> && swappable<_Tp>;

  template <typename _Tp>
  concept copyable =
      copy_constructible<_Tp> && movable<_Tp> &&
      assignable_from<_Tp &, _Tp &> && assignable_from<_Tp &, const _Tp &> &&
      assignable_from<_Tp &, const _Tp>;

  template <typename _Tp>
  concept semiregular = copyable<_Tp> && default_initializable<_Tp>;

  namespace __detail {
  template <typename _Tp>
  concept __boolean_testable_impl = convertible_to<_Tp, bool>;

  template <typename _Tp>
  concept __boolean_testable =
      __boolean_testable_impl<_Tp> && requires(_Tp &&__t) {
        { !static_cast<_Tp &&>(__t) } -> __boolean_testable_impl;
      };
  } // namespace __detail

  namespace __detail {
  template <typename _Tp, typename _Up>
  concept __weakly_eq_cmp_with =
      requires(__detail::__cref<_Tp> __t, __detail::__cref<_Up> __u) {
        { __t == __u } -> __boolean_testable;
        { __t != __u } -> __boolean_testable;
        { __u == __t } -> __boolean_testable;
        { __u != __t } -> __boolean_testable;
      };
  } // namespace __detail

  template <typename _Tp>
  concept equality_comparable = __detail::__weakly_eq_cmp_with<_Tp, _Tp>;

  template <typename _Tp, typename _Up>
  concept equality_comparable_with =
      equality_comparable<_Tp> && equality_comparable<_Up> &&
      common_reference_with<__detail::__cref<_Tp>, __detail::__cref<_Up>> &&
      equality_comparable<
          common_reference_t<__detail::__cref<_Tp>, __detail::__cref<_Up>>> &&
      __detail::__weakly_eq_cmp_with<_Tp, _Up>;

  namespace __detail {
  template <typename _Tp, typename _Up>
  concept __partially_ordered_with = requires(
      const remove_reference_t<_Tp> &__t, const remove_reference_t<_Up> &__u) {
    { __t < __u } -> __boolean_testable;
    { __t > __u } -> __boolean_testable;
    { __t <= __u } -> __boolean_testable;
    { __t >= __u } -> __boolean_testable;
    { __u < __t } -> __boolean_testable;
    { __u > __t } -> __boolean_testable;
    { __u <= __t } -> __boolean_testable;
    { __u >= __t } -> __boolean_testable;
  };
  } // namespace __detail

  template <typename _Tp>
  concept totally_ordered =
      equality_comparable<_Tp> && __detail::__partially_ordered_with<_Tp, _Tp>;

  template <typename _Tp, typename _Up>
  concept totally_ordered_with =
      totally_ordered<_Tp> && totally_ordered<_Up> &&
      equality_comparable_with<_Tp, _Up> &&
      totally_ordered<
          common_reference_t<__detail::__cref<_Tp>, __detail::__cref<_Up>>> &&
      __detail::__partially_ordered_with<_Tp, _Up>;

  template <typename _Tp>
  concept regular = semiregular<_Tp> && equality_comparable<_Tp>;

  template <typename _Fn, typename... _Args>
  concept invocable = is_invocable_v<_Fn, _Args...>;

  template <typename _Fn, typename... _Args>
  concept regular_invocable = invocable<_Fn, _Args...>;

  template <typename _Fn, typename... _Args>
  concept predicate =
      regular_invocable<_Fn, _Args...> &&
      __detail::__boolean_testable<invoke_result_t<_Fn, _Args...>>;

  template <typename _Rel, typename _Tp, typename _Up>
  concept relation = predicate<_Rel, _Tp, _Tp> && predicate<_Rel, _Up, _Up> &&
                     predicate<_Rel, _Tp, _Up> && predicate<_Rel, _Up, _Tp>;

  template <typename _Rel, typename _Tp, typename _Up>
  concept equivalence_relation = relation<_Rel, _Tp, _Up>;

  template <typename _Rel, typename _Tp, typename _Up>
  concept strict_weak_order = relation<_Rel, _Tp, _Up>;

} // namespace std

namespace std __attribute__((__visibility__("default"))) {

  namespace __cmp_cat {
  using type = signed char;

  enum class _Ord : type { equivalent = 0, less = -1, greater = 1 };

  enum class _Ncmp : type { _Unordered = 2 };

  struct __unspec {
    consteval __unspec(__unspec *) noexcept {}
  };
  } // namespace __cmp_cat

  class partial_ordering {

    __cmp_cat::type _M_value;

    constexpr explicit partial_ordering(__cmp_cat::_Ord __v) noexcept
        : _M_value(__cmp_cat::type(__v)) {}

    constexpr explicit partial_ordering(__cmp_cat::_Ncmp __v) noexcept
        : _M_value(__cmp_cat::type(__v)) {}

    friend class weak_ordering;
    friend class strong_ordering;

  public:
    static const partial_ordering less;
    static const partial_ordering equivalent;
    static const partial_ordering greater;
    static const partial_ordering unordered;

    [[nodiscard]]
    friend constexpr bool operator==(partial_ordering __v,
                                     __cmp_cat::__unspec) noexcept {
      return __v._M_value == 0;
    }

    [[nodiscard]]
    friend constexpr bool operator==(partial_ordering,
                                     partial_ordering) noexcept = default;

    [[nodiscard]]
    friend constexpr bool operator<(partial_ordering __v,
                                    __cmp_cat::__unspec) noexcept {
      return __v._M_value == -1;
    }

    [[nodiscard]]
    friend constexpr bool operator>(partial_ordering __v,
                                    __cmp_cat::__unspec) noexcept {
      return __v._M_value == 1;
    }

    [[nodiscard]]
    friend constexpr bool operator<=(partial_ordering __v,
                                     __cmp_cat::__unspec) noexcept {
      return __v._M_value <= 0;
    }

    [[nodiscard]]
    friend constexpr bool operator>=(partial_ordering __v,
                                     __cmp_cat::__unspec) noexcept {
      return __cmp_cat::type(__v._M_value & 1) == __v._M_value;
    }

    [[nodiscard]]
    friend constexpr bool operator<(__cmp_cat::__unspec,
                                    partial_ordering __v) noexcept {
      return __v._M_value == 1;
    }

    [[nodiscard]]
    friend constexpr bool operator>(__cmp_cat::__unspec,
                                    partial_ordering __v) noexcept {
      return __v._M_value == -1;
    }

    [[nodiscard]]
    friend constexpr bool operator<=(__cmp_cat::__unspec,
                                     partial_ordering __v) noexcept {
      return __cmp_cat::type(__v._M_value & 1) == __v._M_value;
    }

    [[nodiscard]]
    friend constexpr bool operator>=(__cmp_cat::__unspec,
                                     partial_ordering __v) noexcept {
      return 0 >= __v._M_value;
    }

    [[nodiscard]]
    friend constexpr partial_ordering
    operator<=>(partial_ordering __v, __cmp_cat::__unspec) noexcept {
      return __v;
    }

    [[nodiscard]]
    friend constexpr partial_ordering
    operator<=>(__cmp_cat::__unspec, partial_ordering __v) noexcept {
      if (__v._M_value & 1)
        return partial_ordering(__cmp_cat::_Ord(-__v._M_value));
      else
        return __v;
    }
  };

  inline constexpr partial_ordering partial_ordering::less(
      __cmp_cat::_Ord::less);

  inline constexpr partial_ordering partial_ordering::equivalent(
      __cmp_cat::_Ord::equivalent);

  inline constexpr partial_ordering partial_ordering::greater(
      __cmp_cat::_Ord::greater);

  inline constexpr partial_ordering partial_ordering::unordered(
      __cmp_cat::_Ncmp::_Unordered);

  class weak_ordering {
    __cmp_cat::type _M_value;

    constexpr explicit weak_ordering(__cmp_cat::_Ord __v) noexcept
        : _M_value(__cmp_cat::type(__v)) {}

    friend class strong_ordering;

  public:
    static const weak_ordering less;
    static const weak_ordering equivalent;
    static const weak_ordering greater;

    [[nodiscard]]
    constexpr operator partial_ordering() const noexcept {
      return partial_ordering(__cmp_cat::_Ord(_M_value));
    }

    [[nodiscard]]
    friend constexpr bool operator==(weak_ordering __v,
                                     __cmp_cat::__unspec) noexcept {
      return __v._M_value == 0;
    }

    [[nodiscard]]
    friend constexpr bool operator==(weak_ordering,
                                     weak_ordering) noexcept = default;

    [[nodiscard]]
    friend constexpr bool operator<(weak_ordering __v,
                                    __cmp_cat::__unspec) noexcept {
      return __v._M_value < 0;
    }

    [[nodiscard]]
    friend constexpr bool operator>(weak_ordering __v,
                                    __cmp_cat::__unspec) noexcept {
      return __v._M_value > 0;
    }

    [[nodiscard]]
    friend constexpr bool operator<=(weak_ordering __v,
                                     __cmp_cat::__unspec) noexcept {
      return __v._M_value <= 0;
    }

    [[nodiscard]]
    friend constexpr bool operator>=(weak_ordering __v,
                                     __cmp_cat::__unspec) noexcept {
      return __v._M_value >= 0;
    }

    [[nodiscard]]
    friend constexpr bool operator<(__cmp_cat::__unspec,
                                    weak_ordering __v) noexcept {
      return 0 < __v._M_value;
    }

    [[nodiscard]]
    friend constexpr bool operator>(__cmp_cat::__unspec,
                                    weak_ordering __v) noexcept {
      return 0 > __v._M_value;
    }

    [[nodiscard]]
    friend constexpr bool operator<=(__cmp_cat::__unspec,
                                     weak_ordering __v) noexcept {
      return 0 <= __v._M_value;
    }

    [[nodiscard]]
    friend constexpr bool operator>=(__cmp_cat::__unspec,
                                     weak_ordering __v) noexcept {
      return 0 >= __v._M_value;
    }

    [[nodiscard]]
    friend constexpr weak_ordering operator<=>(weak_ordering __v,
                                               __cmp_cat::__unspec) noexcept {
      return __v;
    }

    [[nodiscard]]
    friend constexpr weak_ordering operator<=>(__cmp_cat::__unspec,
                                               weak_ordering __v) noexcept {
      return weak_ordering(__cmp_cat::_Ord(-__v._M_value));
    }
  };

  inline constexpr weak_ordering weak_ordering::less(__cmp_cat::_Ord::less);

  inline constexpr weak_ordering weak_ordering::equivalent(
      __cmp_cat::_Ord::equivalent);

  inline constexpr weak_ordering weak_ordering::greater(
      __cmp_cat::_Ord::greater);

  class strong_ordering {
    __cmp_cat::type _M_value;

    constexpr explicit strong_ordering(__cmp_cat::_Ord __v) noexcept
        : _M_value(__cmp_cat::type(__v)) {}

  public:
    static const strong_ordering less;
    static const strong_ordering equal;
    static const strong_ordering equivalent;
    static const strong_ordering greater;

    [[nodiscard]]
    constexpr operator partial_ordering() const noexcept {
      return partial_ordering(__cmp_cat::_Ord(_M_value));
    }

    [[nodiscard]]
    constexpr operator weak_ordering() const noexcept {
      return weak_ordering(__cmp_cat::_Ord(_M_value));
    }

    [[nodiscard]]
    friend constexpr bool operator==(strong_ordering __v,
                                     __cmp_cat::__unspec) noexcept {
      return __v._M_value == 0;
    }

    [[nodiscard]]
    friend constexpr bool operator==(strong_ordering,
                                     strong_ordering) noexcept = default;

    [[nodiscard]]
    friend constexpr bool operator<(strong_ordering __v,
                                    __cmp_cat::__unspec) noexcept {
      return __v._M_value < 0;
    }

    [[nodiscard]]
    friend constexpr bool operator>(strong_ordering __v,
                                    __cmp_cat::__unspec) noexcept {
      return __v._M_value > 0;
    }

    [[nodiscard]]
    friend constexpr bool operator<=(strong_ordering __v,
                                     __cmp_cat::__unspec) noexcept {
      return __v._M_value <= 0;
    }

    [[nodiscard]]
    friend constexpr bool operator>=(strong_ordering __v,
                                     __cmp_cat::__unspec) noexcept {
      return __v._M_value >= 0;
    }

    [[nodiscard]]
    friend constexpr bool operator<(__cmp_cat::__unspec,
                                    strong_ordering __v) noexcept {
      return 0 < __v._M_value;
    }

    [[nodiscard]]
    friend constexpr bool operator>(__cmp_cat::__unspec,
                                    strong_ordering __v) noexcept {
      return 0 > __v._M_value;
    }

    [[nodiscard]]
    friend constexpr bool operator<=(__cmp_cat::__unspec,
                                     strong_ordering __v) noexcept {
      return 0 <= __v._M_value;
    }

    [[nodiscard]]
    friend constexpr bool operator>=(__cmp_cat::__unspec,
                                     strong_ordering __v) noexcept {
      return 0 >= __v._M_value;
    }

    [[nodiscard]]
    friend constexpr strong_ordering operator<=>(strong_ordering __v,
                                                 __cmp_cat::__unspec) noexcept {
      return __v;
    }

    [[nodiscard]]
    friend constexpr strong_ordering operator<=>(__cmp_cat::__unspec,
                                                 strong_ordering __v) noexcept {
      return strong_ordering(__cmp_cat::_Ord(-__v._M_value));
    }
  };

  inline constexpr strong_ordering strong_ordering::less(__cmp_cat::_Ord::less);

  inline constexpr strong_ordering strong_ordering::equal(
      __cmp_cat::_Ord::equivalent);

  inline constexpr strong_ordering strong_ordering::equivalent(
      __cmp_cat::_Ord::equivalent);

  inline constexpr strong_ordering strong_ordering::greater(
      __cmp_cat::_Ord::greater);

  [[nodiscard]]
  constexpr bool is_eq(partial_ordering __cmp) noexcept {
    return __cmp == 0;
  }

  [[nodiscard]]
  constexpr bool is_neq(partial_ordering __cmp) noexcept {
    return __cmp != 0;
  }

  [[nodiscard]]
  constexpr bool is_lt(partial_ordering __cmp) noexcept {
    return __cmp < 0;
  }

  [[nodiscard]]
  constexpr bool is_lteq(partial_ordering __cmp) noexcept {
    return __cmp <= 0;
  }

  [[nodiscard]]
  constexpr bool is_gt(partial_ordering __cmp) noexcept {
    return __cmp > 0;
  }

  [[nodiscard]]
  constexpr bool is_gteq(partial_ordering __cmp) noexcept {
    return __cmp >= 0;
  }

  namespace __detail {
  template <typename _Tp> inline constexpr unsigned __cmp_cat_id = 1;
  template <> inline constexpr unsigned __cmp_cat_id<partial_ordering> = 2;
  template <> inline constexpr unsigned __cmp_cat_id<weak_ordering> = 4;
  template <> inline constexpr unsigned __cmp_cat_id<strong_ordering> = 8;

  template <typename... _Ts> constexpr auto __common_cmp_cat() {
    constexpr unsigned __cats = (__cmp_cat_id<_Ts> | ...);

    if constexpr (__cats & 1)
      return;

    else if constexpr (bool(__cats & __cmp_cat_id<partial_ordering>))
      return partial_ordering::equivalent;

    else if constexpr (bool(__cats & __cmp_cat_id<weak_ordering>))
      return weak_ordering::equivalent;

    else
      return strong_ordering::equivalent;
  }
  } // namespace __detail

  template <typename... _Ts> struct common_comparison_category {
    using type = decltype(__detail::__common_cmp_cat<_Ts...>());
  };

  template <typename _Tp> struct common_comparison_category<_Tp> {
    using type = void;
  };

  template <> struct common_comparison_category<partial_ordering> {
    using type = partial_ordering;
  };

  template <> struct common_comparison_category<weak_ordering> {
    using type = weak_ordering;
  };

  template <> struct common_comparison_category<strong_ordering> {
    using type = strong_ordering;
  };

  template <> struct common_comparison_category<> {
    using type = strong_ordering;
  };

  template <typename... _Ts>
  using common_comparison_category_t =
      typename common_comparison_category<_Ts...>::type;

  namespace __detail {
  template <typename _Tp, typename _Cat>
  concept __compares_as =
      same_as<common_comparison_category_t<_Tp, _Cat>, _Cat>;
  }

  template <typename _Tp, typename _Cat = partial_ordering>
  concept three_way_comparable = __detail::__weakly_eq_cmp_with<_Tp, _Tp> &&
                                 __detail::__partially_ordered_with<_Tp, _Tp> &&
                                 requires(const remove_reference_t<_Tp> &__a,
                                          const remove_reference_t<_Tp> &__b) {
                                   {
                                     __a <=> __b
                                   } -> __detail::__compares_as<_Cat>;
                                 };

  template <typename _Tp, typename _Up, typename _Cat = partial_ordering>
  concept three_way_comparable_with =
      three_way_comparable<_Tp, _Cat> && three_way_comparable<_Up, _Cat> &&
      common_reference_with<const remove_reference_t<_Tp> &,
                            const remove_reference_t<_Up> &> &&
      three_way_comparable<common_reference_t<const remove_reference_t<_Tp> &,
                                              const remove_reference_t<_Up> &>,
                           _Cat> &&
      __detail::__weakly_eq_cmp_with<_Tp, _Up> &&
      __detail::__partially_ordered_with<_Tp, _Up> &&
      requires(const remove_reference_t<_Tp> &__t,
               const remove_reference_t<_Up> &__u) {
        { __t <=> __u } -> __detail::__compares_as<_Cat>;
        { __u <=> __t } -> __detail::__compares_as<_Cat>;
      };

  namespace __detail {
  template <typename _Tp, typename _Up>
  using __cmp3way_res_t = decltype(std::declval<_Tp>() <=> std::declval<_Up>());

  template <typename _Tp, typename _Up> struct __cmp3way_res_impl {};

  template <typename _Tp, typename _Up>
    requires requires { typename __cmp3way_res_t<__cref<_Tp>, __cref<_Up>>; }
  struct __cmp3way_res_impl<_Tp, _Up> {
    using type = __cmp3way_res_t<__cref<_Tp>, __cref<_Up>>;
  };
  } // namespace __detail

  template <typename _Tp, typename _Up = _Tp>
  struct compare_three_way_result : __detail::__cmp3way_res_impl<_Tp, _Up> {};

  template <typename _Tp, typename _Up = _Tp>
  using compare_three_way_result_t =
      typename __detail::__cmp3way_res_impl<_Tp, _Up>::type;

  namespace __detail {

  template <typename _Tp, typename _Up>
  concept __3way_builtin_ptr_cmp =
      requires(_Tp &&__t, _Up &&__u) {
        static_cast<_Tp &&>(__t) <=> static_cast<_Up &&>(__u);
      } && convertible_to<_Tp, const volatile void *> &&
      convertible_to<_Up, const volatile void *> &&
      !requires(_Tp &&__t, _Up &&__u) {
        operator<=>(static_cast<_Tp &&>(__t), static_cast<_Up &&>(__u));
      } && !requires(_Tp &&__t, _Up &&__u) {
        static_cast<_Tp &&>(__t).operator<=>(static_cast<_Up &&>(__u));
      };
  } // namespace __detail

  struct compare_three_way {
    template <typename _Tp, typename _Up>
      requires three_way_comparable_with<_Tp, _Up>
    constexpr auto operator() [[nodiscard]] (_Tp &&__t, _Up &&__u) const
        noexcept(noexcept(std::declval<_Tp>() <=> std::declval<_Up>())) {
      if constexpr (__detail::__3way_builtin_ptr_cmp<_Tp, _Up>) {
        auto __pt = static_cast<const volatile void *>(__t);
        auto __pu = static_cast<const volatile void *>(__u);
        if (std::__is_constant_evaluated())
          return __pt <=> __pu;
        auto __it = reinterpret_cast<long unsigned int>(__pt);
        auto __iu = reinterpret_cast<long unsigned int>(__pu);
        return __it <=> __iu;
      } else
        return static_cast<_Tp &&>(__t) <=> static_cast<_Up &&>(__u);
    }

    using is_transparent = void;
  };

  namespace __compare {
  template <floating_point _Tp>
  constexpr weak_ordering __fp_weak_ordering(_Tp __e, _Tp __f) {

    auto __cat = [](_Tp __fp) -> int {
      const int __sign = __builtin_signbit(__fp) ? -1 : 1;
      if (__builtin_isnormal(__fp))
        return (__fp == 0 ? 1 : 3) * __sign;
      if (__builtin_isnan(__fp))
        return 5 * __sign;
      if (int __inf = __builtin_isinf_sign(__fp))
        return 4 * __inf;
      return 2 * __sign;
    };

    auto __po = __e <=> __f;
    if (is_lt(__po))
      return weak_ordering::less;
    else if (is_gt(__po))
      return weak_ordering::greater;
    else if (__po == partial_ordering::equivalent)
      return weak_ordering::equivalent;
    else {

      auto __isnan_sign = [](_Tp __fp) -> int {
        return __builtin_isnan(__fp) ? __builtin_signbit(__fp) ? -1 : 1 : 0;
      };
      auto __ord = __isnan_sign(__e) <=> __isnan_sign(__f);
      if (is_eq(__ord))
        return weak_ordering::equivalent;
      else if (is_lt(__ord))
        return weak_ordering::less;
      else
        return weak_ordering::greater;
    }
  }

  void strong_order() = delete;

  template <typename _Tp, typename _Up>
  concept __adl_strong = requires(_Tp &&__t, _Up &&__u) {
    strong_ordering(
        strong_order(static_cast<_Tp &&>(__t), static_cast<_Up &&>(__u)));
  };

  void weak_order() = delete;

  template <typename _Tp, typename _Up>
  concept __adl_weak = requires(_Tp &&__t, _Up &&__u) {
    weak_ordering(
        weak_order(static_cast<_Tp &&>(__t), static_cast<_Up &&>(__u)));
  };

  void partial_order() = delete;

  template <typename _Tp, typename _Up>
  concept __adl_partial = requires(_Tp &&__t, _Up &&__u) {
    partial_ordering(
        partial_order(static_cast<_Tp &&>(__t), static_cast<_Up &&>(__u)));
  };

  template <typename _Ord, typename _Tp, typename _Up>
  concept __cmp3way = requires(_Tp &&__t, _Up &&__u, compare_three_way __c) {
    _Ord(__c(static_cast<_Tp &&>(__t), static_cast<_Up &&>(__u)));
  };

  template <typename _Tp, typename _Up>
  concept __strongly_ordered =
      __adl_strong<_Tp, _Up> || floating_point<remove_reference_t<_Tp>> ||
      __cmp3way<strong_ordering, _Tp, _Up>;

  template <typename _Tp, typename _Up>
  concept __decayed_same_as = same_as<decay_t<_Tp>, decay_t<_Up>>;

  class _Strong_order {
    template <typename _Tp, typename _Up> static constexpr bool _S_noexcept() {
      if constexpr (floating_point<decay_t<_Tp>>)
        return true;
      else if constexpr (__adl_strong<_Tp, _Up>)
        return noexcept(strong_ordering(
            strong_order(std::declval<_Tp>(), std::declval<_Up>())));
      else if constexpr (__cmp3way<strong_ordering, _Tp, _Up>)
        return noexcept(
            compare_three_way()(std::declval<_Tp>(), std::declval<_Up>()));
    }

    friend class _Weak_order;
    friend class _Strong_fallback;

    enum class _Fp_fmt {
      _Binary16,
      _Binary32,
      _Binary64,
      _Binary128,
      _X86_80bit,
      _M68k_80bit,
      _Dbldbl,
      _Bfloat16,
    };
    template <typename _Tp> static consteval _Fp_fmt _S_fp_fmt() noexcept {

      using enum _Fp_fmt;
      if constexpr (__is_same(_Tp, long double))
        return (-16381) == -16381 ? _X86_80bit : _M68k_80bit;

      if constexpr (__is_same(_Tp, __float80))
        return _X86_80bit;

      constexpr int __width = sizeof(_Tp) * 8;

      if constexpr (__width == 16)
        return _Binary16;
      else if constexpr (__width == 32)
        return _Binary32;
      else if constexpr (__width == 64)
        return _Binary64;
      else if constexpr (__width == 128)
        return _Binary128;
    }

    using int64_t = long int;
    using int32_t = int;
    using int16_t = short int;
    using uint64_t = long unsigned int;
    using uint16_t = short unsigned int;

    template <typename _Tp> struct _Int {

      uint64_t _M_lo;
      _Tp _M_hi;

      constexpr explicit _Int(_Tp __hi, uint64_t __lo) noexcept : _M_hi(__hi) {
        _M_lo = __lo;
      }

      constexpr explicit _Int(uint64_t __lo) noexcept : _M_hi(0) {
        _M_lo = __lo;
      }

      constexpr bool operator==(const _Int &) const = default;
      constexpr _Int &operator^=(const _Int &__rhs) noexcept {
        _M_hi ^= __rhs._M_hi;
        _M_lo ^= __rhs._M_lo;
        return *this;
      }

      constexpr strong_ordering operator<=>(const _Int &__rhs) const noexcept {
        strong_ordering __cmp = _M_hi <=> __rhs._M_hi;
        if (__cmp != strong_ordering::equal)
          return __cmp;
        return _M_lo <=> __rhs._M_lo;
      }
    };

    template <typename _Tp> static constexpr _Tp _S_compl(_Tp __t) noexcept {
      constexpr int __width = sizeof(_Tp) * 8;

      make_unsigned_t<_Tp> __sign = __t >> (__width - 1);

      return __t ^ (__sign >> 1);
    }

    template <typename _Tp>
    static constexpr _Int<_Tp> _S_compl(_Int<_Tp> __t) noexcept {
      constexpr int __width = sizeof(_Tp) * 8;
      make_unsigned_t<_Tp> __sign = __t._M_hi >> (__width - 1);
      __t._M_hi ^= (__sign >> 1);
      uint64_t __sign64 = (_Tp)__sign;
      __t._M_lo ^= __sign64;
      return __t;
    }

    template <typename _Tp>
    constexpr static auto _S_fp_bits(_Tp __val) noexcept {
      if constexpr (sizeof(_Tp) == sizeof(int64_t))
        return __builtin_bit_cast(int64_t, __val);
      else if constexpr (sizeof(_Tp) == sizeof(int32_t))
        return __builtin_bit_cast(int32_t, __val);
      else if constexpr (sizeof(_Tp) == sizeof(int16_t))
        return __builtin_bit_cast(int16_t, __val);
      else {

        using enum _Fp_fmt;

        constexpr auto __fmt = _S_fp_fmt<_Tp>();
        if constexpr (__fmt == _X86_80bit || __fmt == _M68k_80bit) {
          if constexpr (sizeof(_Tp) == 3 * sizeof(int32_t)) {
            auto __ival = __builtin_bit_cast(_Int<int32_t>, __val);
            return _Int<int16_t>(__ival._M_hi, __ival._M_lo);
          } else {
            auto __ival = __builtin_bit_cast(_Int<int64_t>, __val);
            return _Int<int16_t>(__ival._M_hi, __ival._M_lo);
          }
        } else if constexpr (sizeof(_Tp) == 2 * sizeof(int64_t)) {

          return __builtin_bit_cast(__int128, __val);

        } else
          static_assert(sizeof(_Tp) == sizeof(int64_t),
                        "unsupported floating-point type");
      }
    }

    template <typename _Tp>
    static constexpr strong_ordering _S_fp_cmp(_Tp __x, _Tp __y) noexcept {
      auto __ix = _S_fp_bits(__x);
      auto __iy = _S_fp_bits(__y);

      if (__ix == __iy)
        return strong_ordering::equal;

      using enum _Fp_fmt;

      constexpr auto __fmt = _S_fp_fmt<_Tp>();

      if constexpr (__fmt == _Dbldbl) {

        struct _Unpacked {
          double _M_hi;
          int64_t _M_lo;
        };
        auto __x2 = __builtin_bit_cast(_Unpacked, __x);
        auto __y2 = __builtin_bit_cast(_Unpacked, __y);

        auto __cmp = _S_fp_cmp(__x2._M_hi, __y2._M_hi);
        if (__cmp != strong_ordering::equal)
          return __cmp;

        if (__builtin_isnan(__x2._M_hi))
          return strong_ordering::equal;

        if (((__x2._M_lo | __y2._M_lo) & 0x7fffffffffffffffULL) == 0)
          return strong_ordering::equal;

        return _S_compl(__x2._M_lo) <=> _S_compl(__y2._M_lo);
      } else {
        if constexpr (__fmt == _M68k_80bit) {

          constexpr uint16_t __maxexp = 0x7fff;
          if ((__ix._M_hi & __maxexp) == __maxexp)
            __ix._M_lo |= 1ull << 63;
          if ((__iy._M_hi & __maxexp) == __maxexp)
            __iy._M_lo |= 1ull << 63;
        } else {
        }
        return _S_compl(__ix) <=> _S_compl(__iy);
      }
    }

  public:
    template <typename _Tp, __decayed_same_as<_Tp> _Up>
      requires __strongly_ordered<_Tp, _Up>
    constexpr strong_ordering operator()
        [[nodiscard]] (_Tp &&__e, _Up &&__f) const
        noexcept(_S_noexcept<_Tp, _Up>()) {
      if constexpr (floating_point<decay_t<_Tp>>)
        return _S_fp_cmp(__e, __f);
      else if constexpr (__adl_strong<_Tp, _Up>)
        return strong_ordering(
            strong_order(static_cast<_Tp &&>(__e), static_cast<_Up &&>(__f)));
      else if constexpr (__cmp3way<strong_ordering, _Tp, _Up>)
        return compare_three_way()(static_cast<_Tp &&>(__e),
                                   static_cast<_Up &&>(__f));
    }
  };

  template <typename _Tp, typename _Up>
  concept __weakly_ordered =
      floating_point<remove_reference_t<_Tp>> || __adl_weak<_Tp, _Up> ||
      __cmp3way<weak_ordering, _Tp, _Up> || __strongly_ordered<_Tp, _Up>;

  class _Weak_order {
    template <typename _Tp, typename _Up> static constexpr bool _S_noexcept() {
      if constexpr (floating_point<decay_t<_Tp>>)
        return true;
      else if constexpr (__adl_weak<_Tp, _Up>)
        return noexcept(weak_ordering(
            weak_order(std::declval<_Tp>(), std::declval<_Up>())));
      else if constexpr (__cmp3way<weak_ordering, _Tp, _Up>)
        return noexcept(
            compare_three_way()(std::declval<_Tp>(), std::declval<_Up>()));
      else if constexpr (__strongly_ordered<_Tp, _Up>)
        return _Strong_order::_S_noexcept<_Tp, _Up>();
    }

    friend class _Partial_order;
    friend class _Weak_fallback;

  public:
    template <typename _Tp, __decayed_same_as<_Tp> _Up>
      requires __weakly_ordered<_Tp, _Up>
    constexpr weak_ordering operator()
        [[nodiscard]] (_Tp &&__e, _Up &&__f) const
        noexcept(_S_noexcept<_Tp, _Up>()) {
      if constexpr (floating_point<decay_t<_Tp>>)
        return __compare::__fp_weak_ordering(__e, __f);
      else if constexpr (__adl_weak<_Tp, _Up>)
        return weak_ordering(
            weak_order(static_cast<_Tp &&>(__e), static_cast<_Up &&>(__f)));
      else if constexpr (__cmp3way<weak_ordering, _Tp, _Up>)
        return compare_three_way()(static_cast<_Tp &&>(__e),
                                   static_cast<_Up &&>(__f));
      else if constexpr (__strongly_ordered<_Tp, _Up>)
        return _Strong_order{}(static_cast<_Tp &&>(__e),
                               static_cast<_Up &&>(__f));
    }
  };

  template <typename _Tp, typename _Up>
  concept __partially_ordered =
      __adl_partial<_Tp, _Up> || __cmp3way<partial_ordering, _Tp, _Up> ||
      __weakly_ordered<_Tp, _Up>;

  class _Partial_order {
    template <typename _Tp, typename _Up> static constexpr bool _S_noexcept() {
      if constexpr (__adl_partial<_Tp, _Up>)
        return noexcept(partial_ordering(
            partial_order(std::declval<_Tp>(), std::declval<_Up>())));
      else if constexpr (__cmp3way<partial_ordering, _Tp, _Up>)
        return noexcept(
            compare_three_way()(std::declval<_Tp>(), std::declval<_Up>()));
      else if constexpr (__weakly_ordered<_Tp, _Up>)
        return _Weak_order::_S_noexcept<_Tp, _Up>();
    }

    friend class _Partial_fallback;

  public:
    template <typename _Tp, __decayed_same_as<_Tp> _Up>
      requires __partially_ordered<_Tp, _Up>
    constexpr partial_ordering operator()
        [[nodiscard]] (_Tp &&__e, _Up &&__f) const
        noexcept(_S_noexcept<_Tp, _Up>()) {
      if constexpr (__adl_partial<_Tp, _Up>)
        return partial_ordering(
            partial_order(static_cast<_Tp &&>(__e), static_cast<_Up &&>(__f)));
      else if constexpr (__cmp3way<partial_ordering, _Tp, _Up>)
        return compare_three_way()(static_cast<_Tp &&>(__e),
                                   static_cast<_Up &&>(__f));
      else if constexpr (__weakly_ordered<_Tp, _Up>)
        return _Weak_order{}(static_cast<_Tp &&>(__e),
                             static_cast<_Up &&>(__f));
    }
  };

  template <typename _Tp, typename _Up>
  concept __op_eq_lt = requires(_Tp &&__t, _Up &&__u) {
    {
      static_cast<_Tp &&>(__t) == static_cast<_Up &&>(__u)
    } -> convertible_to<bool>;
    {
      static_cast<_Tp &&>(__t) < static_cast<_Up &&>(__u)
    } -> convertible_to<bool>;
  };

  class _Strong_fallback {
    template <typename _Tp, typename _Up> static constexpr bool _S_noexcept() {
      if constexpr (__strongly_ordered<_Tp, _Up>)
        return _Strong_order::_S_noexcept<_Tp, _Up>();
      else
        return noexcept(bool(std::declval<_Tp>() == std::declval<_Up>())) &&
               noexcept(bool(std::declval<_Tp>() < std::declval<_Up>()));
    }

  public:
    template <typename _Tp, __decayed_same_as<_Tp> _Up>
      requires __strongly_ordered<_Tp, _Up> || __op_eq_lt<_Tp, _Up>
    constexpr strong_ordering operator()
        [[nodiscard]] (_Tp &&__e, _Up &&__f) const
        noexcept(_S_noexcept<_Tp, _Up>()) {
      if constexpr (__strongly_ordered<_Tp, _Up>)
        return _Strong_order{}(static_cast<_Tp &&>(__e),
                               static_cast<_Up &&>(__f));
      else
        return static_cast<_Tp &&>(__e) == static_cast<_Up &&>(__f)
                   ? strong_ordering::equal
               : static_cast<_Tp &&>(__e) < static_cast<_Up &&>(__f)
                   ? strong_ordering::less
                   : strong_ordering::greater;
    }
  };

  class _Weak_fallback {
    template <typename _Tp, typename _Up> static constexpr bool _S_noexcept() {
      if constexpr (__weakly_ordered<_Tp, _Up>)
        return _Weak_order::_S_noexcept<_Tp, _Up>();
      else
        return noexcept(bool(std::declval<_Tp>() == std::declval<_Up>())) &&
               noexcept(bool(std::declval<_Tp>() < std::declval<_Up>()));
    }

  public:
    template <typename _Tp, __decayed_same_as<_Tp> _Up>
      requires __weakly_ordered<_Tp, _Up> || __op_eq_lt<_Tp, _Up>
    constexpr weak_ordering operator()
        [[nodiscard]] (_Tp &&__e, _Up &&__f) const
        noexcept(_S_noexcept<_Tp, _Up>()) {
      if constexpr (__weakly_ordered<_Tp, _Up>)
        return _Weak_order{}(static_cast<_Tp &&>(__e),
                             static_cast<_Up &&>(__f));
      else
        return static_cast<_Tp &&>(__e) == static_cast<_Up &&>(__f)
                   ? weak_ordering::equivalent
               : static_cast<_Tp &&>(__e) < static_cast<_Up &&>(__f)
                   ? weak_ordering::less
                   : weak_ordering::greater;
    }
  };

  template <typename _Tp, typename _Up>
  concept __op_eq_lt_lt =
      __op_eq_lt<_Tp, _Up> && requires(_Tp &&__t, _Up &&__u) {
        {
          static_cast<_Up &&>(__u) < static_cast<_Tp &&>(__t)
        } -> convertible_to<bool>;
      };

  class _Partial_fallback {
    template <typename _Tp, typename _Up> static constexpr bool _S_noexcept() {
      if constexpr (__partially_ordered<_Tp, _Up>)
        return _Partial_order::_S_noexcept<_Tp, _Up>();
      else
        return noexcept(bool(std::declval<_Tp>() == std::declval<_Up>())) &&
               noexcept(bool(std::declval<_Tp>() < std::declval<_Up>()));
    }

  public:
    template <typename _Tp, __decayed_same_as<_Tp> _Up>
      requires __partially_ordered<_Tp, _Up> || __op_eq_lt_lt<_Tp, _Up>
    constexpr partial_ordering operator()
        [[nodiscard]] (_Tp &&__e, _Up &&__f) const
        noexcept(_S_noexcept<_Tp, _Up>()) {
      if constexpr (__partially_ordered<_Tp, _Up>)
        return _Partial_order{}(static_cast<_Tp &&>(__e),
                                static_cast<_Up &&>(__f));
      else
        return static_cast<_Tp &&>(__e) == static_cast<_Up &&>(__f)
                   ? partial_ordering::equivalent
               : static_cast<_Tp &&>(__e) < static_cast<_Up &&>(__f)
                   ? partial_ordering::less
               : static_cast<_Up &&>(__f) < static_cast<_Tp &&>(__e)
                   ? partial_ordering::greater
                   : partial_ordering::unordered;
    }
  };
  } // namespace __compare

  inline namespace _Cpo {
  inline constexpr __compare::_Strong_order strong_order{};

  inline constexpr __compare::_Weak_order weak_order{};

  inline constexpr __compare::_Partial_order partial_order{};

  inline constexpr __compare::_Strong_fallback compare_strong_order_fallback{};

  inline constexpr __compare::_Weak_fallback compare_weak_order_fallback{};

  inline constexpr __compare::_Partial_fallback
      compare_partial_order_fallback{};
  } // namespace _Cpo

  namespace __detail {

  inline constexpr struct _Synth3way {
    template <typename _Tp, typename _Up>
    static constexpr bool _S_noexcept(const _Tp *__t = nullptr,
                                      const _Up *__u = nullptr) {
      if constexpr (three_way_comparable_with<_Tp, _Up>)
        return noexcept(*__t <=> *__u);
      else
        return noexcept(*__t < *__u) && noexcept(*__u < *__t);
    }

    template <typename _Tp, typename _Up>
    [[nodiscard]]
    constexpr auto operator()(const _Tp &__t, const _Up &__u) const
        noexcept(_S_noexcept<_Tp, _Up>())
      requires requires {
        { __t < __u } -> __boolean_testable;
        { __u < __t } -> __boolean_testable;
      }
    {
      if constexpr (three_way_comparable_with<_Tp, _Up>)
        return __t <=> __u;
      else {
        if (__t < __u)
          return weak_ordering::less;
        else if (__u < __t)
          return weak_ordering::greater;
        else
          return weak_ordering::equivalent;
      }
    }
  } __synth3way = {};

  template <typename _Tp, typename _Up = _Tp>
  using __synth3way_t = decltype(__detail::__synth3way(std::declval<_Tp &>(),
                                                       std::declval<_Up &>()));
  } // namespace __detail

} // namespace std

namespace std __attribute__((__visibility__("default"))) {

  struct piecewise_construct_t {
    explicit piecewise_construct_t() = default;
  };

  inline constexpr piecewise_construct_t piecewise_construct =
      piecewise_construct_t();

  template <typename _T1, typename _T2> struct pair;

  template <typename...> class tuple;

  template <typename _Tp, size_t _Nm> struct array;

  template <size_t...> struct _Index_tuple;

  template <size_t _Int, class _Tp1, class _Tp2>
  constexpr typename tuple_element<_Int, pair<_Tp1, _Tp2>>::type &get(
      pair<_Tp1, _Tp2> & __in) noexcept;

  template <size_t _Int, class _Tp1, class _Tp2>
  constexpr typename tuple_element<_Int, pair<_Tp1, _Tp2>>::type &&get(
      pair<_Tp1, _Tp2> && __in) noexcept;

  template <size_t _Int, class _Tp1, class _Tp2>
  constexpr const typename tuple_element<_Int, pair<_Tp1, _Tp2>>::type &get(
      const pair<_Tp1, _Tp2> &__in) noexcept;

  template <size_t _Int, class _Tp1, class _Tp2>
  constexpr const typename tuple_element<_Int, pair<_Tp1, _Tp2>>::type &&get(
      const pair<_Tp1, _Tp2> &&__in) noexcept;

  template <size_t __i, typename... _Elements>
  constexpr __tuple_element_t<__i, tuple<_Elements...>> &get(
      tuple<_Elements...> & __t) noexcept;

  template <size_t __i, typename... _Elements>
  constexpr const __tuple_element_t<__i, tuple<_Elements...>> &get(
      const tuple<_Elements...> &__t) noexcept;

  template <size_t __i, typename... _Elements>
  constexpr __tuple_element_t<__i, tuple<_Elements...>> &&get(
      tuple<_Elements...> && __t) noexcept;

  template <size_t __i, typename... _Elements>
  constexpr const __tuple_element_t<__i, tuple<_Elements...>> &&get(
      const tuple<_Elements...> &&__t) noexcept;

  template <size_t _Int, typename _Tp, size_t _Nm>
  constexpr _Tp &get(array<_Tp, _Nm> &) noexcept;

  template <size_t _Int, typename _Tp, size_t _Nm>
  constexpr _Tp &&get(array<_Tp, _Nm> &&) noexcept;

  template <size_t _Int, typename _Tp, size_t _Nm>
  constexpr const _Tp &get(const array<_Tp, _Nm> &) noexcept;

  template <size_t _Int, typename _Tp, size_t _Nm>
  constexpr const _Tp &&get(const array<_Tp, _Nm> &&) noexcept;
  template <typename _U1, typename _U2> class __pair_base {};
  template <typename _T1, typename _T2>
  struct pair : public __pair_base<_T1, _T2> {
    typedef _T1 first_type;
    typedef _T2 second_type;

    _T1 first;
    _T2 second;

    constexpr pair(const pair &) = default;
    constexpr pair(pair &&) = default;

    template <typename... _Args1, typename... _Args2>
    constexpr pair(piecewise_construct_t, tuple<_Args1...>, tuple<_Args2...>);

    constexpr void
    swap(pair &__p) noexcept(__and_<__is_nothrow_swappable<_T1>,
                                    __is_nothrow_swappable<_T2>>::value) {
      using std::swap;
      swap(first, __p.first);
      swap(second, __p.second);
    }

  private:
    template <typename... _Args1, size_t... _Indexes1, typename... _Args2,
              size_t... _Indexes2>
    constexpr pair(tuple<_Args1...> &, tuple<_Args2...> &,
                   _Index_tuple<_Indexes1...>, _Index_tuple<_Indexes2...>);

  public:
    constexpr explicit(
        __not_<__and_<__is_implicitly_default_constructible<_T1>,
                      __is_implicitly_default_constructible<_T2>>>()) pair()
      requires is_default_constructible_v<_T1> &&
                   is_default_constructible_v<_T2>
        : first(), second() {}

  private:
    template <typename _U1, typename _U2>
    static constexpr bool _S_constructible() {
      if constexpr (is_constructible_v<_T1, _U1>)
        return is_constructible_v<_T2, _U2>;
      return false;
    }

    template <typename _U1, typename _U2>
    static constexpr bool _S_nothrow_constructible() {
      if constexpr (is_nothrow_constructible_v<_T1, _U1>)
        return is_nothrow_constructible_v<_T2, _U2>;
      return false;
    }

    template <typename _U1, typename _U2>
    static constexpr bool _S_convertible() {
      if constexpr (is_convertible_v<_U1, _T1>)
        return is_convertible_v<_U2, _T2>;
      return false;
    }

    template <typename _U1, typename _U2> static constexpr bool _S_dangles() {

      if constexpr (__reference_constructs_from_temporary(_T1, _U1 &&))
        return true;
      else
        return __reference_constructs_from_temporary(_T2, _U2 &&);
    }

  public:
    constexpr explicit(!_S_convertible<const _T1 &, const _T2 &>())
        pair(const _T1 &__x, const _T2 &__y) noexcept(
            _S_nothrow_constructible<const _T1 &, const _T2 &>())
      requires(_S_constructible<const _T1 &, const _T2 &>())
        : first(__x), second(__y) {}

    template <typename _U1, typename _U2>

      requires(_S_constructible<_U1, _U2>()) && (!_S_dangles<_U1, _U2>())
    constexpr explicit(!_S_convertible<_U1, _U2>())
        pair(_U1 &&__x,
             _U2 &&__y) noexcept(_S_nothrow_constructible<_U1, _U2>())
        : first(std::forward<_U1>(__x)), second(std::forward<_U2>(__y)) {}

    template <typename _U1, typename _U2>

      requires(_S_constructible<_U1, _U2>()) && (_S_dangles<_U1, _U2>())
    constexpr explicit(!_S_convertible<_U1, _U2>())
        pair(_U1 &&, _U2 &&) = delete;

    template <typename _U1, typename _U2>
      requires(_S_constructible<const _U1 &, const _U2 &>()) &&
                  (!_S_dangles<_U1, _U2>())
    constexpr explicit(!_S_convertible<const _U1 &, const _U2 &>())
        pair(const pair<_U1, _U2> &__p) noexcept(
            _S_nothrow_constructible<const _U1 &, const _U2 &>())
        : first(__p.first), second(__p.second) {}

    template <typename _U1, typename _U2>
      requires(_S_constructible<const _U1 &, const _U2 &>()) &&
                  (_S_dangles<const _U1 &, const _U2 &>())
    constexpr explicit(!_S_convertible<const _U1 &, const _U2 &>())
        pair(const pair<_U1, _U2> &) = delete;

    template <typename _U1, typename _U2>
      requires(_S_constructible<_U1, _U2>()) && (!_S_dangles<_U1, _U2>())
    constexpr explicit(!_S_convertible<_U1, _U2>()) pair(
        pair<_U1, _U2> &&__p) noexcept(_S_nothrow_constructible<_U1, _U2>())
        : first(std::forward<_U1>(__p.first)),
          second(std::forward<_U2>(__p.second)) {}

    template <typename _U1, typename _U2>
      requires(_S_constructible<_U1, _U2>()) && (_S_dangles<_U1, _U2>())
    constexpr explicit(!_S_convertible<_U1, _U2>())
        pair(pair<_U1, _U2> &&) = delete;

  private:
    template <typename _U1, typename _U2>
    static constexpr bool _S_assignable() {
      if constexpr (is_assignable_v<_T1 &, _U1>)
        return is_assignable_v<_T2 &, _U2>;
      return false;
    }

    template <typename _U1, typename _U2>
    static constexpr bool _S_const_assignable() {
      if constexpr (is_assignable_v<const _T1 &, _U1>)
        return is_assignable_v<const _T2 &, _U2>;
      return false;
    }

    template <typename _U1, typename _U2>
    static constexpr bool _S_nothrow_assignable() {
      if constexpr (is_nothrow_assignable_v<_T1 &, _U1>)
        return is_nothrow_assignable_v<_T2 &, _U2>;
      return false;
    }

  public:
    pair &operator=(const pair &) = delete;

    constexpr pair &operator=(const pair &__p) noexcept(
        _S_nothrow_assignable<const _T1 &, const _T2 &>())
      requires(_S_assignable<const _T1 &, const _T2 &>())
    {
      first = __p.first;
      second = __p.second;
      return *this;
    }

    constexpr pair &
    operator=(pair &&__p) noexcept(_S_nothrow_assignable<_T1, _T2>())
      requires(_S_assignable<_T1, _T2>())
    {
      first = std::forward<first_type>(__p.first);
      second = std::forward<second_type>(__p.second);
      return *this;
    }

    template <typename _U1, typename _U2>
    constexpr pair &operator=(const pair<_U1, _U2> &__p) noexcept(
        _S_nothrow_assignable<const _U1 &, const _U2 &>())
      requires(_S_assignable<const _U1 &, const _U2 &>())
    {
      first = __p.first;
      second = __p.second;
      return *this;
    }

    template <typename _U1, typename _U2>
    constexpr pair &
    operator=(pair<_U1, _U2> &&__p) noexcept(_S_nothrow_assignable<_U1, _U2>())
      requires(_S_assignable<_U1, _U2>())
    {
      first = std::forward<_U1>(__p.first);
      second = std::forward<_U2>(__p.second);
      return *this;
    }
  };

  template <typename _T1, typename _T2> pair(_T1, _T2) -> pair<_T1, _T2>;

  template <typename _T1, typename _T2, typename _U1, typename _U2>
  inline constexpr bool operator==(const pair<_T1, _T2> &__x,
                                   const pair<_U1, _U2> &__y) {
    return __x.first == __y.first && __x.second == __y.second;
  }
  template <typename _T1, typename _T2, typename _U1, typename _U2>
  constexpr common_comparison_category_t<__detail::__synth3way_t<_T1, _U1>,
                                         __detail::__synth3way_t<_T2, _U2>>
  operator<=>(const pair<_T1, _T2> &__x, const pair<_U1, _U2> &__y) {
    if (auto __c = __detail::__synth3way(__x.first, __y.first); __c != 0)
      return __c;
    return __detail::__synth3way(__x.second, __y.second);
  }
  template <typename _T1, typename _T2>
  constexpr inline

      typename enable_if<
          __and_<__is_swappable<_T1>, __is_swappable<_T2>>::value>::type

      swap(pair<_T1, _T2> & __x,
           pair<_T1, _T2> & __y) noexcept(noexcept(__x.swap(__y))) {
    __x.swap(__y);
  }
  template <typename _T1, typename _T2>
  typename enable_if<
      !__and_<__is_swappable<_T1>, __is_swappable<_T2>>::value>::type
  swap(pair<_T1, _T2> &, pair<_T1, _T2> &) = delete;
  template <typename _T1, typename _T2>
  constexpr pair<typename __decay_and_strip<_T1>::__type,
                 typename __decay_and_strip<_T2>::__type>
  make_pair(_T1 && __x, _T2 && __y) {
    typedef typename __decay_and_strip<_T1>::__type __ds_type1;
    typedef typename __decay_and_strip<_T2>::__type __ds_type2;
    typedef pair<__ds_type1, __ds_type2> __pair_type;
    return __pair_type(std::forward<_T1>(__x), std::forward<_T2>(__y));
  }
  template <typename _T1, typename _T2>
  struct __is_tuple_like_impl<pair<_T1, _T2>> : true_type {};

  template <class _Tp1, class _Tp2>
  struct tuple_size<pair<_Tp1, _Tp2>> : public integral_constant<size_t, 2> {};

  template <class _Tp1, class _Tp2> struct tuple_element<0, pair<_Tp1, _Tp2>> {
    typedef _Tp1 type;
  };

  template <class _Tp1, class _Tp2> struct tuple_element<1, pair<_Tp1, _Tp2>> {
    typedef _Tp2 type;
  };

  template <size_t __i, typename... _Types>
  struct tuple_element<__i, tuple<_Types...>>;

  template <typename _Tp1, typename _Tp2>
  inline constexpr size_t tuple_size_v<pair<_Tp1, _Tp2>> = 2;

  template <typename _Tp1, typename _Tp2>
  inline constexpr size_t tuple_size_v<const pair<_Tp1, _Tp2>> = 2;

  template <typename _Tp> inline constexpr bool __is_pair = false;

  template <typename _Tp, typename _Up>
  inline constexpr bool __is_pair<pair<_Tp, _Up>> = true;

  template <size_t _Int> struct __pair_get;

  template <> struct __pair_get<0> {
    template <typename _Tp1, typename _Tp2>
    static constexpr _Tp1 &__get(pair<_Tp1, _Tp2> &__pair) noexcept {
      return __pair.first;
    }

    template <typename _Tp1, typename _Tp2>
    static constexpr _Tp1 &&__move_get(pair<_Tp1, _Tp2> &&__pair) noexcept {
      return std::forward<_Tp1>(__pair.first);
    }

    template <typename _Tp1, typename _Tp2>
    static constexpr const _Tp1 &
    __const_get(const pair<_Tp1, _Tp2> &__pair) noexcept {
      return __pair.first;
    }

    template <typename _Tp1, typename _Tp2>
    static constexpr const _Tp1 &&
    __const_move_get(const pair<_Tp1, _Tp2> &&__pair) noexcept {
      return std::forward<const _Tp1>(__pair.first);
    }
  };

  template <> struct __pair_get<1> {
    template <typename _Tp1, typename _Tp2>
    static constexpr _Tp2 &__get(pair<_Tp1, _Tp2> &__pair) noexcept {
      return __pair.second;
    }

    template <typename _Tp1, typename _Tp2>
    static constexpr _Tp2 &&__move_get(pair<_Tp1, _Tp2> &&__pair) noexcept {
      return std::forward<_Tp2>(__pair.second);
    }

    template <typename _Tp1, typename _Tp2>
    static constexpr const _Tp2 &
    __const_get(const pair<_Tp1, _Tp2> &__pair) noexcept {
      return __pair.second;
    }

    template <typename _Tp1, typename _Tp2>
    static constexpr const _Tp2 &&
    __const_move_get(const pair<_Tp1, _Tp2> &&__pair) noexcept {
      return std::forward<const _Tp2>(__pair.second);
    }
  };

  template <size_t _Int, class _Tp1, class _Tp2>
  constexpr typename tuple_element<_Int, pair<_Tp1, _Tp2>>::type &get(
      pair<_Tp1, _Tp2> & __in) noexcept {
    return __pair_get<_Int>::__get(__in);
  }

  template <size_t _Int, class _Tp1, class _Tp2>
  constexpr typename tuple_element<_Int, pair<_Tp1, _Tp2>>::type &&get(
      pair<_Tp1, _Tp2> && __in) noexcept {
    return __pair_get<_Int>::__move_get(std::move(__in));
  }

  template <size_t _Int, class _Tp1, class _Tp2>
  constexpr const typename tuple_element<_Int, pair<_Tp1, _Tp2>>::type &get(
      const pair<_Tp1, _Tp2> &__in) noexcept {
    return __pair_get<_Int>::__const_get(__in);
  }

  template <size_t _Int, class _Tp1, class _Tp2>
  constexpr const typename tuple_element<_Int, pair<_Tp1, _Tp2>>::type &&get(
      const pair<_Tp1, _Tp2> &&__in) noexcept {
    return __pair_get<_Int>::__const_move_get(std::move(__in));
  }

  template <typename _Tp, typename _Up>
  constexpr _Tp &get(pair<_Tp, _Up> & __p) noexcept {
    return __p.first;
  }

  template <typename _Tp, typename _Up>
  constexpr const _Tp &get(const pair<_Tp, _Up> &__p) noexcept {
    return __p.first;
  }

  template <typename _Tp, typename _Up>
  constexpr _Tp &&get(pair<_Tp, _Up> && __p) noexcept {
    return std::move(__p.first);
  }

  template <typename _Tp, typename _Up>
  constexpr const _Tp &&get(const pair<_Tp, _Up> &&__p) noexcept {
    return std::move(__p.first);
  }

  template <typename _Tp, typename _Up>
  constexpr _Tp &get(pair<_Up, _Tp> & __p) noexcept {
    return __p.second;
  }

  template <typename _Tp, typename _Up>
  constexpr const _Tp &get(const pair<_Up, _Tp> &__p) noexcept {
    return __p.second;
  }

  template <typename _Tp, typename _Up>
  constexpr _Tp &&get(pair<_Up, _Tp> && __p) noexcept {
    return std::move(__p.second);
  }

  template <typename _Tp, typename _Up>
  constexpr const _Tp &&get(const pair<_Up, _Tp> &&__p) noexcept {
    return std::move(__p.second);
  }

} // namespace std
namespace std __attribute__((__visibility__("default"))) {

  struct __erased_type {};

  template <typename _Alloc, typename _Tp>
  using __is_erased_or_convertible =
      __or_<is_convertible<_Alloc, _Tp>, is_same<_Tp, __erased_type>>;

  struct allocator_arg_t {
    explicit allocator_arg_t() = default;
  };

  inline constexpr allocator_arg_t allocator_arg = allocator_arg_t();

  template <typename _Tp, typename _Alloc, typename = __void_t<>>
  struct __uses_allocator_helper : false_type {};

  template <typename _Tp, typename _Alloc>
  struct __uses_allocator_helper<_Tp, _Alloc,
                                 __void_t<typename _Tp::allocator_type>>
      : __is_erased_or_convertible<_Alloc, typename _Tp::allocator_type>::type {
  };

  template <typename _Tp, typename _Alloc>
  struct uses_allocator : __uses_allocator_helper<_Tp, _Alloc>::type {};

  struct __uses_alloc_base {};

  struct __uses_alloc0 : __uses_alloc_base {
    struct _Sink {
      void constexpr operator=(const void *) {}
    } _M_a;
  };

  template <typename _Alloc> struct __uses_alloc1 : __uses_alloc_base {
    const _Alloc *_M_a;
  };

  template <typename _Alloc> struct __uses_alloc2 : __uses_alloc_base {
    const _Alloc *_M_a;
  };

  template <bool, typename _Tp, typename _Alloc, typename... _Args>
  struct __uses_alloc;

  template <typename _Tp, typename _Alloc, typename... _Args>
  struct __uses_alloc<true, _Tp, _Alloc, _Args...>
      : __conditional_t<is_constructible<_Tp, allocator_arg_t, const _Alloc &,
                                         _Args...>::value,
                        __uses_alloc1<_Alloc>, __uses_alloc2<_Alloc>> {

    static_assert(
        __or_<is_constructible<_Tp, allocator_arg_t, const _Alloc &, _Args...>,
              is_constructible<_Tp, _Args..., const _Alloc &>>::value,
        "construction with an allocator must be possible"
        " if uses_allocator is true");
  };

  template <typename _Tp, typename _Alloc, typename... _Args>
  struct __uses_alloc<false, _Tp, _Alloc, _Args...> : __uses_alloc0 {};

  template <typename _Tp, typename _Alloc, typename... _Args>
  using __uses_alloc_t =
      __uses_alloc<uses_allocator<_Tp, _Alloc>::value, _Tp, _Alloc, _Args...>;

  template <typename _Tp, typename _Alloc, typename... _Args>
  constexpr inline __uses_alloc_t<_Tp, _Alloc, _Args...> __use_alloc(
      const _Alloc &__a) {
    __uses_alloc_t<_Tp, _Alloc, _Args...> __ret;
    __ret._M_a = std::__addressof(__a);
    return __ret;
  }

  template <typename _Tp, typename _Alloc, typename... _Args>
  void __use_alloc(const _Alloc &&) = delete;

  template <typename _Tp, typename _Alloc>
  inline constexpr bool uses_allocator_v = uses_allocator<_Tp, _Alloc>::value;

  template <template <typename...> class _Predicate, typename _Tp,
            typename _Alloc, typename... _Args>
  struct __is_uses_allocator_predicate
      : __conditional_t<
            uses_allocator<_Tp, _Alloc>::value,
            __or_<_Predicate<_Tp, allocator_arg_t, _Alloc, _Args...>,
                  _Predicate<_Tp, _Args..., _Alloc>>,
            _Predicate<_Tp, _Args...>> {};

  template <typename _Tp, typename _Alloc, typename... _Args>
  struct __is_uses_allocator_constructible
      : __is_uses_allocator_predicate<is_constructible, _Tp, _Alloc, _Args...> {
  };

  template <typename _Tp, typename _Alloc, typename... _Args>
  inline constexpr bool __is_uses_allocator_constructible_v =
      __is_uses_allocator_constructible<_Tp, _Alloc, _Args...>::value;

  template <typename _Tp, typename _Alloc, typename... _Args>
  struct __is_nothrow_uses_allocator_constructible
      : __is_uses_allocator_predicate<is_nothrow_constructible, _Tp, _Alloc,
                                      _Args...> {};

  template <typename _Tp, typename _Alloc, typename... _Args>
  inline constexpr bool __is_nothrow_uses_allocator_constructible_v =
      __is_nothrow_uses_allocator_constructible<_Tp, _Alloc, _Args...>::value;

  template <typename _Tp, typename... _Args>
  void __uses_allocator_construct_impl(__uses_alloc0, _Tp * __ptr,
                                       _Args && ...__args) {
    ::new ((void *)__ptr) _Tp(std::forward<_Args>(__args)...);
  }

  template <typename _Tp, typename _Alloc, typename... _Args>
  void __uses_allocator_construct_impl(__uses_alloc1<_Alloc> __a, _Tp * __ptr,
                                       _Args && ...__args) {
    ::new ((void *)__ptr)
        _Tp(allocator_arg, *__a._M_a, std::forward<_Args>(__args)...);
  }

  template <typename _Tp, typename _Alloc, typename... _Args>
  void __uses_allocator_construct_impl(__uses_alloc2<_Alloc> __a, _Tp * __ptr,
                                       _Args && ...__args) {
    ::new ((void *)__ptr) _Tp(std::forward<_Args>(__args)..., *__a._M_a);
  }

  template <typename _Tp, typename _Alloc, typename... _Args>
  void __uses_allocator_construct(const _Alloc &__a, _Tp *__ptr,
                                  _Args &&...__args) {
    std::__uses_allocator_construct_impl(
        std::__use_alloc<_Tp, _Alloc, _Args...>(__a), __ptr,
        std::forward<_Args>(__args)...);
  }

} // namespace std

namespace std __attribute__((__visibility__("default"))) {

  template <typename _Tp, typename _Up = typename __inv_unwrap<_Tp>::type>
  constexpr _Up &&__invfwd(typename remove_reference<_Tp>::type &
                           __t) noexcept {
    return static_cast<_Up &&>(__t);
  }

  template <typename _Res, typename _Fn, typename... _Args>
  constexpr _Res __invoke_impl(__invoke_other, _Fn && __f, _Args && ...__args) {
    return std::forward<_Fn>(__f)(std::forward<_Args>(__args)...);
  }

  template <typename _Res, typename _MemFun, typename _Tp, typename... _Args>
  constexpr _Res __invoke_impl(__invoke_memfun_ref, _MemFun && __f, _Tp && __t,
                               _Args && ...__args) {
    return (__invfwd<_Tp>(__t).*__f)(std::forward<_Args>(__args)...);
  }

  template <typename _Res, typename _MemFun, typename _Tp, typename... _Args>
  constexpr _Res __invoke_impl(__invoke_memfun_deref, _MemFun && __f,
                               _Tp && __t, _Args && ...__args) {
    return ((*std::forward<_Tp>(__t)).*__f)(std::forward<_Args>(__args)...);
  }

  template <typename _Res, typename _MemPtr, typename _Tp>
  constexpr _Res __invoke_impl(__invoke_memobj_ref, _MemPtr && __f,
                               _Tp && __t) {
    return __invfwd<_Tp>(__t).*__f;
  }

  template <typename _Res, typename _MemPtr, typename _Tp>
  constexpr _Res __invoke_impl(__invoke_memobj_deref, _MemPtr && __f,
                               _Tp && __t) {
    return (*std::forward<_Tp>(__t)).*__f;
  }

  template <typename _Callable, typename... _Args>
  constexpr typename __invoke_result<_Callable, _Args...>::type
  __invoke(_Callable && __fn, _Args && ...__args) noexcept(
      __is_nothrow_invocable<_Callable, _Args...>::value) {
    using __result = __invoke_result<_Callable, _Args...>;
    using __type = typename __result::type;
    using __tag = typename __result::__invoke_type;
    return std::__invoke_impl<__type>(__tag{}, std::forward<_Callable>(__fn),
                                      std::forward<_Args>(__args)...);
  }

  template <typename _Res, typename _Callable, typename... _Args>
  constexpr enable_if_t<is_invocable_r_v<_Res, _Callable, _Args...>, _Res>
  __invoke_r(_Callable && __fn, _Args && ...__args) noexcept(
      is_nothrow_invocable_r_v<_Res, _Callable, _Args...>) {
    using __result = __invoke_result<_Callable, _Args...>;
    using __type = typename __result::type;
    using __tag = typename __result::__invoke_type;
    if constexpr (is_void_v<_Res>)
      std::__invoke_impl<__type>(__tag{}, std::forward<_Callable>(__fn),
                                 std::forward<_Args>(__args)...);
    else
      return std::__invoke_impl<__type>(__tag{}, std::forward<_Callable>(__fn),
                                        std::forward<_Args>(__args)...);
  }

} // namespace std

extern "C++" {

namespace std __attribute__((__visibility__("default"))) {

  struct __true_type {};
  struct __false_type {};

  template <bool> struct __truth_type {
    typedef __false_type __type;
  };

  template <> struct __truth_type<true> {
    typedef __true_type __type;
  };

  template <class _Sp, class _Tp> struct __traitor {
    enum { __value = bool(_Sp::__value) || bool(_Tp::__value) };
    typedef typename __truth_type<__value>::__type __type;
  };

  template <typename, typename> struct __are_same {
    enum { __value = 0 };
    typedef __false_type __type;
  };

  template <typename _Tp> struct __are_same<_Tp, _Tp> {
    enum { __value = 1 };
    typedef __true_type __type;
  };

  template <typename _Tp> struct __is_void {
    enum { __value = 0 };
    typedef __false_type __type;
  };

  template <> struct __is_void<void> {
    enum { __value = 1 };
    typedef __true_type __type;
  };

  template <typename _Tp> struct __is_integer {
    enum { __value = 0 };
    typedef __false_type __type;
  };

  template <> struct __is_integer<bool> {
    enum { __value = 1 };
    typedef __true_type __type;
  };

  template <> struct __is_integer<char> {
    enum { __value = 1 };
    typedef __true_type __type;
  };

  template <> struct __is_integer<signed char> {
    enum { __value = 1 };
    typedef __true_type __type;
  };

  template <> struct __is_integer<unsigned char> {
    enum { __value = 1 };
    typedef __true_type __type;
  };

  template <> struct __is_integer<wchar_t> {
    enum { __value = 1 };
    typedef __true_type __type;
  };

  template <> struct __is_integer<char8_t> {
    enum { __value = 1 };
    typedef __true_type __type;
  };

  template <> struct __is_integer<char16_t> {
    enum { __value = 1 };
    typedef __true_type __type;
  };

  template <> struct __is_integer<char32_t> {
    enum { __value = 1 };
    typedef __true_type __type;
  };

  template <> struct __is_integer<short> {
    enum { __value = 1 };
    typedef __true_type __type;
  };

  template <> struct __is_integer<unsigned short> {
    enum { __value = 1 };
    typedef __true_type __type;
  };

  template <> struct __is_integer<int> {
    enum { __value = 1 };
    typedef __true_type __type;
  };

  template <> struct __is_integer<unsigned int> {
    enum { __value = 1 };
    typedef __true_type __type;
  };

  template <> struct __is_integer<long> {
    enum { __value = 1 };
    typedef __true_type __type;
  };

  template <> struct __is_integer<unsigned long> {
    enum { __value = 1 };
    typedef __true_type __type;
  };

  template <> struct __is_integer<long long> {
    enum { __value = 1 };
    typedef __true_type __type;
  };

  template <> struct __is_integer<unsigned long long> {
    enum { __value = 1 };
    typedef __true_type __type;
  };
  __extension__ template <> struct __is_integer<__int128> {
    enum { __value = 1 };
    typedef __true_type __type;
  };
  __extension__ template <> struct __is_integer<unsigned __int128> {
    enum { __value = 1 };
    typedef __true_type __type;
  };
  template <typename _Tp> struct __is_floating {
    enum { __value = 0 };
    typedef __false_type __type;
  };

  template <> struct __is_floating<float> {
    enum { __value = 1 };
    typedef __true_type __type;
  };

  template <> struct __is_floating<double> {
    enum { __value = 1 };
    typedef __true_type __type;
  };

  template <> struct __is_floating<long double> {
    enum { __value = 1 };
    typedef __true_type __type;
  };
  template <typename _Tp> struct __is_pointer {
    enum { __value = 0 };
    typedef __false_type __type;
  };

  template <typename _Tp> struct __is_pointer<_Tp *> {
    enum { __value = 1 };
    typedef __true_type __type;
  };

  template <typename _Tp>
  struct __is_arithmetic
      : public __traitor<__is_integer<_Tp>, __is_floating<_Tp>>{};

  template <typename _Tp>
  struct __is_scalar
      : public __traitor<__is_arithmetic<_Tp>, __is_pointer<_Tp>>{};

  template <typename _Tp> struct __is_char {
    enum { __value = 0 };
    typedef __false_type __type;
  };

  template <> struct __is_char<char> {
    enum { __value = 1 };
    typedef __true_type __type;
  };

  template <> struct __is_char<wchar_t> {
    enum { __value = 1 };
    typedef __true_type __type;
  };

  template <typename _Tp> struct __is_byte {
    enum { __value = 0 };
    typedef __false_type __type;
  };

  template <> struct __is_byte<char> {
    enum { __value = 1 };
    typedef __true_type __type;
  };

  template <> struct __is_byte<signed char> {
    enum { __value = 1 };
    typedef __true_type __type;
  };

  template <> struct __is_byte<unsigned char> {
    enum { __value = 1 };
    typedef __true_type __type;
  };

  enum class byte : unsigned char;

  template <> struct __is_byte<byte> {
    enum { __value = 1 };
    typedef __true_type __type;
  };

  template <> struct __is_byte<char8_t> {
    enum { __value = 1 };
    typedef __true_type __type;
  };

  template <typename> struct iterator_traits;

  template <typename _Tp> struct __is_nonvolatile_trivially_copyable {
    enum { __value = __is_trivially_copyable(_Tp) };
  };

  template <typename _Tp>
  struct __is_nonvolatile_trivially_copyable<volatile _Tp> {
    enum { __value = 0 };
  };

  template <typename _OutputIter, typename _InputIter> struct __memcpyable {
    enum { __value = 0 };
  };

  template <typename _Tp>
  struct __memcpyable<_Tp *, _Tp *> : __is_nonvolatile_trivially_copyable<_Tp> {
  };

  template <typename _Tp>
  struct __memcpyable<_Tp *, const _Tp *>
      : __is_nonvolatile_trivially_copyable<_Tp> {};

  template <typename _Iter1, typename _Iter2> struct __memcmpable {
    enum { __value = 0 };
  };

  template <typename _Tp>
  struct __memcmpable<_Tp *, _Tp *> : __is_nonvolatile_trivially_copyable<_Tp> {
  };

  template <typename _Tp>
  struct __memcmpable<const _Tp *, _Tp *>
      : __is_nonvolatile_trivially_copyable<_Tp> {};

  template <typename _Tp>
  struct __memcmpable<_Tp *, const _Tp *>
      : __is_nonvolatile_trivially_copyable<_Tp> {};

  template <typename _Tp, bool _TreatAsBytes =

                              __is_byte<_Tp>::__value

            >
  struct __is_memcmp_ordered {
    static const bool __value = _Tp(-1) > _Tp(1);
  };

  template <typename _Tp> struct __is_memcmp_ordered<_Tp, false> {
    static const bool __value = false;
  };

  template <typename _Tp, typename _Up, bool = sizeof(_Tp) == sizeof(_Up)>
  struct __is_memcmp_ordered_with {
    static const bool __value =
        __is_memcmp_ordered<_Tp>::__value && __is_memcmp_ordered<_Up>::__value;
  };

  template <typename _Tp, typename _Up>
  struct __is_memcmp_ordered_with<_Tp, _Up, false> {
    static const bool __value = false;
  };
  template <> struct __is_memcmp_ordered_with<std::byte, std::byte, true> {
    static constexpr bool __value = true;
  };

  template <typename _Tp, bool _SameSize>
  struct __is_memcmp_ordered_with<_Tp, std::byte, _SameSize> {
    static constexpr bool __value = false;
  };

  template <typename _Up, bool _SameSize>
  struct __is_memcmp_ordered_with<std::byte, _Up, _SameSize> {
    static constexpr bool __value = false;
  };

  template <typename _Tp> struct __is_move_iterator {
    enum { __value = 0 };
    typedef __false_type __type;
  };

  template <typename _Iterator>
  constexpr inline _Iterator __miter_base(_Iterator __it) {
    return __it;
  }

} // namespace std
}

namespace __gnu_debug {
struct _Safe_iterator_base;
}

namespace std __attribute__((__visibility__("default"))) {

  class __undefined;

  template <typename _Tp> struct __get_first_arg {
    using type = __undefined;
  };

  template <template <typename, typename...> class _SomeTemplate, typename _Tp,
            typename... _Types>
  struct __get_first_arg<_SomeTemplate<_Tp, _Types...>> {
    using type = _Tp;
  };

  template <typename _Tp, typename _Up> struct __replace_first_arg {};

  template <template <typename, typename...> class _SomeTemplate, typename _Up,
            typename _Tp, typename... _Types>
  struct __replace_first_arg<_SomeTemplate<_Tp, _Types...>, _Up> {
    using type = _SomeTemplate<_Up, _Types...>;
  };

  template <typename _Ptr, typename = void>
  struct __ptr_traits_elem : __get_first_arg<_Ptr> {};

  template <typename _Ptr>
    requires requires { typename _Ptr::element_type; }
  struct __ptr_traits_elem<_Ptr, void> {
    using type = typename _Ptr::element_type;
  };

  template <typename _Ptr>
  using __ptr_traits_elem_t = typename __ptr_traits_elem<_Ptr>::type;

  template <typename _Ptr, typename _Elt, bool = is_void<_Elt>::value>
  struct __ptr_traits_ptr_to {
    using pointer = _Ptr;
    using element_type = _Elt;

    static pointer pointer_to(element_type &__r)

      requires requires {
        { pointer::pointer_to(__r) } -> convertible_to<pointer>;
      }

    {
      return pointer::pointer_to(__r);
    }
  };

  template <typename _Ptr, typename _Elt>
  struct __ptr_traits_ptr_to<_Ptr, _Elt, true> {};

  template <typename _Tp> struct __ptr_traits_ptr_to<_Tp *, _Tp, false> {
    using pointer = _Tp *;
    using element_type = _Tp;

    static constexpr pointer pointer_to(element_type &__r) noexcept {
      return std::addressof(__r);
    }
  };

  template <typename _Ptr, typename _Elt>
  struct __ptr_traits_impl : __ptr_traits_ptr_to<_Ptr, _Elt> {
  private:
    template <typename _Tp> using __diff_t = typename _Tp::difference_type;

    template <typename _Tp, typename _Up>
    using __rebind = __type_identity<typename _Tp::template rebind<_Up>>;

  public:
    using pointer = _Ptr;

    using element_type = _Elt;

    using difference_type = __detected_or_t<ptrdiff_t, __diff_t, _Ptr>;

    template <typename _Up>
    using rebind = typename __detected_or_t<__replace_first_arg<_Ptr, _Up>,
                                            __rebind, _Ptr, _Up>::type;
  };

  template <typename _Ptr> struct __ptr_traits_impl<_Ptr, __undefined> {};

  template <typename _Ptr>
  struct pointer_traits : __ptr_traits_impl<_Ptr, __ptr_traits_elem_t<_Ptr>> {};

  template <typename _Tp>
  struct pointer_traits<_Tp *> : __ptr_traits_ptr_to<_Tp *, _Tp> {

    typedef _Tp *pointer;

    typedef _Tp element_type;

    typedef ptrdiff_t difference_type;

    template <typename _Up> using rebind = _Up *;
  };

  template <typename _Ptr, typename _Tp>
  using __ptr_rebind = typename pointer_traits<_Ptr>::template rebind<_Tp>;

  template <typename _Tp> constexpr _Tp *__to_address(_Tp * __ptr) noexcept {
    static_assert(!std::is_function<_Tp>::value, "not a function pointer");
    return __ptr;
  }

  template <typename _Ptr>
  constexpr auto __to_address(const _Ptr &__ptr) noexcept
      -> decltype(std::pointer_traits<_Ptr>::to_address(__ptr)) {
    return std::pointer_traits<_Ptr>::to_address(__ptr);
  }

  template <typename _Ptr, typename... _None>
  constexpr auto __to_address(const _Ptr &__ptr, _None...) noexcept {
    if constexpr (is_base_of_v<__gnu_debug::_Safe_iterator_base, _Ptr>)
      return std::__to_address(__ptr.base().operator->());
    else
      return std::__to_address(__ptr.operator->());
  }

  template <typename _Tp> constexpr _Tp *to_address(_Tp * __ptr) noexcept {
    return std::__to_address(__ptr);
  }
  template <typename _Ptr>
  constexpr auto to_address(const _Ptr &__ptr) noexcept {
    return std::__to_address(__ptr);
  }

} // namespace std
namespace std __attribute__((__visibility__("default"))) {

  struct __is_transparent;

  struct identity {
    template <typename _Tp>
    [[nodiscard]]
    constexpr _Tp &&operator()(_Tp &&__t) const noexcept {
      return std::forward<_Tp>(__t);
    }

    using is_transparent = __is_transparent;
  };

  namespace ranges {
  namespace __detail {

  template<typename _Tp, typename _Up>
      concept __less_builtin_ptr_cmp
 = requires (_Tp&& __t, _Up&& __u) { { __t < __u } -> same_as<bool>; }
   && convertible_to<_Tp, const volatile void*>
   && convertible_to<_Up, const volatile void*>
   && (! requires(_Tp&& __t, _Up&& __u)
       { operator<(std::forward<_Tp>(__t), std::forward<_Up>(__u)); }
       && ! requires(_Tp&& __t, _Up&& __u)
       { std::forward<_Tp>(__t).operator<(std::forward<_Up>(__u)); });
  } // namespace __detail

  struct equal_to {
    template <typename _Tp, typename _Up>
      requires equality_comparable_with<_Tp, _Up>
    constexpr bool operator()(_Tp &&__t, _Up &&__u) const
        noexcept(noexcept(std::declval<_Tp>() == std::declval<_Up>())) {
      return std::forward<_Tp>(__t) == std::forward<_Up>(__u);
    }

    using is_transparent = __is_transparent;
  };

  struct not_equal_to {
    template <typename _Tp, typename _Up>
      requires equality_comparable_with<_Tp, _Up>
    constexpr bool operator()(_Tp &&__t, _Up &&__u) const
        noexcept(noexcept(std::declval<_Up>() == std::declval<_Tp>())) {
      return !equal_to{}(std::forward<_Tp>(__t), std::forward<_Up>(__u));
    }

    using is_transparent = __is_transparent;
  };

  struct less {
    template <typename _Tp, typename _Up>
      requires totally_ordered_with<_Tp, _Up>
    constexpr bool operator()(_Tp &&__t, _Up &&__u) const
        noexcept(noexcept(std::declval<_Tp>() < std::declval<_Up>())) {
      if constexpr (__detail::__less_builtin_ptr_cmp<_Tp, _Up>) {
        if (std::__is_constant_evaluated())
          return __t < __u;

        auto __x = reinterpret_cast<long unsigned int>(
            static_cast<const volatile void *>(std::forward<_Tp>(__t)));
        auto __y = reinterpret_cast<long unsigned int>(
            static_cast<const volatile void *>(std::forward<_Up>(__u)));
        return __x < __y;
      } else
        return std::forward<_Tp>(__t) < std::forward<_Up>(__u);
    }

    using is_transparent = __is_transparent;
  };

  struct greater {
    template <typename _Tp, typename _Up>
      requires totally_ordered_with<_Tp, _Up>
    constexpr bool operator()(_Tp &&__t, _Up &&__u) const
        noexcept(noexcept(std::declval<_Up>() < std::declval<_Tp>())) {
      return less{}(std::forward<_Up>(__u), std::forward<_Tp>(__t));
    }

    using is_transparent = __is_transparent;
  };

  struct greater_equal {
    template <typename _Tp, typename _Up>
      requires totally_ordered_with<_Tp, _Up>
    constexpr bool operator()(_Tp &&__t, _Up &&__u) const
        noexcept(noexcept(std::declval<_Tp>() < std::declval<_Up>())) {
      return !less{}(std::forward<_Tp>(__t), std::forward<_Up>(__u));
    }

    using is_transparent = __is_transparent;
  };

  struct less_equal {
    template <typename _Tp, typename _Up>
      requires totally_ordered_with<_Tp, _Up>
    constexpr bool operator()(_Tp &&__t, _Up &&__u) const
        noexcept(noexcept(std::declval<_Up>() < std::declval<_Tp>())) {
      return !less{}(std::forward<_Up>(__u), std::forward<_Tp>(__t));
    }

    using is_transparent = __is_transparent;
  };

  } // namespace ranges

} // namespace std

namespace std __attribute__((__visibility__("default"))) {

  struct default_sentinel_t {};

  inline constexpr default_sentinel_t default_sentinel{};

  struct input_iterator_tag;
  struct output_iterator_tag;
  struct forward_iterator_tag;
  struct bidirectional_iterator_tag;
  struct random_access_iterator_tag;
  struct contiguous_iterator_tag;

  template <typename _Iterator> struct iterator_traits;

  template <typename _Tp>
    requires is_object_v<_Tp>
  struct iterator_traits<_Tp *>;

  template <typename _Iterator, typename> struct __iterator_traits;

  namespace __detail {
  template <typename _Tp> using __with_ref = _Tp &;

  template <typename _Tp>
  concept __can_reference = requires { typename __with_ref<_Tp>; };

  template <typename _Tp>
  concept __dereferenceable = requires(_Tp &__t) {
    { *__t } -> __can_reference;
  };
  } // namespace __detail

  template <__detail::__dereferenceable _Tp>
  using iter_reference_t = decltype(*std::declval<_Tp &>());

  namespace ranges {

  namespace __imove {
  void iter_move() = delete;

  template <typename _Tp>
  concept __adl_imove =
      (std::__detail::__class_or_enum<remove_reference_t<_Tp>>) &&
      requires(_Tp &&__t) { iter_move(static_cast<_Tp &&>(__t)); };

  struct _IterMove {
  private:
    template <typename _Tp> struct __result {
      using type = iter_reference_t<_Tp>;
    };

    template <typename _Tp>
      requires __adl_imove<_Tp>
    struct __result<_Tp> {
      using type = decltype(iter_move(std::declval<_Tp>()));
    };

    template <typename _Tp>
      requires(!__adl_imove<_Tp>) &&
              is_lvalue_reference_v<iter_reference_t<_Tp>>
    struct __result<_Tp> {
      using type = remove_reference_t<iter_reference_t<_Tp>> &&;
    };

    template <typename _Tp> static constexpr bool _S_noexcept() {
      if constexpr (__adl_imove<_Tp>)
        return noexcept(iter_move(std::declval<_Tp>()));
      else
        return noexcept(*std::declval<_Tp>());
    }

  public:
    template <std::__detail::__dereferenceable _Tp>
    using __type = typename __result<_Tp>::type;

    template <std::__detail::__dereferenceable _Tp>
    [[nodiscard]]
    constexpr __type<_Tp> operator()(_Tp &&__e) const
        noexcept(_S_noexcept<_Tp>()) {
      if constexpr (__adl_imove<_Tp>)
        return iter_move(static_cast<_Tp &&>(__e));
      else if constexpr (is_lvalue_reference_v<iter_reference_t<_Tp>>)
        return static_cast<__type<_Tp>>(*__e);
      else
        return *__e;
    }
  };
  } // namespace __imove

  inline namespace _Cpo {
  inline constexpr __imove::_IterMove iter_move{};
  }
  } // namespace ranges

  template <__detail::__dereferenceable _Tp>
    requires __detail::__can_reference<
                 ranges::__imove::_IterMove::__type<_Tp &>>
  using iter_rvalue_reference_t = ranges::__imove::_IterMove::__type<_Tp &>;

  template <typename> struct incrementable_traits {};

  template <typename _Tp>
    requires is_object_v<_Tp>
  struct incrementable_traits<_Tp *> {
    using difference_type = ptrdiff_t;
  };

  template <typename _Iter>
  struct incrementable_traits<const _Iter> : incrementable_traits<_Iter> {};

  template <typename _Tp>
    requires requires { typename _Tp::difference_type; }
  struct incrementable_traits<_Tp> {
    using difference_type = typename _Tp::difference_type;
  };

  template <typename _Tp>
    requires(
        !requires { typename _Tp::difference_type; } &&
        requires(const _Tp &__a, const _Tp &__b) {
          { __a - __b } -> integral;
        })
  struct incrementable_traits<_Tp> {
    using difference_type =
        make_signed_t<decltype(std::declval<_Tp>() - std::declval<_Tp>())>;
  };
  namespace __detail {

  template <typename _Iter>
  concept __primary_traits_iter =
      __is_base_of(__iterator_traits<_Iter, void>, iterator_traits<_Iter>);

  template <typename _Iter, typename _Tp> struct __iter_traits_impl {
    using type = iterator_traits<_Iter>;
  };

  template <typename _Iter, typename _Tp>
    requires __primary_traits_iter<_Iter>
  struct __iter_traits_impl<_Iter, _Tp> {
    using type = _Tp;
  };

  template <typename _Iter, typename _Tp = _Iter>
  using __iter_traits = typename __iter_traits_impl<_Iter, _Tp>::type;

  template <typename _Tp>
  using __iter_diff_t =
      typename __iter_traits<_Tp, incrementable_traits<_Tp>>::difference_type;
  } // namespace __detail

  template <typename _Tp>
  using iter_difference_t = __detail::__iter_diff_t<remove_cvref_t<_Tp>>;

  namespace __detail {
  template <typename> struct __cond_value_type {};

  template <typename _Tp>
    requires is_object_v<_Tp>
  struct __cond_value_type<_Tp> {
    using value_type = remove_cv_t<_Tp>;
  };

  template <typename _Tp>
  concept __has_member_value_type = requires { typename _Tp::value_type; };

  template <typename _Tp>
  concept __has_member_element_type = requires { typename _Tp::element_type; };

  } // namespace __detail

  template <typename> struct indirectly_readable_traits {};

  template <typename _Tp>
  struct indirectly_readable_traits<_Tp *> : __detail::__cond_value_type<_Tp> {
  };

  template <typename _Iter>
    requires is_array_v<_Iter>
  struct indirectly_readable_traits<_Iter> {
    using value_type = remove_cv_t<remove_extent_t<_Iter>>;
  };

  template <typename _Iter>
  struct indirectly_readable_traits<const _Iter>
      : indirectly_readable_traits<_Iter> {};

  template <__detail::__has_member_value_type _Tp>
  struct indirectly_readable_traits<_Tp>
      : __detail::__cond_value_type<typename _Tp::value_type> {};

  template <__detail::__has_member_element_type _Tp>
  struct indirectly_readable_traits<_Tp>
      : __detail::__cond_value_type<typename _Tp::element_type> {};

  template <__detail::__has_member_value_type _Tp>
    requires __detail::__has_member_element_type<_Tp> &&
             same_as<remove_cv_t<typename _Tp::element_type>,
                     remove_cv_t<typename _Tp::value_type>>
  struct indirectly_readable_traits<_Tp>
      : __detail::__cond_value_type<typename _Tp::value_type> {};

  template <__detail::__has_member_value_type _Tp>
    requires __detail::__has_member_element_type<_Tp>
  struct indirectly_readable_traits<_Tp> {};

  namespace __detail {
  template <typename _Tp>
  using __iter_value_t =
      typename __iter_traits<_Tp, indirectly_readable_traits<_Tp>>::value_type;
  }

  template <typename _Tp>
  using iter_value_t = __detail::__iter_value_t<remove_cvref_t<_Tp>>;

  namespace __detail {

  template <typename _Iter>
  concept __cpp17_iterator = requires(_Iter __it) {
    { *__it } -> __can_reference;
    { ++__it } -> same_as<_Iter &>;
    { *__it++ } -> __can_reference;
  } && copyable<_Iter>;

  template <typename _Iter>
  concept __cpp17_input_iterator =
      __cpp17_iterator<_Iter> && equality_comparable<_Iter> &&
      requires(_Iter __it) {
        typename incrementable_traits<_Iter>::difference_type;
        typename indirectly_readable_traits<_Iter>::value_type;
        typename common_reference_t<
            iter_reference_t<_Iter> &&,
            typename indirectly_readable_traits<_Iter>::value_type &>;
        typename common_reference_t<
            decltype(*__it++) &&,
            typename indirectly_readable_traits<_Iter>::value_type &>;
        requires signed_integral<
            typename incrementable_traits<_Iter>::difference_type>;
      };

  template <typename _Iter>
  concept __cpp17_fwd_iterator =
      __cpp17_input_iterator<_Iter> && constructible_from<_Iter> &&
      is_lvalue_reference_v<iter_reference_t<_Iter>> &&
      same_as<remove_cvref_t<iter_reference_t<_Iter>>,
              typename indirectly_readable_traits<_Iter>::value_type> &&
      requires(_Iter __it) {
        { __it++ } -> convertible_to<const _Iter &>;
        { *__it++ } -> same_as<iter_reference_t<_Iter>>;
      };

  template <typename _Iter>
  concept __cpp17_bidi_iterator =
      __cpp17_fwd_iterator<_Iter> && requires(_Iter __it) {
        { --__it } -> same_as<_Iter &>;
        { __it-- } -> convertible_to<const _Iter &>;
        { *__it-- } -> same_as<iter_reference_t<_Iter>>;
      };

  template <typename _Iter>
  concept __cpp17_randacc_iterator =
      __cpp17_bidi_iterator<_Iter> && totally_ordered<_Iter> &&
      requires(_Iter __it,
               typename incrementable_traits<_Iter>::difference_type __n) {
        { __it += __n } -> same_as<_Iter &>;
        { __it -= __n } -> same_as<_Iter &>;
        { __it + __n } -> same_as<_Iter>;
        { __n + __it } -> same_as<_Iter>;
        { __it - __n } -> same_as<_Iter>;
        { __it - __it } -> same_as<decltype(__n)>;
        { __it[__n] } -> convertible_to<iter_reference_t<_Iter>>;
      };

  template <typename _Iter>
  concept __iter_with_nested_types = requires {
    typename _Iter::iterator_category;
    typename _Iter::value_type;
    typename _Iter::difference_type;
    typename _Iter::reference;
  };

  template <typename _Iter>
  concept __iter_without_nested_types = !__iter_with_nested_types<_Iter>;

  template <typename _Iter>
  concept __iter_without_category =
      !requires { typename _Iter::iterator_category; };

  } // namespace __detail

  template <typename _Iterator>
    requires __detail::__iter_with_nested_types<_Iterator>
  struct __iterator_traits<_Iterator, void> {
  private:
    template <typename _Iter> struct __ptr {
      using type = void;
    };

    template <typename _Iter>
      requires requires { typename _Iter::pointer; }
    struct __ptr<_Iter> {
      using type = typename _Iter::pointer;
    };

  public:
    using iterator_category = typename _Iterator::iterator_category;
    using value_type = typename _Iterator::value_type;
    using difference_type = typename _Iterator::difference_type;
    using pointer = typename __ptr<_Iterator>::type;
    using reference = typename _Iterator::reference;
  };

  template <typename _Iterator>
    requires __detail::__iter_without_nested_types<_Iterator> &&
             __detail::__cpp17_input_iterator<_Iterator>
  struct __iterator_traits<_Iterator, void> {
  private:
    template <typename _Iter> struct __cat {
      using type = input_iterator_tag;
    };

    template <typename _Iter>
      requires requires { typename _Iter::iterator_category; }
    struct __cat<_Iter> {
      using type = typename _Iter::iterator_category;
    };

    template <typename _Iter>
      requires __detail::__iter_without_category<_Iter> &&
               __detail::__cpp17_randacc_iterator<_Iter>
    struct __cat<_Iter> {
      using type = random_access_iterator_tag;
    };

    template <typename _Iter>
      requires __detail::__iter_without_category<_Iter> &&
               __detail::__cpp17_bidi_iterator<_Iter>
    struct __cat<_Iter> {
      using type = bidirectional_iterator_tag;
    };

    template <typename _Iter>
      requires __detail::__iter_without_category<_Iter> &&
               __detail::__cpp17_fwd_iterator<_Iter>
    struct __cat<_Iter> {
      using type = forward_iterator_tag;
    };

    template <typename _Iter> struct __ptr {
      using type = void;
    };

    template <typename _Iter>
      requires requires { typename _Iter::pointer; }
    struct __ptr<_Iter> {
      using type = typename _Iter::pointer;
    };

    template <typename _Iter>
      requires(
          !requires { typename _Iter::pointer; } &&
          requires(_Iter &__it) { __it.operator->(); })
    struct __ptr<_Iter> {
      using type = decltype(std::declval<_Iter &>().operator->());
    };

    template <typename _Iter> struct __ref {
      using type = iter_reference_t<_Iter>;
    };

    template <typename _Iter>
      requires requires { typename _Iter::reference; }
    struct __ref<_Iter> {
      using type = typename _Iter::reference;
    };

  public:
    using iterator_category = typename __cat<_Iterator>::type;
    using value_type =
        typename indirectly_readable_traits<_Iterator>::value_type;
    using difference_type =
        typename incrementable_traits<_Iterator>::difference_type;
    using pointer = typename __ptr<_Iterator>::type;
    using reference = typename __ref<_Iterator>::type;
  };

  template <typename _Iterator>
    requires __detail::__iter_without_nested_types<_Iterator> &&
             __detail::__cpp17_iterator<_Iterator>
  struct __iterator_traits<_Iterator, void> {
  private:
    template <typename _Iter> struct __diff {
      using type = void;
    };

    template <typename _Iter>
      requires requires {
        typename incrementable_traits<_Iter>::difference_type;
      }
    struct __diff<_Iter> {
      using type = typename incrementable_traits<_Iter>::difference_type;
    };

  public:
    using iterator_category = output_iterator_tag;
    using value_type = void;
    using difference_type = typename __diff<_Iterator>::type;
    using pointer = void;
    using reference = void;
  };

  namespace __detail {
  template <typename _Iter> struct __iter_concept_impl;

  template <typename _Iter>
    requires requires { typename __iter_traits<_Iter>::iterator_concept; }
  struct __iter_concept_impl<_Iter> {
    using type = typename __iter_traits<_Iter>::iterator_concept;
  };

  template <typename _Iter>
    requires(
        !requires { typename __iter_traits<_Iter>::iterator_concept; } &&
        requires { typename __iter_traits<_Iter>::iterator_category; })
  struct __iter_concept_impl<_Iter> {
    using type = typename __iter_traits<_Iter>::iterator_category;
  };

  template <typename _Iter>
    requires(
        !requires { typename __iter_traits<_Iter>::iterator_concept; } &&
        !requires { typename __iter_traits<_Iter>::iterator_category; } &&
        __primary_traits_iter<_Iter>)
  struct __iter_concept_impl<_Iter> {
    using type = random_access_iterator_tag;
  };

  template <typename _Iter> struct __iter_concept_impl {};

  template <typename _Iter>
  using __iter_concept = typename __iter_concept_impl<_Iter>::type;

  template <typename _In>
  concept __indirectly_readable_impl =
      requires {
        typename iter_value_t<_In>;
        typename iter_reference_t<_In>;
        typename iter_rvalue_reference_t<_In>;
        requires same_as<iter_reference_t<const _In>, iter_reference_t<_In>>;
        requires same_as<iter_rvalue_reference_t<const _In>,
                         iter_rvalue_reference_t<_In>>;
      } &&
      common_reference_with<iter_reference_t<_In> &&, iter_value_t<_In> &> &&
      common_reference_with<iter_reference_t<_In> &&,
                            iter_rvalue_reference_t<_In> &&> &&
      common_reference_with<iter_rvalue_reference_t<_In> &&,
                            const iter_value_t<_In> &>;

  } // namespace __detail

  template <typename _In>
  concept indirectly_readable =
      __detail::__indirectly_readable_impl<remove_cvref_t<_In>>;

  namespace __detail {
  template <typename _Tp> struct __indirect_value {
    using type = iter_value_t<_Tp> &;
  };

  } // namespace __detail

  template <typename _Tp>
  using __indirect_value_t = typename __detail::__indirect_value<_Tp>::type;

  template <indirectly_readable _Tp>
  using iter_common_reference_t =
      common_reference_t<iter_reference_t<_Tp>, __indirect_value_t<_Tp>>;

  template <typename _Out, typename _Tp>
  concept indirectly_writable = requires(_Out &&__o, _Tp &&__t) {
    *__o = std::forward<_Tp>(__t);
    *std::forward<_Out>(__o) = std::forward<_Tp>(__t);
    const_cast<const iter_reference_t<_Out> &&>(*__o) = std::forward<_Tp>(__t);
    const_cast<const iter_reference_t<_Out> &&>(*std::forward<_Out>(__o)) =
        std::forward<_Tp>(__t);
  };

  namespace ranges::__detail {
  class __max_diff_type;
  class __max_size_type;

  __extension__ template <typename _Tp>
  concept __is_signed_int128

      = same_as<_Tp, __int128>;

  __extension__ template <typename _Tp>
  concept __is_unsigned_int128

      = same_as<_Tp, unsigned __int128>;

  template <typename _Tp>
  concept __cv_bool = same_as<const volatile _Tp, const volatile bool>;

  template <typename _Tp>
  concept __integral_nonbool = integral<_Tp> && !__cv_bool<_Tp>;

  template <typename _Tp>
  concept __is_int128 = __is_signed_int128<_Tp> || __is_unsigned_int128<_Tp>;

  template <typename _Tp>
  concept __is_integer_like =
      __integral_nonbool<_Tp> || __is_int128<_Tp> ||
      same_as<_Tp, __max_diff_type> || same_as<_Tp, __max_size_type>;

  template <typename _Tp>
  concept __is_signed_integer_like =
      signed_integral<_Tp> || __is_signed_int128<_Tp> ||
      same_as<_Tp, __max_diff_type>;

  } // namespace ranges::__detail

  namespace __detail {
  using ranges::__detail::__is_signed_integer_like;
  }

  template <typename _Iter>
  concept weakly_incrementable = movable<_Iter> && requires(_Iter __i) {
    typename iter_difference_t<_Iter>;
    requires __detail::__is_signed_integer_like<iter_difference_t<_Iter>>;
    { ++__i } -> same_as<_Iter &>;
    __i++;
  };

  template <typename _Iter>
  concept incrementable =
      regular<_Iter> && weakly_incrementable<_Iter> && requires(_Iter __i) {
        { __i++ } -> same_as<_Iter>;
      };

  template <typename _Iter>
  concept input_or_output_iterator = requires(_Iter __i) {
    { *__i } -> __detail::__can_reference;
  } && weakly_incrementable<_Iter>;

  template <typename _Sent, typename _Iter>
  concept sentinel_for =
      semiregular<_Sent> && input_or_output_iterator<_Iter> &&
      __detail::__weakly_eq_cmp_with<_Sent, _Iter>;

  template <typename _Sent, typename _Iter>
  inline constexpr bool disable_sized_sentinel_for = false;

  template <typename _Sent, typename _Iter>
  concept sized_sentinel_for =
      sentinel_for<_Sent, _Iter> &&
      !disable_sized_sentinel_for<remove_cv_t<_Sent>, remove_cv_t<_Iter>> &&
      requires(const _Iter &__i, const _Sent &__s) {
        { __s - __i } -> same_as<iter_difference_t<_Iter>>;
        { __i - __s } -> same_as<iter_difference_t<_Iter>>;
      };

  template <typename _Iter>
  concept input_iterator =
      input_or_output_iterator<_Iter> && indirectly_readable<_Iter> &&
      requires { typename __detail::__iter_concept<_Iter>; } &&
      derived_from<__detail::__iter_concept<_Iter>, input_iterator_tag>;

  template <typename _Iter, typename _Tp>
  concept output_iterator =
      input_or_output_iterator<_Iter> && indirectly_writable<_Iter, _Tp> &&
      requires(_Iter __i, _Tp &&__t) { *__i++ = std::forward<_Tp>(__t); };

  template <typename _Iter>
  concept forward_iterator =
      input_iterator<_Iter> &&
      derived_from<__detail::__iter_concept<_Iter>, forward_iterator_tag> &&
      incrementable<_Iter> && sentinel_for<_Iter, _Iter>;

  template <typename _Iter>
  concept bidirectional_iterator = forward_iterator<_Iter> &&
                                   derived_from<__detail::__iter_concept<_Iter>,
                                                bidirectional_iterator_tag> &&
                                   requires(_Iter __i) {
                                     { --__i } -> same_as<_Iter &>;
                                     { __i-- } -> same_as<_Iter>;
                                   };

  template <typename _Iter>
  concept random_access_iterator =
      bidirectional_iterator<_Iter> &&
      derived_from<__detail::__iter_concept<_Iter>,
                   random_access_iterator_tag> &&
      totally_ordered<_Iter> && sized_sentinel_for<_Iter, _Iter> &&
      requires(_Iter __i, const _Iter __j, const iter_difference_t<_Iter> __n) {
        { __i += __n } -> same_as<_Iter &>;
        { __j + __n } -> same_as<_Iter>;
        { __n + __j } -> same_as<_Iter>;
        { __i -= __n } -> same_as<_Iter &>;
        { __j - __n } -> same_as<_Iter>;
        { __j[__n] } -> same_as<iter_reference_t<_Iter>>;
      };

  template <typename _Iter>
  concept contiguous_iterator =
      random_access_iterator<_Iter> &&
      derived_from<__detail::__iter_concept<_Iter>, contiguous_iterator_tag> &&
      is_lvalue_reference_v<iter_reference_t<_Iter>> &&
      same_as<iter_value_t<_Iter>, remove_cvref_t<iter_reference_t<_Iter>>> &&
      requires(const _Iter &__i) {
        {
          std::to_address(__i)
        } -> same_as<add_pointer_t<iter_reference_t<_Iter>>>;
      };

  template <typename _Fn, typename _Iter>
  concept indirectly_unary_invocable =
      indirectly_readable<_Iter> && copy_constructible<_Fn> &&
      invocable<_Fn &, __indirect_value_t<_Iter>> &&
      invocable<_Fn &, iter_reference_t<_Iter>> &&
      common_reference_with<invoke_result_t<_Fn &, __indirect_value_t<_Iter>>,
                            invoke_result_t<_Fn &, iter_reference_t<_Iter>>>;

  template <typename _Fn, typename _Iter>
  concept indirectly_regular_unary_invocable =
      indirectly_readable<_Iter> && copy_constructible<_Fn> &&
      regular_invocable<_Fn &, __indirect_value_t<_Iter>> &&
      regular_invocable<_Fn &, iter_reference_t<_Iter>> &&
      common_reference_with<invoke_result_t<_Fn &, __indirect_value_t<_Iter>>,
                            invoke_result_t<_Fn &, iter_reference_t<_Iter>>>;

  template <typename _Fn, typename _Iter>
  concept indirect_unary_predicate =
      indirectly_readable<_Iter> && copy_constructible<_Fn> &&
      predicate<_Fn &, __indirect_value_t<_Iter>> &&
      predicate<_Fn &, iter_reference_t<_Iter>>;

  template <typename _Fn, typename _I1, typename _I2>
  concept indirect_binary_predicate =
      indirectly_readable<_I1> && indirectly_readable<_I2> &&
      copy_constructible<_Fn> &&
      predicate<_Fn &, __indirect_value_t<_I1>, __indirect_value_t<_I2>> &&
      predicate<_Fn &, __indirect_value_t<_I1>, iter_reference_t<_I2>> &&
      predicate<_Fn &, iter_reference_t<_I1>, __indirect_value_t<_I2>> &&
      predicate<_Fn &, iter_reference_t<_I1>, iter_reference_t<_I2>>;

  template <typename _Fn, typename _I1, typename _I2 = _I1>
  concept indirect_equivalence_relation =
      indirectly_readable<_I1> && indirectly_readable<_I2> &&
      copy_constructible<_Fn> &&
      equivalence_relation<_Fn &, __indirect_value_t<_I1>,
                           __indirect_value_t<_I2>> &&
      equivalence_relation<_Fn &, __indirect_value_t<_I1>,
                           iter_reference_t<_I2>> &&
      equivalence_relation<_Fn &, iter_reference_t<_I1>,
                           __indirect_value_t<_I2>> &&
      equivalence_relation<_Fn &, iter_reference_t<_I1>, iter_reference_t<_I2>>;

  template <typename _Fn, typename _I1, typename _I2 = _I1>
  concept indirect_strict_weak_order =
      indirectly_readable<_I1> && indirectly_readable<_I2> &&
      copy_constructible<_Fn> &&
      strict_weak_order<_Fn &, __indirect_value_t<_I1>,
                        __indirect_value_t<_I2>> &&
      strict_weak_order<_Fn &, __indirect_value_t<_I1>,
                        iter_reference_t<_I2>> &&
      strict_weak_order<_Fn &, iter_reference_t<_I1>,
                        __indirect_value_t<_I2>> &&
      strict_weak_order<_Fn &, iter_reference_t<_I1>, iter_reference_t<_I2>>;

  template <typename _Fn, typename... _Is>
    requires(indirectly_readable<_Is> && ...) &&
                invocable<_Fn, iter_reference_t<_Is>...>
  using indirect_result_t = invoke_result_t<_Fn, iter_reference_t<_Is>...>;

  namespace __detail {
  template <typename _Iter, typename _Proj> struct __projected {
    struct __type {
      using value_type = remove_cvref_t<indirect_result_t<_Proj &, _Iter>>;
      indirect_result_t<_Proj &, _Iter> operator*() const;

      using __projected_Iter = _Iter;
      using __projected_Proj = _Proj;
    };
  };

  template <weakly_incrementable _Iter, typename _Proj>
  struct __projected<_Iter, _Proj> {
    struct __type {
      using value_type = remove_cvref_t<indirect_result_t<_Proj &, _Iter>>;
      using difference_type = iter_difference_t<_Iter>;
      indirect_result_t<_Proj &, _Iter> operator*() const;

      using __projected_Iter = _Iter;
      using __projected_Proj = _Proj;
    };
  };
  } // namespace __detail

  template <indirectly_readable _Iter,
            indirectly_regular_unary_invocable<_Iter> _Proj>
  using projected = typename __detail::__projected<_Iter, _Proj>::__type;

  template <typename _Tp>
    requires same_as<_Tp, projected<typename _Tp::__projected_Iter,
                                    typename _Tp::__projected_Proj>>
  struct __detail::__indirect_value<_Tp> {
    using _Iter = typename _Tp::__projected_Iter;
    using _Proj = typename _Tp::__projected_Proj;
    using type = invoke_result_t<_Proj &, __indirect_value_t<_Iter>>;
  };

  template <typename _In, typename _Out>
  concept indirectly_movable =
      indirectly_readable<_In> &&
      indirectly_writable<_Out, iter_rvalue_reference_t<_In>>;

  template <typename _In, typename _Out>
  concept indirectly_movable_storable =
      indirectly_movable<_In, _Out> &&
      indirectly_writable<_Out, iter_value_t<_In>> &&
      movable<iter_value_t<_In>> &&
      constructible_from<iter_value_t<_In>, iter_rvalue_reference_t<_In>> &&
      assignable_from<iter_value_t<_In> &, iter_rvalue_reference_t<_In>>;

  template <typename _In, typename _Out>
  concept indirectly_copyable =
      indirectly_readable<_In> &&
      indirectly_writable<_Out, iter_reference_t<_In>>;

  template <typename _In, typename _Out>
  concept indirectly_copyable_storable =
      indirectly_copyable<_In, _Out> &&
      indirectly_writable<_Out, iter_value_t<_In> &> &&
      indirectly_writable<_Out, const iter_value_t<_In> &> &&
      indirectly_writable<_Out, iter_value_t<_In> &&> &&
      indirectly_writable<_Out, const iter_value_t<_In> &&> &&
      copyable<iter_value_t<_In>> &&
      constructible_from<iter_value_t<_In>, iter_reference_t<_In>> &&
      assignable_from<iter_value_t<_In> &, iter_reference_t<_In>>;

  namespace ranges {

  namespace __iswap {
  template <typename _It1, typename _It2> void iter_swap(_It1, _It2) = delete;

  template <typename _Tp, typename _Up>
  concept __adl_iswap =
      (std::__detail::__class_or_enum<remove_reference_t<_Tp>> ||
       std::__detail::__class_or_enum<remove_reference_t<_Up>>) &&
      requires(_Tp &&__t, _Up &&__u) {
        iter_swap(static_cast<_Tp &&>(__t), static_cast<_Up &&>(__u));
      };

  template <typename _Xp, typename _Yp>
  constexpr iter_value_t<_Xp> __iter_exchange_move(
      _Xp &&__x,
      _Yp &&__y) noexcept(noexcept(iter_value_t<_Xp>(iter_move(__x))) &&
                          noexcept(*__x = iter_move(__y))) {
    iter_value_t<_Xp> __old_value(iter_move(__x));
    *__x = iter_move(__y);
    return __old_value;
  }

  struct _IterSwap {
  private:
    template <typename _Tp, typename _Up> static constexpr bool _S_noexcept() {
      if constexpr (__adl_iswap<_Tp, _Up>)
        return noexcept(iter_swap(std::declval<_Tp>(), std::declval<_Up>()));
      else if constexpr (indirectly_readable<_Tp> && indirectly_readable<_Up> &&
                         swappable_with<iter_reference_t<_Tp>,
                                        iter_reference_t<_Up>>)
        return noexcept(
            ranges::swap(*std::declval<_Tp>(), *std::declval<_Up>()));
      else
        return noexcept(*std::declval<_Tp>() = __iswap::__iter_exchange_move(
                            std::declval<_Up>(), std::declval<_Tp>()));
    }

  public:
    template <typename _Tp, typename _Up>
      requires __adl_iswap<_Tp, _Up> ||
               (indirectly_readable<remove_reference_t<_Tp>> &&
                indirectly_readable<remove_reference_t<_Up>> &&
                swappable_with<iter_reference_t<_Tp>, iter_reference_t<_Up>>) ||
               (indirectly_movable_storable<_Tp, _Up> &&
                indirectly_movable_storable<_Up, _Tp>)
    constexpr void operator()(_Tp &&__e1, _Up &&__e2) const
        noexcept(_S_noexcept<_Tp, _Up>()) {
      if constexpr (__adl_iswap<_Tp, _Up>)
        iter_swap(static_cast<_Tp &&>(__e1), static_cast<_Up &&>(__e2));
      else if constexpr (indirectly_readable<_Tp> && indirectly_readable<_Up> &&
                         swappable_with<iter_reference_t<_Tp>,
                                        iter_reference_t<_Up>>)
        ranges::swap(*__e1, *__e2);
      else
        *__e1 = __iswap::__iter_exchange_move(__e2, __e1);
    }
  };
  } // namespace __iswap

  inline namespace _Cpo {
  inline constexpr __iswap::_IterSwap iter_swap{};
  }

  } // namespace ranges

  template <typename _I1, typename _I2 = _I1>
  concept indirectly_swappable =
      indirectly_readable<_I1> && indirectly_readable<_I2> &&
      requires(const _I1 __i1, const _I2 __i2) {
        ranges::iter_swap(__i1, __i1);
        ranges::iter_swap(__i2, __i2);
        ranges::iter_swap(__i1, __i2);
        ranges::iter_swap(__i2, __i1);
      };

  template <typename _I1, typename _I2, typename _Rel, typename _P1 = identity,
            typename _P2 = identity>
  concept indirectly_comparable =
      indirect_binary_predicate<_Rel, projected<_I1, _P1>, projected<_I2, _P2>>;

  template <typename _Iter>
  concept permutable =
      forward_iterator<_Iter> && indirectly_movable_storable<_Iter, _Iter> &&
      indirectly_swappable<_Iter, _Iter>;

  template <typename _I1, typename _I2, typename _Out,
            typename _Rel = ranges::less, typename _P1 = identity,
            typename _P2 = identity>
  concept mergeable =
      input_iterator<_I1> && input_iterator<_I2> &&
      weakly_incrementable<_Out> && indirectly_copyable<_I1, _Out> &&
      indirectly_copyable<_I2, _Out> &&
      indirect_strict_weak_order<_Rel, projected<_I1, _P1>,
                                 projected<_I2, _P2>>;

  template <typename _Iter, typename _Rel = ranges::less,
            typename _Proj = identity>
  concept sortable = permutable<_Iter> &&
                     indirect_strict_weak_order<_Rel, projected<_Iter, _Proj>>;

  struct unreachable_sentinel_t {
    template <weakly_incrementable _It>
    friend constexpr bool operator==(unreachable_sentinel_t,
                                     const _It &) noexcept {
      return false;
    }
  };

  inline constexpr unreachable_sentinel_t unreachable_sentinel{};

  namespace ranges::__access {
  using std::__detail::__class_or_enum;

  struct _Decay_copy final {
    template <typename _Tp>
    constexpr decay_t<_Tp> operator()(_Tp &&__t) const
        noexcept(is_nothrow_convertible_v<_Tp, decay_t<_Tp>>) {
      return std::forward<_Tp>(__t);
    }
  } inline constexpr __decay_copy{};

  template <typename _Tp>
  concept __member_begin = requires(_Tp &__t) {
    { __decay_copy(__t.begin()) } -> input_or_output_iterator;
  };

  void begin() = delete;

  template <typename _Tp>
  concept __adl_begin =
      __class_or_enum<remove_reference_t<_Tp>> && requires(_Tp &__t) {
        { __decay_copy(begin(__t)) } -> input_or_output_iterator;
      };

  template <typename _Tp>
    requires is_array_v<_Tp> || __member_begin<_Tp &> || __adl_begin<_Tp &>
  auto __begin(_Tp &__t) {
    if constexpr (is_array_v<_Tp>)
      return __t + 0;
    else if constexpr (__member_begin<_Tp &>)
      return __t.begin();
    else
      return begin(__t);
  }
  } // namespace ranges::__access

  namespace __detail {

  template <typename _Tp>
  using __range_iter_t =
      decltype(ranges::__access::__begin(std::declval<_Tp &>()));

  }

} // namespace std

namespace std __attribute__((__visibility__("default"))) {

  struct input_iterator_tag {};

  struct output_iterator_tag {};

  struct forward_iterator_tag : public input_iterator_tag {};

  struct bidirectional_iterator_tag : public forward_iterator_tag {};

  struct random_access_iterator_tag : public bidirectional_iterator_tag {};

  struct contiguous_iterator_tag : public random_access_iterator_tag {};
  template <typename _Category, typename _Tp, typename _Distance = ptrdiff_t,
            typename _Pointer = _Tp *, typename _Reference = _Tp &>
  struct [[__deprecated__]] iterator {

    typedef _Category iterator_category;

    typedef _Tp value_type;

    typedef _Distance difference_type;

    typedef _Pointer pointer;

    typedef _Reference reference;
  };
  template <typename _Iterator> struct iterator_traits;

  template <typename _Iterator, typename = __void_t<>>
  struct __iterator_traits {};
  template <typename _Iterator>
  struct iterator_traits : public __iterator_traits<_Iterator> {};
  template <typename _Tp>

    requires is_object_v<_Tp>

  struct iterator_traits<_Tp *> {
    using iterator_concept = contiguous_iterator_tag;
    using iterator_category = random_access_iterator_tag;
    using value_type = remove_cv_t<_Tp>;
    using difference_type = ptrdiff_t;
    using pointer = _Tp *;
    using reference = _Tp &;
  };
  template <typename _Iter>
  __attribute__((__always_inline__)) inline constexpr
      typename iterator_traits<_Iter>::iterator_category
      __iterator_category(const _Iter &) {
    return typename iterator_traits<_Iter>::iterator_category();
  }

  template <typename _Iter>
  using __iter_category_t = typename iterator_traits<_Iter>::iterator_category;

  template <typename _InIter>
  using _RequireInputIter = __enable_if_t<
      is_convertible<__iter_category_t<_InIter>, input_iterator_tag>::value>;

  template <typename _It, typename _Cat = __iter_category_t<_It>>
  struct __is_random_access_iter
      : is_base_of<random_access_iterator_tag, _Cat> {
    typedef is_base_of<random_access_iterator_tag, _Cat> _Base;
    enum { __value = _Base::value };
  };

} // namespace std

extern "C++" {

namespace __gnu_cxx __attribute__((__visibility__("default"))) {

  template <bool, typename> struct __enable_if {};

  template <typename _Tp> struct __enable_if<true, _Tp> {
    typedef _Tp __type;
  };

  template <bool _Cond, typename _Iftrue, typename _Iffalse>
  struct __conditional_type {
    typedef _Iftrue __type;
  };

  template <typename _Iftrue, typename _Iffalse>
  struct __conditional_type<false, _Iftrue, _Iffalse> {
    typedef _Iffalse __type;
  };

  template <typename _Tp> struct __add_unsigned {
  private:
    typedef __enable_if<std::__is_integer<_Tp>::__value, _Tp> __if_type;

  public:
    typedef typename __if_type::__type __type;
  };

  template <> struct __add_unsigned<char> {
    typedef unsigned char __type;
  };

  template <> struct __add_unsigned<signed char> {
    typedef unsigned char __type;
  };

  template <> struct __add_unsigned<short> {
    typedef unsigned short __type;
  };

  template <> struct __add_unsigned<int> {
    typedef unsigned int __type;
  };

  template <> struct __add_unsigned<long> {
    typedef unsigned long __type;
  };

  template <> struct __add_unsigned<long long> {
    typedef unsigned long long __type;
  };

  template <> struct __add_unsigned<bool>;

  template <> struct __add_unsigned<wchar_t>;

  template <typename _Tp> struct __remove_unsigned {
  private:
    typedef __enable_if<std::__is_integer<_Tp>::__value, _Tp> __if_type;

  public:
    typedef typename __if_type::__type __type;
  };

  template <> struct __remove_unsigned<char> {
    typedef signed char __type;
  };

  template <> struct __remove_unsigned<unsigned char> {
    typedef signed char __type;
  };

  template <> struct __remove_unsigned<unsigned short> {
    typedef short __type;
  };

  template <> struct __remove_unsigned<unsigned int> {
    typedef int __type;
  };

  template <> struct __remove_unsigned<unsigned long> {
    typedef long __type;
  };

  template <> struct __remove_unsigned<unsigned long long> {
    typedef long long __type;
  };

  template <> struct __remove_unsigned<bool>;

  template <> struct __remove_unsigned<wchar_t>;

  template <typename _Type>
  constexpr inline bool __is_null_pointer(_Type * __ptr) {
    return __ptr == 0;
  }

  template <typename _Type> constexpr inline bool __is_null_pointer(_Type) {
    return false;
  }

  constexpr bool __is_null_pointer(std::nullptr_t) { return true; }

  template <typename _Tp, bool = std::__is_integer<_Tp>::__value>
  struct __promote {
    typedef double __type;
  };

  template <typename _Tp> struct __promote<_Tp, false> {};

  template <> struct __promote<long double> {
    typedef long double __type;
  };

  template <> struct __promote<double> {
    typedef double __type;
  };

  template <> struct __promote<float> {
    typedef float __type;
  };
  template <typename... _Tp>
  using __promoted_t = decltype((typename __promote<_Tp>::__type(0) + ...));

  template <typename _Tp, typename _Up>
  using __promote_2 = __promote<__promoted_t<_Tp, _Up>>;

  template <typename _Tp, typename _Up, typename _Vp>
  using __promote_3 = __promote<__promoted_t<_Tp, _Up, _Vp>>;

  template <typename _Tp, typename _Up, typename _Vp, typename _Wp>
  using __promote_4 = __promote<__promoted_t<_Tp, _Up, _Vp, _Wp>>;

} // namespace __gnu_cxx
}

extern "C++" {

namespace std __attribute__((__visibility__("default"))) {
  class exception {
  public:
    exception() noexcept {}
    virtual ~exception() noexcept;

    exception(const exception &) = default;
    exception &operator=(const exception &) = default;
    exception(exception &&) = default;
    exception &operator=(exception &&) = default;

    virtual const char *what() const noexcept;
  };

} // namespace std
}

extern "C++" {

namespace std {

class bad_alloc : public exception {
public:
  bad_alloc() throw() {}

  bad_alloc(const bad_alloc &) = default;
  bad_alloc &operator=(const bad_alloc &) = default;

  virtual ~bad_alloc() throw();

  virtual const char *what() const throw();
};

class bad_array_new_length : public bad_alloc {
public:
  bad_array_new_length() throw() {}

  virtual ~bad_array_new_length() throw();

  virtual const char *what() const throw();
};

enum class align_val_t : size_t {};

struct nothrow_t {

  explicit nothrow_t() = default;
};

extern const nothrow_t nothrow;

typedef void (*new_handler)();

new_handler set_new_handler(new_handler) throw();

new_handler get_new_handler() noexcept;

} // namespace std
[[__nodiscard__]] void *operator new(std::size_t)
    __attribute__((__externally_visible__));
[[__nodiscard__]] void *operator new[](std::size_t)
    __attribute__((__externally_visible__));
void operator delete(void *) noexcept __attribute__((__externally_visible__));
void operator delete[](void *) noexcept __attribute__((__externally_visible__));

void operator delete(void *, std::size_t) noexcept
    __attribute__((__externally_visible__));
void operator delete[](void *, std::size_t) noexcept
    __attribute__((__externally_visible__));

[[__nodiscard__]] void *operator new(std::size_t,
                                     const std::nothrow_t &) noexcept
    __attribute__((__externally_visible__, __alloc_size__(1), __malloc__));
[[__nodiscard__]] void *operator new[](std::size_t,
                                       const std::nothrow_t &) noexcept
    __attribute__((__externally_visible__, __alloc_size__(1), __malloc__));
void operator delete(void *, const std::nothrow_t &) noexcept
    __attribute__((__externally_visible__));
void operator delete[](void *, const std::nothrow_t &) noexcept
    __attribute__((__externally_visible__));

[[__nodiscard__]] void *operator new(std::size_t, std::align_val_t)
    __attribute__((__externally_visible__, __alloc_size__(1), __malloc__));
[[__nodiscard__]] void *operator new(std::size_t, std::align_val_t,
                                     const std::nothrow_t &) noexcept
    __attribute__((__externally_visible__, __alloc_size__(1), __malloc__));
void operator delete(void *, std::align_val_t) noexcept
    __attribute__((__externally_visible__));
void operator delete(void *, std::align_val_t, const std::nothrow_t &) noexcept
    __attribute__((__externally_visible__));
[[__nodiscard__]] void *operator new[](std::size_t, std::align_val_t)
    __attribute__((__externally_visible__, __alloc_size__(1), __malloc__));
[[__nodiscard__]] void *operator new[](std::size_t, std::align_val_t,
                                       const std::nothrow_t &) noexcept
    __attribute__((__externally_visible__, __alloc_size__(1), __malloc__));
void operator delete[](void *, std::align_val_t) noexcept
    __attribute__((__externally_visible__));
void operator delete[](void *, std::align_val_t,
                       const std::nothrow_t &) noexcept
    __attribute__((__externally_visible__));

void operator delete(void *, std::size_t, std::align_val_t) noexcept
    __attribute__((__externally_visible__));
void operator delete[](void *, std::size_t, std::align_val_t) noexcept
    __attribute__((__externally_visible__));

[[__nodiscard__]] inline void *operator new(std::size_t, void *__p) noexcept {
  return __p;
}
[[__nodiscard__]] inline void *operator new[](std::size_t, void *__p) noexcept {
  return __p;
}

inline void operator delete(void *, void *) noexcept {}
inline void operator delete[](void *, void *) noexcept {}
}

namespace std {

template <typename _Tp>
[[nodiscard]] constexpr _Tp *launder(_Tp *__p) noexcept {
  return __builtin_launder(__p);
}

template <typename _Ret, typename... _Args, bool _NE>
void launder(_Ret (*)(_Args...) noexcept(_NE)) = delete;
template <typename _Ret, typename... _Args, bool _NE>
void launder(_Ret (*)(_Args......) noexcept(_NE)) = delete;

void launder(void *) = delete;
void launder(const void *) = delete;
void launder(volatile void *) = delete;
void launder(const volatile void *) = delete;

inline constexpr size_t hardware_destructive_interference_size = 64;
inline constexpr size_t hardware_constructive_interference_size = 64;

} // namespace std

namespace std {

struct destroying_delete_t {
  explicit destroying_delete_t() = default;
};

inline constexpr destroying_delete_t destroying_delete{};
} // namespace std

namespace std __attribute__((__visibility__("default"))) {

  template <typename> struct _List_iterator;
  template <typename> struct _List_const_iterator;

  template <typename _InputIterator>
  inline constexpr typename iterator_traits<_InputIterator>::difference_type
  __distance(_InputIterator __first, _InputIterator __last,
             input_iterator_tag) {

    typename iterator_traits<_InputIterator>::difference_type __n = 0;
    while (__first != __last) {
      ++__first;
      ++__n;
    }
    return __n;
  }

  template <typename _RandomAccessIterator>
  __attribute__((__always_inline__)) inline constexpr
      typename iterator_traits<_RandomAccessIterator>::difference_type
      __distance(_RandomAccessIterator __first, _RandomAccessIterator __last,
                 random_access_iterator_tag) {

    return __last - __first;
  }

  template <typename _Tp>
  ptrdiff_t __distance(std::_List_iterator<_Tp>, std::_List_iterator<_Tp>,
                       input_iterator_tag);

  template <typename _Tp>
  ptrdiff_t __distance(std::_List_const_iterator<_Tp>,
                       std::_List_const_iterator<_Tp>, input_iterator_tag);

  template <typename _OutputIterator>
  void __distance(_OutputIterator, _OutputIterator, output_iterator_tag) =
      delete;
  template <typename _InputIterator>
  [[__nodiscard__]] __attribute__((__always_inline__)) inline constexpr
      typename iterator_traits<_InputIterator>::difference_type
      distance(_InputIterator __first, _InputIterator __last) {

    return std::__distance(__first, __last, std::__iterator_category(__first));
  }

  template <typename _InputIterator, typename _Distance>
  inline constexpr void __advance(_InputIterator & __i, _Distance __n,
                                  input_iterator_tag) {

    do {
      if (std::__is_constant_evaluated())
        if (__builtin_expect(!bool(__n >= 0), false))
          std::__glibcxx_assert_fail();
    } while (false);
    while (__n--)
      ++__i;
  }

  template <typename _BidirectionalIterator, typename _Distance>
  inline constexpr void __advance(_BidirectionalIterator & __i, _Distance __n,
                                  bidirectional_iterator_tag) {

    if (__n > 0)
      while (__n--)
        ++__i;
    else
      while (__n++)
        --__i;
  }

  template <typename _RandomAccessIterator, typename _Distance>
  inline constexpr void __advance(_RandomAccessIterator & __i, _Distance __n,
                                  random_access_iterator_tag) {

    if (__builtin_constant_p(__n) && __n == 1)
      ++__i;
    else if (__builtin_constant_p(__n) && __n == -1)
      --__i;
    else
      __i += __n;
  }

  template <typename _OutputIterator, typename _Distance>
  void __advance(_OutputIterator &, _Distance, output_iterator_tag) = delete;
  template <typename _InputIterator, typename _Distance>
  __attribute__((__always_inline__)) inline constexpr void advance(
      _InputIterator & __i, _Distance __n) {

    typename iterator_traits<_InputIterator>::difference_type __d = __n;
    std::__advance(__i, __d, std::__iterator_category(__i));
  }

  template <typename _InputIterator>
  [[__nodiscard__]] [[__gnu__::__always_inline__]]
  inline constexpr _InputIterator next(
      _InputIterator __x,
      typename iterator_traits<_InputIterator>::difference_type __n = 1) {

    std::advance(__x, __n);
    return __x;
  }

  template <typename _BidirectionalIterator>
  [[__nodiscard__]] [[__gnu__::__always_inline__]]
  inline constexpr _BidirectionalIterator prev(
      _BidirectionalIterator __x,
      typename iterator_traits<_BidirectionalIterator>::difference_type __n =
          1) {

    std::advance(__x, -__n);
    return __x;
  }

} // namespace std
namespace std __attribute__((__visibility__("default"))) {

  template <typename _Tp> constexpr inline void destroy_at(_Tp * __location) {
    if constexpr (202002L > 201703L && is_array_v<_Tp>) {
      for (auto &__x : *__location)
        std::destroy_at(std::__addressof(__x));
    } else
      __location->~_Tp();
  }

  template <typename _Tp, typename... _Args>
  constexpr auto construct_at(_Tp * __location, _Args && ...__args) noexcept(
      noexcept(::new ((void *)0) _Tp(std::declval<_Args>()...)))
      -> decltype(::new ((void *)0) _Tp(std::declval<_Args>()...)) {
    return ::new ((void *)__location) _Tp(std::forward<_Args>(__args)...);
  }
  template <typename _Tp, typename... _Args>
  constexpr inline void _Construct(_Tp * __p, _Args && ...__args) {

    if (std::__is_constant_evaluated()) {

      std::construct_at(__p, std::forward<_Args>(__args)...);
      return;
    }

    ::new ((void *)__p) _Tp(std::forward<_Args>(__args)...);
  }
  template <typename _T1> inline void _Construct_novalue(_T1 * __p) {
    ::new ((void *)__p) _T1;
  }

  template <typename _ForwardIterator>
  constexpr void _Destroy(_ForwardIterator __first, _ForwardIterator __last);

  template <typename _Tp> constexpr inline void _Destroy(_Tp * __pointer) {

    std::destroy_at(__pointer);
  }

  template <bool> struct _Destroy_aux {
    template <typename _ForwardIterator>
    static constexpr void __destroy(_ForwardIterator __first,
                                    _ForwardIterator __last) {
      for (; __first != __last; ++__first)
        std::_Destroy(std::__addressof(*__first));
    }
  };

  template <> struct _Destroy_aux<true> {
    template <typename _ForwardIterator>
    static void __destroy(_ForwardIterator, _ForwardIterator) {}
  };

  template <typename _ForwardIterator>
  constexpr inline void _Destroy(_ForwardIterator __first,
                                 _ForwardIterator __last) {
    typedef typename iterator_traits<_ForwardIterator>::value_type _Value_type;

    static_assert(is_destructible<_Value_type>::value,
                  "value type is destructible");

    if (std::__is_constant_evaluated())
      return std::_Destroy_aux<false>::__destroy(__first, __last);

    std::_Destroy_aux<__has_trivial_destructor(_Value_type)>::__destroy(__first,
                                                                        __last);
  }

  template <bool> struct _Destroy_n_aux {
    template <typename _ForwardIterator, typename _Size>
    static constexpr _ForwardIterator __destroy_n(_ForwardIterator __first,
                                                  _Size __count) {
      for (; __count > 0; (void)++__first, --__count)
        std::_Destroy(std::__addressof(*__first));
      return __first;
    }
  };

  template <> struct _Destroy_n_aux<true> {
    template <typename _ForwardIterator, typename _Size>
    static _ForwardIterator __destroy_n(_ForwardIterator __first,
                                        _Size __count) {
      std::advance(__first, __count);
      return __first;
    }
  };

  template <typename _ForwardIterator, typename _Size>
  constexpr inline _ForwardIterator _Destroy_n(_ForwardIterator __first,
                                               _Size __count) {
    typedef typename iterator_traits<_ForwardIterator>::value_type _Value_type;

    static_assert(is_destructible<_Value_type>::value,
                  "value type is destructible");

    if (std::__is_constant_evaluated())
      return std::_Destroy_n_aux<false>::__destroy_n(__first, __count);

    return std::_Destroy_n_aux<__has_trivial_destructor(
        _Value_type)>::__destroy_n(__first, __count);
  }

  template <typename _ForwardIterator>
  constexpr inline void destroy(_ForwardIterator __first,
                                _ForwardIterator __last) {
    std::_Destroy(__first, __last);
  }

  template <typename _ForwardIterator, typename _Size>
  constexpr inline _ForwardIterator destroy_n(_ForwardIterator __first,
                                              _Size __count) {
    return std::_Destroy_n(__first, __count);
  }

} // namespace std

namespace std __attribute__((__visibility__("default"))) {

  namespace __detail {

  template <typename _Cat, typename _Limit, typename _Otherwise = _Cat>
  using __clamp_iter_cat =
      __conditional_t<derived_from<_Cat, _Limit>, _Limit, _Otherwise>;
  }

  template <typename _Iterator>
  class reverse_iterator
      : public iterator<typename iterator_traits<_Iterator>::iterator_category,
                        typename iterator_traits<_Iterator>::value_type,
                        typename iterator_traits<_Iterator>::difference_type,
                        typename iterator_traits<_Iterator>::pointer,
                        typename iterator_traits<_Iterator>::reference> {
    template <typename _Iter> friend class reverse_iterator;

    template <typename _Iter>
    static constexpr bool __convertible =
        !is_same_v<_Iter, _Iterator> &&
        convertible_to<const _Iter &, _Iterator>;

  protected:
    _Iterator current;

    typedef iterator_traits<_Iterator> __traits_type;

  public:
    typedef _Iterator iterator_type;
    typedef typename __traits_type::pointer pointer;

    using iterator_concept =
        __conditional_t<random_access_iterator<_Iterator>,
                        random_access_iterator_tag, bidirectional_iterator_tag>;
    using iterator_category =
        __detail::__clamp_iter_cat<typename __traits_type::iterator_category,
                                   random_access_iterator_tag>;
    using value_type = iter_value_t<_Iterator>;
    using difference_type = iter_difference_t<_Iterator>;
    using reference = iter_reference_t<_Iterator>;
    constexpr reverse_iterator() noexcept(noexcept(_Iterator())) : current() {}

    explicit constexpr reverse_iterator(iterator_type __x) noexcept(
        noexcept(_Iterator(__x)))
        : current(__x) {}

    constexpr reverse_iterator(const reverse_iterator &__x) noexcept(
        noexcept(_Iterator(__x.current)))
        : current(__x.current) {}

    reverse_iterator &operator=(const reverse_iterator &) = default;

    template <typename _Iter>

      requires __convertible<_Iter>

    constexpr reverse_iterator(const reverse_iterator<_Iter> &__x) noexcept(
        noexcept(_Iterator(__x.current)))
        : current(__x.current) {}

    template <typename _Iter>

      requires __convertible<_Iter> &&
               assignable_from<_Iterator &, const _Iter &>

    constexpr reverse_iterator &
    operator=(const reverse_iterator<_Iter> &__x) noexcept(
        noexcept(current = __x.current)) {
      current = __x.current;
      return *this;
    }

    [[__nodiscard__]]
    constexpr iterator_type base() const
        noexcept(noexcept(_Iterator(current))) {
      return current;
    }
    [[__nodiscard__]]
    constexpr reference operator*() const {
      _Iterator __tmp = current;
      return *--__tmp;
    }

    [[__nodiscard__]]
    constexpr pointer operator->() const

      requires is_pointer_v<_Iterator> ||
               requires(const _Iterator __i) { __i.operator->(); }

    {

      _Iterator __tmp = current;
      --__tmp;
      return _S_to_pointer(__tmp);
    }

    constexpr reverse_iterator &operator++() {
      --current;
      return *this;
    }

    constexpr reverse_iterator operator++(int) {
      reverse_iterator __tmp = *this;
      --current;
      return __tmp;
    }

    constexpr reverse_iterator &operator--() {
      ++current;
      return *this;
    }

    constexpr reverse_iterator operator--(int) {
      reverse_iterator __tmp = *this;
      ++current;
      return __tmp;
    }

    [[__nodiscard__]]
    constexpr reverse_iterator operator+(difference_type __n) const {
      return reverse_iterator(current - __n);
    }

    constexpr reverse_iterator &operator+=(difference_type __n) {
      current -= __n;
      return *this;
    }

    [[__nodiscard__]]
    constexpr reverse_iterator operator-(difference_type __n) const {
      return reverse_iterator(current + __n);
    }

    constexpr reverse_iterator &operator-=(difference_type __n) {
      current += __n;
      return *this;
    }

    [[__nodiscard__]]
    constexpr reference operator[](difference_type __n) const {
      return *(*this + __n);
    }

    [[nodiscard]]
    friend constexpr iter_rvalue_reference_t<_Iterator>
    iter_move(const reverse_iterator &__i) noexcept(
        is_nothrow_copy_constructible_v<_Iterator> &&
        noexcept(ranges::iter_move(--std::declval<_Iterator &>()))) {
      auto __tmp = __i.base();
      return ranges::iter_move(--__tmp);
    }

    template <indirectly_swappable<_Iterator> _Iter2>
    friend constexpr void
    iter_swap(const reverse_iterator &__x,
              const reverse_iterator<_Iter2>
                  &__y) noexcept(is_nothrow_copy_constructible_v<_Iterator> &&
                                 is_nothrow_copy_constructible_v<_Iter2> &&
                                 noexcept(ranges::iter_swap(
                                     --std::declval<_Iterator &>(),
                                     --std::declval<_Iter2 &>()))) {
      auto __xtmp = __x.base();
      auto __ytmp = __y.base();
      ranges::iter_swap(--__xtmp, --__ytmp);
    }

  private:
    template <typename _Tp> static constexpr _Tp *_S_to_pointer(_Tp *__p) {
      return __p;
    }

    template <typename _Tp> static constexpr pointer _S_to_pointer(_Tp __t) {
      return __t.operator->();
    }
  };
  template <typename _IteratorL, typename _IteratorR>
  [[nodiscard]]
  constexpr bool operator==(const reverse_iterator<_IteratorL> &__x,
                            const reverse_iterator<_IteratorR> &__y)
    requires requires {
      { __x.base() == __y.base() } -> convertible_to<bool>;
    }
  {
    return __x.base() == __y.base();
  }

  template <typename _IteratorL, typename _IteratorR>
  [[nodiscard]]
  constexpr bool operator!=(const reverse_iterator<_IteratorL> &__x,
                            const reverse_iterator<_IteratorR> &__y)
    requires requires {
      { __x.base() != __y.base() } -> convertible_to<bool>;
    }
  {
    return __x.base() != __y.base();
  }

  template <typename _IteratorL, typename _IteratorR>
  [[nodiscard]]
  constexpr bool operator<(const reverse_iterator<_IteratorL> &__x,
                           const reverse_iterator<_IteratorR> &__y)
    requires requires {
      { __x.base() > __y.base() } -> convertible_to<bool>;
    }
  {
    return __x.base() > __y.base();
  }

  template <typename _IteratorL, typename _IteratorR>
  [[nodiscard]]
  constexpr bool operator>(const reverse_iterator<_IteratorL> &__x,
                           const reverse_iterator<_IteratorR> &__y)
    requires requires {
      { __x.base() < __y.base() } -> convertible_to<bool>;
    }
  {
    return __x.base() < __y.base();
  }

  template <typename _IteratorL, typename _IteratorR>
  [[nodiscard]]
  constexpr bool operator<=(const reverse_iterator<_IteratorL> &__x,
                            const reverse_iterator<_IteratorR> &__y)
    requires requires {
      { __x.base() >= __y.base() } -> convertible_to<bool>;
    }
  {
    return __x.base() >= __y.base();
  }

  template <typename _IteratorL, typename _IteratorR>
  [[nodiscard]]
  constexpr bool operator>=(const reverse_iterator<_IteratorL> &__x,
                            const reverse_iterator<_IteratorR> &__y)
    requires requires {
      { __x.base() <= __y.base() } -> convertible_to<bool>;
    }
  {
    return __x.base() <= __y.base();
  }

  template <typename _IteratorL,
            three_way_comparable_with<_IteratorL> _IteratorR>
  [[nodiscard]]
  constexpr compare_three_way_result_t<_IteratorL, _IteratorR> operator<=>(
      const reverse_iterator<_IteratorL> &__x,
      const reverse_iterator<_IteratorR> &__y) {
    return __y.base() <=> __x.base();
  }

  template <typename _Iterator>
  [[nodiscard]]
  constexpr bool operator==(const reverse_iterator<_Iterator> &__x,
                            const reverse_iterator<_Iterator> &__y)
    requires requires {
      { __x.base() == __y.base() } -> convertible_to<bool>;
    }
  {
    return __x.base() == __y.base();
  }

  template <three_way_comparable _Iterator>
  [[nodiscard]]
  constexpr compare_three_way_result_t<_Iterator, _Iterator> operator<=>(
      const reverse_iterator<_Iterator> &__x,
      const reverse_iterator<_Iterator> &__y) {
    return __y.base() <=> __x.base();
  }
  template <typename _IteratorL, typename _IteratorR>
  [[__nodiscard__]]
  inline constexpr auto operator-(const reverse_iterator<_IteratorL> &__x,
                                  const reverse_iterator<_IteratorR> &__y)
      ->decltype(__y.base() - __x.base()) {
    return __y.base() - __x.base();
  }

  template <typename _Iterator>
  [[__nodiscard__]]
  inline constexpr reverse_iterator<_Iterator> operator+(
      typename reverse_iterator<_Iterator>::difference_type __n,
      const reverse_iterator<_Iterator> &__x) {
    return reverse_iterator<_Iterator>(__x.base() - __n);
  }

  template <typename _Iterator>
  inline constexpr reverse_iterator<_Iterator> __make_reverse_iterator(
      _Iterator __i) {
    return reverse_iterator<_Iterator>(__i);
  }

  template <typename _Iterator>
  [[__nodiscard__]]
  inline constexpr reverse_iterator<_Iterator> make_reverse_iterator(
      _Iterator __i) {
    return reverse_iterator<_Iterator>(__i);
  }

  template <typename _Iterator1, typename _Iterator2>
    requires(!sized_sentinel_for<_Iterator1, _Iterator2>)
  inline constexpr bool disable_sized_sentinel_for<
      reverse_iterator<_Iterator1>, reverse_iterator<_Iterator2>> = true;

  template <typename _Iterator>
  constexpr auto __niter_base(reverse_iterator<_Iterator> __it)
      -> decltype(__make_reverse_iterator(__niter_base(__it.base()))) {
    return __make_reverse_iterator(__niter_base(__it.base()));
  }

  template <typename _Iterator>
  struct __is_move_iterator<reverse_iterator<_Iterator>>
      : __is_move_iterator<_Iterator> {};

  template <typename _Iterator>
  constexpr auto __miter_base(reverse_iterator<_Iterator> __it)
      -> decltype(__make_reverse_iterator(__miter_base(__it.base()))) {
    return __make_reverse_iterator(__miter_base(__it.base()));
  }
  template <typename _Container>
  class back_insert_iterator
      : public iterator<output_iterator_tag, void, void, void, void> {
  protected:
    _Container *container;

  public:
    typedef _Container container_type;

    using difference_type = ptrdiff_t;

    explicit constexpr back_insert_iterator(_Container &__x)
        : container(std::__addressof(__x)) {}
    constexpr back_insert_iterator &
    operator=(const typename _Container::value_type &__value) {
      container->push_back(__value);
      return *this;
    }

    constexpr back_insert_iterator &
    operator=(typename _Container::value_type &&__value) {
      container->push_back(std::move(__value));
      return *this;
    }

    [[__nodiscard__]] constexpr back_insert_iterator &operator*() {
      return *this;
    }

    constexpr back_insert_iterator &operator++() { return *this; }

    constexpr back_insert_iterator operator++(int) { return *this; }
  };
  template <typename _Container>
  [[__nodiscard__]] constexpr inline back_insert_iterator<_Container>
  back_inserter(_Container & __x) {
    return back_insert_iterator<_Container>(__x);
  }
  template <typename _Container>
  class front_insert_iterator
      : public iterator<output_iterator_tag, void, void, void, void> {
  protected:
    _Container *container;

  public:
    typedef _Container container_type;

    using difference_type = ptrdiff_t;

    explicit constexpr front_insert_iterator(_Container &__x)
        : container(std::__addressof(__x)) {}
    constexpr front_insert_iterator &
    operator=(const typename _Container::value_type &__value) {
      container->push_front(__value);
      return *this;
    }

    constexpr front_insert_iterator &
    operator=(typename _Container::value_type &&__value) {
      container->push_front(std::move(__value));
      return *this;
    }

    [[__nodiscard__]] constexpr front_insert_iterator &operator*() {
      return *this;
    }

    constexpr front_insert_iterator &operator++() { return *this; }

    constexpr front_insert_iterator operator++(int) { return *this; }
  };
  template <typename _Container>
  [[__nodiscard__]] constexpr inline front_insert_iterator<_Container>
  front_inserter(_Container & __x) {
    return front_insert_iterator<_Container>(__x);
  }
  template <typename _Container>
  class insert_iterator
      : public iterator<output_iterator_tag, void, void, void, void> {

    using _Iter = std::__detail::__range_iter_t<_Container>;

  protected:
    _Container *container;
    _Iter iter;

  public:
    typedef _Container container_type;

    using difference_type = ptrdiff_t;

    constexpr insert_iterator(_Container &__x, _Iter __i)
        : container(std::__addressof(__x)), iter(__i) {}
    constexpr insert_iterator &
    operator=(const typename _Container::value_type &__value) {
      iter = container->insert(iter, __value);
      ++iter;
      return *this;
    }

    constexpr insert_iterator &
    operator=(typename _Container::value_type &&__value) {
      iter = container->insert(iter, std::move(__value));
      ++iter;
      return *this;
    }

    [[__nodiscard__]] constexpr insert_iterator &operator*() { return *this; }

    constexpr insert_iterator &operator++() { return *this; }

    constexpr insert_iterator &operator++(int) { return *this; }
  };

  template <typename _Container>
  [[nodiscard]]
  constexpr insert_iterator<_Container> inserter(
      _Container & __x, std::__detail::__range_iter_t<_Container> __i) {
    return insert_iterator<_Container>(__x, __i);
  }

} // namespace std

namespace __gnu_cxx __attribute__((__visibility__("default"))) {

  template <typename _Iterator, typename _Container> class __normal_iterator {
  protected:
    _Iterator _M_current;

    typedef std::iterator_traits<_Iterator> __traits_type;

    template <typename _Iter>
    using __convertible_from =
        std::__enable_if_t<std::is_convertible<_Iter, _Iterator>::value>;

  public:
    typedef _Iterator iterator_type;
    typedef typename __traits_type::iterator_category iterator_category;
    typedef typename __traits_type::value_type value_type;
    typedef typename __traits_type::difference_type difference_type;
    typedef typename __traits_type::reference reference;
    typedef typename __traits_type::pointer pointer;

    using iterator_concept = std::__detail::__iter_concept<_Iterator>;

    constexpr __normal_iterator() noexcept : _M_current(_Iterator()) {}

    explicit constexpr __normal_iterator(const _Iterator &__i) noexcept
        : _M_current(__i) {}

    template <typename _Iter, typename = __convertible_from<_Iter>>
    constexpr __normal_iterator(
        const __normal_iterator<_Iter, _Container> &__i) noexcept
        : _M_current(__i.base()) {}

    constexpr reference operator*() const noexcept { return *_M_current; }

    constexpr pointer operator->() const noexcept { return _M_current; }

    constexpr __normal_iterator &operator++() noexcept {
      ++_M_current;
      return *this;
    }

    constexpr __normal_iterator operator++(int) noexcept {
      return __normal_iterator(_M_current++);
    }

    constexpr __normal_iterator &operator--() noexcept {
      --_M_current;
      return *this;
    }

    constexpr __normal_iterator operator--(int) noexcept {
      return __normal_iterator(_M_current--);
    }

    constexpr reference operator[](difference_type __n) const noexcept {
      return _M_current[__n];
    }

    constexpr __normal_iterator &operator+=(difference_type __n) noexcept {
      _M_current += __n;
      return *this;
    }

    constexpr __normal_iterator operator+(difference_type __n) const noexcept {
      return __normal_iterator(_M_current + __n);
    }

    constexpr __normal_iterator &operator-=(difference_type __n) noexcept {
      _M_current -= __n;
      return *this;
    }

    constexpr __normal_iterator operator-(difference_type __n) const noexcept {
      return __normal_iterator(_M_current - __n);
    }

    constexpr const _Iterator &base() const noexcept { return _M_current; }
  };
  template <typename _IteratorL, typename _IteratorR, typename _Container>
  [[nodiscard]]
  constexpr bool operator==(
      const __normal_iterator<_IteratorL, _Container> &__lhs,
      const __normal_iterator<_IteratorR, _Container>
          &__rhs) noexcept(noexcept(__lhs.base() == __rhs.base()))
    requires requires {
      { __lhs.base() == __rhs.base() } -> std::convertible_to<bool>;
    }
  {
    return __lhs.base() == __rhs.base();
  }

  template <typename _IteratorL, typename _IteratorR, typename _Container>
  [[nodiscard]]
  constexpr std::__detail::__synth3way_t<_IteratorR, _IteratorL> operator<=>(
      const __normal_iterator<_IteratorL, _Container> &__lhs,
      const __normal_iterator<_IteratorR, _Container>
          &__rhs) noexcept(noexcept(std::__detail::__synth3way(__lhs.base(),
                                                               __rhs.base()))) {
    return std::__detail::__synth3way(__lhs.base(), __rhs.base());
  }

  template <typename _Iterator, typename _Container>
  [[nodiscard]]
  constexpr bool operator==(
      const __normal_iterator<_Iterator, _Container> &__lhs,
      const __normal_iterator<_Iterator, _Container>
          &__rhs) noexcept(noexcept(__lhs.base() == __rhs.base()))
    requires requires {
      { __lhs.base() == __rhs.base() } -> std::convertible_to<bool>;
    }
  {
    return __lhs.base() == __rhs.base();
  }

  template <typename _Iterator, typename _Container>
  [[nodiscard]]
  constexpr std::__detail::__synth3way_t<_Iterator> operator<=>(
      const __normal_iterator<_Iterator, _Container> &__lhs,
      const __normal_iterator<_Iterator, _Container>
          &__rhs) noexcept(noexcept(std::__detail::__synth3way(__lhs.base(),
                                                               __rhs.base()))) {
    return std::__detail::__synth3way(__lhs.base(), __rhs.base());
  }
  template <typename _IteratorL, typename _IteratorR, typename _Container>

  [[__nodiscard__]] constexpr inline auto operator-(
      const __normal_iterator<_IteratorL, _Container> &__lhs,
      const __normal_iterator<_IteratorR, _Container> &__rhs) noexcept
      -> decltype(__lhs.base() - __rhs.base())

  {
    return __lhs.base() - __rhs.base();
  }

  template <typename _Iterator, typename _Container>
  [[__nodiscard__]] constexpr inline
      typename __normal_iterator<_Iterator, _Container>::difference_type
      operator-(
          const __normal_iterator<_Iterator, _Container> &__lhs,
          const __normal_iterator<_Iterator, _Container> &__rhs) noexcept {
    return __lhs.base() - __rhs.base();
  }

  template <typename _Iterator, typename _Container>
  [[__nodiscard__]] constexpr inline __normal_iterator<_Iterator, _Container>
  operator+(
      typename __normal_iterator<_Iterator, _Container>::difference_type __n,
      const __normal_iterator<_Iterator, _Container> &__i) noexcept {
    return __normal_iterator<_Iterator, _Container>(__i.base() + __n);
  }

} // namespace __gnu_cxx

namespace std __attribute__((__visibility__("default"))) {

  template <typename _Iterator, typename _Container>
  constexpr _Iterator __niter_base(
      __gnu_cxx::__normal_iterator<_Iterator, _Container>
          __it) noexcept(std::is_nothrow_copy_constructible<_Iterator>::value) {
    return __it.base();
  }
  template <semiregular _Sent> class move_sentinel {
  public:
    constexpr move_sentinel() noexcept(
        is_nothrow_default_constructible_v<_Sent>)
        : _M_last() {}

    constexpr explicit move_sentinel(_Sent __s) noexcept(
        is_nothrow_move_constructible_v<_Sent>)
        : _M_last(std::move(__s)) {}

    template <typename _S2>
      requires convertible_to<const _S2 &, _Sent>
    constexpr move_sentinel(const move_sentinel<_S2> &__s) noexcept(
        is_nothrow_constructible_v<_Sent, const _S2 &>)
        : _M_last(__s.base()) {}

    template <typename _S2>
      requires assignable_from<_Sent &, const _S2 &>
    constexpr move_sentinel &operator=(const move_sentinel<_S2> &__s) noexcept(
        is_nothrow_assignable_v<_Sent, const _S2 &>) {
      _M_last = __s.base();
      return *this;
    }

    [[nodiscard]]
    constexpr _Sent base() const
        noexcept(is_nothrow_copy_constructible_v<_Sent>) {
      return _M_last;
    }

  private:
    _Sent _M_last;
  };

  namespace __detail {

  template <typename _Iterator> struct __move_iter_cat {};

  template <typename _Iterator>
    requires requires { typename __iter_category_t<_Iterator>; }
  struct __move_iter_cat<_Iterator> {
    using iterator_category = __clamp_iter_cat<__iter_category_t<_Iterator>,
                                               random_access_iterator_tag>;
  };

  } // namespace __detail
  template <typename _Iterator>
  class move_iterator

      : public __detail::__move_iter_cat<_Iterator>

  {
    _Iterator _M_current;

    using __traits_type = iterator_traits<_Iterator>;

    template <typename _Iter2> friend class move_iterator;

    template <typename _Iter2>
    static constexpr bool __convertible =
        !is_same_v<_Iter2, _Iterator> &&
        convertible_to<const _Iter2 &, _Iterator>;

    static auto _S_iter_concept() {
      if constexpr (random_access_iterator<_Iterator>)
        return random_access_iterator_tag{};
      else if constexpr (bidirectional_iterator<_Iterator>)
        return bidirectional_iterator_tag{};
      else if constexpr (forward_iterator<_Iterator>)
        return forward_iterator_tag{};
      else
        return input_iterator_tag{};
    }

  public:
    using iterator_type = _Iterator;

    using iterator_concept = decltype(_S_iter_concept());

    using value_type = iter_value_t<_Iterator>;
    using difference_type = iter_difference_t<_Iterator>;
    using pointer = _Iterator;
    using reference = iter_rvalue_reference_t<_Iterator>;
    constexpr move_iterator() : _M_current() {}

    explicit constexpr move_iterator(iterator_type __i)
        : _M_current(std::move(__i)) {}

    template <typename _Iter>

      requires __convertible<_Iter>

    constexpr move_iterator(const move_iterator<_Iter> &__i)
        : _M_current(__i._M_current) {}

    template <typename _Iter>

      requires __convertible<_Iter> &&
               assignable_from<_Iterator &, const _Iter &>

    constexpr move_iterator &operator=(const move_iterator<_Iter> &__i) {
      _M_current = __i._M_current;
      return *this;
    }

    [[nodiscard]]
    constexpr const iterator_type &base() const & noexcept {
      return _M_current;
    }

    [[nodiscard]]
    constexpr iterator_type base() && {
      return std::move(_M_current);
    }

    [[__nodiscard__]]
    constexpr reference operator*() const

    {
      return ranges::iter_move(_M_current);
    }

    [[__nodiscard__]]
    constexpr pointer operator->() const {
      return _M_current;
    }

    constexpr move_iterator &operator++() {
      ++_M_current;
      return *this;
    }

    constexpr move_iterator operator++(int) {
      move_iterator __tmp = *this;
      ++_M_current;
      return __tmp;
    }

    constexpr void operator++(int)
      requires(!forward_iterator<_Iterator>)
    {
      ++_M_current;
    }

    constexpr move_iterator &operator--() {
      --_M_current;
      return *this;
    }

    constexpr move_iterator operator--(int) {
      move_iterator __tmp = *this;
      --_M_current;
      return __tmp;
    }

    [[__nodiscard__]]
    constexpr move_iterator operator+(difference_type __n) const {
      return move_iterator(_M_current + __n);
    }

    constexpr move_iterator &operator+=(difference_type __n) {
      _M_current += __n;
      return *this;
    }

    [[__nodiscard__]]
    constexpr move_iterator operator-(difference_type __n) const {
      return move_iterator(_M_current - __n);
    }

    constexpr move_iterator &operator-=(difference_type __n) {
      _M_current -= __n;
      return *this;
    }

    [[__nodiscard__]]
    constexpr reference operator[](difference_type __n) const

    {
      return ranges::iter_move(_M_current + __n);
    }

    template <sentinel_for<_Iterator> _Sent>
    [[nodiscard]]
    friend constexpr bool operator==(const move_iterator &__x,
                                     const move_sentinel<_Sent> &__y) {
      return __x.base() == __y.base();
    }

    template <sized_sentinel_for<_Iterator> _Sent>
    [[nodiscard]]
    friend constexpr iter_difference_t<_Iterator>
    operator-(const move_sentinel<_Sent> &__x, const move_iterator &__y) {
      return __x.base() - __y.base();
    }

    template <sized_sentinel_for<_Iterator> _Sent>
    [[nodiscard]]
    friend constexpr iter_difference_t<_Iterator>
    operator-(const move_iterator &__x, const move_sentinel<_Sent> &__y) {
      return __x.base() - __y.base();
    }

    [[nodiscard]]
    friend constexpr iter_rvalue_reference_t<_Iterator>
    iter_move(const move_iterator &__i) noexcept(
        noexcept(ranges::iter_move(__i._M_current))) {
      return ranges::iter_move(__i._M_current);
    }

    template <indirectly_swappable<_Iterator> _Iter2>
    friend constexpr void
    iter_swap(const move_iterator &__x,
              const move_iterator<_Iter2>
                  &__y) noexcept(noexcept(ranges::iter_swap(__x._M_current,
                                                            __y._M_current))) {
      return ranges::iter_swap(__x._M_current, __y._M_current);
    }
  };

  template <typename _IteratorL, typename _IteratorR>
  [[__nodiscard__]]
  inline constexpr bool operator==(const move_iterator<_IteratorL> &__x,
                                   const move_iterator<_IteratorR> &__y)

    requires requires {
      { __x.base() == __y.base() } -> convertible_to<bool>;
    }

  {
    return __x.base() == __y.base();
  }

  template <typename _IteratorL,
            three_way_comparable_with<_IteratorL> _IteratorR>
  [[__nodiscard__]]
  constexpr compare_three_way_result_t<_IteratorL, _IteratorR> operator<=>(
      const move_iterator<_IteratorL> &__x,
      const move_iterator<_IteratorR> &__y) {
    return __x.base() <=> __y.base();
  }
  template <typename _IteratorL, typename _IteratorR>
  [[__nodiscard__]]
  inline constexpr bool operator<(const move_iterator<_IteratorL> &__x,
                                  const move_iterator<_IteratorR> &__y)

    requires requires {
      { __x.base() < __y.base() } -> convertible_to<bool>;
    }

  {
    return __x.base() < __y.base();
  }

  template <typename _IteratorL, typename _IteratorR>
  [[__nodiscard__]]
  inline constexpr bool operator<=(const move_iterator<_IteratorL> &__x,
                                   const move_iterator<_IteratorR> &__y)

    requires requires {
      { __y.base() < __x.base() } -> convertible_to<bool>;
    }

  {
    return !(__y < __x);
  }

  template <typename _IteratorL, typename _IteratorR>
  [[__nodiscard__]]
  inline constexpr bool operator>(const move_iterator<_IteratorL> &__x,
                                  const move_iterator<_IteratorR> &__y)

    requires requires {
      { __y.base() < __x.base() } -> convertible_to<bool>;
    }

  {
    return __y < __x;
  }

  template <typename _IteratorL, typename _IteratorR>
  [[__nodiscard__]]
  inline constexpr bool operator>=(const move_iterator<_IteratorL> &__x,
                                   const move_iterator<_IteratorR> &__y)

    requires requires {
      { __x.base() < __y.base() } -> convertible_to<bool>;
    }

  {
    return !(__x < __y);
  }

  template <typename _Iterator>
  [[__nodiscard__]]
  inline constexpr bool operator==(const move_iterator<_Iterator> &__x,
                                   const move_iterator<_Iterator> &__y) {
    return __x.base() == __y.base();
  }

  template <three_way_comparable _Iterator>
  [[__nodiscard__]]
  constexpr compare_three_way_result_t<_Iterator> operator<=>(
      const move_iterator<_Iterator> &__x,
      const move_iterator<_Iterator> &__y) {
    return __x.base() <=> __y.base();
  }
  template <typename _IteratorL, typename _IteratorR>
  [[__nodiscard__]]
  inline constexpr auto operator-(const move_iterator<_IteratorL> &__x,
                                  const move_iterator<_IteratorR> &__y)
      ->decltype(__x.base() - __y.base()) {
    return __x.base() - __y.base();
  }

  template <typename _Iterator>
  [[__nodiscard__]]
  inline constexpr move_iterator<_Iterator> operator+(
      typename move_iterator<_Iterator>::difference_type __n,
      const move_iterator<_Iterator> &__x) {
    return __x + __n;
  }

  template <typename _Iterator>
  [[__nodiscard__]]
  inline constexpr move_iterator<_Iterator> make_move_iterator(_Iterator __i) {
    return move_iterator<_Iterator>(std::move(__i));
  }

  template <typename _Iterator,
            typename _ReturnType = __conditional_t<
                __move_if_noexcept_cond<
                    typename iterator_traits<_Iterator>::value_type>::value,
                _Iterator, move_iterator<_Iterator>>>
  inline constexpr _ReturnType __make_move_if_noexcept_iterator(_Iterator __i) {
    return _ReturnType(__i);
  }

  template <typename _Tp,
            typename _ReturnType =
                __conditional_t<__move_if_noexcept_cond<_Tp>::value,
                                const _Tp *, move_iterator<_Tp *>>>
  inline constexpr _ReturnType __make_move_if_noexcept_iterator(_Tp * __i) {
    return _ReturnType(__i);
  }

  template <typename _Iterator1, typename _Iterator2>
    requires(!sized_sentinel_for<_Iterator1, _Iterator2>)
  inline constexpr bool disable_sized_sentinel_for<move_iterator<_Iterator1>,
                                                   move_iterator<_Iterator2>> =
      true;

  namespace __detail {
  template <typename _It>
  concept __common_iter_has_arrow =
      indirectly_readable<const _It> &&
      (requires(const _It &__it) { __it.operator->(); } ||
       is_reference_v<iter_reference_t<_It>> ||
       constructible_from<iter_value_t<_It>, iter_reference_t<_It>>);

  template <typename _It>
  concept __common_iter_use_postfix_proxy =
      (!requires(_It &__i) {
        { *__i++ } -> __can_reference;
      }) && constructible_from<iter_value_t<_It>, iter_reference_t<_It>> &&
      move_constructible<iter_value_t<_It>>;
  } // namespace __detail

  template <input_or_output_iterator _It, sentinel_for<_It> _Sent>
    requires(!same_as<_It, _Sent>) && copyable<_It>
  class common_iterator {
    template <typename _Tp, typename _Up> static constexpr bool _S_noexcept1() {
      if constexpr (is_trivially_default_constructible_v<_Tp>)
        return is_nothrow_assignable_v<_Tp &, _Up>;
      else
        return is_nothrow_constructible_v<_Tp, _Up>;
    }

    template <typename _It2, typename _Sent2>
    static constexpr bool _S_noexcept() {
      return _S_noexcept1<_It, _It2>() && _S_noexcept1<_Sent, _Sent2>();
    }

    class __arrow_proxy {
      iter_value_t<_It> _M_keep;

      constexpr __arrow_proxy(iter_reference_t<_It> &&__x)
          : _M_keep(std::move(__x)) {}

      friend class common_iterator;

    public:
      constexpr const iter_value_t<_It> *operator->() const noexcept {
        return std::__addressof(_M_keep);
      }
    };

    class __postfix_proxy {
      iter_value_t<_It> _M_keep;

      constexpr __postfix_proxy(iter_reference_t<_It> &&__x)
          : _M_keep(std::forward<iter_reference_t<_It>>(__x)) {}

      friend class common_iterator;

    public:
      constexpr const iter_value_t<_It> &operator*() const noexcept {
        return _M_keep;
      }
    };

  public:
    constexpr common_iterator() noexcept(
        is_nothrow_default_constructible_v<_It>)
      requires default_initializable<_It>
        : _M_it(), _M_index(0) {}

    constexpr common_iterator(_It __i) noexcept(
        is_nothrow_move_constructible_v<_It>)
        : _M_it(std::move(__i)), _M_index(0) {}

    constexpr common_iterator(_Sent __s) noexcept(
        is_nothrow_move_constructible_v<_Sent>)
        : _M_sent(std::move(__s)), _M_index(1) {}

    template <typename _It2, typename _Sent2>
      requires convertible_to<const _It2 &, _It> &&
                   convertible_to<const _Sent2 &, _Sent>
    constexpr common_iterator(
        const common_iterator<_It2, _Sent2>
            &__x) noexcept(_S_noexcept<const _It2 &, const _Sent2 &>())
        : _M_valueless(), _M_index(__x._M_index) {
      do {
        if (std::__is_constant_evaluated())
          if (__builtin_expect(!bool(__x._M_has_value()), false))
            std::__glibcxx_assert_fail();
      } while (false);
      if (_M_index == 0) {
        if constexpr (is_trivially_default_constructible_v<_It>)
          _M_it = std::move(__x._M_it);
        else
          std::construct_at(std::__addressof(_M_it), __x._M_it);
      } else if (_M_index == 1) {
        if constexpr (is_trivially_default_constructible_v<_Sent>)
          _M_sent = std::move(__x._M_sent);
        else
          std::construct_at(std::__addressof(_M_sent), __x._M_sent);
      }
    }

    common_iterator(const common_iterator &) = default;

    constexpr common_iterator(const common_iterator &__x) noexcept(
        _S_noexcept<const _It &, const _Sent &>())
      requires(!is_trivially_copyable_v<_It> || !is_trivially_copyable_v<_Sent>)
        : _M_valueless(), _M_index(__x._M_index) {
      if (_M_index == 0) {
        if constexpr (is_trivially_default_constructible_v<_It>)
          _M_it = __x._M_it;
        else
          std::construct_at(std::__addressof(_M_it), __x._M_it);
      } else if (_M_index == 1) {
        if constexpr (is_trivially_default_constructible_v<_Sent>)
          _M_sent = __x._M_sent;
        else
          std::construct_at(std::__addressof(_M_sent), __x._M_sent);
      }
    }

    common_iterator(common_iterator &&) = default;

    constexpr common_iterator(common_iterator &&__x) noexcept(
        _S_noexcept<_It, _Sent>())
      requires(!is_trivially_copyable_v<_It> || !is_trivially_copyable_v<_Sent>)
        : _M_valueless(), _M_index(__x._M_index) {
      if (_M_index == 0) {
        if constexpr (is_trivially_default_constructible_v<_It>)
          _M_it = std::move(__x._M_it);
        else
          std::construct_at(std::__addressof(_M_it), std::move(__x._M_it));
      } else if (_M_index == 1) {
        if constexpr (is_trivially_default_constructible_v<_Sent>)
          _M_sent = std::move(__x._M_sent);
        else
          std::construct_at(std::__addressof(_M_sent), std::move(__x._M_sent));
      }
    }

    constexpr common_iterator &operator=(const common_iterator &) = default;

    constexpr common_iterator &operator=(const common_iterator &__x) noexcept(
        is_nothrow_copy_assignable_v<_It> &&
        is_nothrow_copy_assignable_v<_Sent> &&
        is_nothrow_copy_constructible_v<_It> &&
        is_nothrow_copy_constructible_v<_Sent>)
      requires(!is_trivially_copy_assignable_v<_It> ||
               !is_trivially_copy_assignable_v<_Sent>)
    {
      _M_assign(__x);
      return *this;
    }

    constexpr common_iterator &operator=(common_iterator &&) = default;

    constexpr common_iterator &operator=(common_iterator &&__x) noexcept(
        is_nothrow_move_assignable_v<_It> &&
        is_nothrow_move_assignable_v<_Sent> &&
        is_nothrow_move_constructible_v<_It> &&
        is_nothrow_move_constructible_v<_Sent>)
      requires(!is_trivially_move_assignable_v<_It> ||
               !is_trivially_move_assignable_v<_Sent>)
    {
      _M_assign(std::move(__x));
      return *this;
    }

    template <typename _It2, typename _Sent2>
      requires convertible_to<const _It2 &, _It> &&
               convertible_to<const _Sent2 &, _Sent> &&
               assignable_from<_It &, const _It2 &> &&
               assignable_from<_Sent &, const _Sent2 &>
    constexpr common_iterator &
    operator=(const common_iterator<_It2, _Sent2> &__x) noexcept(
        is_nothrow_constructible_v<_It, const _It2 &> &&
        is_nothrow_constructible_v<_Sent, const _Sent2 &> &&
        is_nothrow_assignable_v<_It &, const _It2 &> &&
        is_nothrow_assignable_v<_Sent &, const _Sent2 &>) {
      do {
        if (std::__is_constant_evaluated())
          if (__builtin_expect(!bool(__x._M_has_value()), false))
            std::__glibcxx_assert_fail();
      } while (false);
      _M_assign(__x);
      return *this;
    }

    ~common_iterator() = default;

    constexpr ~common_iterator()
      requires(!is_trivially_destructible_v<_It> ||
               !is_trivially_destructible_v<_Sent>)

    {
      if (_M_index == 0)
        _M_it.~_It();
      else if (_M_index == 1)
        _M_sent.~_Sent();
    }

    [[nodiscard]]
    constexpr decltype(auto) operator*() {
      do {
        if (std::__is_constant_evaluated())
          if (__builtin_expect(!bool(_M_index == 0), false))
            std::__glibcxx_assert_fail();
      } while (false);
      return *_M_it;
    }

    [[nodiscard]]
    constexpr decltype(auto) operator*() const
      requires __detail::__dereferenceable<const _It>
    {
      do {
        if (std::__is_constant_evaluated())
          if (__builtin_expect(!bool(_M_index == 0), false))
            std::__glibcxx_assert_fail();
      } while (false);
      return *_M_it;
    }

    [[nodiscard]]
    constexpr auto operator->() const
      requires __detail::__common_iter_has_arrow<_It>
    {
      do {
        if (std::__is_constant_evaluated())
          if (__builtin_expect(!bool(_M_index == 0), false))
            std::__glibcxx_assert_fail();
      } while (false);
      if constexpr (is_pointer_v<_It> || requires { _M_it.operator->(); })
        return _M_it;
      else if constexpr (is_reference_v<iter_reference_t<_It>>) {
        auto &&__tmp = *_M_it;
        return std::__addressof(__tmp);
      } else
        return __arrow_proxy{*_M_it};
    }

    constexpr common_iterator &operator++() {
      do {
        if (std::__is_constant_evaluated())
          if (__builtin_expect(!bool(_M_index == 0), false))
            std::__glibcxx_assert_fail();
      } while (false);
      ++_M_it;
      return *this;
    }

    constexpr decltype(auto) operator++(int) {
      do {
        if (std::__is_constant_evaluated())
          if (__builtin_expect(!bool(_M_index == 0), false))
            std::__glibcxx_assert_fail();
      } while (false);
      if constexpr (forward_iterator<_It>) {
        common_iterator __tmp = *this;
        ++*this;
        return __tmp;
      } else if constexpr (!__detail::__common_iter_use_postfix_proxy<_It>)
        return _M_it++;
      else {
        __postfix_proxy __p(**this);
        ++*this;
        return __p;
      }
    }

    template <typename _It2, sentinel_for<_It> _Sent2>
      requires sentinel_for<_Sent, _It2>
    friend constexpr bool operator==
        [[nodiscard]] (const common_iterator &__x,
                       const common_iterator<_It2, _Sent2> &__y) {
      switch (__x._M_index << 2 | __y._M_index) {
      case 0b0000:
      case 0b0101:
        return true;
      case 0b0001:
        return __x._M_it == __y._M_sent;
      case 0b0100:
        return __x._M_sent == __y._M_it;
      default:
        do {
          if (std::__is_constant_evaluated())
            if (__builtin_expect(!bool(__x._M_has_value()), false))
              std::__glibcxx_assert_fail();
        } while (false);
        do {
          if (std::__is_constant_evaluated())
            if (__builtin_expect(!bool(__y._M_has_value()), false))
              std::__glibcxx_assert_fail();
        } while (false);
        __builtin_unreachable();
      }
    }

    template <typename _It2, sentinel_for<_It> _Sent2>
      requires sentinel_for<_Sent, _It2> && equality_comparable_with<_It, _It2>
    friend constexpr bool operator==
        [[nodiscard]] (const common_iterator &__x,
                       const common_iterator<_It2, _Sent2> &__y) {
      switch (__x._M_index << 2 | __y._M_index) {
      case 0b0101:
        return true;
      case 0b0000:
        return __x._M_it == __y._M_it;
      case 0b0001:
        return __x._M_it == __y._M_sent;
      case 0b0100:
        return __x._M_sent == __y._M_it;
      default:
        do {
          if (std::__is_constant_evaluated())
            if (__builtin_expect(!bool(__x._M_has_value()), false))
              std::__glibcxx_assert_fail();
        } while (false);
        do {
          if (std::__is_constant_evaluated())
            if (__builtin_expect(!bool(__y._M_has_value()), false))
              std::__glibcxx_assert_fail();
        } while (false);
        __builtin_unreachable();
      }
    }

    template <sized_sentinel_for<_It> _It2, sized_sentinel_for<_It> _Sent2>
      requires sized_sentinel_for<_Sent, _It2>
    friend constexpr iter_difference_t<_It2> operator-
        [[nodiscard]] (const common_iterator & __x,
                       const common_iterator<_It2, _Sent2> &__y) {
      switch (__x._M_index << 2 | __y._M_index) {
      case 0b0101:
        return 0;
      case 0b0000:
        return __x._M_it - __y._M_it;
      case 0b0001:
        return __x._M_it - __y._M_sent;
      case 0b0100:
        return __x._M_sent - __y._M_it;
      default:
        do {
          if (std::__is_constant_evaluated())
            if (__builtin_expect(!bool(__x._M_has_value()), false))
              std::__glibcxx_assert_fail();
        } while (false);
        do {
          if (std::__is_constant_evaluated())
            if (__builtin_expect(!bool(__y._M_has_value()), false))
              std::__glibcxx_assert_fail();
        } while (false);
        __builtin_unreachable();
      }
    }

    [[nodiscard]]
    friend constexpr iter_rvalue_reference_t<_It>
    iter_move(const common_iterator &__i) noexcept(
        noexcept(ranges::iter_move(std::declval<const _It &>())))
      requires input_iterator<_It>
    {
      do {
        if (std::__is_constant_evaluated())
          if (__builtin_expect(!bool(__i._M_index == 0), false))
            std::__glibcxx_assert_fail();
      } while (false);
      return ranges::iter_move(__i._M_it);
    }

    template <indirectly_swappable<_It> _It2, typename _Sent2>
    friend constexpr void iter_swap(
        const common_iterator &__x,
        const common_iterator<_It2, _Sent2>
            &__y) noexcept(noexcept(ranges::
                                        iter_swap(
                                            std::declval<const _It &>(),
                                            std::declval<const _It2 &>()))) {
      do {
        if (std::__is_constant_evaluated())
          if (__builtin_expect(!bool(__x._M_index == 0), false))
            std::__glibcxx_assert_fail();
      } while (false);
      do {
        if (std::__is_constant_evaluated())
          if (__builtin_expect(!bool(__y._M_index == 0), false))
            std::__glibcxx_assert_fail();
      } while (false);
      return ranges::iter_swap(__x._M_it, __y._M_it);
    }

  private:
    template <input_or_output_iterator _It2, sentinel_for<_It2> _Sent2>
      requires(!same_as<_It2, _Sent2>) && copyable<_It2>
    friend class common_iterator;

    constexpr bool _M_has_value() const noexcept {
      return _M_index != _S_valueless;
    }

    template <typename _CIt> constexpr void _M_assign(_CIt &&__x) {
      if (_M_index == __x._M_index) {
        if (_M_index == 0)
          _M_it = std::forward<_CIt>(__x)._M_it;
        else if (_M_index == 1)
          _M_sent = std::forward<_CIt>(__x)._M_sent;
      } else {
        if (_M_index == 0)
          _M_it.~_It();
        else if (_M_index == 1)
          _M_sent.~_Sent();
        _M_index = _S_valueless;

        if (__x._M_index == 0)
          std::construct_at(std::__addressof(_M_it),
                            std::forward<_CIt>(__x)._M_it);
        else if (__x._M_index == 1)
          std::construct_at(std::__addressof(_M_sent),
                            std::forward<_CIt>(__x)._M_sent);
        _M_index = __x._M_index;
      }
    }

    union {
      _It _M_it;
      _Sent _M_sent;
      unsigned char _M_valueless;
    };
    unsigned char _M_index;

    static constexpr unsigned char _S_valueless{2};
  };

  template <typename _It, typename _Sent>
  struct incrementable_traits<common_iterator<_It, _Sent>> {
    using difference_type = iter_difference_t<_It>;
  };

  template <input_iterator _It, typename _Sent>
  struct iterator_traits<common_iterator<_It, _Sent>> {
  private:
    template <typename _Iter> struct __ptr {
      using type = void;
    };

    template <typename _Iter>
      requires __detail::__common_iter_has_arrow<_Iter>
    struct __ptr<_Iter> {
      using _CIter = common_iterator<_Iter, _Sent>;
      using type = decltype(std::declval<const _CIter &>().operator->());
    };

    static auto _S_iter_cat() {
      if constexpr (requires {
                      requires derived_from<__iter_category_t<_It>,
                                            forward_iterator_tag>;
                    })
        return forward_iterator_tag{};
      else
        return input_iterator_tag{};
    }

  public:
    using iterator_concept =
        __conditional_t<forward_iterator<_It>, forward_iterator_tag,
                        input_iterator_tag>;
    using iterator_category = decltype(_S_iter_cat());
    using value_type = iter_value_t<_It>;
    using difference_type = iter_difference_t<_It>;
    using pointer = typename __ptr<_It>::type;
    using reference = iter_reference_t<_It>;
  };

  namespace __detail {
  template <typename _It> struct __counted_iter_value_type {};

  template <indirectly_readable _It> struct __counted_iter_value_type<_It> {
    using value_type = iter_value_t<_It>;
  };

  template <typename _It> struct __counted_iter_concept {};

  template <typename _It>
    requires requires { typename _It::iterator_concept; }
  struct __counted_iter_concept<_It> {
    using iterator_concept = typename _It::iterator_concept;
  };

  template <typename _It> struct __counted_iter_cat {};

  template <typename _It>
    requires requires { typename _It::iterator_category; }
  struct __counted_iter_cat<_It> {
    using iterator_category = typename _It::iterator_category;
  };
  } // namespace __detail

  template <input_or_output_iterator _It>
  class counted_iterator : public __detail::__counted_iter_value_type<_It>,
                           public __detail::__counted_iter_concept<_It>,
                           public __detail::__counted_iter_cat<_It> {
  public:
    using iterator_type = _It;

    using difference_type = iter_difference_t<_It>;

    constexpr counted_iterator()
      requires default_initializable<_It>
    = default;

    constexpr counted_iterator(_It __i, iter_difference_t<_It> __n)
        : _M_current(std::move(__i)), _M_length(__n) {
      do {
        if (std::__is_constant_evaluated())
          if (__builtin_expect(!bool(__n >= 0), false))
            std::__glibcxx_assert_fail();
      } while (false);
    }

    template <typename _It2>
      requires convertible_to<const _It2 &, _It>
    constexpr counted_iterator(const counted_iterator<_It2> &__x)
        : _M_current(__x._M_current), _M_length(__x._M_length) {}

    template <typename _It2>
      requires assignable_from<_It &, const _It2 &>
    constexpr counted_iterator &operator=(const counted_iterator<_It2> &__x) {
      _M_current = __x._M_current;
      _M_length = __x._M_length;
      return *this;
    }

    [[nodiscard]]
    constexpr const _It &base() const & noexcept {
      return _M_current;
    }

    [[nodiscard]]
    constexpr _It base() && noexcept(is_nothrow_move_constructible_v<_It>) {
      return std::move(_M_current);
    }

    [[nodiscard]]
    constexpr iter_difference_t<_It> count() const noexcept {
      return _M_length;
    }

    [[nodiscard]]
    constexpr decltype(auto) operator*() noexcept(noexcept(*_M_current)) {
      do {
        if (std::__is_constant_evaluated())
          if (__builtin_expect(!bool(_M_length > 0), false))
            std::__glibcxx_assert_fail();
      } while (false);
      return *_M_current;
    }

    [[nodiscard]]
    constexpr decltype(auto) operator*() const noexcept(noexcept(*_M_current))
      requires __detail::__dereferenceable<const _It>
    {
      do {
        if (std::__is_constant_evaluated())
          if (__builtin_expect(!bool(_M_length > 0), false))
            std::__glibcxx_assert_fail();
      } while (false);
      return *_M_current;
    }

    [[nodiscard]]
    constexpr auto operator->() const noexcept
      requires contiguous_iterator<_It>
    {
      return std::to_address(_M_current);
    }

    constexpr counted_iterator &operator++() {
      do {
        if (std::__is_constant_evaluated())
          if (__builtin_expect(!bool(_M_length > 0), false))
            std::__glibcxx_assert_fail();
      } while (false);
      ++_M_current;
      --_M_length;
      return *this;
    }

    constexpr decltype(auto) operator++(int) {
      do {
        if (std::__is_constant_evaluated())
          if (__builtin_expect(!bool(_M_length > 0), false))
            std::__glibcxx_assert_fail();
      } while (false);
      --_M_length;
      try {
        return _M_current++;
      } catch (...) {
        ++_M_length;
        throw;
      }
    }

    constexpr counted_iterator operator++(int)
      requires forward_iterator<_It>
    {
      auto __tmp = *this;
      ++*this;
      return __tmp;
    }

    constexpr counted_iterator &operator--()
      requires bidirectional_iterator<_It>
    {
      --_M_current;
      ++_M_length;
      return *this;
    }

    constexpr counted_iterator operator--(int)
      requires bidirectional_iterator<_It>
    {
      auto __tmp = *this;
      --*this;
      return __tmp;
    }

    [[nodiscard]]
    constexpr counted_iterator operator+(iter_difference_t<_It> __n) const
      requires random_access_iterator<_It>
    {
      return counted_iterator(_M_current + __n, _M_length - __n);
    }

    [[nodiscard]]
    friend constexpr counted_iterator operator+(iter_difference_t<_It> __n,
                                                const counted_iterator &__x)
      requires random_access_iterator<_It>
    {
      return __x + __n;
    }

    constexpr counted_iterator &operator+=(iter_difference_t<_It> __n)
      requires random_access_iterator<_It>
    {
      do {
        if (std::__is_constant_evaluated())
          if (__builtin_expect(!bool(__n <= _M_length), false))
            std::__glibcxx_assert_fail();
      } while (false);
      _M_current += __n;
      _M_length -= __n;
      return *this;
    }

    [[nodiscard]]
    constexpr counted_iterator operator-(iter_difference_t<_It> __n) const
      requires random_access_iterator<_It>
    {
      return counted_iterator(_M_current - __n, _M_length + __n);
    }

    template <common_with<_It> _It2>
    [[nodiscard]]
    friend constexpr iter_difference_t<_It2>
    operator-(const counted_iterator &__x, const counted_iterator<_It2> &__y) {
      return __y._M_length - __x._M_length;
    }

    [[nodiscard]]
    friend constexpr iter_difference_t<_It>
    operator-(const counted_iterator &__x, default_sentinel_t) {
      return -__x._M_length;
    }

    [[nodiscard]]
    friend constexpr iter_difference_t<_It>
    operator-(default_sentinel_t, const counted_iterator &__y) {
      return __y._M_length;
    }

    constexpr counted_iterator &operator-=(iter_difference_t<_It> __n)
      requires random_access_iterator<_It>
    {
      do {
        if (std::__is_constant_evaluated())
          if (__builtin_expect(!bool(-__n <= _M_length), false))
            std::__glibcxx_assert_fail();
      } while (false);
      _M_current -= __n;
      _M_length += __n;
      return *this;
    }

    [[nodiscard]]
    constexpr decltype(auto) operator[](iter_difference_t<_It> __n) const
        noexcept(noexcept(_M_current[__n]))
      requires random_access_iterator<_It>
    {
      do {
        if (std::__is_constant_evaluated())
          if (__builtin_expect(!bool(__n < _M_length), false))
            std::__glibcxx_assert_fail();
      } while (false);
      return _M_current[__n];
    }

    template <common_with<_It> _It2>
    [[nodiscard]]
    friend constexpr bool operator==(const counted_iterator &__x,
                                     const counted_iterator<_It2> &__y) {
      return __x._M_length == __y._M_length;
    }

    [[nodiscard]]
    friend constexpr bool operator==(const counted_iterator &__x,
                                     default_sentinel_t) {
      return __x._M_length == 0;
    }

    template <common_with<_It> _It2>
    [[nodiscard]]
    friend constexpr strong_ordering
    operator<=>(const counted_iterator &__x,
                const counted_iterator<_It2> &__y) {
      return __y._M_length <=> __x._M_length;
    }

    [[nodiscard]]
    friend constexpr iter_rvalue_reference_t<_It>
    iter_move(const counted_iterator &__i) noexcept(
        noexcept(ranges::iter_move(__i._M_current)))
      requires input_iterator<_It>
    {
      do {
        if (std::__is_constant_evaluated())
          if (__builtin_expect(!bool(__i._M_length > 0), false))
            std::__glibcxx_assert_fail();
      } while (false);
      return ranges::iter_move(__i._M_current);
    }

    template <indirectly_swappable<_It> _It2>
    friend constexpr void
    iter_swap(const counted_iterator &__x,
              const counted_iterator<_It2>
                  &__y) noexcept(noexcept(ranges::iter_swap(__x._M_current,
                                                            __y._M_current))) {
      do {
        if (std::__is_constant_evaluated())
          if (__builtin_expect(!bool(__x._M_length > 0 && __y._M_length > 0),
                               false))
            std::__glibcxx_assert_fail();
      } while (false);
      ranges::iter_swap(__x._M_current, __y._M_current);
    }

  private:
    template <input_or_output_iterator _It2> friend class counted_iterator;

    _It _M_current = _It();
    iter_difference_t<_It> _M_length = 0;
  };

  template <input_iterator _It>
    requires same_as<__detail::__iter_traits<_It>, iterator_traits<_It>>
  struct iterator_traits<counted_iterator<_It>> : iterator_traits<_It> {
    using pointer = __conditional_t<contiguous_iterator<_It>,
                                    add_pointer_t<iter_reference_t<_It>>, void>;
  };
  template <typename _Iterator>
  constexpr auto __niter_base(move_iterator<_Iterator> __it)
      -> decltype(make_move_iterator(__niter_base(__it.base()))) {
    return make_move_iterator(__niter_base(__it.base()));
  }

  template <typename _Iterator>
  struct __is_move_iterator<move_iterator<_Iterator>> {
    enum { __value = 1 };
    typedef __true_type __type;
  };

  template <typename _Iterator>
  constexpr auto __miter_base(move_iterator<_Iterator> __it)
      -> decltype(__miter_base(__it.base())) {
    return __miter_base(__it.base());
  }
  template <typename _InputIterator>
  using __iter_key_t = remove_const_t<

      typename iterator_traits<_InputIterator>::value_type::first_type>;

  template <typename _InputIterator>
  using __iter_val_t

      = typename iterator_traits<_InputIterator>::value_type::second_type;

  template <typename _T1, typename _T2> struct pair;

  template <typename _InputIterator>
  using __iter_to_alloc_t =
      pair<const __iter_key_t<_InputIterator>, __iter_val_t<_InputIterator>>;

} // namespace std

namespace __gnu_cxx __attribute__((__visibility__("default"))) {

  template <typename _Tp>
  struct __is_integer_nonstrict : public std::__is_integer<_Tp> {
    using std::__is_integer<_Tp>::__value;

    enum { __width = __value ? sizeof(_Tp) * 8 : 0 };
  };

  template <typename _Value> struct __numeric_traits_integer {

    static_assert(__is_integer_nonstrict<_Value>::__value,
                  "invalid specialization");

    static const bool __is_signed = (_Value)(-1) < 0;
    static const int __digits =
        __is_integer_nonstrict<_Value>::__width - __is_signed;

    static const _Value __max =
        __is_signed ? (((((_Value)1 << (__digits - 1)) - 1) << 1) + 1)
                    : ~(_Value)0;
    static const _Value __min = __is_signed ? -__max - 1 : (_Value)0;
  };

  template <typename _Value>
  const _Value __numeric_traits_integer<_Value>::__min;

  template <typename _Value>
  const _Value __numeric_traits_integer<_Value>::__max;

  template <typename _Value>
  const bool __numeric_traits_integer<_Value>::__is_signed;

  template <typename _Value>
  const int __numeric_traits_integer<_Value>::__digits;
  template <typename _Tp> using __int_traits = __numeric_traits_integer<_Tp>;
  template <typename _Value> struct __numeric_traits_floating {

    static const int __max_digits10 =
        (2 + (std::__are_same<_Value, float>::__value    ? 24
              : std::__are_same<_Value, double>::__value ? 53
                                                         : 64) *
                 643L / 2136);

    static const bool __is_signed = true;
    static const int __digits10 =
        (std::__are_same<_Value, float>::__value    ? 6
         : std::__are_same<_Value, double>::__value ? 15
                                                    : 18);
    static const int __max_exponent10 =
        (std::__are_same<_Value, float>::__value    ? 38
         : std::__are_same<_Value, double>::__value ? 308
                                                    : 4932);
  };

  template <typename _Value>
  const int __numeric_traits_floating<_Value>::__max_digits10;

  template <typename _Value>
  const bool __numeric_traits_floating<_Value>::__is_signed;

  template <typename _Value>
  const int __numeric_traits_floating<_Value>::__digits10;

  template <typename _Value>
  const int __numeric_traits_floating<_Value>::__max_exponent10;

  template <typename _Value>
  struct __numeric_traits : public __numeric_traits_integer<_Value> {};

  template <>
  struct __numeric_traits<float> : public __numeric_traits_floating<float> {};

  template <>
  struct __numeric_traits<double> : public __numeric_traits_floating<double> {};

  template <>
  struct __numeric_traits<long double>
      : public __numeric_traits_floating<long double> {};

} // namespace __gnu_cxx

namespace std __attribute__((__visibility__("default"))) {

  namespace numbers {

  template <typename _Tp>
  using _Enable_if_floating = enable_if_t<is_floating_point_v<_Tp>, _Tp>;

  template <typename _Tp>
  inline constexpr _Tp e_v =
      _Enable_if_floating<_Tp>(2.718281828459045235360287471352662498L);

  template <typename _Tp>
  inline constexpr _Tp log2e_v =
      _Enable_if_floating<_Tp>(1.442695040888963407359924681001892137L);

  template <typename _Tp>
  inline constexpr _Tp log10e_v =
      _Enable_if_floating<_Tp>(0.434294481903251827651128918916605082L);

  template <typename _Tp>
  inline constexpr _Tp pi_v =
      _Enable_if_floating<_Tp>(3.141592653589793238462643383279502884L);

  template <typename _Tp>
  inline constexpr _Tp inv_pi_v =
      _Enable_if_floating<_Tp>(0.318309886183790671537767526745028724L);

  template <typename _Tp>
  inline constexpr _Tp inv_sqrtpi_v =
      _Enable_if_floating<_Tp>(0.564189583547756286948079451560772586L);

  template <typename _Tp>
  inline constexpr _Tp ln2_v =
      _Enable_if_floating<_Tp>(0.693147180559945309417232121458176568L);

  template <typename _Tp>
  inline constexpr _Tp ln10_v =
      _Enable_if_floating<_Tp>(2.302585092994045684017991454684364208L);

  template <typename _Tp>
  inline constexpr _Tp sqrt2_v =
      _Enable_if_floating<_Tp>(1.414213562373095048801688724209698079L);

  template <typename _Tp>
  inline constexpr _Tp sqrt3_v =
      _Enable_if_floating<_Tp>(1.732050807568877293527446341505872367L);

  template <typename _Tp>
  inline constexpr _Tp inv_sqrt3_v =
      _Enable_if_floating<_Tp>(0.577350269189625764509148780501957456L);

  template <typename _Tp>
  inline constexpr _Tp egamma_v =
      _Enable_if_floating<_Tp>(0.577215664901532860606512090082402431L);

  template <typename _Tp>
  inline constexpr _Tp phi_v =
      _Enable_if_floating<_Tp>(1.618033988749894848204586834365638118L);

  inline constexpr double e = e_v<double>;
  inline constexpr double log2e = log2e_v<double>;
  inline constexpr double log10e = log10e_v<double>;
  inline constexpr double pi = pi_v<double>;
  inline constexpr double inv_pi = inv_pi_v<double>;
  inline constexpr double inv_sqrtpi = inv_sqrtpi_v<double>;
  inline constexpr double ln2 = ln2_v<double>;
  inline constexpr double ln10 = ln10_v<double>;
  inline constexpr double sqrt2 = sqrt2_v<double>;
  inline constexpr double sqrt3 = sqrt3_v<double>;
  inline constexpr double inv_sqrt3 = inv_sqrt3_v<double>;
  inline constexpr double egamma = egamma_v<double>;
  inline constexpr double phi = phi_v<double>;
  template <>
  inline constexpr __float128 e_v<__float128> =
      2.718281828459045235360287471352662498Q;
  template <>
  inline constexpr __float128 log2e_v<__float128> =
      1.442695040888963407359924681001892137Q;
  template <>
  inline constexpr __float128 log10e_v<__float128> =
      0.434294481903251827651128918916605082Q;
  template <>
  inline constexpr __float128 pi_v<__float128> =
      3.141592653589793238462643383279502884Q;
  template <>
  inline constexpr __float128 inv_pi_v<__float128> =
      0.318309886183790671537767526745028724Q;
  template <>
  inline constexpr __float128 inv_sqrtpi_v<__float128> =
      0.564189583547756286948079451560772586Q;
  template <>
  inline constexpr __float128 ln2_v<__float128> =
      0.693147180559945309417232121458176568Q;
  template <>
  inline constexpr __float128 ln10_v<__float128> =
      2.302585092994045684017991454684364208Q;
  template <>
  inline constexpr __float128 sqrt2_v<__float128> =
      1.414213562373095048801688724209698079Q;
  template <>
  inline constexpr __float128 sqrt3_v<__float128> =
      1.732050807568877293527446341505872367Q;
  template <>
  inline constexpr __float128 inv_sqrt3_v<__float128> =
      0.577350269189625764509148780501957456Q;
  template <>
  inline constexpr __float128 egamma_v<__float128> =
      0.577215664901532860606512090082402431Q;
  template <>
  inline constexpr __float128 phi_v<__float128> =
      1.618033988749894848204586834365638118Q;

  } // namespace numbers

} // namespace std
namespace std __attribute__((__visibility__("default"))) {

  template <typename _Tp> struct numeric_limits;

  namespace ranges {
  namespace __detail {
  class __max_size_type {
  public:
    __max_size_type() = default;

    template <typename _Tp>
      requires integral<_Tp> || __is_int128<_Tp>
    constexpr __max_size_type(_Tp __i) noexcept
        : _M_val(__i), _M_msb(__i < 0) {}

    constexpr explicit __max_size_type(const __max_diff_type &__d) noexcept;

    template <typename _Tp>
      requires integral<_Tp> || __is_int128<_Tp>
    constexpr explicit operator _Tp() const noexcept {
      return _M_val;
    }

    constexpr explicit operator bool() const noexcept {
      return _M_val != 0 || _M_msb != 0;
    }

    constexpr __max_size_type operator+() const noexcept { return *this; }

    constexpr __max_size_type operator~() const noexcept {
      return __max_size_type{~_M_val, !_M_msb};
    }

    constexpr __max_size_type operator-() const noexcept {
      return operator~() + 1;
    }

    constexpr __max_size_type &operator++() noexcept { return *this += 1; }

    constexpr __max_size_type operator++(int) noexcept {
      auto __tmp = *this;
      ++*this;
      return __tmp;
    }

    constexpr __max_size_type &operator--() noexcept { return *this -= 1; }

    constexpr __max_size_type operator--(int) noexcept {
      auto __tmp = *this;
      --*this;
      return __tmp;
    }

    constexpr __max_size_type &operator+=(const __max_size_type &__r) noexcept {
      const auto __sum = _M_val + __r._M_val;
      const bool __overflow = (__sum < _M_val);
      _M_msb = _M_msb ^ __r._M_msb ^ __overflow;
      _M_val = __sum;
      return *this;
    }

    constexpr __max_size_type &operator-=(const __max_size_type &__r) noexcept {
      return *this += -__r;
    }

    constexpr __max_size_type &operator*=(__max_size_type __r) noexcept {
      constexpr __max_size_type __threshold = __rep(1) << (_S_rep_bits / 2 - 1);
      if (_M_val < __threshold && __r < __threshold)

        _M_val = _M_val * __r._M_val;
      else {

        const bool __lsb = _M_val & 1;
        const bool __rlsb = __r._M_val & 1;
        *this >>= 1;
        __r >>= 1;
        _M_val =
            (2 * _M_val * __r._M_val + _M_val * __rlsb + __r._M_val * __lsb);
        *this <<= 1;
        *this += __rlsb * __lsb;
      }

      return *this;
    }

    constexpr __max_size_type &operator/=(const __max_size_type &__r) noexcept {
      do {
        if (std::__is_constant_evaluated())
          if (__builtin_expect(!bool(__r != 0), false))
            std::__glibcxx_assert_fail();
      } while (false);

      if (!_M_msb && !__r._M_msb) [[likely]]
        _M_val /= __r._M_val;
      else if (_M_msb && __r._M_msb) {
        _M_val = (_M_val >= __r._M_val);
        _M_msb = 0;
      } else if (!_M_msb && __r._M_msb)
        _M_val = 0;
      else if (_M_msb && !__r._M_msb) {

        const auto __orig = *this;
        *this >>= 1;
        _M_val /= __r._M_val;
        *this <<= 1;
        if (__orig - *this * __r >= __r)
          ++_M_val;
      }
      return *this;
    }

    constexpr __max_size_type &operator%=(const __max_size_type &__r) noexcept {
      if (!_M_msb && !__r._M_msb) [[likely]]
        _M_val %= __r._M_val;
      else
        *this -= (*this / __r) * __r;
      return *this;
    }

    constexpr __max_size_type &
    operator<<=(const __max_size_type &__r) noexcept {
      do {
        if (std::__is_constant_evaluated())
          if (__builtin_expect(!bool(__r <= _S_rep_bits), false))
            std::__glibcxx_assert_fail();
      } while (false);
      if (__r != 0) {
        _M_msb = (_M_val >> (_S_rep_bits - __r._M_val)) & 1;

        if (__r._M_val == _S_rep_bits) [[unlikely]]
          _M_val = 0;
        else
          _M_val <<= __r._M_val;
      }
      return *this;
    }

    constexpr __max_size_type &
    operator>>=(const __max_size_type &__r) noexcept {
      do {
        if (std::__is_constant_evaluated())
          if (__builtin_expect(!bool(__r <= _S_rep_bits), false))
            std::__glibcxx_assert_fail();
      } while (false);
      if (__r != 0) {
        if (__r._M_val == _S_rep_bits) [[unlikely]]
          _M_val = 0;
        else
          _M_val >>= __r._M_val;

        if (_M_msb) [[unlikely]] {
          _M_val |= __rep(1) << (_S_rep_bits - __r._M_val);
          _M_msb = 0;
        }
      }
      return *this;
    }

    constexpr __max_size_type &operator&=(const __max_size_type &__r) noexcept {
      _M_val &= __r._M_val;
      _M_msb &= __r._M_msb;
      return *this;
    }

    constexpr __max_size_type &operator|=(const __max_size_type &__r) noexcept {
      _M_val |= __r._M_val;
      _M_msb |= __r._M_msb;
      return *this;
    }

    constexpr __max_size_type &operator^=(const __max_size_type &__r) noexcept {
      _M_val ^= __r._M_val;
      _M_msb ^= __r._M_msb;
      return *this;
    }

    template <typename _Tp>
      requires integral<_Tp> || __is_int128<_Tp>
    friend constexpr _Tp &operator+=(_Tp &__a,
                                     const __max_size_type &__b) noexcept {
      return (__a = static_cast<_Tp>(__a + __b));
    }

    template <typename _Tp>
      requires integral<_Tp> || __is_int128<_Tp>
    friend constexpr _Tp &operator-=(_Tp &__a,
                                     const __max_size_type &__b) noexcept {
      return (__a = static_cast<_Tp>(__a - __b));
    }

    template <typename _Tp>
      requires integral<_Tp> || __is_int128<_Tp>
    friend constexpr _Tp &operator*=(_Tp &__a,
                                     const __max_size_type &__b) noexcept {
      return (__a = static_cast<_Tp>(__a * __b));
    }

    template <typename _Tp>
      requires integral<_Tp> || __is_int128<_Tp>
    friend constexpr _Tp &operator/=(_Tp &__a,
                                     const __max_size_type &__b) noexcept {
      return (__a = static_cast<_Tp>(__a / __b));
    }

    template <typename _Tp>
      requires integral<_Tp> || __is_int128<_Tp>
    friend constexpr _Tp &operator%=(_Tp &__a,
                                     const __max_size_type &__b) noexcept {
      return (__a = static_cast<_Tp>(__a % __b));
    }

    template <typename _Tp>
      requires integral<_Tp> || __is_int128<_Tp>
    friend constexpr _Tp &operator&=(_Tp &__a,
                                     const __max_size_type &__b) noexcept {
      return (__a = static_cast<_Tp>(__a & __b));
    }

    template <typename _Tp>
      requires integral<_Tp> || __is_int128<_Tp>
    friend constexpr _Tp &operator|=(_Tp &__a,
                                     const __max_size_type &__b) noexcept {
      return (__a = static_cast<_Tp>(__a | __b));
    }

    template <typename _Tp>
      requires integral<_Tp> || __is_int128<_Tp>
    friend constexpr _Tp &operator^=(_Tp &__a,
                                     const __max_size_type &__b) noexcept {
      return (__a = static_cast<_Tp>(__a ^ __b));
    }

    template <typename _Tp>
      requires integral<_Tp> || __is_int128<_Tp>
    friend constexpr _Tp &operator<<=(_Tp &__a,
                                      const __max_size_type &__b) noexcept {
      return (__a = static_cast<_Tp>(__a << __b));
    }

    template <typename _Tp>
      requires integral<_Tp> || __is_int128<_Tp>
    friend constexpr _Tp &operator>>=(_Tp &__a,
                                      const __max_size_type &__b) noexcept {
      return (__a = static_cast<_Tp>(__a >> __b));
    }

    friend constexpr __max_size_type
    operator+(__max_size_type __l, const __max_size_type &__r) noexcept {
      __l += __r;
      return __l;
    }

    friend constexpr __max_size_type
    operator-(__max_size_type __l, const __max_size_type &__r) noexcept {
      __l -= __r;
      return __l;
    }

    friend constexpr __max_size_type
    operator*(__max_size_type __l, const __max_size_type &__r) noexcept {
      __l *= __r;
      return __l;
    }

    friend constexpr __max_size_type
    operator/(__max_size_type __l, const __max_size_type &__r) noexcept {
      __l /= __r;
      return __l;
    }

    friend constexpr __max_size_type
    operator%(__max_size_type __l, const __max_size_type &__r) noexcept {
      __l %= __r;
      return __l;
    }

    friend constexpr __max_size_type
    operator<<(__max_size_type __l, const __max_size_type &__r) noexcept {
      __l <<= __r;
      return __l;
    }

    friend constexpr __max_size_type
    operator>>(__max_size_type __l, const __max_size_type &__r) noexcept {
      __l >>= __r;
      return __l;
    }

    friend constexpr __max_size_type
    operator&(__max_size_type __l, const __max_size_type &__r) noexcept {
      __l &= __r;
      return __l;
    }

    friend constexpr __max_size_type
    operator|(__max_size_type __l, const __max_size_type &__r) noexcept {
      __l |= __r;
      return __l;
    }

    friend constexpr __max_size_type
    operator^(__max_size_type __l, const __max_size_type &__r) noexcept {
      __l ^= __r;
      return __l;
    }

    friend constexpr bool operator==(const __max_size_type &__l,
                                     const __max_size_type &__r) noexcept {
      return __l._M_val == __r._M_val && __l._M_msb == __r._M_msb;
    }

    friend constexpr strong_ordering
    operator<=>(const __max_size_type &__l,
                const __max_size_type &__r) noexcept {
      if (__l._M_msb ^ __r._M_msb)
        return __l._M_msb ? strong_ordering::greater : strong_ordering::less;
      else
        return __l._M_val <=> __r._M_val;
    }
    __extension__ using __rep = unsigned __int128;

    static constexpr size_t _S_rep_bits = sizeof(__rep) * 8;

  private:
    __rep _M_val = 0;
    unsigned _M_msb : 1 = 0;

    constexpr explicit __max_size_type(__rep __val, int __msb) noexcept
        : _M_val(__val), _M_msb(__msb) {}

    friend __max_diff_type;
    friend std::numeric_limits<__max_size_type>;
    friend std::numeric_limits<__max_diff_type>;
  };

  class __max_diff_type {
  public:
    __max_diff_type() = default;

    template <typename _Tp>
      requires integral<_Tp> || __is_int128<_Tp>
    constexpr __max_diff_type(_Tp __i) noexcept : _M_rep(__i) {}

    constexpr explicit __max_diff_type(const __max_size_type &__d) noexcept
        : _M_rep(__d) {}

    template <typename _Tp>
      requires integral<_Tp> || __is_int128<_Tp>
    constexpr explicit operator _Tp() const noexcept {
      return static_cast<_Tp>(_M_rep);
    }

    constexpr explicit operator bool() const noexcept { return _M_rep != 0; }

    constexpr __max_diff_type operator+() const noexcept { return *this; }

    constexpr __max_diff_type operator-() const noexcept {
      return __max_diff_type(-_M_rep);
    }

    constexpr __max_diff_type operator~() const noexcept {
      return __max_diff_type(~_M_rep);
    }

    constexpr __max_diff_type &operator++() noexcept { return *this += 1; }

    constexpr __max_diff_type operator++(int) noexcept {
      auto __tmp = *this;
      ++*this;
      return __tmp;
    }

    constexpr __max_diff_type &operator--() noexcept { return *this -= 1; }

    constexpr __max_diff_type operator--(int) noexcept {
      auto __tmp = *this;
      --*this;
      return __tmp;
    }

    constexpr __max_diff_type &operator+=(const __max_diff_type &__r) noexcept {
      _M_rep += __r._M_rep;
      return *this;
    }

    constexpr __max_diff_type &operator-=(const __max_diff_type &__r) noexcept {
      _M_rep -= __r._M_rep;
      return *this;
    }

    constexpr __max_diff_type &operator*=(const __max_diff_type &__r) noexcept {
      _M_rep *= __r._M_rep;
      return *this;
    }

    constexpr __max_diff_type &operator/=(const __max_diff_type &__r) noexcept {
      do {
        if (std::__is_constant_evaluated())
          if (__builtin_expect(!bool(__r != 0), false))
            std::__glibcxx_assert_fail();
      } while (false);
      const bool __neg = *this < 0;
      const bool __rneg = __r < 0;
      if (!__neg && !__rneg)
        _M_rep = _M_rep / __r._M_rep;
      else if (__neg && __rneg)
        _M_rep = -_M_rep / -__r._M_rep;
      else if (__neg && !__rneg)
        _M_rep = -(-_M_rep / __r._M_rep);
      else
        _M_rep = -(_M_rep / -__r._M_rep);
      return *this;
    }

    constexpr __max_diff_type &operator%=(const __max_diff_type &__r) noexcept {
      do {
        if (std::__is_constant_evaluated())
          if (__builtin_expect(!bool(__r != 0), false))
            std::__glibcxx_assert_fail();
      } while (false);
      if (*this >= 0 && __r > 0)
        _M_rep %= __r._M_rep;
      else
        *this -= (*this / __r) * __r;
      return *this;
    }

    constexpr __max_diff_type &
    operator<<=(const __max_diff_type &__r) noexcept {
      _M_rep.operator<<=(__r._M_rep);
      return *this;
    }

    constexpr __max_diff_type &
    operator>>=(const __max_diff_type &__r) noexcept {

      const auto __msb = _M_rep._M_msb;
      _M_rep >>= __r._M_rep;
      if (__msb)
        _M_rep |= ~(__max_size_type(-1) >> __r._M_rep);
      return *this;
    }

    constexpr __max_diff_type &operator&=(const __max_diff_type &__r) noexcept {
      _M_rep &= __r._M_rep;
      return *this;
    }

    constexpr __max_diff_type &operator|=(const __max_diff_type &__r) noexcept {
      _M_rep |= __r._M_rep;
      return *this;
    }

    constexpr __max_diff_type &operator^=(const __max_diff_type &__r) noexcept {
      _M_rep ^= __r._M_rep;
      return *this;
    }

    template <typename _Tp>
      requires integral<_Tp> || __is_int128<_Tp>
    friend constexpr _Tp &operator+=(_Tp &__a,
                                     const __max_diff_type &__b) noexcept {
      return (__a = static_cast<_Tp>(__a + __b));
    }

    template <typename _Tp>
      requires integral<_Tp> || __is_int128<_Tp>
    friend constexpr _Tp &operator-=(_Tp &__a,
                                     const __max_diff_type &__b) noexcept {
      return (__a = static_cast<_Tp>(__a - __b));
    }

    template <typename _Tp>
      requires integral<_Tp> || __is_int128<_Tp>
    friend constexpr _Tp &operator*=(_Tp &__a,
                                     const __max_diff_type &__b) noexcept {
      return (__a = static_cast<_Tp>(__a * __b));
    }

    template <typename _Tp>
      requires integral<_Tp> || __is_int128<_Tp>
    friend constexpr _Tp &operator/=(_Tp &__a,
                                     const __max_diff_type &__b) noexcept {
      return (__a = static_cast<_Tp>(__a / __b));
    }

    template <typename _Tp>
      requires integral<_Tp> || __is_int128<_Tp>
    friend constexpr _Tp &operator%=(_Tp &__a,
                                     const __max_diff_type &__b) noexcept {
      return (__a = static_cast<_Tp>(__a % __b));
    }

    template <typename _Tp>
      requires integral<_Tp> || __is_int128<_Tp>
    friend constexpr _Tp &operator&=(_Tp &__a,
                                     const __max_diff_type &__b) noexcept {
      return (__a = static_cast<_Tp>(__a & __b));
    }

    template <typename _Tp>
      requires integral<_Tp> || __is_int128<_Tp>
    friend constexpr _Tp &operator|=(_Tp &__a,
                                     const __max_diff_type &__b) noexcept {
      return (__a = static_cast<_Tp>(__a | __b));
    }

    template <typename _Tp>
      requires integral<_Tp> || __is_int128<_Tp>
    friend constexpr _Tp &operator^=(_Tp &__a,
                                     const __max_diff_type &__b) noexcept {
      return (__a = static_cast<_Tp>(__a ^ __b));
    }

    template <typename _Tp>
      requires integral<_Tp> || __is_int128<_Tp>
    friend constexpr _Tp &operator<<=(_Tp &__a,
                                      const __max_diff_type &__b) noexcept {
      return (__a = static_cast<_Tp>(__a << __b));
    }

    template <typename _Tp>
      requires integral<_Tp> || __is_int128<_Tp>
    friend constexpr _Tp &operator>>=(_Tp &__a,
                                      const __max_diff_type &__b) noexcept {
      return (__a = static_cast<_Tp>(__a >> __b));
    }

    friend constexpr __max_diff_type
    operator+(__max_diff_type __l, const __max_diff_type &__r) noexcept {
      __l += __r;
      return __l;
    }

    friend constexpr __max_diff_type
    operator-(__max_diff_type __l, const __max_diff_type &__r) noexcept {
      __l -= __r;
      return __l;
    }

    friend constexpr __max_diff_type
    operator*(__max_diff_type __l, const __max_diff_type &__r) noexcept {
      __l *= __r;
      return __l;
    }

    friend constexpr __max_diff_type
    operator/(__max_diff_type __l, const __max_diff_type &__r) noexcept {
      __l /= __r;
      return __l;
    }

    friend constexpr __max_diff_type
    operator%(__max_diff_type __l, const __max_diff_type &__r) noexcept {
      __l %= __r;
      return __l;
    }

    friend constexpr __max_diff_type
    operator<<(__max_diff_type __l, const __max_diff_type &__r) noexcept {
      __l <<= __r;
      return __l;
    }

    friend constexpr __max_diff_type
    operator>>(__max_diff_type __l, const __max_diff_type &__r) noexcept {
      __l >>= __r;
      return __l;
    }

    friend constexpr __max_diff_type
    operator&(__max_diff_type __l, const __max_diff_type &__r) noexcept {
      __l &= __r;
      return __l;
    }

    friend constexpr __max_diff_type
    operator|(__max_diff_type __l, const __max_diff_type &__r) noexcept {
      __l |= __r;
      return __l;
    }

    friend constexpr __max_diff_type
    operator^(__max_diff_type __l, const __max_diff_type &__r) noexcept {
      __l ^= __r;
      return __l;
    }

    friend constexpr bool operator==(const __max_diff_type &__l,
                                     const __max_diff_type &__r) noexcept {
      return __l._M_rep == __r._M_rep;
    }

    constexpr strong_ordering
    operator<=>(const __max_diff_type &__r) const noexcept {
      const auto __lsign = _M_rep._M_msb;
      const auto __rsign = __r._M_rep._M_msb;
      if (__lsign ^ __rsign)
        return __lsign ? strong_ordering::less : strong_ordering::greater;
      else
        return _M_rep <=> __r._M_rep;
    }

  private:
    __max_size_type _M_rep = 0;

    friend class __max_size_type;
  };

  constexpr __max_size_type::__max_size_type(
      const __max_diff_type &__d) noexcept
      : __max_size_type(__d._M_rep) {}

  } // namespace __detail
  } // namespace ranges

  template <> struct numeric_limits<ranges::__detail::__max_size_type> {
    using _Sp = ranges::__detail::__max_size_type;
    static constexpr bool is_specialized = true;
    static constexpr bool is_signed = false;
    static constexpr bool is_integer = true;
    static constexpr bool is_exact = true;
    static constexpr int digits =
        __gnu_cxx::__int_traits<_Sp::__rep>::__digits + 1;
    static constexpr int digits10 =
        static_cast<int>(digits * numbers::ln2 / numbers::ln10);

    static constexpr _Sp min() noexcept { return 0; }

    static constexpr _Sp max() noexcept {
      return _Sp(static_cast<_Sp::__rep>(-1), 1);
    }

    static constexpr _Sp lowest() noexcept { return min(); }
  };

  template <> struct numeric_limits<ranges::__detail::__max_diff_type> {
    using _Dp = ranges::__detail::__max_diff_type;
    using _Sp = ranges::__detail::__max_size_type;
    static constexpr bool is_specialized = true;
    static constexpr bool is_signed = true;
    static constexpr bool is_integer = true;
    static constexpr bool is_exact = true;
    static constexpr int digits = numeric_limits<_Sp>::digits - 1;
    static constexpr int digits10 =
        static_cast<int>(digits * numbers::ln2 / numbers::ln10);

    static constexpr _Dp min() noexcept { return _Dp(_Sp(0, 1)); }

    static constexpr _Dp max() noexcept {
      return _Dp(_Sp(static_cast<_Sp::__rep>(-1), 0));
    }

    static constexpr _Dp lowest() noexcept { return min(); }
  };

} // namespace std

namespace std __attribute__((__visibility__("default"))) {

  namespace ranges {
  template <typename> inline constexpr bool disable_sized_range = false;

  template <typename _Tp> inline constexpr bool enable_borrowed_range = false;

  namespace __detail {
  constexpr __max_size_type __to_unsigned_like(__max_size_type __t) noexcept {
    return __t;
  }

  constexpr __max_size_type __to_unsigned_like(__max_diff_type __t) noexcept {
    return __max_size_type(__t);
  }

  template <integral _Tp> constexpr auto __to_unsigned_like(_Tp __t) noexcept {
    return static_cast<make_unsigned_t<_Tp>>(__t);
  }
  template <typename _Tp>
  using __make_unsigned_like_t =
      decltype(__detail::__to_unsigned_like(std::declval<_Tp>()));

  template <typename _Tp>
  concept __maybe_borrowed_range =
      is_lvalue_reference_v<_Tp> || enable_borrowed_range<remove_cvref_t<_Tp>>;

  } // namespace __detail

  namespace __access {
  using std::__detail::__range_iter_t;
  using std::ranges::__detail::__maybe_borrowed_range;

  struct _Begin {
  private:
    template <typename _Tp> static constexpr bool _S_noexcept() {
      if constexpr (is_array_v<remove_reference_t<_Tp>>)
        return true;
      else if constexpr (__member_begin<_Tp>)
        return noexcept(__decay_copy(std::declval<_Tp &>().begin()));
      else
        return noexcept(__decay_copy(begin(std::declval<_Tp &>())));
    }

  public:
    template <__maybe_borrowed_range _Tp>
      requires is_array_v<remove_reference_t<_Tp>> || __member_begin<_Tp> ||
               __adl_begin<_Tp>
    constexpr auto operator() [[nodiscard]] (_Tp &&__t) const
        noexcept(_S_noexcept<_Tp &>()) {
      if constexpr (is_array_v<remove_reference_t<_Tp>>) {
        static_assert(is_lvalue_reference_v<_Tp>);
        return __t + 0;
      } else if constexpr (__member_begin<_Tp>)
        return __t.begin();
      else
        return begin(__t);
    }
  };

  template <typename _Tp>
  concept __member_end = requires(_Tp &__t) {
    { __decay_copy(__t.end()) } -> sentinel_for<__range_iter_t<_Tp>>;
  };

  void end() = delete;

  template <typename _Tp>
  concept __adl_end =
      __class_or_enum<remove_reference_t<_Tp>> && requires(_Tp &__t) {
        { __decay_copy(end(__t)) } -> sentinel_for<__range_iter_t<_Tp>>;
      };

  struct _End {
  private:
    template <typename _Tp> static constexpr bool _S_noexcept() {
      if constexpr (is_bounded_array_v<remove_reference_t<_Tp>>)
        return true;
      else if constexpr (__member_end<_Tp>)
        return noexcept(__decay_copy(std::declval<_Tp &>().end()));
      else
        return noexcept(__decay_copy(end(std::declval<_Tp &>())));
    }

  public:
    template <__maybe_borrowed_range _Tp>
      requires is_bounded_array_v<remove_reference_t<_Tp>> ||
               __member_end<_Tp> || __adl_end<_Tp>
    constexpr auto operator() [[nodiscard]] (_Tp &&__t) const
        noexcept(_S_noexcept<_Tp &>()) {
      if constexpr (is_bounded_array_v<remove_reference_t<_Tp>>) {
        static_assert(is_lvalue_reference_v<_Tp>);
        return __t + extent_v<remove_reference_t<_Tp>>;
      } else if constexpr (__member_end<_Tp>)
        return __t.end();
      else
        return end(__t);
    }
  };

  template <typename _Tp>
  concept __member_rbegin = requires(_Tp &__t) {
    { __decay_copy(__t.rbegin()) } -> input_or_output_iterator;
  };

  void rbegin() = delete;

  template <typename _Tp>
  concept __adl_rbegin =
      __class_or_enum<remove_reference_t<_Tp>> && requires(_Tp &__t) {
        { __decay_copy(rbegin(__t)) } -> input_or_output_iterator;
      };

  template <typename _Tp>
  concept __reversable = requires(_Tp &__t) {
    { _Begin{}(__t) } -> bidirectional_iterator;
    { _End{}(__t) } -> same_as<decltype(_Begin{}(__t))>;
  };

  struct _RBegin {
  private:
    template <typename _Tp> static constexpr bool _S_noexcept() {
      if constexpr (__member_rbegin<_Tp>)
        return noexcept(__decay_copy(std::declval<_Tp &>().rbegin()));
      else if constexpr (__adl_rbegin<_Tp>)
        return noexcept(__decay_copy(rbegin(std::declval<_Tp &>())));
      else {
        if constexpr (noexcept(_End{}(std::declval<_Tp &>()))) {
          using _It = decltype(_End{}(std::declval<_Tp &>()));

          return is_nothrow_copy_constructible_v<_It>;
        } else
          return false;
      }
    }

  public:
    template <__maybe_borrowed_range _Tp>
      requires __member_rbegin<_Tp> || __adl_rbegin<_Tp> || __reversable<_Tp>
    constexpr auto operator() [[nodiscard]] (_Tp &&__t) const
        noexcept(_S_noexcept<_Tp &>()) {
      if constexpr (__member_rbegin<_Tp>)
        return __t.rbegin();
      else if constexpr (__adl_rbegin<_Tp>)
        return rbegin(__t);
      else
        return std::make_reverse_iterator(_End{}(__t));
    }
  };

  template <typename _Tp>
  concept __member_rend = requires(_Tp &__t) {
    {
      __decay_copy(__t.rend())
    } -> sentinel_for<decltype(_RBegin{}(std::forward<_Tp>(__t)))>;
  };

  void rend() = delete;

  template <typename _Tp>
  concept __adl_rend =
      __class_or_enum<remove_reference_t<_Tp>> && requires(_Tp &__t) {
        {
          __decay_copy(rend(__t))
        } -> sentinel_for<decltype(_RBegin{}(std::forward<_Tp>(__t)))>;
      };

  struct _REnd {
  private:
    template <typename _Tp> static constexpr bool _S_noexcept() {
      if constexpr (__member_rend<_Tp>)
        return noexcept(__decay_copy(std::declval<_Tp &>().rend()));
      else if constexpr (__adl_rend<_Tp>)
        return noexcept(__decay_copy(rend(std::declval<_Tp &>())));
      else {
        if constexpr (noexcept(_Begin{}(std::declval<_Tp &>()))) {
          using _It = decltype(_Begin{}(std::declval<_Tp &>()));

          return is_nothrow_copy_constructible_v<_It>;
        } else
          return false;
      }
    }

  public:
    template <__maybe_borrowed_range _Tp>
      requires __member_rend<_Tp> || __adl_rend<_Tp> || __reversable<_Tp>
    constexpr auto operator() [[nodiscard]] (_Tp &&__t) const
        noexcept(_S_noexcept<_Tp &>()) {
      if constexpr (__member_rend<_Tp>)
        return __t.rend();
      else if constexpr (__adl_rend<_Tp>)
        return rend(__t);
      else
        return std::make_reverse_iterator(_Begin{}(__t));
    }
  };

  template <typename _Tp>
  concept __member_size =
      !disable_sized_range<remove_cvref_t<_Tp>> && requires(_Tp &__t) {
        { __decay_copy(__t.size()) } -> __detail::__is_integer_like;
      };

  void size() = delete;

  template <typename _Tp>
  concept __adl_size =
      __class_or_enum<remove_reference_t<_Tp>> &&
      !disable_sized_range<remove_cvref_t<_Tp>> && requires(_Tp &__t) {
        { __decay_copy(size(__t)) } -> __detail::__is_integer_like;
      };

  template <typename _Tp>
  concept __sentinel_size = requires(_Tp &__t) {
    requires(!is_unbounded_array_v<remove_reference_t<_Tp>>);

    { _Begin{}(__t) } -> forward_iterator;

    { _End{}(__t) } -> sized_sentinel_for<decltype(_Begin{}(__t))>;

    __detail::__to_unsigned_like(_End{}(__t)-_Begin{}(__t));
  };

  struct _Size {
  private:
    template <typename _Tp> static constexpr bool _S_noexcept() {
      if constexpr (is_bounded_array_v<remove_reference_t<_Tp>>)
        return true;
      else if constexpr (__member_size<_Tp>)
        return noexcept(__decay_copy(std::declval<_Tp &>().size()));
      else if constexpr (__adl_size<_Tp>)
        return noexcept(__decay_copy(size(std::declval<_Tp &>())));
      else if constexpr (__sentinel_size<_Tp>)
        return noexcept(_End{}(std::declval<_Tp &>()) -
                        _Begin{}(std::declval<_Tp &>()));
    }

  public:
    template <typename _Tp>
      requires is_bounded_array_v<remove_reference_t<_Tp>> ||
               __member_size<_Tp> || __adl_size<_Tp> || __sentinel_size<_Tp>
    constexpr auto operator() [[nodiscard]] (_Tp &&__t) const
        noexcept(_S_noexcept<_Tp &>()) {
      if constexpr (is_bounded_array_v<remove_reference_t<_Tp>>)
        return extent_v<remove_reference_t<_Tp>>;
      else if constexpr (__member_size<_Tp>)
        return __t.size();
      else if constexpr (__adl_size<_Tp>)
        return size(__t);
      else if constexpr (__sentinel_size<_Tp>)
        return __detail::__to_unsigned_like(_End{}(__t)-_Begin{}(__t));
    }
  };

  struct _SSize {

    template <typename _Tp>
      requires requires(_Tp &__t) { _Size{}(__t); }
    constexpr auto operator() [[nodiscard]] (_Tp &&__t) const
        noexcept(noexcept(_Size{}(__t))) {
      auto __size = _Size{}(__t);
      using __size_type = decltype(__size);

      if constexpr (integral<__size_type>) {
        using __gnu_cxx::__int_traits;
        if constexpr (__int_traits<__size_type>::__digits <
                      __int_traits<ptrdiff_t>::__digits)
          return static_cast<ptrdiff_t>(__size);
        else
          return static_cast<make_signed_t<__size_type>>(__size);
      }

      else
        return __detail::__max_diff_type(__size);
    }
  };

  template <typename _Tp>
  concept __member_empty = requires(_Tp &__t) { bool(__t.empty()); };

  template <typename _Tp>
  concept __size0_empty = requires(_Tp &__t) { _Size{}(__t) == 0; };

  template <typename _Tp>
  concept __eq_iter_empty = requires(_Tp &__t) {
    requires(!is_unbounded_array_v<remove_reference_t<_Tp>>);

    { _Begin{}(__t) } -> forward_iterator;

    bool(_Begin{}(__t) == _End{}(__t));
  };

  struct _Empty {
  private:
    template <typename _Tp> static constexpr bool _S_noexcept() {
      if constexpr (__member_empty<_Tp>)
        return noexcept(bool(std::declval<_Tp &>().empty()));
      else if constexpr (__size0_empty<_Tp>)
        return noexcept(_Size{}(std::declval<_Tp &>()) == 0);
      else
        return noexcept(bool(_Begin{}(std::declval<_Tp &>()) ==
                             _End{}(std::declval<_Tp &>())));
    }

  public:
    template <typename _Tp>
      requires __member_empty<_Tp> || __size0_empty<_Tp> || __eq_iter_empty<_Tp>
    constexpr bool operator() [[nodiscard]] (_Tp &&__t) const
        noexcept(_S_noexcept<_Tp &>()) {
      if constexpr (__member_empty<_Tp>)
        return bool(__t.empty());
      else if constexpr (__size0_empty<_Tp>)
        return _Size{}(__t) == 0;
      else
        return bool(_Begin{}(__t) == _End{}(__t));
    }
  };

  template <typename _Tp>
  concept __pointer_to_object =
      is_pointer_v<_Tp> && is_object_v<remove_pointer_t<_Tp>>;

  template <typename _Tp>
  concept __member_data = requires(_Tp &__t) {
    { __decay_copy(__t.data()) } -> __pointer_to_object;
  };

  template <typename _Tp>
  concept __begin_data = contiguous_iterator<__range_iter_t<_Tp>>;

  struct _Data {
  private:
    template <typename _Tp> static constexpr bool _S_noexcept() {
      if constexpr (__member_data<_Tp>)
        return noexcept(__decay_copy(std::declval<_Tp &>().data()));
      else
        return noexcept(_Begin{}(std::declval<_Tp &>()));
    }

  public:
    template <__maybe_borrowed_range _Tp>
      requires __member_data<_Tp> || __begin_data<_Tp>
    constexpr auto operator() [[nodiscard]] (_Tp &&__t) const
        noexcept(_S_noexcept<_Tp>()) {
      if constexpr (__member_data<_Tp>)
        return __t.data();
      else
        return std::to_address(_Begin{}(__t));
    }
  };

  } // namespace __access

  inline namespace _Cpo {
  inline constexpr ranges::__access::_Begin begin{};
  inline constexpr ranges::__access::_End end{};
  inline constexpr ranges::__access::_RBegin rbegin{};
  inline constexpr ranges::__access::_REnd rend{};
  inline constexpr ranges::__access::_Size size{};
  inline constexpr ranges::__access::_SSize ssize{};
  inline constexpr ranges::__access::_Empty empty{};
  inline constexpr ranges::__access::_Data data{};
  } // namespace _Cpo

  template <typename _Tp>
  concept range = requires(_Tp &__t) {
    ranges::begin(__t);
    ranges::end(__t);
  };

  template <typename _Tp>
  concept borrowed_range = range<_Tp> && __detail::__maybe_borrowed_range<_Tp>;

  template <typename _Tp> using iterator_t = std::__detail::__range_iter_t<_Tp>;

  template <range _Range>
  using sentinel_t = decltype(ranges::end(std::declval<_Range &>()));
  template <range _Range>
  using range_difference_t = iter_difference_t<iterator_t<_Range>>;

  template <range _Range>
  using range_value_t = iter_value_t<iterator_t<_Range>>;

  template <range _Range>
  using range_reference_t = iter_reference_t<iterator_t<_Range>>;

  template <range _Range>
  using range_rvalue_reference_t = iter_rvalue_reference_t<iterator_t<_Range>>;

  template <typename _Tp>
  concept sized_range = range<_Tp> && requires(_Tp &__t) { ranges::size(__t); };

  template <sized_range _Range>
  using range_size_t = decltype(ranges::size(std::declval<_Range &>()));

  template <typename _Derived>
    requires is_class_v<_Derived> && same_as<_Derived, remove_cv_t<_Derived>>
  class view_interface;

  namespace __detail {
  template <typename _Tp, typename _Up>
    requires(!same_as<_Tp, view_interface<_Up>>)
  void __is_derived_from_view_interface_fn(const _Tp &,
                                           const view_interface<_Up> &);

  template <typename _Tp>
  concept __is_derived_from_view_interface =
      requires(_Tp __t) { __is_derived_from_view_interface_fn(__t, __t); };
  } // namespace __detail

  struct view_base {};

  template <typename _Tp>
  inline constexpr bool enable_view =
      derived_from<_Tp, view_base> ||
      __detail::__is_derived_from_view_interface<_Tp>;

  template <typename _Tp>
  concept view = range<_Tp> && movable<_Tp> && enable_view<_Tp>;

  template <typename _Range, typename _Tp>
  concept output_range =
      range<_Range> && output_iterator<iterator_t<_Range>, _Tp>;

  template <typename _Tp>
  concept input_range = range<_Tp> && input_iterator<iterator_t<_Tp>>;

  template <typename _Tp>
  concept forward_range = input_range<_Tp> && forward_iterator<iterator_t<_Tp>>;

  template <typename _Tp>
  concept bidirectional_range =
      forward_range<_Tp> && bidirectional_iterator<iterator_t<_Tp>>;

  template <typename _Tp>
  concept random_access_range =
      bidirectional_range<_Tp> && random_access_iterator<iterator_t<_Tp>>;

  template <typename _Tp>
  concept contiguous_range =
      random_access_range<_Tp> && contiguous_iterator<iterator_t<_Tp>> &&
      requires(_Tp &__t) {
        { ranges::data(__t) } -> same_as<add_pointer_t<range_reference_t<_Tp>>>;
      };

  template <typename _Tp>
  concept common_range =
      range<_Tp> && same_as<iterator_t<_Tp>, sentinel_t<_Tp>>;

  namespace __access {
  template <typename _To, typename _Tp>
  constexpr decltype(auto) __as_const(_Tp &__t) noexcept {
    static_assert(std::is_same_v<_To &, _Tp &>);

    if constexpr (is_lvalue_reference_v<_To>)
      return const_cast<const _Tp &>(__t);
    else
      return static_cast<const _Tp &&>(__t);
  }

  struct _CBegin {
    template <typename _Tp>
    [[nodiscard]]
    constexpr auto operator()(_Tp &&__e) const
        noexcept(noexcept(_Begin{}(__access::__as_const<_Tp>(__e))))
      requires requires { _Begin{}(__access::__as_const<_Tp>(__e)); }
    {
      return _Begin{}(__access::__as_const<_Tp>(__e));
    }
  };

  struct _CEnd final {
    template <typename _Tp>
    [[nodiscard]]
    constexpr auto operator()(_Tp &&__e) const
        noexcept(noexcept(_End{}(__access::__as_const<_Tp>(__e))))
      requires requires { _End{}(__access::__as_const<_Tp>(__e)); }
    {
      return _End{}(__access::__as_const<_Tp>(__e));
    }
  };

  struct _CRBegin {
    template <typename _Tp>
    [[nodiscard]]
    constexpr auto operator()(_Tp &&__e) const
        noexcept(noexcept(_RBegin{}(__access::__as_const<_Tp>(__e))))
      requires requires { _RBegin{}(__access::__as_const<_Tp>(__e)); }
    {
      return _RBegin{}(__access::__as_const<_Tp>(__e));
    }
  };

  struct _CREnd {
    template <typename _Tp>
    [[nodiscard]]
    constexpr auto operator()(_Tp &&__e) const
        noexcept(noexcept(_REnd{}(__access::__as_const<_Tp>(__e))))
      requires requires { _REnd{}(__access::__as_const<_Tp>(__e)); }
    {
      return _REnd{}(__access::__as_const<_Tp>(__e));
    }
  };

  struct _CData {
    template <typename _Tp>
    [[nodiscard]]
    constexpr auto operator()(_Tp &&__e) const
        noexcept(noexcept(_Data{}(__access::__as_const<_Tp>(__e))))
      requires requires { _Data{}(__access::__as_const<_Tp>(__e)); }
    {
      return _Data{}(__access::__as_const<_Tp>(__e));
    }
  };
  } // namespace __access

  inline namespace _Cpo {
  inline constexpr ranges::__access::_CBegin cbegin{};
  inline constexpr ranges::__access::_CEnd cend{};
  inline constexpr ranges::__access::_CRBegin crbegin{};
  inline constexpr ranges::__access::_CREnd crend{};
  inline constexpr ranges::__access::_CData cdata{};
  } // namespace _Cpo

  namespace __detail {
  template <typename _Tp> inline constexpr bool __is_initializer_list = false;

  template <typename _Tp>
  inline constexpr bool __is_initializer_list<initializer_list<_Tp>> = true;
  } // namespace __detail

  template <typename _Tp>
  concept viewable_range =
      range<_Tp> &&
      ((view<remove_cvref_t<_Tp>> &&
        constructible_from<remove_cvref_t<_Tp>, _Tp>) ||
       (!view<remove_cvref_t<_Tp>> &&
        (is_lvalue_reference_v<_Tp> ||
         (movable<remove_reference_t<_Tp>> &&
          !__detail::__is_initializer_list<remove_cvref_t<_Tp>>))));

  struct __advance_fn final {
    template <input_or_output_iterator _It>
    constexpr void operator()(_It &__it, iter_difference_t<_It> __n) const {
      if constexpr (random_access_iterator<_It>)
        __it += __n;
      else if constexpr (bidirectional_iterator<_It>) {
        if (__n > 0) {
          do {
            ++__it;
          } while (--__n);
        } else if (__n < 0) {
          do {
            --__it;
          } while (++__n);
        }
      } else {

        do {
          if (std::__is_constant_evaluated())
            if (__builtin_expect(!bool(__n >= 0), false))
              std::__glibcxx_assert_fail();
        } while (false);
        while (__n-- > 0)
          ++__it;
      }
    }

    template <input_or_output_iterator _It, sentinel_for<_It> _Sent>
    constexpr void operator()(_It &__it, _Sent __bound) const {
      if constexpr (assignable_from<_It &, _Sent>)
        __it = std::move(__bound);
      else if constexpr (sized_sentinel_for<_Sent, _It>)
        (*this)(__it, __bound - __it);
      else {
        while (__it != __bound)
          ++__it;
      }
    }

    template <input_or_output_iterator _It, sentinel_for<_It> _Sent>
    constexpr iter_difference_t<_It>
    operator()(_It &__it, iter_difference_t<_It> __n, _Sent __bound) const {
      if constexpr (sized_sentinel_for<_Sent, _It>) {
        const auto __diff = __bound - __it;

        if (__diff == 0)
          return __n;
        else if (__diff > 0 ? __n >= __diff : __n <= __diff) {
          (*this)(__it, __bound);
          return __n - __diff;
        } else if (__n != 0) [[likely]] {

          do {
            if (std::__is_constant_evaluated())
              if (__builtin_expect(!bool((__n < 0) == (__diff < 0)), false))
                std::__glibcxx_assert_fail();
          } while (false);

          (*this)(__it, __n);
          return 0;
        } else
          return 0;
      } else if (__it == __bound || __n == 0)
        return __n;
      else if (__n > 0) {
        iter_difference_t<_It> __m = 0;
        do {
          ++__it;
          ++__m;
        } while (__m != __n && __it != __bound);
        return __n - __m;
      } else if constexpr (bidirectional_iterator<_It> && same_as<_It, _Sent>) {
        iter_difference_t<_It> __m = 0;
        do {
          --__it;
          --__m;
        } while (__m != __n && __it != __bound);
        return __n - __m;
      } else {

        do {
          if (std::__is_constant_evaluated())
            if (__builtin_expect(!bool(__n >= 0), false))
              std::__glibcxx_assert_fail();
        } while (false);
        return __n;
      }
    }

    void operator&() const = delete;
  };

  inline constexpr __advance_fn advance{};

  struct __distance_fn final {

    template <typename _It, sentinel_for<_It> _Sent>
      requires(!sized_sentinel_for<_Sent, _It>)
    constexpr iter_difference_t<_It> operator()
        [[nodiscard]] (_It __first, _Sent __last) const {
      iter_difference_t<_It> __n = 0;
      while (__first != __last) {
        ++__first;
        ++__n;
      }
      return __n;
    }

    template <typename _It, sized_sentinel_for<decay_t<_It>> _Sent>
    [[nodiscard]]
    constexpr iter_difference_t<decay_t<_It>> operator()(_It &&__first,
                                                         _Sent __last) const {
      return __last - static_cast<const decay_t<_It> &>(__first);
    }

    template <range _Range>
    [[nodiscard]]
    constexpr range_difference_t<_Range> operator()(_Range &&__r) const {
      if constexpr (sized_range<_Range>)
        return static_cast<range_difference_t<_Range>>(ranges::size(__r));
      else
        return (*this)(ranges::begin(__r), ranges::end(__r));
    }

    void operator&() const = delete;
  };

  inline constexpr __distance_fn distance{};

  struct __next_fn final {
    template <input_or_output_iterator _It>
    [[nodiscard]]
    constexpr _It operator()(_It __x) const {
      ++__x;
      return __x;
    }

    template <input_or_output_iterator _It>
    [[nodiscard]]
    constexpr _It operator()(_It __x, iter_difference_t<_It> __n) const {
      ranges::advance(__x, __n);
      return __x;
    }

    template <input_or_output_iterator _It, sentinel_for<_It> _Sent>
    [[nodiscard]]
    constexpr _It operator()(_It __x, _Sent __bound) const {
      ranges::advance(__x, __bound);
      return __x;
    }

    template <input_or_output_iterator _It, sentinel_for<_It> _Sent>
    [[nodiscard]]
    constexpr _It operator()(_It __x, iter_difference_t<_It> __n,
                             _Sent __bound) const {
      ranges::advance(__x, __n, __bound);
      return __x;
    }

    void operator&() const = delete;
  };

  inline constexpr __next_fn next{};

  struct __prev_fn final {
    template <bidirectional_iterator _It>
    [[nodiscard]]
    constexpr _It operator()(_It __x) const {
      --__x;
      return __x;
    }

    template <bidirectional_iterator _It>
    [[nodiscard]]
    constexpr _It operator()(_It __x, iter_difference_t<_It> __n) const {
      ranges::advance(__x, -__n);
      return __x;
    }

    template <bidirectional_iterator _It>
    [[nodiscard]]
    constexpr _It operator()(_It __x, iter_difference_t<_It> __n,
                             _It __bound) const {
      ranges::advance(__x, -__n, __bound);
      return __x;
    }

    void operator&() const = delete;
  };

  inline constexpr __prev_fn prev{};

  struct dangling {
    constexpr dangling() noexcept = default;
    template <typename... _Args> constexpr dangling(_Args &&...) noexcept {}
  };

  template <range _Range>
  using borrowed_iterator_t =
      __conditional_t<borrowed_range<_Range>, iterator_t<_Range>, dangling>;
  } // namespace ranges

} // namespace std

namespace std __attribute__((__visibility__("default"))) {

  namespace ranges {

  namespace __detail {
  template <typename _Range>
  concept __simple_view =
      view<_Range> && range<const _Range> &&
      same_as<iterator_t<_Range>, iterator_t<const _Range>> &&
      same_as<sentinel_t<_Range>, sentinel_t<const _Range>>;

  template <typename _It>
  concept __has_arrow =
      input_iterator<_It> &&
      (is_pointer_v<_It> || requires(_It __it) { __it.operator->(); });

  using std::__detail::__different_from;
  } // namespace __detail

  template <typename _Derived>
    requires is_class_v<_Derived> && same_as<_Derived, remove_cv_t<_Derived>>
  class view_interface {
  private:
    constexpr _Derived &_M_derived() noexcept {
      static_assert(derived_from<_Derived, view_interface<_Derived>>);
      static_assert(view<_Derived>);
      return static_cast<_Derived &>(*this);
    }

    constexpr const _Derived &_M_derived() const noexcept {
      static_assert(derived_from<_Derived, view_interface<_Derived>>);
      static_assert(view<_Derived>);
      return static_cast<const _Derived &>(*this);
    }

    static constexpr bool _S_bool(bool) noexcept;

    template <typename _Tp>
    static constexpr bool _S_empty(_Tp &__t) noexcept(
        noexcept(_S_bool(ranges::begin(__t) == ranges::end(__t)))) {
      return ranges::begin(__t) == ranges::end(__t);
    }

    template <typename _Tp>
    static constexpr auto _S_size(_Tp &__t) noexcept(
        noexcept(ranges::end(__t) - ranges::begin(__t))) {
      return ranges::end(__t) - ranges::begin(__t);
    }

  public:
    constexpr bool empty() noexcept(noexcept(_S_empty(_M_derived())))
      requires forward_range<_Derived> && (!sized_range<_Derived>)
    {
      return _S_empty(_M_derived());
    }

    constexpr bool empty() noexcept(noexcept(ranges::size(_M_derived()) == 0))
      requires sized_range<_Derived>
    {
      return ranges::size(_M_derived()) == 0;
    }

    constexpr bool empty() const noexcept(noexcept(_S_empty(_M_derived())))
      requires forward_range<const _Derived> && (!sized_range<const _Derived>)
    {
      return _S_empty(_M_derived());
    }

    constexpr bool empty() const
        noexcept(noexcept(ranges::size(_M_derived()) == 0))
      requires sized_range<const _Derived>
    {
      return ranges::size(_M_derived()) == 0;
    }

    constexpr explicit
    operator bool() noexcept(noexcept(ranges::empty(_M_derived())))
      requires requires { ranges::empty(_M_derived()); }
    {
      return !ranges::empty(_M_derived());
    }

    constexpr explicit operator bool() const
        noexcept(noexcept(ranges::empty(_M_derived())))
      requires requires { ranges::empty(_M_derived()); }
    {
      return !ranges::empty(_M_derived());
    }

    constexpr auto data() noexcept(noexcept(ranges::begin(_M_derived())))
      requires contiguous_iterator<iterator_t<_Derived>>
    {
      return std::to_address(ranges::begin(_M_derived()));
    }

    constexpr auto data() const noexcept(noexcept(ranges::begin(_M_derived())))
      requires range<const _Derived> &&
               contiguous_iterator<iterator_t<const _Derived>>
    {
      return std::to_address(ranges::begin(_M_derived()));
    }

    constexpr auto size() noexcept(noexcept(_S_size(_M_derived())))
      requires forward_range<_Derived> &&
               sized_sentinel_for<sentinel_t<_Derived>, iterator_t<_Derived>>
    {
      return _S_size(_M_derived());
    }

    constexpr auto size() const noexcept(noexcept(_S_size(_M_derived())))
      requires forward_range<const _Derived> &&
               sized_sentinel_for<sentinel_t<const _Derived>,
                                  iterator_t<const _Derived>>
    {
      return _S_size(_M_derived());
    }

    constexpr decltype(auto) front()
      requires forward_range<_Derived>
    {
      do {
        if (std::__is_constant_evaluated())
          if (__builtin_expect(!bool(!empty()), false))
            std::__glibcxx_assert_fail();
      } while (false);
      return *ranges::begin(_M_derived());
    }

    constexpr decltype(auto) front() const
      requires forward_range<const _Derived>
    {
      do {
        if (std::__is_constant_evaluated())
          if (__builtin_expect(!bool(!empty()), false))
            std::__glibcxx_assert_fail();
      } while (false);
      return *ranges::begin(_M_derived());
    }

    constexpr decltype(auto) back()
      requires bidirectional_range<_Derived> && common_range<_Derived>
    {
      do {
        if (std::__is_constant_evaluated())
          if (__builtin_expect(!bool(!empty()), false))
            std::__glibcxx_assert_fail();
      } while (false);
      return *ranges::prev(ranges::end(_M_derived()));
    }

    constexpr decltype(auto) back() const
      requires bidirectional_range<const _Derived> &&
               common_range<const _Derived>
    {
      do {
        if (std::__is_constant_evaluated())
          if (__builtin_expect(!bool(!empty()), false))
            std::__glibcxx_assert_fail();
      } while (false);
      return *ranges::prev(ranges::end(_M_derived()));
    }

    template <random_access_range _Range = _Derived>
    constexpr decltype(auto) operator[](range_difference_t<_Range> __n) {
      return ranges::begin(_M_derived())[__n];
    }

    template <random_access_range _Range = const _Derived>
    constexpr decltype(auto) operator[](range_difference_t<_Range> __n) const {
      return ranges::begin(_M_derived())[__n];
    }
  };

  namespace __detail {
  template <typename _From, typename _To>
  concept __uses_nonqualification_pointer_conversion =
      is_pointer_v<_From> && is_pointer_v<_To> &&
      !convertible_to<remove_pointer_t<_From> (*)[],
                      remove_pointer_t<_To> (*)[]>;

  template <typename _From, typename _To>
  concept __convertible_to_non_slicing =
      convertible_to<_From, _To> &&
      !__uses_nonqualification_pointer_conversion<decay_t<_From>, decay_t<_To>>;

  template <typename _Tp>
  concept __pair_like = !is_reference_v<_Tp> && requires(_Tp __t) {
    typename tuple_size<_Tp>::type;
    requires derived_from<tuple_size<_Tp>, integral_constant<size_t, 2>>;
    typename tuple_element_t<0, remove_const_t<_Tp>>;
    typename tuple_element_t<1, remove_const_t<_Tp>>;
    { get<0>(__t) } -> convertible_to<const tuple_element_t<0, _Tp> &>;
    { get<1>(__t) } -> convertible_to<const tuple_element_t<1, _Tp> &>;
  };

  template <typename _Tp, typename _Up, typename _Vp>
  concept __pair_like_convertible_from =
      !range<_Tp> && !is_reference_v<_Vp> && __pair_like<_Tp> &&
      constructible_from<_Tp, _Up, _Vp> &&
      __convertible_to_non_slicing<_Up, tuple_element_t<0, _Tp>> &&
      convertible_to<_Vp, tuple_element_t<1, _Tp>>;

  } // namespace __detail

  namespace views {
  struct _Drop;
  }

  enum class subrange_kind : bool { unsized, sized };

  template <input_or_output_iterator _It, sentinel_for<_It> _Sent = _It,
            subrange_kind _Kind = sized_sentinel_for<_Sent, _It>
                                      ? subrange_kind::sized
                                      : subrange_kind::unsized>
    requires(_Kind == subrange_kind::sized || !sized_sentinel_for<_Sent, _It>)
  class subrange : public view_interface<subrange<_It, _Sent, _Kind>> {
  private:
    static constexpr bool _S_store_size =
        _Kind == subrange_kind::sized && !sized_sentinel_for<_Sent, _It>;

    friend struct views::_Drop;

    _It _M_begin = _It();
    [[no_unique_address]] _Sent _M_end = _Sent();

    using __size_type =
        __detail::__make_unsigned_like_t<iter_difference_t<_It>>;

    template <typename _Tp, bool = _S_store_size> struct _Size {
      [[__gnu__::__always_inline__]]
      constexpr _Size(_Tp = {}) {}
    };

    template <typename _Tp> struct _Size<_Tp, true> {
      [[__gnu__::__always_inline__]]
      constexpr _Size(_Tp __s = {})
          : _M_size(__s) {}

      _Tp _M_size;
    };

    [[no_unique_address]] _Size<__size_type> _M_size = {};

  public:
    subrange()
      requires default_initializable<_It>
    = default;

    constexpr subrange(
        __detail::__convertible_to_non_slicing<_It> auto __i,
        _Sent __s) noexcept(is_nothrow_constructible_v<_It, decltype(__i)> &&
                            is_nothrow_constructible_v<_Sent, _Sent &>)
      requires(!_S_store_size)
        : _M_begin(std::move(__i)), _M_end(__s) {}

    constexpr subrange(
        __detail::__convertible_to_non_slicing<_It> auto __i, _Sent __s,
        __size_type
            __n) noexcept(is_nothrow_constructible_v<_It, decltype(__i)> &&
                          is_nothrow_constructible_v<_Sent, _Sent &>)
      requires(_Kind == subrange_kind::sized)
        : _M_begin(std::move(__i)), _M_end(__s), _M_size(__n) {}

    template <__detail::__different_from<subrange> _Rng>
      requires borrowed_range<_Rng> &&
               __detail::__convertible_to_non_slicing<iterator_t<_Rng>, _It> &&
               convertible_to<sentinel_t<_Rng>, _Sent>
               constexpr subrange(_Rng &&__r) noexcept(
                   noexcept(subrange(__r, ranges::size(__r))))
                 requires _S_store_size && sized_range<_Rng>
        : subrange(__r, ranges::size(__r)) {}

    template <__detail::__different_from<subrange> _Rng>
      requires borrowed_range<_Rng> &&
               __detail::__convertible_to_non_slicing<iterator_t<_Rng>, _It> &&
               convertible_to<sentinel_t<_Rng>, _Sent>
               constexpr subrange(_Rng &&__r) noexcept(
                   noexcept(subrange(ranges::begin(__r), ranges::end(__r))))
                 requires(!_S_store_size)
        : subrange(ranges::begin(__r), ranges::end(__r)) {}

    template <borrowed_range _Rng>
      requires __detail::__convertible_to_non_slicing<iterator_t<_Rng>, _It> &&
               convertible_to<sentinel_t<_Rng>, _Sent>
               constexpr subrange(_Rng &&__r, __size_type __n) noexcept(
                   noexcept(subrange(ranges::begin(__r), ranges::end(__r),
                                     __n)))
                 requires(_Kind == subrange_kind::sized)
        : subrange{ranges::begin(__r), ranges::end(__r), __n} {}

    template <__detail::__different_from<subrange> _PairLike>
      requires __detail::__pair_like_convertible_from<_PairLike, const _It &,
                                                      const _Sent &>
    constexpr operator _PairLike() const {
      return _PairLike(_M_begin, _M_end);
    }

    constexpr _It begin() const
      requires copyable<_It>
    {
      return _M_begin;
    }

    [[nodiscard]] constexpr _It begin()
      requires(!copyable<_It>)
    {
      return std::move(_M_begin);
    }

    constexpr _Sent end() const { return _M_end; }

    constexpr bool empty() const { return _M_begin == _M_end; }

    constexpr __size_type size() const
      requires(_Kind == subrange_kind::sized)
    {
      if constexpr (_S_store_size)
        return _M_size._M_size;
      else
        return __detail::__to_unsigned_like(_M_end - _M_begin);
    }

    [[nodiscard]] constexpr subrange
    next(iter_difference_t<_It> __n = 1) const &
      requires forward_iterator<_It>
    {
      auto __tmp = *this;
      __tmp.advance(__n);
      return __tmp;
    }

    [[nodiscard]] constexpr subrange next(iter_difference_t<_It> __n = 1) && {
      advance(__n);
      return std::move(*this);
    }

    [[nodiscard]] constexpr subrange prev(iter_difference_t<_It> __n = 1) const
      requires bidirectional_iterator<_It>
    {
      auto __tmp = *this;
      __tmp.advance(-__n);
      return __tmp;
    }

    constexpr subrange &advance(iter_difference_t<_It> __n) {

      if constexpr (bidirectional_iterator<_It>)
        if (__n < 0) {
          ranges::advance(_M_begin, __n);
          if constexpr (_S_store_size)
            _M_size._M_size += __detail::__to_unsigned_like(-__n);
          return *this;
        }

      do {
        if (std::__is_constant_evaluated())
          if (__builtin_expect(!bool(__n >= 0), false))
            std::__glibcxx_assert_fail();
      } while (false);
      auto __d = __n - ranges::advance(_M_begin, __n, _M_end);
      if constexpr (_S_store_size)
        _M_size._M_size -= __detail::__to_unsigned_like(__d);
      return *this;
    }
  };

  template <input_or_output_iterator _It, sentinel_for<_It> _Sent>
  subrange(_It, _Sent) -> subrange<_It, _Sent>;

  template <input_or_output_iterator _It, sentinel_for<_It> _Sent>
  subrange(_It, _Sent, __detail::__make_unsigned_like_t<iter_difference_t<_It>>)
      -> subrange<_It, _Sent, subrange_kind::sized>;

  template <borrowed_range _Rng>
  subrange(_Rng &&)
      -> subrange<iterator_t<_Rng>, sentinel_t<_Rng>,
                  (sized_range<_Rng> ||
                   sized_sentinel_for<sentinel_t<_Rng>, iterator_t<_Rng>>)
                      ? subrange_kind::sized
                      : subrange_kind::unsized>;

  template <borrowed_range _Rng>
  subrange(_Rng &&, __detail::__make_unsigned_like_t<range_difference_t<_Rng>>)
      -> subrange<iterator_t<_Rng>, sentinel_t<_Rng>, subrange_kind::sized>;

  template <size_t _Num, class _It, class _Sent, subrange_kind _Kind>
    requires(_Num < 2)
  constexpr auto get(const subrange<_It, _Sent, _Kind> &__r) {
    if constexpr (_Num == 0)
      return __r.begin();
    else
      return __r.end();
  }

  template <size_t _Num, class _It, class _Sent, subrange_kind _Kind>
    requires(_Num < 2)
  constexpr auto get(subrange<_It, _Sent, _Kind> &&__r) {
    if constexpr (_Num == 0)
      return __r.begin();
    else
      return __r.end();
  }

  template <typename _It, typename _Sent, subrange_kind _Kind>
  inline constexpr bool enable_borrowed_range<subrange<_It, _Sent, _Kind>> =
      true;

  template <range _Range>
  using borrowed_subrange_t =
      __conditional_t<borrowed_range<_Range>, subrange<iterator_t<_Range>>,
                      dangling>;

  template <typename _Iter, typename _Sent, subrange_kind _Kind>
  inline constexpr bool __detail::__is_subrange<subrange<_Iter, _Sent, _Kind>> =
      true;
  } // namespace ranges
  namespace ranges {
  struct __find_fn {
    template <input_iterator _Iter, sentinel_for<_Iter> _Sent, typename _Tp,
              typename _Proj = identity>
      requires indirect_binary_predicate<ranges::equal_to,
                                         projected<_Iter, _Proj>, const _Tp *>
    constexpr _Iter operator()(_Iter __first, _Sent __last, const _Tp &__value,
                               _Proj __proj = {}) const {
      while (__first != __last && !(std::__invoke(__proj, *__first) == __value))
        ++__first;
      return __first;
    }

    template <input_range _Range, typename _Tp, typename _Proj = identity>
      requires indirect_binary_predicate<
          ranges::equal_to, projected<iterator_t<_Range>, _Proj>, const _Tp *>
    constexpr borrowed_iterator_t<_Range>
    operator()(_Range &&__r, const _Tp &__value, _Proj __proj = {}) const {
      return (*this)(ranges::begin(__r), ranges::end(__r), __value,
                     std::move(__proj));
    }
  };

  inline constexpr __find_fn find{};

  struct __find_if_fn {
    template <input_iterator _Iter, sentinel_for<_Iter> _Sent,
              typename _Proj = identity,
              indirect_unary_predicate<projected<_Iter, _Proj>> _Pred>
    constexpr _Iter operator()(_Iter __first, _Sent __last, _Pred __pred,
                               _Proj __proj = {}) const {
      while (__first != __last &&
             !(bool)std::__invoke(__pred, std::__invoke(__proj, *__first)))
        ++__first;
      return __first;
    }

    template <
        input_range _Range, typename _Proj = identity,
        indirect_unary_predicate<projected<iterator_t<_Range>, _Proj>> _Pred>
    constexpr borrowed_iterator_t<_Range> operator()(_Range &&__r, _Pred __pred,
                                                     _Proj __proj = {}) const {
      return (*this)(ranges::begin(__r), ranges::end(__r), std::move(__pred),
                     std::move(__proj));
    }
  };

  inline constexpr __find_if_fn find_if{};

  struct __find_if_not_fn {
    template <input_iterator _Iter, sentinel_for<_Iter> _Sent,
              typename _Proj = identity,
              indirect_unary_predicate<projected<_Iter, _Proj>> _Pred>
    constexpr _Iter operator()(_Iter __first, _Sent __last, _Pred __pred,
                               _Proj __proj = {}) const {
      while (__first != __last &&
             (bool)std::__invoke(__pred, std::__invoke(__proj, *__first)))
        ++__first;
      return __first;
    }

    template <
        input_range _Range, typename _Proj = identity,
        indirect_unary_predicate<projected<iterator_t<_Range>, _Proj>> _Pred>
    constexpr borrowed_iterator_t<_Range> operator()(_Range &&__r, _Pred __pred,
                                                     _Proj __proj = {}) const {
      return (*this)(ranges::begin(__r), ranges::end(__r), std::move(__pred),
                     std::move(__proj));
    }
  };

  inline constexpr __find_if_not_fn find_if_not{};

  template <typename _Iter1, typename _Iter2> struct in_in_result {
    [[no_unique_address]] _Iter1 in1;
    [[no_unique_address]] _Iter2 in2;

    template <typename _IIter1, typename _IIter2>
      requires convertible_to<const _Iter1 &, _IIter1> &&
               convertible_to<const _Iter2 &, _IIter2>
    constexpr operator in_in_result<_IIter1, _IIter2>() const & {
      return {in1, in2};
    }

    template <typename _IIter1, typename _IIter2>
      requires convertible_to<_Iter1, _IIter1> &&
               convertible_to<_Iter2, _IIter2>
    constexpr operator in_in_result<_IIter1, _IIter2>() && {
      return {std::move(in1), std::move(in2)};
    }
  };

  template <typename _Iter1, typename _Iter2>
  using mismatch_result = in_in_result<_Iter1, _Iter2>;

  struct __mismatch_fn {
    template <input_iterator _Iter1, sentinel_for<_Iter1> _Sent1,
              input_iterator _Iter2, sentinel_for<_Iter2> _Sent2,
              typename _Pred = ranges::equal_to, typename _Proj1 = identity,
              typename _Proj2 = identity>
      requires indirectly_comparable<_Iter1, _Iter2, _Pred, _Proj1, _Proj2>
    constexpr mismatch_result<_Iter1, _Iter2>
    operator()(_Iter1 __first1, _Sent1 __last1, _Iter2 __first2, _Sent2 __last2,
               _Pred __pred = {}, _Proj1 __proj1 = {},
               _Proj2 __proj2 = {}) const {
      while (__first1 != __last1 && __first2 != __last2 &&
             (bool)std::__invoke(__pred, std::__invoke(__proj1, *__first1),
                                 std::__invoke(__proj2, *__first2))) {
        ++__first1;
        ++__first2;
      }
      return {std::move(__first1), std::move(__first2)};
    }

    template <input_range _Range1, input_range _Range2,
              typename _Pred = ranges::equal_to, typename _Proj1 = identity,
              typename _Proj2 = identity>
      requires indirectly_comparable<iterator_t<_Range1>, iterator_t<_Range2>,
                                     _Pred, _Proj1, _Proj2>
    constexpr mismatch_result<iterator_t<_Range1>, iterator_t<_Range2>>
    operator()(_Range1 &&__r1, _Range2 &&__r2, _Pred __pred = {},
               _Proj1 __proj1 = {}, _Proj2 __proj2 = {}) const {
      return (*this)(ranges::begin(__r1), ranges::end(__r1),
                     ranges::begin(__r2), ranges::end(__r2), std::move(__pred),
                     std::move(__proj1), std::move(__proj2));
    }
  };

  inline constexpr __mismatch_fn mismatch{};

  struct __search_fn {
    template <forward_iterator _Iter1, sentinel_for<_Iter1> _Sent1,
              forward_iterator _Iter2, sentinel_for<_Iter2> _Sent2,
              typename _Pred = ranges::equal_to, typename _Proj1 = identity,
              typename _Proj2 = identity>
      requires indirectly_comparable<_Iter1, _Iter2, _Pred, _Proj1, _Proj2>
    constexpr subrange<_Iter1>
    operator()(_Iter1 __first1, _Sent1 __last1, _Iter2 __first2, _Sent2 __last2,
               _Pred __pred = {}, _Proj1 __proj1 = {},
               _Proj2 __proj2 = {}) const {
      if (__first1 == __last1 || __first2 == __last2)
        return {__first1, __first1};

      for (;;) {
        for (;;) {
          if (__first1 == __last1)
            return {__first1, __first1};
          if (std::__invoke(__pred, std::__invoke(__proj1, *__first1),
                            std::__invoke(__proj2, *__first2)))
            break;
          ++__first1;
        }
        auto __cur1 = __first1;
        auto __cur2 = __first2;
        for (;;) {
          if (++__cur2 == __last2)
            return {__first1, ++__cur1};
          if (++__cur1 == __last1)
            return {__cur1, __cur1};
          if (!(bool)std::__invoke(__pred, std::__invoke(__proj1, *__cur1),
                                   std::__invoke(__proj2, *__cur2))) {
            ++__first1;
            break;
          }
        }
      }
    }

    template <forward_range _Range1, forward_range _Range2,
              typename _Pred = ranges::equal_to, typename _Proj1 = identity,
              typename _Proj2 = identity>
      requires indirectly_comparable<iterator_t<_Range1>, iterator_t<_Range2>,
                                     _Pred, _Proj1, _Proj2>
    constexpr borrowed_subrange_t<_Range1>
    operator()(_Range1 &&__r1, _Range2 &&__r2, _Pred __pred = {},
               _Proj1 __proj1 = {}, _Proj2 __proj2 = {}) const {
      return (*this)(ranges::begin(__r1), ranges::end(__r1),
                     ranges::begin(__r2), ranges::end(__r2), std::move(__pred),
                     std::move(__proj1), std::move(__proj2));
    }
  };

  inline constexpr __search_fn search{};

  struct __min_fn {
    template <typename _Tp, typename _Proj = identity,
              indirect_strict_weak_order<projected<const _Tp *, _Proj>> _Comp =
                  ranges::less>
    constexpr const _Tp &operator()(const _Tp &__a, const _Tp &__b,
                                    _Comp __comp = {},
                                    _Proj __proj = {}) const {
      if (std::__invoke(__comp, std::__invoke(__proj, __b),
                        std::__invoke(__proj, __a)))
        return __b;
      else
        return __a;
    }

    template <input_range _Range, typename _Proj = identity,
              indirect_strict_weak_order<projected<iterator_t<_Range>, _Proj>>
                  _Comp = ranges::less>
      requires indirectly_copyable_storable<iterator_t<_Range>,
                                            range_value_t<_Range> *>
    constexpr range_value_t<_Range> operator()(_Range &&__r, _Comp __comp = {},
                                               _Proj __proj = {}) const {
      auto __first = ranges::begin(__r);
      auto __last = ranges::end(__r);
      do {
        if (std::__is_constant_evaluated())
          if (__builtin_expect(!bool(__first != __last), false))
            std::__glibcxx_assert_fail();
      } while (false);
      auto __result = *__first;
      while (++__first != __last) {
        auto __tmp = *__first;
        if (std::__invoke(__comp, std::__invoke(__proj, __tmp),
                          std::__invoke(__proj, __result)))
          __result = std::move(__tmp);
      }
      return __result;
    }

    template <copyable _Tp, typename _Proj = identity,
              indirect_strict_weak_order<projected<const _Tp *, _Proj>> _Comp =
                  ranges::less>
    constexpr _Tp operator()(initializer_list<_Tp> __r, _Comp __comp = {},
                             _Proj __proj = {}) const {
      return (*this)(ranges::subrange(__r), std::move(__comp),
                     std::move(__proj));
    }
  };

  inline constexpr __min_fn min{};

  struct __adjacent_find_fn {
    template <forward_iterator _Iter, sentinel_for<_Iter> _Sent,
              typename _Proj = identity,
              indirect_binary_predicate<projected<_Iter, _Proj>,
                                        projected<_Iter, _Proj>>
                  _Pred = ranges::equal_to>
    constexpr _Iter operator()(_Iter __first, _Sent __last, _Pred __pred = {},
                               _Proj __proj = {}) const {
      if (__first == __last)
        return __first;
      auto __next = __first;
      for (; ++__next != __last; __first = __next) {
        if (std::__invoke(__pred, std::__invoke(__proj, *__first),
                          std::__invoke(__proj, *__next)))
          return __first;
      }
      return __next;
    }

    template <forward_range _Range, typename _Proj = identity,
              indirect_binary_predicate<projected<iterator_t<_Range>, _Proj>,
                                        projected<iterator_t<_Range>, _Proj>>
                  _Pred = ranges::equal_to>
    constexpr borrowed_iterator_t<_Range>
    operator()(_Range &&__r, _Pred __pred = {}, _Proj __proj = {}) const {
      return (*this)(ranges::begin(__r), ranges::end(__r), std::move(__pred),
                     std::move(__proj));
    }
  };

  inline constexpr __adjacent_find_fn adjacent_find{};

  } // namespace ranges

  using ranges::get;

  template <typename _Iter, typename _Sent, ranges::subrange_kind _Kind>
  struct tuple_size<ranges::subrange<_Iter, _Sent, _Kind>>
      : integral_constant<size_t, 2> {};

  template <typename _Iter, typename _Sent, ranges::subrange_kind _Kind>
  struct tuple_element<0, ranges::subrange<_Iter, _Sent, _Kind>> {
    using type = _Iter;
  };

  template <typename _Iter, typename _Sent, ranges::subrange_kind _Kind>
  struct tuple_element<1, ranges::subrange<_Iter, _Sent, _Kind>> {
    using type = _Sent;
  };

  template <typename _Iter, typename _Sent, ranges::subrange_kind _Kind>
  struct tuple_element<0, const ranges::subrange<_Iter, _Sent, _Kind>> {
    using type = _Iter;
  };

  template <typename _Iter, typename _Sent, ranges::subrange_kind _Kind>
  struct tuple_element<1, const ranges::subrange<_Iter, _Sent, _Kind>> {
    using type = _Sent;
  };

} // namespace std

namespace std __attribute__((__visibility__("default"))) {

  template <typename... _Elements> class tuple;

  template <typename _Tp> struct __is_empty_non_tuple : is_empty<_Tp> {};

  template <typename _El0, typename... _El>
  struct __is_empty_non_tuple<tuple<_El0, _El...>> : false_type {};

  template <typename _Tp>
  using __empty_not_final =
      __conditional_t<__is_final(_Tp), false_type, __is_empty_non_tuple<_Tp>>;

  template <size_t _Idx, typename _Head, bool = __empty_not_final<_Head>::value>
  struct _Head_base;

  template <size_t _Idx, typename _Head> struct _Head_base<_Idx, _Head, true> {
    constexpr _Head_base() : _M_head_impl() {}

    constexpr _Head_base(const _Head &__h) : _M_head_impl(__h) {}

    constexpr _Head_base(const _Head_base &) = default;
    constexpr _Head_base(_Head_base &&) = default;

    template <typename _UHead>
    constexpr _Head_base(_UHead &&__h)
        : _M_head_impl(std::forward<_UHead>(__h)) {}

    constexpr _Head_base(allocator_arg_t, __uses_alloc0) : _M_head_impl() {}

    template <typename _Alloc>
    constexpr _Head_base(allocator_arg_t, __uses_alloc1<_Alloc> __a)
        : _M_head_impl(allocator_arg, *__a._M_a) {}

    template <typename _Alloc>
    constexpr _Head_base(allocator_arg_t, __uses_alloc2<_Alloc> __a)
        : _M_head_impl(*__a._M_a) {}

    template <typename _UHead>
    constexpr _Head_base(__uses_alloc0, _UHead &&__uhead)
        : _M_head_impl(std::forward<_UHead>(__uhead)) {}

    template <typename _Alloc, typename _UHead>
    constexpr _Head_base(__uses_alloc1<_Alloc> __a, _UHead &&__uhead)
        : _M_head_impl(allocator_arg, *__a._M_a,
                       std::forward<_UHead>(__uhead)) {}

    template <typename _Alloc, typename _UHead>
    constexpr _Head_base(__uses_alloc2<_Alloc> __a, _UHead &&__uhead)
        : _M_head_impl(std::forward<_UHead>(__uhead), *__a._M_a) {}

    static constexpr _Head &_M_head(_Head_base &__b) noexcept {
      return __b._M_head_impl;
    }

    static constexpr const _Head &_M_head(const _Head_base &__b) noexcept {
      return __b._M_head_impl;
    }

    [[__no_unique_address__]] _Head _M_head_impl;
  };
  template <size_t _Idx, typename _Head> struct _Head_base<_Idx, _Head, false> {
    constexpr _Head_base() : _M_head_impl() {}

    constexpr _Head_base(const _Head &__h) : _M_head_impl(__h) {}

    constexpr _Head_base(const _Head_base &) = default;
    constexpr _Head_base(_Head_base &&) = default;

    template <typename _UHead>
    constexpr _Head_base(_UHead &&__h)
        : _M_head_impl(std::forward<_UHead>(__h)) {}

    constexpr _Head_base(allocator_arg_t, __uses_alloc0) : _M_head_impl() {}

    template <typename _Alloc>
    constexpr _Head_base(allocator_arg_t, __uses_alloc1<_Alloc> __a)
        : _M_head_impl(allocator_arg, *__a._M_a) {}

    template <typename _Alloc>
    constexpr _Head_base(allocator_arg_t, __uses_alloc2<_Alloc> __a)
        : _M_head_impl(*__a._M_a) {}

    template <typename _UHead>
    constexpr _Head_base(__uses_alloc0, _UHead &&__uhead)
        : _M_head_impl(std::forward<_UHead>(__uhead)) {}

    template <typename _Alloc, typename _UHead>
    constexpr _Head_base(__uses_alloc1<_Alloc> __a, _UHead &&__uhead)
        : _M_head_impl(allocator_arg, *__a._M_a,
                       std::forward<_UHead>(__uhead)) {}

    template <typename _Alloc, typename _UHead>
    constexpr _Head_base(__uses_alloc2<_Alloc> __a, _UHead &&__uhead)
        : _M_head_impl(std::forward<_UHead>(__uhead), *__a._M_a) {}

    static constexpr _Head &_M_head(_Head_base &__b) noexcept {
      return __b._M_head_impl;
    }

    static constexpr const _Head &_M_head(const _Head_base &__b) noexcept {
      return __b._M_head_impl;
    }

    _Head _M_head_impl;
  };
  template <size_t _Idx, typename... _Elements> struct _Tuple_impl;

  template <size_t _Idx, typename _Head, typename... _Tail>
  struct _Tuple_impl<_Idx, _Head, _Tail...>
      : public _Tuple_impl<_Idx + 1, _Tail...>,
        private _Head_base<_Idx, _Head> {
    template <size_t, typename...> friend struct _Tuple_impl;

    typedef _Tuple_impl<_Idx + 1, _Tail...> _Inherited;
    typedef _Head_base<_Idx, _Head> _Base;

    static constexpr _Head &_M_head(_Tuple_impl &__t) noexcept {
      return _Base::_M_head(__t);
    }

    static constexpr const _Head &_M_head(const _Tuple_impl &__t) noexcept {
      return _Base::_M_head(__t);
    }

    static constexpr _Inherited &_M_tail(_Tuple_impl &__t) noexcept {
      return __t;
    }

    static constexpr const _Inherited &
    _M_tail(const _Tuple_impl &__t) noexcept {
      return __t;
    }

    constexpr _Tuple_impl() : _Inherited(), _Base() {}

    explicit constexpr _Tuple_impl(const _Head &__head, const _Tail &...__tail)
        : _Inherited(__tail...), _Base(__head) {}

    template <typename _UHead, typename... _UTail,
              typename = __enable_if_t<sizeof...(_Tail) == sizeof...(_UTail)>>
    explicit constexpr _Tuple_impl(_UHead &&__head, _UTail &&...__tail)
        : _Inherited(std::forward<_UTail>(__tail)...),
          _Base(std::forward<_UHead>(__head)) {}

    constexpr _Tuple_impl(const _Tuple_impl &) = default;

    _Tuple_impl &operator=(const _Tuple_impl &) = delete;

    _Tuple_impl(_Tuple_impl &&) = default;

    template <typename... _UElements>
    constexpr _Tuple_impl(const _Tuple_impl<_Idx, _UElements...> &__in)
        : _Inherited(_Tuple_impl<_Idx, _UElements...>::_M_tail(__in)),
          _Base(_Tuple_impl<_Idx, _UElements...>::_M_head(__in)) {}

    template <typename _UHead, typename... _UTails>
    constexpr _Tuple_impl(_Tuple_impl<_Idx, _UHead, _UTails...> &&__in)
        : _Inherited(
              std::move(_Tuple_impl<_Idx, _UHead, _UTails...>::_M_tail(__in))),
          _Base(std::forward<_UHead>(
              _Tuple_impl<_Idx, _UHead, _UTails...>::_M_head(__in))) {}
    template <typename _Alloc>
    constexpr _Tuple_impl(allocator_arg_t __tag, const _Alloc &__a)
        : _Inherited(__tag, __a), _Base(__tag, __use_alloc<_Head>(__a)) {}

    template <typename _Alloc>
    constexpr _Tuple_impl(allocator_arg_t __tag, const _Alloc &__a,
                          const _Head &__head, const _Tail &...__tail)
        : _Inherited(__tag, __a, __tail...),
          _Base(__use_alloc<_Head, _Alloc, _Head>(__a), __head) {}

    template <typename _Alloc, typename _UHead, typename... _UTail,
              typename = __enable_if_t<sizeof...(_Tail) == sizeof...(_UTail)>>
    constexpr _Tuple_impl(allocator_arg_t __tag, const _Alloc &__a,
                          _UHead &&__head, _UTail &&...__tail)
        : _Inherited(__tag, __a, std::forward<_UTail>(__tail)...),
          _Base(__use_alloc<_Head, _Alloc, _UHead>(__a),
                std::forward<_UHead>(__head)) {}

    template <typename _Alloc>
    constexpr _Tuple_impl(allocator_arg_t __tag, const _Alloc &__a,
                          const _Tuple_impl &__in)
        : _Inherited(__tag, __a, _M_tail(__in)),
          _Base(__use_alloc<_Head, _Alloc, _Head>(__a), _M_head(__in)) {}

    template <typename _Alloc>
    constexpr _Tuple_impl(allocator_arg_t __tag, const _Alloc &__a,
                          _Tuple_impl &&__in)
        : _Inherited(__tag, __a, std::move(_M_tail(__in))),
          _Base(__use_alloc<_Head, _Alloc, _Head>(__a),
                std::forward<_Head>(_M_head(__in))) {}

    template <typename _Alloc, typename _UHead, typename... _UTails>
    constexpr _Tuple_impl(allocator_arg_t __tag, const _Alloc &__a,
                          const _Tuple_impl<_Idx, _UHead, _UTails...> &__in)
        : _Inherited(__tag, __a,
                     _Tuple_impl<_Idx, _UHead, _UTails...>::_M_tail(__in)),
          _Base(__use_alloc<_Head, _Alloc, const _UHead &>(__a),
                _Tuple_impl<_Idx, _UHead, _UTails...>::_M_head(__in)) {}

    template <typename _Alloc, typename _UHead, typename... _UTails>
    constexpr _Tuple_impl(allocator_arg_t __tag, const _Alloc &__a,
                          _Tuple_impl<_Idx, _UHead, _UTails...> &&__in)
        : _Inherited(
              __tag, __a,
              std::move(_Tuple_impl<_Idx, _UHead, _UTails...>::_M_tail(__in))),
          _Base(__use_alloc<_Head, _Alloc, _UHead>(__a),
                std::forward<_UHead>(
                    _Tuple_impl<_Idx, _UHead, _UTails...>::_M_head(__in))) {}
    template <typename... _UElements>
    constexpr void _M_assign(const _Tuple_impl<_Idx, _UElements...> &__in) {
      _M_head(*this) = _Tuple_impl<_Idx, _UElements...>::_M_head(__in);
      _M_tail(*this)._M_assign(_Tuple_impl<_Idx, _UElements...>::_M_tail(__in));
    }

    template <typename _UHead, typename... _UTails>
    constexpr void _M_assign(_Tuple_impl<_Idx, _UHead, _UTails...> &&__in) {
      _M_head(*this) = std::forward<_UHead>(
          _Tuple_impl<_Idx, _UHead, _UTails...>::_M_head(__in));
      _M_tail(*this)._M_assign(
          std::move(_Tuple_impl<_Idx, _UHead, _UTails...>::_M_tail(__in)));
    }

  protected:
    constexpr void _M_swap(_Tuple_impl &__in) {
      using std::swap;
      swap(_M_head(*this), _M_head(__in));
      _Inherited::_M_swap(_M_tail(__in));
    }
  };

  template <size_t _Idx, typename _Head>
  struct _Tuple_impl<_Idx, _Head> : private _Head_base<_Idx, _Head> {
    template <size_t, typename...> friend struct _Tuple_impl;

    typedef _Head_base<_Idx, _Head> _Base;

    static constexpr _Head &_M_head(_Tuple_impl &__t) noexcept {
      return _Base::_M_head(__t);
    }

    static constexpr const _Head &_M_head(const _Tuple_impl &__t) noexcept {
      return _Base::_M_head(__t);
    }

    constexpr _Tuple_impl() : _Base() {}

    explicit constexpr _Tuple_impl(const _Head &__head) : _Base(__head) {}

    template <typename _UHead>
    explicit constexpr _Tuple_impl(_UHead &&__head)
        : _Base(std::forward<_UHead>(__head)) {}

    constexpr _Tuple_impl(const _Tuple_impl &) = default;

    _Tuple_impl &operator=(const _Tuple_impl &) = delete;

    constexpr _Tuple_impl(_Tuple_impl &&__in) noexcept(
        is_nothrow_move_constructible<_Head>::value)
        : _Base(static_cast<_Base &&>(__in)) {}

    template <typename _UHead>
    constexpr _Tuple_impl(const _Tuple_impl<_Idx, _UHead> &__in)
        : _Base(_Tuple_impl<_Idx, _UHead>::_M_head(__in)) {}

    template <typename _UHead>
    constexpr _Tuple_impl(_Tuple_impl<_Idx, _UHead> &&__in)
        : _Base(
              std::forward<_UHead>(_Tuple_impl<_Idx, _UHead>::_M_head(__in))) {}
    template <typename _Alloc>
    constexpr _Tuple_impl(allocator_arg_t __tag, const _Alloc &__a)
        : _Base(__tag, __use_alloc<_Head>(__a)) {}

    template <typename _Alloc>
    constexpr _Tuple_impl(allocator_arg_t, const _Alloc &__a,
                          const _Head &__head)
        : _Base(__use_alloc<_Head, _Alloc, const _Head &>(__a), __head) {}

    template <typename _Alloc, typename _UHead>
    constexpr _Tuple_impl(allocator_arg_t, const _Alloc &__a, _UHead &&__head)
        : _Base(__use_alloc<_Head, _Alloc, _UHead>(__a),
                std::forward<_UHead>(__head)) {}

    template <typename _Alloc>
    constexpr _Tuple_impl(allocator_arg_t, const _Alloc &__a,
                          const _Tuple_impl &__in)
        : _Base(__use_alloc<_Head, _Alloc, const _Head &>(__a), _M_head(__in)) {
    }

    template <typename _Alloc>
    constexpr _Tuple_impl(allocator_arg_t, const _Alloc &__a,
                          _Tuple_impl &&__in)
        : _Base(__use_alloc<_Head, _Alloc, _Head>(__a),
                std::forward<_Head>(_M_head(__in))) {}

    template <typename _Alloc, typename _UHead>
    constexpr _Tuple_impl(allocator_arg_t, const _Alloc &__a,
                          const _Tuple_impl<_Idx, _UHead> &__in)
        : _Base(__use_alloc<_Head, _Alloc, const _UHead &>(__a),
                _Tuple_impl<_Idx, _UHead>::_M_head(__in)) {}

    template <typename _Alloc, typename _UHead>
    constexpr _Tuple_impl(allocator_arg_t, const _Alloc &__a,
                          _Tuple_impl<_Idx, _UHead> &&__in)
        : _Base(
              __use_alloc<_Head, _Alloc, _UHead>(__a),
              std::forward<_UHead>(_Tuple_impl<_Idx, _UHead>::_M_head(__in))) {}
    template <typename _UHead>
    constexpr void _M_assign(const _Tuple_impl<_Idx, _UHead> &__in) {
      _M_head(*this) = _Tuple_impl<_Idx, _UHead>::_M_head(__in);
    }

    template <typename _UHead>
    constexpr void _M_assign(_Tuple_impl<_Idx, _UHead> &&__in) {
      _M_head(*this) =
          std::forward<_UHead>(_Tuple_impl<_Idx, _UHead>::_M_head(__in));
    }

  protected:
    constexpr void _M_swap(_Tuple_impl &__in) {
      using std::swap;
      swap(_M_head(*this), _M_head(__in));
    }
  };

  template <bool, typename... _Types> struct _TupleConstraints {
    template <typename... _UTypes>
    using __constructible = __and_<is_constructible<_Types, _UTypes>...>;

    template <typename... _UTypes>
    using __convertible = __and_<is_convertible<_UTypes, _Types>...>;

    template <typename... _UTypes>
    static constexpr bool __is_implicitly_constructible() {
      return __and_<__constructible<_UTypes...>,
                    __convertible<_UTypes...>>::value;
    }

    template <typename... _UTypes>
    static constexpr bool __is_explicitly_constructible() {
      return __and_<__constructible<_UTypes...>,
                    __not_<__convertible<_UTypes...>>>::value;
    }

    static constexpr bool __is_implicitly_default_constructible() {
      return __and_<
          std::__is_implicitly_default_constructible<_Types>...>::value;
    }

    static constexpr bool __is_explicitly_default_constructible() {
      return __and_<is_default_constructible<_Types>...,
                    __not_<__and_<std::__is_implicitly_default_constructible<
                        _Types>...>>>::value;
    }
  };

  template <typename... _Types> struct _TupleConstraints<false, _Types...> {
    template <typename... _UTypes>
    static constexpr bool __is_implicitly_constructible() {
      return false;
    }

    template <typename... _UTypes>
    static constexpr bool __is_explicitly_constructible() {
      return false;
    }
  };

  template <typename... _Elements>
  class tuple : public _Tuple_impl<0, _Elements...> {
    using _Inherited = _Tuple_impl<0, _Elements...>;

    template <typename... _UTypes> static consteval bool __constructible() {
      if constexpr (sizeof...(_UTypes) == sizeof...(_Elements))
        return __and_v<is_constructible<_Elements, _UTypes>...>;
      else
        return false;
    }

    template <typename... _UTypes>
    static consteval bool __nothrow_constructible() {
      if constexpr (sizeof...(_UTypes) == sizeof...(_Elements))
        return __and_v<is_nothrow_constructible<_Elements, _UTypes>...>;
      else
        return false;
    }

    template <typename... _UTypes> static consteval bool __convertible() {
      if constexpr (sizeof...(_UTypes) == sizeof...(_Elements))
        return __and_v<is_convertible<_UTypes, _Elements>...>;
      else
        return false;
    }

    template <typename... _UTypes>
    static consteval bool __disambiguating_constraint() {
      if constexpr (sizeof...(_Elements) != sizeof...(_UTypes))
        return false;
      else if constexpr (sizeof...(_Elements) == 1) {
        using _U0 = typename _Nth_type<0, _UTypes...>::type;
        return !is_same_v<remove_cvref_t<_U0>, tuple>;
      } else if constexpr (sizeof...(_Elements) < 4) {
        using _U0 = typename _Nth_type<0, _UTypes...>::type;
        if constexpr (!is_same_v<remove_cvref_t<_U0>, allocator_arg_t>)
          return true;
        else {
          using _T0 = typename _Nth_type<0, _Elements...>::type;
          return is_same_v<remove_cvref_t<_T0>, allocator_arg_t>;
        }
      }
      return true;
    }

    template <typename _Tuple> static consteval bool __use_other_ctor() {
      if constexpr (sizeof...(_Elements) != 1)
        return false;
      else if constexpr (is_same_v<remove_cvref_t<_Tuple>, tuple>)
        return true;
      else {
        using _Tp = typename _Nth_type<0, _Elements...>::type;
        if constexpr (is_convertible_v<_Tuple, _Tp>)
          return true;
        else if constexpr (is_constructible_v<_Tp, _Tuple>)
          return true;
      }
      return false;
    }

    template <typename... _Up> static consteval bool __dangles() {

      return (__reference_constructs_from_temporary(_Elements, _Up &&) || ...);
    }

  public:
    constexpr explicit(!(__is_implicitly_default_constructible_v<_Elements> &&
                         ...))
        tuple() noexcept((is_nothrow_default_constructible_v<_Elements> && ...))
      requires(is_default_constructible_v<_Elements> && ...)
        : _Inherited() {}

    constexpr explicit(!__convertible<const _Elements &...>())
        tuple(const _Elements &...__elements) noexcept(
            __nothrow_constructible<const _Elements &...>())
      requires(__constructible<const _Elements &...>())
        : _Inherited(__elements...) {}

    template <typename... _UTypes>
      requires(__disambiguating_constraint<_UTypes...>()) &&
              (__constructible<_UTypes...>()) && (!__dangles<_UTypes...>())
    constexpr explicit(!__convertible<_UTypes...>())
        tuple(_UTypes &&...__u) noexcept(__nothrow_constructible<_UTypes...>())
        : _Inherited(std::forward<_UTypes>(__u)...) {}

    template <typename... _UTypes>
      requires(__disambiguating_constraint<_UTypes...>()) &&
                  (__constructible<_UTypes...>()) && (__dangles<_UTypes...>())
    tuple(_UTypes &&...) = delete;

    constexpr tuple(const tuple &) = default;

    constexpr tuple(tuple &&) = default;

    template <typename... _UTypes>
      requires(__constructible<const _UTypes &...>()) &&
              (!__use_other_ctor<const tuple<_UTypes...> &>()) &&
              (!__dangles<const _UTypes &...>())
    constexpr explicit(!__convertible<const _UTypes &...>())
        tuple(const tuple<_UTypes...> &__u) noexcept(
            __nothrow_constructible<const _UTypes &...>())
        : _Inherited(static_cast<const _Tuple_impl<0, _UTypes...> &>(__u)) {}

    template <typename... _UTypes>
      requires(__constructible<const _UTypes &...>()) &&
                  (!__use_other_ctor<const tuple<_UTypes...> &>()) &&
                  (__dangles<const _UTypes &...>())
    tuple(const tuple<_UTypes...> &) = delete;

    template <typename... _UTypes>
      requires(__constructible<_UTypes...>()) &&
              (!__use_other_ctor<tuple<_UTypes...>>()) &&
              (!__dangles<_UTypes...>())
    constexpr explicit(!__convertible<_UTypes...>()) tuple(
        tuple<_UTypes...> &&__u) noexcept(__nothrow_constructible<_UTypes...>())
        : _Inherited(static_cast<_Tuple_impl<0, _UTypes...> &&>(__u)) {}

    template <typename... _UTypes>
      requires(__constructible<_UTypes...>()) &&
                  (!__use_other_ctor<tuple<_UTypes...>>()) &&
                  (__dangles<_UTypes...>())
    tuple(tuple<_UTypes...> &&) = delete;
    template <typename _U1, typename _U2>
      requires(sizeof...(_Elements) == 2) &&
              (__constructible<const _U1 &, const _U2 &>()) &&
              (!__dangles<const _U1 &, const _U2 &>())
    constexpr explicit(!__convertible<const _U1 &, const _U2 &>())
        tuple(const pair<_U1, _U2> &__u) noexcept(
            __nothrow_constructible<const _U1 &, const _U2 &>())
        : _Inherited(__u.first, __u.second) {}

    template <typename _U1, typename _U2>
      requires(sizeof...(_Elements) == 2) &&
                  (__constructible<const _U1 &, const _U2 &>()) &&
                  (__dangles<const _U1 &, const _U2 &>())
    tuple(const pair<_U1, _U2> &) = delete;

    template <typename _U1, typename _U2>
      requires(sizeof...(_Elements) == 2) && (__constructible<_U1, _U2>()) &&
              (!__dangles<_U1, _U2>())
    constexpr explicit(!__convertible<_U1, _U2>()) tuple(
        pair<_U1, _U2> &&__u) noexcept(__nothrow_constructible<_U1, _U2>())
        : _Inherited(std::forward<_U1>(__u.first),
                     std::forward<_U2>(__u.second)) {}

    template <typename _U1, typename _U2>
      requires(sizeof...(_Elements) == 2) && (__constructible<_U1, _U2>()) &&
                  (__dangles<_U1, _U2>())
    tuple(pair<_U1, _U2> &&) = delete;
    template <typename _Alloc>
    constexpr explicit(!(__is_implicitly_default_constructible_v<_Elements> &&
                         ...)) tuple(allocator_arg_t __tag, const _Alloc &__a)
      requires(is_default_constructible_v<_Elements> && ...)
        : _Inherited(__tag, __a) {}

    template <typename _Alloc>
    constexpr explicit(!__convertible<const _Elements &...>())
        tuple(allocator_arg_t __tag, const _Alloc &__a,
              const _Elements &...__elements)
      requires(__constructible<const _Elements &...>())
        : _Inherited(__tag, __a, __elements...) {}

    template <typename _Alloc, typename... _UTypes>
      requires(__disambiguating_constraint<_UTypes...>()) &&
              (__constructible<_UTypes...>()) && (!__dangles<_UTypes...>())
    constexpr explicit(!__convertible<_UTypes...>())
        tuple(allocator_arg_t __tag, const _Alloc &__a, _UTypes &&...__u)
        : _Inherited(__tag, __a, std::forward<_UTypes>(__u)...) {}

    template <typename _Alloc, typename... _UTypes>
      requires(__disambiguating_constraint<_UTypes...>()) &&
                  (__constructible<_UTypes...>()) && (__dangles<_UTypes...>())
    tuple(allocator_arg_t, const _Alloc &, _UTypes &&...) = delete;

    template <typename _Alloc>
    constexpr tuple(allocator_arg_t __tag, const _Alloc &__a, const tuple &__u)
        : _Inherited(__tag, __a, static_cast<const _Inherited &>(__u)) {}

    template <typename _Alloc>
      requires(__constructible<_Elements...>())
    constexpr tuple(allocator_arg_t __tag, const _Alloc &__a, tuple &&__u)
        : _Inherited(__tag, __a, static_cast<_Inherited &&>(__u)) {}

    template <typename _Alloc, typename... _UTypes>
      requires(__constructible<const _UTypes &...>()) &&
              (!__use_other_ctor<const tuple<_UTypes...> &>()) &&
              (!__dangles<const _UTypes &...>())
    constexpr explicit(!__convertible<const _UTypes &...>())
        tuple(allocator_arg_t __tag, const _Alloc &__a,
              const tuple<_UTypes...> &__u)
        : _Inherited(__tag, __a,
                     static_cast<const _Tuple_impl<0, _UTypes...> &>(__u)) {}

    template <typename _Alloc, typename... _UTypes>
      requires(__constructible<const _UTypes &...>()) &&
                  (!__use_other_ctor<const tuple<_UTypes...> &>()) &&
                  (__dangles<const _UTypes &...>())
    tuple(allocator_arg_t, const _Alloc &, const tuple<_UTypes...> &) = delete;

    template <typename _Alloc, typename... _UTypes>
      requires(__constructible<_UTypes...>()) &&
              (!__use_other_ctor<tuple<_UTypes...>>()) &&
              (!__dangles<_UTypes...>())
    constexpr explicit(!__use_other_ctor<tuple<_UTypes...>>())
        tuple(allocator_arg_t __tag, const _Alloc &__a, tuple<_UTypes...> &&__u)
        : _Inherited(__tag, __a,
                     static_cast<_Tuple_impl<0, _UTypes...> &&>(__u)) {}

    template <typename _Alloc, typename... _UTypes>
      requires(__constructible<_UTypes...>()) &&
                  (!__use_other_ctor<tuple<_UTypes...>>()) &&
                  (__dangles<_UTypes...>())
    tuple(allocator_arg_t, const _Alloc &, tuple<_UTypes...> &&) = delete;
    template <typename _Alloc, typename _U1, typename _U2>
      requires(sizeof...(_Elements) == 2) &&
              (__constructible<const _U1 &, const _U2 &>()) &&
              (!__dangles<const _U1 &, const _U2 &>())
    constexpr explicit(!__convertible<const _U1 &, const _U2 &>()) tuple(
        allocator_arg_t __tag, const _Alloc &__a,
        const pair<_U1, _U2>
            &__u) noexcept(__nothrow_constructible<const _U1 &, const _U2 &>())
        : _Inherited(__tag, __a, __u.first, __u.second) {}

    template <typename _Alloc, typename _U1, typename _U2>
      requires(sizeof...(_Elements) == 2) &&
                  (__constructible<const _U1 &, const _U2 &>()) &&
                  (__dangles<const _U1 &, const _U2 &>())
    tuple(allocator_arg_t, const _Alloc &, const pair<_U1, _U2> &) = delete;

    template <typename _Alloc, typename _U1, typename _U2>
      requires(sizeof...(_Elements) == 2) && (__constructible<_U1, _U2>()) &&
              (!__dangles<_U1, _U2>())
    constexpr explicit(!__convertible<_U1, _U2>()) tuple(
        allocator_arg_t __tag, const _Alloc &__a,
        pair<_U1, _U2> &&__u) noexcept(__nothrow_constructible<_U1, _U2>())
        : _Inherited(__tag, __a, std::move(__u.first), std::move(__u.second)) {}

    template <typename _Alloc, typename _U1, typename _U2>
      requires(sizeof...(_Elements) == 2) && (__constructible<_U1, _U2>()) &&
                  (__dangles<_U1, _U2>())
    tuple(allocator_arg_t, const _Alloc &, pair<_U1, _U2> &&) = delete;

  private:
    template <typename... _UTypes> static consteval bool __assignable() {
      if constexpr (sizeof...(_UTypes) == sizeof...(_Elements))
        return __and_v<is_assignable<_Elements &, _UTypes>...>;
      else
        return false;
    }

    template <typename... _UTypes>
    static consteval bool __nothrow_assignable() {
      if constexpr (sizeof...(_UTypes) == sizeof...(_Elements))
        return __and_v<is_nothrow_assignable<_Elements &, _UTypes>...>;
      else
        return false;
    }

  public:
    tuple &operator=(const tuple &__u) = delete;

    constexpr tuple &operator=(const tuple &__u) noexcept(
        __nothrow_assignable<const _Elements &...>())
      requires(__assignable<const _Elements &...>())
    {
      this->_M_assign(__u);
      return *this;
    }

    constexpr tuple &
    operator=(tuple &&__u) noexcept(__nothrow_assignable<_Elements...>())
      requires(__assignable<_Elements...>())
    {
      this->_M_assign(std::move(__u));
      return *this;
    }

    template <typename... _UTypes>
      requires(__assignable<const _UTypes &...>())
    constexpr tuple &operator=(const tuple<_UTypes...> &__u) noexcept(
        __nothrow_assignable<const _UTypes &...>()) {
      this->_M_assign(__u);
      return *this;
    }

    template <typename... _UTypes>
      requires(__assignable<_UTypes...>())
    constexpr tuple &operator=(tuple<_UTypes...> &&__u) noexcept(
        __nothrow_assignable<_UTypes...>()) {
      this->_M_assign(std::move(__u));
      return *this;
    }
    template <typename _U1, typename _U2>
      requires(__assignable<const _U1 &, const _U2 &>())
    constexpr tuple &operator=(const pair<_U1, _U2> &__u) noexcept(
        __nothrow_assignable<const _U1 &, const _U2 &>()) {
      this->_M_head(*this) = __u.first;
      this->_M_tail(*this)._M_head(*this) = __u.second;
      return *this;
    }

    template <typename _U1, typename _U2>
      requires(__assignable<_U1, _U2>())
    constexpr tuple &
    operator=(pair<_U1, _U2> &&__u) noexcept(__nothrow_assignable<_U1, _U2>()) {
      this->_M_head(*this) = std::forward<_U1>(__u.first);
      this->_M_tail(*this)._M_head(*this) = std::forward<_U2>(__u.second);
      return *this;
    }
    constexpr void swap(tuple &__in) noexcept(
        __and_<__is_nothrow_swappable<_Elements>...>::value) {
      _Inherited::_M_swap(__in);
    }
  };

  template <typename... _UTypes> tuple(_UTypes...) -> tuple<_UTypes...>;
  template <typename _T1, typename _T2>
  tuple(pair<_T1, _T2>) -> tuple<_T1, _T2>;
  template <typename _Alloc, typename... _UTypes>
  tuple(allocator_arg_t, _Alloc, _UTypes...) -> tuple<_UTypes...>;
  template <typename _Alloc, typename _T1, typename _T2>
  tuple(allocator_arg_t, _Alloc, pair<_T1, _T2>) -> tuple<_T1, _T2>;
  template <typename _Alloc, typename... _UTypes>
  tuple(allocator_arg_t, _Alloc, tuple<_UTypes...>) -> tuple<_UTypes...>;

  template <> class tuple<> {
  public:
    constexpr void swap(tuple &) noexcept {}

    tuple() = default;

    template <typename _Alloc>
    constexpr tuple(allocator_arg_t, const _Alloc &) noexcept {}
    template <typename _Alloc>
    constexpr tuple(allocator_arg_t, const _Alloc &, const tuple &) noexcept {}
  };
  template <typename... _Elements>
  struct tuple_size<tuple<_Elements...>>
      : public integral_constant<size_t, sizeof...(_Elements)> {};

  template <typename... _Types>
  inline constexpr size_t tuple_size_v<tuple<_Types...>> = sizeof...(_Types);

  template <typename... _Types>
  inline constexpr size_t tuple_size_v<const tuple<_Types...>> =
      sizeof...(_Types);

  template <size_t __i, typename... _Types>
  struct tuple_element<__i, tuple<_Types...>> {
    static_assert(__i < sizeof...(_Types), "tuple index must be in range");

    using type = typename _Nth_type<__i, _Types...>::type;
  };

  template <size_t __i, typename _Head, typename... _Tail>
  constexpr _Head &__get_helper(_Tuple_impl<__i, _Head, _Tail...> &
                                __t) noexcept {
    return _Tuple_impl<__i, _Head, _Tail...>::_M_head(__t);
  }

  template <size_t __i, typename _Head, typename... _Tail>
  constexpr const _Head &__get_helper(
      const _Tuple_impl<__i, _Head, _Tail...> &__t) noexcept {
    return _Tuple_impl<__i, _Head, _Tail...>::_M_head(__t);
  }

  template <size_t __i, typename... _Types>
  __enable_if_t<(__i >= sizeof...(_Types))> __get_helper(
      const tuple<_Types...> &) = delete;

  template <size_t __i, typename... _Elements>
  constexpr __tuple_element_t<__i, tuple<_Elements...>> &get(
      tuple<_Elements...> & __t) noexcept {
    return std::__get_helper<__i>(__t);
  }

  template <size_t __i, typename... _Elements>
  constexpr const __tuple_element_t<__i, tuple<_Elements...>> &get(
      const tuple<_Elements...> &__t) noexcept {
    return std::__get_helper<__i>(__t);
  }

  template <size_t __i, typename... _Elements>
  constexpr __tuple_element_t<__i, tuple<_Elements...>> &&get(
      tuple<_Elements...> && __t) noexcept {
    typedef __tuple_element_t<__i, tuple<_Elements...>> __element_type;
    return std::forward<__element_type>(std::__get_helper<__i>(__t));
  }

  template <size_t __i, typename... _Elements>
  constexpr const __tuple_element_t<__i, tuple<_Elements...>> &&get(
      const tuple<_Elements...> &&__t) noexcept {
    typedef __tuple_element_t<__i, tuple<_Elements...>> __element_type;
    return std::forward<const __element_type>(std::__get_helper<__i>(__t));
  }

  template <size_t __i, typename... _Elements>
  constexpr __enable_if_t<(__i >= sizeof...(_Elements))> get(
      const tuple<_Elements...> &) = delete;

  template <typename _Tp, typename... _Types>
  constexpr _Tp &get(tuple<_Types...> & __t) noexcept {
    constexpr size_t __idx = __find_uniq_type_in_pack<_Tp, _Types...>();
    static_assert(
        __idx < sizeof...(_Types),
        "the type T in std::get<T> must occur exactly once in the tuple");
    return std::__get_helper<__idx>(__t);
  }

  template <typename _Tp, typename... _Types>
  constexpr _Tp &&get(tuple<_Types...> && __t) noexcept {
    constexpr size_t __idx = __find_uniq_type_in_pack<_Tp, _Types...>();
    static_assert(
        __idx < sizeof...(_Types),
        "the type T in std::get<T> must occur exactly once in the tuple");
    return std::forward<_Tp>(std::__get_helper<__idx>(__t));
  }

  template <typename _Tp, typename... _Types>
  constexpr const _Tp &get(const tuple<_Types...> &__t) noexcept {
    constexpr size_t __idx = __find_uniq_type_in_pack<_Tp, _Types...>();
    static_assert(
        __idx < sizeof...(_Types),
        "the type T in std::get<T> must occur exactly once in the tuple");
    return std::__get_helper<__idx>(__t);
  }

  template <typename _Tp, typename... _Types>
  constexpr const _Tp &&get(const tuple<_Types...> &&__t) noexcept {
    constexpr size_t __idx = __find_uniq_type_in_pack<_Tp, _Types...>();
    static_assert(
        __idx < sizeof...(_Types),
        "the type T in std::get<T> must occur exactly once in the tuple");
    return std::forward<const _Tp>(std::__get_helper<__idx>(__t));
  }

  template <typename _Tp, typename _Up, size_t __i, size_t __size>
  struct __tuple_compare {
    static constexpr bool __eq(const _Tp &__t, const _Up &__u) {
      return bool(std::get<__i>(__t) == std::get<__i>(__u)) &&
             __tuple_compare<_Tp, _Up, __i + 1, __size>::__eq(__t, __u);
    }

    static constexpr bool __less(const _Tp &__t, const _Up &__u) {
      return bool(std::get<__i>(__t) < std::get<__i>(__u)) ||
             (!bool(std::get<__i>(__u) < std::get<__i>(__t)) &&
              __tuple_compare<_Tp, _Up, __i + 1, __size>::__less(__t, __u));
    }
  };

  template <typename _Tp, typename _Up, size_t __size>
  struct __tuple_compare<_Tp, _Up, __size, __size> {
    static constexpr bool __eq(const _Tp &, const _Up &) { return true; }

    static constexpr bool __less(const _Tp &, const _Up &) { return false; }
  };

  template <typename... _TElements, typename... _UElements>
  constexpr bool operator==(const tuple<_TElements...> &__t,
                            const tuple<_UElements...> &__u) {
    static_assert(
        sizeof...(_TElements) == sizeof...(_UElements),
        "tuple objects can only be compared if they have equal sizes.");
    using __compare =
        __tuple_compare<tuple<_TElements...>, tuple<_UElements...>, 0,
                        sizeof...(_TElements)>;
    return __compare::__eq(__t, __u);
  }

  template <typename _Cat, typename _Tp, typename _Up>
  constexpr _Cat __tuple_cmp(const _Tp &, const _Up &, index_sequence<>) {
    return _Cat::equivalent;
  }

  template <typename _Cat, typename _Tp, typename _Up, size_t _Idx0,
            size_t... _Idxs>
  constexpr _Cat __tuple_cmp(const _Tp &__t, const _Up &__u,
                             index_sequence<_Idx0, _Idxs...>) {
    auto __c =
        __detail::__synth3way(std::get<_Idx0>(__t), std::get<_Idx0>(__u));
    if (__c != 0)
      return __c;
    return std::__tuple_cmp<_Cat>(__t, __u, index_sequence<_Idxs...>());
  }

  template <typename... _Tps, typename... _Ups>
  constexpr common_comparison_category_t<__detail::__synth3way_t<_Tps, _Ups>...>
  operator<=>(const tuple<_Tps...> &__t, const tuple<_Ups...> &__u) {
    using _Cat =
        common_comparison_category_t<__detail::__synth3way_t<_Tps, _Ups>...>;
    return std::__tuple_cmp<_Cat>(__t, __u, index_sequence_for<_Tps...>());
  }
  template <typename... _Elements>
  constexpr tuple<typename __decay_and_strip<_Elements>::__type...> make_tuple(
      _Elements && ...__args) {
    typedef tuple<typename __decay_and_strip<_Elements>::__type...>
        __result_type;
    return __result_type(std::forward<_Elements>(__args)...);
  }

  template <typename... _Elements>
  constexpr tuple<_Elements &&...> forward_as_tuple(_Elements &&
                                                    ...__args) noexcept {
    return tuple<_Elements &&...>(std::forward<_Elements>(__args)...);
  }

  template <size_t, typename, typename, size_t> struct __make_tuple_impl;

  template <size_t _Idx, typename _Tuple, typename... _Tp, size_t _Nm>
  struct __make_tuple_impl<_Idx, tuple<_Tp...>, _Tuple, _Nm>
      : __make_tuple_impl<_Idx + 1,
                          tuple<_Tp..., __tuple_element_t<_Idx, _Tuple>>,
                          _Tuple, _Nm> {};

  template <size_t _Nm, typename _Tuple, typename... _Tp>
  struct __make_tuple_impl<_Nm, tuple<_Tp...>, _Tuple, _Nm> {
    typedef tuple<_Tp...> __type;
  };

  template <typename _Tuple>
  struct __do_make_tuple
      : __make_tuple_impl<0, tuple<>, _Tuple, tuple_size<_Tuple>::value> {};

  template <typename _Tuple>
  struct __make_tuple : public __do_make_tuple<__remove_cvref_t<_Tuple>> {};

  template <typename...> struct __combine_tuples;

  template <> struct __combine_tuples<> {
    typedef tuple<> __type;
  };

  template <typename... _Ts> struct __combine_tuples<tuple<_Ts...>> {
    typedef tuple<_Ts...> __type;
  };

  template <typename... _T1s, typename... _T2s, typename... _Rem>
  struct __combine_tuples<tuple<_T1s...>, tuple<_T2s...>, _Rem...> {
    typedef typename __combine_tuples<tuple<_T1s..., _T2s...>, _Rem...>::__type
        __type;
  };

  template <typename... _Tpls> struct __tuple_cat_result {
    typedef typename __combine_tuples<
        typename __make_tuple<_Tpls>::__type...>::__type __type;
  };

  template <typename...> struct __make_1st_indices;

  template <> struct __make_1st_indices<> {
    typedef _Index_tuple<> __type;
  };

  template <typename _Tp, typename... _Tpls>
  struct __make_1st_indices<_Tp, _Tpls...> {
    typedef typename _Build_index_tuple<
        tuple_size<typename remove_reference<_Tp>::type>::value>::__type __type;
  };

  template <typename _Ret, typename _Indices, typename... _Tpls>
  struct __tuple_concater;

  template <typename _Ret, size_t... _Is, typename _Tp, typename... _Tpls>
  struct __tuple_concater<_Ret, _Index_tuple<_Is...>, _Tp, _Tpls...> {
    template <typename... _Us>
    static constexpr _Ret _S_do(_Tp &&__tp, _Tpls &&...__tps, _Us &&...__us) {
      typedef typename __make_1st_indices<_Tpls...>::__type __idx;
      typedef __tuple_concater<_Ret, __idx, _Tpls...> __next;
      return __next::_S_do(std::forward<_Tpls>(__tps)...,
                           std::forward<_Us>(__us)...,
                           std::get<_Is>(std::forward<_Tp>(__tp))...);
    }
  };

  template <typename _Ret> struct __tuple_concater<_Ret, _Index_tuple<>> {
    template <typename... _Us> static constexpr _Ret _S_do(_Us &&...__us) {
      return _Ret(std::forward<_Us>(__us)...);
    }
  };

  template <typename... _Tps>
  struct __is_tuple_like_impl<tuple<_Tps...>> : true_type {};

  template <typename... _Tpls, typename = typename enable_if<__and_<
                                   __is_tuple_like<_Tpls>...>::value>::type>

  constexpr auto tuple_cat(_Tpls && ...__tpls) ->
      typename __tuple_cat_result<_Tpls...>::__type {
    typedef typename __tuple_cat_result<_Tpls...>::__type __ret;
    typedef typename __make_1st_indices<_Tpls...>::__type __idx;
    typedef __tuple_concater<__ret, __idx, _Tpls...> __concater;
    return __concater::_S_do(std::forward<_Tpls>(__tpls)...);
  }

  template <typename... _Elements>
  constexpr tuple<_Elements &...> tie(_Elements & ...__args) noexcept {
    return tuple<_Elements &...>(__args...);
  }

  template <typename... _Elements>
  constexpr inline

      typename enable_if<__and_<__is_swappable<_Elements>...>::value>::type

      swap(tuple<_Elements...> & __x,
           tuple<_Elements...> & __y) noexcept(noexcept(__x.swap(__y))) {
    __x.swap(__y);
  }
  template <typename... _Elements>
  constexpr
      typename enable_if<!__and_<__is_swappable<_Elements>...>::value>::type
      swap(tuple<_Elements...> &, tuple<_Elements...> &) = delete;

  struct _Swallow_assign {
    template <class _Tp>
    constexpr const _Swallow_assign &operator=(const _Tp &) const {
      return *this;
    }
  };
  inline constexpr _Swallow_assign ignore{};

  template <typename... _Types, typename _Alloc>
  struct uses_allocator<tuple<_Types...>, _Alloc> : true_type {};
  template <class _T1, class _T2>
  template <typename... _Args1, typename... _Args2>
  constexpr inline pair<_T1, _T2>::pair(piecewise_construct_t,
                                        tuple<_Args1...> __first,
                                        tuple<_Args2...> __second)
      : pair(__first, __second,
             typename _Build_index_tuple<sizeof...(_Args1)>::__type(),
             typename _Build_index_tuple<sizeof...(_Args2)>::__type()) {}

  template <class _T1, class _T2>
  template <typename... _Args1, size_t... _Indexes1, typename... _Args2,
            size_t... _Indexes2>
  constexpr inline pair<_T1, _T2>::pair(
      tuple<_Args1...> & __tuple1, tuple<_Args2...> & __tuple2,
      _Index_tuple<_Indexes1...>, _Index_tuple<_Indexes2...>)
      : first(std::forward<_Args1>(std::get<_Indexes1>(__tuple1))...),
        second(std::forward<_Args2>(std::get<_Indexes2>(__tuple2))...) {}

  template <template <typename...> class _Trait, typename _Tp, typename _Tuple>
  inline constexpr bool __unpack_std_tuple = false;

  template <template <typename...> class _Trait, typename _Tp, typename... _Up>
  inline constexpr bool __unpack_std_tuple<_Trait, _Tp, tuple<_Up...>> =
      _Trait<_Tp, _Up...>::value;

  template <template <typename...> class _Trait, typename _Tp, typename... _Up>
  inline constexpr bool __unpack_std_tuple<_Trait, _Tp, tuple<_Up...> &> =
      _Trait<_Tp, _Up &...>::value;

  template <template <typename...> class _Trait, typename _Tp, typename... _Up>
  inline constexpr bool __unpack_std_tuple<_Trait, _Tp, const tuple<_Up...>> =
      _Trait<_Tp, const _Up...>::value;

  template <template <typename...> class _Trait, typename _Tp, typename... _Up>
  inline constexpr bool __unpack_std_tuple<_Trait, _Tp, const tuple<_Up...> &> =
      _Trait<_Tp, const _Up &...>::value;

  template <typename _Fn, typename _Tuple, size_t... _Idx>
  constexpr decltype(auto) __apply_impl(_Fn && __f, _Tuple && __t,
                                        index_sequence<_Idx...>) {
    return std::__invoke(std::forward<_Fn>(__f),
                         std::get<_Idx>(std::forward<_Tuple>(__t))...);
  }

  template <typename _Fn, typename _Tuple>

  constexpr decltype(auto) apply(_Fn && __f, _Tuple && __t) noexcept(
      __unpack_std_tuple<is_nothrow_invocable, _Fn, _Tuple>) {
    using _Indices =
        make_index_sequence<tuple_size_v<remove_reference_t<_Tuple>>>;
    return std::__apply_impl(std::forward<_Fn>(__f), std::forward<_Tuple>(__t),
                             _Indices{});
  }

  template <typename _Tp, typename _Tuple, size_t... _Idx>
  constexpr _Tp __make_from_tuple_impl(_Tuple && __t, index_sequence<_Idx...>) {
    return _Tp(std::get<_Idx>(std::forward<_Tuple>(__t))...);
  }

  template <typename _Tp, typename _Tuple>

  constexpr _Tp make_from_tuple(_Tuple && __t) noexcept(
      __unpack_std_tuple<is_nothrow_constructible, _Tp, _Tuple>) {
    constexpr size_t __n = tuple_size_v<remove_reference_t<_Tuple>>;

    if constexpr (__n == 1) {
      using _Elt = decltype(std::get<0>(std::declval<_Tuple>()));
      static_assert(!__reference_constructs_from_temporary(_Tp, _Elt));
    }

    return __make_from_tuple_impl<_Tp>(std::forward<_Tuple>(__t),
                                       make_index_sequence<__n>{});
  }

} // namespace std

namespace std {

size_t _Hash_bytes(const void *__ptr, size_t __len, size_t __seed);

size_t _Fnv_hash_bytes(const void *__ptr, size_t __len, size_t __seed);

} // namespace std

namespace std __attribute__((__visibility__("default"))) {

  template <typename _Result, typename _Arg> struct __hash_base {
    typedef _Result result_type [[__deprecated__]];
    typedef _Arg argument_type [[__deprecated__]];
  };

  template <typename _Tp> struct hash;

  template <typename _Tp, typename = void> struct __poison_hash {
    static constexpr bool __enable_hash_call = false;

  private:
    __poison_hash(__poison_hash &&);
    ~__poison_hash();
  };

  template <typename _Tp>
  struct __poison_hash<_Tp, __void_t<decltype(hash<_Tp>()(declval<_Tp>()))>> {
    static constexpr bool __enable_hash_call = true;
  };

  template <typename _Tp, bool = is_enum<_Tp>::value> struct __hash_enum {
  private:
    __hash_enum(__hash_enum &&);
    ~__hash_enum();
  };

  template <typename _Tp>
  struct __hash_enum<_Tp, true> : public __hash_base<size_t, _Tp> {
    size_t operator()(_Tp __val) const noexcept {
      using __type = typename underlying_type<_Tp>::type;
      return hash<__type>{}(static_cast<__type>(__val));
    }
  };

  template <typename _Tp> struct hash : __hash_enum<_Tp> {};

  template <typename _Tp>
  struct hash<_Tp *> : public __hash_base<size_t, _Tp *> {
    size_t operator()(_Tp *__p) const noexcept {
      return reinterpret_cast<size_t>(__p);
    }
  };
  template <> struct hash<bool> : public __hash_base<size_t, bool> {
    size_t operator()(bool __val) const noexcept {
      return static_cast<size_t>(__val);
    }
  };

  template <> struct hash<char> : public __hash_base<size_t, char> {
    size_t operator()(char __val) const noexcept {
      return static_cast<size_t>(__val);
    }
  };

  template <>
  struct hash<signed char> : public __hash_base<size_t, signed char> {
    size_t operator()(signed char __val) const noexcept {
      return static_cast<size_t>(__val);
    }
  };

  template <>
  struct hash<unsigned char> : public __hash_base<size_t, unsigned char> {
    size_t operator()(unsigned char __val) const noexcept {
      return static_cast<size_t>(__val);
    }
  };

  template <> struct hash<wchar_t> : public __hash_base<size_t, wchar_t> {
    size_t operator()(wchar_t __val) const noexcept {
      return static_cast<size_t>(__val);
    }
  };

  template <> struct hash<char8_t> : public __hash_base<size_t, char8_t> {
    size_t operator()(char8_t __val) const noexcept {
      return static_cast<size_t>(__val);
    }
  };

  template <> struct hash<char16_t> : public __hash_base<size_t, char16_t> {
    size_t operator()(char16_t __val) const noexcept {
      return static_cast<size_t>(__val);
    }
  };

  template <> struct hash<char32_t> : public __hash_base<size_t, char32_t> {
    size_t operator()(char32_t __val) const noexcept {
      return static_cast<size_t>(__val);
    }
  };

  template <> struct hash<short> : public __hash_base<size_t, short> {
    size_t operator()(short __val) const noexcept {
      return static_cast<size_t>(__val);
    }
  };

  template <> struct hash<int> : public __hash_base<size_t, int> {
    size_t operator()(int __val) const noexcept {
      return static_cast<size_t>(__val);
    }
  };

  template <> struct hash<long> : public __hash_base<size_t, long> {
    size_t operator()(long __val) const noexcept {
      return static_cast<size_t>(__val);
    }
  };

  template <> struct hash<long long> : public __hash_base<size_t, long long> {
    size_t operator()(long long __val) const noexcept {
      return static_cast<size_t>(__val);
    }
  };

  template <>
  struct hash<unsigned short> : public __hash_base<size_t, unsigned short> {
    size_t operator()(unsigned short __val) const noexcept {
      return static_cast<size_t>(__val);
    }
  };

  template <>
  struct hash<unsigned int> : public __hash_base<size_t, unsigned int> {
    size_t operator()(unsigned int __val) const noexcept {
      return static_cast<size_t>(__val);
    }
  };

  template <>
  struct hash<unsigned long> : public __hash_base<size_t, unsigned long> {
    size_t operator()(unsigned long __val) const noexcept {
      return static_cast<size_t>(__val);
    }
  };

  template <>
  struct hash<unsigned long long>
      : public __hash_base<size_t, unsigned long long> {
    size_t operator()(unsigned long long __val) const noexcept {
      return static_cast<size_t>(__val);
    }
  };

  __extension__ template <>
  struct hash<__int128> : public __hash_base<size_t, __int128> {
    size_t operator()(__int128 __val) const noexcept {
      return static_cast<size_t>(__val);
    }
  };
  __extension__ template <>
  struct hash<__int128 unsigned>
      : public __hash_base<size_t, __int128 unsigned> {
    size_t operator()(__int128 unsigned __val) const noexcept {
      return static_cast<size_t>(__val);
    }
  };
  struct _Hash_impl {
    static size_t hash(const void *__ptr, size_t __clength,
                       size_t __seed = static_cast<size_t>(0xc70f6907UL)) {
      return _Hash_bytes(__ptr, __clength, __seed);
    }

    template <typename _Tp> static size_t hash(const _Tp &__val) {
      return hash(&__val, sizeof(__val));
    }

    template <typename _Tp>
    static size_t __hash_combine(const _Tp &__val, size_t __hash) {
      return hash(&__val, sizeof(__val), __hash);
    }
  };

  struct _Fnv_hash_impl {
    static size_t hash(const void *__ptr, size_t __clength,
                       size_t __seed = static_cast<size_t>(2166136261UL)) {
      return _Fnv_hash_bytes(__ptr, __clength, __seed);
    }

    template <typename _Tp> static size_t hash(const _Tp &__val) {
      return hash(&__val, sizeof(__val));
    }

    template <typename _Tp>
    static size_t __hash_combine(const _Tp &__val, size_t __hash) {
      return hash(&__val, sizeof(__val), __hash);
    }
  };

  template <> struct hash<float> : public __hash_base<size_t, float> {
    size_t operator()(float __val) const noexcept {

      return __val != 0.0f ? std::_Hash_impl::hash(__val) : 0;
    }
  };

  template <> struct hash<double> : public __hash_base<size_t, double> {
    size_t operator()(double __val) const noexcept {

      return __val != 0.0 ? std::_Hash_impl::hash(__val) : 0;
    }
  };

  template <>
  struct hash<long double> : public __hash_base<size_t, long double> {
    __attribute__((__pure__)) size_t
    operator()(long double __val) const noexcept;
  };

  template <> struct hash<nullptr_t> : public __hash_base<size_t, nullptr_t> {
    size_t operator()(nullptr_t) const noexcept { return 0; }
  };
  template <typename _Hash> struct __is_fast_hash : public std::true_type {};

  template <>
  struct __is_fast_hash<hash<long double>> : public std::false_type {};

} // namespace std
namespace std __attribute__((__visibility__("default"))) {

  void __throw_bad_exception(void) __attribute__((__noreturn__));

  void __throw_bad_alloc(void) __attribute__((__noreturn__));

  void __throw_bad_array_new_length(void) __attribute__((__noreturn__));

  void __throw_bad_cast(void) __attribute__((__noreturn__, __cold__));

  void __throw_bad_typeid(void) __attribute__((__noreturn__, __cold__));

  void __throw_logic_error(const char *)
      __attribute__((__noreturn__, __cold__));

  void __throw_domain_error(const char *)
      __attribute__((__noreturn__, __cold__));

  void __throw_invalid_argument(const char *)
      __attribute__((__noreturn__, __cold__));

  void __throw_length_error(const char *)
      __attribute__((__noreturn__, __cold__));

  void __throw_out_of_range(const char *)
      __attribute__((__noreturn__, __cold__));

  void __throw_out_of_range_fmt(const char *, ...)
      __attribute__((__noreturn__, __cold__))
      __attribute__((__format__(__gnu_printf__, 1, 2)));

  void __throw_runtime_error(const char *)
      __attribute__((__noreturn__, __cold__));

  void __throw_range_error(const char *)
      __attribute__((__noreturn__, __cold__));

  void __throw_overflow_error(const char *)
      __attribute__((__noreturn__, __cold__));

  void __throw_underflow_error(const char *)
      __attribute__((__noreturn__, __cold__));

  void __throw_ios_failure(const char *)
      __attribute__((__noreturn__, __cold__));

  void __throw_ios_failure(const char *, int)
      __attribute__((__noreturn__, __cold__));

  void __throw_system_error(int) __attribute__((__noreturn__, __cold__));

  void __throw_future_error(int) __attribute__((__noreturn__, __cold__));

  void __throw_bad_function_call() __attribute__((__noreturn__, __cold__));

} // namespace std
namespace std {
namespace __debug {}
} // namespace std

namespace __gnu_debug {
using namespace std::__debug;

template <typename _Ite, typename _Seq, typename _Cat> struct _Safe_iterator;
} // namespace __gnu_debug

namespace __gnu_cxx {
namespace __ops {
struct _Iter_less_iter {
  template <typename _Iterator1, typename _Iterator2>
  constexpr bool operator()(_Iterator1 __it1, _Iterator2 __it2) const {
    return *__it1 < *__it2;
  }
};

constexpr inline _Iter_less_iter __iter_less_iter() {
  return _Iter_less_iter();
}

struct _Iter_less_val {

  constexpr _Iter_less_val() = default;

  constexpr explicit _Iter_less_val(_Iter_less_iter) {}

  template <typename _Iterator, typename _Value>
  constexpr bool operator()(_Iterator __it, _Value &__val) const {
    return *__it < __val;
  }
};

constexpr inline _Iter_less_val __iter_less_val() { return _Iter_less_val(); }

constexpr inline _Iter_less_val __iter_comp_val(_Iter_less_iter) {
  return _Iter_less_val();
}

struct _Val_less_iter {

  constexpr _Val_less_iter() = default;

  constexpr explicit _Val_less_iter(_Iter_less_iter) {}

  template <typename _Value, typename _Iterator>
  constexpr bool operator()(_Value &__val, _Iterator __it) const {
    return __val < *__it;
  }
};

constexpr inline _Val_less_iter __val_less_iter() { return _Val_less_iter(); }

constexpr inline _Val_less_iter __val_comp_iter(_Iter_less_iter) {
  return _Val_less_iter();
}

struct _Iter_equal_to_iter {
  template <typename _Iterator1, typename _Iterator2>
  constexpr bool operator()(_Iterator1 __it1, _Iterator2 __it2) const {
    return *__it1 == *__it2;
  }
};

constexpr inline _Iter_equal_to_iter __iter_equal_to_iter() {
  return _Iter_equal_to_iter();
}

struct _Iter_equal_to_val {
  template <typename _Iterator, typename _Value>
  constexpr bool operator()(_Iterator __it, _Value &__val) const {
    return *__it == __val;
  }
};

constexpr inline _Iter_equal_to_val __iter_equal_to_val() {
  return _Iter_equal_to_val();
}

constexpr inline _Iter_equal_to_val __iter_comp_val(_Iter_equal_to_iter) {
  return _Iter_equal_to_val();
}

template <typename _Compare> struct _Iter_comp_iter {
  _Compare _M_comp;

  explicit constexpr _Iter_comp_iter(_Compare __comp)
      : _M_comp(std::move(__comp)) {}

  template <typename _Iterator1, typename _Iterator2>
  constexpr bool operator()(_Iterator1 __it1, _Iterator2 __it2) {
    return bool(_M_comp(*__it1, *__it2));
  }
};

template <typename _Compare>
constexpr inline _Iter_comp_iter<_Compare> __iter_comp_iter(_Compare __comp) {
  return _Iter_comp_iter<_Compare>(std::move(__comp));
}

template <typename _Compare> struct _Iter_comp_val {
  _Compare _M_comp;

  constexpr explicit _Iter_comp_val(_Compare __comp)
      : _M_comp(std::move(__comp)) {}

  constexpr explicit _Iter_comp_val(const _Iter_comp_iter<_Compare> &__comp)
      : _M_comp(__comp._M_comp) {}

  constexpr explicit _Iter_comp_val(_Iter_comp_iter<_Compare> &&__comp)
      : _M_comp(std::move(__comp._M_comp)) {}

  template <typename _Iterator, typename _Value>
  constexpr bool operator()(_Iterator __it, _Value &__val) {
    return bool(_M_comp(*__it, __val));
  }
};

template <typename _Compare>
constexpr inline _Iter_comp_val<_Compare> __iter_comp_val(_Compare __comp) {
  return _Iter_comp_val<_Compare>(std::move(__comp));
}

template <typename _Compare>
constexpr inline _Iter_comp_val<_Compare>
__iter_comp_val(_Iter_comp_iter<_Compare> __comp) {
  return _Iter_comp_val<_Compare>(std::move(__comp));
}

template <typename _Compare> struct _Val_comp_iter {
  _Compare _M_comp;

  constexpr explicit _Val_comp_iter(_Compare __comp)
      : _M_comp(std::move(__comp)) {}

  constexpr explicit _Val_comp_iter(const _Iter_comp_iter<_Compare> &__comp)
      : _M_comp(__comp._M_comp) {}

  constexpr explicit _Val_comp_iter(_Iter_comp_iter<_Compare> &&__comp)
      : _M_comp(std::move(__comp._M_comp)) {}

  template <typename _Value, typename _Iterator>
  constexpr bool operator()(_Value &__val, _Iterator __it) {
    return bool(_M_comp(__val, *__it));
  }
};

template <typename _Compare>
constexpr inline _Val_comp_iter<_Compare> __val_comp_iter(_Compare __comp) {
  return _Val_comp_iter<_Compare>(std::move(__comp));
}

template <typename _Compare>
constexpr inline _Val_comp_iter<_Compare>
__val_comp_iter(_Iter_comp_iter<_Compare> __comp) {
  return _Val_comp_iter<_Compare>(std::move(__comp));
}

template <typename _Value> struct _Iter_equals_val {
  _Value &_M_value;

  constexpr explicit _Iter_equals_val(_Value &__value) : _M_value(__value) {}

  template <typename _Iterator> constexpr bool operator()(_Iterator __it) {
    return *__it == _M_value;
  }
};

template <typename _Value>
constexpr inline _Iter_equals_val<_Value> __iter_equals_val(_Value &__val) {
  return _Iter_equals_val<_Value>(__val);
}

template <typename _Iterator1> struct _Iter_equals_iter {
  _Iterator1 _M_it1;

  constexpr explicit _Iter_equals_iter(_Iterator1 __it1) : _M_it1(__it1) {}

  template <typename _Iterator2> constexpr bool operator()(_Iterator2 __it2) {
    return *__it2 == *_M_it1;
  }
};

template <typename _Iterator>
constexpr inline _Iter_equals_iter<_Iterator>
__iter_comp_iter(_Iter_equal_to_iter, _Iterator __it) {
  return _Iter_equals_iter<_Iterator>(__it);
}

template <typename _Predicate> struct _Iter_pred {
  _Predicate _M_pred;

  constexpr explicit _Iter_pred(_Predicate __pred)
      : _M_pred(std::move(__pred)) {}

  template <typename _Iterator> constexpr bool operator()(_Iterator __it) {
    return bool(_M_pred(*__it));
  }
};

template <typename _Predicate>
constexpr inline _Iter_pred<_Predicate> __pred_iter(_Predicate __pred) {
  return _Iter_pred<_Predicate>(std::move(__pred));
}

template <typename _Compare, typename _Value> struct _Iter_comp_to_val {
  _Compare _M_comp;
  _Value &_M_value;

  constexpr _Iter_comp_to_val(_Compare __comp, _Value &__value)
      : _M_comp(std::move(__comp)), _M_value(__value) {}

  template <typename _Iterator> constexpr bool operator()(_Iterator __it) {
    return bool(_M_comp(*__it, _M_value));
  }
};

template <typename _Compare, typename _Value>
_Iter_comp_to_val<_Compare, _Value> constexpr __iter_comp_val(_Compare __comp,
                                                              _Value &__val) {
  return _Iter_comp_to_val<_Compare, _Value>(std::move(__comp), __val);
}

template <typename _Compare, typename _Iterator1> struct _Iter_comp_to_iter {
  _Compare _M_comp;
  _Iterator1 _M_it1;

  constexpr _Iter_comp_to_iter(_Compare __comp, _Iterator1 __it1)
      : _M_comp(std::move(__comp)), _M_it1(__it1) {}

  template <typename _Iterator2> constexpr bool operator()(_Iterator2 __it2) {
    return bool(_M_comp(*__it2, *_M_it1));
  }
};

template <typename _Compare, typename _Iterator>
constexpr inline _Iter_comp_to_iter<_Compare, _Iterator>
__iter_comp_iter(_Iter_comp_iter<_Compare> __comp, _Iterator __it) {
  return _Iter_comp_to_iter<_Compare, _Iterator>(std::move(__comp._M_comp),
                                                 __it);
}

template <typename _Predicate> struct _Iter_negate {
  _Predicate _M_pred;

  constexpr explicit _Iter_negate(_Predicate __pred)
      : _M_pred(std::move(__pred)) {}

  template <typename _Iterator> constexpr bool operator()(_Iterator __it) {
    return !bool(_M_pred(*__it));
  }
};

template <typename _Predicate>
constexpr inline _Iter_negate<_Predicate>
__negate(_Iter_pred<_Predicate> __pred) {
  return _Iter_negate<_Predicate>(std::move(__pred._M_pred));
}

} // namespace __ops
} // namespace __gnu_cxx

namespace std __attribute__((__visibility__("default"))) {

  template <typename _To, typename _From>
  [[nodiscard]]
  constexpr _To bit_cast(const _From &__from) noexcept

    requires(sizeof(_To) == sizeof(_From)) && is_trivially_copyable_v<_To> &&
            is_trivially_copyable_v<_From>

  {
    return __builtin_bit_cast(_To, __from);
  }
  template <typename _Tp> constexpr _Tp __rotl(_Tp __x, int __s) noexcept {
    constexpr auto _Nd = __gnu_cxx::__int_traits<_Tp>::__digits;
    if constexpr ((_Nd & (_Nd - 1)) == 0) {

      constexpr unsigned __uNd = _Nd;
      const unsigned __r = __s;
      return (__x << (__r % __uNd)) | (__x >> ((-__r) % __uNd));
    }
    const int __r = __s % _Nd;
    if (__r == 0)
      return __x;
    else if (__r > 0)
      return (__x << __r) | (__x >> ((_Nd - __r) % _Nd));
    else
      return (__x >> -__r) | (__x << ((_Nd + __r) % _Nd));
  }

  template <typename _Tp> constexpr _Tp __rotr(_Tp __x, int __s) noexcept {
    constexpr auto _Nd = __gnu_cxx::__int_traits<_Tp>::__digits;
    if constexpr ((_Nd & (_Nd - 1)) == 0) {

      constexpr unsigned __uNd = _Nd;
      const unsigned __r = __s;
      return (__x >> (__r % __uNd)) | (__x << ((-__r) % __uNd));
    }
    const int __r = __s % _Nd;
    if (__r == 0)
      return __x;
    else if (__r > 0)
      return (__x >> __r) | (__x << ((_Nd - __r) % _Nd));
    else
      return (__x << -__r) | (__x >> ((_Nd + __r) % _Nd));
  }

  template <typename _Tp> constexpr int __countl_zero(_Tp __x) noexcept {
    using __gnu_cxx::__int_traits;
    constexpr auto _Nd = __int_traits<_Tp>::__digits;

    if (__x == 0)
      return _Nd;

    constexpr auto _Nd_ull = __int_traits<unsigned long long>::__digits;
    constexpr auto _Nd_ul = __int_traits<unsigned long>::__digits;
    constexpr auto _Nd_u = __int_traits<unsigned>::__digits;

    if constexpr (_Nd <= _Nd_u) {
      constexpr int __diff = _Nd_u - _Nd;
      return __builtin_clz(__x) - __diff;
    } else if constexpr (_Nd <= _Nd_ul) {
      constexpr int __diff = _Nd_ul - _Nd;
      return __builtin_clzl(__x) - __diff;
    } else if constexpr (_Nd <= _Nd_ull) {
      constexpr int __diff = _Nd_ull - _Nd;
      return __builtin_clzll(__x) - __diff;
    } else {
      static_assert(_Nd <= (2 * _Nd_ull),
                    "Maximum supported integer size is 128-bit");

      unsigned long long __high = __x >> _Nd_ull;
      if (__high != 0) {
        constexpr int __diff = (2 * _Nd_ull) - _Nd;
        return __builtin_clzll(__high) - __diff;
      }
      constexpr auto __max_ull = __int_traits<unsigned long long>::__max;
      unsigned long long __low = __x & __max_ull;
      return (_Nd - _Nd_ull) + __builtin_clzll(__low);
    }
  }

  template <typename _Tp> constexpr int __countl_one(_Tp __x) noexcept {
    return std::__countl_zero<_Tp>((_Tp)~__x);
  }

  template <typename _Tp> constexpr int __countr_zero(_Tp __x) noexcept {
    using __gnu_cxx::__int_traits;
    constexpr auto _Nd = __int_traits<_Tp>::__digits;

    if (__x == 0)
      return _Nd;

    constexpr auto _Nd_ull = __int_traits<unsigned long long>::__digits;
    constexpr auto _Nd_ul = __int_traits<unsigned long>::__digits;
    constexpr auto _Nd_u = __int_traits<unsigned>::__digits;

    if constexpr (_Nd <= _Nd_u)
      return __builtin_ctz(__x);
    else if constexpr (_Nd <= _Nd_ul)
      return __builtin_ctzl(__x);
    else if constexpr (_Nd <= _Nd_ull)
      return __builtin_ctzll(__x);
    else {
      static_assert(_Nd <= (2 * _Nd_ull),
                    "Maximum supported integer size is 128-bit");

      constexpr auto __max_ull = __int_traits<unsigned long long>::__max;
      unsigned long long __low = __x & __max_ull;
      if (__low != 0)
        return __builtin_ctzll(__low);
      unsigned long long __high = __x >> _Nd_ull;
      return __builtin_ctzll(__high) + _Nd_ull;
    }
  }

  template <typename _Tp> constexpr int __countr_one(_Tp __x) noexcept {
    return std::__countr_zero((_Tp)~__x);
  }

  template <typename _Tp> constexpr int __popcount(_Tp __x) noexcept {
    using __gnu_cxx::__int_traits;
    constexpr auto _Nd = __int_traits<_Tp>::__digits;

    constexpr auto _Nd_ull = __int_traits<unsigned long long>::__digits;
    constexpr auto _Nd_ul = __int_traits<unsigned long>::__digits;
    constexpr auto _Nd_u = __int_traits<unsigned>::__digits;

    if constexpr (_Nd <= _Nd_u)
      return __builtin_popcount(__x);
    else if constexpr (_Nd <= _Nd_ul)
      return __builtin_popcountl(__x);
    else if constexpr (_Nd <= _Nd_ull)
      return __builtin_popcountll(__x);
    else {
      static_assert(_Nd <= (2 * _Nd_ull),
                    "Maximum supported integer size is 128-bit");

      constexpr auto __max_ull = __int_traits<unsigned long long>::__max;
      unsigned long long __low = __x & __max_ull;
      unsigned long long __high = __x >> _Nd_ull;
      return __builtin_popcountll(__low) + __builtin_popcountll(__high);
    }
  }

  template <typename _Tp> constexpr bool __has_single_bit(_Tp __x) noexcept {
    return std::__popcount(__x) == 1;
  }

  template <typename _Tp> constexpr _Tp __bit_ceil(_Tp __x) noexcept {
    using __gnu_cxx::__int_traits;
    constexpr auto _Nd = __int_traits<_Tp>::__digits;
    if (__x == 0 || __x == 1)
      return 1;
    auto __shift_exponent = _Nd - std::__countl_zero((_Tp)(__x - 1u));

    if (!std::__is_constant_evaluated()) {
      do {
        if (std::__is_constant_evaluated())
          if (__builtin_expect(
                  !bool(__shift_exponent != __int_traits<_Tp>::__digits),
                  false))
            std::__glibcxx_assert_fail();
      } while (false);
    }

    using __promoted_type = decltype(__x << 1);
    if constexpr (!is_same<__promoted_type, _Tp>::value) {

      const int __extra_exp = sizeof(__promoted_type) / sizeof(_Tp) / 2;
      __shift_exponent |= (__shift_exponent & _Nd) << __extra_exp;
    }
    return (_Tp)1u << __shift_exponent;
  }

  template <typename _Tp> constexpr _Tp __bit_floor(_Tp __x) noexcept {
    constexpr auto _Nd = __gnu_cxx::__int_traits<_Tp>::__digits;
    if (__x == 0)
      return 0;
    return (_Tp)1u << (_Nd - std::__countl_zero((_Tp)(__x >> 1)));
  }

  template <typename _Tp> constexpr int __bit_width(_Tp __x) noexcept {
    constexpr auto _Nd = __gnu_cxx::__int_traits<_Tp>::__digits;
    return _Nd - std::__countl_zero(__x);
  }

  template <typename _Tp>
  concept __unsigned_integer = __is_unsigned_integer<_Tp>::value;

  template <__unsigned_integer _Tp>
  [[nodiscard]] constexpr _Tp rotl(_Tp __x, int __s) noexcept {
    return std::__rotl(__x, __s);
  }

  template <__unsigned_integer _Tp>
  [[nodiscard]] constexpr _Tp rotr(_Tp __x, int __s) noexcept {
    return std::__rotr(__x, __s);
  }

  template <__unsigned_integer _Tp>
  constexpr int countl_zero(_Tp __x) noexcept {
    return std::__countl_zero(__x);
  }

  template <__unsigned_integer _Tp> constexpr int countl_one(_Tp __x) noexcept {
    return std::__countl_one(__x);
  }

  template <__unsigned_integer _Tp>
  constexpr int countr_zero(_Tp __x) noexcept {
    return std::__countr_zero(__x);
  }

  template <__unsigned_integer _Tp> constexpr int countr_one(_Tp __x) noexcept {
    return std::__countr_one(__x);
  }

  template <__unsigned_integer _Tp> constexpr int popcount(_Tp __x) noexcept {
    return std::__popcount(__x);
  }

  template <__unsigned_integer _Tp>
  constexpr bool has_single_bit(_Tp __x) noexcept {
    return std::__has_single_bit(__x);
  }

  template <__unsigned_integer _Tp> constexpr _Tp bit_ceil(_Tp __x) noexcept {
    return std::__bit_ceil(__x);
  }

  template <__unsigned_integer _Tp> constexpr _Tp bit_floor(_Tp __x) noexcept {
    return std::__bit_floor(__x);
  }

  template <__unsigned_integer _Tp> constexpr int bit_width(_Tp __x) noexcept {
    return std::__bit_width(__x);
  }
  enum class endian { little = 1234, big = 4321, native = 1234 };

} // namespace std

namespace std __attribute__((__visibility__("default"))) {

  template <typename _Tp, typename _Up>
  constexpr inline int __memcmp(const _Tp *__first1, const _Up *__first2,
                                size_t __num) {

    static_assert(sizeof(_Tp) == sizeof(_Up), "can be compared with memcmp");

    if (std::is_constant_evaluated()) {
      for (; __num > 0; ++__first1, ++__first2, --__num)
        if (*__first1 != *__first2)
          return *__first1 < *__first2 ? -1 : 1;
      return 0;
    } else

      return __builtin_memcmp(__first1, __first2, sizeof(_Tp) * __num);
  }
  template <typename _ForwardIterator1, typename _ForwardIterator2>
  constexpr inline void iter_swap(_ForwardIterator1 __a,
                                  _ForwardIterator2 __b) {

    swap(*__a, *__b);
  }
  template <typename _ForwardIterator1, typename _ForwardIterator2>
  constexpr _ForwardIterator2 swap_ranges(_ForwardIterator1 __first1,
                                          _ForwardIterator1 __last1,
                                          _ForwardIterator2 __first2) {

    ;

    for (; __first1 != __last1; ++__first1, (void)++__first2)
      std::iter_swap(__first1, __first2);
    return __first2;
  }
  template <typename _Tp>
  [[__nodiscard__]] constexpr inline const _Tp &min(const _Tp &__a,
                                                    const _Tp &__b) {

    if (__b < __a)
      return __b;
    return __a;
  }
  template <typename _Tp>
  [[__nodiscard__]] constexpr inline const _Tp &max(const _Tp &__a,
                                                    const _Tp &__b) {

    if (__a < __b)
      return __b;
    return __a;
  }
  template <typename _Tp, typename _Compare>
  [[__nodiscard__]] constexpr inline const _Tp &min(
      const _Tp &__a, const _Tp &__b, _Compare __comp) {

    if (__comp(__b, __a))
      return __b;
    return __a;
  }
  template <typename _Tp, typename _Compare>
  [[__nodiscard__]] constexpr inline const _Tp &max(
      const _Tp &__a, const _Tp &__b, _Compare __comp) {

    if (__comp(__a, __b))
      return __b;
    return __a;
  }

  template <typename _Iterator>
  constexpr inline _Iterator __niter_base(_Iterator __it) noexcept(
      std::is_nothrow_copy_constructible<_Iterator>::value) {
    return __it;
  }
  template <typename _Ite, typename _Seq>
  constexpr decltype(std::__niter_base(std::declval<_Ite>())) __niter_base(
      const ::__gnu_debug::_Safe_iterator<_Ite, _Seq,
                                          std::random_access_iterator_tag>
          &) noexcept(std::is_nothrow_copy_constructible<_Ite>::value);

  template <typename _From, typename _To>
  constexpr inline _From __niter_wrap(_From __from, _To __res) {
    return __from + (std::__niter_base(__res) - std::__niter_base(__from));
  }

  template <typename _Iterator>
  constexpr inline _Iterator __niter_wrap(const _Iterator &, _Iterator __res) {
    return __res;
  }

  template <bool _IsMove, bool _IsSimple, typename _Category>
  struct __copy_move {
    template <typename _II, typename _OI>
    constexpr static _OI __copy_m(_II __first, _II __last, _OI __result) {
      for (; __first != __last; ++__result, (void)++__first)
        *__result = *__first;
      return __result;
    }
  };

  template <typename _Category> struct __copy_move<true, false, _Category> {
    template <typename _II, typename _OI>
    constexpr static _OI __copy_m(_II __first, _II __last, _OI __result) {
      for (; __first != __last; ++__result, (void)++__first)
        *__result = std::move(*__first);
      return __result;
    }
  };

  template <> struct __copy_move<false, false, random_access_iterator_tag> {
    template <typename _II, typename _OI>
    constexpr static _OI __copy_m(_II __first, _II __last, _OI __result) {
      typedef typename iterator_traits<_II>::difference_type _Distance;
      for (_Distance __n = __last - __first; __n > 0; --__n) {
        *__result = *__first;
        ++__first;
        ++__result;
      }
      return __result;
    }

    template <typename _Tp, typename _Up>
    static void __assign_one(_Tp *__to, _Up *__from) {
      *__to = *__from;
    }
  };

  template <> struct __copy_move<true, false, random_access_iterator_tag> {
    template <typename _II, typename _OI>
    constexpr static _OI __copy_m(_II __first, _II __last, _OI __result) {
      typedef typename iterator_traits<_II>::difference_type _Distance;
      for (_Distance __n = __last - __first; __n > 0; --__n) {
        *__result = std::move(*__first);
        ++__first;
        ++__result;
      }
      return __result;
    }

    template <typename _Tp, typename _Up>
    static void __assign_one(_Tp *__to, _Up *__from) {
      *__to = std::move(*__from);
    }
  };

  template <bool _IsMove>
  struct __copy_move<_IsMove, true, random_access_iterator_tag> {
    template <typename _Tp, typename _Up>
    constexpr static _Up *__copy_m(_Tp *__first, _Tp *__last, _Up *__result) {
      const ptrdiff_t _Num = __last - __first;
      if (__builtin_expect(_Num > 1, true))
        __builtin_memmove(__result, __first, sizeof(_Tp) * _Num);
      else if (_Num == 1)
        std::__copy_move<_IsMove, false,
                         random_access_iterator_tag>::__assign_one(__result,
                                                                   __first);
      return __result + _Num;
    }
  };

  template <typename _Tp, typename _Ref, typename _Ptr> struct _Deque_iterator;

  struct _Bit_iterator;

  template <typename _CharT> struct char_traits;

  template <typename _CharT, typename _Traits> class istreambuf_iterator;

  template <typename _CharT, typename _Traits> class ostreambuf_iterator;

  template <bool _IsMove, typename _CharT>
  typename __gnu_cxx::__enable_if<
      __is_char<_CharT>::__value,
      ostreambuf_iterator<_CharT, char_traits<_CharT>>>::__type
  __copy_move_a2(_CharT *, _CharT *,
                 ostreambuf_iterator<_CharT, char_traits<_CharT>>);

  template <bool _IsMove, typename _CharT>
  typename __gnu_cxx::__enable_if<
      __is_char<_CharT>::__value,
      ostreambuf_iterator<_CharT, char_traits<_CharT>>>::__type
  __copy_move_a2(const _CharT *, const _CharT *,
                 ostreambuf_iterator<_CharT, char_traits<_CharT>>);

  template <bool _IsMove, typename _CharT>
  typename __gnu_cxx::__enable_if<__is_char<_CharT>::__value, _CharT *>::__type
  __copy_move_a2(istreambuf_iterator<_CharT, char_traits<_CharT>>,
                 istreambuf_iterator<_CharT, char_traits<_CharT>>, _CharT *);

  template <bool _IsMove, typename _CharT>
  typename __gnu_cxx::__enable_if<
      __is_char<_CharT>::__value,
      std::_Deque_iterator<_CharT, _CharT &, _CharT *>>::__type
      __copy_move_a2(istreambuf_iterator<_CharT, char_traits<_CharT>>,
                     istreambuf_iterator<_CharT, char_traits<_CharT>>,
                     std::_Deque_iterator<_CharT, _CharT &, _CharT *>);

  template <bool _IsMove, typename _II, typename _OI>
  constexpr inline _OI __copy_move_a2(_II __first, _II __last, _OI __result) {
    typedef typename iterator_traits<_II>::iterator_category _Category;

    if (std::is_constant_evaluated())
      return std::__copy_move<_IsMove, false, _Category>::__copy_m(
          __first, __last, __result);

    return std::__copy_move<_IsMove, __memcpyable<_OI, _II>::__value,
                            _Category>::__copy_m(__first, __last, __result);
  }

  template <bool _IsMove, typename _Tp, typename _Ref, typename _Ptr,
            typename _OI>
  _OI __copy_move_a1(std::_Deque_iterator<_Tp, _Ref, _Ptr>,
                     std::_Deque_iterator<_Tp, _Ref, _Ptr>, _OI);

  template <bool _IsMove, typename _ITp, typename _IRef, typename _IPtr,
            typename _OTp>
  std::_Deque_iterator<_OTp, _OTp &, _OTp *> __copy_move_a1(
      std::_Deque_iterator<_ITp, _IRef, _IPtr>,
      std::_Deque_iterator<_ITp, _IRef, _IPtr>,
      std::_Deque_iterator<_OTp, _OTp &, _OTp *>);

  template <bool _IsMove, typename _II, typename _Tp>
  typename __gnu_cxx::__enable_if<__is_random_access_iter<_II>::__value,
                                  std::_Deque_iterator<_Tp, _Tp &, _Tp *>>::
      __type __copy_move_a1(_II, _II, std::_Deque_iterator<_Tp, _Tp &, _Tp *>);

  template <bool _IsMove, typename _II, typename _OI>
  constexpr inline _OI __copy_move_a1(_II __first, _II __last, _OI __result) {
    return std::__copy_move_a2<_IsMove>(__first, __last, __result);
  }

  template <bool _IsMove, typename _II, typename _OI>
  constexpr inline _OI __copy_move_a(_II __first, _II __last, _OI __result) {
    return std::__niter_wrap(
        __result, std::__copy_move_a1<_IsMove>(std::__niter_base(__first),
                                               std::__niter_base(__last),
                                               std::__niter_base(__result)));
  }

  template <bool _IsMove, typename _Ite, typename _Seq, typename _Cat,
            typename _OI>
  constexpr _OI __copy_move_a(
      const ::__gnu_debug::_Safe_iterator<_Ite, _Seq, _Cat> &,
      const ::__gnu_debug::_Safe_iterator<_Ite, _Seq, _Cat> &, _OI);

  template <bool _IsMove, typename _II, typename _Ite, typename _Seq,
            typename _Cat>
  constexpr __gnu_debug::_Safe_iterator<_Ite, _Seq, _Cat> __copy_move_a(
      _II, _II, const ::__gnu_debug::_Safe_iterator<_Ite, _Seq, _Cat> &);

  template <bool _IsMove, typename _IIte, typename _ISeq, typename _ICat,
            typename _OIte, typename _OSeq, typename _OCat>
  constexpr ::__gnu_debug::_Safe_iterator<_OIte, _OSeq, _OCat> __copy_move_a(
      const ::__gnu_debug::_Safe_iterator<_IIte, _ISeq, _ICat> &,
      const ::__gnu_debug::_Safe_iterator<_IIte, _ISeq, _ICat> &,
      const ::__gnu_debug::_Safe_iterator<_OIte, _OSeq, _OCat> &);

  template <typename _InputIterator, typename _Size, typename _OutputIterator>
  constexpr _OutputIterator __copy_n_a(_InputIterator __first, _Size __n,
                                       _OutputIterator __result, bool) {
    if (__n > 0) {
      while (true) {
        *__result = *__first;
        ++__result;
        if (--__n > 0)
          ++__first;
        else
          break;
      }
    }
    return __result;
  }

  template <typename _CharT, typename _Size>
  typename __gnu_cxx::__enable_if<__is_char<_CharT>::__value, _CharT *>::__type
  __copy_n_a(istreambuf_iterator<_CharT, char_traits<_CharT>>, _Size, _CharT *,
             bool);

  template <typename _CharT, typename _Size>
  typename __gnu_cxx::__enable_if<
      __is_char<_CharT>::__value,
      std::_Deque_iterator<_CharT, _CharT &, _CharT *>>::__type
  __copy_n_a(istreambuf_iterator<_CharT, char_traits<_CharT>>, _Size,
             std::_Deque_iterator<_CharT, _CharT &, _CharT *>, bool);
  template <typename _II, typename _OI>
  constexpr inline _OI copy(_II __first, _II __last, _OI __result) {

    ;

    return std::__copy_move_a<__is_move_iterator<_II>::__value>(
        std::__miter_base(__first), std::__miter_base(__last), __result);
  }
  template <typename _II, typename _OI>
  constexpr inline _OI move(_II __first, _II __last, _OI __result) {

    ;

    return std::__copy_move_a<true>(std::__miter_base(__first),
                                    std::__miter_base(__last), __result);
  }

  template <bool _IsMove, bool _IsSimple, typename _Category>
  struct __copy_move_backward {
    template <typename _BI1, typename _BI2>
    constexpr static _BI2 __copy_move_b(_BI1 __first, _BI1 __last,
                                        _BI2 __result) {
      while (__first != __last)
        *--__result = *--__last;
      return __result;
    }
  };

  template <typename _Category>
  struct __copy_move_backward<true, false, _Category> {
    template <typename _BI1, typename _BI2>
    constexpr static _BI2 __copy_move_b(_BI1 __first, _BI1 __last,
                                        _BI2 __result) {
      while (__first != __last)
        *--__result = std::move(*--__last);
      return __result;
    }
  };

  template <>
  struct __copy_move_backward<false, false, random_access_iterator_tag> {
    template <typename _BI1, typename _BI2>
    constexpr static _BI2 __copy_move_b(_BI1 __first, _BI1 __last,
                                        _BI2 __result) {
      typename iterator_traits<_BI1>::difference_type __n = __last - __first;
      for (; __n > 0; --__n)
        *--__result = *--__last;
      return __result;
    }
  };

  template <>
  struct __copy_move_backward<true, false, random_access_iterator_tag> {
    template <typename _BI1, typename _BI2>
    constexpr static _BI2 __copy_move_b(_BI1 __first, _BI1 __last,
                                        _BI2 __result) {
      typename iterator_traits<_BI1>::difference_type __n = __last - __first;
      for (; __n > 0; --__n)
        *--__result = std::move(*--__last);
      return __result;
    }
  };

  template <bool _IsMove>
  struct __copy_move_backward<_IsMove, true, random_access_iterator_tag> {
    template <typename _Tp, typename _Up>
    constexpr static _Up *__copy_move_b(_Tp *__first, _Tp *__last,
                                        _Up *__result) {
      const ptrdiff_t _Num = __last - __first;
      if (__builtin_expect(_Num > 1, true))
        __builtin_memmove(__result - _Num, __first, sizeof(_Tp) * _Num);
      else if (_Num == 1)
        std::__copy_move<_IsMove, false,
                         random_access_iterator_tag>::__assign_one(__result - 1,
                                                                   __first);
      return __result - _Num;
    }
  };

  template <bool _IsMove, typename _BI1, typename _BI2>
  constexpr inline _BI2 __copy_move_backward_a2(_BI1 __first, _BI1 __last,
                                                _BI2 __result) {
    typedef typename iterator_traits<_BI1>::iterator_category _Category;

    if (std::is_constant_evaluated())
      return std::__copy_move_backward<_IsMove, false,
                                       _Category>::__copy_move_b(__first,
                                                                 __last,
                                                                 __result);

    return std::__copy_move_backward<_IsMove, __memcpyable<_BI2, _BI1>::__value,
                                     _Category>::__copy_move_b(__first, __last,
                                                               __result);
  }

  template <bool _IsMove, typename _BI1, typename _BI2>
  constexpr inline _BI2 __copy_move_backward_a1(_BI1 __first, _BI1 __last,
                                                _BI2 __result) {
    return std::__copy_move_backward_a2<_IsMove>(__first, __last, __result);
  }

  template <bool _IsMove, typename _Tp, typename _Ref, typename _Ptr,
            typename _OI>
  _OI __copy_move_backward_a1(std::_Deque_iterator<_Tp, _Ref, _Ptr>,
                              std::_Deque_iterator<_Tp, _Ref, _Ptr>, _OI);

  template <bool _IsMove, typename _ITp, typename _IRef, typename _IPtr,
            typename _OTp>
  std::_Deque_iterator<_OTp, _OTp &, _OTp *> __copy_move_backward_a1(
      std::_Deque_iterator<_ITp, _IRef, _IPtr>,
      std::_Deque_iterator<_ITp, _IRef, _IPtr>,
      std::_Deque_iterator<_OTp, _OTp &, _OTp *>);

  template <bool _IsMove, typename _II, typename _Tp>
  typename __gnu_cxx::__enable_if<__is_random_access_iter<_II>::__value,
                                  std::_Deque_iterator<_Tp, _Tp &, _Tp *>>::
      __type __copy_move_backward_a1(_II, _II,
                                     std::_Deque_iterator<_Tp, _Tp &, _Tp *>);

  template <bool _IsMove, typename _II, typename _OI>
  constexpr inline _OI __copy_move_backward_a(_II __first, _II __last,
                                              _OI __result) {
    return std::__niter_wrap(__result, std::__copy_move_backward_a1<_IsMove>(
                                           std::__niter_base(__first),
                                           std::__niter_base(__last),
                                           std::__niter_base(__result)));
  }

  template <bool _IsMove, typename _Ite, typename _Seq, typename _Cat,
            typename _OI>
  constexpr _OI __copy_move_backward_a(
      const ::__gnu_debug::_Safe_iterator<_Ite, _Seq, _Cat> &,
      const ::__gnu_debug::_Safe_iterator<_Ite, _Seq, _Cat> &, _OI);

  template <bool _IsMove, typename _II, typename _Ite, typename _Seq,
            typename _Cat>
  constexpr __gnu_debug::_Safe_iterator<_Ite, _Seq, _Cat>
  __copy_move_backward_a(
      _II, _II, const ::__gnu_debug::_Safe_iterator<_Ite, _Seq, _Cat> &);

  template <bool _IsMove, typename _IIte, typename _ISeq, typename _ICat,
            typename _OIte, typename _OSeq, typename _OCat>
  constexpr ::__gnu_debug::_Safe_iterator<_OIte, _OSeq, _OCat>
  __copy_move_backward_a(
      const ::__gnu_debug::_Safe_iterator<_IIte, _ISeq, _ICat> &,
      const ::__gnu_debug::_Safe_iterator<_IIte, _ISeq, _ICat> &,
      const ::__gnu_debug::_Safe_iterator<_OIte, _OSeq, _OCat> &);
  template <typename _BI1, typename _BI2>
  constexpr inline _BI2 copy_backward(_BI1 __first, _BI1 __last,
                                      _BI2 __result) {

    ;

    return std::__copy_move_backward_a<__is_move_iterator<_BI1>::__value>(
        std::__miter_base(__first), std::__miter_base(__last), __result);
  }
  template <typename _BI1, typename _BI2>
  constexpr inline _BI2 move_backward(_BI1 __first, _BI1 __last,
                                      _BI2 __result) {

    ;

    return std::__copy_move_backward_a<true>(
        std::__miter_base(__first), std::__miter_base(__last), __result);
  }

  template <typename _ForwardIterator, typename _Tp>
  constexpr inline
      typename __gnu_cxx::__enable_if<!__is_scalar<_Tp>::__value, void>::__type
      __fill_a1(_ForwardIterator __first, _ForwardIterator __last,
                const _Tp &__value) {
    for (; __first != __last; ++__first)
      *__first = __value;
  }

  template <typename _ForwardIterator, typename _Tp>
  constexpr inline
      typename __gnu_cxx::__enable_if<__is_scalar<_Tp>::__value, void>::__type
      __fill_a1(_ForwardIterator __first, _ForwardIterator __last,
                const _Tp &__value) {
    const _Tp __tmp = __value;
    for (; __first != __last; ++__first)
      *__first = __tmp;
  }

  template <typename _Tp>
  constexpr inline
      typename __gnu_cxx::__enable_if<__is_byte<_Tp>::__value, void>::__type
      __fill_a1(_Tp * __first, _Tp * __last, const _Tp &__c) {
    const _Tp __tmp = __c;

    if (std::is_constant_evaluated()) {
      for (; __first != __last; ++__first)
        *__first = __tmp;
      return;
    }

    if (const size_t __len = __last - __first)
      __builtin_memset(__first, static_cast<unsigned char>(__tmp), __len);
  }

  template <typename _Ite, typename _Cont, typename _Tp>
  constexpr inline void __fill_a1(
      ::__gnu_cxx::__normal_iterator<_Ite, _Cont> __first,
      ::__gnu_cxx::__normal_iterator<_Ite, _Cont> __last, const _Tp &__value) {
    std::__fill_a1(__first.base(), __last.base(), __value);
  }

  template <typename _Tp, typename _VTp>
  void __fill_a1(const std::_Deque_iterator<_Tp, _Tp &, _Tp *> &,
                 const std::_Deque_iterator<_Tp, _Tp &, _Tp *> &, const _VTp &);

  constexpr void __fill_a1(std::_Bit_iterator, std::_Bit_iterator,
                           const bool &);

  template <typename _FIte, typename _Tp>
  constexpr inline void __fill_a(_FIte __first, _FIte __last,
                                 const _Tp &__value) {
    std::__fill_a1(__first, __last, __value);
  }

  template <typename _Ite, typename _Seq, typename _Cat, typename _Tp>
  constexpr void __fill_a(
      const ::__gnu_debug::_Safe_iterator<_Ite, _Seq, _Cat> &,
      const ::__gnu_debug::_Safe_iterator<_Ite, _Seq, _Cat> &, const _Tp &);
  template <typename _ForwardIterator, typename _Tp>
  constexpr inline void fill(_ForwardIterator __first, _ForwardIterator __last,
                             const _Tp &__value) {

    ;

    std::__fill_a(__first, __last, __value);
  }

  inline constexpr int __size_to_integer(int __n) { return __n; }
  inline constexpr unsigned __size_to_integer(unsigned __n) { return __n; }
  inline constexpr long __size_to_integer(long __n) { return __n; }
  inline constexpr unsigned long __size_to_integer(unsigned long __n) {
    return __n;
  }
  inline constexpr long long __size_to_integer(long long __n) { return __n; }
  inline constexpr unsigned long long __size_to_integer(
      unsigned long long __n) {
    return __n;
  }

  __extension__ inline constexpr __int128 __size_to_integer(__int128 __n) {
    return __n;
  }
  __extension__ inline constexpr unsigned __int128 __size_to_integer(
      unsigned __int128 __n) {
    return __n;
  }
  inline constexpr long long __size_to_integer(float __n) {
    return (long long)__n;
  }
  inline constexpr long long __size_to_integer(double __n) {
    return (long long)__n;
  }
  inline constexpr long long __size_to_integer(long double __n) {
    return (long long)__n;
  }

  __extension__ inline constexpr long long __size_to_integer(__float128 __n) {
    return (long long)__n;
  }

  template <typename _OutputIterator, typename _Size, typename _Tp>
  constexpr inline typename __gnu_cxx::__enable_if<!__is_scalar<_Tp>::__value,
                                                   _OutputIterator>::__type
  __fill_n_a1(_OutputIterator __first, _Size __n, const _Tp &__value) {
    for (; __n > 0; --__n, (void)++__first)
      *__first = __value;
    return __first;
  }

  template <typename _OutputIterator, typename _Size, typename _Tp>
  constexpr inline typename __gnu_cxx::__enable_if<__is_scalar<_Tp>::__value,
                                                   _OutputIterator>::__type
  __fill_n_a1(_OutputIterator __first, _Size __n, const _Tp &__value) {
    const _Tp __tmp = __value;
    for (; __n > 0; --__n, (void)++__first)
      *__first = __tmp;
    return __first;
  }

  template <typename _Ite, typename _Seq, typename _Cat, typename _Size,
            typename _Tp>
  constexpr ::__gnu_debug::_Safe_iterator<_Ite, _Seq, _Cat> __fill_n_a(
      const ::__gnu_debug::_Safe_iterator<_Ite, _Seq, _Cat> &__first, _Size __n,
      const _Tp &__value, std::input_iterator_tag);

  template <typename _OutputIterator, typename _Size, typename _Tp>
  constexpr inline _OutputIterator __fill_n_a(_OutputIterator __first,
                                              _Size __n, const _Tp &__value,
                                              std::output_iterator_tag) {

    static_assert(is_integral<_Size>{}, "fill_n must pass integral size");

    return __fill_n_a1(__first, __n, __value);
  }

  template <typename _OutputIterator, typename _Size, typename _Tp>
  constexpr inline _OutputIterator __fill_n_a(_OutputIterator __first,
                                              _Size __n, const _Tp &__value,
                                              std::input_iterator_tag) {

    static_assert(is_integral<_Size>{}, "fill_n must pass integral size");

    return __fill_n_a1(__first, __n, __value);
  }

  template <typename _OutputIterator, typename _Size, typename _Tp>
  constexpr inline _OutputIterator __fill_n_a(_OutputIterator __first,
                                              _Size __n, const _Tp &__value,
                                              std::random_access_iterator_tag) {

    static_assert(is_integral<_Size>{}, "fill_n must pass integral size");

    if (__n <= 0)
      return __first;

    ;

    std::__fill_a(__first, __first + __n, __value);
    return __first + __n;
  }
  template <typename _OI, typename _Size, typename _Tp>
  constexpr inline _OI fill_n(_OI __first, _Size __n, const _Tp &__value) {

    return std::__fill_n_a(__first, std::__size_to_integer(__n), __value,
                           std::__iterator_category(__first));
  }

  template <bool _BoolType> struct __equal {
    template <typename _II1, typename _II2>
    constexpr static bool equal(_II1 __first1, _II1 __last1, _II2 __first2) {
      for (; __first1 != __last1; ++__first1, (void)++__first2)
        if (!(*__first1 == *__first2))
          return false;
      return true;
    }
  };

  template <> struct __equal<true> {
    template <typename _Tp>
    constexpr static bool equal(const _Tp *__first1, const _Tp *__last1,
                                const _Tp *__first2) {
      if (const size_t __len = (__last1 - __first1))
        return !std::__memcmp(__first1, __first2, __len);
      return true;
    }
  };

  template <typename _Tp, typename _Ref, typename _Ptr, typename _II>
  typename __gnu_cxx::__enable_if<__is_random_access_iter<_II>::__value,
                                  bool>::__type
      __equal_aux1(std::_Deque_iterator<_Tp, _Ref, _Ptr>,
                   std::_Deque_iterator<_Tp, _Ref, _Ptr>, _II);

  template <typename _Tp1, typename _Ref1, typename _Ptr1, typename _Tp2,
            typename _Ref2, typename _Ptr2>
  bool __equal_aux1(std::_Deque_iterator<_Tp1, _Ref1, _Ptr1>,
                    std::_Deque_iterator<_Tp1, _Ref1, _Ptr1>,
                    std::_Deque_iterator<_Tp2, _Ref2, _Ptr2>);

  template <typename _II, typename _Tp, typename _Ref, typename _Ptr>
  typename __gnu_cxx::__enable_if<__is_random_access_iter<_II>::__value,
                                  bool>::__type
      __equal_aux1(_II, _II, std::_Deque_iterator<_Tp, _Ref, _Ptr>);

  template <typename _II1, typename _II2>
  constexpr inline bool __equal_aux1(_II1 __first1, _II1 __last1,
                                     _II2 __first2) {
    typedef typename iterator_traits<_II1>::value_type _ValueType1;
    const bool __simple = ((__is_integer<_ValueType1>::__value ||
                            __is_pointer<_ValueType1>::__value) &&
                           __memcmpable<_II1, _II2>::__value);
    return std::__equal<__simple>::equal(__first1, __last1, __first2);
  }

  template <typename _II1, typename _II2>
  constexpr inline bool __equal_aux(_II1 __first1, _II1 __last1,
                                    _II2 __first2) {
    return std::__equal_aux1(std::__niter_base(__first1),
                             std::__niter_base(__last1),
                             std::__niter_base(__first2));
  }

  template <typename _II1, typename _Seq1, typename _Cat1, typename _II2>
  constexpr bool __equal_aux(
      const ::__gnu_debug::_Safe_iterator<_II1, _Seq1, _Cat1> &,
      const ::__gnu_debug::_Safe_iterator<_II1, _Seq1, _Cat1> &, _II2);

  template <typename _II1, typename _II2, typename _Seq2, typename _Cat2>
  constexpr bool __equal_aux(
      _II1, _II1, const ::__gnu_debug::_Safe_iterator<_II2, _Seq2, _Cat2> &);

  template <typename _II1, typename _Seq1, typename _Cat1, typename _II2,
            typename _Seq2, typename _Cat2>
  constexpr bool __equal_aux(
      const ::__gnu_debug::_Safe_iterator<_II1, _Seq1, _Cat1> &,
      const ::__gnu_debug::_Safe_iterator<_II1, _Seq1, _Cat1> &,
      const ::__gnu_debug::_Safe_iterator<_II2, _Seq2, _Cat2> &);

  template <typename, typename> struct __lc_rai {
    template <typename _II1, typename _II2>
    constexpr static _II1 __newlast1(_II1, _II1 __last1, _II2, _II2) {
      return __last1;
    }

    template <typename _II>
    constexpr static bool __cnd2(_II __first, _II __last) {
      return __first != __last;
    }
  };

  template <>
  struct __lc_rai<random_access_iterator_tag, random_access_iterator_tag> {
    template <typename _RAI1, typename _RAI2>
    constexpr static _RAI1 __newlast1(_RAI1 __first1, _RAI1 __last1,
                                      _RAI2 __first2, _RAI2 __last2) {
      const typename iterator_traits<_RAI1>::difference_type __diff1 =
          __last1 - __first1;
      const typename iterator_traits<_RAI2>::difference_type __diff2 =
          __last2 - __first2;
      return __diff2 < __diff1 ? __first1 + __diff2 : __last1;
    }

    template <typename _RAI> static constexpr bool __cnd2(_RAI, _RAI) {
      return true;
    }
  };

  template <typename _II1, typename _II2, typename _Compare>
  constexpr bool __lexicographical_compare_impl(_II1 __first1, _II1 __last1,
                                                _II2 __first2, _II2 __last2,
                                                _Compare __comp) {
    typedef typename iterator_traits<_II1>::iterator_category _Category1;
    typedef typename iterator_traits<_II2>::iterator_category _Category2;
    typedef std::__lc_rai<_Category1, _Category2> __rai_type;

    __last1 = __rai_type::__newlast1(__first1, __last1, __first2, __last2);
    for (; __first1 != __last1 && __rai_type::__cnd2(__first2, __last2);
         ++__first1, (void)++__first2) {
      if (__comp(__first1, __first2))
        return true;
      if (__comp(__first2, __first1))
        return false;
    }
    return __first1 == __last1 && __first2 != __last2;
  }

  template <bool _BoolType> struct __lexicographical_compare {
    template <typename _II1, typename _II2>
    constexpr static bool __lc(_II1 __first1, _II1 __last1, _II2 __first2,
                               _II2 __last2) {
      using __gnu_cxx::__ops::__iter_less_iter;
      return std::__lexicographical_compare_impl(__first1, __last1, __first2,
                                                 __last2, __iter_less_iter());
    }

    template <typename _II1, typename _II2>
    constexpr static int __3way(_II1 __first1, _II1 __last1, _II2 __first2,
                                _II2 __last2) {
      while (__first1 != __last1) {
        if (__first2 == __last2)
          return +1;
        if (*__first1 < *__first2)
          return -1;
        if (*__first2 < *__first1)
          return +1;
        ++__first1;
        ++__first2;
      }
      return int(__first2 == __last2) - 1;
    }
  };

  template <> struct __lexicographical_compare<true> {
    template <typename _Tp, typename _Up>
    constexpr static bool __lc(const _Tp *__first1, const _Tp *__last1,
                               const _Up *__first2, const _Up *__last2) {
      return __3way(__first1, __last1, __first2, __last2) < 0;
    }

    template <typename _Tp, typename _Up>
    constexpr static ptrdiff_t __3way(const _Tp *__first1, const _Tp *__last1,
                                      const _Up *__first2, const _Up *__last2) {
      const size_t __len1 = __last1 - __first1;
      const size_t __len2 = __last2 - __first2;
      if (const size_t __len = std::min(__len1, __len2))
        if (int __result = std::__memcmp(__first1, __first2, __len))
          return __result;
      return ptrdiff_t(__len1 - __len2);
    }
  };

  template <typename _II1, typename _II2>
  constexpr inline bool __lexicographical_compare_aux1(
      _II1 __first1, _II1 __last1, _II2 __first2, _II2 __last2) {
    typedef typename iterator_traits<_II1>::value_type _ValueType1;
    typedef typename iterator_traits<_II2>::value_type _ValueType2;
    const bool __simple =
        (__is_memcmp_ordered_with<_ValueType1, _ValueType2>::__value &&
         __is_pointer<_II1>::__value && __is_pointer<_II2>::__value

         && !is_volatile_v<remove_reference_t<iter_reference_t<_II1>>> &&
         !is_volatile_v<remove_reference_t<iter_reference_t<_II2>>>

        );

    return std::__lexicographical_compare<__simple>::__lc(__first1, __last1,
                                                          __first2, __last2);
  }

  template <typename _Tp1, typename _Ref1, typename _Ptr1, typename _Tp2>
  bool __lexicographical_compare_aux1(std::_Deque_iterator<_Tp1, _Ref1, _Ptr1>,
                                      std::_Deque_iterator<_Tp1, _Ref1, _Ptr1>,
                                      _Tp2 *, _Tp2 *);

  template <typename _Tp1, typename _Tp2, typename _Ref2, typename _Ptr2>
  bool __lexicographical_compare_aux1(_Tp1 *, _Tp1 *,
                                      std::_Deque_iterator<_Tp2, _Ref2, _Ptr2>,
                                      std::_Deque_iterator<_Tp2, _Ref2, _Ptr2>);

  template <typename _Tp1, typename _Ref1, typename _Ptr1, typename _Tp2,
            typename _Ref2, typename _Ptr2>
  bool __lexicographical_compare_aux1(std::_Deque_iterator<_Tp1, _Ref1, _Ptr1>,
                                      std::_Deque_iterator<_Tp1, _Ref1, _Ptr1>,
                                      std::_Deque_iterator<_Tp2, _Ref2, _Ptr2>,
                                      std::_Deque_iterator<_Tp2, _Ref2, _Ptr2>);

  template <typename _II1, typename _II2>
  constexpr inline bool __lexicographical_compare_aux(
      _II1 __first1, _II1 __last1, _II2 __first2, _II2 __last2) {
    return std::__lexicographical_compare_aux1(
        std::__niter_base(__first1), std::__niter_base(__last1),
        std::__niter_base(__first2), std::__niter_base(__last2));
  }

  template <typename _Iter1, typename _Seq1, typename _Cat1, typename _II2>
  constexpr bool __lexicographical_compare_aux(
      const ::__gnu_debug::_Safe_iterator<_Iter1, _Seq1, _Cat1> &,
      const ::__gnu_debug::_Safe_iterator<_Iter1, _Seq1, _Cat1> &, _II2, _II2);

  template <typename _II1, typename _Iter2, typename _Seq2, typename _Cat2>
  constexpr bool __lexicographical_compare_aux(
      _II1, _II1, const ::__gnu_debug::_Safe_iterator<_Iter2, _Seq2, _Cat2> &,
      const ::__gnu_debug::_Safe_iterator<_Iter2, _Seq2, _Cat2> &);

  template <typename _Iter1, typename _Seq1, typename _Cat1, typename _Iter2,
            typename _Seq2, typename _Cat2>
  constexpr bool __lexicographical_compare_aux(
      const ::__gnu_debug::_Safe_iterator<_Iter1, _Seq1, _Cat1> &,
      const ::__gnu_debug::_Safe_iterator<_Iter1, _Seq1, _Cat1> &,
      const ::__gnu_debug::_Safe_iterator<_Iter2, _Seq2, _Cat2> &,
      const ::__gnu_debug::_Safe_iterator<_Iter2, _Seq2, _Cat2> &);

  template <typename _ForwardIterator, typename _Tp, typename _Compare>
  constexpr _ForwardIterator __lower_bound(_ForwardIterator __first,
                                           _ForwardIterator __last,
                                           const _Tp &__val, _Compare __comp) {
    typedef typename iterator_traits<_ForwardIterator>::difference_type
        _DistanceType;

    _DistanceType __len = std::distance(__first, __last);

    while (__len > 0) {
      _DistanceType __half = __len >> 1;
      _ForwardIterator __middle = __first;
      std::advance(__middle, __half);
      if (__comp(__middle, __val)) {
        __first = __middle;
        ++__first;
        __len = __len - __half - 1;
      } else
        __len = __half;
    }
    return __first;
  }
  template <typename _ForwardIterator, typename _Tp>
  [[__nodiscard__]] constexpr inline _ForwardIterator lower_bound(
      _ForwardIterator __first, _ForwardIterator __last, const _Tp &__val) {

    ;

    return std::__lower_bound(__first, __last, __val,
                              __gnu_cxx::__ops::__iter_less_val());
  }

  template <typename _Tp> inline constexpr _Tp __lg(_Tp __n) {

    return std::__bit_width(make_unsigned_t<_Tp>(__n)) - 1;
  }

  template <typename _II1, typename _II2>
  [[__nodiscard__]] constexpr inline bool equal(_II1 __first1, _II1 __last1,
                                                _II2 __first2) {

    ;

    return std::__equal_aux(__first1, __last1, __first2);
  }
  template <typename _IIter1, typename _IIter2, typename _BinaryPredicate>
  [[__nodiscard__]] constexpr inline bool equal(
      _IIter1 __first1, _IIter1 __last1, _IIter2 __first2,
      _BinaryPredicate __binary_pred) {

    ;

    for (; __first1 != __last1; ++__first1, (void)++__first2)
      if (!bool(__binary_pred(*__first1, *__first2)))
        return false;
    return true;
  }

  template <typename _II1, typename _II2>
  constexpr inline bool __equal4(_II1 __first1, _II1 __last1, _II2 __first2,
                                 _II2 __last2) {
    using _RATag = random_access_iterator_tag;
    using _Cat1 = typename iterator_traits<_II1>::iterator_category;
    using _Cat2 = typename iterator_traits<_II2>::iterator_category;
    using _RAIters = __and_<is_same<_Cat1, _RATag>, is_same<_Cat2, _RATag>>;
    if (_RAIters()) {
      auto __d1 = std::distance(__first1, __last1);
      auto __d2 = std::distance(__first2, __last2);
      if (__d1 != __d2)
        return false;
      return std::equal(__first1, __last1, __first2);
    }

    for (; __first1 != __last1 && __first2 != __last2;
         ++__first1, (void)++__first2)
      if (!(*__first1 == *__first2))
        return false;
    return __first1 == __last1 && __first2 == __last2;
  }

  template <typename _II1, typename _II2, typename _BinaryPredicate>
  constexpr inline bool __equal4(_II1 __first1, _II1 __last1, _II2 __first2,
                                 _II2 __last2, _BinaryPredicate __binary_pred) {
    using _RATag = random_access_iterator_tag;
    using _Cat1 = typename iterator_traits<_II1>::iterator_category;
    using _Cat2 = typename iterator_traits<_II2>::iterator_category;
    using _RAIters = __and_<is_same<_Cat1, _RATag>, is_same<_Cat2, _RATag>>;
    if (_RAIters()) {
      auto __d1 = std::distance(__first1, __last1);
      auto __d2 = std::distance(__first2, __last2);
      if (__d1 != __d2)
        return false;
      return std::equal(__first1, __last1, __first2, __binary_pred);
    }

    for (; __first1 != __last1 && __first2 != __last2;
         ++__first1, (void)++__first2)
      if (!bool(__binary_pred(*__first1, *__first2)))
        return false;
    return __first1 == __last1 && __first2 == __last2;
  }
  template <typename _II1, typename _II2>
  [[__nodiscard__]] constexpr inline bool equal(_II1 __first1, _II1 __last1,
                                                _II2 __first2, _II2 __last2) {

    ;
    ;

    return std::__equal4(__first1, __last1, __first2, __last2);
  }
  template <typename _IIter1, typename _IIter2, typename _BinaryPredicate>
  [[__nodiscard__]] constexpr inline bool equal(
      _IIter1 __first1, _IIter1 __last1, _IIter2 __first2, _IIter2 __last2,
      _BinaryPredicate __binary_pred) {

    ;
    ;

    return std::__equal4(__first1, __last1, __first2, __last2, __binary_pred);
  }
  template <typename _II1, typename _II2>
  [[__nodiscard__]] constexpr inline bool lexicographical_compare(
      _II1 __first1, _II1 __last1, _II2 __first2, _II2 __last2) {

    ;
    ;

    return std::__lexicographical_compare_aux(__first1, __last1, __first2,
                                              __last2);
  }
  template <typename _II1, typename _II2, typename _Compare>
  [[__nodiscard__]] constexpr inline bool lexicographical_compare(
      _II1 __first1, _II1 __last1, _II2 __first2, _II2 __last2,
      _Compare __comp) {

    ;
    ;

    return std::__lexicographical_compare_impl(
        __first1, __last1, __first2, __last2,
        __gnu_cxx::__ops::__iter_comp_iter(__comp));
  }

  template <typename _Iter1, typename _Iter2>
  concept __memcmp_ordered_with =
      (__is_memcmp_ordered_with<iter_value_t<_Iter1>,
                                iter_value_t<_Iter2>>::__value) &&
      contiguous_iterator<_Iter1> && contiguous_iterator<_Iter2>;

  template <typename _Tp> constexpr auto __min_cmp(_Tp __x, _Tp __y) {
    struct _Res {
      _Tp _M_min;
      decltype(__x <=> __y) _M_cmp;
    };
    auto __c = __x <=> __y;
    if (__c > 0)
      return _Res{__y, __c};
    return _Res{__x, __c};
  }
  template <typename _InputIter1, typename _InputIter2, typename _Comp>
  [[nodiscard]] constexpr auto lexicographical_compare_three_way(
      _InputIter1 __first1, _InputIter1 __last1, _InputIter2 __first2,
      _InputIter2 __last2, _Comp __comp)
      -> decltype(__comp(*__first1, *__first2)) {

    ;
    ;

    using _Cat = decltype(__comp(*__first1, *__first2));
    static_assert(same_as<common_comparison_category_t<_Cat>, _Cat>);

    if (!std::__is_constant_evaluated())
      if constexpr (same_as<_Comp, __detail::_Synth3way> ||
                    same_as<_Comp, compare_three_way>)
        if constexpr (__memcmp_ordered_with<_InputIter1, _InputIter2>) {
          const auto [__len, __lencmp] =
              std::__min_cmp(__last1 - __first1, __last2 - __first2);
          if (__len) {
            const auto __blen = __len * sizeof(*__first1);
            const auto __c =
                __builtin_memcmp(&*__first1, &*__first2, __blen) <=> 0;
            if (__c != 0)
              return __c;
          }
          return __lencmp;
        }

    while (__first1 != __last1) {
      if (__first2 == __last2)
        return strong_ordering::greater;
      if (auto __cmp = __comp(*__first1, *__first2); __cmp != 0)
        return __cmp;
      ++__first1;
      ++__first2;
    }
    return (__first2 == __last2) <=> true;
  }

  template <typename _InputIter1, typename _InputIter2>
  constexpr auto lexicographical_compare_three_way(
      _InputIter1 __first1, _InputIter1 __last1, _InputIter2 __first2,
      _InputIter2 __last2) {
    return std::lexicographical_compare_three_way(__first1, __last1, __first2,
                                                  __last2, compare_three_way{});
  }

  template <typename _InputIterator1, typename _InputIterator2,
            typename _BinaryPredicate>
  constexpr pair<_InputIterator1, _InputIterator2> __mismatch(
      _InputIterator1 __first1, _InputIterator1 __last1,
      _InputIterator2 __first2, _BinaryPredicate __binary_pred) {
    while (__first1 != __last1 && __binary_pred(__first1, __first2)) {
      ++__first1;
      ++__first2;
    }
    return pair<_InputIterator1, _InputIterator2>(__first1, __first2);
  }
  template <typename _InputIterator1, typename _InputIterator2>
  [[__nodiscard__]] constexpr inline pair<_InputIterator1, _InputIterator2>
  mismatch(_InputIterator1 __first1, _InputIterator1 __last1,
           _InputIterator2 __first2) {

    ;

    return std::__mismatch(__first1, __last1, __first2,
                           __gnu_cxx::__ops::__iter_equal_to_iter());
  }
  template <typename _InputIterator1, typename _InputIterator2,
            typename _BinaryPredicate>
  [[__nodiscard__]] constexpr inline pair<_InputIterator1, _InputIterator2>
  mismatch(_InputIterator1 __first1, _InputIterator1 __last1,
           _InputIterator2 __first2, _BinaryPredicate __binary_pred) {

    ;

    return std::__mismatch(__first1, __last1, __first2,
                           __gnu_cxx::__ops::__iter_comp_iter(__binary_pred));
  }

  template <typename _InputIterator1, typename _InputIterator2,
            typename _BinaryPredicate>
  constexpr pair<_InputIterator1, _InputIterator2> __mismatch(
      _InputIterator1 __first1, _InputIterator1 __last1,
      _InputIterator2 __first2, _InputIterator2 __last2,
      _BinaryPredicate __binary_pred) {
    while (__first1 != __last1 && __first2 != __last2 &&
           __binary_pred(__first1, __first2)) {
      ++__first1;
      ++__first2;
    }
    return pair<_InputIterator1, _InputIterator2>(__first1, __first2);
  }
  template <typename _InputIterator1, typename _InputIterator2>
  [[__nodiscard__]] constexpr inline pair<_InputIterator1, _InputIterator2>
  mismatch(_InputIterator1 __first1, _InputIterator1 __last1,
           _InputIterator2 __first2, _InputIterator2 __last2) {

    ;
    ;

    return std::__mismatch(__first1, __last1, __first2, __last2,
                           __gnu_cxx::__ops::__iter_equal_to_iter());
  }
  template <typename _InputIterator1, typename _InputIterator2,
            typename _BinaryPredicate>
  [[__nodiscard__]] constexpr inline pair<_InputIterator1, _InputIterator2>
  mismatch(_InputIterator1 __first1, _InputIterator1 __last1,
           _InputIterator2 __first2, _InputIterator2 __last2,
           _BinaryPredicate __binary_pred) {

    ;
    ;

    return std::__mismatch(__first1, __last1, __first2, __last2,
                           __gnu_cxx::__ops::__iter_comp_iter(__binary_pred));
  }

  template <typename _InputIterator, typename _Predicate>
  constexpr inline _InputIterator __find_if(
      _InputIterator __first, _InputIterator __last, _Predicate __pred,
      input_iterator_tag) {
    while (__first != __last && !__pred(__first))
      ++__first;
    return __first;
  }

  template <typename _RandomAccessIterator, typename _Predicate>
  constexpr _RandomAccessIterator __find_if(
      _RandomAccessIterator __first, _RandomAccessIterator __last,
      _Predicate __pred, random_access_iterator_tag) {
    typename iterator_traits<_RandomAccessIterator>::difference_type
        __trip_count = (__last - __first) >> 2;

    for (; __trip_count > 0; --__trip_count) {
      if (__pred(__first))
        return __first;
      ++__first;

      if (__pred(__first))
        return __first;
      ++__first;

      if (__pred(__first))
        return __first;
      ++__first;

      if (__pred(__first))
        return __first;
      ++__first;
    }

    switch (__last - __first) {
    case 3:
      if (__pred(__first))
        return __first;
      ++__first;

    case 2:
      if (__pred(__first))
        return __first;
      ++__first;

    case 1:
      if (__pred(__first))
        return __first;
      ++__first;

    case 0:
    default:
      return __last;
    }
  }

  template <typename _Iterator, typename _Predicate>
  constexpr inline _Iterator __find_if(_Iterator __first, _Iterator __last,
                                       _Predicate __pred) {
    return __find_if(__first, __last, __pred,
                     std::__iterator_category(__first));
  }

  template <typename _InputIterator, typename _Predicate>
  constexpr typename iterator_traits<_InputIterator>::difference_type
  __count_if(_InputIterator __first, _InputIterator __last, _Predicate __pred) {
    typename iterator_traits<_InputIterator>::difference_type __n = 0;
    for (; __first != __last; ++__first)
      if (__pred(__first))
        ++__n;
    return __n;
  }

  template <typename _ForwardIterator, typename _Predicate>
  constexpr _ForwardIterator __remove_if(
      _ForwardIterator __first, _ForwardIterator __last, _Predicate __pred) {
    __first = std::__find_if(__first, __last, __pred);
    if (__first == __last)
      return __first;
    _ForwardIterator __result = __first;
    ++__first;
    for (; __first != __last; ++__first)
      if (!__pred(__first)) {
        *__result = std::move(*__first);
        ++__result;
      }
    return __result;
  }

  template <typename _ForwardIterator1, typename _ForwardIterator2,
            typename _BinaryPredicate>
  constexpr _ForwardIterator1 __search(
      _ForwardIterator1 __first1, _ForwardIterator1 __last1,
      _ForwardIterator2 __first2, _ForwardIterator2 __last2,
      _BinaryPredicate __predicate) {

    if (__first1 == __last1 || __first2 == __last2)
      return __first1;

    _ForwardIterator2 __p1(__first2);
    if (++__p1 == __last2)
      return std::__find_if(
          __first1, __last1,
          __gnu_cxx::__ops::__iter_comp_iter(__predicate, __first2));

    _ForwardIterator1 __current = __first1;

    for (;;) {
      __first1 = std::__find_if(
          __first1, __last1,
          __gnu_cxx::__ops::__iter_comp_iter(__predicate, __first2));

      if (__first1 == __last1)
        return __last1;

      _ForwardIterator2 __p = __p1;
      __current = __first1;
      if (++__current == __last1)
        return __last1;

      while (__predicate(__current, __p)) {
        if (++__p == __last2)
          return __first1;
        if (++__current == __last1)
          return __last1;
      }
      ++__first1;
    }
    return __first1;
  }

  template <typename _ForwardIterator1, typename _ForwardIterator2,
            typename _BinaryPredicate>
  constexpr bool __is_permutation(
      _ForwardIterator1 __first1, _ForwardIterator1 __last1,
      _ForwardIterator2 __first2, _BinaryPredicate __pred) {

    for (; __first1 != __last1; ++__first1, (void)++__first2)
      if (!__pred(__first1, __first2))
        break;

    if (__first1 == __last1)
      return true;

    _ForwardIterator2 __last2 = __first2;
    std::advance(__last2, std::distance(__first1, __last1));
    for (_ForwardIterator1 __scan = __first1; __scan != __last1; ++__scan) {
      if (__scan !=
          std::__find_if(__first1, __scan,
                         __gnu_cxx::__ops::__iter_comp_iter(__pred, __scan)))
        continue;

      auto __matches =
          std::__count_if(__first2, __last2,
                          __gnu_cxx::__ops::__iter_comp_iter(__pred, __scan));
      if (0 == __matches || std::__count_if(__scan, __last1,
                                            __gnu_cxx::__ops::__iter_comp_iter(
                                                __pred, __scan)) != __matches)
        return false;
    }
    return true;
  }
  template <typename _ForwardIterator1, typename _ForwardIterator2>
  constexpr inline bool is_permutation(_ForwardIterator1 __first1,
                                       _ForwardIterator1 __last1,
                                       _ForwardIterator2 __first2) {

    ;

    return std::__is_permutation(__first1, __last1, __first2,
                                 __gnu_cxx::__ops::__iter_equal_to_iter());
  }

  template <typename _ForwardIterator1, typename _ForwardIterator2,
            typename _BinaryPredicate>
  constexpr inline _ForwardIterator1 search(
      _ForwardIterator1 __first1, _ForwardIterator1 __last1,
      _ForwardIterator2 __first2, _ForwardIterator2 __last2,
      _BinaryPredicate __predicate) {

    ;
    ;

    return std::__search(__first1, __last1, __first2, __last2,
                         __gnu_cxx::__ops::__iter_comp_iter(__predicate));
  }

} // namespace std

namespace __gnu_cxx {

template <typename _Tp> struct __aligned_membuf {

  struct _Tp2 {
    _Tp _M_t;
  };

  alignas(__alignof__(_Tp2::_M_t)) unsigned char _M_storage[sizeof(_Tp)];

  __aligned_membuf() = default;

  __aligned_membuf(std::nullptr_t) {}

  void *_M_addr() noexcept { return static_cast<void *>(&_M_storage); }

  const void *_M_addr() const noexcept {
    return static_cast<const void *>(&_M_storage);
  }

  _Tp *_M_ptr() noexcept { return static_cast<_Tp *>(_M_addr()); }

  const _Tp *_M_ptr() const noexcept {
    return static_cast<const _Tp *>(_M_addr());
  }
};

template <typename _Tp>
struct __aligned_buffer : std::aligned_storage<sizeof(_Tp), __alignof__(_Tp)> {
  typename std::aligned_storage<sizeof(_Tp), __alignof__(_Tp)>::type _M_storage;

  __aligned_buffer() = default;

  __aligned_buffer(std::nullptr_t) {}

  void *_M_addr() noexcept { return static_cast<void *>(&_M_storage); }

  const void *_M_addr() const noexcept {
    return static_cast<const void *>(&_M_storage);
  }

  _Tp *_M_ptr() noexcept { return static_cast<_Tp *>(_M_addr()); }

  const _Tp *_M_ptr() const noexcept {
    return static_cast<const _Tp *>(_M_addr());
  }
};

} // namespace __gnu_cxx

namespace std __attribute__((__visibility__("default"))) {

  template <typename> class allocator;

  template <> class allocator<void>;

  template <typename, typename> struct uses_allocator;

  template <typename> struct allocator_traits;

} // namespace std

namespace std __attribute__((__visibility__("default"))) {

  template <typename _Tp> class __new_allocator {
  public:
    typedef _Tp value_type;
    typedef std::size_t size_type;
    typedef std::ptrdiff_t difference_type;
    typedef std::true_type propagate_on_container_move_assignment;

    __attribute__((__always_inline__)) constexpr __new_allocator() noexcept {}

    __attribute__((__always_inline__)) constexpr __new_allocator(
        const __new_allocator &) noexcept {}

    template <typename _Tp1>
    __attribute__((__always_inline__)) constexpr __new_allocator(
        const __new_allocator<_Tp1> &) noexcept {}

    __new_allocator &operator=(const __new_allocator &) = default;
    [[__nodiscard__]] _Tp *
    allocate(size_type __n, const void * = static_cast<const void *>(0)) {

      static_assert(sizeof(_Tp) != 0, "cannot allocate incomplete types");

      if (__builtin_expect(__n > this->_M_max_size(), false)) {

        if (__n > (std::size_t(-1) / sizeof(_Tp)))
          std::__throw_bad_array_new_length();
        std::__throw_bad_alloc();
      }

      if (alignof(_Tp) > 16) {
        std::align_val_t __al = std::align_val_t(alignof(_Tp));
        return static_cast<_Tp *>(::operator new(__n * sizeof(_Tp), __al));
      }

      return static_cast<_Tp *>(::operator new(__n * sizeof(_Tp)));
    }

    void deallocate(_Tp *__p, size_type __n __attribute__((__unused__))) {

      if (alignof(_Tp) > 16) {
        ::operator delete((__p), (__n) * sizeof(_Tp),
                          std::align_val_t(alignof(_Tp)));
        return;
      }

      ::operator delete((__p), (__n) * sizeof(_Tp));
    }
    template <typename _Up>
    friend __attribute__((__always_inline__)) constexpr bool
    operator==(const __new_allocator &, const __new_allocator<_Up> &) noexcept {
      return true;
    }

  private:
    __attribute__((__always_inline__)) constexpr size_type
    _M_max_size() const noexcept {

      return std::size_t(0x7fffffffffffffffL) / sizeof(_Tp);
    }
  };

} // namespace std

namespace std {
template <typename _Tp> using __allocator_base = __new_allocator<_Tp>;
}

namespace std __attribute__((__visibility__("default"))) {

  template <> class allocator<void> {
  public:
    typedef void value_type;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    using propagate_on_container_move_assignment = true_type;

    using is_always_equal
        __attribute__((__deprecated__("use '"
                                      "std::allocator_traits::is_always_equal"
                                      "' instead"))) = true_type;

    allocator() = default;
    ~allocator() = default;

    template <typename _Up>
    __attribute__((__always_inline__)) constexpr allocator(
        const allocator<_Up> &) noexcept {}
  };
  template <typename _Tp> class allocator : public __allocator_base<_Tp> {
  public:
    typedef _Tp value_type;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    using propagate_on_container_move_assignment = true_type;

    using is_always_equal
        __attribute__((__deprecated__("use '"
                                      "std::allocator_traits::is_always_equal"
                                      "' instead"))) = true_type;

    __attribute__((__always_inline__)) constexpr allocator() noexcept {}

    __attribute__((__always_inline__)) constexpr allocator(
        const allocator &__a) noexcept
        : __allocator_base<_Tp>(__a) {}

    allocator &operator=(const allocator &) = default;

    template <typename _Tp1>
    __attribute__((__always_inline__)) constexpr allocator(
        const allocator<_Tp1> &) noexcept {}

    __attribute__((__always_inline__))

    constexpr

        ~allocator() noexcept {}

    [[nodiscard, __gnu__::__always_inline__]]
    constexpr _Tp *allocate(size_t __n) {
      if (std::__is_constant_evaluated()) {
        if (__builtin_mul_overflow(__n, sizeof(_Tp), &__n))
          std::__throw_bad_array_new_length();
        return static_cast<_Tp *>(::operator new(__n));
      }

      return __allocator_base<_Tp>::allocate(__n, 0);
    }

    [[__gnu__::__always_inline__]]
    constexpr void deallocate(_Tp *__p, size_t __n) {
      if (std::__is_constant_evaluated()) {
        ::operator delete(__p);
        return;
      }
      __allocator_base<_Tp>::deallocate(__p, __n);
    }

    friend __attribute__((__always_inline__)) constexpr bool
    operator==(const allocator &, const allocator &) noexcept {
      return true;
    }
  };

  template <typename _T1, typename _T2>
  __attribute__((__always_inline__)) inline constexpr bool operator==(
      const allocator<_T1> &, const allocator<_T2> &) noexcept {
    return true;
  }
  template <typename _Tp> class allocator<const _Tp> {
  public:
    typedef _Tp value_type;
    allocator() {}
    template <typename _Up> allocator(const allocator<_Up> &) {}
  };

  template <typename _Tp> class allocator<volatile _Tp> {
  public:
    typedef _Tp value_type;
    allocator() {}
    template <typename _Up> allocator(const allocator<_Up> &) {}
  };

  template <typename _Tp> class allocator<const volatile _Tp> {
  public:
    typedef _Tp value_type;
    allocator() {}
    template <typename _Up> allocator(const allocator<_Up> &) {}
  };

  extern template class allocator<char>;
  extern template class allocator<wchar_t>;

} // namespace std

namespace std __attribute__((__visibility__("default"))) {

  struct __allocator_traits_base {
    template <typename _Tp, typename _Up, typename = void>
    struct __rebind : __replace_first_arg<_Tp, _Up> {
      static_assert(
          is_same<
              typename __replace_first_arg<_Tp, typename _Tp::value_type>::type,
              _Tp>::value,
          "allocator_traits<A>::rebind_alloc<A::value_type> must be A");
    };

    template <typename _Tp, typename _Up>
    struct __rebind<_Tp, _Up,
                    __void_t<typename _Tp::template rebind<_Up>::other>> {
      using type = typename _Tp::template rebind<_Up>::other;

      static_assert(
          is_same<
              typename _Tp::template rebind<typename _Tp::value_type>::other,
              _Tp>::value,
          "allocator_traits<A>::rebind_alloc<A::value_type> must be A");
    };

  protected:
    template <typename _Tp> using __pointer = typename _Tp::pointer;
    template <typename _Tp> using __c_pointer = typename _Tp::const_pointer;
    template <typename _Tp> using __v_pointer = typename _Tp::void_pointer;
    template <typename _Tp>
    using __cv_pointer = typename _Tp::const_void_pointer;
    template <typename _Tp>
    using __pocca = typename _Tp::propagate_on_container_copy_assignment;
    template <typename _Tp>
    using __pocma = typename _Tp::propagate_on_container_move_assignment;
    template <typename _Tp>
    using __pocs = typename _Tp::propagate_on_container_swap;
    template <typename _Tp>
    using __equal = __type_identity<typename _Tp::is_always_equal>;

    template <typename _Alloc, typename _Tp, typename... _Args>
    using __construct_t = decltype(std::declval<_Alloc &>().construct(
        std::declval<_Tp *>(), std::declval<_Args>()...));
    template <typename _Alloc, typename _Tp, typename, typename... _Args>
    static constexpr bool __has_construct_impl = false;
    template <typename _Alloc, typename _Tp, typename... _Args>
    static constexpr bool __has_construct_impl<
        _Alloc, _Tp, __void_t<__construct_t<_Alloc, _Tp, _Args...>>, _Args...> =
        true;
    template <typename _Alloc, typename _Tp, typename... _Args>
    static constexpr bool __has_construct =
        __has_construct_impl<_Alloc, _Tp, void, _Args...>;
    template <typename _Tp, typename... _Args>
    using __new_expr_t =
        decltype(::new ((void *)0) _Tp(std::declval<_Args>()...));
    template <typename _Tp, typename, typename... _Args>
    static constexpr bool __has_new_expr = false;
    template <typename _Tp, typename... _Args>
    static constexpr bool
        __has_new_expr<_Tp, __void_t<__new_expr_t<_Tp, _Args...>>, _Args...> =
            true;
    template <typename _Alloc, typename _Tp, typename... _Args>
    static constexpr bool __can_construct =
        __has_construct<_Alloc, _Tp, _Args...> ||
        __has_new_expr<_Tp, void, _Args...>;
  };

  template <typename _Alloc, typename _Up>
  using __alloc_rebind =
      typename __allocator_traits_base::template __rebind<_Alloc, _Up>::type;
  template <typename _Alloc> struct allocator_traits : __allocator_traits_base {

    typedef _Alloc allocator_type;

    typedef typename _Alloc::value_type value_type;

    using pointer = __detected_or_t<value_type *, __pointer, _Alloc>;

  private:
    template <template <typename> class _Func, typename _Tp, typename = void>
    struct _Ptr {
      using type = typename pointer_traits<pointer>::template rebind<_Tp>;
    };

    template <template <typename> class _Func, typename _Tp>
    struct _Ptr<_Func, _Tp, __void_t<_Func<_Alloc>>> {
      using type = _Func<_Alloc>;
    };

    template <typename _A2, typename _PtrT, typename = void> struct _Diff {
      using type = typename pointer_traits<_PtrT>::difference_type;
    };

    template <typename _A2, typename _PtrT>
    struct _Diff<_A2, _PtrT, __void_t<typename _A2::difference_type>> {
      using type = typename _A2::difference_type;
    };

    template <typename _A2, typename _DiffT, typename = void>
    struct _Size : make_unsigned<_DiffT> {};

    template <typename _A2, typename _DiffT>
    struct _Size<_A2, _DiffT, __void_t<typename _A2::size_type>> {
      using type = typename _A2::size_type;
    };

  public:
    using const_pointer = typename _Ptr<__c_pointer, const value_type>::type;

    using void_pointer = typename _Ptr<__v_pointer, void>::type;

    using const_void_pointer = typename _Ptr<__cv_pointer, const void>::type;

    using difference_type = typename _Diff<_Alloc, pointer>::type;

    using size_type = typename _Size<_Alloc, difference_type>::type;

    using propagate_on_container_copy_assignment =
        __detected_or_t<false_type, __pocca, _Alloc>;

    using propagate_on_container_move_assignment =
        __detected_or_t<false_type, __pocma, _Alloc>;

    using propagate_on_container_swap =
        __detected_or_t<false_type, __pocs, _Alloc>;

    using is_always_equal =
        typename __detected_or_t<is_empty<_Alloc>, __equal, _Alloc>::type;

    template <typename _Tp> using rebind_alloc = __alloc_rebind<_Alloc, _Tp>;
    template <typename _Tp>
    using rebind_traits = allocator_traits<rebind_alloc<_Tp>>;

  private:
    template <typename _Alloc2>
    static constexpr auto _S_allocate(_Alloc2 &__a, size_type __n,
                                      const_void_pointer __hint, int)
        -> decltype(__a.allocate(__n, __hint)) {
      return __a.allocate(__n, __hint);
    }

    template <typename _Alloc2>
    static constexpr pointer _S_allocate(_Alloc2 &__a, size_type __n,
                                         const_void_pointer, ...) {
      return __a.allocate(__n);
    }

    template <typename _Alloc2, typename _Tp>
    static constexpr auto _S_destroy(_Alloc2 &__a, _Tp *__p,
                                     int) noexcept(noexcept(__a.destroy(__p)))
        -> decltype(__a.destroy(__p)) {
      __a.destroy(__p);
    }

    template <typename _Alloc2, typename _Tp>
    static constexpr void
    _S_destroy(_Alloc2 &, _Tp *__p,
               ...) noexcept(std::is_nothrow_destructible<_Tp>::value) {
      std::_Destroy(__p);
    }

    template <typename _Alloc2>
    static constexpr auto _S_max_size(_Alloc2 &__a, int)
        -> decltype(__a.max_size()) {
      return __a.max_size();
    }

    template <typename _Alloc2>
    static constexpr size_type _S_max_size(_Alloc2 &, ...) {

      return __gnu_cxx::__numeric_traits<size_type>::__max / sizeof(value_type);
    }

    template <typename _Alloc2>
    static constexpr auto _S_select(_Alloc2 &__a, int)
        -> decltype(__a.select_on_container_copy_construction()) {
      return __a.select_on_container_copy_construction();
    }

    template <typename _Alloc2>
    static constexpr _Alloc2 _S_select(_Alloc2 &__a, ...) {
      return __a;
    }

  public:
    [[__nodiscard__]] static constexpr pointer allocate(_Alloc &__a,
                                                        size_type __n) {
      return __a.allocate(__n);
    }
    [[__nodiscard__]] static constexpr pointer
    allocate(_Alloc &__a, size_type __n, const_void_pointer __hint) {
      return _S_allocate(__a, __n, __hint, 0);
    }
    static constexpr void deallocate(_Alloc &__a, pointer __p, size_type __n) {
      __a.deallocate(__p, __n);
    }
    template <typename _Tp, typename... _Args>
    static constexpr __enable_if_t<__can_construct<_Alloc, _Tp, _Args...>>
    construct(_Alloc &__a, _Tp *__p, _Args &&...__args) noexcept(
        _S_nothrow_construct<_Tp, _Args...>()) {
      if constexpr (__has_construct<_Alloc, _Tp, _Args...>)
        __a.construct(__p, std::forward<_Args>(__args)...);
      else
        std::_Construct(__p, std::forward<_Args>(__args)...);
    }
    template <typename _Tp>
    static constexpr void
    destroy(_Alloc &__a, _Tp *__p) noexcept(noexcept(_S_destroy(__a, __p, 0))) {
      _S_destroy(__a, __p, 0);
    }
    static constexpr size_type max_size(const _Alloc &__a) noexcept {
      return _S_max_size(__a, 0);
    }
    static constexpr _Alloc
    select_on_container_copy_construction(const _Alloc &__rhs) {
      return _S_select(__rhs, 0);
    }

  private:
    template <typename _Tp, typename... _Args>
    static constexpr bool _S_nothrow_construct(_Alloc *__a = nullptr,
                                               _Tp *__p = nullptr) {
      if constexpr (__has_construct<_Alloc, _Tp, _Args...>)
        return noexcept(__a->construct(__p, std::declval<_Args>()...));
      else
        return __is_nothrow_new_constructible<_Tp, _Args...>;
    }
  };

  template <typename _Tp> struct allocator_traits<allocator<_Tp>> {

    using allocator_type = allocator<_Tp>;

    using value_type = _Tp;

    using pointer = _Tp *;

    using const_pointer = const _Tp *;

    using void_pointer = void *;

    using const_void_pointer = const void *;

    using difference_type = std::ptrdiff_t;

    using size_type = std::size_t;

    using propagate_on_container_copy_assignment = false_type;

    using propagate_on_container_move_assignment = true_type;

    using propagate_on_container_swap = false_type;

    using is_always_equal = true_type;

    template <typename _Up> using rebind_alloc = allocator<_Up>;

    template <typename _Up>
    using rebind_traits = allocator_traits<allocator<_Up>>;
    [[__nodiscard__, __gnu__::__always_inline__]]
    static constexpr pointer allocate(allocator_type &__a, size_type __n) {
      return __a.allocate(__n);
    }
    [[__nodiscard__, __gnu__::__always_inline__]]
    static constexpr pointer
    allocate(allocator_type &__a, size_type __n,
             [[maybe_unused]] const_void_pointer __hint) {

      return __a.allocate(__n);
    }
    [[__gnu__::__always_inline__]]
    static constexpr void deallocate(allocator_type &__a, pointer __p,
                                     size_type __n) {
      __a.deallocate(__p, __n);
    }
    template <typename _Up, typename... _Args>
    [[__gnu__::__always_inline__]]
    static constexpr void construct(allocator_type &__a
                                    __attribute__((__unused__)),
                                    _Up *__p, _Args &&...__args)

        noexcept(__is_nothrow_new_constructible<_Up, _Args...>)

    {

      std::construct_at(__p, std::forward<_Args>(__args)...);
    }
    template <typename _Up>
    [[__gnu__::__always_inline__]]
    static constexpr void
    destroy(allocator_type &__a __attribute__((__unused__)),
            _Up *__p) noexcept(is_nothrow_destructible<_Up>::value) {

      std::destroy_at(__p);
    }

    [[__gnu__::__always_inline__]]
    static constexpr size_type max_size(const allocator_type &__a
                                        __attribute__((__unused__))) noexcept {

      return size_t(-1) / sizeof(value_type);
    }

    [[__gnu__::__always_inline__]]
    static constexpr allocator_type
    select_on_container_copy_construction(const allocator_type &__rhs) {
      return __rhs;
    }
  };

  template <> struct allocator_traits<allocator<void>> {

    using allocator_type = allocator<void>;

    using value_type = void;

    using pointer = void *;

    using const_pointer = const void *;

    using void_pointer = void *;

    using const_void_pointer = const void *;

    using difference_type = std::ptrdiff_t;

    using size_type = std::size_t;

    using propagate_on_container_copy_assignment = false_type;

    using propagate_on_container_move_assignment = true_type;

    using propagate_on_container_swap = false_type;

    using is_always_equal = true_type;

    template <typename _Up> using rebind_alloc = allocator<_Up>;

    template <typename _Up>
    using rebind_traits = allocator_traits<allocator<_Up>>;

    static void *allocate(allocator_type &, size_type,
                          const void * = nullptr) = delete;

    static void deallocate(allocator_type &, void *, size_type) = delete;
    template <typename _Up, typename... _Args>
    [[__gnu__::__always_inline__]]
    static constexpr void
    construct(allocator_type &, _Up *__p, _Args &&...__args) noexcept(
        __is_nothrow_new_constructible<_Up, _Args...>) {
      std::_Construct(__p, std::forward<_Args>(__args)...);
    }
    template <typename _Up>
    [[__gnu__::__always_inline__]]
    static constexpr void
    destroy(allocator_type &,
            _Up *__p) noexcept(is_nothrow_destructible<_Up>::value) {
      std::_Destroy(__p);
    }

    static size_type max_size(const allocator_type &) = delete;

    [[__gnu__::__always_inline__]]
    static constexpr allocator_type
    select_on_container_copy_construction(const allocator_type &__rhs) {
      return __rhs;
    }
  };
  template <typename _Alloc>
  [[__gnu__::__always_inline__]]
  constexpr inline void __alloc_on_copy(_Alloc & __one, const _Alloc &__two) {
    using __traits = allocator_traits<_Alloc>;
    using __pocca =
        typename __traits::propagate_on_container_copy_assignment::type;

    if constexpr (__pocca::value)
      __one = __two;
  }

  template <typename _Alloc>
  [[__gnu__::__always_inline__]]
  constexpr _Alloc __alloc_on_copy(const _Alloc &__a) {
    typedef allocator_traits<_Alloc> __traits;
    return __traits::select_on_container_copy_construction(__a);
  }
  template <typename _Alloc>
  [[__gnu__::__always_inline__]]
  constexpr inline void __alloc_on_move(_Alloc & __one, _Alloc & __two) {
    using __traits = allocator_traits<_Alloc>;
    using __pocma =
        typename __traits::propagate_on_container_move_assignment::type;

    if constexpr (__pocma::value)
      __one = std::move(__two);
  }
  template <typename _Alloc>
  [[__gnu__::__always_inline__]]
  constexpr inline void __alloc_on_swap(_Alloc & __one, _Alloc & __two) {
    using __traits = allocator_traits<_Alloc>;
    using __pocs = typename __traits::propagate_on_container_swap::type;

    if constexpr (__pocs::value) {
      using std::swap;
      swap(__one, __two);
    }
  }

  template <typename _Alloc, typename _Tp,
            typename _ValueT = __remove_cvref_t<typename _Alloc::value_type>,
            typename = void>
  struct __is_alloc_insertable_impl : false_type {};

  template <typename _Alloc, typename _Tp, typename _ValueT>
  struct __is_alloc_insertable_impl<
      _Alloc, _Tp, _ValueT,
      __void_t<decltype(allocator_traits<_Alloc>::construct(
          std::declval<_Alloc &>(), std::declval<_ValueT *>(),
          std::declval<_Tp>()))>> : true_type {};

  template <typename _Alloc>
  struct __is_copy_insertable
      : __is_alloc_insertable_impl<_Alloc,
                                   typename _Alloc::value_type const &>::type {
  };

  template <typename _Tp>
  struct __is_copy_insertable<allocator<_Tp>> : is_copy_constructible<_Tp> {};

  template <typename _Alloc>
  struct __is_move_insertable
      : __is_alloc_insertable_impl<_Alloc, typename _Alloc::value_type>::type {
  };

  template <typename _Tp>
  struct __is_move_insertable<allocator<_Tp>> : is_move_constructible<_Tp> {};

  template <typename _Alloc, typename = void>
  struct __is_allocator : false_type {};

  template <typename _Alloc>
  struct __is_allocator<
      _Alloc, __void_t<typename _Alloc::value_type,
                       decltype(std::declval<_Alloc &>().allocate(size_t{}))>>
      : true_type {};

  template <typename _Alloc>
  using _RequireAllocator =
      typename enable_if<__is_allocator<_Alloc>::value, _Alloc>::type;

  template <typename _Alloc>
  using _RequireNotAllocator =
      typename enable_if<!__is_allocator<_Alloc>::value, _Alloc>::type;

  template <typename _Alloc>
  concept __allocator_like = requires(_Alloc &__a) {
    typename _Alloc::value_type;
    __a.deallocate(__a.allocate(1u), 1u);
  };

  template <typename _Alloc, bool = __is_empty(_Alloc)> struct __alloc_swap {
    static void _S_do_it(_Alloc &, _Alloc &) noexcept {}
  };

  template <typename _Alloc> struct __alloc_swap<_Alloc, false> {
    static void _S_do_it(_Alloc &__one, _Alloc &__two) noexcept {

      if (__one != __two)
        swap(__one, __two);
    }
  };

  template <typename _Tp,
            bool = __or_<
                is_copy_constructible<typename _Tp::value_type>,
                is_nothrow_move_constructible<typename _Tp::value_type>>::value>
  struct __shrink_to_fit_aux {
    static bool _S_do_it(_Tp &) noexcept { return false; }
  };

  template <typename _Tp> struct __shrink_to_fit_aux<_Tp, true> {
    constexpr static bool _S_do_it(_Tp &__c) noexcept {

      try {
        _Tp(__make_move_if_noexcept_iterator(__c.begin()),
            __make_move_if_noexcept_iterator(__c.end()), __c.get_allocator())
            .swap(__c);
        return true;
      } catch (...) {
        return false;
      }
    }
  };
  template <typename _ForwardIterator, typename _Allocator>
  constexpr void _Destroy(_ForwardIterator __first, _ForwardIterator __last,
                          _Allocator & __alloc) {
    for (; __first != __last; ++__first)

      allocator_traits<_Allocator>::destroy(__alloc,
                                            std::__addressof(*__first));
  }

  template <typename _ForwardIterator, typename _Tp>
  __attribute__((__always_inline__)) constexpr inline void _Destroy(
      _ForwardIterator __first, _ForwardIterator __last, allocator<_Tp> &) {
    std::_Destroy(__first, __last);
  }

} // namespace std

namespace __gnu_cxx __attribute__((__visibility__("default"))) {

  template <typename _Alloc, typename = typename _Alloc::value_type>
  struct __alloc_traits

      : std::allocator_traits<_Alloc>

  {
    typedef _Alloc allocator_type;

    typedef std::allocator_traits<_Alloc> _Base_type;
    typedef typename _Base_type::value_type value_type;
    typedef typename _Base_type::pointer pointer;
    typedef typename _Base_type::const_pointer const_pointer;
    typedef typename _Base_type::size_type size_type;
    typedef typename _Base_type::difference_type difference_type;

    typedef value_type &reference;
    typedef const value_type &const_reference;
    using _Base_type::allocate;
    using _Base_type::construct;
    using _Base_type::deallocate;
    using _Base_type::destroy;
    using _Base_type::max_size;

  private:
    template <typename _Ptr>
    using __is_custom_pointer = std::__and_<std::is_same<pointer, _Ptr>,
                                            std::__not_<std::is_pointer<_Ptr>>>;

  public:
    template <typename _Ptr, typename... _Args>
    [[__gnu__::__always_inline__]]
    static constexpr std::__enable_if_t<__is_custom_pointer<_Ptr>::value>
    construct(_Alloc &__a, _Ptr __p, _Args &&...__args) noexcept(
        noexcept(_Base_type::construct(__a, std::__to_address(__p),
                                       std::forward<_Args>(__args)...))) {
      _Base_type::construct(__a, std::__to_address(__p),
                            std::forward<_Args>(__args)...);
    }

    template <typename _Ptr>
    [[__gnu__::__always_inline__]]
    static constexpr std::__enable_if_t<__is_custom_pointer<_Ptr>::value>
    destroy(_Alloc &__a, _Ptr __p) noexcept(
        noexcept(_Base_type::destroy(__a, std::__to_address(__p)))) {
      _Base_type::destroy(__a, std::__to_address(__p));
    }

    [[__gnu__::__always_inline__]]
    static constexpr _Alloc _S_select_on_copy(const _Alloc &__a) {
      return _Base_type::select_on_container_copy_construction(__a);
    }

    [[__gnu__::__always_inline__]]
    static constexpr void _S_on_swap(_Alloc &__a, _Alloc &__b) {
      std::__alloc_on_swap(__a, __b);
    }

    [[__gnu__::__always_inline__]]
    static constexpr bool _S_propagate_on_copy_assign() {
      return _Base_type::propagate_on_container_copy_assignment::value;
    }

    [[__gnu__::__always_inline__]]
    static constexpr bool _S_propagate_on_move_assign() {
      return _Base_type::propagate_on_container_move_assignment::value;
    }

    [[__gnu__::__always_inline__]]
    static constexpr bool _S_propagate_on_swap() {
      return _Base_type::propagate_on_container_swap::value;
    }

    [[__gnu__::__always_inline__]]
    static constexpr bool _S_always_equal() {
      return _Base_type::is_always_equal::value;
    }

    __attribute__((__always_inline__)) static constexpr bool _S_nothrow_move() {
      return _S_propagate_on_move_assign() || _S_always_equal();
    }

    template <typename _Tp> struct rebind {
      typedef typename _Base_type::template rebind_alloc<_Tp> other;
    };
  };

} // namespace __gnu_cxx

namespace std __attribute__((__visibility__("default"))) {

  template <typename _Key, typename _Value, typename _Alloc,
            typename _ExtractKey, typename _Equal, typename _Hash,
            typename _RangeHash, typename _Unused, typename _RehashPolicy,
            typename _Traits>
  class _Hashtable;

  namespace __detail {

  template <typename _Key, typename _Value, typename _ExtractKey,
            typename _Equal, typename _Hash, typename _RangeHash,
            typename _Unused, typename _Traits>
  struct _Hashtable_base;

  template <typename _Iterator>
  inline typename std::iterator_traits<_Iterator>::difference_type
  __distance_fw(_Iterator __first, _Iterator __last, std::input_iterator_tag) {
    return __first != __last ? 1 : 0;
  }

  template <typename _Iterator>
  inline typename std::iterator_traits<_Iterator>::difference_type
  __distance_fw(_Iterator __first, _Iterator __last,
                std::forward_iterator_tag) {
    return std::distance(__first, __last);
  }

  template <typename _Iterator>
  inline typename std::iterator_traits<_Iterator>::difference_type
  __distance_fw(_Iterator __first, _Iterator __last) {
    return __distance_fw(__first, __last, std::__iterator_category(__first));
  }

  struct _Identity {
    template <typename _Tp> _Tp &&operator()(_Tp &&__x) const noexcept {
      return std::forward<_Tp>(__x);
    }
  };

  struct _Select1st {
    template <typename _Pair> struct __1st_type;

    template <typename _Tp, typename _Up> struct __1st_type<pair<_Tp, _Up>> {
      using type = _Tp;
    };

    template <typename _Tp, typename _Up>
    struct __1st_type<const pair<_Tp, _Up>> {
      using type = const _Tp;
    };

    template <typename _Pair> struct __1st_type<_Pair &> {
      using type = typename __1st_type<_Pair>::type &;
    };

    template <typename _Tp>
    typename __1st_type<_Tp>::type &&operator()(_Tp &&__x) const noexcept {
      return std::forward<_Tp>(__x).first;
    }
  };

  template <typename _ExKey, typename _Value> struct _ConvertToValueType;

  template <typename _Value> struct _ConvertToValueType<_Identity, _Value> {
    template <typename _Kt>
    constexpr _Kt &&operator()(_Kt &&__k) const noexcept {
      return std::forward<_Kt>(__k);
    }
  };

  template <typename _Value> struct _ConvertToValueType<_Select1st, _Value> {
    constexpr _Value &&operator()(_Value &&__x) const noexcept {
      return std::move(__x);
    }

    constexpr const _Value &operator()(const _Value &__x) const noexcept {
      return __x;
    }

    template <typename _Kt, typename _Val>
    constexpr std::pair<_Kt, _Val> &&
    operator()(std::pair<_Kt, _Val> &&__x) const noexcept {
      return std::move(__x);
    }

    template <typename _Kt, typename _Val>
    constexpr const std::pair<_Kt, _Val> &
    operator()(const std::pair<_Kt, _Val> &__x) const noexcept {
      return __x;
    }
  };

  template <typename _ExKey> struct _NodeBuilder;

  template <> struct _NodeBuilder<_Select1st> {
    template <typename _Kt, typename _Arg, typename _NodeGenerator>
    static auto _S_build(_Kt &&__k, _Arg &&__arg,
                         const _NodeGenerator &__node_gen) ->
        typename _NodeGenerator::__node_ptr {
      return __node_gen(std::forward<_Kt>(__k),
                        std::forward<_Arg>(__arg).second);
    }
  };

  template <> struct _NodeBuilder<_Identity> {
    template <typename _Kt, typename _Arg, typename _NodeGenerator>
    static auto _S_build(_Kt &&__k, _Arg &&, const _NodeGenerator &__node_gen)
        -> typename _NodeGenerator::__node_ptr {
      return __node_gen(std::forward<_Kt>(__k));
    }
  };

  template <typename _HashtableAlloc, typename _NodePtr> struct _NodePtrGuard {
    _HashtableAlloc &_M_h;
    _NodePtr _M_ptr;

    ~_NodePtrGuard() {
      if (_M_ptr)
        _M_h._M_deallocate_node_ptr(_M_ptr);
    }
  };

  template <typename _NodeAlloc> struct _Hashtable_alloc;

  template <typename _NodeAlloc> struct _ReuseOrAllocNode {
  private:
    using __node_alloc_type = _NodeAlloc;
    using __hashtable_alloc = _Hashtable_alloc<__node_alloc_type>;
    using __node_alloc_traits = typename __hashtable_alloc::__node_alloc_traits;

  public:
    using __node_ptr = typename __hashtable_alloc::__node_ptr;

    _ReuseOrAllocNode(__node_ptr __nodes, __hashtable_alloc &__h)
        : _M_nodes(__nodes), _M_h(__h) {}
    _ReuseOrAllocNode(const _ReuseOrAllocNode &) = delete;

    ~_ReuseOrAllocNode() { _M_h._M_deallocate_nodes(_M_nodes); }

    template <typename... _Args>
    __node_ptr operator()(_Args &&...__args) const {
      if (!_M_nodes)
        return _M_h._M_allocate_node(std::forward<_Args>(__args)...);

      __node_ptr __node = _M_nodes;
      _M_nodes = _M_nodes->_M_next();
      __node->_M_nxt = nullptr;
      auto &__a = _M_h._M_node_allocator();
      __node_alloc_traits::destroy(__a, __node->_M_valptr());
      _NodePtrGuard<__hashtable_alloc, __node_ptr> __guard{_M_h, __node};
      __node_alloc_traits::construct(__a, __node->_M_valptr(),
                                     std::forward<_Args>(__args)...);
      __guard._M_ptr = nullptr;
      return __node;
    }

  private:
    mutable __node_ptr _M_nodes;
    __hashtable_alloc &_M_h;
  };

  template <typename _NodeAlloc> struct _AllocNode {
  private:
    using __hashtable_alloc = _Hashtable_alloc<_NodeAlloc>;

  public:
    using __node_ptr = typename __hashtable_alloc::__node_ptr;

    _AllocNode(__hashtable_alloc &__h) : _M_h(__h) {}

    template <typename... _Args>
    __node_ptr operator()(_Args &&...__args) const {
      return _M_h._M_allocate_node(std::forward<_Args>(__args)...);
    }

  private:
    __hashtable_alloc &_M_h;
  };
  template <bool _Cache_hash_code, bool _Constant_iterators, bool _Unique_keys>
  struct _Hashtable_traits {
    using __hash_cached = __bool_constant<_Cache_hash_code>;
    using __constant_iterators = __bool_constant<_Constant_iterators>;
    using __unique_keys = __bool_constant<_Unique_keys>;
  };

  template <typename _Hash> struct _Hashtable_hash_traits {
    static constexpr std::size_t __small_size_threshold() noexcept {
      return std::__is_fast_hash<_Hash>::value ? 0 : 20;
    }
  };
  struct _Hash_node_base {
    _Hash_node_base *_M_nxt;

    _Hash_node_base() noexcept : _M_nxt() {}

    _Hash_node_base(_Hash_node_base *__next) noexcept : _M_nxt(__next) {}
  };

  template <typename _Value> struct _Hash_node_value_base {
    typedef _Value value_type;

    __gnu_cxx::__aligned_buffer<_Value> _M_storage;

    [[__gnu__::__always_inline__]]
    _Value *_M_valptr() noexcept {
      return _M_storage._M_ptr();
    }

    [[__gnu__::__always_inline__]]
    const _Value *_M_valptr() const noexcept {
      return _M_storage._M_ptr();
    }

    [[__gnu__::__always_inline__]]
    _Value &_M_v() noexcept {
      return *_M_valptr();
    }

    [[__gnu__::__always_inline__]]
    const _Value &_M_v() const noexcept {
      return *_M_valptr();
    }
  };

  template <bool _Cache_hash_code> struct _Hash_node_code_cache {};

  template <> struct _Hash_node_code_cache<true> {
    std::size_t _M_hash_code;
  };

  template <typename _Value, bool _Cache_hash_code>
  struct _Hash_node_value : _Hash_node_value_base<_Value>,
                            _Hash_node_code_cache<_Cache_hash_code> {};

  template <typename _Value, bool _Cache_hash_code>
  struct _Hash_node : _Hash_node_base,
                      _Hash_node_value<_Value, _Cache_hash_code> {
    _Hash_node *_M_next() const noexcept {
      return static_cast<_Hash_node *>(this->_M_nxt);
    }
  };

  template <typename _Value, bool _Cache_hash_code> struct _Node_iterator_base {
    using __node_type = _Hash_node<_Value, _Cache_hash_code>;

    __node_type *_M_cur;

    _Node_iterator_base() : _M_cur(nullptr) {}
    _Node_iterator_base(__node_type *__p) noexcept : _M_cur(__p) {}

    void _M_incr() noexcept { _M_cur = _M_cur->_M_next(); }

    friend bool operator==(const _Node_iterator_base &__x,
                           const _Node_iterator_base &__y) noexcept {
      return __x._M_cur == __y._M_cur;
    }
  };

  template <typename _Value, bool __constant_iterators, bool __cache>
  struct _Node_iterator : public _Node_iterator_base<_Value, __cache> {
  private:
    using __base_type = _Node_iterator_base<_Value, __cache>;
    using __node_type = typename __base_type::__node_type;

  public:
    using value_type = _Value;
    using difference_type = std::ptrdiff_t;
    using iterator_category = std::forward_iterator_tag;

    using pointer =
        __conditional_t<__constant_iterators, const value_type *, value_type *>;

    using reference =
        __conditional_t<__constant_iterators, const value_type &, value_type &>;

    _Node_iterator() = default;

    explicit _Node_iterator(__node_type *__p) noexcept : __base_type(__p) {}

    reference operator*() const noexcept { return this->_M_cur->_M_v(); }

    pointer operator->() const noexcept { return this->_M_cur->_M_valptr(); }

    _Node_iterator &operator++() noexcept {
      this->_M_incr();
      return *this;
    }

    _Node_iterator operator++(int) noexcept {
      _Node_iterator __tmp(*this);
      this->_M_incr();
      return __tmp;
    }
  };

  template <typename _Value, bool __constant_iterators, bool __cache>
  struct _Node_const_iterator : public _Node_iterator_base<_Value, __cache> {
  private:
    using __base_type = _Node_iterator_base<_Value, __cache>;
    using __node_type = typename __base_type::__node_type;

  public:
    typedef _Value value_type;
    typedef std::ptrdiff_t difference_type;
    typedef std::forward_iterator_tag iterator_category;

    typedef const value_type *pointer;
    typedef const value_type &reference;

    _Node_const_iterator() = default;

    explicit _Node_const_iterator(__node_type *__p) noexcept
        : __base_type(__p) {}

    _Node_const_iterator(const _Node_iterator<_Value, __constant_iterators,
                                              __cache> &__x) noexcept
        : __base_type(__x._M_cur) {}

    reference operator*() const noexcept { return this->_M_cur->_M_v(); }

    pointer operator->() const noexcept { return this->_M_cur->_M_valptr(); }

    _Node_const_iterator &operator++() noexcept {
      this->_M_incr();
      return *this;
    }

    _Node_const_iterator operator++(int) noexcept {
      _Node_const_iterator __tmp(*this);
      this->_M_incr();
      return __tmp;
    }
  };

  struct _Mod_range_hashing {
    typedef std::size_t first_argument_type;
    typedef std::size_t second_argument_type;
    typedef std::size_t result_type;

    result_type operator()(first_argument_type __num,
                           second_argument_type __den) const noexcept {
      return __num % __den;
    }
  };

  struct _Default_ranged_hash {};

  struct _Prime_rehash_policy {
    using __has_load_factor = true_type;

    _Prime_rehash_policy(float __z = 1.0) noexcept
        : _M_max_load_factor(__z), _M_next_resize(0) {}

    float max_load_factor() const noexcept { return _M_max_load_factor; }

    std::size_t _M_next_bkt(std::size_t __n) const;

    std::size_t _M_bkt_for_elements(std::size_t __n) const {
      return __builtin_ceil(__n / (double)_M_max_load_factor);
    }

    std::pair<bool, std::size_t> _M_need_rehash(std::size_t __n_bkt,
                                                std::size_t __n_elt,
                                                std::size_t __n_ins) const;

    typedef std::size_t _State;

    _State _M_state() const { return _M_next_resize; }

    void _M_reset() noexcept { _M_next_resize = 0; }

    void _M_reset(_State __state) { _M_next_resize = __state; }

    static const std::size_t _S_growth_factor = 2;

    float _M_max_load_factor;
    mutable std::size_t _M_next_resize;
  };

  struct _Mask_range_hashing {
    typedef std::size_t first_argument_type;
    typedef std::size_t second_argument_type;
    typedef std::size_t result_type;

    result_type operator()(first_argument_type __num,
                           second_argument_type __den) const noexcept {
      return __num & (__den - 1);
    }
  };

  inline std::size_t __clp2(std::size_t __n) noexcept {
    using __gnu_cxx::__int_traits;

    if (__n < 2)
      return __n;
    const unsigned __lz = sizeof(size_t) > sizeof(long)
                              ? __builtin_clzll(__n - 1ull)
                              : __builtin_clzl(__n - 1ul);

    return (size_t(1) << (__int_traits<size_t>::__digits - __lz - 1)) << 1;
  }

  struct _Power2_rehash_policy {
    using __has_load_factor = true_type;

    _Power2_rehash_policy(float __z = 1.0) noexcept
        : _M_max_load_factor(__z), _M_next_resize(0) {}

    float max_load_factor() const noexcept { return _M_max_load_factor; }

    std::size_t _M_next_bkt(std::size_t __n) noexcept {
      if (__n == 0)

        return 1;

      const auto __max_width = std::min<size_t>(sizeof(size_t), 8);
      const auto __max_bkt = size_t(1) << (__max_width * 8 - 1);
      std::size_t __res = __clp2(__n);

      if (__res == 0)
        __res = __max_bkt;
      else if (__res == 1)

        __res = 2;

      if (__res == __max_bkt)

        _M_next_resize = size_t(-1);
      else
        _M_next_resize = __builtin_floor(__res * (double)_M_max_load_factor);

      return __res;
    }

    std::size_t _M_bkt_for_elements(std::size_t __n) const noexcept {
      return __builtin_ceil(__n / (double)_M_max_load_factor);
    }

    std::pair<bool, std::size_t> _M_need_rehash(std::size_t __n_bkt,
                                                std::size_t __n_elt,
                                                std::size_t __n_ins) noexcept {
      if (__n_elt + __n_ins > _M_next_resize) {

        double __min_bkts =
            std::max<std::size_t>(__n_elt + __n_ins, _M_next_resize ? 0 : 11) /
            (double)_M_max_load_factor;
        if (__min_bkts >= __n_bkt)
          return {true, _M_next_bkt(std::max<std::size_t>(
                            __builtin_floor(__min_bkts) + 1,
                            __n_bkt * _S_growth_factor))};

        _M_next_resize = __builtin_floor(__n_bkt * (double)_M_max_load_factor);
        return {false, 0};
      } else
        return {false, 0};
    }

    typedef std::size_t _State;

    _State _M_state() const noexcept { return _M_next_resize; }

    void _M_reset() noexcept { _M_next_resize = 0; }

    void _M_reset(_State __state) noexcept { _M_next_resize = __state; }

    static const std::size_t _S_growth_factor = 2;

    float _M_max_load_factor;
    std::size_t _M_next_resize;
  };

  template <typename _RehashPolicy> struct _RehashStateGuard {
    _RehashPolicy *_M_guarded_obj;
    typename _RehashPolicy::_State _M_prev_state;

    _RehashStateGuard(_RehashPolicy &__policy)
        : _M_guarded_obj(std::__addressof(__policy)),
          _M_prev_state(__policy._M_state()) {}
    _RehashStateGuard(const _RehashStateGuard &) = delete;

    ~_RehashStateGuard() {
      if (_M_guarded_obj)
        _M_guarded_obj->_M_reset(_M_prev_state);
    }
  };
  template <typename _Key, typename _Value, typename _Alloc,
            typename _ExtractKey, typename _Equal, typename _Hash,
            typename _RangeHash, typename _Unused, typename _RehashPolicy,
            typename _Traits, bool _Unique_keys = _Traits::__unique_keys::value>
  struct _Map_base {};

  template <typename _Key, typename _Val, typename _Alloc, typename _Equal,
            typename _Hash, typename _RangeHash, typename _Unused,
            typename _RehashPolicy, typename _Traits>
  struct _Map_base<_Key, pair<const _Key, _Val>, _Alloc, _Select1st, _Equal,
                   _Hash, _RangeHash, _Unused, _RehashPolicy, _Traits, false> {
    using mapped_type = _Val;
  };

  template <typename _Key, typename _Val, typename _Alloc, typename _Equal,
            typename _Hash, typename _RangeHash, typename _Unused,
            typename _RehashPolicy, typename _Traits>
  struct _Map_base<_Key, pair<const _Key, _Val>, _Alloc, _Select1st, _Equal,
                   _Hash, _RangeHash, _Unused, _RehashPolicy, _Traits, true> {
  private:
    using __hashtable_base =
        _Hashtable_base<_Key, pair<const _Key, _Val>, _Select1st, _Equal, _Hash,
                        _RangeHash, _Unused, _Traits>;

    using __hashtable =
        _Hashtable<_Key, pair<const _Key, _Val>, _Alloc, _Select1st, _Equal,
                   _Hash, _RangeHash, _Unused, _RehashPolicy, _Traits>;

    using __hash_code = typename __hashtable_base::__hash_code;

  public:
    using key_type = typename __hashtable_base::key_type;
    using mapped_type = _Val;

    mapped_type &operator[](const key_type &__k);

    mapped_type &operator[](key_type &&__k);

    mapped_type &at(const key_type &__k) {
      auto __ite = static_cast<__hashtable *>(this)->find(__k);
      if (!__ite._M_cur)
        __throw_out_of_range(("unordered_map::at"));
      return __ite->second;
    }

    const mapped_type &at(const key_type &__k) const {
      auto __ite = static_cast<const __hashtable *>(this)->find(__k);
      if (!__ite._M_cur)
        __throw_out_of_range(("unordered_map::at"));
      return __ite->second;
    }
  };

  template <typename _Key, typename _Val, typename _Alloc, typename _Equal,
            typename _Hash, typename _RangeHash, typename _Unused,
            typename _RehashPolicy, typename _Traits>
  auto _Map_base<_Key, pair<const _Key, _Val>, _Alloc, _Select1st, _Equal,
                 _Hash, _RangeHash, _Unused, _RehashPolicy, _Traits,
                 true>::operator[](const key_type &__k) -> mapped_type & {
    __hashtable *__h = static_cast<__hashtable *>(this);
    __hash_code __code = __h->_M_hash_code(__k);
    std::size_t __bkt = __h->_M_bucket_index(__code);
    if (auto __node = __h->_M_find_node(__bkt, __k, __code))
      return __node->_M_v().second;

    typename __hashtable::_Scoped_node __node{__h, std::piecewise_construct,
                                              std::tuple<const key_type &>(__k),
                                              std::tuple<>()};
    auto __pos = __h->_M_insert_unique_node(__bkt, __code, __node._M_node);
    __node._M_node = nullptr;
    return __pos->second;
  }

  template <typename _Key, typename _Val, typename _Alloc, typename _Equal,
            typename _Hash, typename _RangeHash, typename _Unused,
            typename _RehashPolicy, typename _Traits>
  auto _Map_base<_Key, pair<const _Key, _Val>, _Alloc, _Select1st, _Equal,
                 _Hash, _RangeHash, _Unused, _RehashPolicy, _Traits,
                 true>::operator[](key_type &&__k) -> mapped_type & {
    __hashtable *__h = static_cast<__hashtable *>(this);
    __hash_code __code = __h->_M_hash_code(__k);
    std::size_t __bkt = __h->_M_bucket_index(__code);
    if (auto __node = __h->_M_find_node(__bkt, __k, __code))
      return __node->_M_v().second;

    typename __hashtable::_Scoped_node __node{
        __h, std::piecewise_construct, std::forward_as_tuple(std::move(__k)),
        std::tuple<>()};
    auto __pos = __h->_M_insert_unique_node(__bkt, __code, __node._M_node);
    __node._M_node = nullptr;
    return __pos->second;
  }

  template <typename _Key, typename _Val, typename _Alloc, typename _Equal,
            typename _Hash, typename _RangeHash, typename _Unused,
            typename _RehashPolicy, typename _Traits, bool __uniq>
  struct _Map_base<const _Key, pair<const _Key, _Val>, _Alloc, _Select1st,
                   _Equal, _Hash, _RangeHash, _Unused, _RehashPolicy, _Traits,
                   __uniq>
      : _Map_base<_Key, pair<const _Key, _Val>, _Alloc, _Select1st, _Equal,
                  _Hash, _RangeHash, _Unused, _RehashPolicy, _Traits, __uniq> {
  };

  template <typename _Key, typename _Value, typename _Alloc,
            typename _ExtractKey, typename _Equal, typename _Hash,
            typename _RangeHash, typename _Unused, typename _RehashPolicy,
            typename _Traits>
  struct _Insert_base {
  protected:
    using __hashtable_base =
        _Hashtable_base<_Key, _Value, _ExtractKey, _Equal, _Hash, _RangeHash,
                        _Unused, _Traits>;

    using __hashtable =
        _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash, _RangeHash,
                   _Unused, _RehashPolicy, _Traits>;

    using __hash_cached = typename _Traits::__hash_cached;
    using __constant_iterators = typename _Traits::__constant_iterators;

    using __hashtable_alloc = _Hashtable_alloc<
        __alloc_rebind<_Alloc, _Hash_node<_Value, __hash_cached::value>>>;

    using value_type = typename __hashtable_base::value_type;
    using size_type = typename __hashtable_base::size_type;

    using __unique_keys = typename _Traits::__unique_keys;
    using __node_alloc_type = typename __hashtable_alloc::__node_alloc_type;
    using __node_gen_type = _AllocNode<__node_alloc_type>;

    __hashtable &_M_conjure_hashtable() {
      return *(static_cast<__hashtable *>(this));
    }

    template <typename _InputIterator, typename _NodeGetter>
    void _M_insert_range(_InputIterator __first, _InputIterator __last,
                         const _NodeGetter &, true_type __uks);

    template <typename _InputIterator, typename _NodeGetter>
    void _M_insert_range(_InputIterator __first, _InputIterator __last,
                         const _NodeGetter &, false_type __uks);

  public:
    using iterator = _Node_iterator<_Value, __constant_iterators::value,
                                    __hash_cached::value>;

    using const_iterator =
        _Node_const_iterator<_Value, __constant_iterators::value,
                             __hash_cached::value>;

    using __ireturn_type = __conditional_t<__unique_keys::value,
                                           std::pair<iterator, bool>, iterator>;

    __ireturn_type insert(const value_type &__v) {
      __hashtable &__h = _M_conjure_hashtable();
      __node_gen_type __node_gen(__h);
      return __h._M_insert(__v, __node_gen, __unique_keys{});
    }

    iterator insert(const_iterator __hint, const value_type &__v) {
      __hashtable &__h = _M_conjure_hashtable();
      __node_gen_type __node_gen(__h);
      return __h._M_insert(__hint, __v, __node_gen, __unique_keys{});
    }

    template <typename _KType, typename... _Args>
    std::pair<iterator, bool> try_emplace(const_iterator, _KType &&__k,
                                          _Args &&...__args) {
      __hashtable &__h = _M_conjure_hashtable();
      auto __code = __h._M_hash_code(__k);
      std::size_t __bkt = __h._M_bucket_index(__code);
      if (auto __node = __h._M_find_node(__bkt, __k, __code))
        return {iterator(__node), false};

      typename __hashtable::_Scoped_node __node{
          &__h, std::piecewise_construct,
          std::forward_as_tuple(std::forward<_KType>(__k)),
          std::forward_as_tuple(std::forward<_Args>(__args)...)};
      auto __it = __h._M_insert_unique_node(__bkt, __code, __node._M_node);
      __node._M_node = nullptr;
      return {__it, true};
    }

    void insert(initializer_list<value_type> __l) {
      this->insert(__l.begin(), __l.end());
    }

    template <typename _InputIterator>
    void insert(_InputIterator __first, _InputIterator __last) {
      __hashtable &__h = _M_conjure_hashtable();
      __node_gen_type __node_gen(__h);
      return _M_insert_range(__first, __last, __node_gen, __unique_keys{});
    }
  };

  template <typename _Key, typename _Value, typename _Alloc,
            typename _ExtractKey, typename _Equal, typename _Hash,
            typename _RangeHash, typename _Unused, typename _RehashPolicy,
            typename _Traits>
  template <typename _InputIterator, typename _NodeGetter>
  void _Insert_base<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash,
                    _RangeHash, _Unused, _RehashPolicy,
                    _Traits>::_M_insert_range(_InputIterator __first,
                                              _InputIterator __last,
                                              const _NodeGetter &__node_gen,
                                              true_type __uks) {
    __hashtable &__h = _M_conjure_hashtable();
    for (; __first != __last; ++__first)
      __h._M_insert(*__first, __node_gen, __uks);
  }

  template <typename _Key, typename _Value, typename _Alloc,
            typename _ExtractKey, typename _Equal, typename _Hash,
            typename _RangeHash, typename _Unused, typename _RehashPolicy,
            typename _Traits>
  template <typename _InputIterator, typename _NodeGetter>
  void _Insert_base<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash,
                    _RangeHash, _Unused, _RehashPolicy,
                    _Traits>::_M_insert_range(_InputIterator __first,
                                              _InputIterator __last,
                                              const _NodeGetter &__node_gen,
                                              false_type __uks) {
    using __rehash_guard_t = typename __hashtable::__rehash_guard_t;
    using __pair_type = std::pair<bool, std::size_t>;

    size_type __n_elt = __detail::__distance_fw(__first, __last);
    if (__n_elt == 0)
      return;

    __hashtable &__h = _M_conjure_hashtable();
    __rehash_guard_t __rehash_guard(__h._M_rehash_policy);
    __pair_type __do_rehash = __h._M_rehash_policy._M_need_rehash(
        __h._M_bucket_count, __h._M_element_count, __n_elt);

    if (__do_rehash.first)
      __h._M_rehash(__do_rehash.second, __uks);

    __rehash_guard._M_guarded_obj = nullptr;
    for (; __first != __last; ++__first)
      __h._M_insert(*__first, __node_gen, __uks);
  }

  template <typename _Key, typename _Value, typename _Alloc,
            typename _ExtractKey, typename _Equal, typename _Hash,
            typename _RangeHash, typename _Unused, typename _RehashPolicy,
            typename _Traits,
            bool _Constant_iterators = _Traits::__constant_iterators::value>
  struct _Insert;

  template <typename _Key, typename _Value, typename _Alloc,
            typename _ExtractKey, typename _Equal, typename _Hash,
            typename _RangeHash, typename _Unused, typename _RehashPolicy,
            typename _Traits>
  struct _Insert<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash, _RangeHash,
                 _Unused, _RehashPolicy, _Traits, true>
      : public _Insert_base<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash,
                            _RangeHash, _Unused, _RehashPolicy, _Traits> {
    using __base_type =
        _Insert_base<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash,
                     _RangeHash, _Unused, _RehashPolicy, _Traits>;

    using value_type = typename __base_type::value_type;
    using iterator = typename __base_type::iterator;
    using const_iterator = typename __base_type::const_iterator;
    using __ireturn_type = typename __base_type::__ireturn_type;

    using __unique_keys = typename __base_type::__unique_keys;
    using __hashtable = typename __base_type::__hashtable;
    using __node_gen_type = typename __base_type::__node_gen_type;

    using __base_type::insert;

    __ireturn_type insert(value_type &&__v) {
      __hashtable &__h = this->_M_conjure_hashtable();
      __node_gen_type __node_gen(__h);
      return __h._M_insert(std::move(__v), __node_gen, __unique_keys{});
    }

    iterator insert(const_iterator __hint, value_type &&__v) {
      __hashtable &__h = this->_M_conjure_hashtable();
      __node_gen_type __node_gen(__h);
      return __h._M_insert(__hint, std::move(__v), __node_gen, __unique_keys{});
    }
  };

  template <typename _Key, typename _Value, typename _Alloc,
            typename _ExtractKey, typename _Equal, typename _Hash,
            typename _RangeHash, typename _Unused, typename _RehashPolicy,
            typename _Traits>
  struct _Insert<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash, _RangeHash,
                 _Unused, _RehashPolicy, _Traits, false>
      : public _Insert_base<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash,
                            _RangeHash, _Unused, _RehashPolicy, _Traits> {
    using __base_type =
        _Insert_base<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash,
                     _RangeHash, _Unused, _RehashPolicy, _Traits>;
    using value_type = typename __base_type::value_type;
    using iterator = typename __base_type::iterator;
    using const_iterator = typename __base_type::const_iterator;

    using __unique_keys = typename __base_type::__unique_keys;
    using __hashtable = typename __base_type::__hashtable;
    using __ireturn_type = typename __base_type::__ireturn_type;

    using __base_type::insert;

    template <typename _Pair>
    using __is_cons = std::is_constructible<value_type, _Pair &&>;

    template <typename _Pair>
    using _IFcons = std::enable_if<__is_cons<_Pair>::value>;

    template <typename _Pair> using _IFconsp = typename _IFcons<_Pair>::type;

    template <typename _Pair, typename = _IFconsp<_Pair>>
    __ireturn_type insert(_Pair &&__v) {
      __hashtable &__h = this->_M_conjure_hashtable();
      return __h._M_emplace(__unique_keys{}, std::forward<_Pair>(__v));
    }

    template <typename _Pair, typename = _IFconsp<_Pair>>
    iterator insert(const_iterator __hint, _Pair &&__v) {
      __hashtable &__h = this->_M_conjure_hashtable();
      return __h._M_emplace(__hint, __unique_keys{}, std::forward<_Pair>(__v));
    }
  };

  template <typename _Policy>
  using __has_load_factor = typename _Policy::__has_load_factor;

  template <
      typename _Key, typename _Value, typename _Alloc, typename _ExtractKey,
      typename _Equal, typename _Hash, typename _RangeHash, typename _Unused,
      typename _RehashPolicy, typename _Traits,
      typename = __detected_or_t<false_type, __has_load_factor, _RehashPolicy>>
  struct _Rehash_base;

  template <typename _Key, typename _Value, typename _Alloc,
            typename _ExtractKey, typename _Equal, typename _Hash,
            typename _RangeHash, typename _Unused, typename _RehashPolicy,
            typename _Traits>
  struct _Rehash_base<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash,
                      _RangeHash, _Unused, _RehashPolicy, _Traits, false_type> {
  };

  template <typename _Key, typename _Value, typename _Alloc,
            typename _ExtractKey, typename _Equal, typename _Hash,
            typename _RangeHash, typename _Unused, typename _RehashPolicy,
            typename _Traits>
  struct _Rehash_base<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash,
                      _RangeHash, _Unused, _RehashPolicy, _Traits, true_type> {
  private:
    using __hashtable =
        _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash, _RangeHash,
                   _Unused, _RehashPolicy, _Traits>;

  public:
    float max_load_factor() const noexcept {
      const __hashtable *__this = static_cast<const __hashtable *>(this);
      return __this->__rehash_policy().max_load_factor();
    }

    void max_load_factor(float __z) {
      __hashtable *__this = static_cast<__hashtable *>(this);
      __this->__rehash_policy(_RehashPolicy(__z));
    }

    void reserve(std::size_t __n) {
      __hashtable *__this = static_cast<__hashtable *>(this);
      __this->rehash(__this->__rehash_policy()._M_bkt_for_elements(__n));
    }
  };

  template <int _Nm, typename _Tp,
            bool __use_ebo = !__is_final(_Tp) && __is_empty(_Tp)>
  struct _Hashtable_ebo_helper;

  template <int _Nm, typename _Tp>
  struct _Hashtable_ebo_helper<_Nm, _Tp, true> : private _Tp {
    _Hashtable_ebo_helper() noexcept(noexcept(_Tp())) : _Tp() {}

    template <typename _OtherTp>
    _Hashtable_ebo_helper(_OtherTp &&__tp)
        : _Tp(std::forward<_OtherTp>(__tp)) {}

    const _Tp &_M_cget() const { return static_cast<const _Tp &>(*this); }
    _Tp &_M_get() { return static_cast<_Tp &>(*this); }
  };

  template <int _Nm, typename _Tp>
  struct _Hashtable_ebo_helper<_Nm, _Tp, false> {
    _Hashtable_ebo_helper() = default;

    template <typename _OtherTp>
    _Hashtable_ebo_helper(_OtherTp &&__tp)
        : _M_tp(std::forward<_OtherTp>(__tp)) {}

    const _Tp &_M_cget() const { return _M_tp; }
    _Tp &_M_get() { return _M_tp; }

  private:
    _Tp _M_tp{};
  };

  template <typename _Key, typename _Value, typename _ExtractKey,
            typename _Hash, typename _RangeHash, typename _Unused,
            bool __cache_hash_code>
  struct _Local_iterator_base;
  template <typename _Key, typename _Value, typename _ExtractKey,
            typename _Hash, typename _RangeHash, typename _Unused,
            bool __cache_hash_code>
  struct _Hash_code_base : private _Hashtable_ebo_helper<1, _Hash> {
  private:
    using __ebo_hash = _Hashtable_ebo_helper<1, _Hash>;

    friend struct _Local_iterator_base<_Key, _Value, _ExtractKey, _Hash,
                                       _RangeHash, _Unused, false>;

  public:
    typedef _Hash hasher;

    hasher hash_function() const { return _M_hash(); }

  protected:
    typedef std::size_t __hash_code;

    _Hash_code_base() = default;

    _Hash_code_base(const _Hash &__hash) : __ebo_hash(__hash) {}

    __hash_code _M_hash_code(const _Key &__k) const {
      static_assert(
          __is_invocable<const _Hash &, const _Key &>{},
          "hash function must be invocable with an argument of key type");
      return _M_hash()(__k);
    }

    template <typename _Kt> __hash_code _M_hash_code_tr(const _Kt &__k) const {
      static_assert(
          __is_invocable<const _Hash &, const _Kt &>{},
          "hash function must be invocable with an argument of key type");
      return _M_hash()(__k);
    }

    __hash_code _M_hash_code(const _Hash_node_value<_Value, false> &__n) const {
      return _M_hash_code(_ExtractKey{}(__n._M_v()));
    }

    __hash_code _M_hash_code(const _Hash_node_value<_Value, true> &__n) const {
      return __n._M_hash_code;
    }

    std::size_t _M_bucket_index(__hash_code __c,
                                std::size_t __bkt_count) const {
      return _RangeHash{}(__c, __bkt_count);
    }

    std::size_t _M_bucket_index(const _Hash_node_value<_Value, false> &__n,
                                std::size_t __bkt_count) const
        noexcept(noexcept(declval<const _Hash &>()(declval<const _Key &>())) &&
                 noexcept(declval<const _RangeHash &>()((__hash_code)0,
                                                        (std::size_t)0))) {
      return _RangeHash{}(_M_hash_code(_ExtractKey{}(__n._M_v())), __bkt_count);
    }

    std::size_t _M_bucket_index(const _Hash_node_value<_Value, true> &__n,
                                std::size_t __bkt_count) const
        noexcept(noexcept(declval<const _RangeHash &>()((__hash_code)0,
                                                        (std::size_t)0))) {
      return _RangeHash{}(__n._M_hash_code, __bkt_count);
    }

    void _M_store_code(_Hash_node_code_cache<false> &, __hash_code) const {}

    void _M_copy_code(_Hash_node_code_cache<false> &,
                      const _Hash_node_code_cache<false> &) const {}

    void _M_store_code(_Hash_node_code_cache<true> &__n,
                       __hash_code __c) const {
      __n._M_hash_code = __c;
    }

    void _M_copy_code(_Hash_node_code_cache<true> &__to,
                      const _Hash_node_code_cache<true> &__from) const {
      __to._M_hash_code = __from._M_hash_code;
    }

    void _M_swap(_Hash_code_base &__x) {
      std::swap(__ebo_hash::_M_get(), __x.__ebo_hash::_M_get());
    }

    const _Hash &_M_hash() const { return __ebo_hash::_M_cget(); }
  };

  template <typename _Key, typename _Value, typename _ExtractKey,
            typename _Hash, typename _RangeHash, typename _Unused>
  struct _Local_iterator_base<_Key, _Value, _ExtractKey, _Hash, _RangeHash,
                              _Unused, true>
      : public _Node_iterator_base<_Value, true> {
  protected:
    using __base_node_iter = _Node_iterator_base<_Value, true>;
    using __hash_code_base = _Hash_code_base<_Key, _Value, _ExtractKey, _Hash,
                                             _RangeHash, _Unused, true>;

    _Local_iterator_base() = default;
    _Local_iterator_base(const __hash_code_base &,
                         _Hash_node<_Value, true> *__p, std::size_t __bkt,
                         std::size_t __bkt_count)
        : __base_node_iter(__p), _M_bucket(__bkt),
          _M_bucket_count(__bkt_count) {}

    void _M_incr() {
      __base_node_iter::_M_incr();
      if (this->_M_cur) {
        std::size_t __bkt =
            _RangeHash{}(this->_M_cur->_M_hash_code, _M_bucket_count);
        if (__bkt != _M_bucket)
          this->_M_cur = nullptr;
      }
    }

    std::size_t _M_bucket;
    std::size_t _M_bucket_count;

  public:
    std::size_t _M_get_bucket() const { return _M_bucket; }
  };

  template <typename _Tp, bool _IsEmpty = std::is_empty<_Tp>::value>
  struct _Hash_code_storage {
    __gnu_cxx::__aligned_buffer<_Tp> _M_storage;

    _Tp *_M_h() { return _M_storage._M_ptr(); }

    const _Tp *_M_h() const { return _M_storage._M_ptr(); }
  };

  template <typename _Tp> struct _Hash_code_storage<_Tp, true> {
    static_assert(std::is_empty<_Tp>::value, "Type must be empty");

    _Tp *_M_h() { return reinterpret_cast<_Tp *>(this); }

    const _Tp *_M_h() const { return reinterpret_cast<const _Tp *>(this); }
  };

  template <typename _Key, typename _Value, typename _ExtractKey,
            typename _Hash, typename _RangeHash, typename _Unused>
  using __hash_code_for_local_iter =
      _Hash_code_storage<_Hash_code_base<_Key, _Value, _ExtractKey, _Hash,
                                         _RangeHash, _Unused, false>>;

  template <typename _Key, typename _Value, typename _ExtractKey,
            typename _Hash, typename _RangeHash, typename _Unused>
  struct _Local_iterator_base<_Key, _Value, _ExtractKey, _Hash, _RangeHash,
                              _Unused, false>
      : __hash_code_for_local_iter<_Key, _Value, _ExtractKey, _Hash, _RangeHash,
                                   _Unused>,
        _Node_iterator_base<_Value, false> {
  protected:
    using __hash_code_base = _Hash_code_base<_Key, _Value, _ExtractKey, _Hash,
                                             _RangeHash, _Unused, false>;
    using __node_iter_base = _Node_iterator_base<_Value, false>;

    _Local_iterator_base() : _M_bucket_count(-1) {}

    _Local_iterator_base(const __hash_code_base &__base,
                         _Hash_node<_Value, false> *__p, std::size_t __bkt,
                         std::size_t __bkt_count)
        : __node_iter_base(__p), _M_bucket(__bkt),
          _M_bucket_count(__bkt_count) {
      _M_init(__base);
    }

    ~_Local_iterator_base() {
      if (_M_bucket_count != size_t(-1))
        _M_destroy();
    }

    _Local_iterator_base(const _Local_iterator_base &__iter)
        : __node_iter_base(__iter._M_cur), _M_bucket(__iter._M_bucket),
          _M_bucket_count(__iter._M_bucket_count) {
      if (_M_bucket_count != size_t(-1))
        _M_init(*__iter._M_h());
    }

    _Local_iterator_base &operator=(const _Local_iterator_base &__iter) {
      if (_M_bucket_count != -1)
        _M_destroy();
      this->_M_cur = __iter._M_cur;
      _M_bucket = __iter._M_bucket;
      _M_bucket_count = __iter._M_bucket_count;
      if (_M_bucket_count != -1)
        _M_init(*__iter._M_h());
      return *this;
    }

    void _M_incr() {
      __node_iter_base::_M_incr();
      if (this->_M_cur) {
        std::size_t __bkt =
            this->_M_h()->_M_bucket_index(*this->_M_cur, _M_bucket_count);
        if (__bkt != _M_bucket)
          this->_M_cur = nullptr;
      }
    }

    std::size_t _M_bucket;
    std::size_t _M_bucket_count;

    void _M_init(const __hash_code_base &__base) {
      ::new (this->_M_h()) __hash_code_base(__base);
    }

    void _M_destroy() { this->_M_h()->~__hash_code_base(); }

  public:
    std::size_t _M_get_bucket() const { return _M_bucket; }
  };

  template <typename _Key, typename _Value, typename _ExtractKey,
            typename _Hash, typename _RangeHash, typename _Unused,
            bool __constant_iterators, bool __cache>
  struct _Local_iterator
      : public _Local_iterator_base<_Key, _Value, _ExtractKey, _Hash,
                                    _RangeHash, _Unused, __cache> {
  private:
    using __base_type = _Local_iterator_base<_Key, _Value, _ExtractKey, _Hash,
                                             _RangeHash, _Unused, __cache>;
    using __hash_code_base = typename __base_type::__hash_code_base;

  public:
    using value_type = _Value;
    using pointer =
        __conditional_t<__constant_iterators, const value_type *, value_type *>;
    using reference =
        __conditional_t<__constant_iterators, const value_type &, value_type &>;
    using difference_type = ptrdiff_t;
    using iterator_category = forward_iterator_tag;

    _Local_iterator() = default;

    _Local_iterator(const __hash_code_base &__base,
                    _Hash_node<_Value, __cache> *__n, std::size_t __bkt,
                    std::size_t __bkt_count)
        : __base_type(__base, __n, __bkt, __bkt_count) {}

    reference operator*() const { return this->_M_cur->_M_v(); }

    pointer operator->() const { return this->_M_cur->_M_valptr(); }

    _Local_iterator &operator++() {
      this->_M_incr();
      return *this;
    }

    _Local_iterator operator++(int) {
      _Local_iterator __tmp(*this);
      this->_M_incr();
      return __tmp;
    }
  };

  template <typename _Key, typename _Value, typename _ExtractKey,
            typename _Hash, typename _RangeHash, typename _Unused,
            bool __constant_iterators, bool __cache>
  struct _Local_const_iterator
      : public _Local_iterator_base<_Key, _Value, _ExtractKey, _Hash,
                                    _RangeHash, _Unused, __cache> {
  private:
    using __base_type = _Local_iterator_base<_Key, _Value, _ExtractKey, _Hash,
                                             _RangeHash, _Unused, __cache>;
    using __hash_code_base = typename __base_type::__hash_code_base;

  public:
    typedef _Value value_type;
    typedef const value_type *pointer;
    typedef const value_type &reference;
    typedef std::ptrdiff_t difference_type;
    typedef std::forward_iterator_tag iterator_category;

    _Local_const_iterator() = default;

    _Local_const_iterator(const __hash_code_base &__base,
                          _Hash_node<_Value, __cache> *__n, std::size_t __bkt,
                          std::size_t __bkt_count)
        : __base_type(__base, __n, __bkt, __bkt_count) {}

    _Local_const_iterator(
        const _Local_iterator<_Key, _Value, _ExtractKey, _Hash, _RangeHash,
                              _Unused, __constant_iterators, __cache> &__x)
        : __base_type(__x) {}

    reference operator*() const { return this->_M_cur->_M_v(); }

    pointer operator->() const { return this->_M_cur->_M_valptr(); }

    _Local_const_iterator &operator++() {
      this->_M_incr();
      return *this;
    }

    _Local_const_iterator operator++(int) {
      _Local_const_iterator __tmp(*this);
      this->_M_incr();
      return __tmp;
    }
  };
  template <typename _Key, typename _Value, typename _ExtractKey,
            typename _Equal, typename _Hash, typename _RangeHash,
            typename _Unused, typename _Traits>
  struct _Hashtable_base
      : public _Hash_code_base<_Key, _Value, _ExtractKey, _Hash, _RangeHash,
                               _Unused, _Traits::__hash_cached::value>,
        private _Hashtable_ebo_helper<0, _Equal> {
  public:
    typedef _Key key_type;
    typedef _Value value_type;
    typedef _Equal key_equal;
    typedef std::size_t size_type;
    typedef std::ptrdiff_t difference_type;

    using __traits_type = _Traits;
    using __hash_cached = typename __traits_type::__hash_cached;

    using __hash_code_base =
        _Hash_code_base<_Key, _Value, _ExtractKey, _Hash, _RangeHash, _Unused,
                        __hash_cached::value>;

    using __hash_code = typename __hash_code_base::__hash_code;

  private:
    using _EqualEBO = _Hashtable_ebo_helper<0, _Equal>;

    static bool _S_equals(__hash_code, const _Hash_node_code_cache<false> &) {
      return true;
    }

    static bool _S_node_equals(const _Hash_node_code_cache<false> &,
                               const _Hash_node_code_cache<false> &) {
      return true;
    }

    static bool _S_equals(__hash_code __c,
                          const _Hash_node_code_cache<true> &__n) {
      return __c == __n._M_hash_code;
    }

    static bool _S_node_equals(const _Hash_node_code_cache<true> &__lhn,
                               const _Hash_node_code_cache<true> &__rhn) {
      return __lhn._M_hash_code == __rhn._M_hash_code;
    }

  protected:
    _Hashtable_base() = default;

    _Hashtable_base(const _Hash &__hash, const _Equal &__eq)
        : __hash_code_base(__hash), _EqualEBO(__eq) {}

    bool _M_key_equals(
        const _Key &__k,
        const _Hash_node_value<_Value, __hash_cached::value> &__n) const {
      static_assert(
          __is_invocable<const _Equal &, const _Key &, const _Key &>{},
          "key equality predicate must be invocable with two arguments of "
          "key type");
      return _M_eq()(__k, _ExtractKey{}(__n._M_v()));
    }

    template <typename _Kt>
    bool _M_key_equals_tr(
        const _Kt &__k,
        const _Hash_node_value<_Value, __hash_cached::value> &__n) const {
      static_assert(
          __is_invocable<const _Equal &, const _Kt &, const _Key &>{},
          "key equality predicate must be invocable with two arguments of "
          "key type");
      return _M_eq()(__k, _ExtractKey{}(__n._M_v()));
    }

    bool
    _M_equals(const _Key &__k, __hash_code __c,
              const _Hash_node_value<_Value, __hash_cached::value> &__n) const {
      return _S_equals(__c, __n) && _M_key_equals(__k, __n);
    }

    template <typename _Kt>
    bool _M_equals_tr(
        const _Kt &__k, __hash_code __c,
        const _Hash_node_value<_Value, __hash_cached::value> &__n) const {
      return _S_equals(__c, __n) && _M_key_equals_tr(__k, __n);
    }

    bool _M_node_equals(
        const _Hash_node_value<_Value, __hash_cached::value> &__lhn,
        const _Hash_node_value<_Value, __hash_cached::value> &__rhn) const {
      return _S_node_equals(__lhn, __rhn) &&
             _M_key_equals(_ExtractKey{}(__lhn._M_v()), __rhn);
    }

    void _M_swap(_Hashtable_base &__x) {
      __hash_code_base::_M_swap(__x);
      std::swap(_EqualEBO::_M_get(), __x._EqualEBO::_M_get());
    }

    const _Equal &_M_eq() const { return _EqualEBO::_M_cget(); }
  };
  template <typename _Key, typename _Value, typename _Alloc,
            typename _ExtractKey, typename _Equal, typename _Hash,
            typename _RangeHash, typename _Unused, typename _RehashPolicy,
            typename _Traits, bool _Unique_keys = _Traits::__unique_keys::value>
  struct _Equality;

  template <typename _Key, typename _Value, typename _Alloc,
            typename _ExtractKey, typename _Equal, typename _Hash,
            typename _RangeHash, typename _Unused, typename _RehashPolicy,
            typename _Traits>
  struct _Equality<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash, _RangeHash,
                   _Unused, _RehashPolicy, _Traits, true> {
    using __hashtable =
        _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash, _RangeHash,
                   _Unused, _RehashPolicy, _Traits>;

    bool _M_equal(const __hashtable &) const;
  };

  template <typename _Key, typename _Value, typename _Alloc,
            typename _ExtractKey, typename _Equal, typename _Hash,
            typename _RangeHash, typename _Unused, typename _RehashPolicy,
            typename _Traits>
  bool _Equality<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash, _RangeHash,
                 _Unused, _RehashPolicy, _Traits,
                 true>::_M_equal(const __hashtable &__other) const {
    using __node_ptr = typename __hashtable::__node_ptr;
    const __hashtable *__this = static_cast<const __hashtable *>(this);
    if (__this->size() != __other.size())
      return false;

    for (auto __x_n = __this->_M_begin(); __x_n; __x_n = __x_n->_M_next()) {
      std::size_t __ybkt = __other._M_bucket_index(*__x_n);
      auto __prev_n = __other._M_buckets[__ybkt];
      if (!__prev_n)
        return false;

      for (__node_ptr __n = static_cast<__node_ptr>(__prev_n->_M_nxt);;
           __n = __n->_M_next()) {
        if (__n->_M_v() == __x_n->_M_v())
          break;

        if (!__n->_M_nxt || __other._M_bucket_index(*__n->_M_next()) != __ybkt)
          return false;
      }
    }

    return true;
  }

  template <typename _Key, typename _Value, typename _Alloc,
            typename _ExtractKey, typename _Equal, typename _Hash,
            typename _RangeHash, typename _Unused, typename _RehashPolicy,
            typename _Traits>
  struct _Equality<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash, _RangeHash,
                   _Unused, _RehashPolicy, _Traits, false> {
    using __hashtable =
        _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash, _RangeHash,
                   _Unused, _RehashPolicy, _Traits>;

    bool _M_equal(const __hashtable &) const;
  };

  template <typename _Key, typename _Value, typename _Alloc,
            typename _ExtractKey, typename _Equal, typename _Hash,
            typename _RangeHash, typename _Unused, typename _RehashPolicy,
            typename _Traits>
  bool _Equality<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash, _RangeHash,
                 _Unused, _RehashPolicy, _Traits,
                 false>::_M_equal(const __hashtable &__other) const {
    using __node_ptr = typename __hashtable::__node_ptr;
    using const_iterator = typename __hashtable::const_iterator;
    const __hashtable *__this = static_cast<const __hashtable *>(this);
    if (__this->size() != __other.size())
      return false;

    for (auto __x_n = __this->_M_begin(); __x_n;) {
      std::size_t __x_count = 1;
      auto __x_n_end = __x_n->_M_next();
      for (; __x_n_end && __this->key_eq()(_ExtractKey{}(__x_n->_M_v()),
                                           _ExtractKey{}(__x_n_end->_M_v()));
           __x_n_end = __x_n_end->_M_next())
        ++__x_count;

      std::size_t __ybkt = __other._M_bucket_index(*__x_n);
      auto __y_prev_n = __other._M_buckets[__ybkt];
      if (!__y_prev_n)
        return false;

      __node_ptr __y_n = static_cast<__node_ptr>(__y_prev_n->_M_nxt);
      for (;;) {
        if (__this->key_eq()(_ExtractKey{}(__y_n->_M_v()),
                             _ExtractKey{}(__x_n->_M_v())))
          break;

        auto __y_ref_n = __y_n;
        for (__y_n = __y_n->_M_next(); __y_n; __y_n = __y_n->_M_next())
          if (!__other._M_node_equals(*__y_ref_n, *__y_n))
            break;

        if (!__y_n || __other._M_bucket_index(*__y_n) != __ybkt)
          return false;
      }

      auto __y_n_end = __y_n;
      for (; __y_n_end; __y_n_end = __y_n_end->_M_next())
        if (--__x_count == 0)
          break;

      if (__x_count != 0)
        return false;

      const_iterator __itx(__x_n), __itx_end(__x_n_end);
      const_iterator __ity(__y_n);
      if (!std::is_permutation(__itx, __itx_end, __ity))
        return false;

      __x_n = __x_n_end;
    }
    return true;
  }

  template <typename _NodeAlloc>
  struct _Hashtable_alloc : private _Hashtable_ebo_helper<0, _NodeAlloc> {
  private:
    using __ebo_node_alloc = _Hashtable_ebo_helper<0, _NodeAlloc>;

    template <typename> struct __get_value_type;
    template <typename _Val, bool _Cache_hash_code>
    struct __get_value_type<_Hash_node<_Val, _Cache_hash_code>> {
      using type = _Val;
    };

  public:
    using __node_type = typename _NodeAlloc::value_type;
    using __node_alloc_type = _NodeAlloc;

    using __node_alloc_traits = __gnu_cxx::__alloc_traits<__node_alloc_type>;

    using __value_alloc_traits =
        typename __node_alloc_traits::template rebind_traits<
            typename __get_value_type<__node_type>::type>;

    using __node_ptr = __node_type *;
    using __node_base = _Hash_node_base;
    using __node_base_ptr = __node_base *;
    using __buckets_alloc_type =
        __alloc_rebind<__node_alloc_type, __node_base_ptr>;
    using __buckets_alloc_traits = std::allocator_traits<__buckets_alloc_type>;
    using __buckets_ptr = __node_base_ptr *;

    _Hashtable_alloc() = default;
    _Hashtable_alloc(const _Hashtable_alloc &) = default;
    _Hashtable_alloc(_Hashtable_alloc &&) = default;

    template <typename _Alloc>
    _Hashtable_alloc(_Alloc &&__a)
        : __ebo_node_alloc(std::forward<_Alloc>(__a)) {}

    __node_alloc_type &_M_node_allocator() {
      return __ebo_node_alloc::_M_get();
    }

    const __node_alloc_type &_M_node_allocator() const {
      return __ebo_node_alloc::_M_cget();
    }

    template <typename... _Args> __node_ptr _M_allocate_node(_Args &&...__args);

    void _M_deallocate_node(__node_ptr __n);

    void _M_deallocate_node_ptr(__node_ptr __n);

    void _M_deallocate_nodes(__node_ptr __n);

    __buckets_ptr _M_allocate_buckets(std::size_t __bkt_count);

    void _M_deallocate_buckets(__buckets_ptr, std::size_t __bkt_count);
  };

  template <typename _NodeAlloc>
  template <typename... _Args>
  auto _Hashtable_alloc<_NodeAlloc>::_M_allocate_node(_Args &&...__args)
      -> __node_ptr {
    auto &__alloc = _M_node_allocator();
    auto __nptr = __node_alloc_traits::allocate(__alloc, 1);
    __node_ptr __n = std::__to_address(__nptr);
    try {
      ::new ((void *)__n) __node_type;
      __node_alloc_traits::construct(__alloc, __n->_M_valptr(),
                                     std::forward<_Args>(__args)...);
      return __n;
    } catch (...) {
      __n->~__node_type();
      __node_alloc_traits::deallocate(__alloc, __nptr, 1);
      throw;
    }
  }

  template <typename _NodeAlloc>
  void _Hashtable_alloc<_NodeAlloc>::_M_deallocate_node(__node_ptr __n) {
    __node_alloc_traits::destroy(_M_node_allocator(), __n->_M_valptr());
    _M_deallocate_node_ptr(__n);
  }

  template <typename _NodeAlloc>
  void _Hashtable_alloc<_NodeAlloc>::_M_deallocate_node_ptr(__node_ptr __n) {
    typedef typename __node_alloc_traits::pointer _Ptr;
    auto __ptr = std::pointer_traits<_Ptr>::pointer_to(*__n);
    __n->~__node_type();
    __node_alloc_traits::deallocate(_M_node_allocator(), __ptr, 1);
  }

  template <typename _NodeAlloc>
  void _Hashtable_alloc<_NodeAlloc>::_M_deallocate_nodes(__node_ptr __n) {
    while (__n) {
      __node_ptr __tmp = __n;
      __n = __n->_M_next();
      _M_deallocate_node(__tmp);
    }
  }

  template <typename _NodeAlloc>
  auto
  _Hashtable_alloc<_NodeAlloc>::_M_allocate_buckets(std::size_t __bkt_count)
      -> __buckets_ptr {
    __buckets_alloc_type __alloc(_M_node_allocator());

    auto __ptr = __buckets_alloc_traits::allocate(__alloc, __bkt_count);
    __buckets_ptr __p = std::__to_address(__ptr);
    __builtin_memset(__p, 0, __bkt_count * sizeof(__node_base_ptr));
    return __p;
  }

  template <typename _NodeAlloc>
  void
  _Hashtable_alloc<_NodeAlloc>::_M_deallocate_buckets(__buckets_ptr __bkts,
                                                      std::size_t __bkt_count) {
    typedef typename __buckets_alloc_traits::pointer _Ptr;
    auto __ptr = std::pointer_traits<_Ptr>::pointer_to(*__bkts);
    __buckets_alloc_type __alloc(_M_node_allocator());
    __buckets_alloc_traits::deallocate(__alloc, __ptr, __bkt_count);
  }

  } // namespace __detail

} // namespace std

namespace std __attribute__((__visibility__("default"))) {

  struct _Enable_default_constructor_tag {
    explicit constexpr _Enable_default_constructor_tag() = default;
  };

  template <bool _Switch, typename _Tag = void>
  struct _Enable_default_constructor {
    constexpr _Enable_default_constructor() noexcept = default;
    constexpr _Enable_default_constructor(
        _Enable_default_constructor const &) noexcept = default;
    constexpr _Enable_default_constructor(
        _Enable_default_constructor &&) noexcept = default;
    _Enable_default_constructor &
    operator=(_Enable_default_constructor const &) noexcept = default;
    _Enable_default_constructor &
    operator=(_Enable_default_constructor &&) noexcept = default;

    constexpr explicit _Enable_default_constructor(
        _Enable_default_constructor_tag) {}
  };

  template <bool _Switch, typename _Tag = void> struct _Enable_destructor {};

  template <bool _Copy, bool _CopyAssignment, bool _Move, bool _MoveAssignment,
            typename _Tag = void>
  struct _Enable_copy_move {};
  template <bool _Default, bool _Destructor, bool _Copy, bool _CopyAssignment,
            bool _Move, bool _MoveAssignment, typename _Tag = void>
  struct _Enable_special_members
      : private _Enable_default_constructor<_Default, _Tag>,
        private _Enable_destructor<_Destructor, _Tag>,
        private _Enable_copy_move<_Copy, _CopyAssignment, _Move,
                                  _MoveAssignment, _Tag> {};

  template <typename _Tag> struct _Enable_default_constructor<false, _Tag> {
    constexpr _Enable_default_constructor() noexcept = delete;
    constexpr _Enable_default_constructor(
        _Enable_default_constructor const &) noexcept = default;
    constexpr _Enable_default_constructor(
        _Enable_default_constructor &&) noexcept = default;
    _Enable_default_constructor &
    operator=(_Enable_default_constructor const &) noexcept = default;
    _Enable_default_constructor &
    operator=(_Enable_default_constructor &&) noexcept = default;

    constexpr explicit _Enable_default_constructor(
        _Enable_default_constructor_tag) {}
  };

  template <typename _Tag> struct _Enable_destructor<false, _Tag> {
    ~_Enable_destructor() noexcept = delete;
  };

  template <typename _Tag>
  struct _Enable_copy_move<false, true, true, true, _Tag> {
    constexpr _Enable_copy_move() noexcept = default;
    constexpr _Enable_copy_move(_Enable_copy_move const &) noexcept = delete;
    constexpr _Enable_copy_move(_Enable_copy_move &&) noexcept = default;
    _Enable_copy_move &operator=(_Enable_copy_move const &) noexcept = default;
    _Enable_copy_move &operator=(_Enable_copy_move &&) noexcept = default;
  };

  template <typename _Tag>
  struct _Enable_copy_move<true, false, true, true, _Tag> {
    constexpr _Enable_copy_move() noexcept = default;
    constexpr _Enable_copy_move(_Enable_copy_move const &) noexcept = default;
    constexpr _Enable_copy_move(_Enable_copy_move &&) noexcept = default;
    _Enable_copy_move &operator=(_Enable_copy_move const &) noexcept = delete;
    _Enable_copy_move &operator=(_Enable_copy_move &&) noexcept = default;
  };

  template <typename _Tag>
  struct _Enable_copy_move<false, false, true, true, _Tag> {
    constexpr _Enable_copy_move() noexcept = default;
    constexpr _Enable_copy_move(_Enable_copy_move const &) noexcept = delete;
    constexpr _Enable_copy_move(_Enable_copy_move &&) noexcept = default;
    _Enable_copy_move &operator=(_Enable_copy_move const &) noexcept = delete;
    _Enable_copy_move &operator=(_Enable_copy_move &&) noexcept = default;
  };

  template <typename _Tag>
  struct _Enable_copy_move<true, true, false, true, _Tag> {
    constexpr _Enable_copy_move() noexcept = default;
    constexpr _Enable_copy_move(_Enable_copy_move const &) noexcept = default;
    constexpr _Enable_copy_move(_Enable_copy_move &&) noexcept = delete;
    _Enable_copy_move &operator=(_Enable_copy_move const &) noexcept = default;
    _Enable_copy_move &operator=(_Enable_copy_move &&) noexcept = default;
  };

  template <typename _Tag>
  struct _Enable_copy_move<false, true, false, true, _Tag> {
    constexpr _Enable_copy_move() noexcept = default;
    constexpr _Enable_copy_move(_Enable_copy_move const &) noexcept = delete;
    constexpr _Enable_copy_move(_Enable_copy_move &&) noexcept = delete;
    _Enable_copy_move &operator=(_Enable_copy_move const &) noexcept = default;
    _Enable_copy_move &operator=(_Enable_copy_move &&) noexcept = default;
  };

  template <typename _Tag>
  struct _Enable_copy_move<true, false, false, true, _Tag> {
    constexpr _Enable_copy_move() noexcept = default;
    constexpr _Enable_copy_move(_Enable_copy_move const &) noexcept = default;
    constexpr _Enable_copy_move(_Enable_copy_move &&) noexcept = delete;
    _Enable_copy_move &operator=(_Enable_copy_move const &) noexcept = delete;
    _Enable_copy_move &operator=(_Enable_copy_move &&) noexcept = default;
  };

  template <typename _Tag>
  struct _Enable_copy_move<false, false, false, true, _Tag> {
    constexpr _Enable_copy_move() noexcept = default;
    constexpr _Enable_copy_move(_Enable_copy_move const &) noexcept = delete;
    constexpr _Enable_copy_move(_Enable_copy_move &&) noexcept = delete;
    _Enable_copy_move &operator=(_Enable_copy_move const &) noexcept = delete;
    _Enable_copy_move &operator=(_Enable_copy_move &&) noexcept = default;
  };

  template <typename _Tag>
  struct _Enable_copy_move<true, true, true, false, _Tag> {
    constexpr _Enable_copy_move() noexcept = default;
    constexpr _Enable_copy_move(_Enable_copy_move const &) noexcept = default;
    constexpr _Enable_copy_move(_Enable_copy_move &&) noexcept = default;
    _Enable_copy_move &operator=(_Enable_copy_move const &) noexcept = default;
    _Enable_copy_move &operator=(_Enable_copy_move &&) noexcept = delete;
  };

  template <typename _Tag>
  struct _Enable_copy_move<false, true, true, false, _Tag> {
    constexpr _Enable_copy_move() noexcept = default;
    constexpr _Enable_copy_move(_Enable_copy_move const &) noexcept = delete;
    constexpr _Enable_copy_move(_Enable_copy_move &&) noexcept = default;
    _Enable_copy_move &operator=(_Enable_copy_move const &) noexcept = default;
    _Enable_copy_move &operator=(_Enable_copy_move &&) noexcept = delete;
  };

  template <typename _Tag>
  struct _Enable_copy_move<true, false, true, false, _Tag> {
    constexpr _Enable_copy_move() noexcept = default;
    constexpr _Enable_copy_move(_Enable_copy_move const &) noexcept = default;
    constexpr _Enable_copy_move(_Enable_copy_move &&) noexcept = default;
    _Enable_copy_move &operator=(_Enable_copy_move const &) noexcept = delete;
    _Enable_copy_move &operator=(_Enable_copy_move &&) noexcept = delete;
  };

  template <typename _Tag>
  struct _Enable_copy_move<false, false, true, false, _Tag> {
    constexpr _Enable_copy_move() noexcept = default;
    constexpr _Enable_copy_move(_Enable_copy_move const &) noexcept = delete;
    constexpr _Enable_copy_move(_Enable_copy_move &&) noexcept = default;
    _Enable_copy_move &operator=(_Enable_copy_move const &) noexcept = delete;
    _Enable_copy_move &operator=(_Enable_copy_move &&) noexcept = delete;
  };

  template <typename _Tag>
  struct _Enable_copy_move<true, true, false, false, _Tag> {
    constexpr _Enable_copy_move() noexcept = default;
    constexpr _Enable_copy_move(_Enable_copy_move const &) noexcept = default;
    constexpr _Enable_copy_move(_Enable_copy_move &&) noexcept = delete;
    _Enable_copy_move &operator=(_Enable_copy_move const &) noexcept = default;
    _Enable_copy_move &operator=(_Enable_copy_move &&) noexcept = delete;
  };

  template <typename _Tag>
  struct _Enable_copy_move<false, true, false, false, _Tag> {
    constexpr _Enable_copy_move() noexcept = default;
    constexpr _Enable_copy_move(_Enable_copy_move const &) noexcept = delete;
    constexpr _Enable_copy_move(_Enable_copy_move &&) noexcept = delete;
    _Enable_copy_move &operator=(_Enable_copy_move const &) noexcept = default;
    _Enable_copy_move &operator=(_Enable_copy_move &&) noexcept = delete;
  };

  template <typename _Tag>
  struct _Enable_copy_move<true, false, false, false, _Tag> {
    constexpr _Enable_copy_move() noexcept = default;
    constexpr _Enable_copy_move(_Enable_copy_move const &) noexcept = default;
    constexpr _Enable_copy_move(_Enable_copy_move &&) noexcept = delete;
    _Enable_copy_move &operator=(_Enable_copy_move const &) noexcept = delete;
    _Enable_copy_move &operator=(_Enable_copy_move &&) noexcept = delete;
  };

  template <typename _Tag>
  struct _Enable_copy_move<false, false, false, false, _Tag> {
    constexpr _Enable_copy_move() noexcept = default;
    constexpr _Enable_copy_move(_Enable_copy_move const &) noexcept = delete;
    constexpr _Enable_copy_move(_Enable_copy_move &&) noexcept = delete;
    _Enable_copy_move &operator=(_Enable_copy_move const &) noexcept = delete;
    _Enable_copy_move &operator=(_Enable_copy_move &&) noexcept = delete;
  };

} // namespace std
namespace std __attribute__((__visibility__("default"))) {

  template <typename _Arg, typename _Result> struct unary_function {

    typedef _Arg argument_type;

    typedef _Result result_type;
  } __attribute__((__deprecated__));

  template <typename _Arg1, typename _Arg2, typename _Result>
  struct binary_function {

    typedef _Arg1 first_argument_type;

    typedef _Arg2 second_argument_type;

    typedef _Result result_type;
  } __attribute__((__deprecated__));
  struct __is_transparent;

  template <typename _Tp = void> struct plus;

  template <typename _Tp = void> struct minus;

  template <typename _Tp = void> struct multiplies;

  template <typename _Tp = void> struct divides;

  template <typename _Tp = void> struct modulus;

  template <typename _Tp = void> struct negate;

  template <typename _Tp> struct plus : public binary_function<_Tp, _Tp, _Tp> {

    constexpr _Tp operator()(const _Tp &__x, const _Tp &__y) const {
      return __x + __y;
    }
  };

  template <typename _Tp> struct minus : public binary_function<_Tp, _Tp, _Tp> {
    constexpr _Tp operator()(const _Tp &__x, const _Tp &__y) const {
      return __x - __y;
    }
  };

  template <typename _Tp>
  struct multiplies : public binary_function<_Tp, _Tp, _Tp> {
    constexpr _Tp operator()(const _Tp &__x, const _Tp &__y) const {
      return __x * __y;
    }
  };

  template <typename _Tp>
  struct divides : public binary_function<_Tp, _Tp, _Tp> {
    constexpr _Tp operator()(const _Tp &__x, const _Tp &__y) const {
      return __x / __y;
    }
  };

  template <typename _Tp>
  struct modulus : public binary_function<_Tp, _Tp, _Tp> {
    constexpr _Tp operator()(const _Tp &__x, const _Tp &__y) const {
      return __x % __y;
    }
  };

  template <typename _Tp> struct negate : public unary_function<_Tp, _Tp> {
    constexpr _Tp operator()(const _Tp &__x) const { return -__x; }
  };

  template <> struct plus<void> {
    template <typename _Tp, typename _Up>
    constexpr auto operator()(_Tp &&__t, _Up &&__u) const
        noexcept(noexcept(std::forward<_Tp>(__t) + std::forward<_Up>(__u)))
            -> decltype(std::forward<_Tp>(__t) + std::forward<_Up>(__u)) {
      return std::forward<_Tp>(__t) + std::forward<_Up>(__u);
    }

    typedef __is_transparent is_transparent;
  };

  template <> struct minus<void> {
    template <typename _Tp, typename _Up>
    constexpr auto operator()(_Tp &&__t, _Up &&__u) const
        noexcept(noexcept(std::forward<_Tp>(__t) - std::forward<_Up>(__u)))
            -> decltype(std::forward<_Tp>(__t) - std::forward<_Up>(__u)) {
      return std::forward<_Tp>(__t) - std::forward<_Up>(__u);
    }

    typedef __is_transparent is_transparent;
  };

  template <> struct multiplies<void> {
    template <typename _Tp, typename _Up>
    constexpr auto operator()(_Tp &&__t, _Up &&__u) const
        noexcept(noexcept(std::forward<_Tp>(__t) * std::forward<_Up>(__u)))
            -> decltype(std::forward<_Tp>(__t) * std::forward<_Up>(__u)) {
      return std::forward<_Tp>(__t) * std::forward<_Up>(__u);
    }

    typedef __is_transparent is_transparent;
  };

  template <> struct divides<void> {
    template <typename _Tp, typename _Up>
    constexpr auto operator()(_Tp &&__t, _Up &&__u) const
        noexcept(noexcept(std::forward<_Tp>(__t) / std::forward<_Up>(__u)))
            -> decltype(std::forward<_Tp>(__t) / std::forward<_Up>(__u)) {
      return std::forward<_Tp>(__t) / std::forward<_Up>(__u);
    }

    typedef __is_transparent is_transparent;
  };

  template <> struct modulus<void> {
    template <typename _Tp, typename _Up>
    constexpr auto operator()(_Tp &&__t, _Up &&__u) const
        noexcept(noexcept(std::forward<_Tp>(__t) % std::forward<_Up>(__u)))
            -> decltype(std::forward<_Tp>(__t) % std::forward<_Up>(__u)) {
      return std::forward<_Tp>(__t) % std::forward<_Up>(__u);
    }

    typedef __is_transparent is_transparent;
  };

  template <> struct negate<void> {
    template <typename _Tp>
    constexpr auto operator()(_Tp &&__t) const
        noexcept(noexcept(-std::forward<_Tp>(__t)))
            -> decltype(-std::forward<_Tp>(__t)) {
      return -std::forward<_Tp>(__t);
    }

    typedef __is_transparent is_transparent;
  };
  template <typename _Tp = void> struct equal_to;

  template <typename _Tp = void> struct not_equal_to;

  template <typename _Tp = void> struct greater;

  template <typename _Tp = void> struct less;

  template <typename _Tp = void> struct greater_equal;

  template <typename _Tp = void> struct less_equal;

  template <typename _Tp>
  struct equal_to : public binary_function<_Tp, _Tp, bool> {
    constexpr bool operator()(const _Tp &__x, const _Tp &__y) const {
      return __x == __y;
    }
  };

  template <typename _Tp>
  struct not_equal_to : public binary_function<_Tp, _Tp, bool> {
    constexpr bool operator()(const _Tp &__x, const _Tp &__y) const {
      return __x != __y;
    }
  };

  template <typename _Tp>
  struct greater : public binary_function<_Tp, _Tp, bool> {
    constexpr bool operator()(const _Tp &__x, const _Tp &__y) const {
      return __x > __y;
    }
  };

  template <typename _Tp> struct less : public binary_function<_Tp, _Tp, bool> {
    constexpr bool operator()(const _Tp &__x, const _Tp &__y) const {
      return __x < __y;
    }
  };

  template <typename _Tp>
  struct greater_equal : public binary_function<_Tp, _Tp, bool> {
    constexpr bool operator()(const _Tp &__x, const _Tp &__y) const {
      return __x >= __y;
    }
  };

  template <typename _Tp>
  struct less_equal : public binary_function<_Tp, _Tp, bool> {
    constexpr bool operator()(const _Tp &__x, const _Tp &__y) const {
      return __x <= __y;
    }
  };

  template <typename _Tp>
  struct greater<_Tp *> : public binary_function<_Tp *, _Tp *, bool> {
    constexpr bool operator()(_Tp *__x, _Tp *__y) const noexcept {

      if (std::__is_constant_evaluated())
        return __x > __y;

      return (long unsigned int)__x > (long unsigned int)__y;
    }
  };

  template <typename _Tp>
  struct less<_Tp *> : public binary_function<_Tp *, _Tp *, bool> {
    constexpr bool operator()(_Tp *__x, _Tp *__y) const noexcept {

      if (std::__is_constant_evaluated())
        return __x < __y;

      return (long unsigned int)__x < (long unsigned int)__y;
    }
  };

  template <typename _Tp>
  struct greater_equal<_Tp *> : public binary_function<_Tp *, _Tp *, bool> {
    constexpr bool operator()(_Tp *__x, _Tp *__y) const noexcept {

      if (std::__is_constant_evaluated())
        return __x >= __y;

      return (long unsigned int)__x >= (long unsigned int)__y;
    }
  };

  template <typename _Tp>
  struct less_equal<_Tp *> : public binary_function<_Tp *, _Tp *, bool> {
    constexpr bool operator()(_Tp *__x, _Tp *__y) const noexcept {

      if (std::__is_constant_evaluated())
        return __x <= __y;

      return (long unsigned int)__x <= (long unsigned int)__y;
    }
  };

  template <> struct equal_to<void> {
    template <typename _Tp, typename _Up>
    constexpr auto operator()(_Tp &&__t, _Up &&__u) const
        noexcept(noexcept(std::forward<_Tp>(__t) == std::forward<_Up>(__u)))
            -> decltype(std::forward<_Tp>(__t) == std::forward<_Up>(__u)) {
      return std::forward<_Tp>(__t) == std::forward<_Up>(__u);
    }

    typedef __is_transparent is_transparent;
  };

  template <> struct not_equal_to<void> {
    template <typename _Tp, typename _Up>
    constexpr auto operator()(_Tp &&__t, _Up &&__u) const
        noexcept(noexcept(std::forward<_Tp>(__t) != std::forward<_Up>(__u)))
            -> decltype(std::forward<_Tp>(__t) != std::forward<_Up>(__u)) {
      return std::forward<_Tp>(__t) != std::forward<_Up>(__u);
    }

    typedef __is_transparent is_transparent;
  };

  template <> struct greater<void> {
    template <typename _Tp, typename _Up>
    constexpr auto operator()(_Tp &&__t, _Up &&__u) const
        noexcept(noexcept(std::forward<_Tp>(__t) > std::forward<_Up>(__u)))
            -> decltype(std::forward<_Tp>(__t) > std::forward<_Up>(__u)) {
      return _S_cmp(std::forward<_Tp>(__t), std::forward<_Up>(__u),
                    __ptr_cmp<_Tp, _Up>{});
    }

    template <typename _Tp, typename _Up>
    constexpr bool operator()(_Tp *__t, _Up *__u) const noexcept {
      return greater<common_type_t<_Tp *, _Up *>>{}(__t, __u);
    }

    typedef __is_transparent is_transparent;

  private:
    template <typename _Tp, typename _Up>
    static constexpr decltype(auto) _S_cmp(_Tp &&__t, _Up &&__u, false_type) {
      return std::forward<_Tp>(__t) > std::forward<_Up>(__u);
    }

    template <typename _Tp, typename _Up>
    static constexpr bool _S_cmp(_Tp &&__t, _Up &&__u, true_type) noexcept {
      return greater<const volatile void *>{}(
          static_cast<const volatile void *>(std::forward<_Tp>(__t)),
          static_cast<const volatile void *>(std::forward<_Up>(__u)));
    }

    template <typename _Tp, typename _Up, typename = void>
    struct __not_overloaded2 : true_type {};

    template <typename _Tp, typename _Up>
    struct __not_overloaded2<
        _Tp, _Up,
        __void_t<decltype(std::declval<_Tp>().operator>(std::declval<_Up>()))>>
        : false_type {};

    template <typename _Tp, typename _Up, typename = void>
    struct __not_overloaded : __not_overloaded2<_Tp, _Up> {};

    template <typename _Tp, typename _Up>
    struct __not_overloaded<
        _Tp, _Up,
        __void_t<decltype(operator>(std::declval<_Tp>(), std::declval<_Up>()))>>
        : false_type {};

    template <typename _Tp, typename _Up>
    using __ptr_cmp = __and_<__not_overloaded<_Tp, _Up>,
                             is_convertible<_Tp, const volatile void *>,
                             is_convertible<_Up, const volatile void *>>;
  };

  template <> struct less<void> {
    template <typename _Tp, typename _Up>
    constexpr auto operator()(_Tp &&__t, _Up &&__u) const
        noexcept(noexcept(std::forward<_Tp>(__t) < std::forward<_Up>(__u)))
            -> decltype(std::forward<_Tp>(__t) < std::forward<_Up>(__u)) {
      return _S_cmp(std::forward<_Tp>(__t), std::forward<_Up>(__u),
                    __ptr_cmp<_Tp, _Up>{});
    }

    template <typename _Tp, typename _Up>
    constexpr bool operator()(_Tp *__t, _Up *__u) const noexcept {
      return less<common_type_t<_Tp *, _Up *>>{}(__t, __u);
    }

    typedef __is_transparent is_transparent;

  private:
    template <typename _Tp, typename _Up>
    static constexpr decltype(auto) _S_cmp(_Tp &&__t, _Up &&__u, false_type) {
      return std::forward<_Tp>(__t) < std::forward<_Up>(__u);
    }

    template <typename _Tp, typename _Up>
    static constexpr bool _S_cmp(_Tp &&__t, _Up &&__u, true_type) noexcept {
      return less<const volatile void *>{}(
          static_cast<const volatile void *>(std::forward<_Tp>(__t)),
          static_cast<const volatile void *>(std::forward<_Up>(__u)));
    }

    template <typename _Tp, typename _Up, typename = void>
    struct __not_overloaded2 : true_type {};

    template <typename _Tp, typename _Up>
    struct __not_overloaded2<
        _Tp, _Up,
        __void_t<decltype(std::declval<_Tp>().operator<(std::declval<_Up>()))>>
        : false_type {};

    template <typename _Tp, typename _Up, typename = void>
    struct __not_overloaded : __not_overloaded2<_Tp, _Up> {};

    template <typename _Tp, typename _Up>
    struct __not_overloaded<
        _Tp, _Up,
        __void_t<decltype(operator<(std::declval<_Tp>(), std::declval<_Up>()))>>
        : false_type {};

    template <typename _Tp, typename _Up>
    using __ptr_cmp = __and_<__not_overloaded<_Tp, _Up>,
                             is_convertible<_Tp, const volatile void *>,
                             is_convertible<_Up, const volatile void *>>;
  };

  template <> struct greater_equal<void> {
    template <typename _Tp, typename _Up>
    constexpr auto operator()(_Tp &&__t, _Up &&__u) const
        noexcept(noexcept(std::forward<_Tp>(__t) >= std::forward<_Up>(__u)))
            -> decltype(std::forward<_Tp>(__t) >= std::forward<_Up>(__u)) {
      return _S_cmp(std::forward<_Tp>(__t), std::forward<_Up>(__u),
                    __ptr_cmp<_Tp, _Up>{});
    }

    template <typename _Tp, typename _Up>
    constexpr bool operator()(_Tp *__t, _Up *__u) const noexcept {
      return greater_equal<common_type_t<_Tp *, _Up *>>{}(__t, __u);
    }

    typedef __is_transparent is_transparent;

  private:
    template <typename _Tp, typename _Up>
    static constexpr decltype(auto) _S_cmp(_Tp &&__t, _Up &&__u, false_type) {
      return std::forward<_Tp>(__t) >= std::forward<_Up>(__u);
    }

    template <typename _Tp, typename _Up>
    static constexpr bool _S_cmp(_Tp &&__t, _Up &&__u, true_type) noexcept {
      return greater_equal<const volatile void *>{}(
          static_cast<const volatile void *>(std::forward<_Tp>(__t)),
          static_cast<const volatile void *>(std::forward<_Up>(__u)));
    }

    template <typename _Tp, typename _Up, typename = void>
    struct __not_overloaded2 : true_type {};

    template <typename _Tp, typename _Up>
    struct __not_overloaded2<
        _Tp, _Up,
        __void_t<decltype(std::declval<_Tp>().operator>=(std::declval<_Up>()))>>
        : false_type {};

    template <typename _Tp, typename _Up, typename = void>
    struct __not_overloaded : __not_overloaded2<_Tp, _Up> {};

    template <typename _Tp, typename _Up>
    struct __not_overloaded<_Tp, _Up,
                            __void_t<decltype(operator>=(std::declval<_Tp>(),
                                                         std::declval<_Up>()))>>
        : false_type {};

    template <typename _Tp, typename _Up>
    using __ptr_cmp = __and_<__not_overloaded<_Tp, _Up>,
                             is_convertible<_Tp, const volatile void *>,
                             is_convertible<_Up, const volatile void *>>;
  };

  template <> struct less_equal<void> {
    template <typename _Tp, typename _Up>
    constexpr auto operator()(_Tp &&__t, _Up &&__u) const
        noexcept(noexcept(std::forward<_Tp>(__t) <= std::forward<_Up>(__u)))
            -> decltype(std::forward<_Tp>(__t) <= std::forward<_Up>(__u)) {
      return _S_cmp(std::forward<_Tp>(__t), std::forward<_Up>(__u),
                    __ptr_cmp<_Tp, _Up>{});
    }

    template <typename _Tp, typename _Up>
    constexpr bool operator()(_Tp *__t, _Up *__u) const noexcept {
      return less_equal<common_type_t<_Tp *, _Up *>>{}(__t, __u);
    }

    typedef __is_transparent is_transparent;

  private:
    template <typename _Tp, typename _Up>
    static constexpr decltype(auto) _S_cmp(_Tp &&__t, _Up &&__u, false_type) {
      return std::forward<_Tp>(__t) <= std::forward<_Up>(__u);
    }

    template <typename _Tp, typename _Up>
    static constexpr bool _S_cmp(_Tp &&__t, _Up &&__u, true_type) noexcept {
      return less_equal<const volatile void *>{}(
          static_cast<const volatile void *>(std::forward<_Tp>(__t)),
          static_cast<const volatile void *>(std::forward<_Up>(__u)));
    }

    template <typename _Tp, typename _Up, typename = void>
    struct __not_overloaded2 : true_type {};

    template <typename _Tp, typename _Up>
    struct __not_overloaded2<
        _Tp, _Up,
        __void_t<decltype(std::declval<_Tp>().operator<=(std::declval<_Up>()))>>
        : false_type {};

    template <typename _Tp, typename _Up, typename = void>
    struct __not_overloaded : __not_overloaded2<_Tp, _Up> {};

    template <typename _Tp, typename _Up>
    struct __not_overloaded<_Tp, _Up,
                            __void_t<decltype(operator<=(std::declval<_Tp>(),
                                                         std::declval<_Up>()))>>
        : false_type {};

    template <typename _Tp, typename _Up>
    using __ptr_cmp = __and_<__not_overloaded<_Tp, _Up>,
                             is_convertible<_Tp, const volatile void *>,
                             is_convertible<_Up, const volatile void *>>;
  };
  template <typename _Tp = void> struct logical_and;

  template <typename _Tp = void> struct logical_or;

  template <typename _Tp = void> struct logical_not;

  template <typename _Tp>
  struct logical_and : public binary_function<_Tp, _Tp, bool> {
    constexpr bool operator()(const _Tp &__x, const _Tp &__y) const {
      return __x && __y;
    }
  };

  template <typename _Tp>
  struct logical_or : public binary_function<_Tp, _Tp, bool> {
    constexpr bool operator()(const _Tp &__x, const _Tp &__y) const {
      return __x || __y;
    }
  };

  template <typename _Tp>
  struct logical_not : public unary_function<_Tp, bool> {
    constexpr bool operator()(const _Tp &__x) const { return !__x; }
  };

  template <> struct logical_and<void> {
    template <typename _Tp, typename _Up>
    constexpr auto operator()(_Tp &&__t, _Up &&__u) const
        noexcept(noexcept(std::forward<_Tp>(__t) && std::forward<_Up>(__u)))
            -> decltype(std::forward<_Tp>(__t) && std::forward<_Up>(__u)) {
      return std::forward<_Tp>(__t) && std::forward<_Up>(__u);
    }

    typedef __is_transparent is_transparent;
  };

  template <> struct logical_or<void> {
    template <typename _Tp, typename _Up>
    constexpr auto operator()(_Tp &&__t, _Up &&__u) const
        noexcept(noexcept(std::forward<_Tp>(__t) || std::forward<_Up>(__u)))
            -> decltype(std::forward<_Tp>(__t) || std::forward<_Up>(__u)) {
      return std::forward<_Tp>(__t) || std::forward<_Up>(__u);
    }

    typedef __is_transparent is_transparent;
  };

  template <> struct logical_not<void> {
    template <typename _Tp>
    constexpr auto operator()(_Tp &&__t) const
        noexcept(noexcept(!std::forward<_Tp>(__t)))
            -> decltype(!std::forward<_Tp>(__t)) {
      return !std::forward<_Tp>(__t);
    }

    typedef __is_transparent is_transparent;
  };

  template <typename _Tp = void> struct bit_and;

  template <typename _Tp = void> struct bit_or;

  template <typename _Tp = void> struct bit_xor;

  template <typename _Tp = void> struct bit_not;

  template <typename _Tp>
  struct bit_and : public binary_function<_Tp, _Tp, _Tp> {
    constexpr _Tp operator()(const _Tp &__x, const _Tp &__y) const {
      return __x & __y;
    }
  };

  template <typename _Tp>
  struct bit_or : public binary_function<_Tp, _Tp, _Tp> {
    constexpr _Tp operator()(const _Tp &__x, const _Tp &__y) const {
      return __x | __y;
    }
  };

  template <typename _Tp>
  struct bit_xor : public binary_function<_Tp, _Tp, _Tp> {
    constexpr _Tp operator()(const _Tp &__x, const _Tp &__y) const {
      return __x ^ __y;
    }
  };

  template <typename _Tp> struct bit_not : public unary_function<_Tp, _Tp> {
    constexpr _Tp operator()(const _Tp &__x) const { return ~__x; }
  };

  template <> struct bit_and<void> {
    template <typename _Tp, typename _Up>
    constexpr auto operator()(_Tp &&__t, _Up &&__u) const
        noexcept(noexcept(std::forward<_Tp>(__t) & std::forward<_Up>(__u)))
            -> decltype(std::forward<_Tp>(__t) & std::forward<_Up>(__u)) {
      return std::forward<_Tp>(__t) & std::forward<_Up>(__u);
    }

    typedef __is_transparent is_transparent;
  };

  template <> struct bit_or<void> {
    template <typename _Tp, typename _Up>
    constexpr auto operator()(_Tp &&__t, _Up &&__u) const
        noexcept(noexcept(std::forward<_Tp>(__t) | std::forward<_Up>(__u)))
            -> decltype(std::forward<_Tp>(__t) | std::forward<_Up>(__u)) {
      return std::forward<_Tp>(__t) | std::forward<_Up>(__u);
    }

    typedef __is_transparent is_transparent;
  };

  template <> struct bit_xor<void> {
    template <typename _Tp, typename _Up>
    constexpr auto operator()(_Tp &&__t, _Up &&__u) const
        noexcept(noexcept(std::forward<_Tp>(__t) ^ std::forward<_Up>(__u)))
            -> decltype(std::forward<_Tp>(__t) ^ std::forward<_Up>(__u)) {
      return std::forward<_Tp>(__t) ^ std::forward<_Up>(__u);
    }

    typedef __is_transparent is_transparent;
  };

  template <> struct bit_not<void> {
    template <typename _Tp>
    constexpr auto operator()(_Tp &&__t) const
        noexcept(noexcept(~std::forward<_Tp>(__t)))
            -> decltype(~std::forward<_Tp>(__t)) {
      return ~std::forward<_Tp>(__t);
    }

    typedef __is_transparent is_transparent;
  };

  template <typename _Predicate>
  class [[__deprecated__]] unary_negate
      : public unary_function<typename _Predicate::argument_type, bool> {
  protected:
    _Predicate _M_pred;

  public:
    constexpr explicit unary_negate(const _Predicate &__x) : _M_pred(__x) {}

    constexpr bool
    operator()(const typename _Predicate::argument_type &__x) const {
      return !_M_pred(__x);
    }
  };

  template <typename _Predicate>
  __attribute__((
      __deprecated__("use '"
                     "std::not_fn"
                     "' instead"))) constexpr inline unary_negate<_Predicate>
  not1(const _Predicate &__pred) {
    return unary_negate<_Predicate>(__pred);
  }

  template <typename _Predicate>
  class [[__deprecated__]] binary_negate
      : public binary_function<typename _Predicate::first_argument_type,
                               typename _Predicate::second_argument_type,
                               bool> {
  protected:
    _Predicate _M_pred;

  public:
    constexpr explicit binary_negate(const _Predicate &__x) : _M_pred(__x) {}

    constexpr bool
    operator()(const typename _Predicate::first_argument_type &__x,
               const typename _Predicate::second_argument_type &__y) const {
      return !_M_pred(__x, __y);
    }
  };

  template <typename _Predicate>
  __attribute__((
      __deprecated__("use '"
                     "std::not_fn"
                     "' instead"))) constexpr inline binary_negate<_Predicate>
  not2(const _Predicate &__pred) {
    return binary_negate<_Predicate>(__pred);
  }
  template <typename _Arg, typename _Result>
  class pointer_to_unary_function : public unary_function<_Arg, _Result> {
  protected:
    _Result (*_M_ptr)(_Arg);

  public:
    pointer_to_unary_function() {}

    explicit pointer_to_unary_function(_Result (*__x)(_Arg)) : _M_ptr(__x) {}

    _Result operator()(_Arg __x) const { return _M_ptr(__x); }
  } __attribute__((__deprecated__));

  template <typename _Arg, typename _Result>
  __attribute__((__deprecated__(
      "use '"
      "std::function"
      "' instead"))) inline pointer_to_unary_function<_Arg, _Result>
  ptr_fun(_Result(*__x)(_Arg)) {
    return pointer_to_unary_function<_Arg, _Result>(__x);
  }

  template <typename _Arg1, typename _Arg2, typename _Result>
  class pointer_to_binary_function
      : public binary_function<_Arg1, _Arg2, _Result> {
  protected:
    _Result (*_M_ptr)(_Arg1, _Arg2);

  public:
    pointer_to_binary_function() {}

    explicit pointer_to_binary_function(_Result (*__x)(_Arg1, _Arg2))
        : _M_ptr(__x) {}

    _Result operator()(_Arg1 __x, _Arg2 __y) const { return _M_ptr(__x, __y); }
  } __attribute__((__deprecated__));

  template <typename _Arg1, typename _Arg2, typename _Result>
  __attribute__((__deprecated__(
      "use '"
      "std::function"
      "' instead"))) inline pointer_to_binary_function<_Arg1, _Arg2, _Result>
  ptr_fun(_Result(*__x)(_Arg1, _Arg2)) {
    return pointer_to_binary_function<_Arg1, _Arg2, _Result>(__x);
  }

  template <typename _Tp> struct _Identity : public unary_function<_Tp, _Tp> {
    _Tp &operator()(_Tp &__x) const { return __x; }

    const _Tp &operator()(const _Tp &__x) const { return __x; }
  };

  template <typename _Tp> struct _Identity<const _Tp> : _Identity<_Tp> {};

  template <typename _Pair>
  struct _Select1st : public unary_function<_Pair, typename _Pair::first_type> {
    typename _Pair::first_type &operator()(_Pair &__x) const {
      return __x.first;
    }

    const typename _Pair::first_type &operator()(const _Pair &__x) const {
      return __x.first;
    }

    template <typename _Pair2>
    typename _Pair2::first_type &operator()(_Pair2 &__x) const {
      return __x.first;
    }

    template <typename _Pair2>
    const typename _Pair2::first_type &operator()(const _Pair2 &__x) const {
      return __x.first;
    }
  };

  template <typename _Pair>
  struct _Select2nd
      : public unary_function<_Pair, typename _Pair::second_type> {
    typename _Pair::second_type &operator()(_Pair &__x) const {
      return __x.second;
    }

    const typename _Pair::second_type &operator()(const _Pair &__x) const {
      return __x.second;
    }
  };
  template <typename _Ret, typename _Tp>
  class mem_fun_t : public unary_function<_Tp *, _Ret> {
  public:
    explicit mem_fun_t(_Ret (_Tp::*__pf)()) : _M_f(__pf) {}

    _Ret operator()(_Tp *__p) const { return (__p->*_M_f)(); }

  private:
    _Ret (_Tp::*_M_f)();
  } __attribute__((__deprecated__));

  template <typename _Ret, typename _Tp>
  class const_mem_fun_t : public unary_function<const _Tp *, _Ret> {
  public:
    explicit const_mem_fun_t(_Ret (_Tp::*__pf)() const) : _M_f(__pf) {}

    _Ret operator()(const _Tp *__p) const { return (__p->*_M_f)(); }

  private:
    _Ret (_Tp::*_M_f)() const;
  } __attribute__((__deprecated__));

  template <typename _Ret, typename _Tp>
  class mem_fun_ref_t : public unary_function<_Tp, _Ret> {
  public:
    explicit mem_fun_ref_t(_Ret (_Tp::*__pf)()) : _M_f(__pf) {}

    _Ret operator()(_Tp &__r) const { return (__r.*_M_f)(); }

  private:
    _Ret (_Tp::*_M_f)();
  } __attribute__((__deprecated__));

  template <typename _Ret, typename _Tp>
  class const_mem_fun_ref_t : public unary_function<_Tp, _Ret> {
  public:
    explicit const_mem_fun_ref_t(_Ret (_Tp::*__pf)() const) : _M_f(__pf) {}

    _Ret operator()(const _Tp &__r) const { return (__r.*_M_f)(); }

  private:
    _Ret (_Tp::*_M_f)() const;
  } __attribute__((__deprecated__));

  template <typename _Ret, typename _Tp, typename _Arg>
  class mem_fun1_t : public binary_function<_Tp *, _Arg, _Ret> {
  public:
    explicit mem_fun1_t(_Ret (_Tp::*__pf)(_Arg)) : _M_f(__pf) {}

    _Ret operator()(_Tp *__p, _Arg __x) const { return (__p->*_M_f)(__x); }

  private:
    _Ret (_Tp::*_M_f)(_Arg);
  } __attribute__((__deprecated__));

  template <typename _Ret, typename _Tp, typename _Arg>
  class const_mem_fun1_t : public binary_function<const _Tp *, _Arg, _Ret> {
  public:
    explicit const_mem_fun1_t(_Ret (_Tp::*__pf)(_Arg) const) : _M_f(__pf) {}

    _Ret operator()(const _Tp *__p, _Arg __x) const {
      return (__p->*_M_f)(__x);
    }

  private:
    _Ret (_Tp::*_M_f)(_Arg) const;
  } __attribute__((__deprecated__));

  template <typename _Ret, typename _Tp, typename _Arg>
  class mem_fun1_ref_t : public binary_function<_Tp, _Arg, _Ret> {
  public:
    explicit mem_fun1_ref_t(_Ret (_Tp::*__pf)(_Arg)) : _M_f(__pf) {}

    _Ret operator()(_Tp &__r, _Arg __x) const { return (__r.*_M_f)(__x); }

  private:
    _Ret (_Tp::*_M_f)(_Arg);
  } __attribute__((__deprecated__));

  template <typename _Ret, typename _Tp, typename _Arg>
  class const_mem_fun1_ref_t : public binary_function<_Tp, _Arg, _Ret> {
  public:
    explicit const_mem_fun1_ref_t(_Ret (_Tp::*__pf)(_Arg) const) : _M_f(__pf) {}

    _Ret operator()(const _Tp &__r, _Arg __x) const { return (__r.*_M_f)(__x); }

  private:
    _Ret (_Tp::*_M_f)(_Arg) const;
  } __attribute__((__deprecated__));

  template <typename _Ret, typename _Tp>
  __attribute__((__deprecated__("use '"
                                "std::mem_fn"
                                "' instead"))) inline mem_fun_t<_Ret, _Tp>
  mem_fun(_Ret(_Tp::*__f)()) {
    return mem_fun_t<_Ret, _Tp>(__f);
  }

  template <typename _Ret, typename _Tp>
  __attribute__((__deprecated__("use '"
                                "std::mem_fn"
                                "' instead"))) inline const_mem_fun_t<_Ret, _Tp>
  mem_fun(_Ret(_Tp::*__f)() const) {
    return const_mem_fun_t<_Ret, _Tp>(__f);
  }

  template <typename _Ret, typename _Tp>
  __attribute__((__deprecated__("use '"
                                "std::mem_fn"
                                "' instead"))) inline mem_fun_ref_t<_Ret, _Tp>
  mem_fun_ref(_Ret(_Tp::*__f)()) {
    return mem_fun_ref_t<_Ret, _Tp>(__f);
  }

  template <typename _Ret, typename _Tp>
  __attribute__((
      __deprecated__("use '"
                     "std::mem_fn"
                     "' instead"))) inline const_mem_fun_ref_t<_Ret, _Tp>
  mem_fun_ref(_Ret(_Tp::*__f)() const) {
    return const_mem_fun_ref_t<_Ret, _Tp>(__f);
  }

  template <typename _Ret, typename _Tp, typename _Arg>
  __attribute__((
      __deprecated__("use '"
                     "std::mem_fn"
                     "' instead"))) inline mem_fun1_t<_Ret, _Tp, _Arg>
  mem_fun(_Ret(_Tp::*__f)(_Arg)) {
    return mem_fun1_t<_Ret, _Tp, _Arg>(__f);
  }

  template <typename _Ret, typename _Tp, typename _Arg>
  __attribute__((
      __deprecated__("use '"
                     "std::mem_fn"
                     "' instead"))) inline const_mem_fun1_t<_Ret, _Tp, _Arg>
  mem_fun(_Ret(_Tp::*__f)(_Arg) const) {
    return const_mem_fun1_t<_Ret, _Tp, _Arg>(__f);
  }

  template <typename _Ret, typename _Tp, typename _Arg>
  __attribute__((
      __deprecated__("use '"
                     "std::mem_fn"
                     "' instead"))) inline mem_fun1_ref_t<_Ret, _Tp, _Arg>
  mem_fun_ref(_Ret(_Tp::*__f)(_Arg)) {
    return mem_fun1_ref_t<_Ret, _Tp, _Arg>(__f);
  }

  template <typename _Ret, typename _Tp, typename _Arg>
  __attribute__((
      __deprecated__("use '"
                     "std::mem_fn"
                     "' instead"))) inline const_mem_fun1_ref_t<_Ret, _Tp, _Arg>
  mem_fun_ref(_Ret(_Tp::*__f)(_Arg) const) {
    return const_mem_fun1_ref_t<_Ret, _Tp, _Arg>(__f);
  }

  template <typename _Func, typename _SfinaeType, typename = __void_t<>>
  struct __has_is_transparent {};

  template <typename _Func, typename _SfinaeType>
  struct __has_is_transparent<_Func, _SfinaeType,
                              __void_t<typename _Func::is_transparent>> {
    typedef void type;
  };

  template <typename _Func, typename _SfinaeType>
  using __has_is_transparent_t =
      typename __has_is_transparent<_Func, _SfinaeType>::type;

} // namespace std

namespace std __attribute__((__visibility__("default"))) {

  template <typename _Operation>
  class binder1st
      : public unary_function<typename _Operation::second_argument_type,
                              typename _Operation::result_type> {
  protected:
    _Operation op;
    typename _Operation::first_argument_type value;

  public:
    binder1st(const _Operation &__x,
              const typename _Operation::first_argument_type &__y)
        : op(__x), value(__y) {}

    typename _Operation::result_type
    operator()(const typename _Operation::second_argument_type &__x) const {
      return op(value, __x);
    }

    typename _Operation::result_type
    operator()(typename _Operation::second_argument_type &__x) const {
      return op(value, __x);
    }
  } __attribute__((__deprecated__("use '"
                                  "std::bind"
                                  "' instead")));

  template <typename _Operation, typename _Tp>
  __attribute__((__deprecated__("use '"
                                "std::bind"
                                "' instead"))) inline binder1st<_Operation>
  bind1st(const _Operation &__fn, const _Tp &__x) {
    typedef typename _Operation::first_argument_type _Arg1_type;
    return binder1st<_Operation>(__fn, _Arg1_type(__x));
  }

  template <typename _Operation>
  class binder2nd
      : public unary_function<typename _Operation::first_argument_type,
                              typename _Operation::result_type> {
  protected:
    _Operation op;
    typename _Operation::second_argument_type value;

  public:
    binder2nd(const _Operation &__x,
              const typename _Operation::second_argument_type &__y)
        : op(__x), value(__y) {}

    typename _Operation::result_type
    operator()(const typename _Operation::first_argument_type &__x) const {
      return op(__x, value);
    }

    typename _Operation::result_type
    operator()(typename _Operation::first_argument_type &__x) const {
      return op(__x, value);
    }
  } __attribute__((__deprecated__("use '"
                                  "std::bind"
                                  "' instead")));

  template <typename _Operation, typename _Tp>
  __attribute__((__deprecated__("use '"
                                "std::bind"
                                "' instead"))) inline binder2nd<_Operation>
  bind2nd(const _Operation &__fn, const _Tp &__x) {
    typedef typename _Operation::second_argument_type _Arg2_type;
    return binder2nd<_Operation>(__fn, _Arg2_type(__x));
  }

} // namespace std

namespace std __attribute__((__visibility__("default"))) {

  template <typename _Val, typename _NodeAlloc> class _Node_handle_common {
    using _AllocTraits = allocator_traits<_NodeAlloc>;

  public:
    using allocator_type = __alloc_rebind<_NodeAlloc, _Val>;

    allocator_type get_allocator() const noexcept {
      do {
        if (std::__is_constant_evaluated())
          if (__builtin_expect(!bool(!this->empty()), false))
            std::__glibcxx_assert_fail();
      } while (false);
      return allocator_type(_M_alloc._M_alloc);
    }

    explicit operator bool() const noexcept { return _M_ptr != nullptr; }

    [[nodiscard]] bool empty() const noexcept { return _M_ptr == nullptr; }

  protected:
    constexpr _Node_handle_common() noexcept : _M_ptr() {}

    ~_Node_handle_common() {
      if (!empty())
        _M_reset();
    }

    _Node_handle_common(_Node_handle_common &&__nh) noexcept
        : _M_ptr(__nh._M_ptr) {
      if (_M_ptr)
        _M_move(std::move(__nh));
    }

    _Node_handle_common &operator=(_Node_handle_common &&__nh) noexcept {
      if (empty()) {
        if (!__nh.empty())
          _M_move(std::move(__nh));
      } else if (__nh.empty())
        _M_reset();
      else {

        _AllocTraits::destroy(*_M_alloc, _M_ptr->_M_valptr());
        _AllocTraits::deallocate(*_M_alloc, _M_ptr, 1);

        _M_alloc = __nh._M_alloc.release();
        _M_ptr = __nh._M_ptr;
        __nh._M_ptr = nullptr;
      }
      return *this;
    }

    _Node_handle_common(typename _AllocTraits::pointer __ptr,
                        const _NodeAlloc &__alloc)
        : _M_ptr(__ptr), _M_alloc(__alloc) {
      do {
        if (std::__is_constant_evaluated())
          if (__builtin_expect(!bool(__ptr != nullptr), false))
            std::__glibcxx_assert_fail();
      } while (false);
    }

    void _M_swap(_Node_handle_common &__nh) noexcept {
      if (empty()) {
        if (!__nh.empty())
          _M_move(std::move(__nh));
      } else if (__nh.empty())
        __nh._M_move(std::move(*this));
      else {
        using std::swap;
        swap(_M_ptr, __nh._M_ptr);
        _M_alloc.swap(__nh._M_alloc);
      }
    }

  private:
    void _M_move(_Node_handle_common &&__nh) noexcept {
      ::new (std::__addressof(_M_alloc)) _NodeAlloc(__nh._M_alloc.release());
      _M_ptr = __nh._M_ptr;
      __nh._M_ptr = nullptr;
    }

    void _M_reset() noexcept {
      _NodeAlloc __alloc = _M_alloc.release();
      _AllocTraits::destroy(__alloc, _M_ptr->_M_valptr());
      _AllocTraits::deallocate(__alloc, _M_ptr, 1);
      _M_ptr = nullptr;
    }

    void release() noexcept {
      _M_alloc.release();
      _M_ptr = nullptr;
    }

  protected:
    typename _AllocTraits::pointer _M_ptr;

  private:
    union _Optional_alloc {
      _Optional_alloc() {}
      ~_Optional_alloc() {}

      _Optional_alloc(_Optional_alloc &&) = delete;
      _Optional_alloc &operator=(_Optional_alloc &&) = delete;

      _Optional_alloc(const _NodeAlloc &__alloc) noexcept : _M_alloc(__alloc) {}

      void operator=(_NodeAlloc &&__alloc) noexcept {
        using _ATr = _AllocTraits;
        if constexpr (_ATr::propagate_on_container_move_assignment::value)
          _M_alloc = std::move(__alloc);
        else if constexpr (!_AllocTraits::is_always_equal::value)
          do {
            if (std::__is_constant_evaluated())
              if (__builtin_expect(!bool(_M_alloc == __alloc), false))
                std::__glibcxx_assert_fail();
          } while (false);
      }

      void swap(_Optional_alloc &__other) noexcept {
        using std::swap;
        if constexpr (_AllocTraits::propagate_on_container_swap::value)
          swap(_M_alloc, __other._M_alloc);
        else if constexpr (!_AllocTraits::is_always_equal::value)
          do {
            if (std::__is_constant_evaluated())
              if (__builtin_expect(!bool(_M_alloc == __other._M_alloc), false))
                std::__glibcxx_assert_fail();
          } while (false);
      }

      _NodeAlloc &operator*() noexcept { return _M_alloc; }

      _NodeAlloc release() noexcept {
        _NodeAlloc __tmp = std::move(_M_alloc);
        _M_alloc.~_NodeAlloc();
        return __tmp;
      }

      [[__no_unique_address__]] _NodeAlloc _M_alloc;
    };

    [[__no_unique_address__]] _Optional_alloc _M_alloc;

    template <typename _Key2, typename _Value2, typename _KeyOfValue,
              typename _Compare, typename _ValueAlloc>
    friend class _Rb_tree;

    template <typename _Key2, typename _Value2, typename _ValueAlloc,
              typename _ExtractKey, typename _Equal, typename _Hash,
              typename _RangeHash, typename _Unused, typename _RehashPolicy,
              typename _Traits>
    friend class _Hashtable;
  };

  template <typename _Key, typename _Value, typename _NodeAlloc>
  class _Node_handle : public _Node_handle_common<_Value, _NodeAlloc> {
  public:
    constexpr _Node_handle() noexcept = default;
    ~_Node_handle() = default;
    _Node_handle(_Node_handle &&) noexcept = default;

    _Node_handle &operator=(_Node_handle &&) noexcept = default;

    using key_type = _Key;
    using mapped_type = typename _Value::second_type;

    key_type &key() const noexcept {
      do {
        if (std::__is_constant_evaluated())
          if (__builtin_expect(!bool(!this->empty()), false))
            std::__glibcxx_assert_fail();
      } while (false);
      return *_M_pkey;
    }

    mapped_type &mapped() const noexcept {
      do {
        if (std::__is_constant_evaluated())
          if (__builtin_expect(!bool(!this->empty()), false))
            std::__glibcxx_assert_fail();
      } while (false);
      return *_M_pmapped;
    }

    void swap(_Node_handle &__nh) noexcept {
      this->_M_swap(__nh);
      using std::swap;
      swap(_M_pkey, __nh._M_pkey);
      swap(_M_pmapped, __nh._M_pmapped);
    }

    friend void swap(_Node_handle &__x,
                     _Node_handle &__y) noexcept(noexcept(__x.swap(__y))) {
      __x.swap(__y);
    }

  private:
    using _AllocTraits = allocator_traits<_NodeAlloc>;

    _Node_handle(typename _AllocTraits::pointer __ptr,
                 const _NodeAlloc &__alloc)
        : _Node_handle_common<_Value, _NodeAlloc>(__ptr, __alloc) {
      if (__ptr) {
        auto &__key = const_cast<_Key &>(__ptr->_M_valptr()->first);
        _M_pkey = _S_pointer_to(__key);
        _M_pmapped = _S_pointer_to(__ptr->_M_valptr()->second);
      } else {
        _M_pkey = nullptr;
        _M_pmapped = nullptr;
      }
    }

    template <typename _Tp>
    using __pointer =
        __ptr_rebind<typename _AllocTraits::pointer, remove_reference_t<_Tp>>;

    __pointer<_Key> _M_pkey = nullptr;
    __pointer<typename _Value::second_type> _M_pmapped = nullptr;

    template <typename _Tp> __pointer<_Tp> _S_pointer_to(_Tp &__obj) {
      return pointer_traits<__pointer<_Tp>>::pointer_to(__obj);
    }

    const key_type &_M_key() const noexcept { return key(); }

    template <typename _Key2, typename _Value2, typename _KeyOfValue,
              typename _Compare, typename _ValueAlloc>
    friend class _Rb_tree;

    template <typename _Key2, typename _Value2, typename _ValueAlloc,
              typename _ExtractKey, typename _Equal, typename _Hash,
              typename _RangeHash, typename _Unused, typename _RehashPolicy,
              typename _Traits>
    friend class _Hashtable;
  };

  template <typename _Value, typename _NodeAlloc>
  class _Node_handle<_Value, _Value, _NodeAlloc>
      : public _Node_handle_common<_Value, _NodeAlloc> {
  public:
    constexpr _Node_handle() noexcept = default;
    ~_Node_handle() = default;
    _Node_handle(_Node_handle &&) noexcept = default;

    _Node_handle &operator=(_Node_handle &&) noexcept = default;

    using value_type = _Value;

    value_type &value() const noexcept {
      do {
        if (std::__is_constant_evaluated())
          if (__builtin_expect(!bool(!this->empty()), false))
            std::__glibcxx_assert_fail();
      } while (false);
      return *this->_M_ptr->_M_valptr();
    }

    void swap(_Node_handle &__nh) noexcept { this->_M_swap(__nh); }

    friend void swap(_Node_handle &__x,
                     _Node_handle &__y) noexcept(noexcept(__x.swap(__y))) {
      __x.swap(__y);
    }

  private:
    using _AllocTraits = allocator_traits<_NodeAlloc>;

    _Node_handle(typename _AllocTraits::pointer __ptr,
                 const _NodeAlloc &__alloc)
        : _Node_handle_common<_Value, _NodeAlloc>(__ptr, __alloc) {}

    const value_type &_M_key() const noexcept { return value(); }

    template <typename _Key, typename _Val, typename _KeyOfValue,
              typename _Compare, typename _Alloc>
    friend class _Rb_tree;

    template <typename _Key2, typename _Value2, typename _ValueAlloc,
              typename _ExtractKey, typename _Equal, typename _Hash,
              typename _RangeHash, typename _Unused, typename _RehashPolicy,
              typename _Traits>
    friend class _Hashtable;
  };

  template <typename _Iterator, typename _NodeHandle>
  struct _Node_insert_return {
    _Iterator position = _Iterator();
    bool inserted = false;
    _NodeHandle node;
  };

} // namespace std

namespace std __attribute__((__visibility__("default"))) {

  template <typename _Tp, typename _Hash>
  using __cache_default =
      __not_<__and_<__is_fast_hash<_Hash>,

                    __is_nothrow_invocable<const _Hash &, const _Tp &>>>;

  template <typename _Equal, typename _Hash, typename _Allocator>
  using _Hashtable_enable_default_ctor = _Enable_default_constructor<
      __and_<is_default_constructible<_Equal>, is_default_constructible<_Hash>,
             is_default_constructible<_Allocator>>{},
      __detail::_Hash_node_base>;
  template <typename _Key, typename _Value, typename _Alloc,
            typename _ExtractKey, typename _Equal, typename _Hash,
            typename _RangeHash, typename _Unused, typename _RehashPolicy,
            typename _Traits>
  class _Hashtable
      : public __detail::_Hashtable_base<_Key, _Value, _ExtractKey, _Equal,
                                         _Hash, _RangeHash, _Unused, _Traits>,
        public __detail::_Map_base<_Key, _Value, _Alloc, _ExtractKey, _Equal,
                                   _Hash, _RangeHash, _Unused, _RehashPolicy,
                                   _Traits>,
        public __detail::_Insert<_Key, _Value, _Alloc, _ExtractKey, _Equal,
                                 _Hash, _RangeHash, _Unused, _RehashPolicy,
                                 _Traits>,
        public __detail::_Rehash_base<_Key, _Value, _Alloc, _ExtractKey, _Equal,
                                      _Hash, _RangeHash, _Unused, _RehashPolicy,
                                      _Traits>,
        public __detail::_Equality<_Key, _Value, _Alloc, _ExtractKey, _Equal,
                                   _Hash, _RangeHash, _Unused, _RehashPolicy,
                                   _Traits>,
        private __detail::_Hashtable_alloc<__alloc_rebind<
            _Alloc,
            __detail::_Hash_node<_Value, _Traits::__hash_cached::value>>>,
        private _Hashtable_enable_default_ctor<_Equal, _Hash, _Alloc> {
    static_assert(
        is_same<typename remove_cv<_Value>::type, _Value>::value,
        "unordered container must have a non-const, non-volatile value_type");

    static_assert(
        is_same<typename _Alloc::value_type, _Value>{},
        "unordered container must have the same value_type as its allocator");

    using __traits_type = _Traits;
    using __hash_cached = typename __traits_type::__hash_cached;
    using __constant_iterators = typename __traits_type::__constant_iterators;
    using __node_type = __detail::_Hash_node<_Value, __hash_cached::value>;
    using __node_alloc_type = __alloc_rebind<_Alloc, __node_type>;

    using __hashtable_alloc = __detail::_Hashtable_alloc<__node_alloc_type>;

    using __node_value_type =
        __detail::_Hash_node_value<_Value, __hash_cached::value>;
    using __node_ptr = typename __hashtable_alloc::__node_ptr;
    using __value_alloc_traits =
        typename __hashtable_alloc::__value_alloc_traits;
    using __node_alloc_traits = typename __hashtable_alloc::__node_alloc_traits;
    using __node_base = typename __hashtable_alloc::__node_base;
    using __node_base_ptr = typename __hashtable_alloc::__node_base_ptr;
    using __buckets_ptr = typename __hashtable_alloc::__buckets_ptr;

    using __insert_base =
        __detail::_Insert<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash,
                          _RangeHash, _Unused, _RehashPolicy, _Traits>;
    using __enable_default_ctor =
        _Hashtable_enable_default_ctor<_Equal, _Hash, _Alloc>;
    using __rehash_guard_t = __detail::_RehashStateGuard<_RehashPolicy>;

  public:
    typedef _Key key_type;
    typedef _Value value_type;
    typedef _Alloc allocator_type;
    typedef _Equal key_equal;

    typedef typename __value_alloc_traits::pointer pointer;
    typedef typename __value_alloc_traits::const_pointer const_pointer;
    typedef value_type &reference;
    typedef const value_type &const_reference;

    using iterator = typename __insert_base::iterator;

    using const_iterator = typename __insert_base::const_iterator;

    using local_iterator = __detail::_Local_iterator<
        key_type, _Value, _ExtractKey, _Hash, _RangeHash, _Unused,
        __constant_iterators::value, __hash_cached::value>;

    using const_local_iterator = __detail::_Local_const_iterator<
        key_type, _Value, _ExtractKey, _Hash, _RangeHash, _Unused,
        __constant_iterators::value, __hash_cached::value>;

  private:
    using __rehash_type = _RehashPolicy;

    using __unique_keys = typename __traits_type::__unique_keys;

    using __hashtable_base =
        __detail::_Hashtable_base<_Key, _Value, _ExtractKey, _Equal, _Hash,
                                  _RangeHash, _Unused, _Traits>;

    using __hash_code_base = typename __hashtable_base::__hash_code_base;
    using __hash_code = typename __hashtable_base::__hash_code;
    using __ireturn_type = typename __insert_base::__ireturn_type;

    using __map_base =
        __detail::_Map_base<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash,
                            _RangeHash, _Unused, _RehashPolicy, _Traits>;

    using __rehash_base =
        __detail::_Rehash_base<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash,
                               _RangeHash, _Unused, _RehashPolicy, _Traits>;

    using __eq_base =
        __detail::_Equality<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash,
                            _RangeHash, _Unused, _RehashPolicy, _Traits>;

    using __reuse_or_alloc_node_gen_t =
        __detail::_ReuseOrAllocNode<__node_alloc_type>;
    using __alloc_node_gen_t = __detail::_AllocNode<__node_alloc_type>;
    using __node_builder_t = __detail::_NodeBuilder<_ExtractKey>;

    struct _Scoped_node {

      _Scoped_node(__node_ptr __n, __hashtable_alloc *__h)
          : _M_h(__h), _M_node(__n) {}

      template <typename... _Args>
      _Scoped_node(__hashtable_alloc *__h, _Args &&...__args)
          : _M_h(__h),
            _M_node(__h->_M_allocate_node(std::forward<_Args>(__args)...)) {}

      ~_Scoped_node() {
        if (_M_node)
          _M_h->_M_deallocate_node(_M_node);
      };

      _Scoped_node(const _Scoped_node &) = delete;
      _Scoped_node &operator=(const _Scoped_node &) = delete;

      __hashtable_alloc *_M_h;
      __node_ptr _M_node;
    };

    template <typename _Ht>
    static constexpr __conditional_t<std::is_lvalue_reference<_Ht>::value,
                                     const value_type &, value_type &&>
    __fwd_value_for(value_type &__val) noexcept {
      return std::move(__val);
    }

    struct __hash_code_base_access : __hash_code_base {
      using __hash_code_base::_M_bucket_index;
    };

    static_assert(is_nothrow_default_constructible<_RangeHash>::value,
                  "Functor used to map hash code to bucket index"
                  " must be nothrow default constructible");
    static_assert(noexcept(std::declval<const _RangeHash &>()((std::size_t)0,
                                                              (std::size_t)0)),
                  "Functor used to map hash code to bucket index must be"
                  " noexcept");

    static_assert(is_nothrow_default_constructible<_ExtractKey>::value,
                  "_ExtractKey must be nothrow default constructible");
    static_assert(
        noexcept(std::declval<const _ExtractKey &>()(std::declval<_Value>())),
        "_ExtractKey functor must be noexcept invocable");

    template <typename _Keya, typename _Valuea, typename _Alloca,
              typename _ExtractKeya, typename _Equala, typename _Hasha,
              typename _RangeHasha, typename _Unuseda, typename _RehashPolicya,
              typename _Traitsa, bool _Unique_keysa>
    friend struct __detail::_Map_base;

    template <typename _Keya, typename _Valuea, typename _Alloca,
              typename _ExtractKeya, typename _Equala, typename _Hasha,
              typename _RangeHasha, typename _Unuseda, typename _RehashPolicya,
              typename _Traitsa>
    friend struct __detail::_Insert_base;

    template <typename _Keya, typename _Valuea, typename _Alloca,
              typename _ExtractKeya, typename _Equala, typename _Hasha,
              typename _RangeHasha, typename _Unuseda, typename _RehashPolicya,
              typename _Traitsa, bool _Constant_iteratorsa>
    friend struct __detail::_Insert;

    template <typename _Keya, typename _Valuea, typename _Alloca,
              typename _ExtractKeya, typename _Equala, typename _Hasha,
              typename _RangeHasha, typename _Unuseda, typename _RehashPolicya,
              typename _Traitsa, bool _Unique_keysa>
    friend struct __detail::_Equality;

  public:
    using size_type = typename __hashtable_base::size_type;
    using difference_type = typename __hashtable_base::difference_type;

    using node_type = _Node_handle<_Key, _Value, __node_alloc_type>;
    using insert_return_type = _Node_insert_return<iterator, node_type>;

  private:
    __buckets_ptr _M_buckets = &_M_single_bucket;
    size_type _M_bucket_count = 1;
    __node_base _M_before_begin;
    size_type _M_element_count = 0;
    _RehashPolicy _M_rehash_policy;

    __node_base_ptr _M_single_bucket = nullptr;

    void _M_update_bbegin() {
      if (auto __begin = _M_begin())
        _M_buckets[_M_bucket_index(*__begin)] = &_M_before_begin;
    }

    void _M_update_bbegin(__node_ptr __n) {
      _M_before_begin._M_nxt = __n;
      _M_update_bbegin();
    }

    bool _M_uses_single_bucket(__buckets_ptr __bkts) const {
      return __builtin_expect(__bkts == &_M_single_bucket, false);
    }

    bool _M_uses_single_bucket() const {
      return _M_uses_single_bucket(_M_buckets);
    }

    static constexpr size_t __small_size_threshold() noexcept {
      return __detail::_Hashtable_hash_traits<_Hash>::__small_size_threshold();
    }

    __hashtable_alloc &_M_base_alloc() { return *this; }

    __buckets_ptr _M_allocate_buckets(size_type __bkt_count) {
      if (__builtin_expect(__bkt_count == 1, false)) {
        _M_single_bucket = nullptr;
        return &_M_single_bucket;
      }

      return __hashtable_alloc::_M_allocate_buckets(__bkt_count);
    }

    void _M_deallocate_buckets(__buckets_ptr __bkts, size_type __bkt_count) {
      if (_M_uses_single_bucket(__bkts))
        return;

      __hashtable_alloc::_M_deallocate_buckets(__bkts, __bkt_count);
    }

    void _M_deallocate_buckets() {
      _M_deallocate_buckets(_M_buckets, _M_bucket_count);
    }

    __node_ptr _M_bucket_begin(size_type __bkt) const {
      __node_base_ptr __n = _M_buckets[__bkt];
      return __n ? static_cast<__node_ptr>(__n->_M_nxt) : nullptr;
    }

    __node_ptr _M_begin() const {
      return static_cast<__node_ptr>(_M_before_begin._M_nxt);
    }

    template <typename _Ht> void _M_assign_elements(_Ht &&);

    template <typename _Ht, typename _NodeGenerator>
    void _M_assign(_Ht &&, const _NodeGenerator &);

    void _M_move_assign(_Hashtable &&, true_type);

    void _M_move_assign(_Hashtable &&, false_type);

    void _M_reset() noexcept;

    _Hashtable(const _Hash &__h, const _Equal &__eq, const allocator_type &__a)
        : __hashtable_base(__h, __eq),
          __hashtable_alloc(__node_alloc_type(__a)),
          __enable_default_ctor(_Enable_default_constructor_tag{}) {}

    template <bool _No_realloc = true> static constexpr bool _S_nothrow_move() {

      if constexpr (_No_realloc)
        if constexpr (is_nothrow_copy_constructible<_Hash>())
          return is_nothrow_copy_constructible<_Equal>();
      return false;
    }

    _Hashtable(_Hashtable &&__ht, __node_alloc_type &&__a,
               true_type) noexcept(_S_nothrow_move());

    _Hashtable(_Hashtable &&, __node_alloc_type &&, false_type);

    template <typename _InputIterator>
    _Hashtable(_InputIterator __first, _InputIterator __last,
               size_type __bkt_count_hint, const _Hash &, const _Equal &,
               const allocator_type &, true_type __uks);

    template <typename _InputIterator>
    _Hashtable(_InputIterator __first, _InputIterator __last,
               size_type __bkt_count_hint, const _Hash &, const _Equal &,
               const allocator_type &, false_type __uks);

  public:
    _Hashtable() = default;

    _Hashtable(const _Hashtable &);

    _Hashtable(const _Hashtable &, const allocator_type &);

    explicit _Hashtable(size_type __bkt_count_hint, const _Hash &__hf = _Hash(),
                        const key_equal &__eql = key_equal(),
                        const allocator_type &__a = allocator_type());

    _Hashtable(_Hashtable &&__ht) noexcept(_S_nothrow_move())
        : _Hashtable(std::move(__ht), std::move(__ht._M_node_allocator()),
                     true_type{}) {}

    _Hashtable(_Hashtable &&__ht, const allocator_type &__a) noexcept(
        _S_nothrow_move<__node_alloc_traits::_S_always_equal()>())
        : _Hashtable(std::move(__ht), __node_alloc_type(__a),
                     typename __node_alloc_traits::is_always_equal{}) {}

    explicit _Hashtable(const allocator_type &__a)
        : __hashtable_alloc(__node_alloc_type(__a)),
          __enable_default_ctor(_Enable_default_constructor_tag{}) {}

    template <typename _InputIterator>
    _Hashtable(_InputIterator __f, _InputIterator __l,
               size_type __bkt_count_hint = 0, const _Hash &__hf = _Hash(),
               const key_equal &__eql = key_equal(),
               const allocator_type &__a = allocator_type())
        : _Hashtable(__f, __l, __bkt_count_hint, __hf, __eql, __a,
                     __unique_keys{}) {}

    _Hashtable(initializer_list<value_type> __l, size_type __bkt_count_hint = 0,
               const _Hash &__hf = _Hash(),
               const key_equal &__eql = key_equal(),
               const allocator_type &__a = allocator_type())
        : _Hashtable(__l.begin(), __l.end(), __bkt_count_hint, __hf, __eql, __a,
                     __unique_keys{}) {}

    _Hashtable &operator=(const _Hashtable &__ht);

    _Hashtable &operator=(_Hashtable &&__ht) noexcept(
        __node_alloc_traits::_S_nothrow_move() &&
        is_nothrow_move_assignable<_Hash>::value &&
        is_nothrow_move_assignable<_Equal>::value) {
      constexpr bool __move_storage =
          __node_alloc_traits::_S_propagate_on_move_assign() ||
          __node_alloc_traits::_S_always_equal();
      _M_move_assign(std::move(__ht), __bool_constant<__move_storage>());
      return *this;
    }

    _Hashtable &operator=(initializer_list<value_type> __l) {
      __reuse_or_alloc_node_gen_t __roan(_M_begin(), *this);
      _M_before_begin._M_nxt = nullptr;
      clear();

      auto __l_bkt_count = _M_rehash_policy._M_bkt_for_elements(__l.size());

      if (_M_bucket_count < __l_bkt_count)
        rehash(__l_bkt_count);

      this->_M_insert_range(__l.begin(), __l.end(), __roan, __unique_keys{});
      return *this;
    }

    ~_Hashtable() noexcept;

    void
    swap(_Hashtable &) noexcept(__and_<__is_nothrow_swappable<_Hash>,
                                       __is_nothrow_swappable<_Equal>>::value);

    iterator begin() noexcept { return iterator(_M_begin()); }

    const_iterator begin() const noexcept { return const_iterator(_M_begin()); }

    iterator end() noexcept { return iterator(nullptr); }

    const_iterator end() const noexcept { return const_iterator(nullptr); }

    const_iterator cbegin() const noexcept {
      return const_iterator(_M_begin());
    }

    const_iterator cend() const noexcept { return const_iterator(nullptr); }

    size_type size() const noexcept { return _M_element_count; }

    [[__nodiscard__]] bool empty() const noexcept { return size() == 0; }

    allocator_type get_allocator() const noexcept {
      return allocator_type(this->_M_node_allocator());
    }

    size_type max_size() const noexcept {
      return __node_alloc_traits::max_size(this->_M_node_allocator());
    }

    key_equal key_eq() const { return this->_M_eq(); }

    size_type bucket_count() const noexcept { return _M_bucket_count; }

    size_type max_bucket_count() const noexcept { return max_size(); }

    size_type bucket_size(size_type __bkt) const {
      return std::distance(begin(__bkt), end(__bkt));
    }

    size_type bucket(const key_type &__k) const {
      return _M_bucket_index(this->_M_hash_code(__k));
    }

    local_iterator begin(size_type __bkt) {
      return local_iterator(*this, _M_bucket_begin(__bkt), __bkt,
                            _M_bucket_count);
    }

    local_iterator end(size_type __bkt) {
      return local_iterator(*this, nullptr, __bkt, _M_bucket_count);
    }

    const_local_iterator begin(size_type __bkt) const {
      return const_local_iterator(*this, _M_bucket_begin(__bkt), __bkt,
                                  _M_bucket_count);
    }

    const_local_iterator end(size_type __bkt) const {
      return const_local_iterator(*this, nullptr, __bkt, _M_bucket_count);
    }

    const_local_iterator cbegin(size_type __bkt) const {
      return const_local_iterator(*this, _M_bucket_begin(__bkt), __bkt,
                                  _M_bucket_count);
    }

    const_local_iterator cend(size_type __bkt) const {
      return const_local_iterator(*this, nullptr, __bkt, _M_bucket_count);
    }

    float load_factor() const noexcept {
      return static_cast<float>(size()) / static_cast<float>(bucket_count());
    }

    const _RehashPolicy &__rehash_policy() const { return _M_rehash_policy; }

    void __rehash_policy(const _RehashPolicy &__pol) {
      _M_rehash_policy = __pol;
    }

    iterator find(const key_type &__k);

    const_iterator find(const key_type &__k) const;

    size_type count(const key_type &__k) const;

    std::pair<iterator, iterator> equal_range(const key_type &__k);

    std::pair<const_iterator, const_iterator>
    equal_range(const key_type &__k) const;

    template <typename _Kt, typename = __has_is_transparent_t<_Hash, _Kt>,
              typename = __has_is_transparent_t<_Equal, _Kt>>
    iterator _M_find_tr(const _Kt &__k);

    template <typename _Kt, typename = __has_is_transparent_t<_Hash, _Kt>,
              typename = __has_is_transparent_t<_Equal, _Kt>>
    const_iterator _M_find_tr(const _Kt &__k) const;

    template <typename _Kt, typename = __has_is_transparent_t<_Hash, _Kt>,
              typename = __has_is_transparent_t<_Equal, _Kt>>
    size_type _M_count_tr(const _Kt &__k) const;

    template <typename _Kt, typename = __has_is_transparent_t<_Hash, _Kt>,
              typename = __has_is_transparent_t<_Equal, _Kt>>
    pair<iterator, iterator> _M_equal_range_tr(const _Kt &__k);

    template <typename _Kt, typename = __has_is_transparent_t<_Hash, _Kt>,
              typename = __has_is_transparent_t<_Equal, _Kt>>
    pair<const_iterator, const_iterator>
    _M_equal_range_tr(const _Kt &__k) const;

  private:
    size_type _M_bucket_index(const __node_value_type &__n) const noexcept {
      return __hash_code_base::_M_bucket_index(__n, _M_bucket_count);
    }

    size_type _M_bucket_index(__hash_code __c) const {
      return __hash_code_base::_M_bucket_index(__c, _M_bucket_count);
    }

    __node_base_ptr _M_find_before_node(const key_type &);

    __node_base_ptr _M_find_before_node(size_type, const key_type &,
                                        __hash_code) const;

    template <typename _Kt>
    __node_base_ptr _M_find_before_node_tr(size_type, const _Kt &,
                                           __hash_code) const;

    __node_ptr _M_find_node(size_type __bkt, const key_type &__key,
                            __hash_code __c) const {
      __node_base_ptr __before_n = _M_find_before_node(__bkt, __key, __c);
      if (__before_n)
        return static_cast<__node_ptr>(__before_n->_M_nxt);
      return nullptr;
    }

    template <typename _Kt>
    __node_ptr _M_find_node_tr(size_type __bkt, const _Kt &__key,
                               __hash_code __c) const {
      auto __before_n = _M_find_before_node_tr(__bkt, __key, __c);
      if (__before_n)
        return static_cast<__node_ptr>(__before_n->_M_nxt);
      return nullptr;
    }

    void _M_insert_bucket_begin(size_type __bkt, __node_ptr __node) {
      if (_M_buckets[__bkt]) {

        __node->_M_nxt = _M_buckets[__bkt]->_M_nxt;
        _M_buckets[__bkt]->_M_nxt = __node;
      } else {

        __node->_M_nxt = _M_before_begin._M_nxt;
        _M_before_begin._M_nxt = __node;

        if (__node->_M_nxt)

          _M_buckets[_M_bucket_index(*__node->_M_next())] = __node;

        _M_buckets[__bkt] = &_M_before_begin;
      }
    }

    void _M_remove_bucket_begin(size_type __bkt, __node_ptr __next_n,
                                size_type __next_bkt) {
      if (!__next_n)
        _M_buckets[__bkt] = nullptr;
      else if (__next_bkt != __bkt) {
        _M_buckets[__next_bkt] = _M_buckets[__bkt];
        _M_buckets[__bkt] = nullptr;
      }
    }

    __node_base_ptr _M_get_previous_node(size_type __bkt, __node_ptr __n);

    pair<__node_ptr, __hash_code>
    _M_compute_hash_code(__node_ptr __hint, const key_type &__k) const;

    iterator _M_insert_unique_node(size_type __bkt, __hash_code, __node_ptr __n,
                                   size_type __n_elt = 1);

    iterator _M_insert_multi_node(__node_ptr __hint, __hash_code __code,
                                  __node_ptr __n);

    template <typename... _Args>
    std::pair<iterator, bool> _M_emplace(true_type __uks, _Args &&...__args);

    template <typename... _Args>
    iterator _M_emplace(false_type __uks, _Args &&...__args) {
      return _M_emplace(cend(), __uks, std::forward<_Args>(__args)...);
    }

    template <typename... _Args>
    iterator _M_emplace(const_iterator, true_type __uks, _Args &&...__args) {
      return _M_emplace(__uks, std::forward<_Args>(__args)...).first;
    }

    template <typename... _Args>
    iterator _M_emplace(const_iterator, false_type __uks, _Args &&...__args);

    template <typename _Kt, typename _Arg, typename _NodeGenerator>
    std::pair<iterator, bool> _M_insert_unique(_Kt &&, _Arg &&,
                                               const _NodeGenerator &);

    template <typename _Kt>
    static __conditional_t<
        __and_<__is_nothrow_invocable<_Hash &, const key_type &>,
               __not_<__is_nothrow_invocable<_Hash &, _Kt>>>::value,
        key_type, _Kt &&>
    _S_forward_key(_Kt &&__k) {
      return std::forward<_Kt>(__k);
    }

    static const key_type &_S_forward_key(const key_type &__k) { return __k; }

    static key_type &&_S_forward_key(key_type &&__k) { return std::move(__k); }

    template <typename _Arg, typename _NodeGenerator>
    std::pair<iterator, bool>
    _M_insert_unique_aux(_Arg &&__arg, const _NodeGenerator &__node_gen) {
      return _M_insert_unique(
          _S_forward_key(_ExtractKey{}(std::forward<_Arg>(__arg))),
          std::forward<_Arg>(__arg), __node_gen);
    }

    template <typename _Arg, typename _NodeGenerator>
    std::pair<iterator, bool>
    _M_insert(_Arg &&__arg, const _NodeGenerator &__node_gen, true_type) {
      using __to_value = __detail::_ConvertToValueType<_ExtractKey, value_type>;
      return _M_insert_unique_aux(__to_value{}(std::forward<_Arg>(__arg)),
                                  __node_gen);
    }

    template <typename _Arg, typename _NodeGenerator>
    iterator _M_insert(_Arg &&__arg, const _NodeGenerator &__node_gen,
                       false_type __uks) {
      using __to_value = __detail::_ConvertToValueType<_ExtractKey, value_type>;
      return _M_insert(cend(), __to_value{}(std::forward<_Arg>(__arg)),
                       __node_gen, __uks);
    }

    template <typename _Arg, typename _NodeGenerator>
    iterator _M_insert(const_iterator, _Arg &&__arg,
                       const _NodeGenerator &__node_gen, true_type __uks) {
      return _M_insert(std::forward<_Arg>(__arg), __node_gen, __uks).first;
    }

    template <typename _Arg, typename _NodeGenerator>
    iterator _M_insert(const_iterator, _Arg &&, const _NodeGenerator &,
                       false_type __uks);

    size_type _M_erase(true_type __uks, const key_type &);

    size_type _M_erase(false_type __uks, const key_type &);

    iterator _M_erase(size_type __bkt, __node_base_ptr __prev_n,
                      __node_ptr __n);

  public:
    template <typename... _Args> __ireturn_type emplace(_Args &&...__args) {
      return _M_emplace(__unique_keys{}, std::forward<_Args>(__args)...);
    }

    template <typename... _Args>
    iterator emplace_hint(const_iterator __hint, _Args &&...__args) {
      return _M_emplace(__hint, __unique_keys{},
                        std::forward<_Args>(__args)...);
    }

    iterator erase(const_iterator);

    iterator erase(iterator __it) { return erase(const_iterator(__it)); }

    size_type erase(const key_type &__k) {
      return _M_erase(__unique_keys{}, __k);
    }

    iterator erase(const_iterator, const_iterator);

    void clear() noexcept;

    void rehash(size_type __bkt_count);

    insert_return_type _M_reinsert_node(node_type &&__nh) {
      insert_return_type __ret;
      if (__nh.empty())
        __ret.position = end();
      else {
        do {
          if (std::__is_constant_evaluated())
            if (__builtin_expect(!bool(get_allocator() == __nh.get_allocator()),
                                 false))
              std::__glibcxx_assert_fail();
        } while (false);

        __node_ptr __n = nullptr;
        const key_type &__k = __nh._M_key();
        const size_type __size = size();
        if (__size <= __small_size_threshold()) {
          for (__n = _M_begin(); __n; __n = __n->_M_next())
            if (this->_M_key_equals(__k, *__n))
              break;
        }

        __hash_code __code;
        size_type __bkt;
        if (!__n) {
          __code = this->_M_hash_code(__k);
          __bkt = _M_bucket_index(__code);
          if (__size > __small_size_threshold())
            __n = _M_find_node(__bkt, __k, __code);
        }

        if (__n) {
          __ret.node = std::move(__nh);
          __ret.position = iterator(__n);
          __ret.inserted = false;
        } else {
          __ret.position = _M_insert_unique_node(__bkt, __code, __nh._M_ptr);
          __nh.release();
          __ret.inserted = true;
        }
      }
      return __ret;
    }

    iterator _M_reinsert_node_multi(const_iterator __hint, node_type &&__nh) {
      if (__nh.empty())
        return end();

      do {
        if (std::__is_constant_evaluated())
          if (__builtin_expect(!bool(get_allocator() == __nh.get_allocator()),
                               false))
            std::__glibcxx_assert_fail();
      } while (false);

      const key_type &__k = __nh._M_key();
      auto __code = this->_M_hash_code(__k);
      auto __ret = _M_insert_multi_node(__hint._M_cur, __code, __nh._M_ptr);
      __nh.release();
      return __ret;
    }

  private:
    node_type _M_extract_node(size_t __bkt, __node_base_ptr __prev_n) {
      __node_ptr __n = static_cast<__node_ptr>(__prev_n->_M_nxt);
      if (__prev_n == _M_buckets[__bkt])
        _M_remove_bucket_begin(__bkt, __n->_M_next(),
                               __n->_M_nxt ? _M_bucket_index(*__n->_M_next())
                                           : 0);
      else if (__n->_M_nxt) {
        size_type __next_bkt = _M_bucket_index(*__n->_M_next());
        if (__next_bkt != __bkt)
          _M_buckets[__next_bkt] = __prev_n;
      }

      __prev_n->_M_nxt = __n->_M_nxt;
      __n->_M_nxt = nullptr;
      --_M_element_count;
      return {__n, this->_M_node_allocator()};
    }

    template <typename _H2>
    __hash_code _M_src_hash_code(const _H2 &, const key_type &__k,
                                 const __node_value_type &__src_n) const {
      if constexpr (std::is_same_v<_H2, _Hash>)
        if constexpr (std::is_empty_v<_Hash>)
          return this->_M_hash_code(__src_n);

      return this->_M_hash_code(__k);
    }

  public:
    node_type extract(const_iterator __pos) {
      size_t __bkt = _M_bucket_index(*__pos._M_cur);
      return _M_extract_node(__bkt, _M_get_previous_node(__bkt, __pos._M_cur));
    }

    node_type extract(const _Key &__k) {
      node_type __nh;
      __hash_code __code = this->_M_hash_code(__k);
      std::size_t __bkt = _M_bucket_index(__code);
      if (__node_base_ptr __prev_node = _M_find_before_node(__bkt, __k, __code))
        __nh = _M_extract_node(__bkt, __prev_node);
      return __nh;
    }

    template <typename _Compatible_Hashtable>
    void _M_merge_unique(_Compatible_Hashtable &__src) {
      static_assert(
          is_same_v<typename _Compatible_Hashtable::node_type, node_type>,
          "Node types are compatible");
      do {
        if (std::__is_constant_evaluated())
          if (__builtin_expect(!bool(get_allocator() == __src.get_allocator()),
                               false))
            std::__glibcxx_assert_fail();
      } while (false);

      auto __n_elt = __src.size();
      for (auto __i = __src.cbegin(), __end = __src.cend(); __i != __end;) {
        auto __pos = __i++;
        const size_type __size = size();
        const key_type &__k = _ExtractKey{}(*__pos);
        if (__size <= __small_size_threshold()) {
          bool __found = false;
          for (auto __n = _M_begin(); __n; __n = __n->_M_next())
            if (this->_M_key_equals(__k, *__n)) {
              __found = true;
              break;
            }

          if (__found) {
            if (__n_elt != 1)
              --__n_elt;
            continue;
          }
        }

        __hash_code __code =
            _M_src_hash_code(__src.hash_function(), __k, *__pos._M_cur);
        size_type __bkt = _M_bucket_index(__code);
        if (__size <= __small_size_threshold() ||
            _M_find_node(__bkt, __k, __code) == nullptr) {
          auto __nh = __src.extract(__pos);
          _M_insert_unique_node(__bkt, __code, __nh._M_ptr, __n_elt);
          __nh.release();
          __n_elt = 1;
        } else if (__n_elt != 1)
          --__n_elt;
      }
    }

    template <typename _Compatible_Hashtable>
    void _M_merge_multi(_Compatible_Hashtable &__src) {
      static_assert(
          is_same_v<typename _Compatible_Hashtable::node_type, node_type>,
          "Node types are compatible");
      do {
        if (std::__is_constant_evaluated())
          if (__builtin_expect(!bool(get_allocator() == __src.get_allocator()),
                               false))
            std::__glibcxx_assert_fail();
      } while (false);

      __node_ptr __hint = nullptr;
      this->reserve(size() + __src.size());
      for (auto __i = __src.cbegin(), __end = __src.cend(); __i != __end;) {
        auto __pos = __i++;
        const key_type &__k = _ExtractKey{}(*__pos);
        __hash_code __code =
            _M_src_hash_code(__src.hash_function(), __k, *__pos._M_cur);
        auto __nh = __src.extract(__pos);
        __hint = _M_insert_multi_node(__hint, __code, __nh._M_ptr)._M_cur;
        __nh.release();
      }
    }

  private:
    void _M_rehash(size_type __bkt_count, true_type __uks);

    void _M_rehash(size_type __bkt_count, false_type __uks);
  };

  template <typename _Key, typename _Value, typename _Alloc,
            typename _ExtractKey, typename _Equal, typename _Hash,
            typename _RangeHash, typename _Unused, typename _RehashPolicy,
            typename _Traits>
  _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash, _RangeHash,
             _Unused, _RehashPolicy,
             _Traits>::_Hashtable(size_type __bkt_count_hint, const _Hash &__h,
                                  const _Equal &__eq, const allocator_type &__a)
      : _Hashtable(__h, __eq, __a) {
    auto __bkt_count = _M_rehash_policy._M_next_bkt(__bkt_count_hint);
    if (__bkt_count > _M_bucket_count) {
      _M_buckets = _M_allocate_buckets(__bkt_count);
      _M_bucket_count = __bkt_count;
    }
  }

  template <typename _Key, typename _Value, typename _Alloc,
            typename _ExtractKey, typename _Equal, typename _Hash,
            typename _RangeHash, typename _Unused, typename _RehashPolicy,
            typename _Traits>
  template <typename _InputIterator>
  _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash, _RangeHash,
             _Unused, _RehashPolicy,
             _Traits>::_Hashtable(_InputIterator __f, _InputIterator __l,
                                  size_type __bkt_count_hint, const _Hash &__h,
                                  const _Equal &__eq, const allocator_type &__a,
                                  true_type)
      : _Hashtable(__bkt_count_hint, __h, __eq, __a) {
    this->insert(__f, __l);
  }

  template <typename _Key, typename _Value, typename _Alloc,
            typename _ExtractKey, typename _Equal, typename _Hash,
            typename _RangeHash, typename _Unused, typename _RehashPolicy,
            typename _Traits>
  template <typename _InputIterator>
  _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash, _RangeHash,
             _Unused, _RehashPolicy,
             _Traits>::_Hashtable(_InputIterator __f, _InputIterator __l,
                                  size_type __bkt_count_hint, const _Hash &__h,
                                  const _Equal &__eq, const allocator_type &__a,
                                  false_type __uks)
      : _Hashtable(__h, __eq, __a) {
    auto __nb_elems = __detail::__distance_fw(__f, __l);
    auto __bkt_count = _M_rehash_policy._M_next_bkt(std::max(
        _M_rehash_policy._M_bkt_for_elements(__nb_elems), __bkt_count_hint));

    if (__bkt_count > _M_bucket_count) {
      _M_buckets = _M_allocate_buckets(__bkt_count);
      _M_bucket_count = __bkt_count;
    }

    __alloc_node_gen_t __node_gen(*this);
    for (; __f != __l; ++__f)
      _M_insert(*__f, __node_gen, __uks);
  }

  template <typename _Key, typename _Value, typename _Alloc,
            typename _ExtractKey, typename _Equal, typename _Hash,
            typename _RangeHash, typename _Unused, typename _RehashPolicy,
            typename _Traits>
  auto
  _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash, _RangeHash,
             _Unused, _RehashPolicy, _Traits>::operator=(const _Hashtable &__ht)
      -> _Hashtable & {
    if (&__ht == this)
      return *this;

    if (__node_alloc_traits::_S_propagate_on_copy_assign()) {
      auto &__this_alloc = this->_M_node_allocator();
      auto &__that_alloc = __ht._M_node_allocator();
      if (!__node_alloc_traits::_S_always_equal() &&
          __this_alloc != __that_alloc) {

        this->_M_deallocate_nodes(_M_begin());
        _M_before_begin._M_nxt = nullptr;
        _M_deallocate_buckets();
        _M_buckets = nullptr;
        std::__alloc_on_copy(__this_alloc, __that_alloc);
        __hashtable_base::operator=(__ht);
        _M_bucket_count = __ht._M_bucket_count;
        _M_element_count = __ht._M_element_count;
        _M_rehash_policy = __ht._M_rehash_policy;
        __alloc_node_gen_t __alloc_node_gen(*this);
        try {
          _M_assign(__ht, __alloc_node_gen);
        } catch (...) {

          _M_reset();
          throw;
        }
        return *this;
      }
      std::__alloc_on_copy(__this_alloc, __that_alloc);
    }

    _M_assign_elements(__ht);
    return *this;
  }

  template <typename _Key, typename _Value, typename _Alloc,
            typename _ExtractKey, typename _Equal, typename _Hash,
            typename _RangeHash, typename _Unused, typename _RehashPolicy,
            typename _Traits>
  template <typename _Ht>
  void _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash, _RangeHash,
                  _Unused, _RehashPolicy, _Traits>::_M_assign_elements(_Ht &&
                                                                       __ht) {
    __buckets_ptr __former_buckets = nullptr;
    std::size_t __former_bucket_count = _M_bucket_count;
    __rehash_guard_t __rehash_guard(_M_rehash_policy);

    if (_M_bucket_count != __ht._M_bucket_count) {
      __former_buckets = _M_buckets;
      _M_buckets = _M_allocate_buckets(__ht._M_bucket_count);
      _M_bucket_count = __ht._M_bucket_count;
    } else
      __builtin_memset(_M_buckets, 0,
                       _M_bucket_count * sizeof(__node_base_ptr));

    try {
      __hashtable_base::operator=(std::forward<_Ht>(__ht));
      _M_element_count = __ht._M_element_count;
      _M_rehash_policy = __ht._M_rehash_policy;
      __reuse_or_alloc_node_gen_t __roan(_M_begin(), *this);
      _M_before_begin._M_nxt = nullptr;
      _M_assign(std::forward<_Ht>(__ht), __roan);
      if (__former_buckets)
        _M_deallocate_buckets(__former_buckets, __former_bucket_count);
      __rehash_guard._M_guarded_obj = nullptr;
    } catch (...) {
      if (__former_buckets) {

        _M_deallocate_buckets();
        _M_buckets = __former_buckets;
        _M_bucket_count = __former_bucket_count;
      }
      __builtin_memset(_M_buckets, 0,
                       _M_bucket_count * sizeof(__node_base_ptr));
      throw;
    }
  }

  template <typename _Key, typename _Value, typename _Alloc,
            typename _ExtractKey, typename _Equal, typename _Hash,
            typename _RangeHash, typename _Unused, typename _RehashPolicy,
            typename _Traits>
  template <typename _Ht, typename _NodeGenerator>
  void _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash, _RangeHash,
                  _Unused, _RehashPolicy,
                  _Traits>::_M_assign(_Ht && __ht,
                                      const _NodeGenerator &__node_gen) {
    __buckets_ptr __buckets = nullptr;
    if (!_M_buckets)
      _M_buckets = __buckets = _M_allocate_buckets(_M_bucket_count);

    try {
      if (!__ht._M_before_begin._M_nxt)
        return;

      __node_ptr __ht_n = __ht._M_begin();
      __node_ptr __this_n = __node_gen(__fwd_value_for<_Ht>(__ht_n->_M_v()));
      this->_M_copy_code(*__this_n, *__ht_n);
      _M_update_bbegin(__this_n);

      __node_ptr __prev_n = __this_n;
      for (__ht_n = __ht_n->_M_next(); __ht_n; __ht_n = __ht_n->_M_next()) {
        __this_n = __node_gen(__fwd_value_for<_Ht>(__ht_n->_M_v()));
        __prev_n->_M_nxt = __this_n;
        this->_M_copy_code(*__this_n, *__ht_n);
        size_type __bkt = _M_bucket_index(*__this_n);
        if (!_M_buckets[__bkt])
          _M_buckets[__bkt] = __prev_n;
        __prev_n = __this_n;
      }
    } catch (...) {
      clear();
      if (__buckets)
        _M_deallocate_buckets();
      throw;
    }
  }

  template <typename _Key, typename _Value, typename _Alloc,
            typename _ExtractKey, typename _Equal, typename _Hash,
            typename _RangeHash, typename _Unused, typename _RehashPolicy,
            typename _Traits>
  void _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash, _RangeHash,
                  _Unused, _RehashPolicy, _Traits>::_M_reset() noexcept {
    _M_rehash_policy._M_reset();
    _M_bucket_count = 1;
    _M_single_bucket = nullptr;
    _M_buckets = &_M_single_bucket;
    _M_before_begin._M_nxt = nullptr;
    _M_element_count = 0;
  }

  template <typename _Key, typename _Value, typename _Alloc,
            typename _ExtractKey, typename _Equal, typename _Hash,
            typename _RangeHash, typename _Unused, typename _RehashPolicy,
            typename _Traits>
  void _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash, _RangeHash,
                  _Unused, _RehashPolicy, _Traits>::_M_move_assign(_Hashtable &&
                                                                       __ht,
                                                                   true_type) {
    if (__builtin_expect(std::__addressof(__ht) == this, false))
      return;

    this->_M_deallocate_nodes(_M_begin());
    _M_deallocate_buckets();
    __hashtable_base::operator=(std::move(__ht));
    _M_rehash_policy = __ht._M_rehash_policy;
    if (!__ht._M_uses_single_bucket())
      _M_buckets = __ht._M_buckets;
    else {
      _M_buckets = &_M_single_bucket;
      _M_single_bucket = __ht._M_single_bucket;
    }

    _M_bucket_count = __ht._M_bucket_count;
    _M_before_begin._M_nxt = __ht._M_before_begin._M_nxt;
    _M_element_count = __ht._M_element_count;
    std::__alloc_on_move(this->_M_node_allocator(), __ht._M_node_allocator());

    _M_update_bbegin();
    __ht._M_reset();
  }

  template <typename _Key, typename _Value, typename _Alloc,
            typename _ExtractKey, typename _Equal, typename _Hash,
            typename _RangeHash, typename _Unused, typename _RehashPolicy,
            typename _Traits>
  void _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash, _RangeHash,
                  _Unused, _RehashPolicy, _Traits>::_M_move_assign(_Hashtable &&
                                                                       __ht,
                                                                   false_type) {
    if (__ht._M_node_allocator() == this->_M_node_allocator())
      _M_move_assign(std::move(__ht), true_type{});
    else {

      _M_assign_elements(std::move(__ht));
      __ht.clear();
    }
  }

  template <typename _Key, typename _Value, typename _Alloc,
            typename _ExtractKey, typename _Equal, typename _Hash,
            typename _RangeHash, typename _Unused, typename _RehashPolicy,
            typename _Traits>
  _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash, _RangeHash,
             _Unused, _RehashPolicy, _Traits>::_Hashtable(const _Hashtable
                                                              &__ht)
      : __hashtable_base(__ht), __map_base(__ht), __rehash_base(__ht),
        __hashtable_alloc(
            __node_alloc_traits::_S_select_on_copy(__ht._M_node_allocator())),
        __enable_default_ctor(__ht), _M_buckets(nullptr),
        _M_bucket_count(__ht._M_bucket_count),
        _M_element_count(__ht._M_element_count),
        _M_rehash_policy(__ht._M_rehash_policy) {
    __alloc_node_gen_t __alloc_node_gen(*this);
    _M_assign(__ht, __alloc_node_gen);
  }

  template <typename _Key, typename _Value, typename _Alloc,
            typename _ExtractKey, typename _Equal, typename _Hash,
            typename _RangeHash, typename _Unused, typename _RehashPolicy,
            typename _Traits>
  _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash, _RangeHash,
             _Unused, _RehashPolicy,
             _Traits>::_Hashtable(_Hashtable && __ht, __node_alloc_type && __a,
                                  true_type) noexcept(_S_nothrow_move())
      : __hashtable_base(__ht), __map_base(__ht), __rehash_base(__ht),
        __hashtable_alloc(std::move(__a)), __enable_default_ctor(__ht),
        _M_buckets(__ht._M_buckets), _M_bucket_count(__ht._M_bucket_count),
        _M_before_begin(__ht._M_before_begin._M_nxt),
        _M_element_count(__ht._M_element_count),
        _M_rehash_policy(__ht._M_rehash_policy) {

    if (__ht._M_uses_single_bucket()) {
      _M_buckets = &_M_single_bucket;
      _M_single_bucket = __ht._M_single_bucket;
    }

    _M_update_bbegin();

    __ht._M_reset();
  }

  template <typename _Key, typename _Value, typename _Alloc,
            typename _ExtractKey, typename _Equal, typename _Hash,
            typename _RangeHash, typename _Unused, typename _RehashPolicy,
            typename _Traits>
  _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash, _RangeHash,
             _Unused, _RehashPolicy,
             _Traits>::_Hashtable(const _Hashtable &__ht,
                                  const allocator_type &__a)
      : __hashtable_base(__ht), __map_base(__ht), __rehash_base(__ht),
        __hashtable_alloc(__node_alloc_type(__a)), __enable_default_ctor(__ht),
        _M_buckets(), _M_bucket_count(__ht._M_bucket_count),
        _M_element_count(__ht._M_element_count),
        _M_rehash_policy(__ht._M_rehash_policy) {
    __alloc_node_gen_t __alloc_node_gen(*this);
    _M_assign(__ht, __alloc_node_gen);
  }

  template <typename _Key, typename _Value, typename _Alloc,
            typename _ExtractKey, typename _Equal, typename _Hash,
            typename _RangeHash, typename _Unused, typename _RehashPolicy,
            typename _Traits>
  _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash, _RangeHash,
             _Unused, _RehashPolicy, _Traits>::_Hashtable(_Hashtable && __ht,
                                                          __node_alloc_type &&
                                                              __a,
                                                          false_type)
      : __hashtable_base(__ht), __map_base(__ht), __rehash_base(__ht),
        __hashtable_alloc(std::move(__a)), __enable_default_ctor(__ht),
        _M_buckets(nullptr), _M_bucket_count(__ht._M_bucket_count),
        _M_element_count(__ht._M_element_count),
        _M_rehash_policy(__ht._M_rehash_policy) {
    if (__ht._M_node_allocator() == this->_M_node_allocator()) {
      if (__ht._M_uses_single_bucket()) {
        _M_buckets = &_M_single_bucket;
        _M_single_bucket = __ht._M_single_bucket;
      } else
        _M_buckets = __ht._M_buckets;

      _M_update_bbegin(__ht._M_begin());

      __ht._M_reset();
    } else {
      __alloc_node_gen_t __alloc_gen(*this);

      using _Fwd_Ht =
          __conditional_t<__move_if_noexcept_cond<value_type>::value,
                          const _Hashtable &, _Hashtable &&>;
      _M_assign(std::forward<_Fwd_Ht>(__ht), __alloc_gen);
      __ht.clear();
    }
  }

  template <typename _Key, typename _Value, typename _Alloc,
            typename _ExtractKey, typename _Equal, typename _Hash,
            typename _RangeHash, typename _Unused, typename _RehashPolicy,
            typename _Traits>
  _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash, _RangeHash,
             _Unused, _RehashPolicy, _Traits>::~_Hashtable() noexcept {

    static_assert(
        noexcept(declval<const __hash_code_base_access &>()._M_bucket_index(
            declval<const __node_value_type &>(), (std::size_t)0)),
        "Cache the hash code or qualify your functors involved"
        " in hash code and bucket index computation with noexcept");

    clear();
    _M_deallocate_buckets();
  }

  template <typename _Key, typename _Value, typename _Alloc,
            typename _ExtractKey, typename _Equal, typename _Hash,
            typename _RangeHash, typename _Unused, typename _RehashPolicy,
            typename _Traits>
  void _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash, _RangeHash,
                  _Unused, _RehashPolicy, _Traits>::
      swap(_Hashtable &
           __x) noexcept(__and_<__is_nothrow_swappable<_Hash>,
                                __is_nothrow_swappable<_Equal>>::value) {

    this->_M_swap(__x);

    std::__alloc_on_swap(this->_M_node_allocator(), __x._M_node_allocator());
    std::swap(_M_rehash_policy, __x._M_rehash_policy);

    if (this->_M_uses_single_bucket()) {
      if (!__x._M_uses_single_bucket()) {
        _M_buckets = __x._M_buckets;
        __x._M_buckets = &__x._M_single_bucket;
      }
    } else if (__x._M_uses_single_bucket()) {
      __x._M_buckets = _M_buckets;
      _M_buckets = &_M_single_bucket;
    } else
      std::swap(_M_buckets, __x._M_buckets);

    std::swap(_M_bucket_count, __x._M_bucket_count);
    std::swap(_M_before_begin._M_nxt, __x._M_before_begin._M_nxt);
    std::swap(_M_element_count, __x._M_element_count);
    std::swap(_M_single_bucket, __x._M_single_bucket);

    _M_update_bbegin();
    __x._M_update_bbegin();
  }

  template <typename _Key, typename _Value, typename _Alloc,
            typename _ExtractKey, typename _Equal, typename _Hash,
            typename _RangeHash, typename _Unused, typename _RehashPolicy,
            typename _Traits>
  auto _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash, _RangeHash,
                  _Unused, _RehashPolicy, _Traits>::find(const key_type &__k)
      -> iterator {
    if (size() <= __small_size_threshold()) {
      for (auto __it = _M_begin(); __it; __it = __it->_M_next())
        if (this->_M_key_equals(__k, *__it))
          return iterator(__it);
      return end();
    }

    __hash_code __code = this->_M_hash_code(__k);
    std::size_t __bkt = _M_bucket_index(__code);
    return iterator(_M_find_node(__bkt, __k, __code));
  }

  template <typename _Key, typename _Value, typename _Alloc,
            typename _ExtractKey, typename _Equal, typename _Hash,
            typename _RangeHash, typename _Unused, typename _RehashPolicy,
            typename _Traits>
  auto _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash, _RangeHash,
                  _Unused, _RehashPolicy, _Traits>::find(const key_type &__k)
      const -> const_iterator {
    if (size() <= __small_size_threshold()) {
      for (auto __it = _M_begin(); __it; __it = __it->_M_next())
        if (this->_M_key_equals(__k, *__it))
          return const_iterator(__it);
      return end();
    }

    __hash_code __code = this->_M_hash_code(__k);
    std::size_t __bkt = _M_bucket_index(__code);
    return const_iterator(_M_find_node(__bkt, __k, __code));
  }

  template <typename _Key, typename _Value, typename _Alloc,
            typename _ExtractKey, typename _Equal, typename _Hash,
            typename _RangeHash, typename _Unused, typename _RehashPolicy,
            typename _Traits>
  template <typename _Kt, typename, typename>
  auto _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash, _RangeHash,
                  _Unused, _RehashPolicy, _Traits>::_M_find_tr(const _Kt &__k)
      -> iterator {
    if (size() <= __small_size_threshold()) {
      for (auto __n = _M_begin(); __n; __n = __n->_M_next())
        if (this->_M_key_equals_tr(__k, *__n))
          return iterator(__n);
      return end();
    }

    __hash_code __code = this->_M_hash_code_tr(__k);
    std::size_t __bkt = _M_bucket_index(__code);
    return iterator(_M_find_node_tr(__bkt, __k, __code));
  }

  template <typename _Key, typename _Value, typename _Alloc,
            typename _ExtractKey, typename _Equal, typename _Hash,
            typename _RangeHash, typename _Unused, typename _RehashPolicy,
            typename _Traits>
  template <typename _Kt, typename, typename>
  auto _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash, _RangeHash,
                  _Unused, _RehashPolicy, _Traits>::_M_find_tr(const _Kt &__k)
      const -> const_iterator {
    if (size() <= __small_size_threshold()) {
      for (auto __n = _M_begin(); __n; __n = __n->_M_next())
        if (this->_M_key_equals_tr(__k, *__n))
          return const_iterator(__n);
      return end();
    }

    __hash_code __code = this->_M_hash_code_tr(__k);
    std::size_t __bkt = _M_bucket_index(__code);
    return const_iterator(_M_find_node_tr(__bkt, __k, __code));
  }

  template <typename _Key, typename _Value, typename _Alloc,
            typename _ExtractKey, typename _Equal, typename _Hash,
            typename _RangeHash, typename _Unused, typename _RehashPolicy,
            typename _Traits>
  auto _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash, _RangeHash,
                  _Unused, _RehashPolicy, _Traits>::count(const key_type &__k)
      const -> size_type {
    auto __it = find(__k);
    if (!__it._M_cur)
      return 0;

    if (__unique_keys::value)
      return 1;

    size_type __result = 1;
    for (auto __ref = __it++;
         __it._M_cur && this->_M_node_equals(*__ref._M_cur, *__it._M_cur);
         ++__it)
      ++__result;

    return __result;
  }

  template <typename _Key, typename _Value, typename _Alloc,
            typename _ExtractKey, typename _Equal, typename _Hash,
            typename _RangeHash, typename _Unused, typename _RehashPolicy,
            typename _Traits>
  template <typename _Kt, typename, typename>
  auto _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash, _RangeHash,
                  _Unused, _RehashPolicy, _Traits>::_M_count_tr(const _Kt &__k)
      const -> size_type {
    if (size() <= __small_size_threshold()) {
      size_type __result = 0;
      for (auto __n = _M_begin(); __n; __n = __n->_M_next()) {
        if (this->_M_key_equals_tr(__k, *__n)) {
          ++__result;
          continue;
        }

        if (__result)
          break;
      }

      return __result;
    }

    __hash_code __code = this->_M_hash_code_tr(__k);
    std::size_t __bkt = _M_bucket_index(__code);
    auto __n = _M_find_node_tr(__bkt, __k, __code);
    if (!__n)
      return 0;

    iterator __it(__n);
    size_type __result = 1;
    for (++__it; __it._M_cur && this->_M_equals_tr(__k, __code, *__it._M_cur);
         ++__it)
      ++__result;

    return __result;
  }

  template <typename _Key, typename _Value, typename _Alloc,
            typename _ExtractKey, typename _Equal, typename _Hash,
            typename _RangeHash, typename _Unused, typename _RehashPolicy,
            typename _Traits>
  auto
  _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash, _RangeHash,
             _Unused, _RehashPolicy, _Traits>::equal_range(const key_type &__k)
      -> pair<iterator, iterator> {
    auto __ite = find(__k);
    if (!__ite._M_cur)
      return {__ite, __ite};

    auto __beg = __ite++;
    if (__unique_keys::value)
      return {__beg, __ite};

    while (__ite._M_cur && this->_M_node_equals(*__beg._M_cur, *__ite._M_cur))
      ++__ite;

    return {__beg, __ite};
  }

  template <typename _Key, typename _Value, typename _Alloc,
            typename _ExtractKey, typename _Equal, typename _Hash,
            typename _RangeHash, typename _Unused, typename _RehashPolicy,
            typename _Traits>
  auto
  _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash, _RangeHash,
             _Unused, _RehashPolicy, _Traits>::equal_range(const key_type &__k)
      const -> pair<const_iterator, const_iterator> {
    auto __ite = find(__k);
    if (!__ite._M_cur)
      return {__ite, __ite};

    auto __beg = __ite++;
    if (__unique_keys::value)
      return {__beg, __ite};

    while (__ite._M_cur && this->_M_node_equals(*__beg._M_cur, *__ite._M_cur))
      ++__ite;

    return {__beg, __ite};
  }

  template <typename _Key, typename _Value, typename _Alloc,
            typename _ExtractKey, typename _Equal, typename _Hash,
            typename _RangeHash, typename _Unused, typename _RehashPolicy,
            typename _Traits>
  template <typename _Kt, typename, typename>
  auto
  _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash, _RangeHash,
             _Unused, _RehashPolicy, _Traits>::_M_equal_range_tr(const _Kt &__k)
      -> pair<iterator, iterator> {
    if (size() <= __small_size_threshold()) {
      __node_ptr __n, __beg = nullptr;
      for (__n = _M_begin(); __n; __n = __n->_M_next()) {
        if (this->_M_key_equals_tr(__k, *__n)) {
          if (!__beg)
            __beg = __n;
          continue;
        }

        if (__beg)
          break;
      }

      return {iterator(__beg), iterator(__n)};
    }

    __hash_code __code = this->_M_hash_code_tr(__k);
    std::size_t __bkt = _M_bucket_index(__code);
    auto __n = _M_find_node_tr(__bkt, __k, __code);
    iterator __ite(__n);
    if (!__n)
      return {__ite, __ite};

    auto __beg = __ite++;
    while (__ite._M_cur && this->_M_equals_tr(__k, __code, *__ite._M_cur))
      ++__ite;

    return {__beg, __ite};
  }

  template <typename _Key, typename _Value, typename _Alloc,
            typename _ExtractKey, typename _Equal, typename _Hash,
            typename _RangeHash, typename _Unused, typename _RehashPolicy,
            typename _Traits>
  template <typename _Kt, typename, typename>
  auto
  _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash, _RangeHash,
             _Unused, _RehashPolicy, _Traits>::_M_equal_range_tr(const _Kt &__k)
      const -> pair<const_iterator, const_iterator> {
    if (size() <= __small_size_threshold()) {
      __node_ptr __n, __beg = nullptr;
      for (__n = _M_begin(); __n; __n = __n->_M_next()) {
        if (this->_M_key_equals_tr(__k, *__n)) {
          if (!__beg)
            __beg = __n;
          continue;
        }

        if (__beg)
          break;
      }

      return {const_iterator(__beg), const_iterator(__n)};
    }

    __hash_code __code = this->_M_hash_code_tr(__k);
    std::size_t __bkt = _M_bucket_index(__code);
    auto __n = _M_find_node_tr(__bkt, __k, __code);
    const_iterator __ite(__n);
    if (!__n)
      return {__ite, __ite};

    auto __beg = __ite++;
    while (__ite._M_cur && this->_M_equals_tr(__k, __code, *__ite._M_cur))
      ++__ite;

    return {__beg, __ite};
  }

  template <typename _Key, typename _Value, typename _Alloc,
            typename _ExtractKey, typename _Equal, typename _Hash,
            typename _RangeHash, typename _Unused, typename _RehashPolicy,
            typename _Traits>
  auto _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash, _RangeHash,
                  _Unused, _RehashPolicy,
                  _Traits>::_M_find_before_node(const key_type &__k)
      -> __node_base_ptr {
    __node_base_ptr __prev_p = &_M_before_begin;
    if (!__prev_p->_M_nxt)
      return nullptr;

    for (__node_ptr __p = static_cast<__node_ptr>(__prev_p->_M_nxt);
         __p != nullptr; __p = __p->_M_next()) {
      if (this->_M_key_equals(__k, *__p))
        return __prev_p;

      __prev_p = __p;
    }

    return nullptr;
  }

  template <typename _Key, typename _Value, typename _Alloc,
            typename _ExtractKey, typename _Equal, typename _Hash,
            typename _RangeHash, typename _Unused, typename _RehashPolicy,
            typename _Traits>
  auto _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash, _RangeHash,
                  _Unused, _RehashPolicy,
                  _Traits>::_M_find_before_node(size_type __bkt,
                                                const key_type &__k,
                                                __hash_code __code) const
      -> __node_base_ptr {
    __node_base_ptr __prev_p = _M_buckets[__bkt];
    if (!__prev_p)
      return nullptr;

    for (__node_ptr __p = static_cast<__node_ptr>(__prev_p->_M_nxt);;
         __p = __p->_M_next()) {
      if (this->_M_equals(__k, __code, *__p))
        return __prev_p;

      if (!__p->_M_nxt || _M_bucket_index(*__p->_M_next()) != __bkt)
        break;
      __prev_p = __p;
    }

    return nullptr;
  }

  template <typename _Key, typename _Value, typename _Alloc,
            typename _ExtractKey, typename _Equal, typename _Hash,
            typename _RangeHash, typename _Unused, typename _RehashPolicy,
            typename _Traits>
  template <typename _Kt>
  auto _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash, _RangeHash,
                  _Unused, _RehashPolicy,
                  _Traits>::_M_find_before_node_tr(size_type __bkt,
                                                   const _Kt &__k,
                                                   __hash_code __code) const
      -> __node_base_ptr {
    __node_base_ptr __prev_p = _M_buckets[__bkt];
    if (!__prev_p)
      return nullptr;

    for (__node_ptr __p = static_cast<__node_ptr>(__prev_p->_M_nxt);;
         __p = __p->_M_next()) {
      if (this->_M_equals_tr(__k, __code, *__p))
        return __prev_p;

      if (!__p->_M_nxt || _M_bucket_index(*__p->_M_next()) != __bkt)
        break;
      __prev_p = __p;
    }

    return nullptr;
  }

  template <typename _Key, typename _Value, typename _Alloc,
            typename _ExtractKey, typename _Equal, typename _Hash,
            typename _RangeHash, typename _Unused, typename _RehashPolicy,
            typename _Traits>
  auto _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash, _RangeHash,
                  _Unused, _RehashPolicy,
                  _Traits>::_M_get_previous_node(size_type __bkt,
                                                 __node_ptr __n)
      -> __node_base_ptr {
    __node_base_ptr __prev_n = _M_buckets[__bkt];
    while (__prev_n->_M_nxt != __n)
      __prev_n = __prev_n->_M_nxt;
    return __prev_n;
  }

  template <typename _Key, typename _Value, typename _Alloc,
            typename _ExtractKey, typename _Equal, typename _Hash,
            typename _RangeHash, typename _Unused, typename _RehashPolicy,
            typename _Traits>
  template <typename... _Args>
  auto _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash, _RangeHash,
                  _Unused, _RehashPolicy, _Traits>::_M_emplace(true_type,
                                                               _Args &&
                                                                   ...__args)
      -> pair<iterator, bool> {

    _Scoped_node __node{this, std::forward<_Args>(__args)...};
    const key_type &__k = _ExtractKey{}(__node._M_node->_M_v());
    const size_type __size = size();
    if (__size <= __small_size_threshold()) {
      for (auto __it = _M_begin(); __it; __it = __it->_M_next())
        if (this->_M_key_equals(__k, *__it))

          return {iterator(__it), false};
    }

    __hash_code __code = this->_M_hash_code(__k);
    size_type __bkt = _M_bucket_index(__code);
    if (__size > __small_size_threshold())
      if (__node_ptr __p = _M_find_node(__bkt, __k, __code))

        return {iterator(__p), false};

    auto __pos = _M_insert_unique_node(__bkt, __code, __node._M_node);
    __node._M_node = nullptr;
    return {__pos, true};
  }

  template <typename _Key, typename _Value, typename _Alloc,
            typename _ExtractKey, typename _Equal, typename _Hash,
            typename _RangeHash, typename _Unused, typename _RehashPolicy,
            typename _Traits>
  template <typename... _Args>
  auto _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash, _RangeHash,
                  _Unused, _RehashPolicy,
                  _Traits>::_M_emplace(const_iterator __hint, false_type,
                                       _Args && ...__args) -> iterator {

    _Scoped_node __node{this, std::forward<_Args>(__args)...};
    const key_type &__k = _ExtractKey{}(__node._M_node->_M_v());

    auto __res = this->_M_compute_hash_code(__hint._M_cur, __k);
    auto __pos =
        _M_insert_multi_node(__res.first, __res.second, __node._M_node);
    __node._M_node = nullptr;
    return __pos;
  }

  template <typename _Key, typename _Value, typename _Alloc,
            typename _ExtractKey, typename _Equal, typename _Hash,
            typename _RangeHash, typename _Unused, typename _RehashPolicy,
            typename _Traits>
  auto _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash, _RangeHash,
                  _Unused, _RehashPolicy,
                  _Traits>::_M_compute_hash_code(__node_ptr __hint,
                                                 const key_type &__k) const
      -> pair<__node_ptr, __hash_code> {
    if (size() <= __small_size_threshold()) {
      if (__hint) {
        for (auto __it = __hint; __it; __it = __it->_M_next())
          if (this->_M_key_equals(__k, *__it))
            return {__it, this->_M_hash_code(*__it)};
      }

      for (auto __it = _M_begin(); __it != __hint; __it = __it->_M_next())
        if (this->_M_key_equals(__k, *__it))
          return {__it, this->_M_hash_code(*__it)};

      __hint = nullptr;
    }

    return {__hint, this->_M_hash_code(__k)};
  }

  template <typename _Key, typename _Value, typename _Alloc,
            typename _ExtractKey, typename _Equal, typename _Hash,
            typename _RangeHash, typename _Unused, typename _RehashPolicy,
            typename _Traits>
  auto _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash, _RangeHash,
                  _Unused, _RehashPolicy,
                  _Traits>::_M_insert_unique_node(size_type __bkt,
                                                  __hash_code __code,
                                                  __node_ptr __node,
                                                  size_type __n_elt)
      -> iterator {
    __rehash_guard_t __rehash_guard(_M_rehash_policy);
    std::pair<bool, std::size_t> __do_rehash = _M_rehash_policy._M_need_rehash(
        _M_bucket_count, _M_element_count, __n_elt);

    if (__do_rehash.first) {
      _M_rehash(__do_rehash.second, true_type{});
      __bkt = _M_bucket_index(__code);
    }

    __rehash_guard._M_guarded_obj = nullptr;
    this->_M_store_code(*__node, __code);

    _M_insert_bucket_begin(__bkt, __node);
    ++_M_element_count;
    return iterator(__node);
  }

  template <typename _Key, typename _Value, typename _Alloc,
            typename _ExtractKey, typename _Equal, typename _Hash,
            typename _RangeHash, typename _Unused, typename _RehashPolicy,
            typename _Traits>
  auto _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash, _RangeHash,
                  _Unused, _RehashPolicy,
                  _Traits>::_M_insert_multi_node(__node_ptr __hint,
                                                 __hash_code __code,
                                                 __node_ptr __node)
      -> iterator {
    __rehash_guard_t __rehash_guard(_M_rehash_policy);
    std::pair<bool, std::size_t> __do_rehash =
        _M_rehash_policy._M_need_rehash(_M_bucket_count, _M_element_count, 1);

    if (__do_rehash.first)
      _M_rehash(__do_rehash.second, false_type{});

    __rehash_guard._M_guarded_obj = nullptr;
    this->_M_store_code(*__node, __code);
    const key_type &__k = _ExtractKey{}(__node->_M_v());
    size_type __bkt = _M_bucket_index(__code);

    __node_base_ptr __prev = __builtin_expect(__hint != nullptr, false) &&
                                     this->_M_equals(__k, __code, *__hint)
                                 ? __hint
                                 : _M_find_before_node(__bkt, __k, __code);

    if (__prev) {

      __node->_M_nxt = __prev->_M_nxt;
      __prev->_M_nxt = __node;
      if (__builtin_expect(__prev == __hint, false))

        if (__node->_M_nxt &&
            !this->_M_equals(__k, __code, *__node->_M_next())) {
          size_type __next_bkt = _M_bucket_index(*__node->_M_next());
          if (__next_bkt != __bkt)
            _M_buckets[__next_bkt] = __node;
        }
    } else

      _M_insert_bucket_begin(__bkt, __node);
    ++_M_element_count;
    return iterator(__node);
  }

  template <typename _Key, typename _Value, typename _Alloc,
            typename _ExtractKey, typename _Equal, typename _Hash,
            typename _RangeHash, typename _Unused, typename _RehashPolicy,
            typename _Traits>
  template <typename _Kt, typename _Arg, typename _NodeGenerator>
  auto _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash, _RangeHash,
                  _Unused, _RehashPolicy,
                  _Traits>::_M_insert_unique(_Kt && __k, _Arg && __v,
                                             const _NodeGenerator &__node_gen)
      -> pair<iterator, bool> {
    const size_type __size = size();
    if (__size <= __small_size_threshold())
      for (auto __it = _M_begin(); __it; __it = __it->_M_next())
        if (this->_M_key_equals_tr(__k, *__it))
          return {iterator(__it), false};

    __hash_code __code = this->_M_hash_code_tr(__k);
    size_type __bkt = _M_bucket_index(__code);

    if (__size > __small_size_threshold())
      if (__node_ptr __node = _M_find_node_tr(__bkt, __k, __code))
        return {iterator(__node), false};

    _Scoped_node __node{__node_builder_t::_S_build(std::forward<_Kt>(__k),
                                                   std::forward<_Arg>(__v),
                                                   __node_gen),
                        this};
    auto __pos = _M_insert_unique_node(__bkt, __code, __node._M_node);
    __node._M_node = nullptr;
    return {__pos, true};
  }

  template <typename _Key, typename _Value, typename _Alloc,
            typename _ExtractKey, typename _Equal, typename _Hash,
            typename _RangeHash, typename _Unused, typename _RehashPolicy,
            typename _Traits>
  template <typename _Arg, typename _NodeGenerator>
  auto _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash, _RangeHash,
                  _Unused, _RehashPolicy,
                  _Traits>::_M_insert(const_iterator __hint, _Arg && __v,
                                      const _NodeGenerator &__node_gen,
                                      false_type) -> iterator {

    _Scoped_node __node{__node_gen(std::forward<_Arg>(__v)), this};

    auto __res = this->_M_compute_hash_code(
        __hint._M_cur, _ExtractKey{}(__node._M_node->_M_v()));

    auto __pos =
        _M_insert_multi_node(__res.first, __res.second, __node._M_node);
    __node._M_node = nullptr;
    return __pos;
  }

  template <typename _Key, typename _Value, typename _Alloc,
            typename _ExtractKey, typename _Equal, typename _Hash,
            typename _RangeHash, typename _Unused, typename _RehashPolicy,
            typename _Traits>
  auto _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash, _RangeHash,
                  _Unused, _RehashPolicy, _Traits>::erase(const_iterator __it)
      -> iterator {
    __node_ptr __n = __it._M_cur;
    std::size_t __bkt = _M_bucket_index(*__n);

    __node_base_ptr __prev_n = _M_get_previous_node(__bkt, __n);
    return _M_erase(__bkt, __prev_n, __n);
  }

  template <typename _Key, typename _Value, typename _Alloc,
            typename _ExtractKey, typename _Equal, typename _Hash,
            typename _RangeHash, typename _Unused, typename _RehashPolicy,
            typename _Traits>
  auto _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash, _RangeHash,
                  _Unused, _RehashPolicy,
                  _Traits>::_M_erase(size_type __bkt, __node_base_ptr __prev_n,
                                     __node_ptr __n) -> iterator {
    if (__prev_n == _M_buckets[__bkt])
      _M_remove_bucket_begin(__bkt, __n->_M_next(),
                             __n->_M_nxt ? _M_bucket_index(*__n->_M_next())
                                         : 0);
    else if (__n->_M_nxt) {
      size_type __next_bkt = _M_bucket_index(*__n->_M_next());
      if (__next_bkt != __bkt)
        _M_buckets[__next_bkt] = __prev_n;
    }

    __prev_n->_M_nxt = __n->_M_nxt;
    iterator __result(__n->_M_next());
    this->_M_deallocate_node(__n);
    --_M_element_count;

    return __result;
  }

  template <typename _Key, typename _Value, typename _Alloc,
            typename _ExtractKey, typename _Equal, typename _Hash,
            typename _RangeHash, typename _Unused, typename _RehashPolicy,
            typename _Traits>
  auto _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash, _RangeHash,
                  _Unused, _RehashPolicy,
                  _Traits>::_M_erase(true_type, const key_type &__k)
      -> size_type {
    __node_base_ptr __prev_n;
    __node_ptr __n;
    std::size_t __bkt;
    if (size() <= __small_size_threshold()) {
      __prev_n = _M_find_before_node(__k);
      if (!__prev_n)
        return 0;

      __n = static_cast<__node_ptr>(__prev_n->_M_nxt);
      __bkt = _M_bucket_index(*__n);
    } else {
      __hash_code __code = this->_M_hash_code(__k);
      __bkt = _M_bucket_index(__code);

      __prev_n = _M_find_before_node(__bkt, __k, __code);
      if (!__prev_n)
        return 0;

      __n = static_cast<__node_ptr>(__prev_n->_M_nxt);
    }

    _M_erase(__bkt, __prev_n, __n);
    return 1;
  }

  template <typename _Key, typename _Value, typename _Alloc,
            typename _ExtractKey, typename _Equal, typename _Hash,
            typename _RangeHash, typename _Unused, typename _RehashPolicy,
            typename _Traits>
  auto _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash, _RangeHash,
                  _Unused, _RehashPolicy,
                  _Traits>::_M_erase(false_type, const key_type &__k)
      -> size_type {
    std::size_t __bkt;
    __node_base_ptr __prev_n;
    __node_ptr __n;
    if (size() <= __small_size_threshold()) {
      __prev_n = _M_find_before_node(__k);
      if (!__prev_n)
        return 0;

      __n = static_cast<__node_ptr>(__prev_n->_M_nxt);
      __bkt = _M_bucket_index(*__n);
    } else {
      __hash_code __code = this->_M_hash_code(__k);
      __bkt = _M_bucket_index(__code);

      __prev_n = _M_find_before_node(__bkt, __k, __code);
      if (!__prev_n)
        return 0;

      __n = static_cast<__node_ptr>(__prev_n->_M_nxt);
    }

    __node_ptr __n_last = __n->_M_next();
    while (__n_last && this->_M_node_equals(*__n, *__n_last))
      __n_last = __n_last->_M_next();

    std::size_t __n_last_bkt = __n_last ? _M_bucket_index(*__n_last) : __bkt;

    size_type __result = 0;
    do {
      __node_ptr __p = __n->_M_next();
      this->_M_deallocate_node(__n);
      __n = __p;
      ++__result;
    } while (__n != __n_last);

    _M_element_count -= __result;
    if (__prev_n == _M_buckets[__bkt])
      _M_remove_bucket_begin(__bkt, __n_last, __n_last_bkt);
    else if (__n_last_bkt != __bkt)
      _M_buckets[__n_last_bkt] = __prev_n;
    __prev_n->_M_nxt = __n_last;
    return __result;
  }

  template <typename _Key, typename _Value, typename _Alloc,
            typename _ExtractKey, typename _Equal, typename _Hash,
            typename _RangeHash, typename _Unused, typename _RehashPolicy,
            typename _Traits>
  auto _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash, _RangeHash,
                  _Unused, _RehashPolicy,
                  _Traits>::erase(const_iterator __first, const_iterator __last)
      -> iterator {
    __node_ptr __n = __first._M_cur;
    __node_ptr __last_n = __last._M_cur;
    if (__n == __last_n)
      return iterator(__n);

    std::size_t __bkt = _M_bucket_index(*__n);

    __node_base_ptr __prev_n = _M_get_previous_node(__bkt, __n);
    bool __is_bucket_begin = __n == _M_bucket_begin(__bkt);
    std::size_t __n_bkt = __bkt;
    for (;;) {
      do {
        __node_ptr __tmp = __n;
        __n = __n->_M_next();
        this->_M_deallocate_node(__tmp);
        --_M_element_count;
        if (!__n)
          break;
        __n_bkt = _M_bucket_index(*__n);
      } while (__n != __last_n && __n_bkt == __bkt);
      if (__is_bucket_begin)
        _M_remove_bucket_begin(__bkt, __n, __n_bkt);
      if (__n == __last_n)
        break;
      __is_bucket_begin = true;
      __bkt = __n_bkt;
    }

    if (__n && (__n_bkt != __bkt || __is_bucket_begin))
      _M_buckets[__n_bkt] = __prev_n;
    __prev_n->_M_nxt = __n;
    return iterator(__n);
  }

  template <typename _Key, typename _Value, typename _Alloc,
            typename _ExtractKey, typename _Equal, typename _Hash,
            typename _RangeHash, typename _Unused, typename _RehashPolicy,
            typename _Traits>
  void _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash, _RangeHash,
                  _Unused, _RehashPolicy, _Traits>::clear() noexcept {
    this->_M_deallocate_nodes(_M_begin());
    __builtin_memset(_M_buckets, 0, _M_bucket_count * sizeof(__node_base_ptr));
    _M_element_count = 0;
    _M_before_begin._M_nxt = nullptr;
  }

  template <typename _Key, typename _Value, typename _Alloc,
            typename _ExtractKey, typename _Equal, typename _Hash,
            typename _RangeHash, typename _Unused, typename _RehashPolicy,
            typename _Traits>
  void
  _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash, _RangeHash,
             _Unused, _RehashPolicy, _Traits>::rehash(size_type __bkt_count) {
    __rehash_guard_t __rehash_guard(_M_rehash_policy);
    __bkt_count =
        std::max(_M_rehash_policy._M_bkt_for_elements(_M_element_count + 1),
                 __bkt_count);
    __bkt_count = _M_rehash_policy._M_next_bkt(__bkt_count);

    if (__bkt_count != _M_bucket_count) {
      _M_rehash(__bkt_count, __unique_keys{});
      __rehash_guard._M_guarded_obj = nullptr;
    }
  }

  template <typename _Key, typename _Value, typename _Alloc,
            typename _ExtractKey, typename _Equal, typename _Hash,
            typename _RangeHash, typename _Unused, typename _RehashPolicy,
            typename _Traits>
  void _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash, _RangeHash,
                  _Unused, _RehashPolicy,
                  _Traits>::_M_rehash(size_type __bkt_count, true_type) {
    __buckets_ptr __new_buckets = _M_allocate_buckets(__bkt_count);
    __node_ptr __p = _M_begin();
    _M_before_begin._M_nxt = nullptr;
    std::size_t __bbegin_bkt = 0;
    while (__p) {
      __node_ptr __next = __p->_M_next();
      std::size_t __bkt = __hash_code_base::_M_bucket_index(*__p, __bkt_count);
      if (!__new_buckets[__bkt]) {
        __p->_M_nxt = _M_before_begin._M_nxt;
        _M_before_begin._M_nxt = __p;
        __new_buckets[__bkt] = &_M_before_begin;
        if (__p->_M_nxt)
          __new_buckets[__bbegin_bkt] = __p;
        __bbegin_bkt = __bkt;
      } else {
        __p->_M_nxt = __new_buckets[__bkt]->_M_nxt;
        __new_buckets[__bkt]->_M_nxt = __p;
      }

      __p = __next;
    }

    _M_deallocate_buckets();
    _M_bucket_count = __bkt_count;
    _M_buckets = __new_buckets;
  }

  template <typename _Key, typename _Value, typename _Alloc,
            typename _ExtractKey, typename _Equal, typename _Hash,
            typename _RangeHash, typename _Unused, typename _RehashPolicy,
            typename _Traits>
  void _Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash, _RangeHash,
                  _Unused, _RehashPolicy,
                  _Traits>::_M_rehash(size_type __bkt_count, false_type) {
    __buckets_ptr __new_buckets = _M_allocate_buckets(__bkt_count);
    __node_ptr __p = _M_begin();
    _M_before_begin._M_nxt = nullptr;
    std::size_t __bbegin_bkt = 0;
    std::size_t __prev_bkt = 0;
    __node_ptr __prev_p = nullptr;
    bool __check_bucket = false;

    while (__p) {
      __node_ptr __next = __p->_M_next();
      std::size_t __bkt = __hash_code_base::_M_bucket_index(*__p, __bkt_count);

      if (__prev_p && __prev_bkt == __bkt) {

        __p->_M_nxt = __prev_p->_M_nxt;
        __prev_p->_M_nxt = __p;

        __check_bucket = true;
      } else {
        if (__check_bucket) {

          if (__prev_p->_M_nxt) {
            std::size_t __next_bkt = __hash_code_base::_M_bucket_index(
                *__prev_p->_M_next(), __bkt_count);
            if (__next_bkt != __prev_bkt)
              __new_buckets[__next_bkt] = __prev_p;
          }
          __check_bucket = false;
        }

        if (!__new_buckets[__bkt]) {
          __p->_M_nxt = _M_before_begin._M_nxt;
          _M_before_begin._M_nxt = __p;
          __new_buckets[__bkt] = &_M_before_begin;
          if (__p->_M_nxt)
            __new_buckets[__bbegin_bkt] = __p;
          __bbegin_bkt = __bkt;
        } else {
          __p->_M_nxt = __new_buckets[__bkt]->_M_nxt;
          __new_buckets[__bkt]->_M_nxt = __p;
        }
      }
      __prev_p = __p;
      __prev_bkt = __bkt;
      __p = __next;
    }

    if (__check_bucket && __prev_p->_M_nxt) {
      std::size_t __next_bkt =
          __hash_code_base::_M_bucket_index(*__prev_p->_M_next(), __bkt_count);
      if (__next_bkt != __prev_bkt)
        __new_buckets[__next_bkt] = __prev_p;
    }

    _M_deallocate_buckets();
    _M_bucket_count = __bkt_count;
    _M_buckets = __new_buckets;
  }

  template <typename, typename, typename> class _Hash_merge_helper {};

  template <typename _Hash>
  using _RequireNotAllocatorOrIntegral =
      __enable_if_t<!__or_<is_integral<_Hash>, __is_allocator<_Hash>>::value>;

} // namespace std

namespace std __attribute__((__visibility__("default"))) {

  template <bool _Cache>
  using __umap_traits = __detail::_Hashtable_traits<_Cache, false, true>;

  template <typename _Key, typename _Tp, typename _Hash = hash<_Key>,
            typename _Pred = std::equal_to<_Key>,
            typename _Alloc = std::allocator<std::pair<const _Key, _Tp>>,
            typename _Tr = __umap_traits<__cache_default<_Key, _Hash>::value>>
  using __umap_hashtable =
      _Hashtable<_Key, std::pair<const _Key, _Tp>, _Alloc, __detail::_Select1st,
                 _Pred, _Hash, __detail::_Mod_range_hashing,
                 __detail::_Default_ranged_hash, __detail::_Prime_rehash_policy,
                 _Tr>;

  template <bool _Cache>
  using __ummap_traits = __detail::_Hashtable_traits<_Cache, false, false>;

  template <typename _Key, typename _Tp, typename _Hash = hash<_Key>,
            typename _Pred = std::equal_to<_Key>,
            typename _Alloc = std::allocator<std::pair<const _Key, _Tp>>,
            typename _Tr = __ummap_traits<__cache_default<_Key, _Hash>::value>>
  using __ummap_hashtable =
      _Hashtable<_Key, std::pair<const _Key, _Tp>, _Alloc, __detail::_Select1st,
                 _Pred, _Hash, __detail::_Mod_range_hashing,
                 __detail::_Default_ranged_hash, __detail::_Prime_rehash_policy,
                 _Tr>;

  template <class _Key, class _Tp, class _Hash, class _Pred, class _Alloc>
  class unordered_multimap;
  template <typename _Key, typename _Tp, typename _Hash = hash<_Key>,
            typename _Pred = equal_to<_Key>,
            typename _Alloc = allocator<std::pair<const _Key, _Tp>>>
  class unordered_map {
    typedef __umap_hashtable<_Key, _Tp, _Hash, _Pred, _Alloc> _Hashtable;
    _Hashtable _M_h;

  public:
    typedef typename _Hashtable::key_type key_type;
    typedef typename _Hashtable::value_type value_type;
    typedef typename _Hashtable::mapped_type mapped_type;
    typedef typename _Hashtable::hasher hasher;
    typedef typename _Hashtable::key_equal key_equal;
    typedef typename _Hashtable::allocator_type allocator_type;

    typedef typename _Hashtable::pointer pointer;
    typedef typename _Hashtable::const_pointer const_pointer;
    typedef typename _Hashtable::reference reference;
    typedef typename _Hashtable::const_reference const_reference;
    typedef typename _Hashtable::iterator iterator;
    typedef typename _Hashtable::const_iterator const_iterator;
    typedef typename _Hashtable::local_iterator local_iterator;
    typedef typename _Hashtable::const_local_iterator const_local_iterator;
    typedef typename _Hashtable::size_type size_type;
    typedef typename _Hashtable::difference_type difference_type;

    using node_type = typename _Hashtable::node_type;
    using insert_return_type = typename _Hashtable::insert_return_type;

    unordered_map() = default;
    explicit unordered_map(size_type __n, const hasher &__hf = hasher(),
                           const key_equal &__eql = key_equal(),
                           const allocator_type &__a = allocator_type())
        : _M_h(__n, __hf, __eql, __a) {}
    template <typename _InputIterator>
    unordered_map(_InputIterator __first, _InputIterator __last,
                  size_type __n = 0, const hasher &__hf = hasher(),
                  const key_equal &__eql = key_equal(),
                  const allocator_type &__a = allocator_type())
        : _M_h(__first, __last, __n, __hf, __eql, __a) {}

    unordered_map(const unordered_map &) = default;

    unordered_map(unordered_map &&) = default;

    explicit unordered_map(const allocator_type &__a) : _M_h(__a) {}

    unordered_map(const unordered_map &__umap, const allocator_type &__a)
        : _M_h(__umap._M_h, __a) {}

    unordered_map(unordered_map &&__umap, const allocator_type &__a) noexcept(
        noexcept(_Hashtable(std::move(__umap._M_h), __a)))
        : _M_h(std::move(__umap._M_h), __a) {}
    unordered_map(initializer_list<value_type> __l, size_type __n = 0,
                  const hasher &__hf = hasher(),
                  const key_equal &__eql = key_equal(),
                  const allocator_type &__a = allocator_type())
        : _M_h(__l, __n, __hf, __eql, __a) {}

    unordered_map(size_type __n, const allocator_type &__a)
        : unordered_map(__n, hasher(), key_equal(), __a) {}

    unordered_map(size_type __n, const hasher &__hf, const allocator_type &__a)
        : unordered_map(__n, __hf, key_equal(), __a) {}

    template <typename _InputIterator>
    unordered_map(_InputIterator __first, _InputIterator __last, size_type __n,
                  const allocator_type &__a)
        : unordered_map(__first, __last, __n, hasher(), key_equal(), __a) {}

    template <typename _InputIterator>
    unordered_map(_InputIterator __first, _InputIterator __last, size_type __n,
                  const hasher &__hf, const allocator_type &__a)
        : unordered_map(__first, __last, __n, __hf, key_equal(), __a) {}

    unordered_map(initializer_list<value_type> __l, size_type __n,
                  const allocator_type &__a)
        : unordered_map(__l, __n, hasher(), key_equal(), __a) {}

    unordered_map(initializer_list<value_type> __l, size_type __n,
                  const hasher &__hf, const allocator_type &__a)
        : unordered_map(__l, __n, __hf, key_equal(), __a) {}

    unordered_map &operator=(const unordered_map &) = default;

    unordered_map &operator=(unordered_map &&) = default;
    unordered_map &operator=(initializer_list<value_type> __l) {
      _M_h = __l;
      return *this;
    }

    allocator_type get_allocator() const noexcept {
      return _M_h.get_allocator();
    }

    [[__nodiscard__]] bool empty() const noexcept { return _M_h.empty(); }

    size_type size() const noexcept { return _M_h.size(); }

    size_type max_size() const noexcept { return _M_h.max_size(); }

    iterator begin() noexcept { return _M_h.begin(); }

    const_iterator begin() const noexcept { return _M_h.begin(); }

    const_iterator cbegin() const noexcept { return _M_h.begin(); }

    iterator end() noexcept { return _M_h.end(); }

    const_iterator end() const noexcept { return _M_h.end(); }

    const_iterator cend() const noexcept { return _M_h.end(); }
    template <typename... _Args>
    std::pair<iterator, bool> emplace(_Args &&...__args) {
      return _M_h.emplace(std::forward<_Args>(__args)...);
    }
    template <typename... _Args>
    iterator emplace_hint(const_iterator __pos, _Args &&...__args) {
      return _M_h.emplace_hint(__pos, std::forward<_Args>(__args)...);
    }

    node_type extract(const_iterator __pos) {
      do {
        if (std::__is_constant_evaluated())
          if (__builtin_expect(!bool(__pos != end()), false))
            std::__glibcxx_assert_fail();
      } while (false);
      return _M_h.extract(__pos);
    }

    node_type extract(const key_type &__key) { return _M_h.extract(__key); }

    insert_return_type insert(node_type &&__nh) {
      return _M_h._M_reinsert_node(std::move(__nh));
    }

    iterator insert(const_iterator, node_type &&__nh) {
      return _M_h._M_reinsert_node(std::move(__nh)).position;
    }
    template <typename... _Args>
    pair<iterator, bool> try_emplace(const key_type &__k, _Args &&...__args) {
      return _M_h.try_emplace(cend(), __k, std::forward<_Args>(__args)...);
    }

    template <typename... _Args>
    pair<iterator, bool> try_emplace(key_type &&__k, _Args &&...__args) {
      return _M_h.try_emplace(cend(), std::move(__k),
                              std::forward<_Args>(__args)...);
    }
    template <typename... _Args>
    iterator try_emplace(const_iterator __hint, const key_type &__k,
                         _Args &&...__args) {
      return _M_h.try_emplace(__hint, __k, std::forward<_Args>(__args)...)
          .first;
    }

    template <typename... _Args>
    iterator try_emplace(const_iterator __hint, key_type &&__k,
                         _Args &&...__args) {
      return _M_h
          .try_emplace(__hint, std::move(__k), std::forward<_Args>(__args)...)
          .first;
    }
    std::pair<iterator, bool> insert(const value_type &__x) {
      return _M_h.insert(__x);
    }

    std::pair<iterator, bool> insert(value_type &&__x) {
      return _M_h.insert(std::move(__x));
    }

    template <typename _Pair>
    __enable_if_t<is_constructible<value_type, _Pair &&>::value,
                  pair<iterator, bool>>
    insert(_Pair &&__x) {
      return _M_h.emplace(std::forward<_Pair>(__x));
    }
    iterator insert(const_iterator __hint, const value_type &__x) {
      return _M_h.insert(__hint, __x);
    }

    iterator insert(const_iterator __hint, value_type &&__x) {
      return _M_h.insert(__hint, std::move(__x));
    }

    template <typename _Pair>
    __enable_if_t<is_constructible<value_type, _Pair &&>::value, iterator>
    insert(const_iterator __hint, _Pair &&__x) {
      return _M_h.emplace_hint(__hint, std::forward<_Pair>(__x));
    }
    template <typename _InputIterator>
    void insert(_InputIterator __first, _InputIterator __last) {
      _M_h.insert(__first, __last);
    }
    void insert(initializer_list<value_type> __l) { _M_h.insert(__l); }
    template <typename _Obj>
    pair<iterator, bool> insert_or_assign(const key_type &__k, _Obj &&__obj) {
      auto __ret = _M_h.try_emplace(cend(), __k, std::forward<_Obj>(__obj));
      if (!__ret.second)
        __ret.first->second = std::forward<_Obj>(__obj);
      return __ret;
    }

    template <typename _Obj>
    pair<iterator, bool> insert_or_assign(key_type &&__k, _Obj &&__obj) {
      auto __ret =
          _M_h.try_emplace(cend(), std::move(__k), std::forward<_Obj>(__obj));
      if (!__ret.second)
        __ret.first->second = std::forward<_Obj>(__obj);
      return __ret;
    }
    template <typename _Obj>
    iterator insert_or_assign(const_iterator __hint, const key_type &__k,
                              _Obj &&__obj) {
      auto __ret = _M_h.try_emplace(__hint, __k, std::forward<_Obj>(__obj));
      if (!__ret.second)
        __ret.first->second = std::forward<_Obj>(__obj);
      return __ret.first;
    }

    template <typename _Obj>
    iterator insert_or_assign(const_iterator __hint, key_type &&__k,
                              _Obj &&__obj) {
      auto __ret =
          _M_h.try_emplace(__hint, std::move(__k), std::forward<_Obj>(__obj));
      if (!__ret.second)
        __ret.first->second = std::forward<_Obj>(__obj);
      return __ret.first;
    }
    iterator erase(const_iterator __position) { return _M_h.erase(__position); }

    iterator erase(iterator __position) { return _M_h.erase(__position); }
    size_type erase(const key_type &__x) { return _M_h.erase(__x); }
    iterator erase(const_iterator __first, const_iterator __last) {
      return _M_h.erase(__first, __last);
    }

    void clear() noexcept { _M_h.clear(); }
    void swap(unordered_map &__x) noexcept(noexcept(_M_h.swap(__x._M_h))) {
      _M_h.swap(__x._M_h);
    }

    template <typename, typename, typename>
    friend class std::_Hash_merge_helper;

    template <typename _H2, typename _P2>
    void merge(unordered_map<_Key, _Tp, _H2, _P2, _Alloc> &__source) {
      using _Merge_helper = _Hash_merge_helper<unordered_map, _H2, _P2>;
      _M_h._M_merge_unique(_Merge_helper::_S_get_table(__source));
    }

    template <typename _H2, typename _P2>
    void merge(unordered_map<_Key, _Tp, _H2, _P2, _Alloc> &&__source) {
      merge(__source);
    }

    template <typename _H2, typename _P2>
    void merge(unordered_multimap<_Key, _Tp, _H2, _P2, _Alloc> &__source) {
      using _Merge_helper = _Hash_merge_helper<unordered_map, _H2, _P2>;
      _M_h._M_merge_unique(_Merge_helper::_S_get_table(__source));
    }

    template <typename _H2, typename _P2>
    void merge(unordered_multimap<_Key, _Tp, _H2, _P2, _Alloc> &&__source) {
      merge(__source);
    }

    hasher hash_function() const { return _M_h.hash_function(); }

    key_equal key_eq() const { return _M_h.key_eq(); }
    iterator find(const key_type &__x) { return _M_h.find(__x); }

    template <typename _Kt>
    auto find(const _Kt &__x) -> decltype(_M_h._M_find_tr(__x)) {
      return _M_h._M_find_tr(__x);
    }

    const_iterator find(const key_type &__x) const { return _M_h.find(__x); }

    template <typename _Kt>
    auto find(const _Kt &__x) const -> decltype(_M_h._M_find_tr(__x)) {
      return _M_h._M_find_tr(__x);
    }
    size_type count(const key_type &__x) const { return _M_h.count(__x); }

    template <typename _Kt>
    auto count(const _Kt &__x) const -> decltype(_M_h._M_count_tr(__x)) {
      return _M_h._M_count_tr(__x);
    }
    bool contains(const key_type &__x) const {
      return _M_h.find(__x) != _M_h.end();
    }

    template <typename _Kt>
    auto contains(const _Kt &__x) const
        -> decltype(_M_h._M_find_tr(__x), void(), true) {
      return _M_h._M_find_tr(__x) != _M_h.end();
    }
    std::pair<iterator, iterator> equal_range(const key_type &__x) {
      return _M_h.equal_range(__x);
    }

    template <typename _Kt>
    auto equal_range(const _Kt &__x) -> decltype(_M_h._M_equal_range_tr(__x)) {
      return _M_h._M_equal_range_tr(__x);
    }

    std::pair<const_iterator, const_iterator>
    equal_range(const key_type &__x) const {
      return _M_h.equal_range(__x);
    }

    template <typename _Kt>
    auto equal_range(const _Kt &__x) const
        -> decltype(_M_h._M_equal_range_tr(__x)) {
      return _M_h._M_equal_range_tr(__x);
    }
    mapped_type &operator[](const key_type &__k) { return _M_h[__k]; }

    mapped_type &operator[](key_type &&__k) { return _M_h[std::move(__k)]; }
    mapped_type &at(const key_type &__k) { return _M_h.at(__k); }

    const mapped_type &at(const key_type &__k) const { return _M_h.at(__k); }

    size_type bucket_count() const noexcept { return _M_h.bucket_count(); }

    size_type max_bucket_count() const noexcept {
      return _M_h.max_bucket_count();
    }

    size_type bucket_size(size_type __n) const { return _M_h.bucket_size(__n); }

    size_type bucket(const key_type &__key) const { return _M_h.bucket(__key); }

    local_iterator begin(size_type __n) { return _M_h.begin(__n); }
    const_local_iterator begin(size_type __n) const { return _M_h.begin(__n); }

    const_local_iterator cbegin(size_type __n) const {
      return _M_h.cbegin(__n);
    }
    local_iterator end(size_type __n) { return _M_h.end(__n); }
    const_local_iterator end(size_type __n) const { return _M_h.end(__n); }

    const_local_iterator cend(size_type __n) const { return _M_h.cend(__n); }

    float load_factor() const noexcept { return _M_h.load_factor(); }

    float max_load_factor() const noexcept { return _M_h.max_load_factor(); }

    void max_load_factor(float __z) { _M_h.max_load_factor(__z); }
    void rehash(size_type __n) { _M_h.rehash(__n); }
    void reserve(size_type __n) { _M_h.reserve(__n); }

    template <typename _Key1, typename _Tp1, typename _Hash1, typename _Pred1,
              typename _Alloc1>
    friend bool
    operator==(const unordered_map<_Key1, _Tp1, _Hash1, _Pred1, _Alloc1> &,
               const unordered_map<_Key1, _Tp1, _Hash1, _Pred1, _Alloc1> &);
  };

  template <typename _InputIterator,
            typename _Hash = hash<__iter_key_t<_InputIterator>>,
            typename _Pred = equal_to<__iter_key_t<_InputIterator>>,
            typename _Allocator = allocator<__iter_to_alloc_t<_InputIterator>>,
            typename = _RequireInputIter<_InputIterator>,
            typename = _RequireNotAllocatorOrIntegral<_Hash>,
            typename = _RequireNotAllocator<_Pred>,
            typename = _RequireAllocator<_Allocator>>
  unordered_map(_InputIterator, _InputIterator,
                typename unordered_map<int, int>::size_type = {},
                _Hash = _Hash(), _Pred = _Pred(), _Allocator = _Allocator())
      -> unordered_map<__iter_key_t<_InputIterator>,
                       __iter_val_t<_InputIterator>, _Hash, _Pred, _Allocator>;

  template <typename _Key, typename _Tp, typename _Hash = hash<_Key>,
            typename _Pred = equal_to<_Key>,
            typename _Allocator = allocator<pair<const _Key, _Tp>>,
            typename = _RequireNotAllocatorOrIntegral<_Hash>,
            typename = _RequireNotAllocator<_Pred>,
            typename = _RequireAllocator<_Allocator>>
  unordered_map(initializer_list<pair<_Key, _Tp>>,
                typename unordered_map<int, int>::size_type = {},
                _Hash = _Hash(), _Pred = _Pred(), _Allocator = _Allocator())
      -> unordered_map<_Key, _Tp, _Hash, _Pred, _Allocator>;

  template <typename _InputIterator, typename _Allocator,
            typename = _RequireInputIter<_InputIterator>,
            typename = _RequireAllocator<_Allocator>>
  unordered_map(_InputIterator, _InputIterator,
                typename unordered_map<int, int>::size_type, _Allocator)
      -> unordered_map<__iter_key_t<_InputIterator>,
                       __iter_val_t<_InputIterator>,
                       hash<__iter_key_t<_InputIterator>>,
                       equal_to<__iter_key_t<_InputIterator>>, _Allocator>;

  template <typename _InputIterator, typename _Allocator,
            typename = _RequireInputIter<_InputIterator>,
            typename = _RequireAllocator<_Allocator>>
  unordered_map(_InputIterator, _InputIterator, _Allocator)
      -> unordered_map<__iter_key_t<_InputIterator>,
                       __iter_val_t<_InputIterator>,
                       hash<__iter_key_t<_InputIterator>>,
                       equal_to<__iter_key_t<_InputIterator>>, _Allocator>;

  template <typename _InputIterator, typename _Hash, typename _Allocator,
            typename = _RequireInputIter<_InputIterator>,
            typename = _RequireNotAllocatorOrIntegral<_Hash>,
            typename = _RequireAllocator<_Allocator>>
  unordered_map(_InputIterator, _InputIterator,
                typename unordered_map<int, int>::size_type, _Hash, _Allocator)
      -> unordered_map<__iter_key_t<_InputIterator>,
                       __iter_val_t<_InputIterator>, _Hash,
                       equal_to<__iter_key_t<_InputIterator>>, _Allocator>;

  template <typename _Key, typename _Tp, typename _Allocator,
            typename = _RequireAllocator<_Allocator>>
  unordered_map(initializer_list<pair<_Key, _Tp>>,
                typename unordered_map<int, int>::size_type, _Allocator)
      -> unordered_map<_Key, _Tp, hash<_Key>, equal_to<_Key>, _Allocator>;

  template <typename _Key, typename _Tp, typename _Allocator,
            typename = _RequireAllocator<_Allocator>>
  unordered_map(initializer_list<pair<_Key, _Tp>>, _Allocator)
      -> unordered_map<_Key, _Tp, hash<_Key>, equal_to<_Key>, _Allocator>;

  template <typename _Key, typename _Tp, typename _Hash, typename _Allocator,
            typename = _RequireNotAllocatorOrIntegral<_Hash>,
            typename = _RequireAllocator<_Allocator>>
  unordered_map(initializer_list<pair<_Key, _Tp>>,
                typename unordered_map<int, int>::size_type, _Hash, _Allocator)
      -> unordered_map<_Key, _Tp, _Hash, equal_to<_Key>, _Allocator>;
  template <typename _Key, typename _Tp, typename _Hash = hash<_Key>,
            typename _Pred = equal_to<_Key>,
            typename _Alloc = allocator<std::pair<const _Key, _Tp>>>
  class unordered_multimap {
    typedef __ummap_hashtable<_Key, _Tp, _Hash, _Pred, _Alloc> _Hashtable;
    _Hashtable _M_h;

  public:
    typedef typename _Hashtable::key_type key_type;
    typedef typename _Hashtable::value_type value_type;
    typedef typename _Hashtable::mapped_type mapped_type;
    typedef typename _Hashtable::hasher hasher;
    typedef typename _Hashtable::key_equal key_equal;
    typedef typename _Hashtable::allocator_type allocator_type;

    typedef typename _Hashtable::pointer pointer;
    typedef typename _Hashtable::const_pointer const_pointer;
    typedef typename _Hashtable::reference reference;
    typedef typename _Hashtable::const_reference const_reference;
    typedef typename _Hashtable::iterator iterator;
    typedef typename _Hashtable::const_iterator const_iterator;
    typedef typename _Hashtable::local_iterator local_iterator;
    typedef typename _Hashtable::const_local_iterator const_local_iterator;
    typedef typename _Hashtable::size_type size_type;
    typedef typename _Hashtable::difference_type difference_type;

    using node_type = typename _Hashtable::node_type;

    unordered_multimap() = default;
    explicit unordered_multimap(size_type __n, const hasher &__hf = hasher(),
                                const key_equal &__eql = key_equal(),
                                const allocator_type &__a = allocator_type())
        : _M_h(__n, __hf, __eql, __a) {}
    template <typename _InputIterator>
    unordered_multimap(_InputIterator __first, _InputIterator __last,
                       size_type __n = 0, const hasher &__hf = hasher(),
                       const key_equal &__eql = key_equal(),
                       const allocator_type &__a = allocator_type())
        : _M_h(__first, __last, __n, __hf, __eql, __a) {}

    unordered_multimap(const unordered_multimap &) = default;

    unordered_multimap(unordered_multimap &&) = default;

    explicit unordered_multimap(const allocator_type &__a) : _M_h(__a) {}

    unordered_multimap(const unordered_multimap &__ummap,
                       const allocator_type &__a)
        : _M_h(__ummap._M_h, __a) {}

    unordered_multimap(
        unordered_multimap &&__ummap,
        const allocator_type
            &__a) noexcept(noexcept(_Hashtable(std::move(__ummap._M_h), __a)))
        : _M_h(std::move(__ummap._M_h), __a) {}
    unordered_multimap(initializer_list<value_type> __l, size_type __n = 0,
                       const hasher &__hf = hasher(),
                       const key_equal &__eql = key_equal(),
                       const allocator_type &__a = allocator_type())
        : _M_h(__l, __n, __hf, __eql, __a) {}

    unordered_multimap(size_type __n, const allocator_type &__a)
        : unordered_multimap(__n, hasher(), key_equal(), __a) {}

    unordered_multimap(size_type __n, const hasher &__hf,
                       const allocator_type &__a)
        : unordered_multimap(__n, __hf, key_equal(), __a) {}

    template <typename _InputIterator>
    unordered_multimap(_InputIterator __first, _InputIterator __last,
                       size_type __n, const allocator_type &__a)
        : unordered_multimap(__first, __last, __n, hasher(), key_equal(), __a) {
    }

    template <typename _InputIterator>
    unordered_multimap(_InputIterator __first, _InputIterator __last,
                       size_type __n, const hasher &__hf,
                       const allocator_type &__a)
        : unordered_multimap(__first, __last, __n, __hf, key_equal(), __a) {}

    unordered_multimap(initializer_list<value_type> __l, size_type __n,
                       const allocator_type &__a)
        : unordered_multimap(__l, __n, hasher(), key_equal(), __a) {}

    unordered_multimap(initializer_list<value_type> __l, size_type __n,
                       const hasher &__hf, const allocator_type &__a)
        : unordered_multimap(__l, __n, __hf, key_equal(), __a) {}

    unordered_multimap &operator=(const unordered_multimap &) = default;

    unordered_multimap &operator=(unordered_multimap &&) = default;
    unordered_multimap &operator=(initializer_list<value_type> __l) {
      _M_h = __l;
      return *this;
    }

    allocator_type get_allocator() const noexcept {
      return _M_h.get_allocator();
    }

    [[__nodiscard__]] bool empty() const noexcept { return _M_h.empty(); }

    size_type size() const noexcept { return _M_h.size(); }

    size_type max_size() const noexcept { return _M_h.max_size(); }

    iterator begin() noexcept { return _M_h.begin(); }

    const_iterator begin() const noexcept { return _M_h.begin(); }

    const_iterator cbegin() const noexcept { return _M_h.begin(); }

    iterator end() noexcept { return _M_h.end(); }

    const_iterator end() const noexcept { return _M_h.end(); }

    const_iterator cend() const noexcept { return _M_h.end(); }
    template <typename... _Args> iterator emplace(_Args &&...__args) {
      return _M_h.emplace(std::forward<_Args>(__args)...);
    }
    template <typename... _Args>
    iterator emplace_hint(const_iterator __pos, _Args &&...__args) {
      return _M_h.emplace_hint(__pos, std::forward<_Args>(__args)...);
    }
    iterator insert(const value_type &__x) { return _M_h.insert(__x); }

    iterator insert(value_type &&__x) { return _M_h.insert(std::move(__x)); }

    template <typename _Pair>
    __enable_if_t<is_constructible<value_type, _Pair &&>::value, iterator>
    insert(_Pair &&__x) {
      return _M_h.emplace(std::forward<_Pair>(__x));
    }
    iterator insert(const_iterator __hint, const value_type &__x) {
      return _M_h.insert(__hint, __x);
    }

    iterator insert(const_iterator __hint, value_type &&__x) {
      return _M_h.insert(__hint, std::move(__x));
    }

    template <typename _Pair>
    __enable_if_t<is_constructible<value_type, _Pair &&>::value, iterator>
    insert(const_iterator __hint, _Pair &&__x) {
      return _M_h.emplace_hint(__hint, std::forward<_Pair>(__x));
    }
    template <typename _InputIterator>
    void insert(_InputIterator __first, _InputIterator __last) {
      _M_h.insert(__first, __last);
    }
    void insert(initializer_list<value_type> __l) { _M_h.insert(__l); }

    node_type extract(const_iterator __pos) {
      do {
        if (std::__is_constant_evaluated())
          if (__builtin_expect(!bool(__pos != end()), false))
            std::__glibcxx_assert_fail();
      } while (false);
      return _M_h.extract(__pos);
    }

    node_type extract(const key_type &__key) { return _M_h.extract(__key); }

    iterator insert(node_type &&__nh) {
      return _M_h._M_reinsert_node_multi(cend(), std::move(__nh));
    }

    iterator insert(const_iterator __hint, node_type &&__nh) {
      return _M_h._M_reinsert_node_multi(__hint, std::move(__nh));
    }
    iterator erase(const_iterator __position) { return _M_h.erase(__position); }

    iterator erase(iterator __position) { return _M_h.erase(__position); }
    size_type erase(const key_type &__x) { return _M_h.erase(__x); }
    iterator erase(const_iterator __first, const_iterator __last) {
      return _M_h.erase(__first, __last);
    }

    void clear() noexcept { _M_h.clear(); }
    void swap(unordered_multimap &__x) noexcept(noexcept(_M_h.swap(__x._M_h))) {
      _M_h.swap(__x._M_h);
    }

    template <typename, typename, typename>
    friend class std::_Hash_merge_helper;

    template <typename _H2, typename _P2>
    void merge(unordered_multimap<_Key, _Tp, _H2, _P2, _Alloc> &__source) {
      using _Merge_helper = _Hash_merge_helper<unordered_multimap, _H2, _P2>;
      _M_h._M_merge_multi(_Merge_helper::_S_get_table(__source));
    }

    template <typename _H2, typename _P2>
    void merge(unordered_multimap<_Key, _Tp, _H2, _P2, _Alloc> &&__source) {
      merge(__source);
    }

    template <typename _H2, typename _P2>
    void merge(unordered_map<_Key, _Tp, _H2, _P2, _Alloc> &__source) {
      using _Merge_helper = _Hash_merge_helper<unordered_multimap, _H2, _P2>;
      _M_h._M_merge_multi(_Merge_helper::_S_get_table(__source));
    }

    template <typename _H2, typename _P2>
    void merge(unordered_map<_Key, _Tp, _H2, _P2, _Alloc> &&__source) {
      merge(__source);
    }

    hasher hash_function() const { return _M_h.hash_function(); }

    key_equal key_eq() const { return _M_h.key_eq(); }
    iterator find(const key_type &__x) { return _M_h.find(__x); }

    template <typename _Kt>
    auto find(const _Kt &__x) -> decltype(_M_h._M_find_tr(__x)) {
      return _M_h._M_find_tr(__x);
    }

    const_iterator find(const key_type &__x) const { return _M_h.find(__x); }

    template <typename _Kt>
    auto find(const _Kt &__x) const -> decltype(_M_h._M_find_tr(__x)) {
      return _M_h._M_find_tr(__x);
    }
    size_type count(const key_type &__x) const { return _M_h.count(__x); }

    template <typename _Kt>
    auto count(const _Kt &__x) const -> decltype(_M_h._M_count_tr(__x)) {
      return _M_h._M_count_tr(__x);
    }
    bool contains(const key_type &__x) const {
      return _M_h.find(__x) != _M_h.end();
    }

    template <typename _Kt>
    auto contains(const _Kt &__x) const
        -> decltype(_M_h._M_find_tr(__x), void(), true) {
      return _M_h._M_find_tr(__x) != _M_h.end();
    }
    std::pair<iterator, iterator> equal_range(const key_type &__x) {
      return _M_h.equal_range(__x);
    }

    template <typename _Kt>
    auto equal_range(const _Kt &__x) -> decltype(_M_h._M_equal_range_tr(__x)) {
      return _M_h._M_equal_range_tr(__x);
    }

    std::pair<const_iterator, const_iterator>
    equal_range(const key_type &__x) const {
      return _M_h.equal_range(__x);
    }

    template <typename _Kt>
    auto equal_range(const _Kt &__x) const
        -> decltype(_M_h._M_equal_range_tr(__x)) {
      return _M_h._M_equal_range_tr(__x);
    }

    size_type bucket_count() const noexcept { return _M_h.bucket_count(); }

    size_type max_bucket_count() const noexcept {
      return _M_h.max_bucket_count();
    }

    size_type bucket_size(size_type __n) const { return _M_h.bucket_size(__n); }

    size_type bucket(const key_type &__key) const { return _M_h.bucket(__key); }

    local_iterator begin(size_type __n) { return _M_h.begin(__n); }
    const_local_iterator begin(size_type __n) const { return _M_h.begin(__n); }

    const_local_iterator cbegin(size_type __n) const {
      return _M_h.cbegin(__n);
    }
    local_iterator end(size_type __n) { return _M_h.end(__n); }
    const_local_iterator end(size_type __n) const { return _M_h.end(__n); }

    const_local_iterator cend(size_type __n) const { return _M_h.cend(__n); }

    float load_factor() const noexcept { return _M_h.load_factor(); }

    float max_load_factor() const noexcept { return _M_h.max_load_factor(); }

    void max_load_factor(float __z) { _M_h.max_load_factor(__z); }
    void rehash(size_type __n) { _M_h.rehash(__n); }
    void reserve(size_type __n) { _M_h.reserve(__n); }

    template <typename _Key1, typename _Tp1, typename _Hash1, typename _Pred1,
              typename _Alloc1>
    friend bool operator==(
        const unordered_multimap<_Key1, _Tp1, _Hash1, _Pred1, _Alloc1> &,
        const unordered_multimap<_Key1, _Tp1, _Hash1, _Pred1, _Alloc1> &);
  };

  template <typename _InputIterator,
            typename _Hash = hash<__iter_key_t<_InputIterator>>,
            typename _Pred = equal_to<__iter_key_t<_InputIterator>>,
            typename _Allocator = allocator<__iter_to_alloc_t<_InputIterator>>,
            typename = _RequireInputIter<_InputIterator>,
            typename = _RequireNotAllocatorOrIntegral<_Hash>,
            typename = _RequireNotAllocator<_Pred>,
            typename = _RequireAllocator<_Allocator>>
  unordered_multimap(_InputIterator, _InputIterator,
                     unordered_multimap<int, int>::size_type = {},
                     _Hash = _Hash(), _Pred = _Pred(),
                     _Allocator = _Allocator())
      -> unordered_multimap<__iter_key_t<_InputIterator>,
                            __iter_val_t<_InputIterator>, _Hash, _Pred,
                            _Allocator>;

  template <typename _Key, typename _Tp, typename _Hash = hash<_Key>,
            typename _Pred = equal_to<_Key>,
            typename _Allocator = allocator<pair<const _Key, _Tp>>,
            typename = _RequireNotAllocatorOrIntegral<_Hash>,
            typename = _RequireNotAllocator<_Pred>,
            typename = _RequireAllocator<_Allocator>>
  unordered_multimap(initializer_list<pair<_Key, _Tp>>,
                     unordered_multimap<int, int>::size_type = {},
                     _Hash = _Hash(), _Pred = _Pred(),
                     _Allocator = _Allocator())
      -> unordered_multimap<_Key, _Tp, _Hash, _Pred, _Allocator>;

  template <typename _InputIterator, typename _Allocator,
            typename = _RequireInputIter<_InputIterator>,
            typename = _RequireAllocator<_Allocator>>
  unordered_multimap(_InputIterator, _InputIterator,
                     unordered_multimap<int, int>::size_type, _Allocator)
      -> unordered_multimap<__iter_key_t<_InputIterator>,
                            __iter_val_t<_InputIterator>,
                            hash<__iter_key_t<_InputIterator>>,
                            equal_to<__iter_key_t<_InputIterator>>, _Allocator>;

  template <typename _InputIterator, typename _Allocator,
            typename = _RequireInputIter<_InputIterator>,
            typename = _RequireAllocator<_Allocator>>
  unordered_multimap(_InputIterator, _InputIterator, _Allocator)
      -> unordered_multimap<__iter_key_t<_InputIterator>,
                            __iter_val_t<_InputIterator>,
                            hash<__iter_key_t<_InputIterator>>,
                            equal_to<__iter_key_t<_InputIterator>>, _Allocator>;

  template <typename _InputIterator, typename _Hash, typename _Allocator,
            typename = _RequireInputIter<_InputIterator>,
            typename = _RequireNotAllocatorOrIntegral<_Hash>,
            typename = _RequireAllocator<_Allocator>>
  unordered_multimap(_InputIterator, _InputIterator,
                     unordered_multimap<int, int>::size_type, _Hash, _Allocator)
      -> unordered_multimap<__iter_key_t<_InputIterator>,
                            __iter_val_t<_InputIterator>, _Hash,
                            equal_to<__iter_key_t<_InputIterator>>, _Allocator>;

  template <typename _Key, typename _Tp, typename _Allocator,
            typename = _RequireAllocator<_Allocator>>
  unordered_multimap(initializer_list<pair<_Key, _Tp>>,
                     unordered_multimap<int, int>::size_type, _Allocator)
      -> unordered_multimap<_Key, _Tp, hash<_Key>, equal_to<_Key>, _Allocator>;

  template <typename _Key, typename _Tp, typename _Allocator,
            typename = _RequireAllocator<_Allocator>>
  unordered_multimap(initializer_list<pair<_Key, _Tp>>, _Allocator)
      -> unordered_multimap<_Key, _Tp, hash<_Key>, equal_to<_Key>, _Allocator>;

  template <typename _Key, typename _Tp, typename _Hash, typename _Allocator,
            typename = _RequireNotAllocatorOrIntegral<_Hash>,
            typename = _RequireAllocator<_Allocator>>
  unordered_multimap(initializer_list<pair<_Key, _Tp>>,
                     unordered_multimap<int, int>::size_type, _Hash, _Allocator)
      -> unordered_multimap<_Key, _Tp, _Hash, equal_to<_Key>, _Allocator>;

  template <class _Key, class _Tp, class _Hash, class _Pred, class _Alloc>
  inline void swap(unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc> & __x,
                   unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc> &
                       __y) noexcept(noexcept(__x.swap(__y))) {
    __x.swap(__y);
  }

  template <class _Key, class _Tp, class _Hash, class _Pred, class _Alloc>
  inline void swap(unordered_multimap<_Key, _Tp, _Hash, _Pred, _Alloc> & __x,
                   unordered_multimap<_Key, _Tp, _Hash, _Pred, _Alloc> &
                       __y) noexcept(noexcept(__x.swap(__y))) {
    __x.swap(__y);
  }

  template <class _Key, class _Tp, class _Hash, class _Pred, class _Alloc>
  inline bool operator==(
      const unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc> &__x,
      const unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc> &__y) {
    return __x._M_h._M_equal(__y._M_h);
  }
  template <class _Key, class _Tp, class _Hash, class _Pred, class _Alloc>
  inline bool operator==(
      const unordered_multimap<_Key, _Tp, _Hash, _Pred, _Alloc> &__x,
      const unordered_multimap<_Key, _Tp, _Hash, _Pred, _Alloc> &__y) {
    return __x._M_h._M_equal(__y._M_h);
  }

  template <typename _Key, typename _Val, typename _Hash1, typename _Eq1,
            typename _Alloc, typename _Hash2, typename _Eq2>
  struct _Hash_merge_helper<
      std::unordered_map<_Key, _Val, _Hash1, _Eq1, _Alloc>, _Hash2, _Eq2> {
  private:
    template <typename... _Tp> using unordered_map = std::unordered_map<_Tp...>;
    template <typename... _Tp>
    using unordered_multimap = std::unordered_multimap<_Tp...>;

    friend unordered_map<_Key, _Val, _Hash1, _Eq1, _Alloc>;

    static auto &
    _S_get_table(unordered_map<_Key, _Val, _Hash2, _Eq2, _Alloc> &__map) {
      return __map._M_h;
    }

    static auto &
    _S_get_table(unordered_multimap<_Key, _Val, _Hash2, _Eq2, _Alloc> &__map) {
      return __map._M_h;
    }
  };

  template <typename _Key, typename _Val, typename _Hash1, typename _Eq1,
            typename _Alloc, typename _Hash2, typename _Eq2>
  struct _Hash_merge_helper<
      std::unordered_multimap<_Key, _Val, _Hash1, _Eq1, _Alloc>, _Hash2, _Eq2> {
  private:
    template <typename... _Tp> using unordered_map = std::unordered_map<_Tp...>;
    template <typename... _Tp>
    using unordered_multimap = std::unordered_multimap<_Tp...>;

    friend unordered_multimap<_Key, _Val, _Hash1, _Eq1, _Alloc>;

    static auto &
    _S_get_table(unordered_map<_Key, _Val, _Hash2, _Eq2, _Alloc> &__map) {
      return __map._M_h;
    }

    static auto &
    _S_get_table(unordered_multimap<_Key, _Val, _Hash2, _Eq2, _Alloc> &__map) {
      return __map._M_h;
    }
  };

} // namespace std

namespace std __attribute__((__visibility__("default"))) {

  template <typename _Container>
  [[__nodiscard__, __gnu__::__always_inline__]]
  inline constexpr auto begin(_Container & __cont) -> decltype(__cont.begin()) {
    return __cont.begin();
  }

  template <typename _Container>
  [[__nodiscard__, __gnu__::__always_inline__]]
  inline constexpr auto begin(const _Container &__cont)
      -> decltype(__cont.begin()) {
    return __cont.begin();
  }

  template <typename _Container>
  [[__nodiscard__, __gnu__::__always_inline__]]
  inline constexpr auto end(_Container & __cont) -> decltype(__cont.end()) {
    return __cont.end();
  }

  template <typename _Container>
  [[__nodiscard__, __gnu__::__always_inline__]]
  inline constexpr auto end(const _Container &__cont)
      -> decltype(__cont.end()) {
    return __cont.end();
  }

  template <typename _Tp, size_t _Nm>
  [[__nodiscard__, __gnu__::__always_inline__]]
  inline constexpr _Tp *begin(_Tp(&__arr)[_Nm]) noexcept {
    return __arr;
  }

  template <typename _Tp, size_t _Nm>
  [[__nodiscard__, __gnu__::__always_inline__]]
  inline constexpr _Tp *end(_Tp(&__arr)[_Nm]) noexcept {
    return __arr + _Nm;
  }

  template <typename _Tp> class valarray;

  template <typename _Tp> _Tp *begin(valarray<_Tp> &) noexcept;
  template <typename _Tp> const _Tp *begin(const valarray<_Tp> &) noexcept;
  template <typename _Tp> _Tp *end(valarray<_Tp> &) noexcept;
  template <typename _Tp> const _Tp *end(const valarray<_Tp> &) noexcept;

  template <typename _Container>
  [[__nodiscard__, __gnu__::__always_inline__]]
  constexpr auto cbegin(const _Container &__cont) noexcept(
      noexcept(std::begin(__cont))) -> decltype(std::begin(__cont)) {
    return std::begin(__cont);
  }

  template <typename _Container>
  [[__nodiscard__, __gnu__::__always_inline__]]
  constexpr auto cend(const _Container &__cont) noexcept(
      noexcept(std::end(__cont))) -> decltype(std::end(__cont)) {
    return std::end(__cont);
  }

  template <typename _Container>
  [[__nodiscard__, __gnu__::__always_inline__]]
  inline constexpr auto rbegin(_Container & __cont)
      -> decltype(__cont.rbegin()) {
    return __cont.rbegin();
  }

  template <typename _Container>
  [[__nodiscard__, __gnu__::__always_inline__]]
  inline constexpr auto rbegin(const _Container &__cont)
      -> decltype(__cont.rbegin()) {
    return __cont.rbegin();
  }

  template <typename _Container>
  [[__nodiscard__, __gnu__::__always_inline__]]
  inline constexpr auto rend(_Container & __cont) -> decltype(__cont.rend()) {
    return __cont.rend();
  }

  template <typename _Container>
  [[__nodiscard__, __gnu__::__always_inline__]]
  inline constexpr auto rend(const _Container &__cont)
      -> decltype(__cont.rend()) {
    return __cont.rend();
  }

  template <typename _Tp, size_t _Nm>
  [[__nodiscard__]]
  inline constexpr reverse_iterator<_Tp *> rbegin(_Tp(&__arr)[_Nm]) noexcept {
    return reverse_iterator<_Tp *>(__arr + _Nm);
  }

  template <typename _Tp, size_t _Nm>
  [[__nodiscard__]]
  inline constexpr reverse_iterator<_Tp *> rend(_Tp(&__arr)[_Nm]) noexcept {
    return reverse_iterator<_Tp *>(__arr);
  }

  template <typename _Tp>
  [[__nodiscard__]]
  inline constexpr reverse_iterator<const _Tp *> rbegin(
      initializer_list<_Tp> __il) noexcept {
    return reverse_iterator<const _Tp *>(__il.end());
  }

  template <typename _Tp>
  [[__nodiscard__]]
  inline constexpr reverse_iterator<const _Tp *> rend(
      initializer_list<_Tp> __il) noexcept {
    return reverse_iterator<const _Tp *>(__il.begin());
  }

  template <typename _Container>
  [[__nodiscard__, __gnu__::__always_inline__]]
  inline constexpr auto crbegin(const _Container &__cont)
      -> decltype(std::rbegin(__cont)) {
    return std::rbegin(__cont);
  }

  template <typename _Container>
  [[__nodiscard__, __gnu__::__always_inline__]]
  inline constexpr auto crend(const _Container &__cont)
      -> decltype(std::rend(__cont)) {
    return std::rend(__cont);
  }
  template <typename _Container>
  [[nodiscard, __gnu__::__always_inline__]]
  constexpr auto size(const _Container &__cont) noexcept(
      noexcept(__cont.size())) -> decltype(__cont.size()) {
    return __cont.size();
  }

  template <typename _Tp, size_t _Nm>
  [[nodiscard, __gnu__::__always_inline__]]
  constexpr size_t size(const _Tp(&)[_Nm]) noexcept {
    return _Nm;
  }

  template <typename _Container>
  [[nodiscard, __gnu__::__always_inline__]]
  constexpr auto empty(const _Container &__cont) noexcept(
      noexcept(__cont.empty())) -> decltype(__cont.empty()) {
    return __cont.empty();
  }

  template <typename _Tp, size_t _Nm>
  [[nodiscard, __gnu__::__always_inline__]]
  constexpr bool empty(const _Tp(&)[_Nm]) noexcept {
    return false;
  }

  template <typename _Tp>
  [[nodiscard, __gnu__::__always_inline__]]
  constexpr bool empty(initializer_list<_Tp> __il) noexcept {
    return __il.size() == 0;
  }

  template <typename _Container>
  [[nodiscard, __gnu__::__always_inline__]]
  constexpr auto data(_Container & __cont) noexcept(noexcept(__cont.data()))
      -> decltype(__cont.data()) {
    return __cont.data();
  }

  template <typename _Container>
  [[nodiscard, __gnu__::__always_inline__]]
  constexpr auto data(const _Container &__cont) noexcept(
      noexcept(__cont.data())) -> decltype(__cont.data()) {
    return __cont.data();
  }

  template <typename _Tp, size_t _Nm>
  [[nodiscard, __gnu__::__always_inline__]]
  constexpr _Tp *data(_Tp(&__array)[_Nm]) noexcept {
    return __array;
  }

  template <typename _Tp>
  [[nodiscard, __gnu__::__always_inline__]]
  constexpr const _Tp *data(initializer_list<_Tp> __il) noexcept {
    return __il.begin();
  }

  template <typename _Container>
  [[nodiscard, __gnu__::__always_inline__]]
  constexpr auto ssize(const _Container &__cont) noexcept(
      noexcept(__cont.size()))
      -> common_type_t<ptrdiff_t, make_signed_t<decltype(__cont.size())>> {
    using type = make_signed_t<decltype(__cont.size())>;
    return static_cast<common_type_t<ptrdiff_t, type>>(__cont.size());
  }

  template <typename _Tp, ptrdiff_t _Num>
  [[nodiscard, __gnu__::__always_inline__]]
  constexpr ptrdiff_t ssize(const _Tp(&)[_Num]) noexcept {
    return _Num;
  }

} // namespace std

namespace std {

namespace __detail {
template <typename _Container, typename _UnsafeContainer, typename _Predicate>
typename _Container::size_type __erase_nodes_if(_Container &__cont,
                                                _UnsafeContainer &__ucont,
                                                _Predicate __pred) {
  typename _Container::size_type __num = 0;
  for (auto __iter = __ucont.begin(), __last = __ucont.end();
       __iter != __last;) {
    if (__pred(*__iter)) {
      __iter = __cont.erase(__iter);
      ++__num;
    } else
      ++__iter;
  }
  return __num;
}
} // namespace __detail

} // namespace std

typedef long int ptrdiff_t;
typedef long unsigned int size_t;
typedef struct {
  long long __max_align_ll __attribute__((__aligned__(__alignof__(long long))));
  long double __max_align_ld
      __attribute__((__aligned__(__alignof__(long double))));
} max_align_t;

typedef decltype(nullptr) nullptr_t;

extern "C++" {

namespace std {

using ::max_align_t;
}

namespace std {

enum class byte : unsigned char {};

template <typename _IntegerType> struct __byte_operand {};
template <> struct __byte_operand<bool> {
  using __type = byte;
};
template <> struct __byte_operand<char> {
  using __type = byte;
};
template <> struct __byte_operand<signed char> {
  using __type = byte;
};
template <> struct __byte_operand<unsigned char> {
  using __type = byte;
};
template <> struct __byte_operand<wchar_t> {
  using __type = byte;
};

template <> struct __byte_operand<char8_t> {
  using __type = byte;
};

template <> struct __byte_operand<char16_t> {
  using __type = byte;
};
template <> struct __byte_operand<char32_t> {
  using __type = byte;
};
template <> struct __byte_operand<short> {
  using __type = byte;
};
template <> struct __byte_operand<unsigned short> {
  using __type = byte;
};
template <> struct __byte_operand<int> {
  using __type = byte;
};
template <> struct __byte_operand<unsigned int> {
  using __type = byte;
};
template <> struct __byte_operand<long> {
  using __type = byte;
};
template <> struct __byte_operand<unsigned long> {
  using __type = byte;
};
template <> struct __byte_operand<long long> {
  using __type = byte;
};
template <> struct __byte_operand<unsigned long long> {
  using __type = byte;
};

template <> struct __byte_operand<__int128> {
  using __type = byte;
};
template <> struct __byte_operand<unsigned __int128> {
  using __type = byte;
};
template <typename _IntegerType>
struct __byte_operand<const _IntegerType> : __byte_operand<_IntegerType> {};
template <typename _IntegerType>
struct __byte_operand<volatile _IntegerType> : __byte_operand<_IntegerType> {};
template <typename _IntegerType>
struct __byte_operand<const volatile _IntegerType>
    : __byte_operand<_IntegerType> {};

template <typename _IntegerType>
using __byte_op_t = typename __byte_operand<_IntegerType>::__type;

template <typename _IntegerType>
[[__gnu__::__always_inline__]]
constexpr __byte_op_t<_IntegerType> operator<<(byte __b,
                                               _IntegerType __shift) noexcept {
  return (byte)(unsigned char)((unsigned)__b << __shift);
}

template <typename _IntegerType>
[[__gnu__::__always_inline__]]
constexpr __byte_op_t<_IntegerType> operator>>(byte __b,
                                               _IntegerType __shift) noexcept {
  return (byte)(unsigned char)((unsigned)__b >> __shift);
}

[[__gnu__::__always_inline__]]
constexpr byte operator|(byte __l, byte __r) noexcept {
  return (byte)(unsigned char)((unsigned)__l | (unsigned)__r);
}

[[__gnu__::__always_inline__]]
constexpr byte operator&(byte __l, byte __r) noexcept {
  return (byte)(unsigned char)((unsigned)__l & (unsigned)__r);
}

[[__gnu__::__always_inline__]]
constexpr byte operator^(byte __l, byte __r) noexcept {
  return (byte)(unsigned char)((unsigned)__l ^ (unsigned)__r);
}

[[__gnu__::__always_inline__]]
constexpr byte operator~(byte __b) noexcept {
  return (byte)(unsigned char)~(unsigned)__b;
}

template <typename _IntegerType>
[[__gnu__::__always_inline__]]
constexpr __byte_op_t<_IntegerType> &
operator<<=(byte &__b, _IntegerType __shift) noexcept {
  return __b = __b << __shift;
}

template <typename _IntegerType>
[[__gnu__::__always_inline__]]
constexpr __byte_op_t<_IntegerType> &
operator>>=(byte &__b, _IntegerType __shift) noexcept {
  return __b = __b >> __shift;
}

[[__gnu__::__always_inline__]]
constexpr byte &operator|=(byte &__l, byte __r) noexcept {
  return __l = __l | __r;
}

[[__gnu__::__always_inline__]]
constexpr byte &operator&=(byte &__l, byte __r) noexcept {
  return __l = __l & __r;
}

[[__gnu__::__always_inline__]]
constexpr byte &operator^=(byte &__l, byte __r) noexcept {
  return __l = __l ^ __r;
}

template <typename _IntegerType>
[[nodiscard, __gnu__::__always_inline__]]
constexpr _IntegerType to_integer(__byte_op_t<_IntegerType> __b) noexcept {
  return _IntegerType(__b);
}

} // namespace std
}

namespace std __attribute__((__visibility__("default"))) {

  template <typename _Tp>
  concept _Std_pair = __is_pair<remove_cv_t<_Tp>>;

  template <typename _Tp, typename _Alloc, typename... _Args>
  constexpr auto uses_allocator_construction_args(const _Alloc &__a,
                                                  _Args &&...__args) noexcept
    requires(!_Std_pair<_Tp>)
  {
    if constexpr (uses_allocator_v<remove_cv_t<_Tp>, _Alloc>) {
      if constexpr (is_constructible_v<_Tp, allocator_arg_t, const _Alloc &,
                                       _Args...>) {
        return tuple<allocator_arg_t, const _Alloc &, _Args &&...>(
            allocator_arg, __a, std::forward<_Args>(__args)...);
      } else {
        static_assert(is_constructible_v<_Tp, _Args..., const _Alloc &>,
                      "construction with an allocator must be possible"
                      " if uses_allocator is true");

        return tuple<_Args &&..., const _Alloc &>(
            std::forward<_Args>(__args)..., __a);
      }
    } else {
      static_assert(is_constructible_v<_Tp, _Args...>);

      return tuple<_Args &&...>(std::forward<_Args>(__args)...);
    }
  }

  template <_Std_pair _Tp, typename _Alloc, typename _Tuple1, typename _Tuple2>
  constexpr auto uses_allocator_construction_args(
      const _Alloc &__a, piecewise_construct_t, _Tuple1 &&__x,
      _Tuple2 &&__y) noexcept;

  template <_Std_pair _Tp, typename _Alloc>
  constexpr auto uses_allocator_construction_args(const _Alloc &) noexcept;

  template <_Std_pair _Tp, typename _Alloc, typename _Up, typename _Vp>
  constexpr auto uses_allocator_construction_args(const _Alloc &, _Up &&,
                                                  _Vp &&) noexcept;

  template <_Std_pair _Tp, typename _Alloc, typename _Up, typename _Vp>
  constexpr auto uses_allocator_construction_args(
      const _Alloc &, const pair<_Up, _Vp> &) noexcept;

  template <_Std_pair _Tp, typename _Alloc, typename _Up, typename _Vp>
  constexpr auto uses_allocator_construction_args(const _Alloc &,
                                                  pair<_Up, _Vp> &&) noexcept;
  template <_Std_pair _Tp, typename _Alloc, typename _Tuple1, typename _Tuple2>
  constexpr auto uses_allocator_construction_args(
      const _Alloc &__a, piecewise_construct_t, _Tuple1 &&__x,
      _Tuple2 &&__y) noexcept {
    using _Tp1 = typename _Tp::first_type;
    using _Tp2 = typename _Tp::second_type;

    return std::make_tuple(
        piecewise_construct,
        std::apply(
            [&__a](auto &&...__args1) {
              return std::uses_allocator_construction_args<_Tp1>(
                  __a, std::forward<decltype(__args1)>(__args1)...);
            },
            std::forward<_Tuple1>(__x)),
        std::apply(
            [&__a](auto &&...__args2) {
              return std::uses_allocator_construction_args<_Tp2>(
                  __a, std::forward<decltype(__args2)>(__args2)...);
            },
            std::forward<_Tuple2>(__y)));
  }

  template <_Std_pair _Tp, typename _Alloc>
  constexpr auto uses_allocator_construction_args(const _Alloc &__a) noexcept {
    using _Tp1 = typename _Tp::first_type;
    using _Tp2 = typename _Tp::second_type;

    return std::make_tuple(piecewise_construct,
                           std::uses_allocator_construction_args<_Tp1>(__a),
                           std::uses_allocator_construction_args<_Tp2>(__a));
  }

  template <_Std_pair _Tp, typename _Alloc, typename _Up, typename _Vp>
  constexpr auto uses_allocator_construction_args(const _Alloc &__a, _Up &&__u,
                                                  _Vp &&__v) noexcept {
    using _Tp1 = typename _Tp::first_type;
    using _Tp2 = typename _Tp::second_type;

    return std::make_tuple(piecewise_construct,
                           std::uses_allocator_construction_args<_Tp1>(
                               __a, std::forward<_Up>(__u)),
                           std::uses_allocator_construction_args<_Tp2>(
                               __a, std::forward<_Vp>(__v)));
  }

  template <_Std_pair _Tp, typename _Alloc, typename _Up, typename _Vp>
  constexpr auto uses_allocator_construction_args(
      const _Alloc &__a, const pair<_Up, _Vp> &__pr) noexcept {
    using _Tp1 = typename _Tp::first_type;
    using _Tp2 = typename _Tp::second_type;

    return std::make_tuple(
        piecewise_construct,
        std::uses_allocator_construction_args<_Tp1>(__a, __pr.first),
        std::uses_allocator_construction_args<_Tp2>(__a, __pr.second));
  }

  template <_Std_pair _Tp, typename _Alloc, typename _Up, typename _Vp>
  constexpr auto uses_allocator_construction_args(
      const _Alloc &__a, pair<_Up, _Vp> &&__pr) noexcept {
    using _Tp1 = typename _Tp::first_type;
    using _Tp2 = typename _Tp::second_type;

    return std::make_tuple(piecewise_construct,
                           std::uses_allocator_construction_args<_Tp1>(
                               __a, std::get<0>(std::move(__pr))),
                           std::uses_allocator_construction_args<_Tp2>(
                               __a, std::get<1>(std::move(__pr))));
  }
  template <typename _Tp, typename _Alloc, typename... _Args>
  constexpr _Tp make_obj_using_allocator(const _Alloc &__a, _Args &&...__args) {
    return std::make_from_tuple<_Tp>(std::uses_allocator_construction_args<_Tp>(
        __a, std::forward<_Args>(__args)...));
  }

  template <typename _Tp, typename _Alloc, typename... _Args>
  constexpr _Tp *uninitialized_construct_using_allocator(
      _Tp * __p, const _Alloc &__a, _Args &&...__args) {
    return std::apply(
        [&](auto &&...__xs) {
          return std::construct_at(__p, std::forward<decltype(__xs)>(__xs)...);
        },
        std::uses_allocator_construction_args<_Tp>(
            __a, std::forward<_Args>(__args)...));
  }

} // namespace std
namespace std __attribute__((__visibility__("default"))) {

  namespace pmr {

  class memory_resource {
    static constexpr size_t _S_max_align = alignof(max_align_t);

  public:
    memory_resource() = default;
    memory_resource(const memory_resource &) = default;
    virtual ~memory_resource();

    memory_resource &operator=(const memory_resource &) = default;

    [[nodiscard]]
    void *allocate(size_t __bytes, size_t __alignment = _S_max_align)
        __attribute__((__returns_nonnull__, __alloc_size__(2),
                       __alloc_align__(3))) {
      return ::operator new(__bytes, do_allocate(__bytes, __alignment));
    }

    void deallocate(void *__p, size_t __bytes,
                    size_t __alignment = _S_max_align)
        __attribute__((__nonnull__)) {
      return do_deallocate(__p, __bytes, __alignment);
    }

    [[nodiscard]]
    bool is_equal(const memory_resource &__other) const noexcept {
      return do_is_equal(__other);
    }

  private:
    virtual void *do_allocate(size_t __bytes, size_t __alignment) = 0;

    virtual void do_deallocate(void *__p, size_t __bytes,
                               size_t __alignment) = 0;

    virtual bool do_is_equal(const memory_resource &__other) const noexcept = 0;
  };

  [[nodiscard]]
  inline bool operator==(const memory_resource &__a,
                         const memory_resource &__b) noexcept {
    return &__a == &__b || __a.is_equal(__b);
  }
  template <typename _Tp> class polymorphic_allocator {

    template <typename _Up> struct __not_pair {
      using type = void;
    };

    template <typename _Up1, typename _Up2>
    struct __not_pair<pair<_Up1, _Up2>> {};

  public:
    using value_type = _Tp;

    polymorphic_allocator() noexcept {
      extern memory_resource *get_default_resource() noexcept
          __attribute__((__returns_nonnull__));
      _M_resource = get_default_resource();
    }

    polymorphic_allocator(memory_resource *__r) noexcept
        __attribute__((__nonnull__))
        : _M_resource(__r) {
      ;
    }

    polymorphic_allocator(const polymorphic_allocator &__other) = default;

    template <typename _Up>
    polymorphic_allocator(const polymorphic_allocator<_Up> &__x) noexcept
        : _M_resource(__x.resource()) {}

    polymorphic_allocator &operator=(const polymorphic_allocator &) = delete;

    [[nodiscard]]
    _Tp *allocate(size_t __n) __attribute__((__returns_nonnull__)) {
      if ((__gnu_cxx::__int_traits<size_t>::__max / sizeof(_Tp)) < __n)
        std::__throw_bad_array_new_length();
      return static_cast<_Tp *>(
          _M_resource->allocate(__n * sizeof(_Tp), alignof(_Tp)));
    }

    void deallocate(_Tp *__p, size_t __n) noexcept
        __attribute__((__nonnull__)) {
      _M_resource->deallocate(__p, __n * sizeof(_Tp), alignof(_Tp));
    }

    [[nodiscard]] void *
    allocate_bytes(size_t __nbytes, size_t __alignment = alignof(max_align_t)) {
      return _M_resource->allocate(__nbytes, __alignment);
    }

    void deallocate_bytes(void *__p, size_t __nbytes,
                          size_t __alignment = alignof(max_align_t)) {
      _M_resource->deallocate(__p, __nbytes, __alignment);
    }

    template <typename _Up> [[nodiscard]] _Up *allocate_object(size_t __n = 1) {
      if ((__gnu_cxx::__int_traits<size_t>::__max / sizeof(_Up)) < __n)
        std::__throw_bad_array_new_length();
      return static_cast<_Up *>(
          allocate_bytes(__n * sizeof(_Up), alignof(_Up)));
    }

    template <typename _Up> void deallocate_object(_Up *__p, size_t __n = 1) {
      deallocate_bytes(__p, __n * sizeof(_Up), alignof(_Up));
    }

    template <typename _Up, typename... _CtorArgs>
    [[nodiscard]] _Up *new_object(_CtorArgs &&...__ctor_args) {
      _Up *__p = allocate_object<_Up>();
      try {
        construct(__p, std::forward<_CtorArgs>(__ctor_args)...);
      } catch (...) {
        deallocate_object(__p);
        throw;
      }
      return __p;
    }

    template <typename _Up> void delete_object(_Up *__p) {
      __p->~_Up();
      deallocate_object(__p);
    }
    template <typename _Tp1, typename... _Args>
    __attribute__((__nonnull__)) void construct(_Tp1 *__p, _Args &&...__args) {
      std::uninitialized_construct_using_allocator(
          __p, *this, std::forward<_Args>(__args)...);
    }

    template <typename _Up>
    __attribute__((__deprecated__("use '"
                                  "allocator_traits::destroy"
                                  "' instead")))
    __attribute__((__nonnull__)) void
    destroy(_Up *__p) {
      __p->~_Up();
    }

    polymorphic_allocator
    select_on_container_copy_construction() const noexcept {
      return polymorphic_allocator();
    }

    memory_resource *resource() const noexcept
        __attribute__((__returns_nonnull__)) {
      return _M_resource;
    }

    [[nodiscard]]
    friend bool operator==(const polymorphic_allocator &__a,
                           const polymorphic_allocator &__b) noexcept {
      return *__a.resource() == *__b.resource();
    }

  private:
    memory_resource *_M_resource;
  };

  template <typename _Tp1, typename _Tp2>
  [[nodiscard]]
  inline bool operator==(const polymorphic_allocator<_Tp1> &__a,
                         const polymorphic_allocator<_Tp2> &__b) noexcept {
    return *__a.resource() == *__b.resource();
  }
  } // namespace pmr

  template <typename _Alloc> struct allocator_traits;

  template <typename _Tp>
  struct allocator_traits<pmr::polymorphic_allocator<_Tp>> {

    using allocator_type = pmr::polymorphic_allocator<_Tp>;

    using value_type = _Tp;

    using pointer = _Tp *;

    using const_pointer = const _Tp *;

    using void_pointer = void *;

    using const_void_pointer = const void *;

    using difference_type = std::ptrdiff_t;

    using size_type = std::size_t;

    using propagate_on_container_copy_assignment = false_type;
    using propagate_on_container_move_assignment = false_type;
    using propagate_on_container_swap = false_type;

    static allocator_type
    select_on_container_copy_construction(const allocator_type &) noexcept {
      return allocator_type();
    }

    using is_always_equal = false_type;

    template <typename _Up>
    using rebind_alloc = pmr::polymorphic_allocator<_Up>;

    template <typename _Up>
    using rebind_traits = allocator_traits<pmr::polymorphic_allocator<_Up>>;
    [[nodiscard]] static pointer allocate(allocator_type &__a, size_type __n) {
      return __a.allocate(__n);
    }
    [[nodiscard]] static pointer allocate(allocator_type &__a, size_type __n,
                                          const_void_pointer) {
      return __a.allocate(__n);
    }
    static void deallocate(allocator_type &__a, pointer __p, size_type __n) {
      __a.deallocate(__p, __n);
    }
    template <typename _Up, typename... _Args>
    static void construct(allocator_type &__a, _Up *__p, _Args &&...__args) {
      __a.construct(__p, std::forward<_Args>(__args)...);
    }
    template <typename _Up>
    static constexpr void
    destroy(allocator_type &,
            _Up *__p) noexcept(is_nothrow_destructible<_Up>::value) {
      __p->~_Up();
    }

    static constexpr size_type max_size(const allocator_type &) noexcept {
      return size_t(-1) / sizeof(value_type);
    }
  };

} // namespace std
namespace std __attribute__((__visibility__("default"))) {

  namespace pmr {
  template <typename _Key, typename _Tp, typename _Hash = std::hash<_Key>,
            typename _Pred = std::equal_to<_Key>>
  using unordered_map =
      std::unordered_map<_Key, _Tp, _Hash, _Pred,
                         polymorphic_allocator<pair<const _Key, _Tp>>>;
  template <typename _Key, typename _Tp, typename _Hash = std::hash<_Key>,
            typename _Pred = std::equal_to<_Key>>
  using unordered_multimap =
      std::unordered_multimap<_Key, _Tp, _Hash, _Pred,
                              polymorphic_allocator<pair<const _Key, _Tp>>>;
  } // namespace pmr

} // namespace std

namespace std __attribute__((__visibility__("default"))) {

  template <typename _Key, typename _Tp, typename _Hash, typename _CPred,
            typename _Alloc, typename _Predicate>
  inline typename unordered_map<_Key, _Tp, _Hash, _CPred, _Alloc>::size_type
  erase_if(unordered_map<_Key, _Tp, _Hash, _CPred, _Alloc> & __cont,
           _Predicate __pred) {
    std::unordered_map<_Key, _Tp, _Hash, _CPred, _Alloc> &__ucont = __cont;
    return __detail::__erase_nodes_if(__cont, __ucont, __pred);
  }

  template <typename _Key, typename _Tp, typename _Hash, typename _CPred,
            typename _Alloc, typename _Predicate>
  inline
      typename unordered_multimap<_Key, _Tp, _Hash, _CPred, _Alloc>::size_type
      erase_if(unordered_multimap<_Key, _Tp, _Hash, _CPred, _Alloc> & __cont,
               _Predicate __pred) {
    std::unordered_multimap<_Key, _Tp, _Hash, _CPred, _Alloc> &__ucont = __cont;
    return __detail::__erase_nodes_if(__cont, __ucont, __pred);
  }

} // namespace std

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
