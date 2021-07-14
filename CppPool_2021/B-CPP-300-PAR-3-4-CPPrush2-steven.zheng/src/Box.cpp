/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Box
*/

#include "../include/Box.hpp"

Box::Box(std::string title) : Wrap(title)
{
    type = "Box";
}

Box::~Box()
{
}

bool Box::wrapMeThat(Object *obj)
{
    if (this->getIsOpen() == false) {
        return (false);
    }
    else if (getObj() == NULL && obj != NULL && !(obj->getType().compare("Toy"))) {
        setToy(obj);
        CloseMe();
        std::cout << "tuuuut tuuut tuut" << std::endl;
        return (true);
    }
    else
        return (false);
}
