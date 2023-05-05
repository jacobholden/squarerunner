#include "MenuItemBlueprint.h"

#include <SFML/Graphics/Text.hpp>

#include "../../../Components/MyRender.h"
#include "../../../Components/MyTransform.h"
#include "../../../Managers/AssetManager.h"

MenuItemBlueprint::MenuItemBlueprint(sf::Vector2f position, std::string content)
{
    position_ = position;
    content_ = content;
}

void MenuItemBlueprint::build_blueprint()
{
    set_name("menu_item");
    add_component<MyTransform>([this](MyTransform& component)
    {
        component.position = position_;
    });
    add_component<MyRender>([this](MyRender& component)
    {
        auto text = std::make_unique<sf::Text>(content_, *AssetManager::get_font("georgia"), 40);

        sf::FloatRect textBounds = text->getLocalBounds();
        text->setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
        
        component.drawable = std::move(text);
    });
}
