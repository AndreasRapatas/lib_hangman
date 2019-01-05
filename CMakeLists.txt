cmake_minimum_required(VERSION 3.0)

# Required for YCM to work
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(
	hangmansolver
	VERSION 0.2.0
	LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(
	${PROJECT_NAME}
	./src/hangmansolver.cpp
)

target_include_directories(
	${PROJECT_NAME}
	PUBLIC
		$<INSTALL_INTERFACE:include>
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_compile_options(
	${PROJECT_NAME}
	PRIVATE
		-Werror
		-Wall
)

# =============================================================================
#                                    Testing
# =============================================================================

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
			Catch2::Catch2
			${PROJECT_NAME}
	)

	add_test(
		NAME ${PROJECT_NAME}_test
		COMMAND ${PROJECT_NAME}_test
	)

endif()

