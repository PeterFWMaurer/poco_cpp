cmake_minimum_required(VERSION 3.8)

project(helloworld,C++)

enable_testing()

# try to find include-what-you-use
find_program(iwyu_path NAMES include-what-you-use iwyu)
#ifma (NOT iwyu_path)
  #message(FATAL_ERROR "Could not find include-what-you-use")
#else()
#  set (iwyu_path_and_options ${iwyu_path} -I/usr/lib/clang/3.5/include -Xiwyu)
  set (iwyu_path_and_options ${iwyu_path} -I/usr/lib/clang/3.5/include)
#  set (iwyu_path_and_options ${iwyu_path})
#endif()

# google test will be searched in our intallation dir
set(GTEST_ROOT ${INST_DIR}/usr/local)
message("GTEST_ROOT: ${GTEST_ROOT}")
find_package(GTest REQUIRED)

include_directories(
    ${GTEST_INCLUDE_DIRS},
)

add_subdirectory(HelloWorld)
