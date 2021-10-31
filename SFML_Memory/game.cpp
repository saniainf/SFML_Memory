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
    for (size_t i = 0; i <= 11; i++) {
        assets.set_texture("image/" + std::to_string(i) + ".png");
    }

    for (size_t i = 1; i <= 8; i++) {
        for (size_t j = 0; j < 2; j++) {
            Card card;
            card.set_texture(assets.textures[0], assets.textures[i]);
            card.set_outline(sf::Color::Yellow, { 255, 255, 200 }, 2.0);
            card.shape.setFillColor(sf::Color::White);
            card.shape.setSize({ 64.0, 64.0 });
            cards.push_back(card);
        }
    }

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(cards.begin(), cards.end(), g);

    int k = 0;
    for (size_t i = 0; i < 4; i++) {
        for (size_t j = 0; j < 4; j++) {
            float x = 40 + 10 + 76.0 * i;
            float y = 50 + 10 + 76.0 * j;
            cards[k++].shape.setPosition(x, y);
        }
    }
}

void Game::update(sf::Vector2i mouse_pos) {
    for (size_t i = 0; i < cards.size(); i++) {
        if (cards[i].shape.getGlobalBounds().contains(mouse_pos.x, mouse_pos.y)) {
            cards[i].states.isHover = true;
        }
        else {
            cards[i].states.isHover = false;
        }

        cards[i].update();
    }
}

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const {

    target.draw(borderShape, states);

    for (size_t i = 0; i < cards.size(); i++) {
        target.draw(cards[i].shape, states);
    }
}
