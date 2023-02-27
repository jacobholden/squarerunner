#pragma once

class Entity;

class Component
{
public:
    virtual ~Component() {}
    Entity* entity;
};
