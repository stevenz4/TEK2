/*
** EPITECH PROJECT, 2021
** Append, At, Clear, Size
** File description:
** Exercise 02_03_04_05
*/

#include "string.h"

void append_s(string_t *this, const string_t *ap)
{
    if (ap->str) {
        this->str = realloc(this->str, sizeof(char) *
        (strlen(this->str) + strlen(ap->str)));
        strcat(this->str, ap->str);
    }
}

void append_c(string_t *this, const char *ap)
{
    if (ap) {
        if (this->str != NULL) {
            this->str = realloc(this->str, sizeof(char) *
            (strlen(this->str) + strlen(ap)));
            strcat(this->str, ap);
        } else
          this->str = strdup(ap);
    }
}

char at(const string_t *this, size_t pos)
{
    if (this->str == NULL)
        return -1;
    if (pos >= strlen(this->str))
        return -1;
    return this->str[pos];
}

void clear(string_t *this)
{
    memset(this->str, 0, 0);
}

int size(const string_t *this)
{
    if (this == NULL)
        return -1;
    return strlen(this->str);
}