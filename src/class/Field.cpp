#include "../class/Field.h"
#include "../static/RandomGenerator.h"
#include <iostream>
#include <stdexcept>

Field::Field(int width, int height, float density) {
    if (density <= 0 || density >= 1) {
        throw std::invalid_argument("Invalid density, should be a value between 0 and 1");
    }

    if (width <= 0 || height <= 0) {
        throw std::invalid_argument("Invalid field dimensions");
    }

    m_width = width;
    m_height = height;
    m_density = density;
    m_isAlive = true;
    m_generateTiles();
    m_calculateNeighbours();
}

void Field::m_generateTiles() {
    for (int y = 0; y < m_height; y++) {
        for (int x = 0; x < m_height; x++) {
            m_minefield.push_back(Tile(x, y, RandomGenerator::randomBool(m_density)));
        }
    }
}

void Field::m_calculateNeighbours() {
    for (int y = 0; y < m_height; y++) {
        for (int x = 0; x < m_width; x++) {
            int minesNear = 0;
            std::vector<std::pair<int, int> > neighbours;
            for (int dx = x - 1; dx <= x + 1; dx++) {
                for (int dy = y - 1; dy <= y + 1; dy++) {
                    if (!(dx == x && dy == y)) {
                        neighbours.emplace_back(dx, dy);
                    }
                }
            }

            for (auto &[dx, dy]: neighbours) {
                if (dx >= 0 && dx < m_width && dy >= 0 && dy < m_height) {
                    if (m_minefield[m_calcTileIndex(dx, dy)].getIsMine()) minesNear++;
                }
            }

            m_minefield[m_calcTileIndex(x, y)].setMinesNear(minesNear);
        }
    }
}

void Field::m_probeSpread(int origin_x, int origin_y) {
    std::vector<std::pair<int, int> > neighbours;
    for (int dx = origin_x - 1; dx <= origin_x + 1; dx++) {
        for (int dy = origin_y - 1; dy <= origin_y + 1; dy++) {
            if (!(dx == origin_x && dy == origin_y)) {
                neighbours.emplace_back(dx, dy);
            }
        }
    }

    for (auto &[dx, dy]: neighbours) {
        if (dx >= 0 && dx < m_width && dy >= 0 && dy < m_height) {
            if (!m_minefield[m_calcTileIndex(dx, dy)].getIsProbed()) probeTile(dx, dy);
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

void Field::probeTile(int x, int y) {
    int tileIndex = m_calcTileIndex(x, y);
    m_minefield[tileIndex].probe();
    if (m_minefield[tileIndex].getIsMine()) {
        m_isAlive = false;
    }

    if (m_minefield[tileIndex].getMinesNear() == 0 && !m_minefield[tileIndex].getIsMine()) {
        m_probeSpread(x, y);
    }
}

void Field::flagTile(int x, int y) {
    int tileIndex = m_calcTileIndex(x, y);
    m_minefield[tileIndex].flag();
}

void Field::resetField() {
    m_isAlive = true;
    m_minefield.clear();
    m_generateTiles();
    m_calculateNeighbours();
}

std::vector<Tile> Field::getMinefield() {
    return m_minefield;
}
