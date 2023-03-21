#pragma once
#include "Component.h"

class Destructible : public Component
{
public:
    ~Destructible() override;
    void on_awake() override;
};
