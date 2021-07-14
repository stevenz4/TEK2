/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "point.h"
#include <stdarg.h>
#include <new.h>
#include "int.h"

typedef struct
{
    Class   base;
    int     x;
}   IntClass;

static void Int_ctor(IntClass *this, va_list *args)
{
    this->x = va_arg((*args), int);
}

static void Int_dtor(IntClass *this)
{
    free(this->base.__str__);
    free(this->base.__add__);
}

static char *Print_string_int(IntClass *this)
{
    int buffer = 0;

    buffer = snprintf(NULL, 0, "<%s (%d)>", this->base.__name__, this->x);
    this->base.__str__ = malloc(sizeof(char) * buffer + 1);
    if (this->base.__str__ == NULL)
        raise("Out of memory");
    snprintf((char *)this->base.__str__, buffer + 1, "<%s (%d)>", this->base.__name__, this->x);
    return (char *)this->base.__str__;
}

static Object *Int_add(Object const *p1, Object const *p2)
{
    IntClass  *tmp[3];

    tmp[1] = (IntClass *)p1;
    tmp[2] = (IntClass *)p2;
    if (strcmp(tmp[1]->base.__name__, tmp[2]->base.__name__) != 0)
        raise("Add aborted, objects aren't Int");
    tmp[3] = new(Int);
    tmp[3]->x = tmp[1]->x + tmp[2]->x;
    return (tmp[3]);
}

static const IntClass _description = {
    {
        .__size__ = sizeof(IntClass),
        .__name__ = "Int",
        .__ctor__ = (ctor_t)&Int_ctor,
        .__dtor__ = (dtor_t)&Int_dtor,
        .__str__ = (to_string_t)&Print_string_int,
        .__add__ = (binary_operator_t)&Int_add,
        .__sub__ = NULL,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
};

const Class   *Int = (const Class *)&_description;
