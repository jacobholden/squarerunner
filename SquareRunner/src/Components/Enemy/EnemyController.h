#pragma once
#include <array>
#include <map>

#include "../IUpdateable.h"
#include "../../Managers/AssetManager.h"

class EnemyController : public IUpdateable
{
public:
    void on_awake() override;
    void handle_movement();
    void update(float delta_time) override;
    void set_non_walkable_tiles(std::array<std::array<bool, 23>, 40> tiles)
    {
        non_walkable_tiles_ = tiles;
    }
    sf::Vector2i initial_direction = sf::Vector2i(1, 0);
    float movement_speed = 0.25f;
    ~EnemyController() override;

private:
    enum Direction
    {
        Left,
        Right,
        Up,
        Down
    };

    std::array<std::array<bool, 23>, 40> non_walkable_tiles_{};
    std::map<Direction, sf::Texture> textures_ =
        {
        {Left, *AssetManager::get_texture("enemy_left")},
        {Right, *AssetManager::get_texture("enemy_right")},
        {Up, *AssetManager::get_texture("enemy_up")},
        {Down, *AssetManager::get_texture("enemy_down")},
        };
    void update_texture();
    void move();
    sf::Vector2i current_direction_;
};
