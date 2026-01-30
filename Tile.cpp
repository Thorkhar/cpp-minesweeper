#include "Tile.h"

Tile::Tile(int x, int y, bool isMine) {
    m_x = x;
    m_y = y;
    m_isMine = isMine;
    m_isFlagged = false;
    m_isProbed = false;
    m_minesNear = 0;
}

int Tile::getIsMine() {
    if (m_isMine) {
        return 1;
    }
    return 0;
}

bool Tile::getIsFlagged() {
    return m_isFlagged;
}

bool Tile::getIsProbed() {
    return m_isProbed;
}

bool Tile::getMinesNear() {
    return m_minesNear;
}

void Tile::setMinesNear(int nMines) {
    m_minesNear = nMines;
}

void Tile::probe() {
    if (!m_isProbed) {
        m_isProbed = true;
    }
}

void Tile::flag() {
    if (!m_isProbed) {
        m_isFlagged = !m_isFlagged;
    }
}
