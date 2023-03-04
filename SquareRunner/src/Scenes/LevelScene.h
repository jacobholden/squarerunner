#pragma once
#include <array>
#include <map>

#include "IScene.h"

class LevelScene : public IScene
{
public:
    LevelScene(int width, int height);
    ~LevelScene() override;
    bool load_level(std::string level_name);

    void on_mouse_button(const sf::Event::MouseButtonEvent& mouse_button) override;
    void on_mouse_move(const sf::Event::MouseMoveEvent& mouse_move) override;

    std::array<std::array<bool, 40>, 23> non_walkable_tiles_{};
};
