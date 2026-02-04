#ifndef CPP_MINESWEEPER_FIELD_H
#define CPP_MINESWEEPER_FIELD_H
#include <vector>
#include "Tile.h"

class Field {
    int m_width, m_height, m_mineCount;
    float m_density;
    bool m_isAlive;
    std::vector<Tile> m_minefield;

    void m_generateTiles();

    void m_calculateNeighbours();

    void m_probeSpread(int origin_x, int origin_y);

    int m_calcTileIndex(int x, int y);

public:
    Field(int width, int height, float density);

    int getMineCount();

    bool getIsAlive();

    void probeTile(int x, int y);

    void flagTile(int x, int y);

    void resetField();

    std::vector<Tile> getMinefield();
};

#endif //CPP_MINESWEEPER_FIELD_H
