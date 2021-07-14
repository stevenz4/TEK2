/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Motion
*/

#ifndef MOTION_HPP_
#define MOTION_HPP_

#include "GameObject.hpp"

typedef enum DIRECTION {UP, DOWN, LEFT, RIGHT, NONE} Dir;

class Motion : public GameObject {
    public:
        Motion(std::string const &name, Vector3 &position, std::string const &modelpath, std::string const &texturepath, std::string const &animpath = "") 
        : GameObject(name, position, modelpath, texturepath, animpath) {};
        void setPosition(const Vector3 &pos) { _position = pos; };
        void setTilt(const Vector3 &tilt) { _tilt = tilt; };
        void setAngle(const float &angle) { _angle = angle; };
        void move(Dir dir, float moveSpeed);
};

#endif /* !MOTION_HPP_ */
