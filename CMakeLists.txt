﻿cmake_minimum_required(VERSION 3.26)

project(EXERCISE)

set(CMAKE_CXX_STANDARD 20)

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

# add_compile_options(-fno-elide-constructors) # RVO NRVO

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC)

include_directories(${PROJECT_SOURCE_DIR}/include)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(main ${SRC})
