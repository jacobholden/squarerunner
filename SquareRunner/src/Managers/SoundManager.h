#pragma once
#include <map>
#include <string>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

const static std::string sfx_location = "Assets/sfx/";

class SoundManager final
{
public:
    static bool define_sound(std::string file_path, std::string sound_name, bool is_looping = false);
    static void play_sound(std::string sound_name);

private:
    SoundManager() = delete;
    ~SoundManager() = delete;

    static std::map<std::string, sf::Sound*> sounds_;
    static std::map<std::string, sf::SoundBuffer*> sound_buffers_;
};