/*
** EPITECH PROJECT, 2021
** AssaultTerminator
** File description:
** Exercise 02
*/

#ifndef ASSAULTTERMINATOR_HPP_
#define ASSAULTTERMINATOR_HPP_

#include "ISpaceMarine.hpp"

class AssaultTerminator : public ISpaceMarine {
    public:
        AssaultTerminator();
        AssaultTerminator(AssaultTerminator const &copy);
        virtual ~AssaultTerminator();
        ISpaceMarine *clone() const;
        void battleCry() const;
        void rangedAttack() const;
        void meleeAttack() const;
    protected:
    private:
};

#endif /* !ASSAULTTERMINATOR_HPP_ */
