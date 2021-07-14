/*
** EPITECH PROJECT, 2021
** Func PTR
** File description:
** Exercise 03 Include
*/

#ifndef FUNC_PTR_H_

#define FUNC_PTR_H_

#include <stdio.h>
#include <string.h>
#include "func_ptr_enum.h"

typedef struct ptr_function {
    void (*ptr) (const char *str);
    action_t action;
} ptr_s;

void print_normal(const char *str);
void print_reverse(const char *str);
void print_upper(const char *str);
void print_42(const char *str);
void do_action(action_t action, const char *str);

#endif