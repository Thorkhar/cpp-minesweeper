cmake_minimum_required(VERSION 4.1)
project(cpp_minesweeper)

set(CMAKE_CXX_STANDARD 23)

add_executable(cpp_minesweeper src/main.cpp
        src/class/Tile.cpp
        src/class/Tile.h
        src/class/Field.cpp
        src/class/Field.h
        src/class/RandomGenerator.cpp
        src/class/RandomGenerator.h)
target_link_libraries(cpp_minesweeper
        sfml-graphics
        sfml-window
        sfml-system
)