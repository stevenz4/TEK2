/*
** EPITECH PROJECT, 2021
** Back to basics
** File description:
** Exercise 09
*/

#ifndef EX00_H_
#define EX00_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct cthulhu_s {
    char *m_name;
    int m_power;
} cthulhu_t;

typedef struct koala_s {
    cthulhu_t m_parent;
    char m_is_a_legend;
} koala_t;

cthulhu_t *new_cthulhu();
static void cthulhu_initializer(cthulhu_t *);
void print_power(cthulhu_t *this);
void attack(cthulhu_t *this);
void sleeping(cthulhu_t *this);

koala_t *new_koala(char *name, char is_a_legend);
static void koala_initializer(koala_t *this, char *_name, char _is_A_Legend);
void eat(koala_t *this);

#endif
