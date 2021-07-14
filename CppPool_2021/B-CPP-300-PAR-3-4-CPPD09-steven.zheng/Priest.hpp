/*
** EPITECH PROJECT, 2021
** Children
** File description:
** Exercise 03
*/

#ifndef PRIEST_HPP_
#define PRIEST_HPP_

#include "Mage.hpp"

class Priest : public Mage {
    public:
        Priest(const std::string &name, int level);
        ~Priest();
        void Heal();
        int CloseAttack();
    protected:
    private:
};

#endif /* !PRIEST_HPP_ */
