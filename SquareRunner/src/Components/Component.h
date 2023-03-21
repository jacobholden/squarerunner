#pragma once

class Entity;

class Component
{
public:
    virtual ~Component() = default;
    virtual void on_awake() {}
    Entity* entity;
};
