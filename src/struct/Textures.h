#ifndef CPP_MINESWEEPER_TEXTURES_H
#define CPP_MINESWEEPER_TEXTURES_H
#include <SFML/Graphics.hpp>


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

    void load();
};

#endif //CPP_MINESWEEPER_TEXTURES_H
