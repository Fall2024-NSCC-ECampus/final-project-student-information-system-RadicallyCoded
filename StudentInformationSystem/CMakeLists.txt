cmake_minimum_required(VERSION 3.27)
project(StudentInformationSystem)

set(CMAKE_CXX_STANDARD 17)

add_executable(StudentInformationSystem main.cpp
        Student.cpp
        menus.cpp
        Grades.cpp)
