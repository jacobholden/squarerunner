#include "GameScene.h"

#include <fstream>
#include <iostream>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "AScene.h"
#include "../Managers/TextureManager.h"
#include "../Entities/Environment/Wall.h"
#include "../Entities/Player/Player.h"

GameScene::GameScene(int width, int height): ::AScene(width, height)
{
    floor_ = sf::Sprite(*TextureManager::get_texture("floor"), sf::IntRect(0, 0, width, height));

    load_level("01");
}

GameScene::~GameScene()
{
}

void GameScene::update(float elapsedTime)
{
    // auto players = extract_objects_by_type<Player>();

    for (const auto& entity : entities_)
    {
        Updateable* updateable = dynamic_cast<Updateable*>(entity.get());
        
        if (updateable)
        {
            updateable->update(elapsedTime);
        }
    }
}

void GameScene::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(floor_);
    
    AScene::draw(target, states);
}

void GameScene::on_mouse_button(const sf::Event::MouseButtonEvent& mouse_button)
{
    
}

void GameScene::on_mouse_move(const sf::Event::MouseMoveEvent& mouse_move)
{
    
}

bool GameScene::load_level(std::string level_name)
{
    std::ifstream input_file(levels_location + level_name + ".txt");

    if (!input_file.is_open())
    {
        std::cout << "Failed to load level " + level_name << std::endl;
        return false;
    }

    std::string line;

    int x = 0, y = 0;

    while (std::getline(input_file, line))
    {
        for (char c : line)
        {
            // Do something with the character
            std::cout << c;

            auto position = sf::Vector2f(x * 32, y * 32);
            
            if(c == 'W')
            {
                create_entity<Wall>(position);
            }
            else if(c == 'P')
            {
                create_entity<Player>(position);
            }

            x ++;
        }
        // Do something with the end of line
        std::cout << std::endl;

        x = 0;
        y++;
    }

    input_file.close();
    return true;
}
