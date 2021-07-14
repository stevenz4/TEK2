/*
** EPITECH PROJECT, 2021
** main
** File description:
** main function
*/

#include "Droid.hpp"

// int main(void)
// {
//     Droid test("Steven");
//     Droid test2("Bonjour");
    
//     test = test2;
//     test.setStatus(new std::string("Kill Kill Kill!"));
//     std::cout << test;
//     //std::cout << copy.getId() << std::endl;
//     return 0;
// }

int main ()
{
    Droid d;
    Droid d1("Avenger");
    bool test = true;

    size_t Durasel = 200;
    std::cout << d << std::endl;
    std::cout << d1 << std::endl;
    d = d1 ;
    d . setStatus (new std :: string ("Kill Kill Kill!") ) ;
    d << Durasel ;
    std :: cout << d << "--" << Durasel << std :: endl ;
    Droid d2 = d ;
    d . setId ("Rex") ;
    std :: cout << ( d2 != d ) << std :: endl ;
    return 0;
}