#include "Field.h"
#include "RandomGenerator.h"
#include "Tile.h"
#include <vector>
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
            Tile tile = Tile(x, y, RandomGenerator::randomBool(m_density));
            tileRow.push_back(tile);
            if (tile.getIsMine()) {
                m_mineCount++;
            }
        }
        m_minefield.push_back(tileRow);
    }
}

void Field::printFieldToConsole() {
    for (int y = 0; y < m_height; y++) {
        for (int x = 0; x < m_width; x++) {
            std::cout << m_minefield[y][x].getIsMine();
        }
        std::cout << std::endl;
    }
}
