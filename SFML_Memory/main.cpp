#include <SFML/Graphics.hpp>
#include "game.h"

int main() {

    sf::RenderWindow window(sf::VideoMode(393, 405), "Memory Game");
    window.setFramerateLimit(60);

    sf::Font font;
    font.loadFromFile("calibri.ttf");

    sf::Text text("F2 - New Game / Esc - Exit", font, 20);
    text.setFillColor({ 255, 251, 179 });
    text.setPosition(5.f, 5.f);

    Game game;
    //game.setPosition(40.f, 50.f);

    sf::Vector2i mouse_pos;
    sf::Event event;

    game.initialize();

    while (window.isOpen()) {

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    window.close();
                }
                if (event.key.code == sf::Keyboard::F2) {
                    game.initialize();
                }
            }
        }

        mouse_pos = sf::Mouse::getPosition(window);
        game.update(mouse_pos);

        window.clear();
        window.draw(game);
        window.draw(text);
        window.display();
    }

    return 0;
}