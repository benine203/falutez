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
  gtest
  cpptrace
)

# pkg_check_modules(LIBTACO taco)
# find_package_handle_standard_args(LIBTACO DEFAULT_MSG LIBTACO_LIBRARIES LIBTACO_INCLUDE_DIRS)

find_package(glaze CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
find_package(restclient-cpp CONFIG REQUIRED)
find_package(CURL REQUIRED)
find_package(cpptrace CONFIG REQUIRED)
find_package(GTest CONFIG REQUIRED)
include(GoogleTest)

#############################################
##  target defns

add_library(falutez STATIC src/falutez.cpp include/falutez/falutez.hpp include/falutez/serio.hpp)

target_include_directories(falutez PUBLIC  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:include>)

target_sources(falutez INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/falutez/falutez.hpp>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/falutez/serio.hpp>
  $<INSTALL_INTERFACE:include/falutez/falutez.hpp>
  $<INSTALL_INTERFACE:include/falutez/serio.hpp>
)

target_link_libraries(falutez PUBLIC
    CURL::libcurl
    restclient-cpp
    glaze::glaze
    nlohmann_json::nlohmann_json
    cpptrace::cpptrace
)

generate_export_header(falutez)
#target_compile_definitions(falutez INTERFACE FALUTEZ_EXPORTS)



########################################33
##         testing

enable_testing()

add_executable(test-serio tests/test-serio.cpp)

target_link_libraries(test-serio PRIVATE falutez GTest::gtest)

gtest_discover_tests(test-serio)

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
