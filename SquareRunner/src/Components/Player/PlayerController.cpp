#include "PlayerController.h"

#include "../MyTransform.h"
#include "../../Entities/Entity.h"

void PlayerController::update(float delta_time)
{
    entity->get_component<MyTransform>()->position = sf::Vector2f(600, 600);
}
