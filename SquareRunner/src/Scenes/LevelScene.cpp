﻿#include "LevelScene.h"

#include <fstream>
#include <iostream>
#include <SFML/Graphics/Sprite.hpp>

#include "../Components/Player/PlayerController.h"
#include "../Entities/Blueprints/BackgroundBlueprint.h"
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
            entity.get()->get_component<PlayerController>()->set_non_walkable_tiles(non_walkable_tiles_);   
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
                auto player = create_entity(new PlayerBlueprint(position));
                // player->get_component<PlayerController>()->set_non_walkable_tiles(non_walkable_tiles_);
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
