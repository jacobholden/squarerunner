#pragma once
#include <SFML/System/Vector2.hpp>

#include "Component.h"

class MyTransform : public Component
{
public:
    sf::Vector2f position;
    float rotation;
    void on_awake() override;
    ~MyTransform() override;
};
