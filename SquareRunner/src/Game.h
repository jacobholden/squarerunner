#pragma once
#include <SFML/Graphics/RenderWindow.hpp>

#include "Components/CircleCollidier.h"
#include "Components/MyTransform.h"
#include "Scenes/IScene.h"

class Game
{
public:
    Game();

    void load_scene(IScene* level_scene);
    void handle_scene_switching();
    void run();

    static IScene* get_current_scene()
    {
        return scene_;
    }

private:
    sf::RenderWindow window_;
    static IScene* scene_;

    struct ColliderStruct
    {
        Entity* entity;
        MyTransform my_transform;
        CircleCollidier circle_collidier;
    };

    void update_and_render(float delta_time);
    void check_collision(Entity* src_entity, std::vector<ColliderStruct> collider_structs);
};
