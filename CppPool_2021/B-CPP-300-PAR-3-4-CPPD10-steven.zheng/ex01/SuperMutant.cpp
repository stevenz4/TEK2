/*
** EPITECH PROJECT, 2021
** SuperMutant
** File description:
** Exercise 01
*/

#include "SuperMutant.hpp"

SuperMutant::SuperMutant() : AEnemy(170, "Super Mutant")
{
    std::cout << "Gaaah. Me want smash heads!" << std::endl;
}

SuperMutant::~SuperMutant()
{
    std::cout << "Aaargh..." << std::endl;
}

void SuperMutant::takeDamage(int damage)
{
    damage = damage - 3;
    if (damage >= 0)
        this->_hp = this->_hp - damage;
}