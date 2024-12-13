#pragma once

#include <latch>
#include <random>
#include <regex>

#include <netinet/in.h>
#include <sys/epoll.h>
#include <sys/socket.h>

#include <gtest/gtest.h>

#include <falutez/falutez-types.hpp>

struct RESTFixture : public ::testing::Test {

  static inline std::random_device rd;
  const uint16_t port = rd() % 1000 + 8000;

  static inline constexpr std::string_view kSuccessPath = "/api/v1/test";
  static inline constexpr auto kSuccessMethod = HTTP::METHOD::GET;
  static inline constexpr auto kFailureMethod = HTTP::METHOD::POST;

  std::latch server_up_latch{1};

  void SetUp() override {

    std::cerr << std::format("{}:{}:{}: Starting server\n", __FILE__, __LINE__,
                             __func__);
    std::cerr.flush();

    server_thread = std::jthread{[server_up_latch = &server_up_latch,
                                  port = this->port](auto stoken) {
      int server_socket = socket(AF_INET, SOCK_STREAM, 0);
      int epoll_fd = epoll_create1(0);

      try {

        if (server_socket == -1 || epoll_fd == -1) {
          throw std::runtime_error{
              std::format("{} failed: {}",
                          server_socket == -1 ? "socket()" : "epoll_create1()",
                          strerror(errno))};
        }

        auto server_addr =
            sockaddr_in{.sin_family = AF_INET,
                        .sin_port = htons(port),
                        .sin_addr = in_addr{.s_addr = INADDR_ANY}};

        if (bind(server_socket, (struct sockaddr *)&server_addr,
                 sizeof(server_addr)) < 0) {
          throw std::runtime_error{
              std::format("bind() failed: {}; port={}", strerror(errno), port)};
        }

        if (listen(server_socket, 5) < 0) {
          throw std::runtime_error{
              std::format("listen() failed: {}", strerror(errno))};
        }

        std::cerr << std::format("{}:{}:{}: Server listening on port {}\n",
                                 __FILE__, __LINE__, __func__, port);

        server_up_latch->count_down();

        struct epoll_event ev;
        ev.events = EPOLLIN;
        ev.data.fd = server_socket;

        struct epoll_event events[1];

        if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, server_socket, &ev) == -1) {
          throw std::runtime_error{
              std::format("epoll_ctl() failed: {}", strerror(errno))};
        }

        while (!stoken.stop_requested()) {

          while (!stoken.stop_requested()) {

            auto const nfds = epoll_wait(
                epoll_fd, events, 1, std::chrono::milliseconds{1000}.count());

            if (nfds == -1) {
              throw std::runtime_error{
                  std::format("epoll_wait() failed: {}", strerror(errno))};
            } else if (nfds == 0) {
              continue;
            } else if (events[0].data.fd != server_socket) {
              std::cerr << std::format(
                  "{}:{}:{}: server epoll event not server "
                  "socket\n",
                  __FILE__, __LINE__, __func__);
              continue;
            }

            break;
          }

          if (stoken.stop_requested()) {
            break;
          }

          std::cerr << std::format("{}:{}:{}: Server accepting connection\n",
                                   __FILE__, __LINE__, __func__);

          auto client_socket = accept(server_socket, nullptr, nullptr);

          if (client_socket < 0) {
            throw std::runtime_error{
                std::format("accept() failed: {}", strerror(errno))};
          }

          std::string request;
          request.resize(1024);

          auto bytes = recv(client_socket, request.data(), request.size(), 0);
          if (bytes < 0) {
            throw std::runtime_error{
                std::format("recv() failed: {}", strerror(errno))};
          }

          static const std::regex request_line_re{R"(^([A-Z]+)( ([^ ]+))?)",
                                                  std::regex::optimize};

          if (std::smatch request_line_match;
              std::regex_search(request, request_line_match, request_line_re)) {

            auto const method = request_line_match[1].str();
            auto const path = request_line_match[3].str();

            std::string response;

            if (method == to_string(kSuccessMethod) && path == kSuccessPath) {
              response = "HTTP/1.0 200 OK\r\n"
                         "Content-Type: text/plain\r\n"
                         "Content-Length: 12\r\n"
                         "\r\n"
                         "Hello, World!";
            } else {
              response = "HTTP/1.0 404 Not Found\r\n";
            }

            send(client_socket, response.c_str(), response.size(), 0);
          } else {
            auto response = "HTTP/1.0 400 Bad Request\r\n";

            send(client_socket, response, strlen(response), 0);
          }

          close(client_socket);
        }
      } catch (std::exception const &e) {
        if (epoll_fd != -1)
          close(epoll_fd);
        if (server_socket != -1)
          close(server_socket);
        std::cerr << "Server thread exception: " << e.what() << "\n";
      }
    }};

    server_up_latch.wait();
  }

  void TearDown() override {
    if (server_thread.joinable()) {
      server_thread.request_stop();
      server_thread.join();
    }
  }

private:
  std::jthread server_thread{};
};