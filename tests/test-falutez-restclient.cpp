
#include <gtest/gtest.h>

#include <falutez/falutez-impl-restclient.hpp>

TEST(FalRESTClient, InitDestroy) {
  auto cfg = HTTP::RestClientClientConfig{};

  cfg.base_url = "http://localhost:8080";
  cfg.timeout = std::chrono::milliseconds{1000};
  cfg.keepalive = std::make_pair(true, std::chrono::milliseconds{1000});
  cfg.headers = HTTP::Headers{{{"Content-Type", "application/json"}}};

  HTTP::RestClientClient client{cfg};
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}