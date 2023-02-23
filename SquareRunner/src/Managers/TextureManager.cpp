#include "TextureManager.h"

#include <iostream>

const static std::string gfx_location = "Assets/gfx/";

std::map<std::string, sf::Texture*> TextureManager::textures_;

bool TextureManager::define_texture(std::string file_path, std::string texture_name, bool is_repeated)
{
    sf::Texture *texture = new sf::Texture;

    if(!texture->loadFromFile(gfx_location + file_path))
    {
        std::cout << "Could not load " + file_path;
        return false;
    }

    texture->setRepeated(is_repeated);
    
    textures_[texture_name] = texture;
    return true;
}

sf::Texture* TextureManager::get_texture(std::string texture_name)
{
    return textures_[texture_name];
}