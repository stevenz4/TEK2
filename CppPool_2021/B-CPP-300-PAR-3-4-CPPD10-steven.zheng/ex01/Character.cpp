/*
** EPITECH PROJECT, 2021
** Character
** File description:
** Exercise 01
*/

#include "Character.hpp"

Character::Character(const std::string &name)
{
    this->_name = name;
    this->_ap = 40;
    this->weapon = NULL;
}

Character::~Character()
{
}

std::string Character::getName() const
{
    return this->_name;
}

int Character::getAp() const
{
    return this->_ap;
}

void Character::recoverAP()
{
    if (this->_ap < 40) {
        if (this->_ap >= 30 && this->_ap < 40)
            this->_ap = 40;
        else
            this->_ap = this->_ap + 10;
    }
}

void Character::attack(AEnemy *enemy)
{
    if (this->weapon) {
        if (this->_ap >= weapon->getAPCost()) {
            std::cout << this->_name << " attacks " << enemy->getType() << " with a " << this->weapon->getName() << std::endl;
            this->weapon->attack();
            this->_ap = this->_ap - weapon->getAPCost();
            enemy->takeDamage(this->weapon->getDamage());
        }
        if (enemy->getHP() <= 0)
            enemy->~AEnemy();
    }
}

void Character::equip(AWeapon *weapon)
{
    this->weapon = weapon;
}

std::ostream &operator<<(std::ostream &flux, Character &c)
{
    if (c.weapon)
        return (flux << c.getName() << " has " << c.getAp() << " AP and wields a " << c.weapon->getName() << std::endl);
    else
        return (flux << c.getName() << " has " << c.getAp() << " AP and is unarmed" << std::endl);
}