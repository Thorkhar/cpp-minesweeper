#include <cmath>
#include <filesystem>
#include <SFML/Graphics.hpp>
#include "./class/Field.h"
#include "./struct/Textures.h"


int main() {
    unsigned int fieldWidth = 30;
    unsigned int fieldHeight = 30;
    sf::Window window(sf::VideoMode({fieldWidth * 16, fieldHeight * 16}), "Minesweeper");
    Textures textures;
    textures.load();
    Field minefield(fieldWidth, fieldHeight, 0.15);

    while (window.isOpen()) {
        while (const std::optional<sf::Event> event = window.pollEvent()) {
            if (event->is<sf::Event::KeyPressed>()) {
                window.close();
            }

            if (const auto *keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                if (keyPressed->code == sf::Keyboard::Key::Escape) {
                    minefield.resetField();
                }
            }

            if (const auto *mouseButtonPressed = event->getIf<sf::Event::MouseButtonPressed>()) {
                std::pair<int, int> clickCoords = {
                    std::ceil(mouseButtonPressed->position.x / 16),
                    std::ceil(mouseButtonPressed->position.y / 16)
                };

                if (mouseButtonPressed->button == sf::Mouse::Button::Left) {
                    minefield.probeTile(clickCoords.first, clickCoords.second);
                }

                if (mouseButtonPressed->button == sf::Mouse::Button::Right) {
                    minefield.flagTile(clickCoords.first, clickCoords.second);
                }
            }
        }

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
                    {0, 0}, {16, 16})
            );
            window.draw(rect);
        }

        window.display();
    }
    return 0;
}
