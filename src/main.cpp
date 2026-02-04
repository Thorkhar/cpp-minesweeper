#include <filesystem>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "class/Field.h"

struct Textures {
    sf::Texture tileMine;
    sf::Texture tileUnknown;
    sf::Texture tileFlag;
    sf::Texture tileEmpty;
    sf::Texture tileExploded;
    sf::Texture tileOne;
    sf::Texture tileTwo;
    sf::Texture tileThree;
    sf::Texture tileFour;
    sf::Texture tileFive;
    sf::Texture tileSix;
    sf::Texture tileSeven;
    sf::Texture tileEight;

    void load() {
        tileMine.loadFromFile("../assets/TileMine.png");
        tileUnknown.loadFromFile("../assets/TileUnknown.png");
        tileFlag.loadFromFile("../assets/TileFlag.png");
        tileEmpty.loadFromFile("../assets/TileEmpty.png");
        tileExploded.loadFromFile("../assets/TileExploded.png");
        tileOne.loadFromFile("../assets/Tile1.png");
        tileTwo.loadFromFile("../assets/Tile2.png");
        tileThree.loadFromFile("../assets/Tile3.png");
        tileFour.loadFromFile("../assets/Tile4.png");
        tileFive.loadFromFile("../assets/Tile5.png");
        tileSix.loadFromFile("../assets/Tile6.png");
        tileSeven.loadFromFile("../assets/Tile7.png");
        tileEight.loadFromFile("../assets/Tile8.png");
    }
};

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
