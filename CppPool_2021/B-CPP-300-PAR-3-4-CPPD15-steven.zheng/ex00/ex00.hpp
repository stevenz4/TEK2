/*
** EPITECH PROJECT, 2021
** Ex00
** File description:
** Exercise 00
*/

#ifndef EX00_HPP_
#define EX00_HPP_

#include <iostream>
#include <string>

template<typename s_t>
void swap(s_t &a, s_t &b)
{
    s_t c = a;

    a = b;
    b = c;
}

template<typename min_t>
min_t min(min_t a, min_t b)
{
    if (a < b)
        return a;
    else if (b < a)
        return b;
    else
        return b;
}

template<typename max_t>
max_t max(max_t a, max_t b)
{
    if (a < b)
        return b;
    else if (b < a)
        return a;
    else
        return b;
}

template<typename add_t>
add_t add(add_t a, add_t b)
{
    return a + b;
}


#endif /* !EX00_HPP_ */
