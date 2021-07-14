/*
** EPITECH PROJECT, 2021
** Indie Studio
** File description:
** create_Image
*/

#ifndef CREATE_IMAGE_HPP_
#define CREATE_IMAGE_HPP_

#include "raylib.h"
#include <string>

class create_Image {
    public:
        create_Image(const std::string &path, const float &_imageWidth, const float &_imageHeight, const int &_DisplayIf); //DisplayIf pour savoir si on display dans le menu ou le jeu
        ~create_Image();
        void Draw_Image();

    protected:
    private:
        int _DisplayIf;
        Texture2D _Image;
        int _imageHeight;
        int _imageWidth;
};

#endif /* !create_Image_HPP_ */