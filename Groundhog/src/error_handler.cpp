/*
** EPITECH PROJECT, 2021
** error handler
** File description:
** Groundhog
*/

#include "include/groundhog.hpp"

int isNumber(char *period)
{
    for (int j = 0; period[j] != '\0'; j++) {
        if (period[j] < 48 || period[j] > 57)
            return FAILURE;
    }
    return SUCCESS;
}

int checkIfNumber(std::string input)
{
    for (char c : input) {
        if (std::isdigit(c) == 0 && c != '.' && c != ',') {
            std::cout << "Not a number" << std::endl;
            return FAILURE;
        }
    }
    return SUCCESS;
}