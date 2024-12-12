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
  Headers headers;
};

template <typename TConfig = GenericClientConfig> struct GenericClient {

  virtual ~GenericClient() = default;

  GenericClient() = delete;

  GenericClient(TConfig params) : config{std::make_unique<TConfig>(params)} {}

  GenericClient(std::shared_ptr<TConfig> params) : config{params} {}

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

  static Request REQ(METHOD method, std::string_view path,
                     std::string_view body = {}) {}

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