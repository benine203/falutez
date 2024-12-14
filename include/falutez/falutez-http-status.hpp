#pragma once

#ifndef _UNIHEADER_BUILD_
#include <compare>
#include <cstdint>
#include <cstring>
#include <optional>
#include <string>
#include <string_view>
#include <unordered_map>
#endif

namespace HTTP {

struct STATUS {

  enum Code : int16_t {
    NONE,

    // 1xx Informational
    CONTINUE = 100,
    SWITCHING_PROTOCOLS = 101,
    PROCESSING = 102,
    EARLY_HINTS = 103,

    // 2xx Success
    OK = 200,
    CREATED = 201,
    ACCEPTED = 202,
    NON_AUTHORITATIVE_INFORMATION = 203,
    NO_CONTENT = 204,
    RESET_CONTENT = 205,
    PARTIAL_CONTENT = 206,
    MULTI_STATUS = 207,
    ALREADY_REPORTED = 208,
    IM_USED = 226,

    // 3xx Redirection
    MULTIPLE_CHOICES = 300,
    MOVED_PERMANENTLY = 301,
    FOUND = 302,
    SEE_OTHER = 303,
    NOT_MODIFIED = 304,
    USE_PROXY = 305,
    SWITCH_PROXY = 306,
    TEMPORARY_REDIRECT = 307,
    PERMANENT_REDIRECT = 308,

    // 4xx Client Error
    BAD_REQUEST = 400,
    UNAUTHORIZED = 401,
    PAYMENT_REQUIRED = 402,
    FORBIDDEN = 403,
    NOT_FOUND = 404,
    METHOD_NOT_ALLOWED = 405,
    NOT_ACCEPTABLE = 406,
    PROXY_AUTHENTICATION_REQUIRED = 407,
    REQUEST_TIMEOUT = 408,
    CONFLICT = 409,
    GONE = 410,
    LENGTH_REQUIRED = 411,
    PRECONDITION_FAILED = 412,
    PAYLOAD_TOO_LARGE = 413,
    URI_TOO_LONG = 414,
    UNSUPPORTED_MEDIA_TYPE = 415,
    RANGE_NOT_SATISFIABLE = 416,
    EXPECTATION_FAILED = 417,
    IM_A_TEAPOT = 418,
    MISDIRECTED_REQUEST = 421,
    UNPROCESSABLE_ENTITY = 422,
    LOCKED = 423,
    FAILED_DEPENDENCY = 424,
    TOO_EARLY = 425,
    UPGRADE_REQUIRED = 426,
    PRECONDITION_REQUIRED = 428,
    TOO_MANY_REQUESTS = 429,
    REQUEST_HEADER_FIELDS_TOO_LARGE = 431,
    UNAVAILABLE_FOR_LEGAL_REASONS = 451,

    // 5xx Server Error
    INTERNAL_SERVER_ERROR = 500,
    NOT_IMPLEMENTED = 501,
    BAD_GATEWAY = 502,
    SERVICE_UNAVAILABLE = 503,
    GATEWAY_TIMEOUT = 504,
    HTTP_VERSION_NOT_SUPPORTED = 505,
    VARIANT_ALSO_NEGOTIATES = 506,
    INSUFFICIENT_STORAGE = 507,
    LOOP_DETECTED = 508,
    NOT_EXTENDED = 510,
    NETWORK_AUTHENTICATION_REQUIRED = 511
  };

  explicit operator bool() const noexcept {
    return code >= OK && code < MULTIPLE_CHOICES;
  }

  bool error() const noexcept { return !operator bool(); }

  bool is_errno() const noexcept { return code < NONE; }

  bool is_platform_error() const noexcept { return platform_error.has_value(); }

  bool is_http() const noexcept {
    return code >= CONTINUE && !is_platform_error();
  }

  auto operator->() const noexcept {
    struct Info {
      int16_t code;
      std::string_view str;
    };

    if (platform_error.has_value()) {
      return Info{
          .code = code,
          .str = platform_error.value(),
      };
    }

    if (code < NONE) {
      return Info{
          .code = code,
          .str = strerror(code),
      };
    }

    static std::unordered_map<int16_t, Info> infos = {
        {NONE, {NONE, "<NONE>"}},

        {CONTINUE, {CONTINUE, "Continue"}},
        {SWITCHING_PROTOCOLS, {SWITCHING_PROTOCOLS, "Switching Protocols"}},
        {PROCESSING, {PROCESSING, "Processing"}},
        {EARLY_HINTS, {EARLY_HINTS, "Early Hints"}},
        {OK, {OK, "OK"}},
        {CREATED, {CREATED, "Created"}},
        {ACCEPTED, {ACCEPTED, "Accepted"}},
        {NON_AUTHORITATIVE_INFORMATION,
         {NON_AUTHORITATIVE_INFORMATION, "Non-Authoritative Information"}},
        {NO_CONTENT, {NO_CONTENT, "No Content"}},
        {RESET_CONTENT, {RESET_CONTENT, "Reset Content"}},
        {PARTIAL_CONTENT, {PARTIAL_CONTENT, "Partial Content"}},
        {MULTI_STATUS, {MULTI_STATUS, "Multi-Status"}},
        {ALREADY_REPORTED, {ALREADY_REPORTED, "Already Reported"}},
        {IM_USED, {IM_USED, "IM Used"}},
        {MULTIPLE_CHOICES, {MULTIPLE_CHOICES, "Multiple Choices"}},
        {MOVED_PERMANENTLY, {MOVED_PERMANENTLY, "Moved Permanently"}},
        {FOUND, {FOUND, "Found"}},
        {SEE_OTHER, {SEE_OTHER, "See Other"}},
        {NOT_MODIFIED, {NOT_MODIFIED, "Not Modified"}},
        {USE_PROXY, {USE_PROXY, "Use Proxy"}},
        {SWITCH_PROXY, {SWITCH_PROXY, "Switch Proxy"}},
        {TEMPORARY_REDIRECT, {TEMPORARY_REDIRECT, "Temporary Redirect"}},
        {PERMANENT_REDIRECT, {PERMANENT_REDIRECT, "Permanent Redirect"}},
        {BAD_REQUEST, {BAD_REQUEST, "Bad Request"}},
        {UNAUTHORIZED, {UNAUTHORIZED, "Unauthorized"}},
        {PAYMENT_REQUIRED, {PAYMENT_REQUIRED, "Payment Required"}},
        {FORBIDDEN, {FORBIDDEN, "Forbidden"}},
        {NOT_FOUND, {NOT_FOUND, "Not Found"}},
        {METHOD_NOT_ALLOWED, {METHOD_NOT_ALLOWED, "Method Not Allowed"}},
        {NOT_ACCEPTABLE, {NOT_ACCEPTABLE, "Not Acceptable"}},
        {PROXY_AUTHENTICATION_REQUIRED,
         {PROXY_AUTHENTICATION_REQUIRED, "Proxy Authentication Required"}},
        {REQUEST_TIMEOUT, {REQUEST_TIMEOUT, "Request Timeout"}},
        {CONFLICT, {CONFLICT, "Conflict"}},
        {GONE, {GONE, "Gone"}},
        {LENGTH_REQUIRED, {LENGTH_REQUIRED, "Length Required"}},
        {PRECONDITION_FAILED, {PRECONDITION_FAILED, "Precondition Failed"}},
        {PAYLOAD_TOO_LARGE, {PAYLOAD_TOO_LARGE, "Payload Too Large"}},
        {URI_TOO_LONG, {URI_TOO_LONG, "URI Too Long"}},
        {UNSUPPORTED_MEDIA_TYPE,
         {UNSUPPORTED_MEDIA_TYPE, "Unsupported Media Type"}},
        {RANGE_NOT_SATISFIABLE,
         {RANGE_NOT_SATISFIABLE, "Range Not Satisfiable"}},
        {EXPECTATION_FAILED, {EXPECTATION_FAILED, "Expectation Failed"}},
        {IM_A_TEAPOT, {IM_A_TEAPOT, "I'm a teapot"}},
        {MISDIRECTED_REQUEST, {MISDIRECTED_REQUEST, "Misdirected Request"}},
        {UNPROCESSABLE_ENTITY, {UNPROCESSABLE_ENTITY, "Unprocessable Entity"}},
        {LOCKED, {LOCKED, "Locked"}},
        {FAILED_DEPENDENCY, {FAILED_DEPENDENCY, "Failed Dependency"}},
        {TOO_EARLY, {TOO_EARLY, "Too Early"}},
        {UPGRADE_REQUIRED, {UPGRADE_REQUIRED, "Upgrade Required"}},
        {PRECONDITION_REQUIRED,
         {PRECONDITION_REQUIRED, "Precondition Required"}},
        {TOO_MANY_REQUESTS, {TOO_MANY_REQUESTS, "Too Many Requests"}},
        {REQUEST_HEADER_FIELDS_TOO_LARGE,
         {REQUEST_HEADER_FIELDS_TOO_LARGE, "Request Header Fields Too Large"}},
        {UNAVAILABLE_FOR_LEGAL_REASONS,

         {UNAVAILABLE_FOR_LEGAL_REASONS, "Unavailable For Legal Reasons"}},
        {INTERNAL_SERVER_ERROR,
         {INTERNAL_SERVER_ERROR, "Internal Server Error"}},
        {NOT_IMPLEMENTED, {NOT_IMPLEMENTED, "Not Implemented"}},
        {BAD_GATEWAY, {BAD_GATEWAY, "Bad Gateway"}},
        {SERVICE_UNAVAILABLE, {SERVICE_UNAVAILABLE, "Service Unavailable"}},
        {GATEWAY_TIMEOUT, {GATEWAY_TIMEOUT, "Gateway Timeout"}},
        {HTTP_VERSION_NOT_SUPPORTED,
         {HTTP_VERSION_NOT_SUPPORTED, "HTTP Version Not Supported"}},
        {VARIANT_ALSO_NEGOTIATES,
         {VARIANT_ALSO_NEGOTIATES, "Variant Also Negotiates"}},
        {INSUFFICIENT_STORAGE, {INSUFFICIENT_STORAGE, "Insufficient Storage"}},
        {LOOP_DETECTED, {LOOP_DETECTED, "Loop Detected"}},
        {NOT_EXTENDED, {NOT_EXTENDED, "Not Extended"}},
        {NETWORK_AUTHENTICATION_REQUIRED,
         {NETWORK_AUTHENTICATION_REQUIRED, "Network Authentication Required"}},
    };

    return infos.at(code);
  }

  STATUS() = default;
  STATUS(int16_t code) noexcept : code(code) {}
  STATUS(std::pair<int16_t, std::string_view> const &platform_error) noexcept
      : code(platform_error.first), platform_error(platform_error.second) {}

  STATUS &operator=(int16_t code) noexcept {
    this->code = code;
    return *this;
  }

  STATUS &operator=(
      std::pair<int16_t, std::string_view> const &platform_error) noexcept {
    this->code = platform_error.first;
    this->platform_error = platform_error.second;
    return *this;
  }

  operator int16_t() const noexcept { return code; }

  std::strong_ordering operator<=>(int16_t code) const noexcept {
    return this->code <=> code;
  }

  std::strong_ordering operator<=>(STATUS const &other) const noexcept {
    return code <=> other.code;
  }

  bool operator==(std::integral auto code) const noexcept {
    return this->code == code;
  }

  bool operator==(STATUS::Code code) const noexcept {
    return this->code == static_cast<int16_t>(code);
  }

  bool operator!=(STATUS::Code code) const noexcept {
    return this->code != code;
  }

  bool operator==(STATUS const &other) const noexcept {
    return code == other.code && platform_error == other.platform_error;
  }

  bool operator!=(std::integral auto code) const noexcept {
    return this->code != code && !is_platform_error();
  }

  bool operator!=(STATUS const &other) const noexcept {
    return code != other.code && platform_error != other.platform_error;
  }

  std::string_view str() const noexcept { return operator->().str; }

private:
  int16_t code = NONE;
  std::optional<std::string> platform_error = std::nullopt;
};

} // namespace HTTP