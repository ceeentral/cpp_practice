cmake_minimum_required(VERSION 3.13)
project(practice_cpp)
set(CMAKE_CXX_STANDARD 14)
set(SRC  ${PROJECT_SOURCE_DIR}/stl.cpp)
set(SRC  ${PROJECT_SOURCE_DIR}/structTest.cpp)
set(SRC  ${PROJECT_SOURCE_DIR}/data_structure_temp.cpp)
add_executable(practice_cpp stl.cpp)
add_executable(test_cpp structTest.cpp)
add_executable(test1_cpp test_temp.cpp)
add_executable(data_ data_structure_temp.cpp)