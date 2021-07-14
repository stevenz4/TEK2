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
Woody w (" wood ") ;
if ( w . setAscii (" file_who_does_not_exist .txt ") == false )
{
auto e = w . getLastError () ;
if ( e.type == Toy :: Error :: PICTURE )
{
std :: cout << " Error in " << e . where () << ": " << e . what () <<
std :: endl ;
}
}
if ( w . speak_es (" Woody does not have spanish mode ") == false )
{
auto e = w . getLastError () ;
if ( e.type == Toy :: Error :: SPEAK )
{
std :: cout << " Error in " << e . where () << ": " << e . what () <<
std :: endl ;
}
}
if ( w . speak_es (" Woody does not have spanish mode ") == false )
{
auto e = w . getLastError () ;
if ( e.type == Toy :: Error :: SPEAK )
{
std :: cout << " Error in " << e . where () << ": " << e . what () <<
std :: endl ;
}
}
}