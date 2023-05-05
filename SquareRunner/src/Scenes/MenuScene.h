#pragma once
#include "IScene.h"

class MenuScene : public IScene
{
public:
    MenuScene(int width, int height);
    ~MenuScene() override;
    void on_mouse_button(const sf::Event::MouseButtonEvent& mouse_button) override;
    void on_mouse_move(const sf::Event::MouseMoveEvent& mouse_move) override;
    void initialise_entities() override;
    void on_entity_destroyed(const std::unique_ptr<Entity>& entity) override;

private:
    std::vector<std::string> get_levels();
    std::vector<Entity*> menu_items_;
};