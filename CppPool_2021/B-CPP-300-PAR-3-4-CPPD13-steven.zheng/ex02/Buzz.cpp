/*
** EPITECH PROJECT, 2021
** Buzz
** File description:
** Exercise 02
*/

#include "Buzz.hpp"

Buzz::Buzz(std::string const &name, std::string const &filename) : Toy(BUZZ, name, filename)
{
}

Buzz::Buzz(Buzz const &copy) : Toy(copy)
{
}

Buzz::~Buzz()
{
}
