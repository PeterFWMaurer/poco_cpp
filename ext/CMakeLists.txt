#
# This CMake file builds all projects in ext directory
#
include(ExternalProject)

#
# GoogleTest / GoogleMock
#

message(debug "Start External Make")

ExternalProject_Add(
    GoogleTest

    UPDATE_COMMAND git submodule update
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
    
    UPDATE_COMMAND git submodule update
    PATCH_COMMAND ""
    CMAKE_ARGS -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE} -DCMAKE_DEBUG_POSTFIX=${CMAKE_DEBUG_POSTFIX} -DCMAKE_INSTALL_PREFIX=${CMAKE_INSTALL_PREFIX}
    TEST_COMMAND ""
)
