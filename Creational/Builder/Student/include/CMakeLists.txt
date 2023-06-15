add_library(StudentInclude INTERFACE)

add_library(Builder::Student::Include ALIAS StudentInclude)

target_include_directories(StudentInclude INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})