#include "MenuInputBlueprint.h"

#include "../../../Components/MyTransform.h"
#include "../../../Components/Menu/MenuInputController.h"

MenuInputBlueprint::MenuInputBlueprint(std::vector<Entity*> menu_item_entities)
{
    menu_item_entities_ = menu_item_entities;
}

void MenuInputBlueprint::build_blueprint()
{
    add_component<MyTransform>();
    add_component<MenuInputController>([this](MenuInputController& component)
    {
        component.menu_item_entities = menu_item_entities_;
    });
}
