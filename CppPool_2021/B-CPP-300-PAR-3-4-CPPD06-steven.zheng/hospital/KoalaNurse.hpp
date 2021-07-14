/*
** EPITECH PROJECT, 2021
** NurseKoala
** File description:
** Exercise 03 include
*/

#ifndef KOALANURSE_HPP_
#define KOALANURSE_HPP_
#include "SickKoala.hpp"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cstring>

class KoalaNurse {
    public:
        bool work;
        KoalaNurse(int id_give);
        ~KoalaNurse();
        void giveDrug(std::string drug, SickKoala *koala);
        std::string readReport(std::string filename);
        void timeCheck();
    protected:
    private:
        int id;
};

#endif
