#pragma once
#include <SFML/Graphics.hpp>
#include "card.h"
#include <vector>

const int FIELD_SIZE = 500;

class Game : public sf::Drawable, public sf::Transformable {
public:
    Game();
    ~Game();

    void initialize();
    void update(sf::Vector2i mouse_pos);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
    std::vector<Card> cards;
};