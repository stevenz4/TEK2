/*
** EPITECH PROJECT, 2021
** Indie Studio
** File description:
** Music
*/

#include "Music.hpp"

music::music(const std::string &musicName)
{
    /*std::ifstream try_musicName(musicName);
    if (!try_musicName)
        throw fdne_ex;
    try_musicName.close();*/
    _musicName = musicName;
    _music = LoadMusicStream(musicName.c_str());
    _music.looping = true;
    _volume = 0.500;
    SetMusicVolume(_music, _volume);
}

music::~music()
{
    UnloadMusicStream(_music);
}

void music::playMusic()
{
    PlayMusicStream(_music);
}

void music::stopMusic()
{
    StopMusicStream(_music);
}

void music::pauseMusic()
{
    PauseMusicStream(_music);
}

void music::resumeMusic()
{
    ResumeMusicStream(_music);
}

void music::UpdateMusic()
{
    UpdateMusicStream(_music);
}

void music::setVolume(char const &flag) // + or -
{
    //if (flag != '+' && flag != '-')
    //    throw sv_ex;
    if (flag == '+') {
        if (_volume < 1.0) {
            _volume += 0.1;
            SetMusicVolume(_music, _volume);
        }
    } if (flag == '-') {
        if (_volume >= 0.1) {
            _volume -= 0.1;
            SetMusicVolume(_music, _volume);
        }
    }
}

float music::getVolume()
{
    return _volume;
}