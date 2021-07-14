/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include "Picture.hpp"
#include "Toy.hpp"

// int main(void)
// {
//     Toy test(BASIC_TOY, "Billy", "B-CPP-300_d13/alien.txt");

//     test.setAscii("B-CPP-300_d13/alien.txt");
//     std::cout << test.getAscii() << std::endl;
//     return 0;
// }

int main ()
{
    Toy toto;
    Toy ET(Toy::ALIEN, "green", "fjezfjzel");

    toto.setName("TOTO!");
    if(toto.getType() == Toy::BASIC_TOY)
        std::cout << " basic toy: " << toto.getName() << std::endl
        << toto.getAscii() << std::endl;
    if(ET.getType() == Toy::ALIEN)
        std::cout << "this alien is: " << ET.getName() << std::endl
        << ET.getAscii() << std::endl;
    return 0;
}