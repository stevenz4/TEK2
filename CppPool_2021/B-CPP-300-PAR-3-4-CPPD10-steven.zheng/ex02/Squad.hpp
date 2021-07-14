/*
** EPITECH PROJECT, 2021
** Squad
** File description:
** Exercise 02
*/

#ifndef SQUAD_HPP_
#define SQUAD_HPP_

#include "ISquad.hpp"

class Squad  : public ISquad {
    public :
        Squad();
        Squad(Squad const &);
        ~Squad();
        int getCount() const;
        ISpaceMarine *getUnit(int);
        int push(ISpaceMarine*);
        int countSquad();
    private :
        int _count;
        ISpaceMarine **_array;
};

#endif /* !SQUAD_HPP_ */