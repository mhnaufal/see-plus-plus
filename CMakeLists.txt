cmake_minimum_required(VERSION 3.10) # specify the minimum version of cmake to run

project(she-plus-plus) # name of the project

set(CMAKE_CXX_STANDARD 17) # which c++ version to use
set(CMAKE_CXX_FLAGS "-Wall")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(${PROJECT_NAME} main.cpp) # the exeexecutable name

add_subdirectory(Basic-CPP) # connect other directory within this root directory
add_subdirectory(Modern-CPP)
add_subdirectory(Object-Oriented-CPP)
add_subdirectory(Pointer-CPP)
add_subdirectory(Testing-CPP)
add_subdirectory(Nodeflux)

target_include_directories(${PROJECT_NAME} PUBLIC Basic-CPP Modern-CPP Object-Oriented-CPP Pointer-CPP Testing-CPP Nodeflux) # we can add this so that we can use #include <folder> instead of #include "folder"

target_link_directories(${PROJECT_NAME} PRIVATE Basic-CPP Modern-CPP Object-Oriented-CPP Pointer-CPP Testing-CPP Nodeflux) # link this root folder into the given sub folder

target_link_libraries(${PROJECT_NAME} basic modern oop pointer test nodeflux) # link this project with the given library name

# Prepare doctest for other targets to use
#find_package(doctest REQUIRED)

# doctest
#add_executable(tests test.cpp)
#target_compile_features(tests PRIVATE cxx_std_17)
#target_link_libraries(tests PRIVATE doctest)
#include_directories(Testing-CPP)
