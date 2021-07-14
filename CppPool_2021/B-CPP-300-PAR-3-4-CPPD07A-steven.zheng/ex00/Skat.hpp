/*
** EPITECH PROJECT, 2021
** Skat
** File description:
** Exercise 00
*/

#ifndef SKAT_HPP_
#define SKAT_HPP_
#include <iostream>
#include <string>

class Skat
{
    public:
        Skat(const std::string &name_koala, int stimPaks);
        Skat(const std::string &name_koala);
        Skat(int stimPaks);
        Skat();
        ~Skat ();
        int &stimPaks();
        void shareStimPaks(int number, int &stock);
        void addStimPaks(unsigned int number);
        void useStimPaks();
        void status();
        const std::string &name();
    private:
        int stimPaks_nb;
        std::string name_koala;
};

#endif
