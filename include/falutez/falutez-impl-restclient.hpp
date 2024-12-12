#include <falutez/falutez.hpp>

#include <restclient-cpp/restclient.h>

namespace HTTP {

struct RestClientClientConfig : public GenericClientConfig {};

struct RestClientClient : public GenericClient<RestClientClientConfig> {

  RestClientClient() = delete;

  RestClientClient(RestClientClientConfig params)
      : GenericClient{std::make_shared<RestClientClientConfig>(params)} {}

  RestClientClient(RestClientClient &&) = default;
  RestClientClient &operator=(RestClientClient &&) = default;
  RestClientClient(const RestClientClient &) = default;
  RestClientClient &operator=(const RestClientClient &) = default;

  void set_base_url(std::string_view base_url) override {
    config->base_url = base_url;
  }

  void set_timeout(std::chrono::milliseconds timeout) override {
    config->timeout = timeout;
  }

  void
  set_keepalive(std::pair<bool, std::chrono::milliseconds> keepalive) override {
    config->keepalive = keepalive;
  }

  void
  set_headers(std::pair<std::string_view, std::string_view> headers) override {
    config->headers = headers;
  }
};

} // namespace HTTP