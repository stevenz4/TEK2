/*
** EPITECH PROJECT, 2021
** Ponymorphism
** File description:
** Exercise 00
*/

#ifndef VICTIM_HPP_
#define VICTIM_HPP_

#include <string>
#include <iostream>

class Victim {
    public:
        Victim(std::string name);
        ~Victim();
        std::string getName();
        virtual void getPolymorphed() const;
    protected:
        std::string _name;
    private:
};

std::ostream &operator<<(std::ostream &flux, Victim &victim);

#endif /* !VICTIM_HPP_ */
