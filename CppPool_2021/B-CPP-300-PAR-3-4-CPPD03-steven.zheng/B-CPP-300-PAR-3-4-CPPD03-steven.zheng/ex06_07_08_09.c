/*
** EPITECH PROJECT, 2021
** Compare, Copy, C_star, Empty
** File description:
** Exercise 06_07_08_09
*/

#include "string.h"

int compare_s(const string_t *this, const string_t *str)
{
    return strcmp(this->str, str->str);
}

int compare_c(const string_t *this, const char *str)
{
    return strcmp(this->str, str);
}

size_t copy(const string_t *this, char *s, size_t n, size_t pos)
{
    int s_count = 0;
    int this_count = 0;

    if (((strlen(this->str) - n) == pos)) {
        s = malloc(sizeof(char) * n);
        if (s == NULL)
            return 0;
        for (this_count = pos; this_count < (int)strlen(this->str);
        this_count++) {
            s[s_count] = this->str[this_count];
            s_count++;
        }
        s[s_count] = '\0';
        return s_count;
    }
    return 0;
}

const char *c_star(const string_t *this)
{
    if (this)
        return (this->str);
    return (NULL);
}

int empty(const string_t *this)
{
    if (this->str)
        return strlen(this->str);
    return 0;
}