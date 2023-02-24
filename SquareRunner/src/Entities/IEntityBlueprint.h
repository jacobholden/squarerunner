﻿#pragma once
#include <string>

#include "Entity.h"

class IEntityBlueprint
{
public:
    template <typename T> IEntityBlueprint& add_component();
    template <typename T, typename Func> IEntityBlueprint& add_component(Func&& init);

    virtual void build_blueprint() = 0;

    std::vector<std::unique_ptr<Component>> components_;
};

template <typename T>
IEntityBlueprint& IEntityBlueprint::add_component()
{
    // Create a new unique_ptr that points to a new instance of T
    components_.push_back(std::make_unique<T>());

    // Return the EntityBlueprint object for method chaining
    return *this;
}

template <typename T, typename Func>
IEntityBlueprint& IEntityBlueprint::add_component(Func&& init)
{
    // Create a new unique_ptr that points to a new instance of T
    auto component = std::make_unique<T>();

    // Initialize the component using the lambda function
    init(*component);

    // Add the component to the vector of components
    components_.push_back(std::move(component));

    // Return the EntityBlueprint object for method chaining
    return *this;
}