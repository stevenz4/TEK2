/*
** EPITECH PROJECT, 2021
** Toy
** File description:
** Exercise 01
*/

#ifndef TOY_HPP_
#define TOY_HPP_

#include <string>
#include <iostream>

#include "Picture.hpp"

class Toy {
    public:
        enum ToyType {
            BASIC_TOY,
            ALIEN,
        };
        Toy(ToyType type, std::string const &name, std::string const &filename);
        Toy(Toy const &copy);
        Toy();
        ~Toy();
        int getType() const;
        std::string getName() const;
        std::string getAscii() const;
        void setName(std::string const &name);
        bool setAscii(std::string const &filename);
        Picture _picture;
        Toy &operator=(Toy const &toy);
    protected:
    private:
        ToyType _type;
        std::string _name;
};

#endif /* !TOY_HPP_ */
