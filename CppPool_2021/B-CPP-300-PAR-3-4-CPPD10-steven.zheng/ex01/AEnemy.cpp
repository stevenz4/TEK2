/*
** EPITECH PROJECT, 2021
** AEnemy
** File description:
** Exercise 01
*/

#include "AEnemy.hpp"

AEnemy::AEnemy(int hp, const std::string &type)
{
    this->_hp = hp;
    this->_type = type;
}

AEnemy::~AEnemy()
{
}

void AEnemy::takeDamage(int damage)
{
    if (damage >= 0)
        this->_hp = this->_hp - damage;
}

std::string AEnemy::getType() const
{
    return this->_type;
}

int AEnemy::getHP() const
{
    return this->_hp;
}