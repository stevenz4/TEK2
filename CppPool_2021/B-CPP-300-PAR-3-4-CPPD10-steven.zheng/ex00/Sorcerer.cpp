/*
** EPITECH PROJECT, 2021
** Ponymorphism
** File description:
** Exercise 00
*/

#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"

Sorcerer::Sorcerer(std::string name, std::string title)
{
    this->_name = name;
    this->_title = title;
    std::cout << this->_name << ", " << this->_title << ", is born!" << std::endl;
}

Sorcerer::~Sorcerer()
{
    std::cout << this->_name << ", " << this->_title << ", is dead. Consequences will never be the same!" << std::endl;
}

std::string Sorcerer::getName()
{
    return this->_name;
}

std::string Sorcerer::getTitle()
{
    return this->_title;
}

void Sorcerer::polymorph(const Victim &victim)
{
    victim.getPolymorphed();
}

std::ostream &operator<<(std::ostream &flux, Sorcerer &sorcerer)
{
    return (flux << "I am " << sorcerer.getName() << ", " << sorcerer.getTitle() << ", and I like ponies!" << std::endl);
}