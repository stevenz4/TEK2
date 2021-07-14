/*
** EPITECH PROJECT, 2021
** ISpaceMarine
** File description:
** Exercise 02
*/

#ifndef ISPACEMARINE_HPP_
#define ISPACEMARINE_HPP_

#include <string>
#include <iostream>

class ISpaceMarine {
    public :
        virtual ~ISpaceMarine() {};
        virtual ISpaceMarine *clone() const = 0;
        virtual void battleCry() const = 0;
        virtual void rangedAttack() const = 0;
        virtual void meleeAttack() const = 0;
};

#endif /* !ISPACEMARINE_HPP_ */
