
#include <gtest/gtest.h>

#include <cpptrace.hpp>
#include <utils.hpp>

#define TESTING
#include <falutez/serio.hpp>

int main(int argc, char **argv) {
  ::cpptrace::register_terminate_handler();
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
