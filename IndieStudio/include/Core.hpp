/*
** EPITECH PROJECT, 2021
** Indie Studio
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include "Music.hpp"
#include "Background.hpp"
#include "Player.hpp"
#include "LoadMap.hpp"
#include "Button.hpp"
#include "Camera.hpp"

#include <iostream>
#include <vector>
#include <cstring>
#include <string>

typedef struct sound_st {
    Music music;
    float volume;
} sound_t;

class Core {
    public:
        Core();
        ~Core();
        void createWindow();
        int gameLoop();
        void getWindowSize();
        void displayLogo();
        void displayCore();
        void displayOptions();
        void getMapObj(Map *createmap);
        void displayPlayer();
        void inputCore();
        void setButton();
        float createTimer(float &timer);
        void bombAnimation(float &timer);
        void displayMap(Map *createmap);
        void displayStat();
    private:
        bool _mapCreated;
        int _WIDTH;
        int _HEIGHT;
        bool _isOpen;
        int _fps;
        int _ia = 2;

        Texture2D _logo;
        Texture2D _bombMenu;
        music *_titleMusic;
        music *_ingameMusic;
        Background *_background;
        Background *_endScreen;
        Vector2 _mousePos;
        GameScreen _currentScreen;
        std::vector<GameObject *> _mapObject;
        std::vector<Button *> _button;
        Map *_map;
        Camera_class *_camera;
        std::vector<Player *>_Player;
        Font _font;
};

int imgtest(void); 

#endif /* !Core_HPP_ */
