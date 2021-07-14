/*
** EPITECH PROJECT, 2021
** Ponymorphism
** File description:
** Exercise 00
*/

#ifndef PEON_HPP_
#define PEON_HPP_

#include "Victim.hpp"

class Peon : public Victim {
    public:
        Peon(std::string name);
        ~Peon();
        void getPolymorphed() const;
    protected:
    private:
};

#endif /* !PEON_HPP_ */
