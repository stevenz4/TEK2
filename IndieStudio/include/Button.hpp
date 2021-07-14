/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Button
*/

#ifndef BUTTON_HPP_
#define BUTTON_HPP_

#include "raylib.h"
#include <string>

typedef enum GameScreen {LOGO = 0, MENU, OPTIONS, GAME, MAP, END} GameScreen;

class Button{
    public:
        Button(float x, float y, float height, float width, std::string text, GameScreen screen);
        void disp();
        bool checkMouseCollision();
        GameScreen getScreen() {return _screen;}
        std::string getText(){ return _text;}

    private:
        Rectangle _rect;
        bool _collisionState;
        std::string _text;
        GameScreen _screen;
};

#endif /* !BUTTON_HPP_ */
