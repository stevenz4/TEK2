/*
** EPITECH PROJECT, 2021
** Little Pony and Teddy
** File description:
** Rush2
*/

#include "../include/Object.hpp"
#include "../include/Toy.hpp"

Object::Object(std::string title)
{
    this->_title = title;
}

Object::~Object()
{
}

std::string Object::getTitle()
{
    return this->_title;
}

bool Object::getIsTaken()
{
    return this->_isTaken;
}

Object **MyUnitTests()
{
    Object **array = new Object*[2];

    array[0] = new Teddy("cuddle");
    array[1] = new Pony("happy pony");
    return array;
}

std::ostream &operator<<(std::ostream &flux, Object &object)
{
    return (flux << "Title : " << object.getTitle() << "  /  " << "isTaken : " << std::boolalpha << object.getIsTaken());
}