/*
** EPITECH PROJECT, 2021
** Buzz
** File description:
** Exercise 02
*/

#ifndef BUZZ_HPP_
#define BUZZ_HPP_

#include "Toy.hpp"

class Buzz : public Toy {
    public:
        Buzz(std::string const &name, std::string const &filename = "buzz.txt");
        Buzz(Buzz const &copy);
        ~Buzz();
        void speak(std::string const &statement);
        bool speak_es(std::string const &statement);
    protected:
    private:
};

#endif /* !BUZZ_HPP_ */
