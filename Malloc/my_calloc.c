/*
** EPITECH PROJECT, 2021
** calloc
** File description:
** Malloc
*/

#include "my_malloc.h"

void *calloc(size_t nmemb, size_t size)
{
    void *new;

    if (nmemb == 0 || size == 0)
        return NULL;
    new = malloc(nmemb * size);
    if (new)
        memset(new, 0, nmemb * size);
    return new;
}