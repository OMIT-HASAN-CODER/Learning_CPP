cmake_minimum_required(VERSION 4.0)
project(Learning_CPP)

set(CMAKE_CXX_STANDARD 23)

add_executable(Learning_CPP main.cpp
        01_varconst/main.cpp
        02_primitives/data.cpp
        02_primitives/modifier.cpp
        02_primitives/casting.cpp
        02_primitives/myString.cpp
        02_primitives/userinput.cpp)
