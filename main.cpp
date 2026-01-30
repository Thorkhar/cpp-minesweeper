#include <iostream>
#include <random>
#include <vector>
#include "Field.h"
using namespace std;

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
