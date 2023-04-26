#include "Animator.h"

#include "MyTransform.h"
#include "../Entities/Entity.h"

void Animator::translate_position(sf::Vector2f start_position, sf::Vector2f end_position, float duration)
{
    // Do not allow the animation to start if one is already playing
    if(is_playing_)
    {
        return;
    }

    // Initialise the variables needed to perform the animation
    start_position_ = start_position;
    end_position_ = end_position;

    float deltaX = end_position.x - start_position.x;
    float deltaY = end_position.y - start_position.y;
    distance_ = sqrt(deltaX * deltaX + deltaY * deltaY);
    x_direction_ = deltaX / distance_;
    y_direction_ = deltaY / distance_;

    duration_ = duration;

    is_playing_ = true;
}

void Animator::update(float delta_time)
{
    if(is_playing_)
    {
        elapsed_time_ += delta_time;

        float percentageComplete = elapsed_time_ / duration_;

        // Clamp so the animation cannot overshoot
        if (percentageComplete > 1.0)
        {
            percentageComplete = 1.0;
        }

        // Calculate the current position for this frame
        auto currentPosition = sf::Vector2f(start_position_.x + x_direction_ * distance_ * percentageComplete,start_position_.y + y_direction_ * distance_ * percentageComplete);

        // Set the position
        entity->get_component<MyTransform>()->position = currentPosition;

        // If the animation is complete, reset
        if (percentageComplete >= 1.0)
        {
            reset();
        }
    }
}

bool Animator::is_playing()
{
    return is_playing_;
}

void Animator::on_awake()
{
    IUpdateable::on_awake();
}

sf::Vector2f Animator::get_target_position()
{
    return end_position_;
}

void Animator::reset()
{
    is_playing_ = false;
    
    elapsed_time_ = 0.f;
}

Animator::~Animator()
{
    // No dynamically allocated memory to clean-up.
}
