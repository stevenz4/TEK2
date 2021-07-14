/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include "Picture.hpp"
#include "Toy.hpp"

int main ()
{
    Toy toto;
    Toy ET(Toy::ALIEN, "green", "B-CPP-300_d13/alien.txt");
    Toy ok(Toy::ALIEN, "violet", "B-CPP-300_d13/rex.txt");

    toto = ET = ok;
    std::cout << toto.getAscii() << std::endl;
    return 0;
}