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
	TEST_DIR
	${CMAKE_CURRENT_SOURCE_DIR}/tests
)
set(
	SRC_DIR
	${CMAKE_CURRENT_SOURCE_DIR}/src
)
set(
	TEST_SOURCES
	${SRC_DIR}/hangman.cpp
	${TEST_DIR}/main.cpp
	${TEST_DIR}/filters.cpp
	${TEST_DIR}/frequency_counter.cpp
	${TEST_DIR}/next_char.cpp
	${TEST_DIR}/positions.cpp
)
add_executable(Tests ${TEST_SOURCES})
target_link_libraries(Tests Catch)

