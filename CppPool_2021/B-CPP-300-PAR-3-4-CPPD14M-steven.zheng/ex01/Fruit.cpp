/*
** EPITECH PROJECT, 2021
** Fruit
** File description:
** Exercise 00
*/

#include "Fruit.hpp"

Fruit::Fruit() : _name(""), _vitamins(0)
{
}


Fruit::Fruit(std::string const &name, int vitamins) : _name(name), _vitamins(vitamins)
{
}


Fruit::~Fruit()
{
}

std::string Fruit::getName() const
{
    return this->_name;
}

int Fruit::getVitamins() const
{
    return this->_vitamins;
}