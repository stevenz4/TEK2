/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 01
*/

#include "new.h"
#include "player.h"
#include "point.h"
#include "vertex.h"
#include <stdlib.h>

Object *new(const Class *class, ...)
{
    Class *new_obj;
    va_list parameters;

    if (class == NULL)
        raise("Out of memory");
    va_start(parameters, class);
    new_obj = va_new(class, &parameters);
    va_end(parameters);
    return new_obj;
}

Object *va_new(const Class *class, va_list *ap)
{
    Class *new_obj = malloc(class->__size__);

    if (new_obj == NULL)
        raise("Out of memory");
    memcpy(new_obj, class, class->__size__);
    if (new_obj->__ctor__ == NULL)
        raise("Error on constructor");
    new_obj->__ctor__(new_obj, ap);
    return new_obj;
}

void delete(Object *ptr)
{
    Class *temp;

    if (ptr == NULL)
        raise("Out of memory");
    temp = (Class*)ptr;
    if (temp->__dtor__ != NULL)
        temp->__dtor__(temp);
    free(temp);
    temp = NULL;
}