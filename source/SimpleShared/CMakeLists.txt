include_directories(include)

set(LIB_NAME SimpleShared)
string(CONCAT TEST_NAME "test_" ${LIB_NAME})

set(LIB_SOURCES
    source/SimpleShared.cpp
    source/HelloPluginImpl.cpp
)

add_library(${LIB_NAME} SHARED
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

install(TARGETS ${LIB_NAME} 
		LIBRARY DESTINATION lib)


