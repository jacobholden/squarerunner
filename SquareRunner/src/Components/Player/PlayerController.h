#pragma once
#include <array>
#include <map>
#include <SFML/Graphics/Texture.hpp>

#include "../IUpdateable.h"
#include "../../Managers/TextureManager.h"

class PlayerController : public IUpdateable
{
public:
    void handle_input();
    void update(float delta_time) override;
    void set_non_walkable_tiles(std::array<std::array<bool, 40>, 23> tiles)
    {
        non_walkable_tiles_ = tiles;
    }

private:
    std::map<int, sf::Texture> textures_ =
        {
        {0, *TextureManager::get_texture("player_left")},
        {1, *TextureManager::get_texture("player_right")},
        {2, *TextureManager::get_texture("player_up")},
        {3, *TextureManager::get_texture("player_down")},
        };

    std::array<std::array<bool, 40>, 23> non_walkable_tiles_{};
};
