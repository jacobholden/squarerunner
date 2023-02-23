#pragma once
#include <SFML\Window.hpp>
#include <SFML/Graphics/Drawable.hpp>

#include "../Components/Updateable.h"

class Entity : public sf::Drawable
{
public:
    Entity();
    virtual ~Entity();

protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

public:
    virtual void set_position(sf::Vector2f pos);
    virtual sf::Vector2f GetPosition();

protected:
    sf::Vector2f position;
};
