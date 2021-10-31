#include "assets.h"
#include <SFML/Graphics.hpp>

Assets::Assets() {
}

Assets::~Assets() {
}

void Assets::set_texture(std::string path) {
    sf::Texture texture;
    texture.loadFromFile(path);
    textures.push_back(texture);
}
