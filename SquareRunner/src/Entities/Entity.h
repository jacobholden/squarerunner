#pragma once
#include <memory>
#include <vector>
#include "../Components/Component.h"

class Entity {
public:
    void add_component(std::unique_ptr<Component> component);

    template <typename T>
    T* get_component() const;

private:
    std::vector<std::unique_ptr<Component>> components_;
};

template <typename T>
T* Entity::get_component() const
{
    for (const auto& component : components_)
    {
        if (auto t = dynamic_cast<T*>(component.get()))
        {
            return t;
        }
    }
    return nullptr;
}