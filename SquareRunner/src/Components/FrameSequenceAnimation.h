#pragma once

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
    void on_awake() override;
    void initialize();

private:
    float elapsed_time_ = 0;
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
