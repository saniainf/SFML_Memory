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
    Card(int id);
    ~Card();
    CardStates states;

    int get_id();
    void set_texture(const sf::Texture& shirt, const sf::Texture& back);
    void set_outline(const sf::Color& color, const sf::Color& hoverColor, float thick);
    void set_fill(const sf::Color& color);
    void set_size(const sf::Vector2f& size);
    void set_position(const sf::Vector2f& pos);
    bool contains(const sf::Vector2f point);
    const sf::RectangleShape& get_rect();
    sf::RectangleShape shape;

private:
    int id;
    sf::Texture shirtTexture;
    sf::Texture backTexture;
    sf::Color outlineColor;
    sf::Color outlineHoverColor;
    float outlineThick;
};


