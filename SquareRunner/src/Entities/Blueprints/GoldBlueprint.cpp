#include "GoldBlueprint.h"

#include "../../Components/CircleCollidier.h"
#include "../../Components/Destructible.h"
#include "../../Components/MyTransform.h"
#include "../../Components/MyRender.h"
#include "../../Components/NonWalkable.h"
#include "../../Managers/AssetManager.h"

GoldBlueprint::GoldBlueprint(sf::Vector2f position)
{
    position_ = position;
}

void GoldBlueprint::build_blueprint()
{
    set_name("gold");
    add_component<MyTransform>([this](MyTransform& component)
    {
        component.position = position_;
    });
    add_component<MyRender>([this](MyRender& component)
    {
        component.drawable = std::make_unique<sf::Sprite>(*AssetManager::get_texture("gold"));
    });
    add_component<NonWalkable>([this](NonWalkable& component)
    {
        component.player_non_walkable = false;
    });
    add_component<CircleCollidier>([this](CircleCollidier& component)
    {
        component.radius = 8;
    });
    add_component<Destructible>();
}
