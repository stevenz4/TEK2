/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** my include file
*/

#ifndef MY_H_
#define MY_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct string_struct_t {
    char *str;
    void (*string_init) (struct string_struct_t *, const char *);
    void (*string_destroy) (struct string_struct_t *);
    void (*assign_s) (struct string_struct_t *, const struct string_struct_t *);
    void (*assign_c) (struct string_struct_t *, const char *);
    void (*append_s) (struct string_struct_t *, const struct string_struct_t *);
    void (*append_c)(struct string_struct_t *, const char *);
    char (*at) (const struct string_struct_t *, size_t);
    void (*clear) (struct string_struct_t *);
    int (*size) (const struct string_struct_t *);
    int (*compare_s) (const struct string_struct_t *,
    const struct string_struct_t *);
    int (*compare_c) (const struct string_struct_t *, const char *);
    size_t (*copy) (const struct string_struct_t *, char *, size_t, size_t);
    const char *(*c_star) (const struct string_struct_t *);
    int (*empty) (const struct string_struct_t *);
} string_t;

void string_init(string_t *this, const char *s);
void string_destroy(string_t *this);

void assign_s(string_t *this, const string_t *str);
void assign_c(string_t *this, const char *s);

void append_s(string_t *this, const string_t *ap);
void append_c(string_t *this, const char *ap);

char at(const string_t *this, size_t pos);

void clear(string_t *this);

int size(const string_t *this);

int compare_s(const string_t *this, const string_t *str);
int compare_c(const string_t *this, const char *str);

size_t copy(const string_t *this, char *s, size_t n, size_t pos);

const char *c_star(const string_t *this);

int empty(const string_t *this);

#endif
