#include <cmath>
#include <filesystem>
#include <SFML/Graphics.hpp>
#include "./class/Field.h"
#include "./struct/Textures.h"


int main() {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Minesweeper");
    Textures textures;
    textures.load();
    Field minefield(10, 10, 0.2);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) { window.close(); }

            if (event.type == sf::Event::MouseButtonPressed && minefield.getIsAlive()) {
                int mouseX = event.mouseButton.x;
                int mouseY = event.mouseButton.y;
                std::pair<int, int> tileCoords = {std::ceil(mouseX / 16), std::ceil(mouseY = mouseY / 16)};
                if (event.mouseButton.button == sf::Mouse::Left) {
                    minefield.probeTile(tileCoords.first, tileCoords.second);
                } else if (event.mouseButton.button == sf::Mouse::Right) {
                    minefield.flagTile(tileCoords.first, tileCoords.second);
                }
            }

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Key::Escape) {
                minefield.resetField();
            }
        }
        window.clear(sf::Color::White);

        for (int i = 0; i < minefield.getMinefield().size(); i++) {
            Tile tile(minefield.getMinefield()[i]);
            sf::RectangleShape rect({16.f, 16.f});
            rect.setPosition({tile.getX() * 16.f, tile.getY() * 16.f});

            if (tile.getIsFlagged() && minefield.getIsAlive()) {
                rect.setTexture(&textures.tileFlag);
            } else if (tile.getIsMine()) {
                if (minefield.getIsAlive()) {
                    rect.setTexture(&textures.tileUnknown);
                } else {
                    if (tile.getIsProbed()) {
                        rect.setTexture(&textures.tileExploded);
                    } else {
                        rect.setTexture(&textures.tileMine);
                    }
                }
            } else if (tile.getIsProbed()) {
                switch (tile.getMinesNear()) {
                    case 1:
                        rect.setTexture(&textures.tileOne);
                        break;
                    case 2:
                        rect.setTexture(&textures.tileTwo);
                        break;
                    case 3:
                        rect.setTexture(&textures.tileThree);
                        break;
                    case 4:
                        rect.setTexture(&textures.tileFour);
                        break;
                    case 5:
                        rect.setTexture(&textures.tileFive);
                        break;
                    case 6:
                        rect.setTexture(&textures.tileSix);
                        break;
                    case 7:
                        rect.setTexture(&textures.tileSeven);
                        break;
                    case 8:
                        rect.setTexture(&textures.tileEight);
                        break;
                    default:
                        rect.setTexture(&textures.tileEmpty);
                }
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
