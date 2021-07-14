/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include "find.hpp"
#include <iostream>
#include <string>
#include <vector>

int main(void)
{
    std::vector<int> v = {1, 5, 8, 64};
    std::vector<int>::iterator it = do_find(v, 5);
    int count = 0;

    count = it - v.begin();
    std::cout << count << std::endl;
}