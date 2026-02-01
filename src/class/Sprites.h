#ifndef CPP_MINESWEEPER_SPRITES_H
#define CPP_MINESWEEPER_SPRITES_H
#include <SFML/Graphics.hpp>

class Sprites {
public:
    Sprites();

    static sf::Texture textureTileMine;
    static sf::Texture textureTileUnknown;
    static sf::Texture textureTileFlag;
    static sf::Texture textureTileEmpty;
    static sf::Texture textureTileExploded;
    static sf::Texture textureTileOne;
    static sf::Texture textureTileTwo;
    static sf::Texture textureTileThree;
    static sf::Texture textureTileFour;
    static sf::Texture textureTileFive;
    static sf::Texture textureTileSix;
    static sf::Texture textureTileSeven;
    static sf::Texture textureTileEight;
};

#endif //CPP_MINESWEEPER_SPRITES_H
