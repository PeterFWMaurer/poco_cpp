# include_directories(inc)
include_directories(include)

set(APP_NAME SharedDemo)
string(CONCAT APP_NAME ${APP_NAME} ${CMAKE_DEBUG_POSTFIX})
string(CONCAT TEST_NAME "test_" ${LIB_NAME})

set(APP_SOURCES
    source/SharedDemoMain.cpp
 )

add_executable(${APP_NAME}
	${APP_SOURCES}
)

set_target_properties(${APP_NAME} PROPERTIES LINKER_LANGUAGE CXX)

set_property(TARGET ${APP_NAME} PROPERTY CXX_STANDARD 14)

target_link_libraries(${APP_NAME} 
    Poco::Foundation
    Poco::Util
    Poco::Net
)

install(TARGETS ${APP_NAME} 
		RUNTIME DESTINATION bin)


