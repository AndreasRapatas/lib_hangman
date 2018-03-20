cmake_minimum_required(VERSION 3.3.0)
project(lib_hangman VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Target to LINK
add_library(lib_hangman ./src/hangman.cpp)

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

# Target to TEST
add_executable(
	Tests
	./tests/main.cpp
	./tests/filters.cpp
	./tests/frequency_counter.cpp
	./tests/next_char.cpp
	./tests/positions.cpp
)

target_link_libraries(
	Tests
	PRIVATE
		lib_hangman
)

install(
	EXPORT      lib_hangman-targets
	FILE        lib_hangmanTargets.cmake
	NAMESPACE   lib_hangman::
	DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/lib_hangman
)

