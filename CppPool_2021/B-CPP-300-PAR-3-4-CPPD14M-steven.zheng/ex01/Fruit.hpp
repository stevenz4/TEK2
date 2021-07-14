/*
** EPITECH PROJECT, 2021
** Fruit
** File description:
** Exercise 00
*/

#ifndef FRUIT_HPP_
#define FRUIT_HPP_

#include <string>
#include <iostream>

class Fruit {
    public:
        Fruit();
        Fruit(std::string const &name, int vitamins);
        ~Fruit();
        std::string getName() const;
        int getVitamins() const;
    protected:
        std::string _name;
        int _vitamins;
    private:
};

#endif /* !FRUIT_HPP_ */
