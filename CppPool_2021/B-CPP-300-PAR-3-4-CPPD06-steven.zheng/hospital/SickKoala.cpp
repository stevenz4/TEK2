/*
** EPITECH PROJECT, 2021
** SickKoala
** File description:
** Exercise 02
*/

#include "SickKoala.hpp"

SickKoala::SickKoala(std::string name_gived)
{
    this->name = name_gived;
}

SickKoala::~SickKoala()
{
    std::cout << "Mr." << name << ": Kreooogg!! I'm cuuuured!" << std::endl;
    this->name.empty();
}

void SickKoala::poke()
{
    std::cout << "Mr." << name << ": Gooeeeeerrk!!" << std::endl;
}

bool SickKoala::takeDrug(std::string choco)
{
    if ((choco.compare("Mars")) == 0) {
        std::cout << "Mr." << name <<": Mars, and it kreogs!" << std::endl;
        return true;
    }
    if ((choco.compare("Kinder")) == 0) {
        std::cout << "Mr." << name <<": There is a toy inside!" << std::endl;
        return true;
    }
    std::cout << "Mr." << name << ": Goerkreog!" << std::endl;
    return false;
}

void SickKoala::overDrive(std::string fever)
{
    size_t pos = fever.find("Kreog!");

    while (pos != fever.npos) {
        fever.replace(pos, 6, "1337!");
        pos = fever.find("Kreog!", pos + 5);
    }
    std::cout << "Mr." << name << ": " << fever << std::endl;
}

std::string SickKoala::getName()
{
    return name;
}