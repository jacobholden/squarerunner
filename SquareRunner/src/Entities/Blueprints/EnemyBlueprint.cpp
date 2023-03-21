#include "EnemyBlueprint.h"

#include "../../Components/FrameSequenceAnimation.h"
#include "../../Components/MyRender.h"
#include "../../Components/MyTransform.h"
#include "../../Managers/TextureManager.h"
#include "../../Components/Animator.h"
#include "../../Components/Enemy/EnemyController.h"
#include "../../Components/CircleCollidier.h"
#include "../../Game.h"
#include "ExplosionBlueprint.h"
#include "../../Components/Flammable.h"

EnemyBlueprint::EnemyBlueprint(sf::Vector2f position)
{
    position_ = position;
}

void EnemyBlueprint::build_blueprint()
{
    set_name("enemy");
    add_component<MyTransform>([this](MyTransform& component)
    {
        component.position = position_;
    });
    add_component<MyRender>([this](MyRender& component)
    {
        component.drawable = std::make_unique<sf::Sprite>(*TextureManager::get_texture("enemy_left"));
        component.z_order = 1;
    });
    add_component<FrameSequenceAnimation>([this](FrameSequenceAnimation& component)
    {
        component.fps = 12;
        component.frame_count = 4;
        component.looping = true;
    });
    add_component<Animator>();
    add_component<EnemyController>();
    add_component<Flammable>();
    add_component<CircleCollidier>([this](CircleCollidier& component)
    {
        component.radius = 12;
    });
}
