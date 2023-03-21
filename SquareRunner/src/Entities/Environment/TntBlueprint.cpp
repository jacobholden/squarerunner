#include "TntBlueprint.h"

#include <SFML/Graphics/Sprite.hpp>

#include "../../Components/CircleCollidier.h"
#include "../../Components/Flammable.h"
#include "../../Components/MyTransform.h"
#include "../../Components/MyRender.h"
#include "../../Components/NonWalkable.h"
#include "../../Managers/TextureManager.h"

TntBlueprint::TntBlueprint(sf::Vector2f position)
{
    position_ = position;
}

void TntBlueprint::build_blueprint()
{
    set_name("tnt");
    add_component<MyTransform>([this](MyTransform& component)
    {
        component.position = position_;
    });
    add_component<MyRender>([this](MyRender& component)
    {
        component.drawable = std::make_unique<sf::Sprite>(*TextureManager::get_texture("tnt"));
    });
    add_component<Flammable>();
    add_component<CircleCollidier>([this](CircleCollidier& component)
    {
        component.radius = 8;
    });
    add_component<NonWalkable>();
}
