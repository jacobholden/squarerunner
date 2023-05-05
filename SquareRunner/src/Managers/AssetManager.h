#pragma once
#include <map>
#include <string>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Texture.hpp>

class AssetManager final
{
public:
    bool static define_texture(std::string file_path, std::string texture_name, bool is_repeated = false);
    sf::Texture static *get_texture(std::string texture_name);

    bool static define_font(std::string file_path, std::string font_name);
    sf::Font static *get_font(std::string font_name);

private:
    AssetManager();
    ~AssetManager();
    std::map<std::string, sf::Texture*> static textures_;
    std::map<std::string, sf::Font*> static fonts_;
};
