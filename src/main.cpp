#include <iostream>
#include <SFML/Graphics.hpp>
#include "class/Field.h"

int main() {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "My window");
    while (window.isOpen()) {
        window.clear(sf::Color::Black);
        window.display();
    }
    return 0;
}
