#include <gtest/gtest.h>

#include <falutez/falutez.hpp>

struct NullClientConfig : public HTTP::GenericClientConfig {
  bool dummy1;
  std::string dummy2;
};

struct NullClient : public HTTP::GenericClient<NullClientConfig> {

  NullClient() = delete;

  explicit NullClient(NullClientConfig params)
      : GenericClient{std::make_shared<NullClientConfig>(params)} {}

  NullClient(NullClient &&) = default;
  NullClient &operator=(NullClient &&) = default;
  NullClient(const NullClient &) = default;
  NullClient &operator=(const NullClient &) = default;

  void set_base_url(std::string_view url) override {
    GenericClient::set_base_url(url);
  }
  void set_timeout(std::chrono::milliseconds timeout) override {
    GenericClient::set_timeout(timeout);
  }
  void
  set_keepalive(std::pair<bool, std::chrono::milliseconds> keepalive) override {
    GenericClient::set_keepalive(keepalive);
  }
  void set_headers(HTTP::Headers headers) override {
    GenericClient::set_headers(std::move(headers));
  }

  void extra_functionality1() { config->dummy1 = true; }
};

TEST(Falutez, ImplInterface) {

  NullClient client1{NullClientConfig{}};

  client1.set_base_url("http://localhost:8080");

  ASSERT_EQ(client1.base_url(), "http://localhost:8080");

  client1.set_timeout(std::chrono::milliseconds{1000});

  ASSERT_EQ(client1.timeout(), std::chrono::milliseconds{1000});

  client1.set_keepalive(std::make_pair(true, std::chrono::milliseconds{1000}));

  ASSERT_EQ(client1.keepalive(),
            std::make_pair(true, std::chrono::milliseconds{1000}));

  auto hdrs = HTTP::Headers{{{"Content-Type", "application/json"}}};

  client1.set_headers(hdrs);

  ASSERT_EQ(client1.headers(), hdrs);

  SUCCEED();
}

TEST(Falutez, Request) { SUCCEED(); }

TEST(Falutez, TypeErased) {
  HTTP::Client client;

  client = NullClient{NullClientConfig{}};
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}