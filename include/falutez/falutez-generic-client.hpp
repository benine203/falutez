/**
 *  @brief  defines the interface implementations must abide by
 *          along with some baseline data items likely to be useful
 *          across all implementations
 */
#include <chrono>
#include <string>

#include "falutez/falutez-types.hpp"

namespace HTTP {

struct GenericClientConfig {
  std::string base_url;
  std::chrono::milliseconds timeout;
  std::pair<bool, std::chrono::milliseconds> keepalive;
  std::pair<std::string_view, std::string_view> headers;
};

template <typename TConfig = GenericClientConfig> struct GenericClient {

  virtual ~GenericClient() = default;

  GenericClient() = delete;

  GenericClient(TConfig params) : config{std::make_unique<TConfig>(params)} {}

  GenericClient(std::shared_ptr<TConfig> params) : config{params} {}

  virtual void set_base_url(std::string_view) = 0;
  virtual void set_timeout(std::chrono::milliseconds) = 0;
  virtual void set_keepalive(std::pair<bool, std::chrono::milliseconds>) = 0;
  virtual void set_headers(std::pair<std::string_view, std::string_view>) = 0;

  static Request REQ(METHOD method, std::string_view path,
                     std::string_view body = {}) {}

  virtual std::string base_url() const {
    if (!config)
      throw std::runtime_error{"base_url not set"};
    return config->base_url;
  }

  virtual std::chrono::milliseconds timeout() const {
    if (!config)
      throw std::runtime_error{"timeout not set"};
    return config->timeout;
  }

  virtual std::pair<bool, std::chrono::milliseconds> keepalive() const {
    if (!config)
      throw std::runtime_error{"keepalive not set"};
    return config->keepalive;
  }

  virtual std::pair<std::string_view, std::string_view> headers() const {
    if (!config)
      throw std::runtime_error{"headers not set"};
    return config->headers;
  }

protected:
  std::shared_ptr<TConfig> config;
};

////////////////////////////////////////////////////////////
//                     INTERNAL
// static check on GenericClient interface matching concept
////////////////////////////////////////////////////////////
namespace _internal {
template <ClientImpl TImpl> struct StaticCheck {
  static constexpr inline auto value = true;
};

static_assert(StaticCheck<GenericClient<GenericClientConfig>>::value,
              "GenericClient does not match ClientImpl concept");

} // namespace _internal
////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////

} // namespace HTTP