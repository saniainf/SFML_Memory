#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "card.h"
#include "assets.h"

const int FIELD_SIZE = 312;

class Game : public sf::Drawable, public sf::Transformable {
public:
    Game();
    ~Game();

    void initialize();
    void update(sf::Vector2i mouse_pos);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
    Assets assets;
    std::vector<Card> cards;
    sf::RectangleShape borderShape;
};