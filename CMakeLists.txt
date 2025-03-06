cmake_minimum_required(VERSION 3.21)

project(data_structure_and_algorithm_cpp)

find_package(Catch2 3 REQUIRED)

# Set the C++ standard to C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/lib)

set(PROJECT_BIN_NAME ${PROJECT_NAME})
set(PROJECT_LIB_NAME ${PROJECT_NAME}_lib)

add_library(
        ${PROJECT_LIB_NAME}
        src/ArrayList/ArrayList.h
        src/LinkedList/LinkedList.h
        src/LinkedList/LinkedNode.h
        src/DoublyLinkedList/DoublyLinkedList.h
        src/DoublyLinkedList/DoublyLinkedNode.h
        src/ArrayStack/ArrayStack.h
        src/LinkedQueue/LinkedQueue.h
        src/Hashmap/Hashmap.h
        src/Hashmap/Tuple.h
        src/BinarySearchTree/BinarySearchTree.h
        src/utils/errors.h
        src/utils/option.h
)

set_target_properties(${PROJECT_LIB_NAME} PROPERTIES LINKER_LANGUAGE CXX)

add_executable(${PROJECT_BIN_NAME} src/main.cpp)

target_link_libraries(${PROJECT_BIN_NAME} ${PROJECT_LIB_NAME})

file(GLOB SOURCES tests/*.cpp)

enable_testing()

foreach(test_source ${SOURCES})
    get_filename_component(test_file_name ${test_source} NAME)
    get_filename_component(test_exec_name ${test_source} NAME_WE)
    
    message(${test_file_name} - ${test_exec_name})

    add_executable(project_${test_exec_name} tests/${test_file_name})
    target_link_libraries(project_${test_exec_name} PRIVATE Catch2::Catch2WithMain ${PROJECT_LIB_NAME})
    add_test(NAME ${test_exec_name} COMMAND project_${test_exec_name})
endforeach()
