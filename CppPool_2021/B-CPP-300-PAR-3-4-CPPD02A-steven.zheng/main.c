/*
** EPITECH PROJECT, 2021
** Double List
** File description:
** Exercise 0
*/

#include "double_list.h"
#include "my.h"

static void populate_list ( double_list_t * list_head )
{
    double_list_add_elem_at_back ( list_head , 5.2) ;
    double_list_add_elem_at_back ( list_head , 42.5) ;
    double_list_add_elem_at_back ( list_head , 3.3) ;
}

static void test_size ( double_list_t list_head )
{
    printf (" There are %u elements in the list \n", double_list_get_size ( list_head ) ) ;
    double_list_dump ( list_head ) ;
}

static void test_del ( double_list_t * list_head )
{
    double_list_del_elem_at_back ( list_head ) ;
    printf (" There are %u elements in the list \n", double_list_get_size (* list_head ) ) ;
    double_list_dump (* list_head ) ;
}

int main ( void )
{
double_list_t list_head = NULL ;
populate_list (& list_head ) ;
double_list_del_elem_at_back(&list_head);
double_list_dump (list_head ) ;
return 0;
}