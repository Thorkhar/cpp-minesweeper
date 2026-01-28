#include <iostream>
#include <random>
using namespace std;

bool randomBool(float p) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::bernoulli_distribution dist(p);
    return dist(gen);
}

class Tile {
    int m_x;
    int m_y;
    bool m_isMine;
    bool m_isFlagged = false;
    bool m_isProbed = false;
    int m_minesNear;

public:
    Tile(int x, int y, bool isMine) : m_x(x), m_y(y), m_isMine(isMine) {
    };

    void Probe() {
        if (!m_isProbed) {
            m_isProbed = true;
        }
    }

    void Flag() {
        if (!m_isProbed) {
            m_isFlagged = !m_isFlagged;
        }
    }

    void setMinesNear(int mineCount) {
        m_minesNear = mineCount;
    }

    int getMinesNear() { return m_minesNear; };

    bool getTileInfo() {
        return (m_isMine);
    }
};

class Field {
    int m_width;
    int m_height;

    vector<vector<Tile> > m_minefield;

    void generateTiles() {
        for (int x = 0; x < m_width; x++) {
            vector<Tile> tileRow;
            for (int y = 0; y < m_height; y++) {
                tileRow.push_back(Tile(x, y, randomBool(0.1)));
            }
            m_minefield.push_back(tileRow);
        }
    }

public:
    Field(int width, int height) : m_width(width), m_height(height) {
        generateTiles();
    };

    void printFieldToConsole() {
        for (int y = 0; y < m_height; y++) {
            for (int x = 0; x < m_width; x++) {
                cout << m_minefield[x][y].getTileInfo();
            }
            cout << endl;
        }
    }
};


int main() {
    Field mineField(10, 10);
    mineField.printFieldToConsole();
    return 0;
}
