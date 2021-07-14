/*
** EPITECH PROJECT, 2021
** Family Matter
** File description:
** Exercise 01
*/

#include "Character.hpp"

Character::Character(const std::string &name, int level)
{
    this->_name = name;
    this->_level = level;
    this->_energy = 100;
    this->_pv = 100;
    this->_race = std::string("Human");
    this->_strength = 5;
    this->_stamina = 5;
    this->_intelligence = 5;
    this->_spirit = 5;
    this->_agility = 5;
    this->Range = CLOSE;
    std::cout << this->_name << " Created" << std::endl;
}

Character::~Character()
{
}

const std::string &Character::getName() const
{
    return this->_name;
}

int Character::getLvl() const
{
    return this->_level;
}

int Character::getPv() const
{
    return this->_pv;
}

int Character::getPower() const
{
    return this->_energy;
}

int Character::CloseAttack()
{
    if (this->_energy >= 10) {
        if (this->Range == CLOSE) {
            this->_energy = this->_energy - 10;
            std::cout << this->_name << " strikes with a wooden stick" << std::endl;
            return (10 + this->_strength);
        } else {
            this->_energy = this->_energy - 10;
            std::cout << this->_name << " strikes with a wooden stick" << std::endl;
            return 0;
        }
    } else {
        std::cout << this->_name << " out of power" << std::endl;
        return 0;
    }
    return 0;
}

void Character::Heal()
{
    int pv_required = 100 - this->_pv;

    if (pv_required < 50)
        this->_pv = 100;
    else
        this->_pv = this->_pv + 50;
    std::cout << this->_name << " takes a potion" << std::endl;
}

int Character::RangeAttack()
{
    if (this->_energy < 10) {
        std::cout << this->_name << " out of power" << std::endl;
        return 0;
    }
    else {
        this->_energy = this->_energy - 10;
        std::cout << this->_name << " tosses a stone" << std::endl;
        return (5 + this->_strength);
    }
}

void Character::RestorePower()
{
    this->_energy = 100;
    std::cout << this->_name << " eats" << std::endl;
}

void Character::TakeDamage(int damage)
{
    if (this->_pv <= 0) {
        std::cout << this->_name << " out of combat" << std::endl;
    } else {
        if (damage >= this->_pv) {
            std::cout << this->_name << " out of combat" << std::endl;
            this->_pv = this->_pv - damage;
        } else {
            std::cout << this->_name << " takes " << damage << " damage" << std::endl;
            this->_pv = this->_pv - damage;
        }
    }
}