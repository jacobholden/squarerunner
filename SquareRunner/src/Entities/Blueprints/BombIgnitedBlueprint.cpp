#include "BombIgnitedBlueprint.h"

#include "ExplosionBlueprint.h"
#include "../../Components/FrameSequenceAnimation.h"
#include "../../Components/MyRender.h"
#include "../../Components/MyTransform.h"
#include "../../Managers/TextureManager.h"
#include "../../Game.h"
#include "../../Managers/SoundManager.h"

BombIgnitedBlueprint::BombIgnitedBlueprint(sf::Vector2f position)
{
    position_ = position;
}

void BombIgnitedBlueprint::build_blueprint()
{
    set_name("bomb_ignited");
    add_component<MyTransform>([this](MyTransform& component)
    {
        component.position = position_;
    });
    add_component<MyRender>([this](MyRender& component)
    {
        component.drawable = std::make_unique<sf::Sprite>(*TextureManager::get_texture("bomb_ignited"));
    });
    add_component<FrameSequenceAnimation>([this](FrameSequenceAnimation& component)
    {
        component.fps = 12;
        component.frame_count = 12;
        component.on_complete_function = [this]
        {
            for(int i = 0; i < 3; i ++)
            {
                for(int j = 0; j < 3; j ++)
                {
                    auto position = entity->get_component<MyTransform>()->position;
                    
                    Game::get_current_scene()->create_entity(new ExplosionBlueprint(sf::Vector2f(position.x - 32 + i * 32, position.y - 32 + j * 32)));
                }
            }

            SoundManager::play_sound("explosion");
            
            entity->destroy();
        };
    });
}
