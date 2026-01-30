#include <iostream>
#include <random>
#include <vector>
#include "Field.h"

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
    mineField.printFieldToConsole();
    return 0;
}
