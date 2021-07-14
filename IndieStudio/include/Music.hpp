/*
** EPITECH PROJECT, 2021
** Indie Studio
** File description:
** Music
*/

#ifndef MUSIC_HPP_
#define MUSIC_HPP_

#include "raylib.h"
#include <string>
//#include "Exception.hpp"

class music {
    public:
        music(const std::string &musicName);
        ~music();
        void playMusic();
        void stopMusic();
        void pauseMusic();
        void resumeMusic();
        void UpdateMusic();
        void setVolume(char const &flag);
        float getVolume();
    protected:
    private:
        std::string _musicName;
        Music _music;
        float _volume;
};

#endif /* !MUSIC_HPP_ */
