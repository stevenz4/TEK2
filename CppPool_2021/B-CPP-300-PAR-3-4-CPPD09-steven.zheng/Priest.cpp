/*
** EPITECH PROJECT, 2021
** Children
** File description:
** Exercise 03
*/

#include "Priest.hpp"

Priest::Priest(const std::string &name, int level) : Character(name, level), Mage(name, level)
{
    this->_name = name;
    this->_level = level;
    this->_energy = 100;
    this->_pv = 100;
    this->_race = std::string("Orc");
    this->_strength = 4;
    this->_stamina = 4;
    this->_intelligence = 42;
    this->_spirit = 21;
    this->_agility = 2;
    this->Range = CLOSE;
    std::cout << this->_name << " enters in the order" << std::endl;
}

Priest::~Priest()
{
}

void Priest::Heal()
{
    int pv_required = 100 - this->_pv;

    if (this->_energy >= 10) {
        if (pv_required < 70)
            this->_pv = 100;
        else
            this->_pv = this->_pv + 70;
        std::cout << this->_name << " casts a little heal spell" << std::endl;
        this->_energy = this->_energy - 10;
    } else
        std::cout << this->_name << " out of power" << std::endl;
}

int Priest::CloseAttack()
{
    if (this->_energy >= 10) {
        if (this->Range == CLOSE) {
            std::cout << this->_name << " uses a spirit explosion" << std::endl;
            this->Range = RANGE;
            this->_energy = this->_energy - 10;
            return (10 + this->_spirit);
        } else {
            std::cout << this->_name << " uses a spirit explosion" << std::endl;
            this->_energy = this->_energy - 10;
            return 0;
        }
    } else {
        std::cout << this->_name << " out of power" << std::endl;
        return 0;
    }
    return 0;
}