#pragma once

class Entity;

class Component
{
public:
    virtual ~Component() {}
    virtual void on_awake() {}
    Entity* entity;
};
