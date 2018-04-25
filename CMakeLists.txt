cmake_minimum_required(VERSION 3.0)
project(lib_hangman VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Target to LINK
add_library(
	lib_hangman
	./src/hangman.cpp
)

target_include_directories(
	lib_hangman
	PUBLIC
		$<INSTALL_INTERFACE:include>
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_compile_options(
	lib_hangman
	PRIVATE
		-Werror
		-Wall
)

# =======
# Testing
# =======

# To run the tests, Install https://github.com/catchorg/Catch2

include(CTest)
find_package(Catch2 CONFIG QUIET)
if (BUILD_TESTING AND Catch2_FOUND)

	add_executable(
		${PROJECT_NAME}_test
		./tests/main.cpp
		./tests/filters.cpp
		./tests/frequency_counter.cpp
		./tests/next_char.cpp
		./tests/positions.cpp
	)

	target_link_libraries(
		${PROJECT_NAME}_test
		PRIVATE
			Catch2::Catch
			lib_hangman
	)

	add_test(
		NAME ${PROJECT_NAME}_test
		COMMAND ${PROJECT_NAME}_test
	)

endif()

