/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 02
*/

#include <stdarg.h>
#include <stdio.h>
#include "vertex.h"
#include "new.h"

typedef struct
{
    Class   base;
    int     x, y, z;
}   VertexClass;

static void Vertex_ctor(VertexClass *this, va_list *args)
{
    if (!args || !this)
        raise("Out of memory");
    this->x = va_arg((*args), int);
    this->y = va_arg((*args), int);
    this->z = va_arg((*args), int);
}

static void Vertex_dtor(VertexClass *this)
{
    this->base.__str__ = NULL;
    free(this->base.__str__);
}

static char *Print_string_vertex(VertexClass *this)
{
    int buffer = 0;
    char *str;

    buffer = snprintf(NULL, 0, "<%s (%d, %d, %d)>", this->base.__name__, this->x, this->y, this->z);
    if (this->base.__str__ != NULL) {
        str = NULL;
    }
    str = malloc(sizeof(char) * buffer + 1);
    if (str == NULL)
        raise("Out of memory");
    snprintf(str, buffer + 1, "<%s (%d, %d, %d)>", this->base.__name__, this->x, this->y, this->z);
    return str;
}

static Object *Vertex_add(Object const *v1, Object const *v2)
{
    VertexClass  *tmp[3];

    tmp[1] = (VertexClass *)v1;
    tmp[2] = (VertexClass *)v2;
    tmp[3] = new(Vertex);
    tmp[3]->x = tmp[1]->x + tmp[2]->x;
    tmp[3]->y = tmp[1]->y + tmp[2]->y;
    tmp[3]->z = tmp[1]->z + tmp[2]->z;
    return (tmp[3]);
}

static Object *Vertex_sub(Object const *v1, Object const *v2)
{
    VertexClass  *tmp[3];

    tmp[1] = (VertexClass *)v1;
    tmp[2] = (VertexClass *)v2;
    tmp[3] = new(Vertex);
    tmp[3]->x = tmp[1]->x - tmp[2]->x;
    tmp[3]->y = tmp[1]->y - tmp[2]->y;
    tmp[3]->z = tmp[1]->z - tmp[2]->z;
    
    return (tmp[3]);
}

static const VertexClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(VertexClass),
        .__name__ = "Vertex",
        .__ctor__ = (ctor_t)&Vertex_ctor,
        .__dtor__ = (dtor_t)&Vertex_dtor,
        .__str__ = (to_string_t)&Print_string_vertex,
        .__add__ = (binary_operator_t)&Vertex_add,
        .__sub__ = (binary_operator_t)&Vertex_sub,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0,
    .z = 0
};

const Class *Vertex = (const Class *)&_description;
