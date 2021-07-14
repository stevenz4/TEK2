/*
** EPITECH PROJECT, 2021
** Ponymorphism
** File description:
** Exercise 00
*/

#include "Victim.hpp"

Victim::Victim(std::string name)
{
    this->_name = name;
    std::cout << "Some random victim called " << this->getName() << " just popped!" << std::endl;
}

Victim::~Victim()
{
    std::cout << "Victim " << this->_name << " just died for no apparent reason!" << std::endl;
}

std::string Victim::getName()
{
    return this->_name;
}

void Victim::getPolymorphed() const
{
    std::cout << this->_name << " has been turned into a cute little sheep!" << std::endl;
}

std::ostream &operator<<(std::ostream &flux, Victim &victim)
{
    return (flux << "I'm " << victim.getName() << " and I like otters!" << std::endl);
}
