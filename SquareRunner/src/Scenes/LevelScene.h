#pragma once
#include <array>

#include "IScene.h"

class LevelScene : public IScene
{
public:
    LevelScene(int width, int height, std::string level_name);
    ~LevelScene() override;
    bool load_level(std::string level_name);
    void on_mouse_button(const sf::Event::MouseButtonEvent& mouse_button) override;
    void initialise_entities() override;
    void on_mouse_move(const sf::Event::MouseMoveEvent& mouse_move) override;
    void on_entity_destroyed(const std::unique_ptr<Entity>& entity) override;
    
    std::array<std::array<bool, 23>, 40> non_walkable_tiles_player_{};
    std::array<std::array<bool, 23>, 40> non_walkable_tiles_enemy_{};
};
