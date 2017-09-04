include_directories(include)

set(LIB_NAME ThreadDemo)
string(CONCAT TEST_NAME "test_" ${LIB_NAME})

set(LIB_SOURCES
	source/EventSample.cpp
    source/ThreadSample.cpp
    source/ThreadPoolSample.cpp
    source/ThreadDemoSub.cpp
    source/MutexSample.cpp
)

set(TEST_SOURCES
    #
)

add_library(${LIB_NAME}
	${LIB_SOURCES}
)
#
# in our code, we are using C++14
#
set_property(TARGET ${LIB_NAME} PROPERTY CXX_STANDARD 14)

#
# We explicitely set the linker language to C++
#
set_target_properties(${LIB_NAME} PROPERTIES LINKER_LANGUAGE CXX)

#target_link_libraries(${LIB_NAME} 
#    Poco::Foundation
#)

#add_executable(${TEST_NAME}
#    ${LIB_SOURCES}
#    ${TEST_SOURCES}
#)

#target_link_libraries(${TEST_NAME}
#    ${GTEST_BOTH_LIBRARIES}
#    ${GMOCK_LIBS}
#    Threads::Threads
#)

#set_property(TARGET ${TEST_NAME} PROPERTY CXX_STANDARD 14)

#add_test(${TEST_NAME} ${TEST_NAME})



