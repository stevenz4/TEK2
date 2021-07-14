/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 02
*/

#include <stdio.h>
#include <stdarg.h>
#include "point.h"
#include "new.h"
typedef struct
{
    Class   base;
    int     x, y;
}   PointClass;

static void Point_ctor(PointClass *this, va_list *args)
{
    if (!args || !this)
        raise("Out of memory");
    this->x = va_arg((*args), int);
    this->y = va_arg((*args), int);
}

static void Point_dtor(PointClass *this)
{
    this->base.__str__ = NULL;
    free(this->base.__str__);
}

static char *Print_string_point(PointClass *this)
{
    int buffer = 0;
    char *str;

    buffer = snprintf(NULL, 0, "<%s (%d, %d)>", this->base.__name__, this->x, this->y);
    if (this->base.__str__ != NULL) {
        str = NULL;
    }
    str = malloc(sizeof(char) * buffer + 1);
    if (str == NULL)
        raise("Out of memory");
    snprintf(str, buffer + 1, "<%s (%d, %d)>", this->base.__name__, this->x, this->y);
    return str;
}

static Object *Point_add(Object const *p1, Object const *p2)
{
    PointClass  *tmp[3];

    tmp[1] = (PointClass *)p1;
    tmp[2] = (PointClass *)p2;
    tmp[3] = new(Point);
    tmp[3]->x = tmp[1]->x + tmp[2]->x;
    tmp[3]->y = tmp[1]->y + tmp[2]->y;
    return (tmp[3]);
}

static Object *Point_sub(Object const *p1, Object const *p2)
{
    PointClass  *tmp[3];

    tmp[1] = (PointClass *)p1;
    tmp[2] = (PointClass *)p2;
    tmp[3] = new(Point);
    tmp[3]->x = tmp[1]->x - tmp[2]->x;
    tmp[3]->y = tmp[1]->y - tmp[2]->y;
    return (tmp[3]);
}

static const PointClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(PointClass),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&Point_ctor,
        .__dtor__ = (dtor_t)&Point_dtor,
        .__str__ = (to_string_t)&Print_string_point,
        .__add__ = (binary_operator_t)&Point_add,
        .__sub__ = (binary_operator_t)&Point_sub,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};

const Class *Point = (const Class *)&_description;