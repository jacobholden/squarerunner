#include "ExplosionBlueprint.h"

#include "../../Components/FrameSequenceAnimation.h"
#include "../../Components/MyRender.h"
#include "../../Components/MyTransform.h"
#include "../../Managers/AssetManager.h"
#include "../../Components/CircleCollidier.h"
#include "../../Game.h"
#include "../../Components/Destructible.h"
#include "../../Components/Flammable.h"
#include "../../Managers/SoundManager.h"

ExplosionBlueprint::ExplosionBlueprint(sf::Vector2f position)
{
    position_ = position;
}

void ExplosionBlueprint::build_blueprint()
{
    set_name("explosion");
    add_component<MyTransform>([this](MyTransform& component)
    {
        component.position = position_;
    });
    add_component<MyRender>([this](MyRender& component)
    {
        component.drawable = std::make_unique<sf::Sprite>(*AssetManager::get_texture("explosion"));
        component.z_order = 2;
    });
    add_component<FrameSequenceAnimation>([this](FrameSequenceAnimation& component)
    {
        component.fps = 30;
        component.frame_count = 10;
        component.on_complete_function = [this]
        {
            entity->destroy();
        };
    });
    add_component<CircleCollidier>([this](CircleCollidier& component)
    {
        component.radius = 16;
        component.func = [](Entity* other_entity)
        {
            if(other_entity->get_component<Destructible>())
            {
                other_entity->destroy();
            }

            auto flammable = other_entity->get_component<Flammable>();
            
            if(flammable)
            {
                flammable->ignite();
            }
        };
    });
}
