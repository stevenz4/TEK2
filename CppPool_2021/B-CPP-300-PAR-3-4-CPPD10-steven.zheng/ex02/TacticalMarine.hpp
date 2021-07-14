/*
** EPITECH PROJECT, 2021
** Tactical Marine
** File description:
** Exercise 02
*/

#ifndef TACTICALMARINE_HPP_
#define TACTICALMARINE_HPP_

#include "ISpaceMarine.hpp"

class TacticalMarine : public ISpaceMarine {
    public:
        TacticalMarine();
        TacticalMarine(TacticalMarine const &copy);
        virtual ~TacticalMarine();
        ISpaceMarine *clone() const;
        void battleCry() const;
        void rangedAttack() const;
        void meleeAttack() const;
    protected:
    private:
};

#endif /* !TACTICALMARINE_HPP_ */
