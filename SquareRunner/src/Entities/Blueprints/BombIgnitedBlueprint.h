#pragma once
#include <SFML/System/Vector2.hpp>

#include "../IEntityBlueprint.h"

class BombIgnitedBlueprint : public IEntityBlueprint
{
public:
    BombIgnitedBlueprint(sf::Vector2f position);
    void build_blueprint() override;

private:
    sf::Vector2f position_;
};
