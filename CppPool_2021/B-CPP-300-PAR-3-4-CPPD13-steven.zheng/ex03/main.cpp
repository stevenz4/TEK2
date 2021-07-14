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

int main ()
{
std :: unique_ptr < Toy > b (new Buzz (" buzziiiii ") ) ;
std :: unique_ptr < Toy > w (new Woody (" wood ") ) ;
std :: unique_ptr < Toy > t (new Toy ( Toy :: ALIEN , "ET", " alien .txt") ) ;
b -> speak ("To the code , and beyond !!!!!!!! ") ;
w -> speak (" There 's a snake in my boot .") ;
t -> speak ("the claaaaaaw ") ;
}