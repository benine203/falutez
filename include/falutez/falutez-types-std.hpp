#pragma once

#ifndef _UNIHEADER_BUILD_
#if __cplusplus >= 202302L
#include <expected>
#else
#include <glaze/util/expected.hpp>
#endif
#endif // _UNIHEADER_BUILD_

namespace HTTP {

template <typename R>
concept aggregate_container = requires(R &r) { // no maps or other composites
  std::ranges::begin(r);
  std::ranges::end(r);
  *std::ranges::begin(r) == r[0];
};

#if __cplusplus >= 202302L
template <typename T, typename E> using expected = std::expected<T, E>;
template <typename E> using unexpected = std::unexpected<E>;
#else
template <typename T, typename E> using expected = glz::expected<T, E>;
template <typename E> using unexpected = glz::unexpected<E>;
#endif

using int128_t = __uint128_t;

} // namespace HTTP