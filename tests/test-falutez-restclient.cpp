
#include <ctime>

#include <gtest/gtest.h>

#include <falutez/falutez-impl-restclient.hpp>

#include "rest-server-fixture.hpp"

TEST(FalRESTClient, InitDestroy) {
  auto cfg = HTTP::RestClientClientConfig{};

  cfg.base_url = "http://localhost:8080";
  cfg.timeout = std::chrono::milliseconds{1000};
  cfg.keepalive = std::make_pair(true, std::chrono::milliseconds{1000});
  cfg.headers = HTTP::Headers{{{"Content-Type", "application/json"}}};

  HTTP::RestClientClient client{cfg};
}

TEST_F(RESTFixture, Request) {
  auto cfg = HTTP::RestClientClientConfig{};
  cfg.base_url = std::format("http://localhost:{}", port);
  cfg.timeout = std::chrono::milliseconds{1000};
  cfg.keepalive = std::make_pair(true, std::chrono::milliseconds{1000});
  // cfg.headers = HTTP::Headers{{{"Content-Type", "application/json"}}};

  HTTP::RestClientClient client{cfg};

  auto success_req = client.request(
      kSuccessMethod, HTTP::RequestSpec{.path = kSuccessPath,
                                        .params = HTTP::Parameters{},
                                        .headers = HTTP::Headers{},
                                        .body = HTTP::Body{}});

  auto [success_req_result] =
      stdexec::sync_wait(std::move(success_req())).value();

  EXPECT_FALSE(success_req_result.error());

  auto success_req_info = success_req_result.value();

  EXPECT_TRUE(success_req_info.status);
  EXPECT_EQ(success_req_info.method, kSuccessMethod);
  EXPECT_EQ(success_req_info.path, kSuccessPath);
  EXPECT_EQ(success_req_info.status, HTTP::STATUS::OK);

  auto fail_req = client.request(kFailureMethod,
                                 HTTP::RequestSpec{.path = "/",
                                                   .params = HTTP::Parameters{},
                                                   .headers = HTTP::Headers{},
                                                   .body = HTTP::Body{}});

  auto [fail_req_result] = stdexec::sync_wait(std::move(fail_req())).value();

  EXPECT_FALSE(fail_req_result.error());
  EXPECT_FALSE(fail_req_result.value().status);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}