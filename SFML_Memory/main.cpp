#include <SFML/Graphics.hpp>
#include "game.h"
#include "assets.h"

int main() {
    Assets assets;

    int wWidth = 392;
    int wHeight = 392;
    bool gameWin = false;

    sf::RenderWindow window(sf::VideoMode(wWidth, wHeight), "Memory Game");
    window.setFramerateLimit(60);

    for (size_t i = 0; i <= 11; i++) {
        assets.set_texture("image/" + std::to_string(i) + ".png");
    }
    assets.set_font("calibri.ttf");

    sf::Text menuText("F2 - New Game / Esc - Exit", assets.get_font(), 16);
    sf::Text winText("YOU WIN", assets.get_font(), 64);
    menuText.setFillColor({ 255, 251, 179 });
    menuText.setPosition(10.f, wHeight - 31.f);
    winText.setFillColor(sf::Color::Red);
    winText.setOutlineColor(sf::Color::White);
    winText.setOutlineThickness(5.f);

    float winTextWidth = winText.getGlobalBounds().width;
    float winTextHeight = winText.getGlobalBounds().height;

    winText.setPosition((wWidth / 2 - winTextWidth / 2), (wHeight / 2 - winTextHeight / 2 - 15));

    Game game(assets);
    sf::Clock clock;
    float deltaTime;
    sf::Vector2i mousePos;
    sf::Event event;

    game.load();
    game.initialize();

    while (window.isOpen()) {
        deltaTime = clock.getElapsedTime().asSeconds();
        clock.restart();

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
                    gameWin = false;
                }
            }
        }

        mousePos = sf::Mouse::getPosition(window);
        if (!gameWin)
            gameWin = game.update(mousePos, deltaTime);

        window.clear();
        window.draw(game);
        window.draw(menuText);
        if (gameWin)
            window.draw(winText);
        window.display();
    }

    return 0;
}