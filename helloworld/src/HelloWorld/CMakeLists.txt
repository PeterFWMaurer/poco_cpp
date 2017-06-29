# include_directories(inc)
include_directories(inc)

set(APP_NAME HelloWorld)
string(CONCAT TEST_NAME "test_" ${APP_NAME})

set (APP_MAIN
    src/HelloWorld.cxx
)

set(APP_SOURCES
    src/HelloHelper.cxx
)

set(TEST_SOURCES
    test/HelloHelper_test.cxx
)

add_executable(${APP_NAME}
	${APP_MAIN}
	${APP_SOURCES}
)

target_compile_features(${APP_NAME} PUBLIC cxx_std_14)

add_executable(${TEST_NAME}
    ${APP_SOURCES}
    ${TEST_SOURCES}
)

target_link_libraries(${TEST_NAME}
    ${GTEST_BOTH_LIBRARIES}
    ${GMOCK_LIBS}
    Threads::Threads
)

target_compile_features(${TEST_NAME} PUBLIC cxx_std_14)
 
add_test(${TEST_NAME} ${TEST_NAME})



