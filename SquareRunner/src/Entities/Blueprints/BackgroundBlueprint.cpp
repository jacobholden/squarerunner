﻿#include "BackgroundBlueprint.h"

#include "../../Components/MyRender.h"
#include "../../Components/MyTransform.h"
#include "../../Managers/TextureManager.h"

BackgroundBlueprint::BackgroundBlueprint(sf::IntRect size)
{
    size_ = size;
}

void BackgroundBlueprint::build_blueprint()
{
    add_component<MyTransform>();
    add_component<MyRender>([this](MyRender& component)
    {
        component.drawable = std::make_unique<sf::Sprite>(*TextureManager::get_texture("floor"), size_);
    });
}