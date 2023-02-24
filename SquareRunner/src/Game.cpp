#include "Game.h"

#include <SFML/Window/Event.hpp>

#include "Components/MyRender.h"
#include "Components/MyTransform.h"
#include "Entities/Blueprints/PlayerBlueprint.h"
#include "Managers/TextureManager.h"

Game::Game()
{
    window_.create(sf::VideoMode(800, 600), "SFML ECS Example");
    render_system_.set_window(&window_);
}

void Game::run()
{
    // Create an entity with a transform and a sprite
    auto entity = create_entity(new PlayerBlueprint);

    // Add entity
    render_system().add_entity(entity);
    
    sf::Clock clock;
    while (window_.isOpen())
    {
        float delta_time = clock.restart().asSeconds();

        sf::Event event;
        while (window_.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window_.close();
            }
        }

        window_.clear(sf::Color::Black);

        render_system_.update(delta_time);

        window_.display();
    }
}

Entity* Game::create_entity()
{
    entities_.emplace_back(new Entity);
    return entities_.back().get();
}

Entity* Game::create_entity(IEntityBlueprint* entity_blueprint)
{
    Entity* entity = new Entity;

    // Build the entity blueprint
    entity_blueprint->build_blueprint();

    // Add components to the entity
    for (auto& component : entity_blueprint->components_)
    {
        entity->add_component(std::move(component));
    }

    // Add the entity to the game's list of entities
    entities_.emplace_back(std::unique_ptr<Entity>(entity));

    // Return the created entity
    return entity;
}

RenderSystem& Game::render_system()
{
    return render_system_;
}
