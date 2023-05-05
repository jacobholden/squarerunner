#pragma once
#include <vector>
#include <SFML/Graphics/Color.hpp>

#include "../IUpdateable.h"

class MenuInputController : public IUpdateable
{
public:
    void update(float delta_time) override;
    void on_awake() override;
    ~MenuInputController() override;

    std::vector<Entity*> menu_item_entities;

private:
    int current_item_index_;
    bool is_down_held_;
    bool is_up_held_;

    void set_text_colour(int item_index, sf::Color colour);
};
