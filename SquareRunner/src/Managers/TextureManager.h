#pragma once
#include <map>
#include <string>
#include <SFML/Graphics/Texture.hpp>

class TextureManager final
{
public:
    bool static define_texture(std::string file_path, std::string texture_name, bool is_repeated = false);
    sf::Texture static *get_texture(std::string texture_name);

private:
    TextureManager();
    ~TextureManager();
    std::map<std::string, sf::Texture*> static textures_;
};
