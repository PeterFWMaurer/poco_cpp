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

message(DEBUG " CONFIG " ${CONFIG})

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_DEBUG")

message(STATUS "C_FLAGS:  =${CMAKE_C_FLAGS}")
message(STATUS "CMAKE_C_FLAGS_DEBUG:=${CMAKE_C_FLAGS_DEBUG}")
message(STATUS "CMAKE_C_FLAGS_RELEASE:=${CMAKE_C_FLAGS_RELEASE}")
message(STATUS "CMAKE_C_FLAGS_MINSIZEREL:=${CMAKE_C_FLAGS_MINSIZEREL}")
message(STATUS "CMAKE_C_FLAGS_RELWITHDEBINFO:=${CMAKE_C_FLAGS_RELWITHDEBINFO}")
message(STATUS "")
message(STATUS "")
message(STATUS "CXX_FLAGS:=${CMAKE_CXX_FLAGS}")
message(STATUS "CMAKE_CXX_FLAGS_DEBUG:=${CMAKE_CXX_FLAGS_DEBUG}")
message(STATUS "CMAKE_CXX_FLAGS_RELEASE:=${CMAKE_CXX_FLAGS_RELEASE}")
message(STATUS "CMAKE_CXX_FLAGS_MINSIZEREL:=${CMAKE_CXX_FLAGS_MINSIZEREL}")
message(STATUS "CMAKE_CXX_FLAGS_RELWITHDEBINFO:=${CMAKE_CXX_FLAGS_RELWITHDEBINFO}")

include_directories(
   SampleSubsystem/include
   TypeDemo/include
   ErrorDemo/include
   ThreadDemo/include
   MemoryDemo/include
   ${CMAKE_PREFIX_PATH/inlclude}
)


add_subdirectory(PocoSample)

add_subdirectory(SampleSubsystem)
add_subdirectory(TypeDemo)
add_subdirectory(ErrorDemo)
add_subdirectory(MemoryDemo)
add_subdirectory(ThreadDemo)
add_subdirectory(FoundationSample)

