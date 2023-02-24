#include "Entity.h"

#include <iostream>

void Entity::add_component(std::unique_ptr<Component> component)
{
    components_.push_back(std::move(component));
}