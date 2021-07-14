/*
** EPITECH PROJECT, 2021
** Indie Studio
** File description:
** Image
*/

#include "Image.hpp"

create_Image::create_Image(const std::string &path, const float &imageWidth, const float &imageHeight, const int &DisplayIf)
{
    _Image = LoadTexture(path.c_str());
    _imageHeight = imageHeight;
    _imageWidth = imageWidth;
    _DisplayIf = DisplayIf;
}

create_Image::~create_Image()
{
    UnloadTexture(_Image);
}

void create_Image::Draw_Image()
{
    DrawTexture(_Image, _imageWidth, (float)_imageWidth, WHITE);
}