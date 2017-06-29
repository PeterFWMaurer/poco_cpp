cmake_minimum_required(VERSION 3.8)

project(helloworld,C++)

#add_compile_options(-std=c++14)

enable_testing()

# google test will be searched in our intallation dir
set(GTEST_ROOT ${INST_DIR}/usr/local)
message("GTEST_ROOT: ${GTEST_ROOT}")
find_package(GTest REQUIRED)

include_directories(
    ${GTEST_INCLUDE_DIRS},
)

add_subdirectory(HelloWorld)
