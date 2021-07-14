/*
** EPITECH PROJECT, 2021
** ex05
** File description:
** Exercise 05
*/

#ifndef EX05_HPP_
#define EX05_HPP_

#include <iostream>
#include <string>

template<typename T>
class array {
    array();
    array(unsigned int n);
    array(array const &copy);
    array &operator=(array const &copy) const;
};

#endif /* !EX05_HPP_ */
