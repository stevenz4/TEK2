/*
** EPITECH PROJECT, 2021
** find
** File description:
** Exercise 00
*/

#ifndef FIND_HPP_
#define FIND_HPP_

#include <algorithm>

template<typename T>
typename T::iterator do_find(T &b, int a)
{
    return (std::find(b.begin(), b.end(), a));
}


#endif /* !FIND_HPP_ */
