/*
** EPITECH PROJECT, 2021
** Double list
** File description:
** exercise 00_2 - all functions
*/

#include "double_list.h"
#include "my.h"

double double_list_get_elem_at_back(double_list_t list)
{
    if (list == NULL)
        return 0;
    while (list->next != NULL)
        list = list->next;
    return list->value;
}

double double_list_get_elem_at_position(double_list_t list,
unsigned int position)
{
    if (double_list_get_size(list) < position)
        return true;
    if (position == 0)
        return double_list_get_elem_at_front(list);
    for (unsigned int j = 0; j < position && list->next != NULL; j++)
        list = list->next;
    return list->value;
}

doublelist_node_t *double_list_get_first_node_with_value(double_list_t list,
double value)
{
    bool value_exist = false;

    if (list == NULL)
        return NULL;
    while (list->next != NULL && value_exist == false) {
        if (list->next->value == value)
            value_exist = true;
        list = list->next;
    }
    if (value_exist == true)
        return list;
    else
        return NULL;
}