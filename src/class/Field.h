#ifndef CPP_MINESWEEPER_FIELD_H
#define CPP_MINESWEEPER_FIELD_H
#include <vector>
#include "Tile.h"

class Field {
    int m_width, m_height, m_mineCount;
    float m_density;
    std::vector<std::vector<Tile> > m_minefield;

    void m_generateTiles();

public:
    Field(int width, int height, float density);

    int getMineCount();

    void printFieldToConsole();
};

#endif //CPP_MINESWEEPER_FIELD_H
