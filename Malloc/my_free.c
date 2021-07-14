/*
** EPITECH PROJECT, 2021
** free
** File description:
** Malloc
*/

#include "my_malloc.h"

void free(void *ptr)
{
    block_t *tmp;

    if (ptr) {
        if ((block_t *)ptr > blk && ptr < sbrk(0)) {
            tmp = ptr - BLOCK_SIZE;
            tmp->free = true;
        }
    }
}