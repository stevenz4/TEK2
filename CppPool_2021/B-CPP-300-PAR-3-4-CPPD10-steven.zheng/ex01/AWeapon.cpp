/*
** EPITECH PROJECT, 2021
** Let Them Burn
** File description:
** Exercise 01
*/

#include "AWeapon.hpp"

AWeapon::AWeapon(const std::string &name, int apcost, int damage)
{
    this->_name = name;
    this->_apcost = apcost;
    this->_damage = damage;
}

AWeapon::~AWeapon()
{
}

void AWeapon::attack() const
{

}

std::string AWeapon::getName() const
{
    return this->_name;
}

int AWeapon::getAPCost() const
{
    return this->_apcost;
}

int AWeapon::getDamage() const
{
    return this->_damage;
}