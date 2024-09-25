cmake_minimum_required(VERSION 3.2)

project(BeginTask-0)

add_executable(main main.cpp tests.cpp)
target_link_libraries(main gtest gmock pthread)