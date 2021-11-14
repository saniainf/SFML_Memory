#include <iostream>
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <random>
#include "game.h"
#include "assets.h"
#include <string>

Game::Game(Assets assets) {
    this->assets = assets;
    sf::Color color = sf::Color(255, 251, 179);
    borderShape.setSize(sf::Vector2f(FIELD_SIZE, FIELD_SIZE));
    borderShape.setPosition({ 40.0, 40.0 });
    borderShape.setOutlineThickness(2.f);
    borderShape.setOutlineColor(color);
    borderShape.setFillColor(sf::Color::Transparent);
}

Game ::~Game() {

}

void Game::load() {
    for (size_t i = 1; i <= 8; i++) {
        for (size_t j = 0; j < 2; j++) {
            Card card(i);
            card.set_texture(assets.get_texture(0), assets.get_texture(i));
            card.set_outline(sf::Color::Yellow, { 255, 255, 200 }, 2.0);
            card.set_fill(sf::Color::White);
            card.set_size({ 64.0, 64.0 });
            cards.push_back(card);
        }
    }
    timeText.setFont(assets.get_font());
    timeText.setCharacterSize(16);
    timeText.setFillColor({ 255, 251, 179 });
    timeText.setPosition(10.f, 6.f);

    moveText.setFont(assets.get_font());
    moveText.setCharacterSize(16);
    moveText.setFillColor({ 255, 251, 179 });
    moveText.setPosition(150.f, 6.f);
}

void Game::initialize() {
    gameWin = false;
    cardFirstID = EMPTY;
    cardSecondID = EMPTY;
    wrongTimer = EMPTY;
    time = 0;
    moveCount = 0;

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(cards.begin(), cards.end(), g);

    int k = 0;
    for (size_t i = 0; i < 4; i++) {
        for (size_t j = 0; j < 4; j++) {
            float x = 40 + 10 + 76.0 * i;
            float y = 40 + 10 + 76.0 * j;
            cards[k].set_position({ x, y });
            cards[k].set_open(false);
            cards[k].set_hover(false);
            k++;
        }
    }
}

bool Game::update(sf::Vector2i mouse_pos, float dt) {
    if (wrongTimer != EMPTY) {
        wrongTimer -= dt;
        if (wrongTimer <= 0) {
            wrongTimer = EMPTY;
            cards[cardFirstID].set_open(false);
            cards[cardFirstID].set_wrong_open(false);
            cardFirstID = EMPTY;
            cards[cardSecondID].set_open(false);
            cards[cardSecondID].set_wrong_open(false);
            cardSecondID = EMPTY;
        }
        return false;
    }

    time += dt;
    timeString = "Time: " + get_time_str(time);
    timeText.setString(timeString);
    moveString = "Move: " + std::to_string(moveCount);
    moveText.setString(moveString);

    int id = update_input(mouse_pos);
    if (id == EMPTY) return false;
    if (cardFirstID == EMPTY) {
        moveCount++;
        cardFirstID = id;
    }
    else {
        cardSecondID = id;
        if (cards[cardFirstID].get_id() == cards[cardSecondID].get_id()) {
            cardFirstID = EMPTY;
            cardSecondID = EMPTY;
            check_win();
        }
        else {
            cards[cardFirstID].set_wrong_open(true);
            cards[cardSecondID].set_wrong_open(true);
            wrongTimer = WRONGTIME;
        }
    }
    return gameWin;
}

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const {

    target.draw(borderShape, states);
    target.draw(timeText, states);
    target.draw(moveText, states);

    for (size_t i = 0; i < cards.size(); i++) {
        Card card = cards[i];
        target.draw(card.get_rect(), states);
    }
}

std::string Game::get_time_str(int sec)
{
    int m = sec / 60;
    int s = sec % 60;
    std::string result = (m < 10 ? "0" + std::to_string(m) : std::to_string(m)) + " : " + (s < 10 ? "0" + std::to_string(s) : std::to_string(s));
        return result;
}

int Game::update_input(sf::Vector2i& mouse_pos) {
    int resultID = EMPTY;
    for (size_t i = 0; i < cards.size(); i++) {
        // hover
        if (cards[i].contains({ (float)mouse_pos.x, (float)mouse_pos.y })) {
            cards[i].set_hover(true);
            // open
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && !cards[i].get_open()) {
                cards[i].set_open(true);
                resultID = i;
            }
        }
        else {
            cards[i].set_hover(false);
        }
    }
    return resultID;
}

void Game::check_win() {
    bool check = true;
    for (size_t i = 0; i < cards.size(); i++) {
        if (!cards[i].get_open()) {
            check = false;
            break;
        }
    }
    gameWin = check;
}
