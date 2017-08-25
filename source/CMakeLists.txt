cmake_minimum_required(VERSION 3.8)

project(helloworld)

enable_testing()  
  
# google test will be searched in our intallation dir
set(GTEST_ROOT ${CMAKE_INSTALL_PREFIX})
message("GTEST_ROOT: ${GTEST_ROOT}")
find_package(GTest REQUIRED)

include_directories(
    ${GTEST_INCLUDE_DIRS}
)

find_package(Poco REQUIRED COMPONENTS 
    Foundation
    Util
)

message(DEBUG " POCO_FOUNDATION_FOUND " ${POCO_FOUNDATION_FOUND})
message(DEBUG " POCO_FOUNDATION_LIBRARY " ${POCO_FOUNDATION_LIBRARY})

message(DEBUG " POCO_INCLUDE_DIRS " ${POCO_INCLUDE_DIRS})

include_directories(
   SampleSubsystem/include
   TypeDemo/include
   ${CMAKE_PREFIX_PATH/inlclude}
)


add_subdirectory(PocoSample)

add_subdirectory(SampleSubsystem)
add_subdirectory(TypeDemo)
add_subdirectory(FoundationSample)

