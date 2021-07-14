/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Wrap
*/

#include "Wrap.hpp"

Wrap::Wrap(std::string title) : Object(title)
{
    obj = NULL;
    isOpen = true;
}

Wrap::~Wrap()
{ 
}

Object *MyUnitTests(Object **obj)
{
    Object *pack;
    obj[1]->wrapMeThat(obj[0]);
    obj[2]->wrapMeThat(obj[1]);
    pack = obj[2];
    return (pack);
}