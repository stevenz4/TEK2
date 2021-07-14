/*
** EPITECH PROJECT, 2021
** Main
** File description:
** main
*/

#include "Skat.hpp"

int main(void)
{
    Skat s("Junior", 5) ;
    std::cout << "Soldier " << s.name() << std::endl;
    s.status();
    s.useStimPaks();
    return 0;
}