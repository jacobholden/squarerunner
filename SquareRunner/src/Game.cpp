#include "Game.h"

#include <SFML/Window/Event.hpp>

Game::Game()
{
    window_.create(sf::VideoMode(800, 600), "SFML ECS Example");
    render_system_.set_window(&window_);
}

void Game::run()
{
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

RenderSystem& Game::render_system()
{
    return render_system_;
}
