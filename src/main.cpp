#include <filesystem>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "class/Field.h"

int main() {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "My window");
    std::cout << std::filesystem::current_path().string() << std::endl;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) { window.close(); }
        }
        window.clear(sf::Color::White);

        sf::Texture texture;
        texture.loadFromFile("../assets/TileUnknown.png");

        sf::RectangleShape rectangle({16.f, 16.f});
        rectangle.setTexture(&texture);
        rectangle.setTextureRect(sf::IntRect(0, 0, 16.f, 16.f));
        window.draw(rectangle);

        window.display();
    }
    return 0;
}
