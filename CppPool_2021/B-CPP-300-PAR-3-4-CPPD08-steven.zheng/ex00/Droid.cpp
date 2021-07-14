/*
** EPITECH PROJECT, 2021
** Droid
** File description:
** Exercise 00
*/

#include "Droid.hpp"

/*Constructor and Destructor*/

Droid::Droid(std::string serial_number) : Id(serial_number), Energy(50), Attack(25), Toughness(15)
{   
    this->Status = new std::string("Standing by");
    std::cout << "Droid '" << this->Id << "' Activated" << std::endl;
}

Droid::Droid(Droid const &copy) : Id(copy.Id), Energy(copy.Energy), Attack(copy.Attack), Toughness(copy.Toughness)
{
    this->Status = new std::string("Standing by");
    std::cout << "Droid '" << Id << "' Activated, Memory Dumped" << std::endl;
}

Droid::Droid() : Attack(25), Toughness(15)
{
    this->Id.empty();
    this->Energy = 50;
    this->Status = new std::string("Standing by");
    std::cout << "Droid '" << this->Id << "' Activated" << std::endl;
}

Droid::~Droid() 
{
    std::cout << "Droid " << this->Id << " Destroyed" << std::endl;
}


/* All functions */

std::string Droid::getId() const
{
    return this->Id;
}

void Droid::setId(std::string serial_number)
{
    this->Id = serial_number;
}

size_t Droid::getEnergy() const
{
    return this->Energy;
}

void Droid::setEnergy(size_t energy) {
    this->Energy = energy;
}

size_t Droid::getAttack() const
{
    return this->Attack;
}

size_t Droid::getToughness() const
{
    return this->Toughness;
}

std::string *Droid::getStatus() const
{
    return this->Status;
}

void Droid::setStatus(std::string *status) {
    this->Status = status;
}

/* Operators */

std::ostream &operator<<(std::ostream &flux, Droid &droid)
{
    return (flux << "Droid '" << droid.getId() << "', " << *(droid.getStatus()) << ", " << droid.getEnergy());
}

Droid &Droid::operator=(Droid &droid)
{
    setId(droid.Id);
    setEnergy(droid.Energy);
    setStatus(droid.Status);
    return *this;
}

Droid &Droid::operator<<(size_t &energy)
{
    size_t energy_required = 100 - this->Energy;

    if (energy > 0) {
        if (energy < energy_required) {
            this->setEnergy(this->Energy + (energy_required - energy));
            energy = 0;
        } else {
            this->setEnergy(this->Energy + energy_required);
            energy = energy - energy_required;
        }
    }
    return *this;
}

bool Droid::operator!=(Droid const &droid) const
{
    if (this->Attack != droid.Attack)
        return true;
    if (this->Id != droid.Id)
        return true;
    if (this->Energy != droid.Energy)
        return true;
    if (this->Status != droid.Status)
        return true;
    if (this->Toughness != droid.Toughness)
        return true;
    return false;
}

bool Droid::operator==(Droid const &droid) const
{
    return (this->Id == droid.Id) &&
        (this->Energy == droid.Energy) &&
        (this->Attack == droid.Attack) &&
        (this->Toughness == droid.Toughness) &&
        (*this->Status == *(droid.Status));
}