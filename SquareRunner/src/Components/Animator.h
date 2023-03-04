#pragma once
#include <SFML/System/Vector2.hpp>

#include "IUpdateable.h"

class Animator : public IUpdateable
{
public:
    void translate_position(sf::Vector2f start_position, sf::Vector2f end_position, float duration);
    void update(float delta_time) override;
    bool is_playing();

private:
    void reset();
    
    bool is_playing_;
    sf::Vector2f start_position_;
    sf::Vector2f end_position_;
    sf::Vector2f current_position_;
    float elapsed_time_;
    float duration_;
    sf::Vector2f duration;

    float distance_;
    float x_direction_;
    float y_direction_;
};
