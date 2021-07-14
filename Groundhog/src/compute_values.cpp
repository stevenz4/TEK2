/*
** EPITECH PROJECT, 2021
** Compute values
** File description:
** Groundhog
*/

#include "include/groundhog.hpp"

void weirdest_value(std::vector<float> global, int value, int period)
{
    std::vector<float> global_7;
    float Q1 = 0;
    float Q3 = 0;
    float Inter = 0;
    float InterL = 0;
    float InterSup = 0;
    float InterInf = 0;

    for (int j = 0; j < period; j++)
        global_7.push_back(global[value - 7 + j]);
    sort(global_7.begin(), global_7.end());
    if (global_7.size() % 4 == 0) {
        Q1 = global_7[global_7.size() / 4 - 1];
        Q3 = global_7[3 * global_7.size() / 4 - 1];
    } else {
        Q1 = global_7[global_7.size() / 4];
        Q3 = global_7[3 * global_7.size() / 4];
    }
    Inter = Q3 - Q1;
    InterInf = Q1 - Inter * 0.8;
    InterSup = Q3 + Inter * 0.8;
    for (int j = 0; j < period; j++)
        if (global_7[j] <= InterInf || global_7[j] >= InterSup)
            if (std::find(weirdValue.begin(), weirdValue.end(), global_7[j]) == weirdValue.end())
                weirdValue.push_back(global_7[j]);
}

int check_occurs(int count)
{
    if (checker == 1) {
        printf("\ta switch occurs\n");
        checker = 0;
        count++;
        return count;
    }
    else
        printf("\n");
    return(count);
}

void percentage(std::vector<float> global, int value, int per)
{
    int value2 = value - per;
    float x = global.at(value);
    float y = global.at(value2);
    float res = ((x - y) / y) * 100;
    float res2 = 0.0;
    printf("\tr=%1.f%%", res);
    if (value == per) {
        checker = 0;
    }
    else {
        x = global.at(value - 1);
        y = global.at(value2 - 1);
        res2 = ((x - y) / y) * 100;
        if (res2 > 0 && res < 0)
            checker = 1;
        if (res2 < 0 && res > 0)
            checker = 1;
    }
}

float standard_deviation(std::vector<float> global, int value, int period)
{
    int index = value - (period - 1);
    float average = 0;
    float result = 0;

    for (int j = index; j < index + period; j++)
        average = average + global.at(j);
    average = average / period;
    for (int j = index; j < index + period; j++)
        result = result + pow((global.at(j) - average), 2);
    result = sqrt(result / period);
    if (value == period - 1)
        printf("g=nan\tr=nan%\ts=%.2f",result);
    else
        printf("\ts=%.2f",result);
    return SUCCESS;
}

void average_func(std::vector<float> global, int value,int av)
{
    int value2 = value - av;
    int count = 0;
    float x = 0.0;
    float y = 0.0;
    float z = 0.0;
    float average = 0.0;
    
    while (count < av) {
        x = global.at(value2);
        value2++;
        y = global.at(value2);
        z = y - x;
        if (z > 0.0)
            average += z;
        count++;
    }
    average = average / av;
    printf("g=%.2f",average);
}

