#pragma once

#include <functional>
#include <memory>
#include <vector>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "IUpdateable.h"

class FrameSequenceAnimation : public IUpdateable
{
public:
    void update(float delta_time) override;
    float fps;
    int frame_count;
    bool looping;
    void on_awake() override;
    void initialize();
    ~FrameSequenceAnimation() override;
    std::function<void()> on_complete_function = {};
    
    void invoke_func()
    {
        if(on_complete_function != nullptr)
        {
            on_complete_function();
        }
    }

private:
    float elapsed_time_ = 0;
    bool is_playing;
    std::vector<sf::IntRect> frames_ =
        {
        sf::IntRect(0, 0, 32, 32),
        sf::IntRect(32, 0, 32, 32),
        sf::IntRect(64, 0, 32, 32),
        sf::IntRect(96, 0, 32, 32),
        };
    int current_frame_;
    float time_until_next_frame_;
    sf::Sprite* sprite_;
};
