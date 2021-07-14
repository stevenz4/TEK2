/*
** EPITECH PROJECT, 2021
** Double list
** File description:
** exercise 00_0 - all functions
*/

#include "double_list.h"
#include "my.h"

unsigned int double_list_get_size(double_list_t list)
{
    unsigned int size = 0;

    while (list != NULL) {
        size++;
        list = list->next;
    }
    return size;
}

bool double_list_is_empty(double_list_t list)
{
    unsigned int size = 0;

    while (list != NULL) {
        size++;
        list = list->next;
    }
    if (size == 0)
        return true;
    else
        return false;
}

void double_list_dump(double_list_t list)
{
    while (list != NULL) {
        printf("%f\n", list->value);
        list = list->next;
    }
}

bool double_list_add_elem_at_front(double_list_t *front_ptr, double elem)
{
    double_list_t new_elem = malloc(sizeof(double_list_t));

    if (new_elem == NULL)
        return true;
    new_elem->value = elem;
    new_elem->next = *front_ptr;
    *front_ptr = new_elem;
    return false;
}

bool double_list_add_elem_at_back(double_list_t *front_ptr, double elem)
{
    doublelist_node_t *new_elem = malloc(sizeof(doublelist_node_t));
    double_list_t list = *front_ptr;

    if (new_elem == NULL)
        return true;
    new_elem->next = NULL;
    new_elem->value = elem;
    if (list != NULL) {
        while (list->next != NULL) {
            list = list->next;
        }
        list->next = new_elem;
    } else
        (*front_ptr) = new_elem;
    return false;
}