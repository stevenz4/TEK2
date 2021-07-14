/*
** EPITECH PROJECT, 2021
** Or is it eleven
** File description:
** Exercise 05
*/

#include "Hunter.hpp"

Hunter::Hunter(const std::string &name, int level) : Character(name, level), Warrior(name, level)
{
    this->_name = name;
    this->_level = level;
    this->_energy = 100;
    this->_pv = 100;
    this->_race = std::string("Elf");
    this->_strength = 9;
    this->_stamina = 9;
    this->_intelligence = 5;
    this->_spirit = 6;
    this->_agility = 25;
    this->Range = CLOSE;
    this->_weaponName = "sword";
    std::cout << this->_name << " is born from a tree" << std::endl;
}

Hunter::~Hunter()
{
}

int Hunter::RangeAttack()
{
    if (this->_energy >= 25) {
        this->_energy = this->_energy - 25;
        std::cout << this->_name << " uses his bow" << std::endl;
        return (20 + this->_agility);
    } else {
        std::cout << this->_name << " out of power" << std::endl;
        return 0;
    }
    return 0;
}

void Hunter::RestorePower()
{
    this->_energy = 100;

    std::cout << this->_name << " meditates" << std::endl;
}