cmake_minimum_required(VERSION 3.5)

add_executable(main main.cpp)

include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}/../lib
)

target_link_libraries(main lib)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/points.txt
    ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)