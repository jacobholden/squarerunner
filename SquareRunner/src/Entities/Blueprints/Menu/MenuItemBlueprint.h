#pragma once

#include <SFML/System/Vector2.hpp>

#include "../../IEntityBlueprint.h"

class MenuItemBlueprint : public IEntityBlueprint
{
public:
    MenuItemBlueprint(sf::Vector2f position, std::string content);
    void build_blueprint() override;

private:
    sf::Vector2f position_;
    std::string content_;
};
