#include <filesystem>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "class/Field.h"


int main() {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Minesweeper");
    sf::Texture textureTileMine;
    sf::Texture textureTileUnknown;
    sf::Texture textureTileFlag;
    sf::Texture textureTileEmpty;
    sf::Texture textureTileExploded;
    sf::Texture textureTileOne;
    sf::Texture textureTileTwo;
    sf::Texture textureTileThree;
    sf::Texture textureTileFour;
    sf::Texture textureTileFive;
    sf::Texture textureTileSix;
    sf::Texture textureTileSeven;
    sf::Texture textureTileEight;

    textureTileMine.loadFromFile("../assets/TileMine.png");
    textureTileUnknown.loadFromFile("../assets/TileUnknown.png");
    textureTileFlag.loadFromFile("../assets/TileFlag.png");
    textureTileEmpty.loadFromFile("../assets/TileEmpty.png");
    textureTileExploded.loadFromFile("../assets/TileExploded.png");
    textureTileOne.loadFromFile("../assets/Tile1.png");
    textureTileTwo.loadFromFile("../assets/Tile2.png");
    textureTileThree.loadFromFile("../assets/Tile3.png");
    textureTileFour.loadFromFile("../assets/Tile4.png");
    textureTileFive.loadFromFile("../assets/Tile5.png");
    textureTileSix.loadFromFile("../assets/Tile6.png");
    textureTileSeven.loadFromFile("../assets/Tile7.png");
    textureTileEight.loadFromFile("../assets/Tile8.png");
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
                rect.setTexture(&textureTileMine);
            } else {
                rect.setTexture(&textureTileUnknown);
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
