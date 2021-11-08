#pragma once
#include <SFML/Graphics.hpp>

class Card {

public:
    Card(int id);
    ~Card();

    int get_id();
    void set_texture(const sf::Texture& shirt, const sf::Texture& back);
    void set_outline(const sf::Color& color, const sf::Color& hoverColor, float thick);
    void set_fill(const sf::Color& color);
    void set_size(const sf::Vector2f& size);
    void set_position(const sf::Vector2f& pos);
    bool contains(const sf::Vector2f point);
    void set_open(bool value);
    bool get_open();
    void set_hover(bool value);
    void set_wrong_open(bool value);
    const sf::RectangleShape& get_rect();
    sf::RectangleShape shape;

private:
    int id;
    sf::Texture shirtTexture;
    sf::Texture backTexture;
    sf::Color outlineColor;
    sf::Color outlineHoverColor;
    float outlineThick;
    bool open;
};


