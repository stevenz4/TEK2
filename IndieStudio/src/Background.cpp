/*
** EPITECH PROJECT, 2021
** Indie Studio
** File description:
** Background
*/

#include "Background.hpp"

Background::Background(const std::string &path, const int &imageWidth, const int &imageHeight)
{
    _background = LoadTexture(path.c_str());
    _imageHeight = imageHeight;
    _imageWidth = imageWidth;
}

Background::~Background()
{
    UnloadTexture(_background);
}

void Background::DrawBackground()
{
    DrawTexturePro(_background, Rectangle{0.0f, 0.0f, (float)_imageWidth, (float)_imageHeight},
    Rectangle{0, 0, (float)GetScreenWidth(), (float)GetScreenHeight()}, {0,0} ,0, WHITE);
}