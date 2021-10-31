#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

class Assets {

public:
    Assets();
    ~Assets();

    std::vector<sf::Texture> textures;
    void set_texture(std::string path);

private:

};



