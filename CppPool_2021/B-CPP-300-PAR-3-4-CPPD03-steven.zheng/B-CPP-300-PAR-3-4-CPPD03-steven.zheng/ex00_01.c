/*
** EPITECH PROJECT, 2021
** My String
** File description:
** Exercise 00_01
*/

#include "string.h"

void string_init(string_t *this, const char *s)
{
    if (this) {
        if (s)
            this->str = strdup(s);
        else
            this->str = NULL;
        this->string_init = &string_init;
        this->string_destroy = &string_destroy;
        this->assign_s = &assign_s;
        this->assign_c = &assign_c;
        this->append_s = &append_s;
        this->append_c = &append_c;
        this->at = &at;
        this->clear = &clear;
        this->size = &size;
        this->compare_s = &compare_s;
        this->compare_c = &compare_c;
        this->copy = &copy;
        this->c_star = &c_star;
        this->empty = &empty;
    }
}

void string_destroy(string_t *this)
{
    if (this && this->str)
        free(this->str);
}

void assign_s(string_t *this, const string_t *str)
{
    if (this && str) {
        string_destroy(this);
        if (str->str)
            this->str = strdup(str->str);
        else
            this->str = NULL;
    }
}

void assign_c(string_t *this, const char *s)
{
    if (this) {
        string_destroy(this);
        if (s)
            this->str = strdup(s);
        else
            this->str = NULL;
    }
}