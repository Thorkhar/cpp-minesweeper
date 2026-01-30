cmake_minimum_required(VERSION 4.1)
project(cpp_minesweeper)

set(CMAKE_CXX_STANDARD 23)

add_executable(cpp_minesweeper main.cpp
        Tile.cpp
        Tile.h
        Field.cpp
        Field.h
        RandomGenerator.cpp
        RandomGenerator.h)
