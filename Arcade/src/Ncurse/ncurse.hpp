/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** ncurse
*/

#ifndef NCURSE_HPP_
#define NCURSE_HPP_
#include <ncurses.h>
#include <iostream>
#include "../IGraphics.hpp"

class Ncurse : IGraphics{
    public:
        Ncurse();
        ~Ncurse();
        int createWin();
        int getInput();
        int createSound(const char *musicName) {return (0);};
        void drawImage(const std::string imageName, rect_t src, rect_t dst);
        void drawText(const std::string text, int ftsize, int x, int y);
        void renderClear() {};
        void renderPresent() {};
        int getMouseX() {return 0;};
        int getMouseY() {return 0;};
        bool isOpen;
        WINDOW *win;
        int WIDTH = 1280;
        int HEIGHT = 720;
    private:
    protected:
};

#endif /* !NCURSE_HPP_ */
