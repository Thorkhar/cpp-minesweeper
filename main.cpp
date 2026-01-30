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
    float m_density;

    vector<vector<Tile> > m_minefield;

    void generateTiles() {
        for (int y = 0; y < m_height; y++) {
            vector<Tile> tileRow;
            for (int x = 0; x < m_height; x++) {
                tileRow.push_back(Tile(x, y, randomBool(m_density)));
            }
            m_minefield.push_back(tileRow);
        }
    }

public:
    Field(int width, int height, float density) : m_width(width), m_height(height), m_density(density) {
        generateTiles();
    };

    void printFieldToConsole() {
        for (int y = 0; y < m_height; y++) {
            for (int x = 0; x < m_width; x++) {
                cout << m_minefield[y][x].getTileInfo();
            }
            cout << endl;
        }
    }
};


int main() {
    int width, height;
    float tileDensity;
    cout << "Enter field width" << endl;
    cin >> width;
    cout << "Enter field height" << endl;
    cin >> height;
    cout << "Enter field density" << endl;
    cin >> tileDensity;

    Field mineField(width, height, tileDensity);
    mineField.printFieldToConsole();
    return 0;
}
