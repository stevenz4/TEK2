/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include "ex02.hpp"
using namespace std;

int main(void)
{
    int tab [2] = {3 , 0};
    int minimum = templateMin(tab, 2);
    cout << " templateMin (tab , 2) = " << minimum << endl;
    minimum = nonTemplateMin(tab, 2);
    cout << " nonTemplateMin (tab , 2) = " << minimum << endl;
}