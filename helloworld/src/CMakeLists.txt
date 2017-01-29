cmake_minimum_required(VERSION 3.0)

project(helloworld,C++)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} --std=c++14)

enable_testing()

find_package(GTest REQUIRED)

include_directories(
    ${GTEST_INCLUDE_DIRS},
)

add_subdirectory(HelloWorld)
