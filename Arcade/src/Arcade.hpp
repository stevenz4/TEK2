/*
** EPITECH PROJECT, 2021
** Arcade
** File description:
** Arcade
*/

#ifndef ARCADE_HPP_
#define ARCADE_HPP_

#include "IGraphics.hpp"
#include "snake/snake.hpp"
#include "LibLoader.hpp"
#include "Ncurse/ncurse.hpp"
#include "SDL2/sdl2.hpp"

class Arcade {
    public:
        Arcade(IGraphics *);
        ~Arcade();
        int menuSetup();
        int menuLoop();
    protected:
    private:
        bool isOpen;
        IGraphics *myGraphic;
        Snake *lib_snake;
};

#endif /* !ARCADE_HPP_ */
