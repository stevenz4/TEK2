/*
** EPITECH PROJECT, 2021
** Borg
** File description:
** Exercise 01
*/

#include "Federation.hpp"
#include "Borg.hpp"

Borg::Ship::Ship(int weaponFrequency, short repair)
{
    this->_side = 300;
    this->_maxWarp = 9;
    this->_home = UNICOMPLEX;
    this->_location = this->_home;
    this->_shield = 100;
    this->_repair = repair;
    this->_weaponFrequency = weaponFrequency;
    std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally." << std::endl;
    std::cout << "Your biological characteristics and technologies will be assimilated." << std::endl;
    std::cout << "Resistance is futile." << std::endl;
}

Borg::Ship::~Ship()
{
}

void Borg::Ship::setupCore(WarpSystem::Core *core)
{
    this->_core_ = core;
}

void Borg::Ship::checkCore()
{
    if (this->_core_->checkReactor()->isStable() == true)
        std::cout << "Everything is in order." << std::endl;
    if (this->_core_->checkReactor()->isStable() == false)
        std::cout << "Critical failure imminent." << std::endl;
}

bool Borg::Ship::move(int warp, Destination d)
{
    if ((warp <= this->_maxWarp) && (d != this->_location) && (this->_core_->checkReactor()->isStable() == true)) {
        this->_location = d;
        return true;
    } else
        return false;
}

bool Borg::Ship::move(int warp)
{
    return (this->move(warp, this->_location));
}

bool Borg::Ship::move(Destination d)
{
    return (this->move(this->_maxWarp, d));
}

bool Borg::Ship::move()
{
    return (this->move(this->_maxWarp, this->_location));
}

int Borg::Ship::getShield() {
    return this->_shield;
}

void Borg::Ship::setShield(int shield) {
    this->_shield = shield;
}

int Borg::Ship::getWeaponFrequency() {
    return this->_weaponFrequency;
}

void Borg::Ship::setWeaponFrequency(int frequency) {
    this->_weaponFrequency = frequency;
}

short Borg::Ship::getRepair() {
    return this->_repair;
}
void Borg::Ship::setRepair(short repair) {
    this->_repair = repair;
}

void Borg::Ship::fire(Federation::Starfleet::Ship *target)
{
    target->_shield = target->_shield - this->_weaponFrequency;
    std::cout << "Firing on target with " << this->_weaponFrequency << "GW frequency." << std::endl;
}

void Borg::Ship::fire(Federation::Ship *target)
{
    target->_core_->checkReactor()->setStability(false);
    std::cout << "Firing on target with " << this->_weaponFrequency << "GW frequency." << std::endl;
}

void Borg::Ship::repair()
{
    if (this->_repair > 0) {
        this->_repair = this->_repair - 1;
        this->_shield = 100;
        std::cout << "Begin shield re-initialisation... Done. Awaiting further instructions." << std::endl;
    } else 
        std::cout << "Energy cells depleted, shield weakening." << std::endl;
}