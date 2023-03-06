#include "EnemyBlueprint.h"

#include "../../Components/FrameSequenceAnimation.h"
#include "../../Components/MyRender.h"
#include "../../Components/MyTransform.h"
#include "../../Managers/TextureManager.h"

EnemyBlueprint::EnemyBlueprint(sf::Vector2f position)
{
    position_ = position;
}

void EnemyBlueprint::build_blueprint()
{
    add_component<MyTransform>([this](MyTransform& component)
    {
        component.position = position_;
    });
    add_component<MyRender>([this](MyRender& component)
    {
        component.drawable = std::make_unique<sf::Sprite>(*TextureManager::get_texture("enemy_left"));
    });
    add_component<FrameSequenceAnimation>([this](FrameSequenceAnimation& component)
    {
        component.fps = 4;
        component.frame_count = 4;
    });
}
