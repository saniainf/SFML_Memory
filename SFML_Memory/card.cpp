#include "card.h"

Card::Card() {

}

Card::~Card() {

}

void Card::update() {
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
}

void Card::set_texture(const sf::Texture& shirt, const sf::Texture& back) {
    shirtTexture = shirt;
    backTexture = back;
}

void Card::set_outline(const sf::Color color, const sf::Color hoverColor, float thick) {
    outlineColor = color;
    outlineHoverColor = hoverColor;
    outlineThick = thick;
    shape.setOutlineColor(color);
    shape.setOutlineThickness(thick);
}
