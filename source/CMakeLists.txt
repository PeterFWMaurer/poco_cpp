cmake_minimum_required(VERSION 3.8)

project(helloworld,C++)

enable_testing()

# include make of external projects used for build
include(${EXT_DIR}/CMakeListsExt.cmake)

# google test will be searched in our intallation dir
set(GTEST_ROOT ${CMAKE_INSTALL_PREFIX})
message("GTEST_ROOT: ${GTEST_ROOT}")
find_package(GTest REQUIRED)

include_directories(
    ${GTEST_INCLUDE_DIRS},
)

add_subdirectory(HelloWorld)
