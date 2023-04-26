#include "EscapeBlueprint.h"

#include "../../Components/CircleCollidier.h"
#include "../../Components/Destructible.h"
#include "../../Components/FrameSequenceAnimation.h"
#include "../../Components/MyRender.h"
#include "../../Components/MyTransform.h"
#include "../../Components/NonWalkable.h"
#include "../../Managers/TextureManager.h"

EscapeBlueprint::EscapeBlueprint(sf::Vector2f position)
{
    position_ = position;
}

void EscapeBlueprint::build_blueprint()
{
    set_name("exit");
    add_component<MyTransform>([this](MyTransform& component)
    {
        component.position = position_;
    });
    add_component<MyRender>([this](MyRender& component)
    {
        component.drawable = std::make_unique<sf::Sprite>(*TextureManager::get_texture("exit"));
    });
    add_component<FrameSequenceAnimation>([this](FrameSequenceAnimation& component)
    {
        component.fps = 12;
        component.frame_count = 4;
        component.looping = true;
    });
    add_component<NonWalkable>([this](NonWalkable& component)
    {
        component.player_non_walkable = false;
    });
    add_component<Destructible>();
    add_component<CircleCollidier>([this](CircleCollidier& component)
    {
        component.radius = 1;
    });
}
