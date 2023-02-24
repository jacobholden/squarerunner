#pragma once
#include <memory>
#include <SFML/Graphics/Sprite.hpp>

#include "Component.h"

class MyRender : public Component
{
public:
    std::unique_ptr<sf::Drawable> drawable;
};
