/*
** EPITECH PROJECT, 2021
** PowerFist
** File description:
** Exercise 01
*/

#ifndef POWERFIST_HPP_
#define POWERFIST_HPP_

#include "AWeapon.hpp"

class PowerFist : public AWeapon {
    public:
        PowerFist();
        ~PowerFist();
        virtual void attack() const;
    protected:
    private:
};

#endif /* !POWERFIST_HPP_ */

