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
        for (int x = 0; x < m_height; x++) {
            m_minefield.push_back(Tile(x, y, RandomGenerator::randomBool(m_density)));
        }
    }
}

int Field::m_calcTileIndex(int x, int y) {
    int tileIndex = y * m_width + x;
    return tileIndex;
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
            int tileIndex = m_calcTileIndex(x, y);
            std::cout << "|" << m_minefield[tileIndex].getX() << "," << m_minefield[tileIndex].getY();
        }
        std::cout << "|" << std::endl;
    }
}

void Field::probeTile(int x, int y) {
    int tileIndex = m_calcTileIndex(x, y);
    m_minefield[tileIndex].probe();
    if (m_minefield[tileIndex].getIsMine()) {
        terminateField();
    }
}

void Field::flagTile(int x, int y) {
    int tileIndex = m_calcTileIndex(x, y);
    m_minefield[tileIndex].flag();
}

void Field::terminateField() {
    std::cout << "Boom" << std::endl;
    m_isAlive = false;
}
