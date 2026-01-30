#ifndef CPP_MINESWEEPER_TILE_H
#define CPP_MINESWEEPER_TILE_H


class Tile {
    int m_x, m_y, m_minesNear;
    bool m_isMine, m_isFlagged, m_isProbed;

public:
    Tile(int x, int y, bool isMine);

    int getIsMine();

    bool getIsFlagged();

    bool getIsProbed();

    bool getMinesNear();

    void setMinesNear(int nMines);

    void probe();

    void flag();
};


#endif //CPP_MINESWEEPER_TILE_H
