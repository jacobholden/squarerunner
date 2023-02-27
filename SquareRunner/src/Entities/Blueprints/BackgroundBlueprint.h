#pragma once
#include <SFML/Graphics/Rect.hpp>

#include "../IEntityBlueprint.h"

class BackgroundBlueprint : public IEntityBlueprint
{
public:
    BackgroundBlueprint(sf::IntRect size);
    
    void build_blueprint() override;

private:
    sf::IntRect size_;
};
