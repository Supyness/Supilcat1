cmake_minimum_required(VERSION 2.6)
project(task2_h)
set(SOURCE "./C/main.cpp")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)

add_custom_command(
	OUTPUT index.h
	COMMAND python ../A/preparing.py
	COMMENT "Generating"
)

add_executable(C ${SOURCE})

add_custom_target(generate DEPENDS index.h)
add_dependencies(C generate)

add_subdirectory(B)
target_link_libraries(C B)
target_include_directories(C PRIVATE ${CMAKE_SOURCE_DIR})
