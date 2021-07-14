/*
** EPITECH PROJECT, 2021
** Tab to 2d Tab
** File description:
** Exercise 02
*/

#include <stdio.h>
#include <stdlib.h>

void tab_to_2dtab(const int * tab, int length, int width, int *** res)
{
    int count = 0;

    *res = malloc(sizeof(int *) * length + 1);
    for (int j = 0; j != length; j++)
        (*res)[j] = malloc(sizeof(int) * width);
    for (int j = 0; j != length; j++) {
        for (int k = 0; k != width; k++) {
            (*res)[j][k] = tab[count];
            count++;
        }
    }
}