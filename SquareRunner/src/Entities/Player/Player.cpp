#include "Player.h"

#include <iostream>
#include <SFML/Graphics/RenderTarget.hpp>

#include "../../Managers/InputManager.h"

Player::Player(): Player(sf::Vector2f(0, 0))
{
}

Player::Player(sf::Vector2f pos)
{
    sprite = std::make_unique<sf::Sprite>(textures_[1]);

    Player::set_position(pos);
}

Player::~Player()
{
    std::cout << "Player Deleted" << std::endl;
}

void Player::update(float elapsedTime)
{
    if(!is_moving_)
    {
        if(InputManager::get_instance().is_key_pressed(sf::Keyboard::Left))
        {
            set_target_position(position + sf::Vector2f(-32, 0), 0);
        }
        else if(InputManager::get_instance().is_key_pressed(sf::Keyboard::Right))
        {
            set_target_position(position + sf::Vector2f(32, 0), 1);
        }
        else if(InputManager::get_instance().is_key_pressed(sf::Keyboard::Up))
        {
            set_target_position(position + sf::Vector2f(0, -32), 2);
        }
        else if(InputManager::get_instance().is_key_pressed(sf::Keyboard::Down))
        {
            set_target_position(position + sf::Vector2f(0, 32), 3);
        }
    }
    
    if(is_moving_)
    {
        time_traveled_ += elapsedTime / duration_;

        if(time_traveled_ >= 1.0f)
        {
            is_moving_ = false;

            time_traveled_ = 1.0f;
        }

        const sf::Vector2f new_position = start_position_ + time_traveled_ * (end_position_ - start_position_);

        set_position(new_position);
    }
}

void Player::set_position(sf::Vector2f pos)
{
    Entity::set_position(pos);

    sprite->setPosition(pos);
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(*sprite);
}

void Player::set_target_position(sf::Vector2f target_position, int look_direction)
{
    start_position_ = position;
    
    end_position_ = target_position;
    
    sprite->setTexture(textures_[look_direction]);

    time_traveled_ = 0;

    is_moving_ = true;
}