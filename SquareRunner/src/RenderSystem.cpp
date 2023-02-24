#include "RenderSystem.h"

#include <SFML/Graphics/Transformable.hpp>
#include "Components/MyRender.h"
#include "Components/MyTransform.h"

void RenderSystem::update(float delta_time)
{
    for (const auto& entity : entities_)
    {
        auto render = entity->get_component<MyRender>();
        auto transform = entity->get_component<MyTransform>();
        auto transformable = dynamic_cast<sf::Transformable*>(render->drawable);
        if (transformable)
        {
            transformable->setPosition(transform->position);
            transformable->setRotation(transform->rotation);
            window_->draw(*render->drawable);
        }
    }
}

void RenderSystem::add_entity(Entity* entity)
{
    entities_.push_back(entity);
}

void RenderSystem::set_window(sf::RenderWindow* window)
{
    window_ = window;
}
