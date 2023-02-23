#include "Entity.h"

#include <iostream>

Entity::Entity()
{
}

Entity::~Entity()
{
    std::cout << "Deleted" << std::endl;
}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
}

void Entity::set_position(sf::Vector2f pos)
{
    position = pos;
}

sf::Vector2f Entity::GetPosition()
{
    return position;
}
