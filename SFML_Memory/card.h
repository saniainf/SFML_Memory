#pragma once
#include <SFML/Graphics.hpp>

struct States {
    bool isHover = false;
    bool isPress = false;
    bool isRelease = false;
    bool isClick = false;
};


class Card {

public:
    Card();
    ~Card();
    States states;
    sf::RectangleShape shape;

private:

};


