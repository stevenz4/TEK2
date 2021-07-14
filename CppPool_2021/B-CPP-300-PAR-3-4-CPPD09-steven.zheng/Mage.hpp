/*
** EPITECH PROJECT, 2021
** Children
** File description:
** Exercise 03
*/

#ifndef MAGE_HPP_
#define MAGE_HPP_

#include "Character.hpp"

class Mage : virtual public Character {
    public:
        Mage(const std::string &name, int level);
        ~Mage();
        int CloseAttack();
        void Heal();
        int RangeAttack();
        void RestorePower();
    protected:
    private:
};

#endif /* !MAGE_HPP_ */
