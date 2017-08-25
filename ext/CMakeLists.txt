#
# This CMake file builds all projects in ext directory
#
cmake_minimum_required(VERSION 3.8)

include(ExternalProject)

#
# GoogleTest / GoogleMock
#

message(debug "Start External Make")

ExternalProject_Add(
    GoogleTest

    GIT_SUBMODULES googletest
    GIT_TAG "release-1.8.0"
    PATCH_COMMAND ""
   
    SOURCE_DIR ${EXT_DIR}/googletest
    CMAKE_ARGS -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE} -DCMAKE_DEBUG_POSTFIX=${CMAKE_DEBUG_POSTFIX} -DCMAKE_INSTALL_PREFIX=${CMAKE_INSTALL_PREFIX}
    TEST_COMMAND ""
)
#
# Poco C++
#
ExternalProject_Add(
    Poco

    SOURCE_DIR ${EXT_DIR}/poco
    
    GIT_SUBMODULES poco
    GIT_TAG "poco-1.7.8p3-release"
    PATCH_COMMAND ""
    CMAKE_ARGS -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE} -DCMAKE_DEBUG_POSTFIX=${CMAKE_DEBUG_POSTFIX} -DCMAKE_INSTALL_PREFIX=${CMAKE_INSTALL_PREFIX}
    TEST_COMMAND ""
)
