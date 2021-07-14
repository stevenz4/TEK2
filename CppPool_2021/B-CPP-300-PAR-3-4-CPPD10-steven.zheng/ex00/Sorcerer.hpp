/*
** EPITECH PROJECT, 2021
** Ponymorphism
** File description:
** Exercise 00
*/

#ifndef SORCERER_HPP_
#define SORCERER_HPP_

#include <string>
#include <iostream>
#include "Victim.hpp"

class Sorcerer {
    public:
        Sorcerer(std::string name, std::string title);
        ~Sorcerer();
        std::string getName();
        std::string getTitle();
        void polymorph(const Victim &victim);
    protected:
    private:
        std::string _title;
        std::string _name;
};

std::ostream &operator<<(std::ostream &flux, Sorcerer &sorcerer);

#endif /* !SORCERER_HPP_ */