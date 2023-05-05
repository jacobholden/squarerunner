#pragma once
#include <array>
#include <map>
#include <SFML/Graphics/Texture.hpp>

#include "../IUpdateable.h"
#include "../../Managers/AssetManager.h"

class PlayerController : public IUpdateable
{
public:
    void handle_movement_input();
    void handle_bomb_input();
    void handle_suicide_input();
    void update(float delta_time) override;
    void set_non_walkable_tiles(std::array<std::array<bool, 23>, 40> tiles)
    {
        non_walkable_tiles_ = tiles;
    }

    ~PlayerController() override;
    void on_awake() override;
    void add_bomb_count();
    void add_gold_count();
    void set_gold_target(int gold_target);
    bool is_gold_target_reached();

private:
    std::map<int, sf::Texture> textures_ =
        {
        {0, *AssetManager::get_texture("player_left")},
        {1, *AssetManager::get_texture("player_right")},
        {2, *AssetManager::get_texture("player_up")},
        {3, *AssetManager::get_texture("player_down")},
        };

    std::array<std::array<bool, 23>, 40> non_walkable_tiles_{};

    bool is_space_held_ = false;
    int bomb_count_ = 0;
    int gold_count_ = 0;
    int gold_target_ = 0;
};
