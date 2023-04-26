#include "EnemyController.h"

#include "../Animator.h"
#include "../FrameSequenceAnimation.h"
#include "../MyRender.h"
#include "../MyTransform.h"
#include "../../Entities/Entity.h"
#include "../../Scenes/LevelScene.h"
#include "../../Game.h"
#include "../../Managers/SoundManager.h"

void EnemyController::on_awake()
{
    current_direction_ = initial_direction;
}

void EnemyController::update(float delta_time)
{
    handle_movement();
}

void EnemyController::handle_movement()
{
    auto animator = entity->get_component<Animator>();

    if(animator->is_playing())
    {
        return; 
    }

    auto current_position = entity->get_component<MyTransform>()->position;

    auto grid_position = sf::Vector2u(current_position.x / 32, current_position.y / 32);

    sf::Vector2i leftTilePos = sf::Vector2i(grid_position.x, grid_position.y) + sf::Vector2i(-current_direction_.y, current_direction_.x);
    sf::Vector2i rightTilePos = sf::Vector2i(grid_position.x, grid_position.y) + sf::Vector2i(current_direction_.y, -current_direction_.x);

    if(!non_walkable_tiles_[grid_position.x + current_direction_.x][grid_position.y + current_direction_.y])
    {       
        move();
    }
    else if(non_walkable_tiles_[leftTilePos.x][leftTilePos.y] && non_walkable_tiles_[rightTilePos.x][rightTilePos.y])
    {
        current_direction_ = sf::Vector2i(-current_direction_.x, -current_direction_.y);
    }
    else if(non_walkable_tiles_[leftTilePos.x][leftTilePos.y])
    {
        current_direction_ = sf::Vector2i(current_direction_.y, -current_direction_.x);
    }
    else
    {
        current_direction_ = sf::Vector2i(-current_direction_.y, current_direction_.x);
    }
}

void EnemyController::move()
{
    auto current_position = entity->get_component<MyTransform>()->position;

    sf::Vector2f target_position = sf::Vector2f(current_position.x + current_direction_.x * 32, current_position.y + current_direction_.y * 32);

    entity->get_component<Animator>()->translate_position(current_position, target_position, movement_speed);

    update_texture();
}

EnemyController::~EnemyController()
{

}

void EnemyController::update_texture()
{
    Direction direction;
    
    if(current_direction_ == sf::Vector2i(-1, 0))
    {
        direction = Left;
    }
    else if(current_direction_ == sf::Vector2i(1, 0))
    {
        direction = Right;
    }
    else if(current_direction_ == sf::Vector2i(0, -1))
    {
        direction = Up;
    }
    else if(current_direction_ == sf::Vector2i(0, 1))
    {
        direction = Down;
    }
    
    entity->get_component<MyRender>()->drawable = std::make_unique<sf::Sprite>(textures_[direction]);
    entity->get_component<FrameSequenceAnimation>()->initialize();
}
