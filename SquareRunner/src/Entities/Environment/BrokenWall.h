#pragma once
#include <SFML/System/Vector2.hpp>

#include "../IEntityBlueprint.h"

class BrokenWall : public IEntityBlueprint
{
public:
    BrokenWall(sf::Vector2f position);
    void build_blueprint() override;

private:
    sf::Vector2f position_;
};
