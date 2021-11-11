#include "assets.h"
#include <SFML/Graphics.hpp>

Assets::Assets() {
}

Assets::~Assets() {
    
}

void Assets::set_texture(const std::string& path) {
    sf::Texture texture;
    texture.loadFromFile(path);
    textures.push_back(texture);
}

sf::Texture& Assets::get_texture(int i){
    return textures[i];
}

void Assets::set_font(const std::string& path){
    font.loadFromFile(path);
}

sf::Font& Assets::get_font(){
    return font;
}
