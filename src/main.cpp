#include <filesystem>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "class/Field.h"
#include "class/Textures.h"


int main() {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Minesweeper");
    Textures textures;
    textures.load();
    Field minefield(10, 10, 0.2);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) { window.close(); }
        }
        window.clear(sf::Color::White);

        for (int i = 0; i < minefield.getMinefield().size(); i++) {
            Tile tile(minefield.getMinefield()[i]);
            sf::RectangleShape rect({16.f, 16.f});
            rect.setPosition({tile.getX() * 16.f, tile.getY() * 16.f});

            if (tile.getIsMine()) {
                rect.setTexture(&textures.tileMine);
            } else {
                rect.setTexture(&textures.tileUnknown);
            }
            rect.setTextureRect(sf::IntRect(
                    0, 0, 16.f, 16.f)
            );
            window.draw(rect);
        }

        window.display();
    }
    return 0;
}
