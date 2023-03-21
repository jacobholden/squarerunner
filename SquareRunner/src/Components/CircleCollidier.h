#pragma once

#include <functional>

#include "../Entities/Entity.h"

class CircleCollidier : public Component
{
public:
    void on_awake() override;
    ~CircleCollidier() override;
    float radius = 16;
    std::function<void(Entity* other_entity)> func;
    bool is_awake = false;

    void invoke_func(Entity* other_entity)
    {
        if(func != nullptr)
        {
            func(other_entity);            
        }
    }
};
