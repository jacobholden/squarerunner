#pragma once
#include <SFML/Graphics/Sprite.hpp>

#include "../Entity.h"

class Wall : public Entity
{
public:
    Wall();
    Wall(sf::Vector2f pos);
    ~Wall() override;

    void set_position(sf::Vector2f pos) override;

    sf::Sprite sprite;

    sf::FloatRect rect_bounds;

protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

public:
    
};
