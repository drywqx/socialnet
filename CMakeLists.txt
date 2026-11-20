cmake_minimum_required(VERSION 3.10)
project(socialnet)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(socialnet
    src/main.cpp
    src/user.cpp
)

target_include_directories(socialnet PRIVATE src)