/*
** EPITECH PROJECT, 2021
** main function
** File description:
** Groundhog
*/

#include "include/groundhog.hpp"

int checker = 0;
std::vector<float> weirdValue;

int print_values(std::vector<float> global, int count, int value, int period)
{
    if (value >= period) {
        if (value % period == 0)
            weirdest_value(global, value, period);
        average_func(global, value, period);
        percentage(global, value,period);
    } if (value >= (period - 1)) {
        standard_deviation(global, value, period);
        count = check_occurs(count);
    } else {
        std::cout << "g=nan\tr=nan%\ts=nan" << std::endl;
    }
    return count;
}

int waitInput(int period)
{
    std::string input;
    std::vector<float> global;
    float average = 0.0;
    int value = 0;
    int count = 0;

    while (1) {
        std::cin >> input;
        if (input == "STOP") {
            std::cout << "Global tendency switched " << count << " times" << std::endl;
            sort(weirdValue.begin(), weirdValue.end());
            std::cout << "5 weirdest values are [";
            for (int j = 0; j < weirdValue.size(); j++) {
                if (j + 1 == weirdValue.size())
                    std::cout << weirdValue[j];
                else    
                    std::cout << weirdValue[j] << ", ";
            }
            std::cout << "]" << std::endl;
            return SUCCESS;
        }
        if (checkIfNumber(input) == FAILURE || std::cin.eof())
            return FAILURE;
        global.push_back(atof(input.c_str()));
        count = print_values(global, count, value, period);
        value++;
    }
    return SUCCESS;
}

int main(int ac, char **av)
{
    if (ac != 2) {
        std::cout << "SYNOPSIS:\n\t./groundhog period\n\nDESCRIPTION:\n\tperiod\tthe number of days defining a period" << std::endl;
        return FAILURE;
    } if (isNumber(av[1]) == FAILURE)
        return FAILURE;
    if (atoi(av[1]) <= 0)
        return FAILURE;
    return waitInput(atoi(av[1]));
}