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
