/*
** EPITECH PROJECT, 2021
** ex02
** File description:
** Exercise 02
*/

#ifndef EX02_HPP_
#define EX02_HPP_

#include <iostream>
#include <string>

template<typename min_t>
const min_t min(min_t const &a, min_t const &b)
{
    std::cout << "template min" << std::endl;
    if (a < b)
        return a;
    else if (b < a)
        return b;
    else
        return a;
}

int min(int a, int b)
{
    std::cout << "non-template min" << std::endl;
    if (a < b)
        return a;
    else if (b < a)
        return b;
    else
        return a;
}

template<typename tmin_t>
const tmin_t &templateMin(tmin_t const *a, int b)
{
    bool div_by_two = false;
    tmin_t &max = const_cast<tmin_t&>(a[0]);

    if (b % 2 == 0)
        div_by_two = true;
    if (div_by_two == true) {
        for (int j = 0; j < b; j += 2)
            max = min<tmin_t>(a[j], a[j + 1]);
    } else {
        max = a[0];
        for (int j = 1; j < (b - 1); j += 2)
            max = min<tmin_t>(a[j], a[j + 1]);
    }
    return max;
}

int nonTemplateMin(int *a, int b)
{
    bool div_by_two = false;
    int max = 0;

    if (b % 2 == 0)
        div_by_two = true;
    if (div_by_two == true) {
        for (int j = 0; j < b; j += 2)
            max = min(a[j], a[j + 1]);
    } else {
        max = a[0];
        for (int j = 1; j < (b - 1); j += 2)
            max = min(a[j], a[j + 1]);
    }
    return max;
}

#endif /* !EX02_HPP_ */
