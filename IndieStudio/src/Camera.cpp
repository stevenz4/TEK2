/*
** EPITECH PROJECT, 2021
** Indie Studio
** File description:
** Camera
*/

#include "Camera.hpp"

Camera_class::Camera_class(const MapSize &size)
{
    Vector3 small_pos = {18.0, 34.4, 20.0};
    Vector3 small_target = {18.0, 6.25, 14.0};
    Vector3 medium_pos = {30.0, 54.5, 35.5};
    Vector3 medium_target = {30.0, -5.0, 21.6};
    Vector3 large_pos = {44.0, 82.0, 55.0};
    Vector3 large_target = {44.0, -10.0, 34.0};

        switch (size) {
        case SMALL:
            _cam.position = small_pos;
            _cam.target = small_target;
            break;
        case MEDIUM:
            _cam.position = medium_pos;
            _cam.target = medium_target;
            break;
        case LARGE:
            _cam.position = large_pos;
            _cam.target = large_target;
            break;
    }
    _cam.up = {0.0, 1.0, 0.0};
    _cam.fovy = 45.0;
    _cam.projection = CAMERA_PERSPECTIVE;
    SetCameraMode(_cam, CAMERA_PERSPECTIVE);
}

Camera_class::~Camera_class()
{
    
}