cmake_minimum_required(VERSION 3.10) # specify the minimum version of cmake to run

project(she-plus-plus) # name of the project

set(CMAKE_CXX_STANDARD 17) # which c++ version to use
set(CMAKE_CXX_FLAGS "-Wall")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(${PROJECT_NAME} main.cpp) # the exeexecutable name

add_subdirectory(Basic-CPP) # connect other directory within this root directory

target_include_directories(${PROJECT_NAME} PUBLIC Basic-CPP) # we can add this so that we can use #include <folder> instead of #include "folder"

target_link_directories(${PROJECT_NAME} PRIVATE Basic-CPP) # link this root folder into the given sub folder

target_link_libraries(${PROJECT_NAME} basic) # link this project with the given library name
