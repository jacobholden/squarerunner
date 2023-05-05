#include "ArrowLeftBlueprint.h"

#include "../../Components/FrameSequenceAnimation.h"
#include "../../Components/MyTransform.h"
#include "../../Components/MyRender.h"
#include "../../Components/NonWalkable.h"
#include "../../Managers/AssetManager.h"

ArrowLeftBlueprint::ArrowLeftBlueprint(sf::Vector2f position)
{
    position_ = position;
}

void ArrowLeftBlueprint::build_blueprint()
{
    add_component<MyTransform>([this](MyTransform& component)
    {
        component.position = position_;
    });
    add_component<MyRender>([this](MyRender& component)
    {
        component.drawable = std::make_unique<sf::Sprite>(*AssetManager::get_texture("arrow_left"));
    });
    add_component<FrameSequenceAnimation>([this](FrameSequenceAnimation& component)
    {
        component.fps = 20;
        component.frame_count = 18;
        component.looping = true;
    });
    add_component<NonWalkable>([this](NonWalkable& component)
    {
        component.player_non_walkable = false;
    });
}
