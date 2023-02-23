#pragma once
#include <map>
#include <SFML/Window/Keyboard.hpp>

class InputManager
{
private:
    InputManager();
    InputManager(const InputManager&) = delete;
    InputManager& operator=(const InputManager&) = delete;
    
    enum class Keys {
        Left,
        Right,
        Up,
        Down,
        Bomb,
        Count
      };

    std::map<sf::Keyboard::Key, Keys> key_map;
    
public:
    static InputManager& get_instance() {
        static InputManager instance;
        return instance;
    }

    bool keysPressed[static_cast<int>(Keys::Count)] = { false };
    
    void set_key_pressed(sf::Keyboard::Key key, bool is_pressed);
    bool is_key_pressed(sf::Keyboard::Key key);
};
