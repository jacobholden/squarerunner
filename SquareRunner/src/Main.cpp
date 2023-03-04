#include "Game.h"
#include "Managers/TextureManager.h"

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
}