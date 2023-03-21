#include "SoundManager.h"

#include <iostream>

const static std::string sfx_location = "Assets/sfx/";

std::map<std::string, sf::Sound*> SoundManager::sounds_;
sf::SoundBuffer SoundManager::sound_buffer_;

bool SoundManager::define_sound(std::string file_path, std::string sound_name, bool is_looping)
{
    if(!sound_buffer_.loadFromFile(sfx_location + file_path))
    {
        std::cout << "Could not load " + file_path;
        return false;
    }

    auto* sound = new sf::Sound;

    sound->setLoop(is_looping);
    
    sounds_[sound_name] = sound;
    return true;
}

void SoundManager::play_sound(std::string sound_name)
{
    auto sound = sounds_[sound_name];
    sound->setBuffer(sound_buffer_);
    sound->setVolume(5.f);
    sound->play();
}
