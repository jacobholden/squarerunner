#include "PlayerBlueprint.h"

#include "../../Components/Animator.h"
#include "../../Components/MyRender.h"
#include "../../Components/MyTransform.h"
#include "../../Components/Player/PlayerController.h"
#include "../../Managers/TextureManager.h"

PlayerBlueprint::PlayerBlueprint(sf::Vector2f position)
{
    position_ = position;
}

void PlayerBlueprint::build_blueprint()
{
    add_component<MyTransform>([this](MyTransform& component)
    {
        component.position = position_;
    });
    add_component<MyRender>([this](MyRender& component)
    {
        component.drawable = std::make_unique<sf::Sprite>(*TextureManager::get_texture("player_up"));
    });
    add_component<Animator>();
    add_component<PlayerController>();
}
