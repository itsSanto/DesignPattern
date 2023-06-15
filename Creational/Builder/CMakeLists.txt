
cmake_minimum_required(VERSION 3.20.0)

project(Builder)

add_subdirectory(Student)

add_executable(${PROJECT_NAME} Builder.cpp)

target_link_libraries(${PROJECT_NAME} Builder::Student)

