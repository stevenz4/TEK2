/*
** EPITECH PROJECT, 2021
** Existentialism
** File description:
** Exercise 02
*/

#include "Warrior.hpp"

Warrior::Warrior(const std::string &name, int level) : Character(name, level)
{
    this->_name = name;
    this->_level = level;
    this->_energy = 100;
    this->_pv = 100;
    this->_race = std::string("Dwarf");
    this->_strength = 12;
    this->_stamina = 12;
    this->_intelligence = 6;
    this->_spirit = 5;
    this->_agility = 7;
    this->Range = CLOSE;
    this->_weaponName = "hammer";
    std::cout << "I'm " << this->_name << " KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG" << std::endl;
}

Warrior::~Warrior()
{
}

int Warrior::CloseAttack()
{
    if (this->_energy >= 30) {
        if (this->Range == CLOSE) {
            this->_energy = this->_energy - 30;
            std::cout << this->_name << " strikes with his " << this->_weaponName << std::endl;
            return (20 + this->_strength);
        } else {
            this->_energy = this->_energy - 30;
            std::cout << this->_name << " strikes with his " << this->_weaponName << std::endl;
            return 0;
        }
    } else {
        std::cout << this->_name << " out of power" << std::endl;
        return 0;
    }
    return 0;
}

int Warrior::RangeAttack()
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