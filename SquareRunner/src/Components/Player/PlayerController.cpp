#include "PlayerController.h"

#include <SFML/Window/Keyboard.hpp>

#include "../Animator.h"
#include "../MyRender.h"
#include "../MyTransform.h"
#include "../../Game.h"
#include "../../Entities/Entity.h"
#include "../../Entities/Blueprints/BombIgnitedBlueprint.h"

const float MOVEMENT_SPEED = 0.15f;

void PlayerController::handle_movement_input()
{
    auto animator = entity->get_component<Animator>();

    if(animator->is_playing())
    {
       return; 
    }
    
    auto current_position = entity->get_component<MyTransform>()->position;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        entity->get_component<MyRender>()->drawable = std::make_unique<sf::Sprite>(textures_[0]);
        
        if(!non_walkable_tiles_[(int)current_position.x / 32 - 1][(int)current_position.y / 32])
        {
            animator->translate_position(current_position, current_position + sf::Vector2f(-32, 0), MOVEMENT_SPEED);
        }
    }

    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        entity->get_component<MyRender>()->drawable = std::make_unique<sf::Sprite>(textures_[1]);
        
        if(!non_walkable_tiles_[(int)current_position.x / 32 + 1][(int)current_position.y / 32])
        {
            animator->translate_position(current_position, current_position + sf::Vector2f(32, 0), MOVEMENT_SPEED);            
        }
    }

    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        entity->get_component<MyRender>()->drawable = std::make_unique<sf::Sprite>(textures_[2]);

        if(!non_walkable_tiles_[(int)current_position.x / 32][(int)current_position.y / 32 - 1])
        {
            animator->translate_position(current_position, current_position + sf::Vector2f(0, -32), MOVEMENT_SPEED);            
        }
    }

    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        entity->get_component<MyRender>()->drawable = std::make_unique<sf::Sprite>(textures_[3]);

        if(!non_walkable_tiles_[(int)current_position.x / 32][(int)current_position.y / 32 + 1])
        {
            animator->translate_position(current_position, current_position + sf::Vector2f(0, 32), MOVEMENT_SPEED);
        }
    }
}

void PlayerController::handle_bomb_input()
{
    if(bomb_count_ > 0 && sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !is_space_held_)
    {
        auto current_position = entity->get_component<Animator>()->get_target_position();
        
        sf::Vector2f truncated_position = sf::Vector2f((int)current_position.x / 32 * 32, (int)current_position.y / 32 * 32);
        
        Game::get_current_scene()->create_entity(new BombIgnitedBlueprint(truncated_position));
        is_space_held_ = true;

        bomb_count_ --;
    }
    else if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        is_space_held_ = false;
    }
}

void PlayerController::update(float delta_time)
{
    handle_movement_input();

    handle_bomb_input();
}

PlayerController::~PlayerController()
{

}

void PlayerController::on_awake()
{
    IUpdateable::on_awake();
}

void PlayerController::add_bomb_count()
{
    bomb_count_ ++;
}

void PlayerController::add_gold_count()
{
    gold_count_ ++;
}

void PlayerController::set_gold_target(int gold_target)
{
    gold_target_ = gold_target;
}

bool PlayerController::is_gold_target_reached()
{
    return gold_count_ >= gold_target_;
}
