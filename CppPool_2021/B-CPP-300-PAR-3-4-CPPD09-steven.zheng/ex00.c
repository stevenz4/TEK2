/*
** EPITECH PROJECT, 2021
** Back to basics
** File description:
** Exercise 09
*/

#include "ex00.h"

cthulhu_t *new_cthulhu()
{
    cthulhu_t *new = malloc(sizeof(cthulhu_t));

    cthulhu_initializer(new);
    return new;
}

static void cthulhu_initializer(cthulhu_t *this)
{
    printf("----\n");
    this->m_name = strdup("Cthulhu");
    this->m_power = 42;
    printf("Building %s\n", this->m_name);
}

void print_power(cthulhu_t *this)
{
     printf("Power => %d\n", this->m_power);
}

void attack(cthulhu_t *this)
{
    if (this->m_power >= 42) {
        printf("%s attacks and destroys the city\n", this->m_name);
        this->m_power = this->m_power - 42;
    } else {
        printf("%s can't attack, he doesn't have enough power\n", this->m_name);
    }
}

void sleeping(cthulhu_t *this)
{
    this->m_power = this->m_power + 42000;
    printf("%s sleeps\n", this->m_name);
}

koala_t *new_koala(char *name, char is_a_legend)
{
    koala_t *new = malloc(sizeof(koala_t));

    koala_initializer(new, name, is_a_legend);
    return new;
}

static void koala_initializer(koala_t *this, char *_name, char _is_A_Legend)
{
    this->m_parent = *new_cthulhu();
    this->m_parent.m_name = strdup(_name);
    this->m_is_a_legend = _is_A_Legend;
    if (_is_A_Legend == 0)
        this->m_parent.m_power = 0;
    printf("Building %s\n", this->m_parent.m_name);
}

void eat(koala_t *this)
{
    this->m_parent.m_power = this->m_parent.m_power + 42;
    printf("%s eats\n", this->m_parent.m_name);
}