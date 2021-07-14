/*
** EPITECH PROJECT, 2021
** Paladin
** File description:
** Exercise 04
*/

#include "Paladin.hpp"

Paladin::Paladin(const std::string &name, int level) : Character(name, level), Warrior(name, level), Priest(name, level)
{
    this->_name = name;
    this->_level = level;
    this->_energy = 100;
    this->_pv = 100;
    this->_race = std::string("Human");
    this->_strength = 9;
    this->_stamina = 10;
    this->_intelligence = 10;
    this->_spirit = 10;
    this->_agility = 2;
    this->Range = CLOSE;
    std::cout << "the light falls on " << this->_name << std::endl;
}

Paladin::~Paladin()
{
}

int Paladin::Intercept()
{
    if (this->_energy >= 10) {
        if (this->Range == RANGE) {
            this->_energy = this->_energy - 10;
            std::cout << this->_name << " intercepts" << std::endl;
            this->Range = CLOSE;
        } else {
            this->_energy = this->_energy - 10;
            std::cout << this->_name << " intercepts" << std::endl;
        }
    } else {
        std::cout << this->_name << " out of power" << std::endl;
        return 0;
    }
    return 0;
}