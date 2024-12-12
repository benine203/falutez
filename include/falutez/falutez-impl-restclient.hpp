#include <falutez/falutez.hpp>

#include <restclient-cpp/connection.h>
#include <restclient-cpp/restclient.h>

namespace HTTP {

struct RestClientClientConfig : public GenericClientConfig {};

struct RestClientClient : public GenericClient<RestClientClientConfig> {

  RestClientClient() = delete;

  ~RestClientClient() override {
    if (conn) {
      conn->Terminate();
    }
    GenericClient::~GenericClient();
  }

  RestClientClient(RestClientClientConfig params)
      : GenericClient{std::make_shared<RestClientClientConfig>(params)} {
    RestClient::init();
    conn = std::make_unique<RestClient::Connection>(config->base_url);
    if (config->timeout.count() != 0) {
      conn->SetTimeout(
          std::chrono::duration_cast<std::chrono::seconds>(config->timeout)
              .count());
    }

    if (config->keepalive.first) {
      // curl automatically reuses connections
    }
  }

  RestClientClient(RestClientClient &&) = default;
  RestClientClient &operator=(RestClientClient &&) = default;
  RestClientClient(const RestClientClient &) = delete;
  RestClientClient &operator=(const RestClientClient &) = delete;

  void set_base_url(std::string_view base_url) override {
    GenericClient::set_base_url(base_url);
  }

  void set_timeout(std::chrono::milliseconds timeout) override {
    GenericClient::set_timeout(timeout);
  }

  void
  set_keepalive(std::pair<bool, std::chrono::milliseconds> keepalive) override {
    GenericClient::set_keepalive(keepalive);
  }

  void set_headers(Headers headers) override {
    GenericClient::set_headers(headers);
  }

private:
  std::unique_ptr<RestClient::Connection> conn;
};

} // namespace HTTP