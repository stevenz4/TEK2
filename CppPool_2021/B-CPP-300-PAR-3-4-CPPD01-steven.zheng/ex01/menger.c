/*
** EPITECH PROJECT, 2021
** The Menger Sponge
** File description:
** exercise 01 menger recursive
*/

#include "menger.h"

int recursive_block(int size, int levels, int x, int y)
{
    int block = size / 3;
    int two_block = block * 2;

    printf("%03d %03d %03d\n", block, x + block, y + block);
    if (levels > 0 && levels != 1) {
        levels = levels - 1;
        recursive_block(block, levels, x, y);
        recursive_block(block, levels, x, y + block);
        recursive_block(block, levels, x, y + two_block);
        recursive_block(block, levels, x + block, y);
        recursive_block(block, levels, x + block, y + two_block);
        recursive_block(block, levels, x + two_block, y);
        recursive_block(block, levels, x + two_block, y + block);
        recursive_block(block, levels, x + two_block, y + two_block);
    }
    return 0;
}
