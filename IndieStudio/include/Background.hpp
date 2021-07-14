/*
** EPITECH PROJECT, 2021
** Indie Studio
** File description:
** Background
*/

#ifndef BACKGROUND_HPP_
#define BACKGROUND_HPP_

#include "raylib.h"
#include <string>

class Background {
    public:
        Background(const std::string &path, const int &imageWidth, const int &imageHeight);
        ~Background();
        void DrawBackground();

    protected:
    private:
        Texture2D _background;
        int _imageHeight;
        int _imageWidth;
};

#endif /* !BACKGROUND_HPP_ */
