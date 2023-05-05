#include "PlayerBlueprint.h"

#include "ExplosionBlueprint.h"
#include "PlayerEscapeBlueprint.h"
#include "../../Components/Animator.h"
#include "../../Components/CircleCollidier.h"
#include "../../Components/MyRender.h"
#include "../../Components/MyTransform.h"
#include "../../Components/Player/PlayerController.h"
#include "../../Managers/AssetManager.h"
#include "../../Game.h"
#include "../../Components/Destructible.h"
#include "../../Managers/SoundManager.h"

PlayerBlueprint::PlayerBlueprint(sf::Vector2f position)
{
    position_ = position;
}

void PlayerBlueprint::build_blueprint()
{
    set_name("player");
    add_component<MyTransform>([this](MyTransform& component)
    {
        component.position = position_;
    });
    add_component<MyRender>([this](MyRender& component)
    {
        component.drawable = std::make_unique<sf::Sprite>(*AssetManager::get_texture("player_up"));
        component.z_order = 1;
    });
    add_component<Animator>();
    add_component<PlayerController>();
    add_component<Destructible>();
    add_component<CircleCollidier>([this](CircleCollidier& component)
    {
        component.radius = 12;
        component.func = [this](Entity* other_entity)
        {
            if(other_entity->name == "enemy")
            {
                entity->destroy();
                other_entity->destroy();

                auto player_position = entity->get_component<MyTransform>()->position;
                auto enemy_position = other_entity->get_component<MyTransform>()->position;
                auto top_left_explosion_position = sf::Vector2f((player_position.x + enemy_position.x) / 2 - 32, (player_position.y + enemy_position.y) / 2 - 32);

                for(int i = 0; i < 3; i ++)
                {
                    for(int j = 0; j < 3; j ++)
                    {
                        Game::get_current_scene()->create_entity(new ExplosionBlueprint(sf::Vector2f(top_left_explosion_position.x + i * 32, top_left_explosion_position.y + j * 32)));
                    }
                }

                SoundManager::play_sound("explosion");

                Game::get_current_scene()->restart_scene();
            }

            if(other_entity->name == "gold")
            {
                other_entity->destroy();
                entity->get_component<PlayerController>()->add_gold_count();

                SoundManager::play_sound("gold_pickup");
            }

            if(other_entity->name == "bomb")
            {
                entity->get_component<PlayerController>()->add_bomb_count();
                
                other_entity->destroy();

                SoundManager::play_sound("bomb_pickup");
            }

            if(other_entity->name == "dirt")
            {
                other_entity->destroy();

                SoundManager::play_sound("dirt");
            }

            if(other_entity->name == "exit")
            {
                if(entity->get_component<PlayerController>()->is_gold_target_reached())
                {
                    Game::get_current_scene()->create_entity(new PlayerEscapeBlueprint(other_entity->get_component<MyTransform>()->position));
                    entity->destroy();

                    SoundManager::play_sound("exit");
                }
            }
        };
    });
}