/*
** EPITECH PROJECT, 2021
** Skat
** File description:
** Exercise 00
*/

#include "Skat.hpp"

Skat::Skat(const std::string &name, int stimPaks)
{
    this->name_koala = name;
    this->stimPaks_nb = stimPaks;
}

Skat::Skat(const std::string &name)
{
    this->name_koala = name;
    this->stimPaks_nb = 15;
}

Skat::Skat(int stimPaks)
{
    this->name_koala = "bob";
    this->stimPaks_nb = stimPaks;   
}

Skat::Skat()
{
    this->name_koala = "bob";
    this->stimPaks_nb = 15;
}

Skat::~Skat()
{
}

int &Skat::stimPaks()
{
    return this->stimPaks_nb;
}

const std::string &Skat::name()
{
    return this->name_koala;
}

void Skat::shareStimPaks(int number, int &stock)
{
    if (this->stimPaks_nb >= number) {
        std::cout << "Keep the change." << std::endl;
        this->stimPaks_nb = this->stimPaks_nb - number;
        stock = stock + number;
    } else
        std::cout << "Don't be greedy" << std::endl;
}

void Skat::addStimPaks(unsigned int number)
{
    if (number == 0)
        std::cout << "Hey boya, did you forget something?" << std::endl;
    else
        this->stimPaks_nb = this->stimPaks_nb + number;
}

void Skat::useStimPaks()
{
    if (this->stimPaks_nb == 0)
        std::cout << "Mediiiiiic" << std::endl;
    else {
        std::cout << "Time to kick some ass and chew bubble gum." << std::endl;   
        this->stimPaks_nb = this->stimPaks_nb - 1;
    }     
}

void Skat::status()
{
    std::cout << "Soldier " << this->name_koala << " reporting " << this->stimPaks_nb << " stimpaks remaining sir!" << std::endl;
}