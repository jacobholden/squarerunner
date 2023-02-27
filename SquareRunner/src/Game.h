#pragma once
#include <SFML/Graphics/RenderWindow.hpp>

#include "Scenes/IScene.h"

class Game
{
public:
    Game();

    void load_scene(IScene* level_scene);
    void run();
    void update_and_render(float delta_time);

private:
    sf::RenderWindow window_;
    IScene* scene_;
};
