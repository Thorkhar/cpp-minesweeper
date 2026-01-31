#ifndef CPP_MINESWEEPER_FIELD_H
#define CPP_MINESWEEPER_FIELD_H
#include <vector>
#include "Tile.h"

class Field {
    int m_width, m_height, m_mineCount;
    float m_density;
    bool m_isAlive;
    std::vector<std::vector<Tile> > m_minefield;

    void m_generateTiles();

public:
    Field(int width, int height, float density);

    int getMineCount();

    bool getIsAlive();

    void printFieldToConsole();

    void probeTile(int x, int y);

    void flagTile(int x, int y);

    void terminateField();
};

#endif //CPP_MINESWEEPER_FIELD_H
