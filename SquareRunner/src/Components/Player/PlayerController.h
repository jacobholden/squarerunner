#pragma once
#include "../IUpdateable.h"

class PlayerController : public IUpdateable
{
public:
    void update(float delta_time) override;
};
