#
# This CMake file builds all projects in ext directory
#
include(ExternalProject)

#
# GoogleTest / GoogleMock
#
find_path(GTEST_EXT_PATH ${CMAKE_INSTALL_PREFIX}/include/gtest)
message(DEBUG "GTEST_EXT_PATH=" ${GTEST_EXT_PATH})
if(NOT GTEST_EXT_PATH)
    message(GTest not found, building...)
    ExternalProject_Add(
      GoogleTest

      UPDATE_COMMAND git submodule update
      PATCH_COMMAND ""
    
      SOURCE_DIR ${EXT_DIR}/googletest
      BUILD_IN_SOURCE 1
      CMAKE_ARGS -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE} -DCMAKE_DEBUG_POSTFIX=${CMAKE_DEBUG_POSTFIX} -DCMAKE_INSTALL_PREFIX=${CMAKE_INSTALL_PREFIX}
      TEST_COMMAND ""
    )
else()
    message(debug "GTEST_INCLUDE_DIRS = " ${GTEST_INCLUDE_DIRS})
endif()
#
# OpenSSL
#

set(OPENSSL_ROOT_DIR ${CMAKE_INSTALL_PREFIX})
find_package(OpenSSL)

message(debug "OPENSSL_FOUND = " ${OPEN_SSL_FOUND})

#ExternalProject_Add(
#    OpenSSL
#    SOURCE_DIR ${EXT_DIR}/openssl
#    BUILD_IN_SOURCE 1
#    UPDATE_COMMAND git submodule update
#    PATCH_COMMAND ""
#    CONFIGURE_COMMAND ./config --prefix=${CMAKE_INSTALL_PREFIX}
#    BUILD_COMMAND make
#    INSTALL_COMMAND make install
#    TEST_COMMAND ""
#)
#
# Poco C++
#
ExternalProject_Add(
    Poco

    SOURCE_DIR ${EXT_DIR}/poco
    BUILD_IN_SOURCE 1
    
    UPDATE_COMMAND git submodule update
    PATCH_COMMAND ""
    CONFIGURE_COMMAND ./configure --no-tests --no-samples --prefix=${CMAKE_INSTALL_PREFIX} --minimal
    BUILD_COMMAND make
    INSTALL_COMMAND make install
    TEST_COMMAND ""
)
