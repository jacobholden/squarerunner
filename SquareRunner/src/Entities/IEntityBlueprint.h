#pragma once

#include "Entity.h"

class IEntityBlueprint
{
public:
    template <typename T> IEntityBlueprint& add_component();
    template <typename T, typename Func> IEntityBlueprint& add_component(Func&& init);
    IEntityBlueprint& set_name(std::string new_name);

    virtual void build_blueprint() = 0;

    std::vector<std::unique_ptr<Component>> components_;
    Entity* entity;
    std::string name;
};

template <typename T>
IEntityBlueprint& IEntityBlueprint::add_component()
{
    auto component = std::make_unique<T>();
    std::unique_ptr<Component> component_base = std::move(component);

    component_base->entity = entity;
    
    components_.push_back(std::move(component_base));
    return *this;
}

template <typename T, typename Func>
IEntityBlueprint& IEntityBlueprint::add_component(Func&& init)
{
    auto component = std::make_unique<T>();
    
    init(*component);
    
    std::unique_ptr<Component> component_base = std::move(component);
    
    component_base->entity = entity;
    
    components_.push_back(std::move(component_base));
    
    return *this;
}
