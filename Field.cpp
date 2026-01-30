#include "Field.h"
#include "RandomGenerator.h"
#include <iostream>

Field::Field(int width, int height, float density) {
    m_width = width;
    m_height = height;
    m_density = density;
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

void Field::printFieldToConsole() {
    for (int y = 0; y < m_height; y++) {
        for (int x = 0; x < m_width; x++) {
            std::cout << m_minefield[y][x].getIsMine();
        }
        std::cout << std::endl;
    }
}
