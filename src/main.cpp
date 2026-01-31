#include <iostream>
#include <random>
#include "class/Field.h"

int main() {
    int width, height;
    float tileDensity;
    std::cout << "Enter field width" << std::endl;
    std::cin >> width;
    std::cout << "Enter field height" << std::endl;
    std::cin >> height;
    std::cout << "Enter field density" << std::endl;
    std::cin >> tileDensity;

    Field mineField(width, height, tileDensity);

    while (mineField.getIsAlive()) {
        mineField.printFieldToConsole();
        int x, y;
        std::cout << "Enter x, y" << std::endl;
        std::cin >> x >> y;
        mineField.probeTile(x, y);
    }

    return 0;
}
