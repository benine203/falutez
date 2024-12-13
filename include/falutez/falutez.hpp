#pragma once

#ifndef _UNIHEADER_BUILD_
#include <memory>
#endif

#include <falutez/falutez-generic-client.hpp>

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
      : impl{std::dynamic_pointer_cast<GenericClient<GenericClientConfig>>(
            impl)} {}

  template <ClientImpl TImpl>
  Client(TImpl &&client)
      : impl{std::dynamic_pointer_cast<GenericClient<GenericClientConfig>>(
            std::make_shared<TImpl>(std::move(client)))} {}

  template <ClientImpl TImpl> Client &operator=(std::shared_ptr<TImpl> impl) {
    this->impl =
        std::dynamic_pointer_cast<GenericClient<GenericClientConfig>>(impl);
    return *this;
  }

private:
  std::shared_ptr<GenericClient<GenericClientConfig>> impl;
};

} // namespace HTTP