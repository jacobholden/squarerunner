#include "Wall.h"

#include <iostream>
#include <SFML/Graphics/RenderTarget.hpp>

#include "../../Managers//TextureManager.h"
#include "../Entity.h"

Wall::Wall(): Wall(sf::Vector2f(0, 0))
{
}

Wall::Wall(sf::Vector2f pos)
{
    sprite = sf::Sprite(*TextureManager::get_texture("wall"));

    Wall::set_position(pos);
}

Wall::~Wall()
{
    std::cout << "Wall Deleted" << std::endl;
}

void Wall::set_position(sf::Vector2f pos)
{
    Entity::set_position(pos);

    sprite.setPosition(pos);

    rect_bounds = sprite.getGlobalBounds();
}

void Wall::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(sprite);
}
