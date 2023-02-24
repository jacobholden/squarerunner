#pragma once
#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>

#include "System.h"
#include "entities/Entity.h"

class RenderSystem : public System
{
public:
    void update(float delta_time) override;
    void add_entity(Entity* entity);
    void set_window(sf::RenderWindow* window);

private:
    std::vector<Entity*> entities_;
    sf::RenderWindow* window_;
};
