/*
** EPITECH PROJECT, 2021
** Little Pony and Teddy
** File description:
** Rush2
*/

#ifndef TOY_HPP_
#define TOY_HPP_

#include "Object.hpp"

class Toy : public Object {
    public:
        Toy(std::string title);
        ~Toy();
    protected:
    private:
};

class Teddy : public Toy {
    public:
        Teddy(std::string title);
        ~Teddy();
        virtual void isTaken();
    protected:
    private:
};

class Pony : public Toy {
    public:
        Pony(std::string title);
        ~Pony();
        virtual void isTaken();
    protected:
    private:
};

#endif /* !TOY_HPP_ */
