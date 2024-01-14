cmake_minimum_required(VERSION 3.27)
project(data_structure_and_algorithm_cpp)

find_package(Catch2 3 REQUIRED)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

add_executable(data_structure_and_algorithm_cpp src/main.cpp
        src/ArrayList/ArrayList.h
        src/LinkedList/LinkedList.h
        src/LinkedList/LinkedNode.h
        )