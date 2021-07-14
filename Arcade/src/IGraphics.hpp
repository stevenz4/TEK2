/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** IGraphics
*/

#ifndef IGRAPHICS_HPP_
#define IGRAPHICS_HPP_

#include <iostream>

typedef struct rect_st{
    int x;
    int y;
    int h;
    int w;
} rect_t;

class IGraphics {
    public:
        virtual ~IGraphics() = default;
        virtual int createWin() = 0;
        virtual int getInput() = 0;
        virtual int createSound(const char *musicName) = 0;
        virtual void drawImage(const std::string imageName, rect_t src, rect_t dst) = 0;
        virtual void drawText(const std::string text, int ftsize, int x, int y) = 0;
        virtual void renderClear() = 0;
        virtual void renderPresent() = 0;
        virtual int getMouseX() = 0;
        virtual int getMouseY() = 0;
        int WIDTH = 1280;
        int HEIGHT = 720;
    protected:
    private:
};

#endif /* !IGRAPHICS_HPP_ */
