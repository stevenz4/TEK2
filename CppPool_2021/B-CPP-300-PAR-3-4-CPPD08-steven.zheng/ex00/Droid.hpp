/*
** EPITECH PROJECT, 2021
** Droid
** File description:
** Exercise 00 include
*/

#ifndef DROID_HPP_
#define DROID_HPP_

#include <iostream>
#include <string>
#include <cstring>
#include <new>

class Droid {
    private:
        std::string Id;
        size_t Energy = 50;
        size_t const Attack = 25;
        size_t const Toughness = 15;
        std::string *Status;
    public:
        Droid(std::string serial_number);
        Droid(Droid const &copy);
        Droid();
        ~Droid();
        void setEnergy(size_t energy);
        void setId(std::string serial_number);
        std::string getId() const;
        size_t getEnergy() const;
        size_t getAttack() const;
        size_t getToughness() const;
        std::string *getStatus() const;
        void setStatus(std::string *status);
        Droid &operator=(Droid &droid);
        Droid &operator<<(size_t &energy);
        bool operator!=(Droid const &droid) const;
        bool operator==(Droid const &droid) const;
    protected:
};

std::ostream &operator<<(std::ostream &flux, Droid &droid);

#endif /* !DROID_HPP_ */
