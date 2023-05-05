#include "SafeZoneBlueprint.h"

#include "../../Components/MyTransform.h"
#include "../../Components/MyRender.h"
#include "../../Components/NonWalkable.h"
#include "../../Managers/AssetManager.h"

SafeZoneBlueprint::SafeZoneBlueprint(sf::Vector2f position)
{
    position_ = position;
}

void SafeZoneBlueprint::build_blueprint()
{
    add_component<MyTransform>([this](MyTransform& component)
    {
        component.position = position_;
    });
    add_component<MyRender>([this](MyRender& component)
    {
        component.drawable = std::make_unique<sf::Sprite>(*AssetManager::get_texture("safe_zone"));
    });
    add_component<NonWalkable>([this](NonWalkable& component)
    {
        component.player_non_walkable = false;
    });
}
