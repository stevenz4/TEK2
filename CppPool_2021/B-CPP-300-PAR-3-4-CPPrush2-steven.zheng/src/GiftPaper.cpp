/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** GiftPaper
*/

#include "../include/GiftPaper.hpp"

GiftPaper::GiftPaper(std::string title) : Wrap(title)
{
    type = "GiftPaper";
}

GiftPaper::~GiftPaper()
{
}

bool GiftPaper::wrapMeThat(Object *obj)
{
    if (obj != NULL && !(obj->getType().compare("Box"))) {
        setBox(obj);
        CloseMe();
        std::cout << "tuuuut tuuut tuut" << std::endl;
        return (true);
    }
    else
        return (false);
}
