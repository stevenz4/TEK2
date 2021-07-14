/*
** EPITECH PROJECT, 2021
** The menger sponge
** File description:
** exercise 01
*/

#include "menger.h"

int main(int ac, char **av)
{
    int size = 0, levels = 0, x = 0, y = 0;

    if (ac != 3 || check_arg(ac, av) == 84)
        return 84;
    size = atoi(av[1]);
    levels = atoi(av[2]);
    if (size > levels && size >= 0 && size >= pow(3, levels))
        recursive_block(size, levels, x, y);
    else
        return 84;
    return 0;
}

int check_arg(int ac, char **av)
{
    for (int j = 1; j < ac; j++) {
        for (int k = 0; av[j][k] != '\0'; k++) {
            if (!isdigit(av[j][k])) {
                return 84;
            }
        }
    }
    return 0;
}
