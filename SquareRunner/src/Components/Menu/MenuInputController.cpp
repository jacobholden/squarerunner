#include "MenuInputController.h"

#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Keyboard.hpp>

#include "../MyRender.h"
#include "../../Entities/Entity.h"
#include "../../Game.h"

MenuInputController::~MenuInputController()
{
}

void MenuInputController::update(float delta_time)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !is_up_held_)
    {
        is_up_held_ = true;

        set_text_colour(current_item_index_, sf::Color::White);
        
        current_item_index_ --;

        if(current_item_index_ < 0)
        {
            current_item_index_ = menu_item_entities.size() - 1;
        }

        set_text_colour(current_item_index_, sf::Color::Yellow);
    }
    else if(!sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        is_up_held_ = false;
    }
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !is_down_held_)
    {
        is_down_held_ = true;

        set_text_colour(current_item_index_, sf::Color::White);
        
        current_item_index_ ++;

        if(current_item_index_ > menu_item_entities.size() - 1)
        {
            current_item_index_ = 0;
        }

        set_text_colour(current_item_index_, sf::Color::Yellow);
    }
    else if(!sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        is_down_held_ = false;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
        Game::set_level_name(menu_item_entities[current_item_index_]->name);
        Game::get_current_scene()->end_scene();
    }
}

void MenuInputController::on_awake()
{
    set_text_colour(current_item_index_, sf::Color::Yellow);
}

void MenuInputController::set_text_colour(int item_index, sf::Color colour)
{
    auto drawable = menu_item_entities[item_index]->get_component<MyRender>()->drawable.get();
    
    auto text = dynamic_cast<sf::Text*>(drawable);
    
    if (text != nullptr)
    {
        text->setFillColor(colour);
    }
}