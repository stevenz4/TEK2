/*
** EPITECH PROJECT, 2021
** PlasmaRifle
** File description:
** Exercise 01
*/

#ifndef PLASMARIFLE_HPP_
#define PLASMARIFLE_HPP_

#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon {
    public:
        PlasmaRifle();
        ~PlasmaRifle();
        virtual void attack() const;
    protected:
    private:
};

#endif /* !PLASMARIFLE_HPP_ */
