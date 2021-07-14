/*
** EPITECH PROJECT, 2021
** main
** File description:
** Indie Studio
*/

#include "Core.hpp"

int main(void)
{
    try {
        Core Core; }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return(84);
    }
    return(0);
}
