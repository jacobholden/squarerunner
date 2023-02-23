#pragma once
#include <map>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "../Entity.h"
#include "../../Managers/TextureManager.h"

class Player : public Entity, public Updateable
{
public:
    Player(); // Constructor
    Player(sf::Vector2f pos); // Constructor
    ~Player() override; // Destructor
    Player(const Player& other) : Entity(other) {};
    Player(Player&& other) noexcept : Entity(std::move(other)) {}
	
    void update(float elapsedTime) override;

    void set_position(sf::Vector2f pos) override;

    std::unique_ptr<sf::Sprite> sprite;

protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
    std::map<int, sf::Texture> textures_ =
        {
        {0, *TextureManager::get_texture("player_left")},
        {1, *TextureManager::get_texture("player_right")},
        {2, *TextureManager::get_texture("player_up")},
        {3, *TextureManager::get_texture("player_down")},
        };

    sf::Vector2f start_position_;
    sf::Vector2f end_position_;
    float time_traveled_;
    bool is_moving_ = false;

    const float duration_ = 0.25f;

    void set_target_position(sf::Vector2f target_position, int look_direction);
};
