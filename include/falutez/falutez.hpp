#pragma once

#ifndef _UNIHEADER_BUILD_
#include <memory>
#endif

#include <falutez/falutez-generic-client.hpp>

#include <falutez/falutez-impl-restclient.hpp>

namespace HTTP {

/**
 * @brief generic handle client implementation
 * Users may want to keep this handle instead of the implementations
 * for flexibility in switching them out later or configuring them
 * dynamically (based on config, etc.)
 */
struct Client {

  Client() = default;

  template <ClientImpl TImpl>
  Client(std::shared_ptr<TImpl> impl)
      : impl_{std::dynamic_pointer_cast<GenericClient<GenericClientConfig>>(
            impl)} {}

  template <ClientImpl TImpl>
  Client(TImpl &&client)
      : impl_{std::dynamic_pointer_cast<GenericClient<GenericClientConfig>>(
            std::make_shared<TImpl>(std::forward<decltype(client)>(client)))} {}

  template <ClientImpl TImpl> Client &operator=(std::shared_ptr<TImpl> impl) {
    this->impl_ =
        std::dynamic_pointer_cast<GenericClient<GenericClientConfig>>(impl);
    return *this;
  }

  auto &operator->() { return *impl_; }

  auto const &operator->() const { return *impl_; }

  auto &operator*() { return *impl_; }

  auto const &operator*() const { return *impl_; }

  template <template <typename> class TImpl> auto &get() {
    if (auto impl_handle =
            std::dynamic_pointer_cast<TImpl<GenericClientConfig>>(this->impl_);
        impl_handle) {
      return *impl_handle;
    }
    throw std::runtime_error{
        std::format("{}:{}:{}: Invalid cast", __FILE__, __LINE__, __func__)};
  }

  template <template <typename> class TImpl> auto const &get() const {
    if (auto impl_handle =
            std::dynamic_pointer_cast<TImpl<GenericClientConfig> const>(impl_);
        impl_handle) {
      return *impl_handle;
    }
    throw std::runtime_error{
        std::format("{}:{}:{}: Invalid cast", __FILE__, __LINE__, __func__)};
  }

  template <template <typename> class TImpl> auto *try_get() {
    return std::dynamic_pointer_cast<TImpl<GenericClientConfig>>(impl_);
  }

  template <template <typename> class TImpl> auto const *try_get() const {
    return std::dynamic_pointer_cast<TImpl<GenericClientConfig> const>(impl_);
  }

private:
  std::shared_ptr<GenericClient<GenericClientConfig>> impl_;
};

} // namespace HTTP