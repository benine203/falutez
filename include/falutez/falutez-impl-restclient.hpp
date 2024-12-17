#pragma once

#ifndef _UNIHEADER_BUILD_
#include <cerrno>
#include <exec/static_thread_pool.hpp>
#include <restclient-cpp/connection.h>
#include <restclient-cpp/restclient.h>
#endif

#include <falutez/falutez-types.hpp>
#include <falutez/falutez.hpp>

namespace HTTP {

struct RestClientClientConfig : public GenericClientConfig {
  uint32_t thread_pool_size = 1;
};

struct RestClientClient : public GenericClient<RestClientClientConfig> {

  RestClientClient() = delete;

  ~RestClientClient() override { GenericClient::~GenericClient(); }

  explicit RestClientClient(RestClientClientConfig params)
      : GenericClient{std::make_shared<RestClientClientConfig>(params)},
        thread_pool_{params.thread_pool_size} {
    RestClient::init();
  }

  RestClientClient(RestClientClient &&) = delete;
  RestClientClient &operator=(RestClientClient &&) = delete;
  RestClientClient(const RestClientClient &) = delete;
  RestClientClient &operator=(const RestClientClient &) = delete;

  AsyncResponse request(RequestSpec params) override {
    // construct a thread-local connection object for each thread in the pool.
    // and apply any necessary configuration.

    if (params.path.empty() && this->config->base_url.empty()) {
      co_return HTTP::unexpected(HTTP::STATUS(
          {EINVAL, std::format("({}:{}:{}): both path and base_url empty",
                               __FILE__, __LINE__, __func__)}));
    }

    auto sync_op = [this, params]() -> HTTP::ResponseDetails {
      static thread_local RestClient::Connection conn = [this]() {
        auto thr_conn = RestClient::Connection{config->base_url};
        if (config->timeout.count() != 0)
          thr_conn.SetTimeout(
              std::chrono::duration_cast<std::chrono::seconds>(config->timeout)
                  .count());
        // if (config->keepalive.first) {
        //   // curl automatically reuses connections
        // }
        if (!config->user_agent.empty())
          thr_conn.SetUserAgent(config->user_agent);
        if (!config->validate_cert)
          thr_conn.SetVerifyPeer(false);
#ifndef NDEBUG
        // std::cerr << std::format(
        //     "{}:{}:{}: threadpool connection initialized with timeout={}\n",
        //     __FILE__, __LINE__, __func__, thr_conn.GetInfo().timeout);
#endif
        return thr_conn;
      }();

      ResponseDetails response{.method = params.method,
                               .path = std::string{params.path}};
      response.headers = config->headers;
      response.body = std::move(params.body);

      {
        auto combined_headers = Headers{config->headers};

        if (params.headers.has_value())
          combined_headers.merge(params.headers.value());

        conn.SetHeaders(std::move(combined_headers));
      }

      const static std::unordered_map<
          METHOD,
          std::function<RestClient::Response(
              HTTP::ResponseDetails &, RestClient::Connection &, std::string)>>
          methods = {
              {METHOD::GET,
               [](auto &req, auto &conn, auto path) { return conn.get(path); }},
              {METHOD::POST,
               [](auto &req, auto &conn, auto path) {
                 return conn.post(path,
                                  req.body.has_value() ? req.body->data : "");
               }},
              {METHOD::PUT,
               [](auto &req, auto &conn, auto path) {
                 return conn.put(path,
                                 req.body.has_value() ? req.body->data : "");
               }},
              {METHOD::PATCH,
               [](auto &req, auto &conn, auto path) {
                 return conn.patch(path,
                                   req.body.has_value() ? req.body->data : "");
               }},
              {METHOD::DELETE,
               [](auto &req, auto &conn, auto path) { return conn.del(path); }},
              {METHOD::HEAD, [](auto &req, auto &conn,
                                auto path) { return conn.head(path); }},
              {METHOD::OPTIONS, [](auto &req, auto &conn,
                                   auto path) { return conn.options(path); }},
          };

      std::string full_path;

      if (auto last_char = base_url().back();
          last_char != '/' && params.path.front() != '/') {
        full_path += '/';
      }

      full_path += params.path;

      if (params.params.has_value()) {
        full_path += params.params.value().get_url_component();
      }

#ifndef NDEBUG
      // std::cerr << std::format("{}:{}:{}: Request: url={}\n", __FILE__,
      //                          __LINE__, __func__, full_path);
#endif

      auto &req_fn = methods.at(params.method);

      response.start_time = std::chrono::system_clock::now();
      auto res = req_fn(response, conn, full_path);
      response.end_time = std::chrono::system_clock::now();

      if (res.code < 100) {
        response.status = HTTP::STATUS{std::pair<int16_t, std::string_view>(
            res.code,
            std::format("(curl) {}",
                        curl_easy_strerror(static_cast<CURLcode>(res.code))))};
        return response;
      }

#ifndef NDEBUG
      // std::cerr << std::format("{}:{}:{}: client timeout={}; base_url={}\n",
      //                          __FILE__, __LINE__, __func__,
      //                          conn.GetInfo().timeout,
      //                          conn.GetInfo().baseUrl);
      // std::cerr << std::format("{}:{}:{}: Request: url={} -> code={}\n",
      //                          __FILE__, __LINE__, __func__, full_path,
      //                          res.code);
      // for (auto &[key, value] : res.headers) {
      //   std::cerr << std::format("{}:{}:{}: Header: <{}, {}>\n", __FILE__,
      //                            __LINE__, __func__, key, value);
      // }
      // std::cerr << std::format("{}:{}:{}: Body: {}\n", __FILE__, __LINE__,
      //                          __func__, res.body);
#endif

      response.status = res.code;

      response.body = HTTP::Body{res.body};

      if (res.headers.contains("Content-Type")) {
        response.body->content_type = res.headers.at("Content-Type");
      }

      if (!res.headers.empty()) {
        response.headers = HTTP::Headers{res.headers};
      }

      return response;
    };

    auto sch = thread_pool_.get_scheduler();

    auto [val] =
        stdexec::sync_wait(stdexec::then(stdexec::schedule(sch), sync_op))
            .value();

    co_return val;
  }

private:
  // std::unique_ptr<RestClient::Connection> conn;
  exec::static_thread_pool thread_pool_;
};

} // namespace HTTP