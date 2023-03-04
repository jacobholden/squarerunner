﻿#include "PlayerController.h"

#include <SFML/Window/Keyboard.hpp>

#include "../Animator.h"
#include "../MyRender.h"
#include "../MyTransform.h"
#include "../../Entities/Entity.h"

const float PLAYER_SPEED = 0.15f;

void PlayerController::handle_input()
{
    auto animator = entity->get_component<Animator>();

    if(animator->is_playing())
    {
       return; 
    }
    
    auto currentPosition = entity->get_component<MyTransform>()->position;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        entity->get_component<MyRender>()->drawable = std::make_unique<sf::Sprite>(textures_[0]);
        
        if(!non_walkable_tiles_[(int)currentPosition.x / 32 - 1][(int)currentPosition.y / 32])
        {
            animator->translate_position(currentPosition, currentPosition + sf::Vector2f(-32, 0), PLAYER_SPEED);
        }
    }

    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        entity->get_component<MyRender>()->drawable = std::make_unique<sf::Sprite>(textures_[1]);
        
        if(!non_walkable_tiles_[(int)currentPosition.x / 32 + 1][(int)currentPosition.y / 32])
        {
            animator->translate_position(currentPosition, currentPosition + sf::Vector2f(32, 0), PLAYER_SPEED);            
        }
    }

    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        entity->get_component<MyRender>()->drawable = std::make_unique<sf::Sprite>(textures_[2]);

        if(!non_walkable_tiles_[(int)currentPosition.x / 32][(int)currentPosition.y / 32 - 1])
        {
            animator->translate_position(currentPosition, currentPosition + sf::Vector2f(0, -32), PLAYER_SPEED);            
        }
    }

    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        entity->get_component<MyRender>()->drawable = std::make_unique<sf::Sprite>(textures_[3]);

        if(!non_walkable_tiles_[(int)currentPosition.x / 32][(int)currentPosition.y / 32 + 1])
        {
            animator->translate_position(currentPosition, currentPosition + sf::Vector2f(0, 32), PLAYER_SPEED);
        }
    }
}

void PlayerController::update(float delta_time)
{
    handle_input();
}
