#include <SFML\Graphics.hpp>

#include "Game.h"
#include "Components/MyRender.h"
#include "Components/MyTransform.h"
#include "Entities/IEntityBlueprint.h"
#include "managers/InputManager.h"
#include "Managers/TextureManager.h"

const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 736;
const int TARGET_FPS = 60;
const sf::Time UPDATE_INTERVAL = sf::seconds(1.0f / TARGET_FPS);

int main()
{
    // Define textures
    TextureManager::define_texture("common/floor.png", "floor", true);
    TextureManager::define_texture("common/wall.png", "wall");
    TextureManager::define_texture("common/broken_wall.png", "broken_wall");
    TextureManager::define_texture("common/dirt.png", "dirt");
    TextureManager::define_texture("common/gold.png", "gold");
    TextureManager::define_texture("common/safe_zone.png", "safe_zone");
    TextureManager::define_texture("common/tnt.png", "tnt");
    TextureManager::define_texture("player/player_left.png", "player_left");
    TextureManager::define_texture("player/player_right.png", "player_right");
    TextureManager::define_texture("player/player_up.png", "player_up");
    TextureManager::define_texture("player/player_down.png", "player_down");
    
    Game game;

    // Run the game
    game.run();

    return 0;

    /*
    // Define textures
    TextureManager::define_texture("common/floor.png", "floor", true);
    TextureManager::define_texture("common/wall.png", "wall");
    TextureManager::define_texture("common/broken_wall.png", "broken_wall");
    TextureManager::define_texture("common/dirt.png", "dirt");
    TextureManager::define_texture("common/gold.png", "gold");
    TextureManager::define_texture("common/safe_zone.png", "safe_zone");
    TextureManager::define_texture("common/tnt.png", "tnt");
    TextureManager::define_texture("player/player_left.png", "player_left");
    TextureManager::define_texture("player/player_right.png", "player_right");
    TextureManager::define_texture("player/player_up.png", "player_up");
    TextureManager::define_texture("player/player_down.png", "player_down");
    
    sf::RenderWindow renderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "My Game", sf::Style::Default);
    sf::Event event{};

    // Set the vertical sync enabled
    renderWindow.setVerticalSyncEnabled(true);

    auto game = std::make_unique<GameScene>(WINDOW_WIDTH, WINDOW_HEIGHT);

    // Set the fixed update rate
    sf::Clock clock;
    const sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    // Game loop
    while (renderWindow.isOpen())
    {
        // Event polling
        while (renderWindow.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                renderWindow.close();
                break;
            case sf::Event::LostFocus:
                break;
            case sf::Event::GainedFocus:
                break;
            case sf::Event::KeyPressed:
                InputManager::get_instance().set_key_pressed(event.key.code, true);
                break;
            case sf::Event::KeyReleased:
                InputManager::get_instance().set_key_pressed(event.key.code, false);
                break;
            case sf::Event::MouseWheelMoved:
                break;
            case sf::Event::MouseWheelScrolled:
                break;
            case sf::Event::MouseButtonPressed:
                game->on_mouse_button(event.mouseButton);
                break;
            case sf::Event::MouseButtonReleased:
                break;
            case sf::Event::MouseMoved:
                game->on_mouse_move(event.mouseMove);
                break;
            case sf::Event::MouseEntered:
                break;
            case sf::Event::MouseLeft:
                break;
            }
        }

        // Add time since last update to the clock
        timeSinceLastUpdate += clock.restart();

        // Check if enough time has passed to update
        while (timeSinceLastUpdate >= timePerFrame)
        {
            game->update(timeSinceLastUpdate.asSeconds());
            
            timeSinceLastUpdate -= timePerFrame;
        }

        // Render
        renderWindow.clear(sf::Color::Black);

        renderWindow.draw(*game);
        
        renderWindow.display();
    }
    */
}