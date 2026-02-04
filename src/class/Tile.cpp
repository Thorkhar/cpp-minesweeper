#include "./Tile.h"
#include <stdexcept>

Tile::Tile(int x, int y, bool isMine) {
    if (x < 0 || y < 0) {
        throw std::invalid_argument("Invalid tile coordinates");
    }

    m_x = x;
    m_y = y;
    m_isMine = isMine;
    m_isFlagged = false;
    m_isProbed = false;
    m_minesNear = 0;
}

int Tile::getX() {
    return m_x;
}

int Tile::getY() {
    return m_y;
}

int Tile::getIsMine() {
    return m_isMine;
}

bool Tile::getIsFlagged() {
    return m_isFlagged;
}

bool Tile::getIsProbed() {
    return m_isProbed;
}

int Tile::getMinesNear() {
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
