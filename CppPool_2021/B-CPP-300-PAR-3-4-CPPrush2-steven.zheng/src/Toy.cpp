/*
** EPITECH PROJECT, 2021
** Little Pony and Teddy
** File description:
** Rush2
*/

#include "../include/Toy.hpp"

Toy::Toy(std::string title) : Object(title)
{
    this->_title = title;
    type = "Toy";
}

Toy::~Toy() {}

Teddy::Teddy(std::string title) : Toy(title)
{

}

Teddy::~Teddy() {}

Pony::Pony(std::string title) : Toy(title)
{

}

Pony::~Pony() {}

void Teddy::isTaken()
{
    std::cout << "gra hu" << std::endl;
    this->_isTaken = true;
}

void Pony::isTaken()
{
    std::cout << "yo man" << std::endl;
    this->_isTaken = true;
}