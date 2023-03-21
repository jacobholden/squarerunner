#include "SpinnerBlueprint.h"

#include "../../Components/FrameSequenceAnimation.h"
#include "../../Components/MyTransform.h"
#include "../../Components/MyRender.h"
#include "../../Components/NonWalkable.h"
#include "../../Managers/TextureManager.h"

SpinnerBlueprint::SpinnerBlueprint(sf::Vector2f position)
{
    position_ = position;
}

void SpinnerBlueprint::build_blueprint()
{
    add_component<MyTransform>([this](MyTransform& component)
    {
        component.position = position_;
    });
    add_component<MyRender>([this](MyRender& component)
    {
        component.drawable = std::make_unique<sf::Sprite>(*TextureManager::get_texture("spinner"));
    });
    add_component<FrameSequenceAnimation>([this](FrameSequenceAnimation& component)
    {
        component.fps = 20;
        component.frame_count = 12;
        component.looping = true;
    });
    add_component<NonWalkable>([this](NonWalkable& component)
    {
        component.player_non_walkable = false;
    });
}
