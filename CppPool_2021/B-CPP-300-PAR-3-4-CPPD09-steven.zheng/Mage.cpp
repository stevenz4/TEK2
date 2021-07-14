/*
** EPITECH PROJECT, 2021
** Children
** File description:
** Exercie 03
*/

#include "Mage.hpp"

Mage::Mage(const std::string &name, int level) : Character(name, level)
{
    this->_name = name;
    this->_level = level;
    this->_energy = 100;
    this->_pv = 100;
    this->_race = std::string("Gnome");
    this->_strength = 6;
    this->_stamina = 6;
    this->_intelligence = 12;
    this->_spirit = 11;
    this->_agility = 7;
    this->Range = CLOSE;
    std::cout << this->_name << " teleported" << std::endl;
}

Mage::~Mage()
{
}

int Mage::CloseAttack()
{
    if (this->_energy >= 10) {
        if (this->Range == CLOSE) {
            this->_energy = this->_energy - 10;
            this->Range = RANGE;
            std::cout << this->_name << " blinks" << std::endl;
        } else {
            this->_energy = this->_energy - 10;
            std::cout << this->_name << " blinks" << std::endl;
        }
    } else {
        std::cout << this->_name << " out of power" << std::endl;
        return 0;
    }
    return 0;
}

int Mage::RangeAttack()
{
    if (this->_energy < 25) {
        std::cout << this->_name << " out of power" << std::endl;
        return 0;
    } else {
        this->_energy = this->_energy - 25;
        std::cout << this->_name << " launches a fire ball" << std::endl;
        this->Range = CLOSE;
        return (20 + this->_spirit);
    }
    return 0;
}

void Mage::RestorePower()
{
    int energy_required = 100 - this->_energy;

    if (energy_required < (50 + this->_intelligence)) {
        this->_energy = 100;
        std::cout << this->_name << " takes a mana potion" << std::endl;
    } else {
        this->_energy = this->_energy + (50 + this->_intelligence);
        std::cout << this->_name << " takes a mana potion" << std::endl;
    }
}