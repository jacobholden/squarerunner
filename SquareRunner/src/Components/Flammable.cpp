#include "Flammable.h"

#include "../Components/MyTransform.h"
#include "../Game.h"
#include "../Entities/Blueprints/ExplosionBlueprint.h"
#include "../Managers/SoundManager.h"

void Flammable::on_awake()
{
    IUpdateable::on_awake();
}

void Flammable::update(float delta_time)
{
    if(!destroy_flag)
    {
        return;
    }
    
    destroy_time -= delta_time;

    if(destroy_time <= 0)
    {
        auto position = entity->get_component<MyTransform>()->position;

        for(int i = 0; i < 3; i ++)
        {
            for(int j = 0; j < 3; j ++)
            {
                Game::get_current_scene()->create_entity(new ExplosionBlueprint(sf::Vector2f(position.x - 32 + i * 32, position.y - 32 + j * 32)));
            }
        }
        
        SoundManager::play_sound("explosion");
        
        entity->destroy();
    }
}

Flammable::~Flammable()
{
}

void Flammable::ignite()
{
    destroy_flag = true;
}
