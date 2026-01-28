#include <iostream>
#include <ostream>

class Tile {
public:
    int m_x;
    int y;

    void printCoords() {
        cout << m_x << " " << y << endl;
    }
};
