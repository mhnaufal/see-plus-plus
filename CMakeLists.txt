cmake_minimum_required(VERSION 3.10)

project(she-plus-plus)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(main main.cpp)
