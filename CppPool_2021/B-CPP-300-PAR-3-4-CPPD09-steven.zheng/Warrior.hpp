/*
** EPITECH PROJECT, 2021
** Existentialism
** File description:
** Exercise 02
*/

#ifndef WARRIOR_HPP_
#define WARRIOR_HPP_

#include "Character.hpp"
#include <string>
#include <iostream>

class Warrior : virtual public Character {
    public:
        Warrior(const std::string &name, int level);
        ~Warrior();
        int CloseAttack();
        int RangeAttack();
    protected:
        std::string _weaponName;
    private:
};


#endif /* !WARRIOR_HPP_ */
