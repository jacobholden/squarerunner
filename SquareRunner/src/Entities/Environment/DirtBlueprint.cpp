﻿#include "DirtBlueprint.h"

#include "../../Components/CircleCollidier.h"
#include "../../Components/Destructible.h"
#include "../../Components/MyTransform.h"
#include "../../Components/MyRender.h"
#include "../../Components/NonWalkable.h"
#include "../../Managers/TextureManager.h"

DirtBlueprint::DirtBlueprint(sf::Vector2f position)
{
    position_ = position;
}

void DirtBlueprint::build_blueprint()
{
    set_name("dirt");
    add_component<MyTransform>([this](MyTransform& component)
    {
        component.position = position_;
    });
    add_component<MyRender>([this](MyRender& component)
    {
        component.drawable = std::make_unique<sf::Sprite>(*TextureManager::get_texture("dirt"));
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