#include "LevelScene.h"

#include <fstream>
#include <iostream>
#include <SFML/Graphics/Sprite.hpp>

#include "../Components/MyTransform.h"
#include "../Components/NonWalkable.h"
#include "../Components/Enemy/EnemyController.h"
#include "../Components/Player/PlayerController.h"
#include "../Entities/Blueprints/BackgroundBlueprint.h"
#include "../Entities/Blueprints/BombItemBlueprint.h"
#include "../Entities/Blueprints/EnemyBlueprint.h"
#include "../Entities/Blueprints/EscapeBlueprint.h"
#include "../Entities/Blueprints/GoldBlueprint.h"
#include "../Entities/Environment/ArrowDownBlueprint.h"
#include "../Entities/Environment/ArrowLeftBlueprint.h"
#include "../Entities/Environment/ArrowRightBlueprint.h"
#include "../Entities/Environment/ArrowUpBlueprint.h"
#include "../Entities/Environment/BrokenWall.h"
#include "../Entities/Environment/DirtBlueprint.h"
#include "../Entities/Environment/SafeZoneBlueprint.h"
#include "../Entities/Environment/SpinnerBlueprint.h"
#include "../Entities/Environment/TntBlueprint.h"
#include "../Entities/Environment/WallBlueprint.h"

LevelScene::LevelScene(int width, int height, std::string level_name): IScene(width, height)
{
    // Create an entity with a transform and a sprite
    create_entity(new BackgroundBlueprint(sf::IntRect(0, 0, width, height)));

    load_level(level_name);
}

LevelScene::~LevelScene()
{
}

bool LevelScene::load_level(std::string level_name)
{
    std::ifstream input_file("Assets/levels/" + level_name);

    if (!input_file.is_open())
    {
        std::cout << "Failed to load level " + level_name << std::endl;
        return false;
    }

    std::string line;

    int gold_count = 0;

    std::vector<Entity*> players; 

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
            }
            else if(c == 'P')
            {
                auto player = create_entity(new PlayerBlueprint(position));
                players.push_back(player);
            }
            else if(c == 'E')
            {
                create_entity(new EnemyBlueprint(position));
            }
            else if(c == 'S')
            {
                create_entity(new SafeZoneBlueprint(position));
            }
            else if(c == '<')
            {
                create_entity(new ArrowLeftBlueprint(position));
            }
            else if(c == '>')
            {
                create_entity(new ArrowRightBlueprint(position));
            }
            else if(c == '^')
            {
                create_entity(new ArrowUpBlueprint(position));
            }
            else if(c == 'V')
            {
                create_entity(new ArrowDownBlueprint(position));
            }
            else if(c == 'O')
            {
                create_entity(new SpinnerBlueprint(position));
            }
            else if(c == 'D')
            {
                create_entity(new DirtBlueprint(position));
            }
            else if(c == 'T')
            {
                create_entity(new TntBlueprint(position));
            }
            else if(c == 'B')
            {
                create_entity(new BrokenWall(position));
            }
            else if(c == 'G')
            {
                create_entity(new GoldBlueprint(position));
                gold_count ++;
            }
            else if(c == 'I')
            {
                create_entity(new BombItemBlueprint(position));
            }
            else if(c == 'X')
            {
                create_entity(new EscapeBlueprint(position));
            }

            x ++;
        }
        // Do something with the end of line
        std::cout << std::endl;

        x = 0;
        y++;
    }

    input_file.close();

    for (const auto& player : players)
    {
        player->get_component<PlayerController>()->set_gold_target(gold_count);
    }
    
    return true;
}

void LevelScene::on_mouse_button(const sf::Event::MouseButtonEvent& mouse_button)
{
}

void LevelScene::initialise_entities()
{
    IScene::initialise_entities();

    // Update all the Controllers with the tile map information.
    for (auto &entity : get_entities())
    {
        auto non_walkable = entity.get()->get_component<NonWalkable>();
        auto transform  = entity.get()->get_component<MyTransform>();

        if(non_walkable && transform)
        {
            auto position = sf::Vector2i(transform->position.x / 32, transform->position.y / 32);
            
            if(non_walkable->player_non_walkable)
            {
                non_walkable_tiles_player_[position.x][position.y] = true;
            }

            if(non_walkable->enemy_non_walkable)
            {
                non_walkable_tiles_enemy_[position.x][position.y] = true;
            }
        }
        
        auto playerController = entity.get()->get_component<PlayerController>();
    
        if(playerController)
        {
            playerController->set_non_walkable_tiles(non_walkable_tiles_player_);   
        }
    
        auto enemyController = entity.get()->get_component<EnemyController>();
    
        if(enemyController)
        {
            enemyController->set_non_walkable_tiles(non_walkable_tiles_enemy_);   
        }
    }
}

void LevelScene::on_mouse_move(const sf::Event::MouseMoveEvent& mouse_move)
{
}

void LevelScene::on_entity_destroyed(const std::unique_ptr<Entity>& entity)
{
    auto transform = entity.get()->get_component<MyTransform>();
    auto non_walkable = entity.get()->get_component<NonWalkable>();

    if(non_walkable && transform)
    {
        auto position = transform->position;
        auto truncated_position = sf::Vector2i(position.x / 32, position.y / 32);

        non_walkable_tiles_player_[truncated_position.x][truncated_position.y] = false;
        non_walkable_tiles_enemy_[truncated_position.x][truncated_position.y] = false;
    }
}

void LevelScene::update(float delta_time)
{
    IScene::update(delta_time);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && !escape_key_held_)
    {
        escape_key_held_ = true;
        escape_key_pressed_count_++; 
    }
    else if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        escape_key_held_ = false;
    }

    if(escape_key_pressed_count_ >= 2)
    {
        is_restarting_ = false;
        end_scene();
    }
}
