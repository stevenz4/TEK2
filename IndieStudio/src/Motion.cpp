/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Motion
*/

#include "Motion.hpp"

void Motion::move(Dir dir, float moveSpeed)
{
    switch (dir)
    {
    case UP:
        setPosition({getPosition().x, getPosition().y, getPosition().z - moveSpeed});
        setAngle(180);
        setTilt({0.0f, 1.0f, 1.0f});
        break;
    case DOWN:
        setPosition({getPosition().x, getPosition().y, getPosition().z + moveSpeed});
        setAngle(-90.0f);
        setTilt({1.0f, 0.0f, 0.0f});
        break;
    case LEFT:
        setPosition({getPosition().x - moveSpeed, getPosition().y, getPosition().z});
        setAngle(-120);
        setTilt({1.0f, 1.0f, 1.0f});
        break;
    case RIGHT:
        setPosition({getPosition().x + moveSpeed, getPosition().y, getPosition().z});
        setAngle(120.0f);
        setTilt({-1.0f, 1.0f, 1.0f});
        break;
    }
}