#pragma once
#include "AScene.h"
#include <SFML\Graphics.hpp>

const static std::string levels_location = "Assets/levels/";

class GameScene : public AScene
{
public:
    GameScene(int width, int height);
    ~GameScene();
    
    void update(float elapsedTime) override;

    void on_mouse_button(const sf::Event::MouseButtonEvent& mouse_button) override;
    void on_mouse_move(const sf::Event::MouseMoveEvent& mouse_move) override;

protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
    sf::Sprite floor_;

    bool load_level(std::string level_name);
};
