#include "LevelScene.h"

#include <fstream>
#include <iostream>
#include <SFML/Graphics/Sprite.hpp>

#include "../Components/Enemy/EnemyController.h"
#include "../Components/Player/PlayerController.h"
#include "../Entities/Blueprints/BackgroundBlueprint.h"
#include "../Entities/Blueprints/EnemyBlueprint.h"
#include "../Entities/Environment/WallBlueprint.h"

LevelScene::LevelScene(int width, int height): IScene(width, height)
{
    // Create an entity with a transform and a sprite
    auto background = create_entity(new BackgroundBlueprint(sf::IntRect(0, 0, width, height)));

    load_level("01");

    // Update all the Controllers with the tile map information.
    for (auto &entity : get_entities())
    {
        auto playerController = entity.get()->get_component<PlayerController>();

        if(playerController)
        {
            playerController->set_non_walkable_tiles(non_walkable_tiles_);   
        }

        auto enemyController = entity.get()->get_component<EnemyController>();

        if(enemyController)
        {
            enemyController->set_non_walkable_tiles(non_walkable_tiles_);   
        }
    }
}

LevelScene::~LevelScene()
{
}

bool LevelScene::load_level(std::string level_name)
{
    std::ifstream input_file("Assets/levels/" + level_name + ".txt");

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
                create_entity(new WallBlueprint(position));
                non_walkable_tiles_[x][y] = true;
            }
            else if(c == 'P')
            {
                create_entity(new PlayerBlueprint(position));
            }
            else if(c == 'E')
            {
                create_entity(new EnemyBlueprint(position));
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

void LevelScene::on_mouse_button(const sf::Event::MouseButtonEvent& mouse_button)
{
}

void LevelScene::on_mouse_move(const sf::Event::MouseMoveEvent& mouse_move)
{
}
