/*
** EPITECH PROJECT, 2021
** SickKoala
** File description:
** Exercise 02 include
*/

#ifndef SICKKOALA_HPP_
#define SICKKOALA_HPP_
#include <iostream>
#include <algorithm>
#include <string>

class SickKoala {
    public:
        SickKoala(std::string name_gived);
        ~SickKoala();
        void poke();
        bool takeDrug(std::string);
        void overDrive(std::string fever);
        std::string getName();
    protected:
    private:
        std::string name;
        std::string fever;
};

#endif
