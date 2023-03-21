#include "Game.h"

#include <iostream>
#include <ostream>
#include <SFML/Window/Event.hpp>

#include "Components/CircleCollidier.h"
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

IScene* Game::scene_ = nullptr;

Game::Game()
{
    window_.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Square Runner");
}

void Game::load_scene(IScene* level_scene)
{
    scene_ = level_scene;
}

void Game::handle_scene_switching()
{
    if(scene_ != nullptr)
    {
        if(!scene_->is_scene_running())
        {
            delete scene_;
        }
        else
        {
            return;
        }
    }
    
    load_scene(new LevelScene(WINDOW_WIDTH, WINDOW_HEIGHT));
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

        handle_scene_switching();

        update_and_render(delta_time);

        window_.display();
    }
}

void Game::update_and_render(float delta_time)
{
    scene_->initialise_entities();
    
    auto& entities = scene_->get_entities();
    auto it = entities.begin();

    std::vector<ColliderStruct> collider_structs;

    for (auto& entity : entities)
    {
        auto trans = entity.get()->get_component<MyTransform>();
        auto circ = entity.get()->get_component<CircleCollidier>();
        if(trans && circ)
        {
            collider_structs.push_back(ColliderStruct{entity.get(), *trans, *circ});
        }
    }

    std::vector<MyRender*> renderables;
    
    while (it != entities.end())
    {
        const auto& entity = *it;
        
        auto updateables = entity->get_components<IUpdateable>();
        
        for (const auto updateable : updateables)
        {
            if(updateable)
            {
                updateable->update(delta_time);
            }
        }
        
        const auto transform = entity->get_component<MyTransform>();

        if(transform)
        {
            const auto circle_collidier = entity->get_component<CircleCollidier>();
            
            if(circle_collidier && circle_collidier->is_awake)
            {
                check_collision(entity.get(), collider_structs);
            }

            // Remove destroyed entities
            if (entity->is_destroyed)
            {
                get_current_scene()->on_entity_destroyed(entity);
            
                it = entities.erase(it);

                continue;
            }
            else
            {
                ++it;
            }

            const auto render = entity->get_component<MyRender>();
            
            if(render)
            {
                const auto transformable = dynamic_cast<sf::Transformable*>(render->drawable.get());
                if (transformable)
                {
                    transformable->setPosition(transform->position);
                    transformable->setRotation(transform->rotation);

                    renderables.push_back(render);
                }
            }
        }
    }

    std::sort(renderables.begin(), renderables.end(),
          [](MyRender* a, MyRender* b) { return a->z_order < b->z_order; });

    for (const auto& renderable : renderables)
    {
        window_.draw(*renderable->drawable);
    }
}

void Game::check_collision(Entity* src_entity, std::vector<ColliderStruct> collider_structs)
{
    for (auto& collider : collider_structs)
    {
        if(collider.entity->is_destroyed)
        {
            continue;
        }
        
        if(src_entity == collider.entity)
        {
            continue;
        }
        
        sf::Vector2f delta = src_entity->get_component<MyTransform>()->position - collider.my_transform.position;
            
        float distance = std::sqrt(delta.x * delta.x + delta.y * delta.y);
        
        auto circle_collidier_a = src_entity->get_component<CircleCollidier>();
        
        float radius_sum = circle_collidier_a->radius + collider.circle_collidier.radius;
            
        if (distance <= radius_sum)
        {
            circle_collidier_a->invoke_func(collider.entity);
            collider.circle_collidier.invoke_func(src_entity);
        }
    }
}
