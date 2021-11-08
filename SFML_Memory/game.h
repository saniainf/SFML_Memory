#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "card.h"
#include "assets.h"

constexpr auto EMPTY = -1;
constexpr auto WRONGTIME = 1.5;

const int FIELD_SIZE = 312;

enum GameStates {
    Close,
    OneOpen,
    TwoOpen,
    WrongOpen
};

class Game : public sf::Drawable, public sf::Transformable {
public:
    Game();
    ~Game();

    void initialize();
    void update(sf::Vector2i mouse_pos, float dt);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    int update_input(sf::Vector2i& mouse_pos);

private:
    Assets assets;
    std::vector<Card> cards;
    sf::RectangleShape borderShape;
    GameStates gameStates;
    int cardFirstID;
    int cardSecondID;
    float wrongTimer;
};