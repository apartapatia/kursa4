cmake_minimum_required(VERSION 3.23)
project(untitled8)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "-static")
set(CMAKE_FIND_LIBRARY_SUFFIXES ".a" CONFIG)
set(BUILD_SHARED_LIBS OFF)

add_executable(untitled8 main.cpp MST.cpp MST.h menu.h)
