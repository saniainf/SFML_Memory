#include <SFML/Graphics.hpp>

struct MouseEvent {
    bool isHover = false;
    bool isPress = false;
    bool isRelease = false;
    bool isClick = false;
};

struct ShapeColor {
    sf::Color color;
    sf::Color hoverColor = sf::Color::Transparent;
    sf::Color pressColor = sf::Color::Transparent;
};

class Card {
private:
    sf::RectangleShape shape;
    ShapeColor color;

public:
    Card(const sf::Vector2f& size, const sf::Vector2f& pos) {
        set_size(size);
        set_position(pos);
        set_color_default();
        set_outline_default();
    }

    MouseEvent mouse;

    void mouse_reset() {
        mouse.isClick = false;
        mouse.isHover = false;
        mouse.isPress = false;
        mouse.isRelease = false;
    }

    void set_position(const sf::Vector2f& pos) {
        shape.setPosition(pos);
    }

    void set_size(const sf::Vector2f& size) {
        shape.setSize(size);
    }

    sf::RectangleShape& get_rect() {
        return shape;
    }

    void set_color(const sf::Color& color) {
        this->color.color = color;
    }

    void set_hover_color(const sf::Color& color) {
        this->color.hoverColor = color;
    }

    void set_press_color(const sf::Color& color) {
        this->color.pressColor = color;
    }

    void set_color_default() {
        set_color(sf::Color::Transparent);
        set_hover_color(sf::Color::Transparent);
        set_press_color(sf::Color::Transparent);
    }

    void set_outline(const sf::Color& color, float thick) {
        shape.setOutlineColor(color);
        shape.setOutlineThickness(thick);
    }

    void set_outline_default() {
        shape.setOutlineColor(sf::Color::Blue);
        shape.setOutlineThickness(1.0);
    }

    bool contains_point(const sf::Vector2f& point) {
        return shape.getGlobalBounds().contains(point);
    }

    bool contains_point(float x, float y) {
        return shape.getGlobalBounds().contains(x, y);
    }

    void update() {
        shape.setFillColor(color.color);
        if (mouse.isHover && color.hoverColor != sf::Color::Transparent) {
            shape.setFillColor(color.hoverColor);
        }
        if (mouse.isPress && color.pressColor != sf::Color::Transparent) {
            shape.setFillColor(color.pressColor);
        }
    }
};


int main() {

    sf::RenderWindow window(sf::VideoMode(320, 480), "It`s work");

    Card card({ 30.0, 30.0 }, { 50.0, 50.0 });
    sf::Vector2i mouse_pos;

    //set
    card.set_hover_color(sf::Color::Green);
    card.set_press_color(sf::Color::Red);

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        // update mouse
        card.mouse_reset();
        mouse_pos = sf::Mouse::getPosition(window);
        if (card.contains_point(mouse_pos.x, mouse_pos.y)) {
            card.mouse.isHover = true;
        }
        if (card.mouse.isHover && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            card.mouse.isPress = true;
        }

        // update shape
        card.update();

        //draw
        window.clear(sf::Color(sf::Color::White));
        window.draw(card.get_rect());
        window.display();
    }

    return 0;
}