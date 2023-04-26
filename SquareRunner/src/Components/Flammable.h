#pragma once
#include "IUpdateable.h"

class Flammable : public IUpdateable
{
public:
    void on_awake() override;
    void update(float delta_time) override;
    ~Flammable() override;
    void ignite();

private:
    bool destroy_flag = false;
    float destroy_time = 0.20f;
};
