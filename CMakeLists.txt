cmake_minimum_required(VERSION 3.10) # specify the minimum version of cmake to run

project(she-plus-plus) # name of the project

set(CMAKE_CXX_STANDARD 17) # which c++ version to use
set(CMAKE_CXX_FLAGS "-Wall")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_PREFIX_PATH "~/temp/libtorch")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")

add_executable(${PROJECT_NAME} main.cpp) # the exeexecutable name

target_include_directories(${PROJECT_NAME} PUBLIC Basic-CPP Modern-CPP Object-Oriented-CPP Pointer-CPP Testing-CPP Nodeflux) # we can add this so that we can use #include <folder> instead of #include "folder"

target_link_directories(${PROJECT_NAME} PRIVATE Basic-CPP Modern-CPP Object-Oriented-CPP Pointer-CPP Testing-CPP Nodeflux) # link this root folder into the given sub folder

target_link_libraries(${PROJECT_NAME} basic modern oop pointer test nodeflux) # link this project with the given library name

# Prepare doctest for other targets to use
#find_package(doctest REQUIRED)

#################
# doctest #
#################
#add_executable(tests test.cpp)
#target_compile_features(tests PRIVATE cxx_std_17)
#target_link_libraries(tests PRIVATE doctest)
#include_directories(Testing-CPP)

#################
# Boost #
#################
find_package(Boost COMPONENTS context fiber date_time REQUIRED)
if (Boost_FOUND)
    target_include_directories(${PROJECT_NAME} PUBLIC ${Boost_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} Boost::fiber Boost::context Boost::date_time)
endif ()

#################
# libasyik #
#################
find_package(libasyik)
if (libasyik_FOUND)
    target_include_directories(${PROJECT_NAME} PUBLIC ${libasyik_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} libasyik)
endif ()

#################
# SOCI #
#################
find_package(SOCI REQUIRED)
if (SOCI_FOUND)
    target_include_directories(${PROJECT_NAME} PUBLIC /usr/include/postgresql)
    target_include_directories(${PROJECT_NAME} PUBLIC /usr/local/include/soci)
    target_include_directories(${PROJECT_NAME} PUBLIC /usr/local/include/soci/postgresql)
    target_include_directories(${PROJECT_NAME} PUBLIC /usr/local/include/soci/sqlite3)
    target_link_libraries(${PROJECT_NAME} SOCI::soci_core SOCI::soci_postgresql SOCI::soci_sqlite3)
endif ()

find_package(Threads REQUIRED)
target_link_libraries(${PROJECT_NAME} Threads::Threads)

find_package(OpenSSL REQUIRED)
target_link_libraries(${PROJECT_NAME} OpenSSL::SSL)

#################
# Libtorch #
#################
list(APPEND CMAKE_PREFIX_PATH "~/temp/libtorch")
find_package(Torch REQUIRED)
target_link_libraries(${PROJECT_NAME} ${TORCH_LIBRARIES})
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)

add_subdirectory(Basic-CPP) # connect other directory within this root directory
add_subdirectory(Modern-CPP)
add_subdirectory(Object-Oriented-CPP)
add_subdirectory(Pointer-CPP)
add_subdirectory(Testing-CPP)
add_subdirectory(Nodeflux)

#################
# pybind module #
#################
#pybind11_add_module(example_module main.cpp)
