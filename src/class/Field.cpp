#include "./Field.h"
#include "./RandomGenerator.h"
#include <iostream>

Field::Field(int width, int height, float density) {
    m_width = width;
    m_height = height;
    m_density = density;
    m_isAlive = true;
    m_generateTiles();
}

void Field::m_generateTiles() {
    for (int y = 0; y < m_height; y++) {
        std::vector<Tile> tileRow;
        for (int x = 0; x < m_height; x++) {
            tileRow.push_back(Tile(x, y, RandomGenerator::randomBool(m_density)));
        }
        m_minefield.push_back(tileRow);
    }
}

int Field::getMineCount() {
    return m_mineCount;
}

bool Field::getIsAlive() {
    return m_isAlive;
}

void Field::printFieldToConsole() {
    for (int y = 0; y < m_height; y++) {
        for (int x = 0; x < m_width; x++) {
            if (m_minefield[y][x].getIsProbed()) {
                std::cout << "|X";
            } else {
                std::cout << "| ";
            }
        }
        std::cout << std::endl;
    }
}

void Field::probeTile(int x, int y) {
    m_minefield[y][x].probe();
    if (m_minefield[y][x].getIsMine()) {
        terminateField();
    }
}

void Field::flagTile(int x, int y) {
    m_minefield[y][x].flag();
}

void Field::terminateField() {
    std::cout << "Boom" << std::endl;
    m_isAlive = false;
}
