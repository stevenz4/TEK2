/*
** EPITECH PROJECT, 2021
** Toy
** File description:
** Exercise 00
*/

#include "Toy.hpp"

Toy::Toy(ToyType type, std::string const &name, std::string const &filename)
{
    this->_type = type;
    this->_name = name;
    this->setAscii(filename);
}

Toy::Toy()
{
    this->_type = BASIC_TOY;
    this->_name = "toy";
    this->_picture.data.clear();
}

Toy::~Toy()
{
}

int Toy::getType() const
{
    return this->_type;
}

std::string Toy::getName() const
{
    return this->_name;
}

std::string Toy::getAscii() const
{
    return this->_picture.data;
}

bool Toy::setAscii(std::string const &filename)
{
    if (this->_picture.getPictureFromFile(filename))
        return true;
    return false;
}

void Toy::setName(std::string const &name)
{
    this->_name = name;
}