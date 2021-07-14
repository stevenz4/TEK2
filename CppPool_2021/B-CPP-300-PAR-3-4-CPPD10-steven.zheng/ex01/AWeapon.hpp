/*
** EPITECH PROJECT, 2021
** Let Them Burn
** File description:
** Exercise 01
*/

#ifndef AWEAPON_HPP_
#define AWEAPON_HPP_

#include <string>
#include <iostream>

class AWeapon
{
    public :
        AWeapon(const std::string &name, int apcost, int damage);
        virtual ~AWeapon();
        std::string getName() const;
        int getAPCost() const;
        int getDamage() const;
        virtual void attack() const  = 0;
    protected :
        std::string _name;
        int _apcost;
        int _damage;
    private :
};

#endif /* !AWEAPON_HPP_ */
