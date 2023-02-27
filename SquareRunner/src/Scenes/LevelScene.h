#pragma once
#include "IScene.h"

class LevelScene : public IScene
{
public:
    LevelScene(int width, int height);
    ~LevelScene() override;
    
    void on_mouse_button(const sf::Event::MouseButtonEvent& mouse_button) override;
    void on_mouse_move(const sf::Event::MouseMoveEvent& mouse_move) override;
};
