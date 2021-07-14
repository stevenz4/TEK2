/*
** EPITECH PROJECT, 2021
** Arcade
** File description:
** Arcade
*/

#include "Arcade.hpp"

Arcade::Arcade(IGraphics *lib_graphic)
{
    this->isOpen = true;
    this->myGraphic = lib_graphic;
}

Arcade::~Arcade()
{
}

int Arcade::menuSetup()
{
    this->myGraphic->createWin();
    this->myGraphic->createSound("assets/music.wav");
    return 0;
}

int Arcade::menuLoop()
{
    typedef Snake*(*Loader)(IGraphics *);
    Snake *lib_snake;
    Loader loader;
    LibLoader lib("lib/arcade_nibbler.so", "create_obj");

    *(void**) (&loader) = lib.get_ptr();
    while(this->isOpen) {
        this->myGraphic->renderClear();
        this->myGraphic->drawImage("assets/wallpaper.jpg", {0, 0, 1920, 1080}, {0, 0, this->myGraphic->WIDTH, this->myGraphic->HEIGHT});
        this->myGraphic->drawImage("assets/texture/snake_image.png", {0, 0, 600, 700}, {0, 150, 400, 500});
        this->myGraphic->drawText("[ARCADE Menu]", 40, 380, 10);
        switch (this->myGraphic->getInput())
        {
        case 'p':
            this->lib_snake = loader(this->myGraphic);
            this->isOpen = false;
            break;
        case 84:
            this->isOpen = false;
            break;
        case 1:
            if (((this->myGraphic->getMouseX() >= 80 && this->myGraphic->getMouseY() >= 170) &&
        (this->myGraphic->getMouseX() <= 350 && this->myGraphic->getMouseY() <= 580)) ||
        this->myGraphic->getInput() == 'p')
            this->lib_snake = loader(this->myGraphic);
            break;
        default:
            break;
        }
        this->myGraphic->renderPresent();
    }
    return 0;
}