#pragma once
#include <SFML/Graphics/RenderWindow.hpp>

#include "RenderSystem.h"
#include "entities/Entity.h"

class Game
{
public:
    Game();

    void run();

    Entity* create_entity();

    RenderSystem& render_system();

private:
    sf::RenderWindow window_;
    std::vector<std::unique_ptr<Entity>> entities_;
    RenderSystem render_system_;
};
