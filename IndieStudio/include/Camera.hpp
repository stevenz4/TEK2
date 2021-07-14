/*
** EPITECH PROJECT, 2021
** Indie Studio
** File description:
** Camera
*/

#ifndef CAMERA_HPP_
#define CAMERA_HPP_

#include "raylib.h"
#include <string>
#include "LoadMap.hpp"

class Camera_class {
    public:
        Camera_class(const MapSize &size);
        ~Camera_class();
        Camera get_cam() {return _cam;};
    protected:
    private:
        Camera _cam;
};

#endif