/*
** EPITECH PROJECT, 2021
** Woody
** File description:
** Exercise 02
*/

#ifndef WODDY_HPP_
#define WODDY_HPP_

#include "Toy.hpp"

class Woody : public Toy {
    public:
        Woody(std::string const &name, std::string const &filename = "woody.txt");
        Woody(Woody const &copy);
        ~Woody();
        void speak(std::string const &statement);
    protected:
    private:
};

#endif /* !WODDY_HPP_ */
