/*
** EPITECH PROJECT, 2021
** Paladin
** File description:
** Exercise 04
*/

#ifndef PALADIN_HPP_
#define PALADIN_HPP_

#include "Warrior.hpp"
#include "Priest.hpp"

class Paladin : virtual public Warrior, public Priest{
    public:
        Paladin(const std::string &name, int level);
        ~Paladin();
        using Warrior::CloseAttack;
        using Priest::Heal;
        using Priest::RangeAttack;
        using Character::RestorePower;
        int Intercept();
    protected:
    private:
};

#endif /* !PALADIN_HPP_ */
