#include "InputManager.h"

InputManager::InputManager()
{
    key_map[sf::Keyboard::Left] = Keys::Left;
    key_map[sf::Keyboard::Right] = Keys::Right;
    key_map[sf::Keyboard::Up] = Keys::Up;
    key_map[sf::Keyboard::Down] = Keys::Down;
    key_map[sf::Keyboard::Space] = Keys::Bomb;
}

void InputManager::set_key_pressed(sf::Keyboard::Key key, bool is_pressed)
{
    const auto iterator = key_map.find(key);
    
    if (iterator == key_map.end())
    {
        // Key not found in the map, return early
        return;
    }
    
    keysPressed[(int)key_map[key]] = is_pressed;
}

bool InputManager::is_key_pressed(sf::Keyboard::Key key)
{
    const auto iterator = key_map.find(key);
    
    if (iterator == key_map.end())
    {
        // Key not found in the map, return early
        return false;
    }
    
    return keysPressed[(int)key_map[key]];
}
