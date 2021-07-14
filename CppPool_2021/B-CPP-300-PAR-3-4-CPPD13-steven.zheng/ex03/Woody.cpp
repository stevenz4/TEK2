/*
** EPITECH PROJECT, 2021
** Woody
** File description:
** Exercise 02
*/

#include "Woody.hpp"

Woody::Woody(std::string const &name, std::string const &filename) : Toy(WOODY, name, filename)
{
}

Woody::Woody(Woody const &copy) : Toy(copy)
{

}

Woody::~Woody()
{
}

void Woody::speak(std::string const &statement)
{
    std::cout << "WOODY: " << this->_name << " \"" << statement << "\"" << std::endl;
}