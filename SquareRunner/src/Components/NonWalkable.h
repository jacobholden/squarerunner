#pragma once
#include "Component.h"

class NonWalkable : public Component
{
public:
    ~NonWalkable() override;
    void on_awake() override;
    bool player_non_walkable = true;
    bool enemy_non_walkable = true;
};
