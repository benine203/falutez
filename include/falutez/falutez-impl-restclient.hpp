#pragma once

#ifndef _UNIHEADER_BUILD_
#include <iostream>
#include <restclient-cpp/connection.h>
#include <restclient-cpp/restclient.h>
#endif

#include <falutez/falutez-types.hpp>
#include <falutez/falutez.hpp>

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

  //// we are satisfied with the base implementations
  // void set_base_url(std::string_view) override;
  // void set_timeout(std::chrono::milliseconds) override;
  // void set_keepalive(std::pair<bool, std::chrono::milliseconds>) override;
  // void set_headers(Headers) override;

  std::function<Request()> request(METHOD method, RequestSpec params) override {

    return [method, params = std::move(params), config = std::ref(config),
            conn = std::ref(conn),
            base_url = [this] { return base_url(); }]() -> Request {
      RequestInfo req{.method = method, .path = std::string{params.path}};
      req.headers = std::move(params.headers);
      req.body = std::move(params.body);

      auto req_headers = Headers{config.get()->headers};

      if (params.headers.has_value())
        req_headers.merge(params.headers.value());

      conn.get()->SetHeaders(req_headers);

      static std::unordered_map<METHOD,
                                std::function<RestClient::Response(
                                    RestClient::Connection *, std::string)>>
          methods = {
              {METHOD::GET,
               [&](auto *conn, auto path) { return conn->get(path); }},
              {METHOD::POST,
               [&](auto *conn, auto path) {
                 return conn->post(
                     path, params.body.has_value() ? params.body->data : "");
               }},
              {METHOD::PUT,
               [&](auto *conn, auto path) {
                 return conn->put(
                     path, params.body.has_value() ? params.body->data : "");
               }},
              {METHOD::PATCH,
               [&](auto *conn, auto path) {
                 return conn->patch(
                     path, params.body.has_value() ? params.body->data : "");
               }},
              {METHOD::DELETE,
               [&](auto *conn, auto path) { return conn->del(path); }},
              {METHOD::HEAD,
               [&](auto *conn, auto path) { return conn->head(path); }},
              {METHOD::OPTIONS,
               [&](auto *conn, auto path) { return conn->options(path); }},
          };

      auto req_fn = methods.at(method);

      std::string full_path;

      if (auto last_char = base_url().back();
          last_char != '/' && params.path.front() != '/') {
        full_path += '/';
      }

      full_path += params.path;

      if (params.params.has_value()) {
        full_path += params.params.value().get_url_component();
      }

      auto res = req_fn(conn.get().get(), full_path);

#ifndef NDEBUG
      std::cerr << std::format("{}:{}:{}: client timeout={}; base_url={}\n",
                               __FILE__, __LINE__, __func__,
                               conn.get()->GetInfo().timeout,
                               conn.get()->GetInfo().baseUrl);
      std::cerr << std::format("{}:{}:{}: Request: url={} -> code={}\n",
                               __FILE__, __LINE__, __func__, full_path,
                               res.code);
      for (auto &[key, value] : res.headers) {
        std::cerr << std::format("{}:{}:{}: Header: <{}, {}>\n", __FILE__,
                                 __LINE__, __func__, key, value);
      }
      std::cerr << std::format("{}:{}:{}: Body: {}\n", __FILE__, __LINE__,
                               __func__, res.body);
#endif

      req.status = res.code;

      req.body = HTTP::Body{res.body};

      if (res.headers.contains("Content-Type")) {
        req.body->content_type = res.headers.at("Content-Type");
      }

      if (!res.headers.empty()) {
        req.headers = HTTP::Headers{res.headers};
      }

      co_return req;
    };
  }

private:
  std::unique_ptr<RestClient::Connection> conn;
};

} // namespace HTTP