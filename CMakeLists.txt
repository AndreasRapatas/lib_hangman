cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 14)


# Prepare "Catch" library for other executables
set(
	CATCH_INCLUDE_DIR
	${CMAKE_CURRENT_SOURCE_DIR}/third_party/catch2/single_include
)
add_library(Catch INTERFACE)
target_include_directories(
	Catch INTERFACE
	${CATCH_INCLUDE_DIR}
)

# Make test executable
set(
	TEST_SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/tests/basic_testing.cpp
)
add_executable(Tests ${TEST_SOURCES})
target_link_libraries(Tests Catch)

