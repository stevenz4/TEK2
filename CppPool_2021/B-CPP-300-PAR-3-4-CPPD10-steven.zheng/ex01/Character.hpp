/*
** EPITECH PROJECT, 2021
** Character
** File description:
** Exercise 01
*/

#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include <string>
#include <iostream>

#include "AWeapon.hpp"
#include "AEnemy.hpp"

class Character {
    public:
        Character(const std::string &name);
        ~Character();
        void recoverAP();
        void equip(AWeapon *weapon);
        void attack(AEnemy *enemy);
        std::string getName() const;
        int getAp() const;
        AWeapon *weapon;
    protected:
    private:
        std::string _name;
        int _ap;
};

std::ostream &operator<<(std::ostream &flux, Character &c);

#endif /* !CHARACTER_HPP_ */
