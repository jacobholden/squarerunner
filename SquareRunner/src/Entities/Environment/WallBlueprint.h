#pragma once
#include <SFML/System/Vector2.hpp>

#include "../IEntityBlueprint.h"

class WallBlueprint : public IEntityBlueprint
{
public:
    WallBlueprint(sf::Vector2f position);
    void build_blueprint() override;

private:
    sf::Vector2f position_;
};
