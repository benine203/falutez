/**
 *  @brief  defines the interface implementations must abide by
 *          along with some baseline data items likely to be useful
 *          across all implementations
 */

#ifndef _UNIHEADER_BUILD_
#include <chrono>
#include <string>
#endif

#include <falutez/falutez-types.hpp>

namespace HTTP {

struct GenericClientConfig {
  std::string base_url;
  std::chrono::milliseconds timeout;
  std::pair<bool, std::chrono::milliseconds> keepalive;
  Headers headers;
  std::string user_agent;
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

  virtual void set_user_agent(std::string_view user_agent) {
    config->user_agent = user_agent;
  }

  virtual std::string base_url() const { return config->base_url; }

  virtual std::chrono::milliseconds timeout() const { return config->timeout; }

  virtual std::pair<bool, std::chrono::milliseconds> keepalive() const {
    return config->keepalive;
  }

  virtual Headers const &headers() const { return config->headers; }

  virtual AsyncResponse request(METHOD method, RequestSpec reqParams) {
    throw std::runtime_error{std::format("{}:{}:{}: request() not implemented",
                                         __FILE__, __LINE__, __func__)};
  }

  virtual std::string_view user_agent() const { return config->user_agent; }

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