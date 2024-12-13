#pragma once

#ifndef _UNIHEADER_BUILD_
#if __cplusplus >= 202302L
#include <expected>
#else
#include <glaze/util/expected.hpp>
#endif
#endif // _UNIHEADER_BUILD_

namespace HTTP {

#if __cplusplus >= 202302L
template <typename T, typename E> using expected = std::expected<T, E>;
#else
template <typename T, typename E> using expected = glz::expected<T, E>;
#endif

using int128_t = __uint128_t;

} // namespace HTTP