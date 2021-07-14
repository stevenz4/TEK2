/*
** EPITECH PROJECT, 2021
** Or is it eleven
** File description:
** Exercise 05
*/

#ifndef HUNTER_HPP_
#define HUNTER_HPP_

#include "Warrior.hpp"

class Hunter : protected Warrior{
    public:
        Hunter(const std::string &name, int level);
        ~Hunter();
        int RangeAttack();
        void RestorePower();
        using Warrior::CloseAttack;
        using Warrior::getLvl;
        using Warrior::getName;
        using Warrior::getPower;
        using Warrior::getPv;
        using Warrior::AttackRange;
        using Warrior::Range;
    protected:
    private:
};

#endif /* !HUNTER_HPP_ */
