#include "AssetManager.h"

#include <iostream>

const static std::string gfx_location = "Assets/gfx/";
const static std::string fonts_location = "Assets/fonts/";

std::map<std::string, sf::Texture*> AssetManager::textures_;
std::map<std::string, sf::Font*> AssetManager::fonts_;

bool AssetManager::define_texture(std::string file_path, std::string texture_name, bool is_repeated)
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

sf::Texture* AssetManager::get_texture(std::string texture_name)
{
    return textures_[texture_name];
}

bool AssetManager::define_font(std::string file_path, std::string font_name)
{
    sf::Font *font = new sf::Font;

    if(!font->loadFromFile(fonts_location + file_path))
    {
        std::cout << "Could not load " + file_path;
        return false;
    }

    fonts_[font_name] = font;
    return true;
}

sf::Font* AssetManager::get_font(std::string font_name)
{
    return fonts_[font_name];
}
