#include <iostream>

#include "Game.h"
#include "Managers/SoundManager.h"
#include "Managers/TextureManager.h"

int main()
{
    // Define textures
    TextureManager::define_texture("common/floor.png", "floor", true);
    TextureManager::define_texture("common/wall.png", "wall");
    TextureManager::define_texture("common/broken_wall.png", "broken_wall");
    TextureManager::define_texture("common/dirt.png", "dirt");
    TextureManager::define_texture("common/gold.png", "gold");
    TextureManager::define_texture("bomb/static/bomb.png", "bomb");
    TextureManager::define_texture("common/safe_zone.png", "safe_zone");
    TextureManager::define_texture("common/tnt.png", "tnt");
    TextureManager::define_texture("player/player_left.png", "player_left");
    TextureManager::define_texture("player/player_right.png", "player_right");
    TextureManager::define_texture("player/player_up.png", "player_up");
    TextureManager::define_texture("player/player_down.png", "player_down");
    TextureManager::define_texture("player/player_escape.png", "player_escape");
    TextureManager::define_texture("enemy/enemy_left.png", "enemy_left");
    TextureManager::define_texture("enemy/enemy_right.png", "enemy_right");
    TextureManager::define_texture("enemy/enemy_up.png", "enemy_up");
    TextureManager::define_texture("enemy/enemy_down.png", "enemy_down");
    TextureManager::define_texture("arrows/arrow_left.png", "arrow_left");
    TextureManager::define_texture("arrows/arrow_right.png", "arrow_right");
    TextureManager::define_texture("arrows/arrow_up.png", "arrow_up");
    TextureManager::define_texture("arrows/arrow_down.png", "arrow_down");
    TextureManager::define_texture("arrows/spinner.png", "spinner");
    TextureManager::define_texture("explosion/explosion.png", "explosion");
    TextureManager::define_texture("bomb/fuse/bomb_fuse.png", "bomb_ignited");
    TextureManager::define_texture("exit/exit.png", "exit");

    SoundManager::define_sound("explosion.wav", "explosion");
    
    Game game;

    // Run the game
    game.run();

    return 0;
}