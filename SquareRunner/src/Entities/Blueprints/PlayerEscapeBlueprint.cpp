#include "PlayerEscapeBlueprint.h"

#include "../../Game.h"
#include "../../Components/FrameSequenceAnimation.h"
#include "../../Components/MyRender.h"
#include "../../Components/MyTransform.h"
#include "../../Managers/TextureManager.h"

PlayerEscapeBlueprint::PlayerEscapeBlueprint(sf::Vector2f position)
{
    position_ = position;
}

void PlayerEscapeBlueprint::build_blueprint()
{
    set_name("player_escape");
    add_component<MyTransform>([this](MyTransform& component)
    {
        component.position = position_;
    });
    add_component<MyRender>([this](MyRender& component)
    {
        component.drawable = std::make_unique<sf::Sprite>(*TextureManager::get_texture("player_escape"));
        component.z_order = 1;
    });
    add_component<FrameSequenceAnimation>([this](FrameSequenceAnimation& component)
    {
        component.fps = 30;
        component.frame_count = 27;
        component.on_complete_function = [this]
        {
            Game::get_current_scene()->end_scene();
        };
    });
}
