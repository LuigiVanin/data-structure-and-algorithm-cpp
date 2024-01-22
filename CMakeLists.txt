cmake_minimum_required(VERSION 3.21)
project(data_structure_and_algorithm_cpp)

# find_package(Catch2 3 REQUIRED)

set(CMAKE_CXX_STANDARD 23)
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
)

set_target_properties(${PROJECT_LIB_NAME} PROPERTIES LINKER_LANGUAGE CXX)

add_executable(${PROJECT_BIN_NAME} src/main.cpp)

target_link_libraries(${PROJECT_BIN_NAME} ${PROJECT_LIB_NAME})

add_executable(cpp_test tests/test.cpp)
add_executable(cpp_test_2 tests/test-2.cpp)

target_link_libraries(cpp_test PRIVATE ${PROJECT_LIB_NAME})

enable_testing()

add_test(FIRST_TEST ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/cpp_test)
add_test(SECOND_TEST ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/cpp_test_2)