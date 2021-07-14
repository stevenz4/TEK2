/*
** EPITECH PROJECT, 2021
** Federation
** File description:
** Exercise 00 Federation
*/

#include "Federation.hpp"

/* Federation's Starfleet ship */

Federation::Starfleet::Ship::Ship(int length, int width, std::string name, short maxWarp)
{
    std::cout << "The ship USS " << name <<  " has been finished." << std::endl;
    std::cout << "It is " << length << " m in length and " << width <<  " m in width." << std::endl;
    std::cout << "It can go to Warp " <<  maxWarp << '!' << std::endl;
    this->_name = name;
    this->_length = length;
    this->_width = width;
    this->_maxWarp = maxWarp;
    this->_home = EARTH;
    this->_location = this->_home;
    this->_shield = 100;
    this->_photoTorpedo = 0;
}

Federation::Starfleet::Ship::~Ship()
{
}

void Federation::Starfleet::Ship::setupCore(WarpSystem::Core *core)
{
    std::cout << "USS " << this->_name << ": The core is set." << std::endl;
    this->_core = core;
}

void Federation::Starfleet::Ship::checkCore()
{
    if (this->_core->checkReactor()->isStable() == true)
        std::cout << "USS " << this->_name << ": The core is stable " <<  "at the time." << std::endl;
    if (this->_core->checkReactor()->isStable() == false)
        std::cout << "USS " << this->_name << ": The core is unstable " <<  "at the time." << std::endl;
}

/*Federation's Ship*/

Federation::Ship::Ship(int length , int width, std::string name)
{
    std::cout << "The independent ship " << name << " just finished its construction." << std::endl;
    std::cout << "It is " << length << " m in length and " << width << " m in width." << std::endl;
    this->_name_ = name;
    this->_length_ = length;
    this->_width_ = width;
    this->_home = VULCAN;
    this->_location = this->_home;
}

Federation::Ship::~Ship()
{
}

void Federation::Ship::setupCore(WarpSystem::Core *core)
{
    std::cout << this->_name_ << ": The core is set." << std::endl;
    this->_core_ = core;
}

void Federation::Ship::checkCore()
{
    if (this->_core_->checkReactor()->isStable() == true)
        std::cout << this->_name_ << ": The core is stable " <<  "at the time." << std::endl;
    if (this->_core_->checkReactor()->isStable() == false)
        std::cout << this->_name_ << ": The core is unstable " <<  "at the time." << std::endl;
}

bool Federation::Ship::move(int warp, Destination d)
{
    if ((warp <= 1) && (d != this->_location) && (this->_core_->checkReactor()->isStable() == true)) {
        this->_location = d;
        return true;
    } else
        return false;
}

bool Federation::Ship::move(int warp)
{
    return (this->move(warp, this->_location));
}

bool Federation::Ship::move(Destination d)
{
    return (this->move(1, d));
}

bool Federation::Ship::move()
{
    return (this->move(1, this->_location));
}

/*Captain*/

Federation::Starfleet::Captain::Captain(std::string name)
{
    this->name = name;
}

Federation::Starfleet::Captain::~Captain()
{
}

std::string Federation::Starfleet::Captain::getName()
{
    return this->name;
}

int Federation::Starfleet::Captain::getAge()
{
    return this->_age;
}

void Federation::Starfleet::Captain::setAge(int age)
{
    this->_age = age;
}

void Federation::Starfleet::Ship::promote(Federation::Starfleet::Captain *captain)
{
    std::cout << captain->getName() << ": I'm glad to be the captain of the USS " << this->_name << "." << std::endl;
    this->_captain = captain;
}

Federation::Starfleet::Ensign::Ensign(std::string name)
{
    this->_name = name;
    std::cout << "Ensign " << name << ", awaiting orders." << std::endl;
}

Federation::Starfleet::Ensign::~Ensign()
{
}

/*Moving Functions*/

bool Federation::Starfleet::Ship::move(int warp, Destination d)
{
    if ((warp <= this->_maxWarp) && (d != this->_location) && (this->_core->checkReactor()->isStable() == true)) {
        this->_location = d;
        return true;
    } else
        return false;
}

bool Federation::Starfleet::Ship::move(int warp)
{
    return (this->move(warp, this->_location));
}

bool Federation::Starfleet::Ship::move(Destination d)
{
    return (this->move(this->_maxWarp, d));
}

bool Federation::Starfleet::Ship::move()
{
    return (this->move(this->_maxWarp, this->_location));
}

/*This is War*/

Federation::Starfleet::Ship::Ship(int length, int width, std::string name, short maxWarp, int torpedo)
{
    std::cout << "The ship USS " << name <<  " has been finished." << std::endl;
    std::cout << "It is " << length << " m in length and " << width <<  " m in width." << std::endl;
    std::cout << "It can go to Warp " <<  maxWarp << '!' << std::endl;
    if (torpedo != 0)
        std::cout << "Weapons are set: " << torpedo << " torpedoes ready." << std::endl;
    this->_name = name;
    this->_length = length;
    this->_width = width;
    this->_maxWarp = maxWarp;
    this->_home = EARTH;
    this->_location = this->_home;
    this->_shield = 100;
    this->_photoTorpedo = torpedo;
}

Federation::Starfleet::Ship::Ship()
{
    std::cout << "The ship USS Entreprise has been finished." << std::endl;
    std::cout << "It is 289 m in length and 132 m in width." << std::endl;
    std::cout << "It can go to Warp 6!" << std::endl;
    this->_home = EARTH;
    this->_location = this->_home;
    this->_shield = 100;
    this->_photoTorpedo = 0;
}

void Federation::Starfleet::Ship::fire(Borg::Ship *target)
{
    if (this->_photoTorpedo > 1) {
        this->_photoTorpedo = this->_photoTorpedo - 1;
        target->_shield = target->_shield - 50;
        std::cout << this->_name <<": Firing on target. " << this->_photoTorpedo << " torpedoes remaining." << std::endl;
    } else
        std::cout << this->_name << ": No enough torpedoes to fire, " << this->_captain->getName() << '!' << std::endl;
}

void Federation::Starfleet::Ship::fire(int torpedoes, Borg::Ship *target)
{
    if (torpedoes > this->_photoTorpedo)
        std::cout << this->_name << ": No more torpedo to fore, " << this->_captain->getName() << '!' << std::endl;
    else if (this ->_photoTorpedo > torpedoes) {
        target->_shield = target->_shield - (torpedoes * 50);
        this->_photoTorpedo = this->_photoTorpedo - 1;
        std::cout << this->_name <<": Firing on target. " << this->_photoTorpedo << " torpedoes remaining." << std::endl;
    } else
        std::cout << this->_name << ": No enough torpedoes to fire, " << this->_captain->getName() << '!' << std::endl;
}

WarpSystem::Core *Federation::Ship::getCore()
{
    return(this->_core_);
}