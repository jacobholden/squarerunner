#include "LevelScene.h"

#include "../Entities/Blueprints/BackgroundBlueprint.h"

LevelScene::LevelScene(int width, int height): IScene(width, height)
{
    // Create an entity with a transform and a sprite
    auto background = create_entity(new BackgroundBlueprint(sf::IntRect(0, 0, width, height)));
    
    auto entity = create_entity(new PlayerBlueprint(sf::Vector2f(150, 300)));
}

LevelScene::~LevelScene()
{
}

void LevelScene::on_mouse_button(const sf::Event::MouseButtonEvent& mouse_button)
{
}

void LevelScene::on_mouse_move(const sf::Event::MouseMoveEvent& mouse_move)
{
}
