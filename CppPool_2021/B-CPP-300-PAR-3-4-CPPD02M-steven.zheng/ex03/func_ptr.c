/*
** EPITECH PROJECT, 2021
** Func PTR
** File description:
** Exercise 03
*/

#include "func_ptr.h"
#include "func_ptr_enum.h"

void print_normal(const char *str)
{
    printf("%s\n", str);
}

void print_reverse(const char *str)
{
    for (int j = strlen(str) - 1; j != -1; j--)
        printf("%c", str[j]);
    printf("\n");
}

void print_upper(const char *str)
{
    for (int j = 0; str[j] != '\0'; j++) {
        if (str[j] >= 'a' && str[j] <= 'z')
            printf("%c", str[j] - 32);
        else
            printf("%c", str[j]);
    }
    printf("\n");
}

void print_42(const char *str)
{
    printf("42\n");
}

void do_action(action_t action, const char *str)
{
    ptr_s print[] = {
        {&print_normal, PRINT_NORMAL},
        {&print_reverse, PRINT_REVERSE},
        {&print_upper, PRINT_UPPER},
        {&print_42, PRINT_42},
    };

    for (int j = 0; j < 4; j++) {
        if (print[j].action == action)
            print[j].ptr(str);
    }
}

int main ( void )
{
const char * str = "I'm using function pointers !";
do_action ( PRINT_NORMAL , str ) ;
do_action ( PRINT_REVERSE , str ) ;
do_action ( PRINT_UPPER , str ) ;
do_action ( PRINT_42 , str ) ;
return (0) ;
}