/*
** EPITECH PROJECT, 2021
** realloc
** File description:
** Malloc
*/

#include "my_malloc.h"

void *realloc(void *ptr, size_t size)
{
    if (size == 0)
        free(ptr);
    if (ptr == NULL)
        return malloc(size);
    ptr = malloc(size);
    return ptr;
}