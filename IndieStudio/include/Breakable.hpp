/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Breakable
*/

#ifndef BREAKABLE_HPP_
#define BREAKABLE_HPP_

#include "GameObject.hpp"

class Breakable : public GameObject {
    public:
        Breakable(const std::string &name, Vector3 &position, const std::string &modelpath, const std::string &texturepath, const std::string &animpath = "") 
        : GameObject(name, position, modelpath, texturepath, animpath) {};
        void Break() {};

    protected:
        ModelAnimation *_BreakAnim;
};

#endif /* !BREAKABLE_HPP_ */
