#include "SoundManager.h"

#include <iostream>

std::map<std::string, sf::Sound*> SoundManager::sounds_;
std::map<std::string, sf::SoundBuffer*> SoundManager::sound_buffers_;

bool SoundManager::define_sound(std::string file_path, std::string sound_name, bool is_looping)
{
    auto sound_buffer = new sf::SoundBuffer();
    if (!sound_buffer->loadFromFile(sfx_location + file_path))
    {
        std::cout << "Could not load " + file_path;
        return false;
    }

    auto sound = new sf::Sound();
    sound->setBuffer(*sound_buffer);
    sound->setLoop(is_looping);

    sounds_[sound_name] = sound;
    sound_buffers_[sound_name] = sound_buffer;

    return true;
}

void SoundManager::play_sound(std::string sound_name)
{
    auto sound = sounds_[sound_name];
    sound->setVolume(100.f);
    sound->play();
}
