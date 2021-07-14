/*
** EPITECH PROJECT, 2021
** Double list
** File description:
** exercise 00_1 - all functions
*/

#include "double_list.h"
#include "my.h"

bool double_list_add_elem_at_position(double_list_t *front_ptr,
double elem, unsigned int position)
{
    doublelist_node_t *new_elem = malloc(sizeof(doublelist_node_t));
    double_list_t list = *front_ptr;

    if (new_elem == NULL || double_list_get_size(*front_ptr) < position)
        return true;
    if (position == 0) {
        double_list_add_elem_at_front(front_ptr, elem);
        return false;
    }
    for (unsigned int j = 0; j < position - 1 && list->next != NULL; j++)
        list = list->next;
    new_elem->value = elem;
    new_elem->next = list->next;
    list->next = new_elem;
    return false;
}

bool double_list_del_elem_at_front(double_list_t *front_ptr)
{
    double_list_t list = *front_ptr;

    if (double_list_get_size(*front_ptr) == 0)
        return true;
    (*front_ptr) = (*front_ptr)->next;
    free(list);
    return false;
}

bool double_list_del_elem_at_back(double_list_t *front_ptr)
{
    double_list_t list = *front_ptr;

    if (double_list_get_size(*front_ptr) == 0)
        return true;
    if (double_list_get_size(*front_ptr) == 1) {
        (*front_ptr) = NULL;
        return false;
    }
    while (list->next->next != NULL)
        list = list->next;
    list->next = NULL;
    return false;
}

bool double_list_del_elem_at_position(double_list_t *front_ptr,
unsigned int position)
{
    doublelist_node_t *new_elem = malloc(sizeof(doublelist_node_t));
    double_list_t list = *front_ptr;

    if (new_elem == NULL || double_list_get_size(*front_ptr) < position)
        return true;
    if (position == 0) {
        double_list_del_elem_at_front(front_ptr);
        return false;
    }
    for (unsigned int j = 0; j < position - 1 && list->next != NULL; j++)
        list = list->next;
    new_elem = list->next->next;
    list->next = new_elem;
    return false;
}

double double_list_get_elem_at_front(double_list_t list)
{
    if (list == NULL)
        return 0;
    else
        return list->value;
}