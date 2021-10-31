#pragma once
#include <SFML/Graphics.hpp>

struct CardStates {
    bool isOpen = false;
    bool isHover = false;
    bool isPress = false;
    bool isRelease = false;
    bool isClick = false;
};


class Card {

public:
    Card();
    ~Card();
    CardStates states;
    sf::RectangleShape shape;

    void update();
    void set_texture(const sf::Texture& shirt, const sf::Texture& back);
    void set_outline(const sf::Color color, const sf::Color hoverColor, float thick);

private:
    sf::Texture shirtTexture;
    sf::Texture backTexture;
    sf::Color outlineColor;
    sf::Color outlineHoverColor;
    float outlineThick;
};


