#include "Game.h"

#include <SFML/Window/Event.hpp>

#include "Components/IUpdateable.h"
#include "Components/MyRender.h"
#include "Components/MyTransform.h"
#include "Managers/InputManager.h"
#include "Managers/TextureManager.h"
#include "Scenes/LevelScene.h"

const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 736;
const int TARGET_FPS = 60;
const sf::Time UPDATE_INTERVAL = sf::seconds(1.0f / TARGET_FPS);

Game::Game()
{
    window_.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Square Runner");
}

void Game::load_scene(IScene* level_scene)
{
    scene_ = level_scene;
}

void Game::run()
{
    auto level_scene = new LevelScene(WINDOW_WIDTH, WINDOW_HEIGHT);

    load_scene(level_scene);
    
    sf::Clock clock;
    while (window_.isOpen())
    {
        float delta_time = clock.restart().asSeconds();

        sf::Event event;
        while (window_.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window_.close();
                break;
            case sf::Event::LostFocus:
                break;
            case sf::Event::GainedFocus:
                break;
            case sf::Event::KeyPressed:
                InputManager::get_instance().set_key_pressed(event.key.code, true);
                break;
            case sf::Event::KeyReleased:
                InputManager::get_instance().set_key_pressed(event.key.code, false);
                break;
            case sf::Event::MouseWheelMoved:
                break;
            case sf::Event::MouseWheelScrolled:
                break;
            case sf::Event::MouseButtonPressed:
                // game->on_mouse_button(event.mouseButton);
                break;
            case sf::Event::MouseButtonReleased:
                break;
            case sf::Event::MouseMoved:
                // game->on_mouse_move(event.mouseMove);
                break;
            case sf::Event::MouseEntered:
                break;
            case sf::Event::MouseLeft:
                break;
            }
        }

        window_.clear(sf::Color::Black);

        update_and_render(delta_time);

        window_.display();
    }
}

void Game::update_and_render(float delta_time)
{
    for (const auto& entity : scene_->get_entities())
    {
        const auto updateables = entity->get_components<IUpdateable>();

        for (auto updateable : updateables)
        {
            if(updateable)
            {
                updateable->update(delta_time);
            }
        }
        
        const auto render = entity->get_component<MyRender>();
        const auto transform = entity->get_component<MyTransform>();
    
        if(render && transform)
        {
            const auto transformable = dynamic_cast<sf::Transformable*>(render->drawable.get());
            if (transformable)
            {
                transformable->setPosition(transform->position);
                transformable->setRotation(transform->rotation);
                window_.draw(*render->drawable);
            }
        }
    }
}
