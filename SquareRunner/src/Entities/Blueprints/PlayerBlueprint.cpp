#include "PlayerBlueprint.h"

#include "../../Components/MyRender.h"
#include "../../Components/MyTransform.h"
#include "../../Managers/TextureManager.h"

void PlayerBlueprint::build_blueprint()
{
    add_component<MyTransform>([](MyTransform& component)
    {
        component.position = sf::Vector2f(200, 200);
    });
    add_component<MyRender>([](MyRender& component)
    {
        component.drawable = std::make_unique<sf::Sprite>(*TextureManager::get_texture("player_up"));
    });
}
