#include "card.h"

Card::Card() {

}

Card::~Card() {

}

void Card::set_texture(const sf::Texture& shirt, const sf::Texture& back) {
    shirtTexture = shirt;
    backTexture = back;
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

void Card::set_position(const sf::Vector2f& pos){
    shape.setPosition(pos);
}

bool Card::contains(const sf::Vector2f point) {
    return shape.getGlobalBounds().contains(point);
}

const sf::RectangleShape& Card::get_rect() {
    if (states.isOpen) {
        shape.setTexture(&backTexture);
    }
    else {
        shape.setTexture(&shirtTexture);
    }
    if (states.isHover) {
        shape.setOutlineColor(outlineHoverColor);
    }
    else {
        shape.setOutlineColor(outlineColor);
    }
    return shape;
}
