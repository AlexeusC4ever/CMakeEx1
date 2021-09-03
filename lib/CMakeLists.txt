cmake_minimum_required(VERSION 3.5)

add_library(lib STATIC interdiff.cpp interdiff.h)
set_target_properties(
	lib PROPERTIES
	CXX_STANDART 11
	CXX_STANDART_REQUIRED ON
)
