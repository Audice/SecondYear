cmake_minimum_required(VERSION 3.16)

project(BitField-2)

Include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.15.2
)

FetchContent_MakeAvailable(googletest)

add_executable(main main.cpp BitField.cpp Set.cpp tests.cpp)

target_link_libraries(main gtest gmock)