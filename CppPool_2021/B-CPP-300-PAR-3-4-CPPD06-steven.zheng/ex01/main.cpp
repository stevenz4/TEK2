/*
** EPITECH PROJECT, 2021
** Temperature Conversion
** File description:
** Exercise 01
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <sstream>

int main (void)
{
    std::string input;
    std::string type;
    float value;
    float celsius = 0;
    float fahrenheit = 0;

    std::cin >> value;
    std::cin >> type;
    if ((type.compare("Fahrenheit")) == 0) {
        celsius = 5.0 / 9.0 * (value - 32);
        std::cout << std::setw(16) << std::fixed << std::setprecision(3) << celsius << std::setw(16) << "Celsius" << std::endl;
    }
    if ((type.compare("Celsius")) == 0) {
        fahrenheit = value * (9.0 / 5.0) + 32;
        std::cout << std::setw(16) << std::fixed << std::setprecision(3) << fahrenheit <<  std::setw(16) << "Fahrenheit" << std::endl;
    }
    return 0;
}