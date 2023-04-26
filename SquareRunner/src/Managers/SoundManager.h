#pragma once
#include <map>
#include <string>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

#include "SoundManager.h"

class SoundManager final
{
public:
    bool static define_sound(std::string file_path, std::string sound_name, bool is_looping = false);
    void static play_sound(std::string sound_name);

private:
    SoundManager();
    ~SoundManager();
    std::map<std::string, sf::Sound*> static sounds_;
    sf::SoundBuffer static sound_buffer_;
};
