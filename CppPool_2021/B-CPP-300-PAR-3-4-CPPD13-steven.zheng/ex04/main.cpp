/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include "Picture.hpp"
#include "Toy.hpp"
#include "Buzz.hpp"
#include "Woody.hpp"
#include <memory>

// int main ()
// {
//     Toy toto;
//     Buzz buzz("Stevy", "B-CPP-300_d13/buzz.txt");
//     Toy ET(Toy::ALIEN, "green", "B-CPP-300_d13/alien.txt");

//     ET = buzz;
//     toto.setName("TOTO!");
//     if(toto.getType() == Toy::BASIC_TOY)
//         std::cout << " basic toy: " << toto.getName() << std::endl
//         << toto.getAscii() << std::endl;
//     if(ET.getType() == Toy::BUZZ)
//         std::cout << "this alien is: " << ET.getName() << std::endl
//         << ET.getAscii() << std::endl;
//     ET.speak("Yo man");
//     buzz.speak("Salut mon bro");
//     return 0;
// }

# include "Toy.hpp"
int main ()
{
Toy a ( Toy :: BASIC_TOY , "REX", "B-CPP-300_d13/rex.txt") ;
std :: cout << a ;
a << "\\o/";
std :: cout << a ;
}