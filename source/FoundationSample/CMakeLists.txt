# include_directories(inc)
include_directories(include)

set(APP_NAME FoundationSample)
string(CONCAT TEST_NAME "test_" ${LIB_NAME})

set(APP_SOURCES
    source/SampleApp.cpp
 )

set(TEST_SOURCES
    #
)

add_executable(${APP_NAME}
	${APP_SOURCES}
)

set_target_properties(${APP_NAME} PROPERTIES LINKER_LANGUAGE CXX)

set_property(TARGET ${APP_NAME} PROPERTY CXX_STANDARD 14)

target_link_libraries(${APP_NAME} 
    SampleSubsystem
    TypeDemo
    ThreadDemo
    ErrorDemo
    MemoryDemo
    EventDemo
    NotificationDemo
    Poco::Foundation
    Poco::Util
)

install(TARGETS ${APP_NAME} 
		RUNTIME DESTINATION bin)

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



