cmake_minimum_required(VERSION 4.1)
project(cpp_minesweeper)

set(CMAKE_CXX_STANDARD 23)

find_package(SFML COMPONENTS Network Graphics Window Audio System CONFIG REQUIRED)

add_executable(cpp_minesweeper src/main.cpp
        src/class/Tile.cpp
        src/class/Tile.h
        src/class/Field.cpp
        src/class/Field.h
        src/static/RandomGenerator.cpp
        src/static/RandomGenerator.h
        src/struct/Textures.cpp
        src/struct/Textures.h
)
target_link_libraries(cpp_minesweeper PRIVATE SFML::Network SFML::Graphics SFML::Window SFML::Audio SFML::System)