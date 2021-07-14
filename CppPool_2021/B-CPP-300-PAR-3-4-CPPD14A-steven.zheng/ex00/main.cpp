/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include "Errors.hpp"

int main(void)
{
    UserError test("Salut", "ok");

    std::cout << test.what() << std::endl;
    return 0;
}