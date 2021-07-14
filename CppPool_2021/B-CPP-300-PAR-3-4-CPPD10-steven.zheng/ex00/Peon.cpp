/*
** EPITECH PROJECT, 2021
** Ponymorphism 
** File description:
** Exercise 00
*/

#include "Peon.hpp"

Peon::Peon(std::string name) : Victim(name)
{
    this->_name = name;
    std::cout << "Zog zog." << std::endl;
}

Peon::~Peon()
{
    std::cout << "Bleuark..." << std::endl;
}

void Peon::getPolymorphed() const
{
    std::cout << this->_name << " has been turned into a pink pony!" << std::endl;
}
