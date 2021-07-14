/*
** EPITECH PROJECT, 2021
** NurseKoala
** File description:
** Exercise 03
*/

#include "KoalaNurse.hpp"

KoalaNurse::KoalaNurse(int id_arg)
{
    this->work = false;
    this->id = id_arg;
}

KoalaNurse::~KoalaNurse()
{
    std::cout << "Nurse " << id << ": Finally some rest!" << std::endl;
}

void KoalaNurse::giveDrug(std::string drug_gived, SickKoala *koala)
{
    if (koala)
        koala->takeDrug(drug_gived);
}

std::string KoalaNurse::readReport(std::string filename_arg)
{
    std::ifstream my_file (filename_arg);
    std::string empty = "";
    std::string patientName = filename_arg.substr(0, filename_arg.find(".report"));
    std::string drugName;

    if (my_file) {
        if (!getline(my_file, drugName) || patientName.length() == 0)
            return empty;
        std::cout << "Nurse " << id << ": Kreog! Mr." << patientName << " needs a " << drugName << "!" << std::endl;
        return drugName;
    } else
        return empty;
}

void KoalaNurse::timeCheck()
{
    if (!this->work) {
        std::cout << "Nurse " << id << ": Time to get to work!" << std::endl;
        this->work = true;
    }
    else {
        std::cout << "Nurse " << id << ": Time to go home to my eucalyptus forest!" << std::endl;
        this->work = false;
    }
}