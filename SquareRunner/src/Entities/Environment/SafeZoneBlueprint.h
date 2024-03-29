﻿#pragma once
#include <SFML/System/Vector2.hpp>

#include "../IEntityBlueprint.h"

class SafeZoneBlueprint : public IEntityBlueprint
{
public:
    SafeZoneBlueprint(sf::Vector2f position);
    void build_blueprint() override;

private:
    sf::Vector2f position_;
};
