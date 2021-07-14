/*
** EPITECH PROJECT, 2021
** ex01
** File description:
** Exercise 01
*/

#ifndef EX01_HPP_
#define EX01_HPP_

#include <iostream>
#include <string>
#include <string.h>

template<typename c>
int compare(c const &a, c const &b)
{
    if (a > b)
        return 1;
    else if (a < b)
        return -1;
    else
        return 0;
}

template<>
int compare<const char *>(const char *const &a, const char *const &b)
{
    int result = strcmp(a, b);

    if (result < 0)
        return - 1;
    else if (result > 0)
        return 1;
    return result;
}

#endif /* !EX01_HPP_ */
