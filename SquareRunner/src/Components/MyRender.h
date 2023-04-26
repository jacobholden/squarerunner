#pragma once
#include <memory>
#include <SFML/Graphics/Sprite.hpp>

#include "Component.h"

class MyRender : public Component
{
public:
    ~MyRender() override;
    std::unique_ptr<sf::Drawable> drawable;
    void on_awake() override;
    int z_order = 0;
};
