#include "IScene.h"

IScene::IScene(int width, int height)
{
}

IScene::~IScene()
{
}

Entity* IScene::create_entity()
{
    entities_.emplace_back(new Entity);
    return entities_.back().get();
}

Entity* IScene::create_entity(IEntityBlueprint* entity_blueprint)
{
    Entity* entity = new Entity;

    entity_blueprint->entity = entity;

    // Build the entity blueprint
    entity_blueprint->build_blueprint();

    // Add components to the entity
    for (auto& component : entity_blueprint->components_)
    {
        entity->add_component(std::move(component));
    }

    for (auto& component : entity->get_components())
    {
        component->on_awake();
    }

    // Add the entity to the game's list of entities
    entities_.emplace_back(std::unique_ptr<Entity>(entity));
    // Return the created entity
    return entity;
}

std::vector<std::unique_ptr<Entity>>& IScene::get_entities()
{
    return entities_;
}
