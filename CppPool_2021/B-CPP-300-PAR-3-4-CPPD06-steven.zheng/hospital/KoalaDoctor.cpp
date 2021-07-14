/*
** EPITECH PROJECT, 2021
** KoalaDoctor
** File description:
** Exercise 04
*/

#include "KoalaDoctor.hpp"

KoalaDoctor::KoalaDoctor(std::string DoctorName)
{
    this->name = DoctorName;
    std::cout << "Dr." << name << ": I'm Dr." << name << "! How do you kreog?" << std::endl; 
    this->work = false;
}

KoalaDoctor::~KoalaDoctor()
{
    this->name.empty();
}

void KoalaDoctor::diagnose(SickKoala *koala_gived)
{
    std::string drug[5] = {"Mars", "Kinder", "Crunch", "Maroilles", "Eucalyptus leaf"};
    std::string filename = koala_gived->getName() + ".report";
    std::ofstream my_file;
    int random_nb = 0;

    std::cout << "Dr." << name << ": So what's goerking you Mr." << koala_gived->getName() << '?' << std::endl;
    my_file.open(filename);
    random_nb = random() % 5;
    my_file << drug[random_nb];
    koala_gived->poke();

}

void KoalaDoctor::timeCheck()
{
    if (!this->work) {
        std::cout << "Dr." << this->name << ": Time to get to work!" << std::endl;
        this->work = true;
    }
    else {
        std::cout << "Dr." << this->name << ": Time to go home to my eucalyptus forest!" << std::endl;
        this->work = false;
    }
}