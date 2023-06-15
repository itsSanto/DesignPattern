add_subdirectory(include)

add_library(Student STATIC Student.cpp)

add_library(Builder::Student ALIAS Student)

target_link_libraries(Student PUBLIC Builder::Student::Include)