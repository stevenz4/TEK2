/*
** EPITECH PROJECT, 2021
** KoalaDoctor
** File description:
** Exercise 04 include
*/

#ifndef KOALADOCTOR_HPP_
#define KOALADOCTOR_HPP_

#include "SickKoala.hpp"
#include "KoalaNurse.hpp"

class KoalaDoctor {
    public:
        KoalaDoctor(std::string);
        ~KoalaDoctor();
        void diagnose(SickKoala *);
        void timeCheck();
        bool work;
    protected:
    private:
        std::string name;
};

#endif
