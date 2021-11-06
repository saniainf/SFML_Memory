#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

class Assets {

public:
    Assets();
    ~Assets();

    void set_texture(const std::string& path);
    sf::Texture& get_texture(int i);
private:
    std::vector<sf::Texture> textures;
};



