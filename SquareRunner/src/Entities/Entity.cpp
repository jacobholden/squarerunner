#include "Entity.h"

#include <iostream>

void Entity::add_component(std::unique_ptr<Component> component)
{
    components_.push_back(std::move(component));
}

std::vector<Component*> Entity::get_components() const
{
    std::vector<Component*> components;
    for (const auto& component : components_)
    {
        components.push_back(component.get());
    }
    return components;
}

void Entity::destroy()
{
    is_destroyed = true;
}
