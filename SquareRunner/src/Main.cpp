#include <iostream>

#include "Game.h"
#include "Managers/SoundManager.h"
#include "Managers/AssetManager.h"

int main()
{
    // Define textures
    AssetManager::define_texture("common/floor.png", "floor", true);
    AssetManager::define_texture("common/wall.png", "wall");
    AssetManager::define_texture("common/broken_wall.png", "broken_wall");
    AssetManager::define_texture("common/dirt.png", "dirt");
    AssetManager::define_texture("common/gold.png", "gold");
    AssetManager::define_texture("bomb/static/bomb.png", "bomb");
    AssetManager::define_texture("common/safe_zone.png", "safe_zone");
    AssetManager::define_texture("common/tnt.png", "tnt");
    AssetManager::define_texture("player/player_left.png", "player_left");
    AssetManager::define_texture("player/player_right.png", "player_right");
    AssetManager::define_texture("player/player_up.png", "player_up");
    AssetManager::define_texture("player/player_down.png", "player_down");
    AssetManager::define_texture("player/player_escape.png", "player_escape");
    AssetManager::define_texture("enemy/enemy_left.png", "enemy_left");
    AssetManager::define_texture("enemy/enemy_right.png", "enemy_right");
    AssetManager::define_texture("enemy/enemy_up.png", "enemy_up");
    AssetManager::define_texture("enemy/enemy_down.png", "enemy_down");
    AssetManager::define_texture("arrows/arrow_left.png", "arrow_left");
    AssetManager::define_texture("arrows/arrow_right.png", "arrow_right");
    AssetManager::define_texture("arrows/arrow_up.png", "arrow_up");
    AssetManager::define_texture("arrows/arrow_down.png", "arrow_down");
    AssetManager::define_texture("arrows/spinner.png", "spinner");
    AssetManager::define_texture("explosion/explosion.png", "explosion");
    AssetManager::define_texture("bomb/fuse/bomb_fuse.png", "bomb_ignited");
    AssetManager::define_texture("exit/exit.png", "exit");
    
    AssetManager::define_font("georgia.ttf", "georgia");

    SoundManager::define_sound("explosion.wav", "explosion");
    SoundManager::define_sound("bomb_pickup.wav", "bomb_pickup");
    SoundManager::define_sound("gold_pickup.wav", "gold_pickup");
    SoundManager::define_sound("ignite.wav", "ignite");
    SoundManager::define_sound("dirt.wav", "dirt");
    SoundManager::define_sound("exit.wav", "exit");
    
    Game game;

    // Run the game
    game.run();

    return 0;
}