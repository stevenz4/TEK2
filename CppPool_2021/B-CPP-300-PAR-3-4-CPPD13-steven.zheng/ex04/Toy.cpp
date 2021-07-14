/*
** EPITECH PROJECT, 2021
** Toy
** File description:
** Exercise 00
*/

#include "Toy.hpp"

Toy::Toy(ToyType type, std::string const &name, std::string const &filename)
{
    this->_type = type;
    this->_name = name;
    this->setAscii(filename);
}

Toy::Toy(Toy const &copy)
{
    this->_name = copy._name;
    this->_picture = copy._picture;
    this->_type = copy._type;
}

Toy::Toy()
{
    this->_type = BASIC_TOY;
    this->_name = "toy";
    this->_picture.data.clear();
}

Toy::~Toy()
{
}

int Toy::getType() const
{
    return this->_type;
}

std::string Toy::getName() const
{
    return this->_name;
}

std::string Toy::getAscii() const
{
    return this->_picture.data;
}

bool Toy::setAscii(std::string const &filename)
{
    if (this->_picture.getPictureFromFile(filename))
        return true;
    return false;
}

void Toy::setName(std::string const &name)
{
    this->_name = name;
}

Toy &Toy::operator=(Toy const &toy)
{
    this->_name = toy._name;
    this->_picture = toy._picture;
    this->_type = toy._type;
    return *this;
}

void Toy::speak(std::string const &statement)
{
    std::cout << this->_name << " \"" << statement << "\"" << std::endl;
}

std::ostream &operator<<(std::ostream &flux, Toy const &toy)
{
    return (flux << toy.getName() << std::endl << toy.getAscii() << std::endl);
}

Toy &Toy::operator<<(std::string const &flux)
{
    this->_picture.data = flux;
    return *this;
}