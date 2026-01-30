#include <iostream>
#include <random>
#include "Tile.h"
using namespace std;

bool randomBool(float p) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::bernoulli_distribution dist(p);
    return dist(gen);
}

class Field {
    int m_width;
    int m_height;
    float m_density;
    int m_mineCount;

    vector<vector<Tile> > m_minefield;

    void generateTiles() {
        for (int y = 0; y < m_height; y++) {
            vector<Tile> tileRow;
            for (int x = 0; x < m_height; x++) {
                Tile tile = Tile(x, y, randomBool(m_density));
                tileRow.push_back(tile);
                if (tile.getIsMine()) {
                    m_mineCount++;
                }
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
                cout << m_minefield[y][x].getIsMine();
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
