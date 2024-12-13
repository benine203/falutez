cmake_minimum_required(VERSION 3.15)

#############################################
##    prelude
include(FetchContent)
if(NOT ENV{VCPKG_ROOT})
  FetchContent_Declare(vcpkg
                       GIT_REPOSITORY https://github.com/microsoft/vcpkg.git)
  FetchContent_MakeAvailable(vcpkg)
  if(NOT VCPKG_BOOTSTRAPPED)
    message(STATUS "Bootstrapping vcpkg")
    execute_process(COMMAND ${vcpkg_SOURCE_DIR}/bootstrap-vcpkg.sh)
    set(VCPKG_BOOTSTRAPPED
        ON
        CACHE BOOL "" FORCE)
  endif()
  set(ENV{VCPKG_ROOT} ${vcpkg_SOURCE_DIR})
endif()

function(vcpkg_install)
  set(packages ${ARGV})
  list(POP_FRONT packages)
  cmake_parse_arguments(VCPKG "" "" "PACKAGES" ${packages})
  execute_process(COMMAND "$ENV{VCPKG_ROOT}/vcpkg" install --recurse
                          ${packages})
endfunction()

set(CMAKE_TOOLCHAIN_FILE
    "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
    CACHE STRING "" FORCE)

#############################################
project(falutez LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
set(CMAKE_VISIBILITY_INLINES_HIDDEN OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(GNUInstallDirs)
include(GenerateExportHeader)
include(CMakePackageConfigHelpers)
#include(FindPackageHandleStandardArgs)
#find_package(PkgConfig)


#############################################
## dependencies
vcpkg_install(PACKAGES
  curl[ssl,c-ares,brotli,zstd,websockets]
  restclient-cpp
  glaze
  nlohmann-json
  stdexec
  gtest
  benchmark
  cpptrace
)

# pkg_check_modules(LIBTACO taco)
# find_package_handle_standard_args(LIBTACO DEFAULT_MSG LIBTACO_LIBRARIES LIBTACO_INCLUDE_DIRS)

find_package(glaze CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
find_package(restclient-cpp CONFIG REQUIRED)
find_package(CURL REQUIRED)
find_package(stdexec CONFIG REQUIRED)
find_package(cpptrace CONFIG REQUIRED)
find_package(GTest CONFIG REQUIRED)
find_package(benchmark CONFIG REQUIRED)
include(GoogleTest)

#############################################
##  target defns

# glob headers
file(GLOB_RECURSE HEADERS include/falutez/*.hpp)
set(HEADERS_ENTRY "${CMAKE_CURRENT_SOURCE_DIR}/include/falutez/falutez.hpp")
set(UNIHEADER "${CMAKE_CURRENT_SOURCE_DIR}/include/falutez.hpp")

add_library(falutez STATIC src/falutez.cpp ${HEADERS})

target_include_directories(falutez PUBLIC  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:include>)

target_sources(falutez PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/falutez/falutez-generic-client.hpp>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/falutez/falutez-http-status.hpp>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/falutez/falutez-impl-restclient.hpp>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/falutez/falutez-types.hpp>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/falutez/falutez-types-headers.hpp>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/falutez/falutez-types-parameters.hpp>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/falutez/falutez-types-std.hpp>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/falutez/falutez.hpp>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/falutez/falutez-serio.hpp>
  $<INSTALL_INTERFACE:include/falutez.hpp>
)

target_link_libraries(falutez PUBLIC
    CURL::libcurl
    restclient-cpp
    glaze::glaze
    STDEXEC::stdexec
    nlohmann_json::nlohmann_json
    cpptrace::cpptrace
)

target_compile_options(falutez PUBLIC -Wno-c99-designator)

generate_export_header(falutez)

set(EXTERNAL_INCLUDES "${CMAKE_CURRENT_BINARY_DIR}/external_includes.hpp")

add_custom_command(
  OUTPUT ${EXTERNAL_INCLUDES}
  COMMAND ${CMAKE_COMMAND} -E remove ${UNIHEADER}
  COMMAND ${CMAKE_COMMAND} -E remove ${EXTERNAL_INCLUDES}
  COMMAND ${CMAKE_COMMAND} -E touch ${EXTERNAL_INCLUDES}
  COMMAND cat ${HEADERS} | sh -c "egrep -h '^.*#include'" | sh -c "egrep -v '((falutez-(.*))|(falutez))\.hpp' | sort | uniq" | tee ${EXTERNAL_INCLUDES}
  COMMENT "Extracting Uni-header external depends"
  VERBATIM
)

add_custom_command(
  OUTPUT ${UNIHEADER}
  COMMAND ${CMAKE_COMMAND} -E remove ${UNIHEADER}
 
  COMMAND sh -c "echo '// Auto-generated unified header' > ${UNIHEADER}"
  COMMAND sh -c "echo '// Do not edit manually' >> ${UNIHEADER}"
  COMMAND sh -c "echo >> ${UNIHEADER}"
  COMMAND sh -c "echo '#pragma once' >> ${UNIHEADER}"
  COMMAND sh -c "echo >> ${UNIHEADER}"

  COMMAND ${CMAKE_CXX_COMPILER} -E ${CXX_FLAGS} 
    -D_UNIHEADER_BUILD_ -std=gnu++20
    -I${CMAKE_CURRENT_SOURCE_DIR}/include
    -I$ENV{VCPKG_ROOT}/installed/x64-linux/include
    ${HEADERS_ENTRY} | sh -c "sed '/^#/d'" > /tmp/uniheader && clang-format -i /tmp/uniheader
  
  COMMAND cat ${EXTERNAL_INCLUDES} /tmp/uniheader >> ${UNIHEADER}

  DEPENDS ${HEADERS} ${EXTERNAL_INCLUDES}
  COMMENT "Generating unified header"
  VERBATIM
)

add_custom_target(unified_header ALL DEPENDS ${UNIHEADER})

########################################33
##         testing

enable_testing()

add_executable(test-serio tests/test-serio.cpp)
target_link_libraries(test-serio PRIVATE falutez GTest::gtest)
gtest_discover_tests(test-serio)

add_executable(test-falutez tests/test-falutez.cpp)
target_link_libraries(test-falutez PRIVATE falutez GTest::gtest)
gtest_discover_tests(test-falutez)

add_executable(test-falutez-restclient tests/test-falutez-restclient.cpp)
target_link_libraries(test-falutez-restclient PRIVATE falutez GTest::gtest)
gtest_discover_tests(test-falutez-restclient)


#############################################
##   benchmarking

add_executable(bench-serio benchmarks/bench-serio.cpp)

target_link_libraries(bench-serio PRIVATE falutez benchmark::benchmark benchmark::benchmark_main)

#############################################
##   cmake install

export(TARGETS falutez FILE falutezTargets.cmake NAMESPACE falutez::)

install(TARGETS falutez EXPORT falutezTargets)

install(DIRECTORY include/ DESTINATION include)

install(EXPORT falutezTargets
  FILE falutezTargets.cmake
  NAMESPACE falutez::
  DESTINATION lib/cmake/falutez
)

#configure_package_config_file(
#  ${CMAKE_CURRENT_SOURCE_DIR}/cmake/falutezConfig.cmake.in
#  ${CMAKE_CURRENT_BINARY_DIR}/falutezConfig.cmake
#  INSTALL_DESTINATION lib/cmake/falutez
#)

write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/falutezConfigVersion.cmake
  VERSION 0.0.1
  COMPATIBILITY AnyNewerVersion
)

install(FILES
  #${CMAKE_CURRENT_BINARY_DIR}/falutezConfig.cmake
  ${CMAKE_CURRENT_BINARY_DIR}/falutezConfigVersion.cmake
  DESTINATION lib/cmake/falutez
)
