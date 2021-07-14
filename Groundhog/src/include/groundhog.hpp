/*
** EPITECH PROJECT, 2021
** groundhob include
** File description:
** Groundhog
*/

#ifndef GROUNDHOG_HPP_
#define GROUNDHOG_HPP_

#include <string>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

extern int checker;
extern std::vector<float> weirdValue;

#define FAILURE 84
#define SUCCESS 0

#define RESET   "\033[0m"
#define YELLOW  "\033[33m"

int waitInput(int period);
void average_func(std::vector<float> global, int value,int av);
float standard_deviation(std::vector<float> global, int value, int period);
void percentage(std::vector<float> global, int value,int per);
int check_occurs(int count);
void weirdest_value(std::vector<float> global, int value, int period);

int isNumber(char *period);
int checkIfNumber(std::string input);
int handle_input(std::string input, int count);


#endif /* !GROUNDHOG_HPP_ */
