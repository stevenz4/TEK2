/*
** EPITECH PROJECT, 2021
** SuperMutant
** File description:
** Exercise 01
*/

#ifndef SUPERMUTANT_HPP_
#define SUPERMUTANT_HPP_

#include "AEnemy.hpp"

class SuperMutant : public AEnemy {
    public:
        SuperMutant();
        ~SuperMutant();
        void takeDamage(int damage);
    protected:
    private:
};

#endif /* !SUPERMUTANT_HPP_ */
