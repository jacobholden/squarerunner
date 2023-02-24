#pragma once
#include <SFML/Graphics/Sprite.hpp>

#include "Component.h"

class MyRender : public Component
{
public:
    sf::Drawable* drawable;
};
