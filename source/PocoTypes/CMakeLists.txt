# include_directories(inc)
include_directories(include)

set(APP_NAME PocoTypes)
string(CONCAT TEST_NAME "test_" ${LIB_NAME})

set(APP_SOURCES
    source/PocoTypesDemo.cpp
)

set(TEST_SOURCES
    #
)

add_executable(${APP_NAME}
	${APP_SOURCES}
)

message(DEBUG " POCO_FOUNDATION_LIB = " ${POCO_FOUNDATION_LIB})

set_target_properties(${APP_NAME} PROPERTIES LINKER_LANGUAGE CXX)

set_property(TARGET ${APP_NAME} PROPERTY CXX_STANDARD 14)

target_link_libraries(${APP_NAME} 
    Poco::Foundation
)

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



