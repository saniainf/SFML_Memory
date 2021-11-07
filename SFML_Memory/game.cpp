#include <iostream>
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <random>
#include "game.h"
#include "assets.h"

Game::Game() {
    sf::Color color = sf::Color(255, 251, 179);
    borderShape.setSize(sf::Vector2f(FIELD_SIZE, FIELD_SIZE));
    borderShape.setPosition({ 40.0, 50.0 });
    borderShape.setOutlineThickness(2.f);
    borderShape.setOutlineColor(color);
    borderShape.setFillColor(sf::Color::Transparent);
}

Game ::~Game() {

}

void Game::initialize() {
    gameStates = GameStates::Close;

    for (size_t i = 0; i <= 11; i++) {
        assets.set_texture("image/" + std::to_string(i) + ".png");
    }

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

    //std::random_device rd;
    //std::mt19937 g(rd());
    //std::shuffle(cards.begin(), cards.end(), g);

    int k = 0;
    for (size_t i = 0; i < 4; i++) {
        for (size_t j = 0; j < 4; j++) {
            float x = 40 + 10 + 76.0 * i;
            float y = 50 + 10 + 76.0 * j;
            cards[k++].set_position({ x, y });
        }
    }
}

void Game::update(sf::Vector2i mouse_pos) {
    if (gameStates == GameStates::WrongOpen) return;
    int id;
    if (update_input(mouse_pos, id))
        if (open_card(id)) {
            // начислить очки
            gameStates = GameStates::Close;
        }
        else {
            gameStates = GameStates::WrongOpen;
        }
}

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const {

    target.draw(borderShape, states);

    for (size_t i = 0; i < cards.size(); i++) {
        Card card = cards[i];
        target.draw(card.get_rect(), states);
    }
}

bool Game::update_input(sf::Vector2i& mouse_pos, int& id) {
    for (size_t i = 0; i < cards.size(); i++) {
        // hover
        if (cards[i].contains({ (float)mouse_pos.x, (float)mouse_pos.y })) {
            cards[i].states.isHover = true;
            // open
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && !cards[i].states.isOpen) {
                cards[i].states.isOpen = true;
                id = cards[i].get_id();
                return true;
            }
        }
        else {
            cards[i].states.isHover = false;
        }
    }
    return false;
}

bool Game::open_card(const int id) {
    if (gameStates == GameStates::Close) {
        gameStates = GameStates::OneOpen;
        openID = id;
    }
    else if (gameStates == GameStates::OneOpen) {
        return openID == id;
    }
}
