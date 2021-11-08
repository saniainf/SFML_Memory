#include "card.h"

Card::Card(int _id) {
    id = _id;
    open = false;
}

Card::~Card() {

}

int Card::get_id() {
    return id;
}

void Card::set_texture(const sf::Texture& shirt, const sf::Texture& back) {
    shirtTexture = shirt;
    backTexture = back;
    shape.setTexture(&shirt);
}

void Card::set_outline(const sf::Color& color, const sf::Color& hoverColor, float thick) {
    outlineColor = color;
    outlineHoverColor = hoverColor;
    outlineThick = thick;
    shape.setOutlineColor(color);
    shape.setOutlineThickness(thick);
}

void Card::set_fill(const sf::Color& color) {
    shape.setFillColor(color);
}

void Card::set_size(const sf::Vector2f& size) {
    shape.setSize(size);
}

void Card::set_position(const sf::Vector2f& pos) {
    shape.setPosition(pos);
}

bool Card::contains(const sf::Vector2f point) {
    return shape.getGlobalBounds().contains(point);
}

void Card::set_open(bool value) {
    if (value) {
        shape.setTexture(&backTexture);
    }
    else {
        shape.setTexture(&shirtTexture);
    }
    open = value;
}

bool Card::get_open() {
    return open;
}

void Card::set_hover(bool value) {
    if (value) {
        shape.setOutlineColor(outlineHoverColor);
    }
    else {
        shape.setOutlineColor(outlineColor);
    }
}

void Card::set_wrong_open(bool value) {
    if (value) {
        shape.setOutlineColor(sf::Color::Red);
    }
    else {
        shape.setOutlineColor(outlineColor);
    }
}

const sf::RectangleShape& Card::get_rect() {
    return shape;
}
