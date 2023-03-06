#include "FrameSequenceAnimation.h"

#include <SFML/Graphics/Texture.hpp>

#include "MyRender.h"
#include "../Entities/Entity.h"

void FrameSequenceAnimation::update(float delta_time)
{
    elapsed_time_ += delta_time;

    if(elapsed_time_ > time_until_next_frame_)
    {
        elapsed_time_ -= time_until_next_frame_;

        current_frame_ ++;

        if(current_frame_ > frame_count - 1)
        {
            current_frame_ = 0;
        }

        sprite_->setTextureRect(frames_[current_frame_]);
    }
}

void FrameSequenceAnimation::on_awake()
{
    initialize();
}

void FrameSequenceAnimation::initialize()
{
    sprite_ = dynamic_cast<sf::Sprite*>(entity->get_component<MyRender>()->drawable.get());
    
    time_until_next_frame_ = 1.f / fps;
    current_frame_ = 0;

    auto texture_size = sprite_->getTexture()->getSize();

    const auto frame_width = texture_size.x / frame_count;

    for(int index = 0; index < frame_count; index ++)
    {
        frames_.push_back(sf::IntRect(index * frame_width, 0, frame_width, texture_size.y));
    }

    sprite_->setTextureRect(frames_[current_frame_]);
}
