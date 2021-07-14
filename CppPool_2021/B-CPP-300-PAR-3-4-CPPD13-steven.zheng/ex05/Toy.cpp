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
    this->error.setType(Error::PICTURE);
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

bool Toy::speak_es(std::string const &statement)
{
    this->error.setType(Error::SPEAK);
    return false;
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

Toy::Error::Error()
{
    this->type = UNKNOWN;
}

Toy::Error const &Toy::getLastError() const
{
    return this->error;
}

std::string Toy::Error::what() const
{
    if (this->type == Error::PICTURE)
        return "bad new illustration";
    if (this->type == Error::SPEAK)
        return "wrong mode";
    return "";
}

std::string Toy::Error::where() const
{
    if (this->type == Error::PICTURE)
        return "setAscii";
    if (this->type == Error::SPEAK)
        return "speak_es";
    return "";
}

void Toy::Error::setType(ErrorType type)
{
    this->type = type;
}