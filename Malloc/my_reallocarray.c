/*
** EPITECH PROJECT, 2021
** Reallocarray
** File description:
** Malloc
*/

#include "my_malloc.h"

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    ptr = malloc(nmemb * size);
    return ptr;
}