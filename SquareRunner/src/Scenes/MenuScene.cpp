#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING

#include "MenuScene.h"

#include <SFML/Graphics/Rect.hpp>
#include "../Entities/Blueprints/BackgroundBlueprint.h"
#include "../Entities/Blueprints/Menu/MenuItemBlueprint.h"
#include "../Entities/Blueprints/Menu/MenuInputBlueprint.h"
#include <experimental/filesystem>
#include <iostream>

const static std::string levels_location = "Assets/levels/";

MenuScene::MenuScene(int width, int height): IScene(width, height)
{
    // Create an entity with a transform and a sprite
    create_entity(new BackgroundBlueprint(sf::IntRect(0, 0, width, height)));

    auto levels_list = get_levels();

    for(int index = 0; index < levels_list.size(); index ++)
    {
        auto menu_item = create_entity(new MenuItemBlueprint(sf::Vector2f(640, 200 + 50 * index), levels_list.at(index)));
        menu_item->name = levels_list.at(index);

        menu_items_.emplace_back(menu_item);
    }

    create_entity(new MenuInputBlueprint(menu_items_));
}

MenuScene::~MenuScene()
{
}

void MenuScene::on_mouse_button(const sf::Event::MouseButtonEvent& mouse_button)
{
}

void MenuScene::on_mouse_move(const sf::Event::MouseMoveEvent& mouse_move)
{
}

void MenuScene::initialise_entities()
{
    IScene::initialise_entities();
}

void MenuScene::on_entity_destroyed(const std::unique_ptr<Entity>& entity)
{
}

void MenuScene::update(float delta_time)
{
    IScene::update(delta_time);
}

std::vector<std::string> MenuScene::get_levels()
{
    const auto list = std::make_unique<std::vector<std::string>>();
    
    for (const auto& entry : std::experimental::filesystem::directory_iterator(levels_location))
    {
        if (entry.status().type() == std::experimental::filesystem::file_type::regular)
        {
            auto level_name = entry.path().filename().string();

            list->emplace_back(level_name);
        }
    }

    return *list;
}
