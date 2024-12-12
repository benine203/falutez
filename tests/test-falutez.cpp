#include <gtest/gtest.h>

#include <falutez/falutez.hpp>

struct NullClient : public HTTP::GenericClient {

  struct NullClientParams : public GenericClient::ClientConfig {
    bool dummy1;
    std::string dummy2;
  };

  NullClient() = delete;
  NullClient(NullClientParams params) : GenericClient{params} {}
  NullClient(bool dummy1, std::string dummy2)
      : GenericClient{NullClientParams{.dummy1 = dummy1, .dummy2 = dummy2}} {}

  NullClient(NullClient &&) = default;
  NullClient &operator=(NullClient &&) = default;
  NullClient(const NullClient &) = default;
  NullClient &operator=(const NullClient &) = default;

  void set_base_url(std::string_view) override {}
  void set_timeout(std::chrono::milliseconds) override {}
  void set_keepalive(std::pair<bool, std::chrono::milliseconds>) override {}
  void set_headers(std::pair<std::string_view, std::string_view>) override {}
};

TEST(Falutez, ImplInterface) {

  NullClient client1{NullClient::NullClientParams{}};

  NullClient client2{1, "x"};

  client1.set_base_url("http://localhost:8080");

  client1.set_timeout(std::chrono::milliseconds{1000});

  client1.set_keepalive(std::make_pair(true, std::chrono::milliseconds{1000}));

  client1.set_headers(std::make_pair("Content-Type", "application/json"));

  client2.set_base_url("http://localhost:8080");

  client2.set_timeout(std::chrono::milliseconds{1000});

  client2.set_keepalive(std::make_pair(true, std::chrono::milliseconds{1000}));

  client2.set_headers(std::make_pair("Content-Type", "application/json"));

  SUCCEED();
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}