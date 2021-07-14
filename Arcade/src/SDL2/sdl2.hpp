/*
** EPITECH PROJECT, 2021
** sdl2 lib
** File description:
** Arcade
*/

#ifndef SDL2_HPP_
#define SDL2_HPP_

#include "../IGraphics.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
 
class SDL2 : IGraphics{
    public:
        SDL2();
        ~SDL2();
        int createWin();
        int getInput();
        int createSound(const char *musicName);
        void drawImage(const std::string imageName, rect_t src, rect_t dst);
        void drawText(const std::string text, int ftsize, int x, int y);
        void renderClear();
        void renderPresent();
        int getMouseX();
        int getMouseY();
        int WIDTH;
        int HEIGHT;
    private:
    protected:
        int mouse_x = 0;
        int mouse_y = 0;
        SDL_Window *win;
        SDL_Renderer *rend;
        SDL_Event events;
        Uint8 *wavBuffer;
        SDL_AudioDeviceID deviceId;
};

#endif /* !SDL2_HPP_ */
