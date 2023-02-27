#pragma once
#include "Component.h"

class IUpdateable : public Component
{
public:
    virtual void update(float delta_time) = 0;
};
