cmake_minimum_required(VERSION 3.10)
project(CreateAccountTests LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_library(validator
  src/CreateAccountValidator.cpp
)

add_executable(validator_test
  tests/CreateAccountValidator_test.cpp
)
target_link_libraries(validator_test
  validator
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(validator_test)
