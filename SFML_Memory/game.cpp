#include <SFML/Graphics.hpp>
#include "game.h"

Game::Game() {

}

Game ::~Game() {

}

void Game::initialize() {

    for (int i = 0; i < 4; i++) {
        for (size_t j = 0; j < 4; j++) {
            sf::Texture text;
            text.loadFromFile("image/1.png");
            Card card;
            card.shape.setSize({ 64.0, 64.0 });
            card.shape.setTexture(text);
            
            float x = i * 64;
            float y = j * 64;
            card.shape.setPosition({ x, y });
            cards.push_back(card);
        }
    }
}

void Game::update(sf::Vector2i mouse_pos) {

}

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    sf::Color color = sf::Color(200, 100, 200);

    // Рисуем рамку игрового поля
    sf::RectangleShape shape(sf::Vector2f(FIELD_SIZE, FIELD_SIZE));
    shape.setOutlineThickness(2.f);
    shape.setOutlineColor(color);
    shape.setFillColor(sf::Color::Transparent);
    target.draw(shape, states);

    for (size_t i = 0; i < cards.size(); i++) {
        target.draw(cards[i].shape, states);
    }
}
