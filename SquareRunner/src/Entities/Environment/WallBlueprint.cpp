#include "WallBlueprint.h"

#include "../../Components/MyTransform.h"
#include "../../Components/MyRender.h"
#include "../../Components/NonWalkable.h"
#include "../../Managers/AssetManager.h"

WallBlueprint::WallBlueprint(sf::Vector2f position)
{
    position_ = position;
}

void WallBlueprint::build_blueprint()
{
    add_component<MyTransform>([this](MyTransform& component)
    {
        component.position = position_;
    });
    add_component<MyRender>([this](MyRender& component)
    {
        component.drawable = std::make_unique<sf::Sprite>(*AssetManager::get_texture("wall"));
    });
    add_component<NonWalkable>();
}
