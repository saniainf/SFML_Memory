#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "card.h"
#include "assets.h"

constexpr auto EMPTY = -1;
constexpr auto WRONGTIME = 1.5;

const int FIELD_SIZE = 312;

class Game : public sf::Drawable, public sf::Transformable {
public:
    Game(Assets assets);
    ~Game();

    void load();
    void initialize();
    bool update(sf::Vector2i mouse_pos, float dt);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
    Assets assets;
    std::vector<Card> cards;
    sf::RectangleShape borderShape;
    int cardFirstID;
    int cardSecondID;
    float wrongTimer;
    bool gameWin;
    float time;
    int moveCount;
    sf::Text moveText;
    sf::Text timeText;
    std::string timeString;
    std::string moveString;
    std::string get_time_str(int sec);
    int update_input(sf::Vector2i& mouse_pos);
    void check_win();
};