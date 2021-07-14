/*
** EPITECH PROJECT, 2021
** ex03
** File description:
** Exercise 03
*/

#ifndef EX03_HPP_
#define EX03_HPP_

#include <iostream>
#include <string>

template<typename T>
void foreach(T const *array, void (func)(const T &), int size)
{
    for (int j = 0; j < size; j++) {
        (*func)(array[j]);
    }
}

template<typename P>
void print(P const &p)
{
    std::cout << p << std::endl;
}

#endif /* !EX03_HPP_ */
