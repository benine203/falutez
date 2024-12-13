
#include <chrono>
#include <ctime>

#include <gtest/gtest.h>

#include <falutez/falutez-impl-restclient.hpp>
#include <stdexec/__detail/__sync_wait.hpp>
#include <stdexec/__detail/__when_all.hpp>

#include "falutez/falutez-types.hpp"
#include "rest-server-fixture.hpp"

TEST(FalRESTClient, InitDestroy) {
  auto cfg = HTTP::RestClientClientConfig{};

  cfg.base_url = "http://localhost:8080";
  cfg.timeout = std::chrono::milliseconds{1000};
  cfg.keepalive = std::make_pair(true, std::chrono::milliseconds{1000});
  cfg.headers = HTTP::Headers{{{"Content-Type", "application/json"}}};

  HTTP::RestClientClient client{cfg};
}

TEST_F(RESTFixture, OneThreadMultipleReqs) {
  auto cfg = HTTP::RestClientClientConfig{};
  cfg.base_url = std::format("http://localhost:{}", port);
  cfg.timeout = std::chrono::milliseconds{2000};
  cfg.keepalive = std::make_pair(true, std::chrono::milliseconds{10000});
  cfg.thread_pool_size = 1;

  HTTP::RestClientClient client{cfg};

  auto req1 = client.request(
      HTTP::RequestSpec{.method = kSuccessMethod,
                        .path = kWaitPath,
                        .params = std::make_optional<HTTP::Parameters>(),
                        .headers = std::make_optional<HTTP::Headers>(),
                        .body = std::make_optional<HTTP::Body>()});

  auto req2 = client.request(
      HTTP::RequestSpec{.method = kSuccessMethod,
                        .path = kSuccessPath,
                        .params = std::make_optional<HTTP::Parameters>(),
                        .headers = std::make_optional<HTTP::Headers>(),
                        .body = std::make_optional<HTTP::Body>()});

  std::chrono::system_clock::time_point req1_finish, req2_finish;

  stdexec::sync_wait(stdexec::when_all(
      stdexec::then(std::move(req1),
                    [&](auto &&) {
                      req1_finish = std::chrono::system_clock::now();
                      SCOPED_TRACE(std::format("req1_finish={}", req1_finish));
                    }),
      stdexec::then(std::move(req2), [&](auto &&) {
        req2_finish = std::chrono::system_clock::now();
        SCOPED_TRACE(std::format("req2_finish={}", req2_finish));
      })));

  ASSERT_NE(req1_finish, req2_finish);

  // even though req2 is "instantaneous" it should finish after req1 because
  // the thread pool size is 1
  ASSERT_GE(req2_finish, req1_finish);

  auto const time_diff =
      std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(
          req2_finish - req1_finish);

  ASSERT_LT(time_diff, kWaitDuration);
}

TEST_F(RESTFixture, MultiThreadPool) {
  auto cfg = HTTP::RestClientClientConfig{};
  cfg.base_url = std::format("http://localhost:{}", port);
  cfg.timeout = std::chrono::milliseconds{2000};
  cfg.keepalive = std::make_pair(true, std::chrono::milliseconds{10000});
  cfg.thread_pool_size = 2;

  HTTP::RestClientClient client{cfg};

  auto req1 = client.request(
      HTTP::RequestSpec{.method = kSuccessMethod,
                        .path = kWaitPath,
                        .params = std::make_optional<HTTP::Parameters>(),
                        .headers = std::make_optional<HTTP::Headers>(),
                        .body = std::make_optional<HTTP::Body>()});

  auto req2 = client.request(
      HTTP::RequestSpec{.method = kSuccessMethod,
                        .path = kWaitPath,
                        .params = std::make_optional<HTTP::Parameters>(),
                        .headers = std::make_optional<HTTP::Headers>(),
                        .body = std::make_optional<HTTP::Body>()});

  auto req3 = client.request(
      HTTP::RequestSpec{.method = kSuccessMethod,
                        .path = kWaitPath,
                        .params = std::make_optional<HTTP::Parameters>(),
                        .headers = std::make_optional<HTTP::Headers>(),
                        .body = std::make_optional<HTTP::Body>()});

  std::chrono::system_clock::time_point req1_finish, req2_finish, req3_finish;

  stdexec::sync_wait(stdexec::when_all(
      stdexec::then(std::move(req1),
                    [&req1_finish](auto &&) {
                      req1_finish = std::chrono::system_clock::now();
                      SCOPED_TRACE(std::format("req1_finish={}", req1_finish));
                    }),
      stdexec::then(std::move(req2),
                    [&](auto &&) {
                      req2_finish = std::chrono::system_clock::now();
                      SCOPED_TRACE(std::format("req2_finish={}", req2_finish));
                    }),
      stdexec::then(std::move(req3), [&](auto &&) {
        req3_finish = std::chrono::system_clock::now();
        SCOPED_TRACE(std::format("req3_finish={}", req3_finish));
      })));

  auto const time_diff =
      std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(
          req2_finish - req1_finish);

  SCOPED_TRACE(std::format("time_diff={}; single_op_duration={}", time_diff,
                           kWaitDuration));

  // even though both requests are busy ops, they should finish around the same
  // time because the thread pool size is 2
  ASSERT_LT(time_diff, 1.5 * kWaitDuration);

  auto const diff2 =
      std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(
          req3_finish - req2_finish);

  SCOPED_TRACE(
      std::format("diff2={}; single_op_duration={}", diff2, kWaitDuration));

  // op3 would have had to wait for one of them to finish before being
  // scheduled onto the work queue
  ASSERT_GE(req3_finish - req2_finish, kWaitDuration);
}

TEST_F(RESTFixture, Request) {
  auto cfg = HTTP::RestClientClientConfig{};
  cfg.base_url = std::format("http://localhost:{}", port);
  cfg.timeout = std::chrono::milliseconds{1000};
  cfg.keepalive = std::make_pair(true, std::chrono::milliseconds{1000});
  // cfg.headers = HTTP::Headers{{{"Content-Type", "application/json"}}};

  HTTP::RestClientClient client{cfg};

  auto success_req = client.request(
      HTTP::RequestSpec{.method = kSuccessMethod,
                        .path = kSuccessPath,
                        .params = std::make_optional<HTTP::Parameters>(),
                        .headers = std::make_optional<HTTP::Headers>(),
                        .body = std::make_optional<HTTP::Body>()});

  auto [success_req_result] =
      stdexec::sync_wait(std::move(success_req)).value();

  EXPECT_FALSE(success_req_result.error());

  auto success_req_info = success_req_result.value();

  EXPECT_TRUE(success_req_info.status);
  EXPECT_EQ(success_req_info.method, kSuccessMethod);
  EXPECT_EQ(success_req_info.path, kSuccessPath);
  EXPECT_EQ(success_req_info.status, HTTP::STATUS::OK);

  auto fail_req = client.request(
      HTTP::RequestSpec{.method = kFailureMethod,
                        .path = "/",
                        .params = std::make_optional<HTTP::Parameters>(),
                        .headers = std::make_optional<HTTP::Headers>(),
                        .body = std::make_optional<HTTP::Body>()});

  auto [fail_req_result] = stdexec::sync_wait(std::move(fail_req)).value();

  EXPECT_FALSE(fail_req_result.error());
  EXPECT_FALSE(fail_req_result.value().status);

  std::cerr << std::format(
      "{}:{}:{}: scheduling latency: {}\n", __FILE__, __LINE__, __func__,
      success_req_info.start_time - success_req_info.init_time);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}