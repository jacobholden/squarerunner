#include "AScene.h"

#include <SFML/Graphics/RenderTarget.hpp>

AScene::AScene(int width, int height)
{
    width_ = width;
    height_ = height;
}

AScene::~AScene()
{
}

void AScene::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (auto& entity : entities_)
    {
        target.draw(*entity);
    }
}
