/*
** EPITECH PROJECT, 2021
** Main function
** File description:
** main
*/

#include "string.h"

int main ( void )
{
    string_t s;
    string_t str;
    char *temp;

    //string_init(&s, NULL);
    string_init(&str, "Yo man");

    printf("%d\n", empty(&s));
    string_destroy(&s);
    string_destroy(&str);
    return (0) ;
}