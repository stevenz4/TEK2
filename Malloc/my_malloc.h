/*
** EPITECH PROJECT, 2021
** Malloc
** File description:
** include
*/

#ifndef MALLOC_H_
#define MALLOC_H_

#include <stdio.h>
#include <unistd.h>
#include <string.h>

typedef enum { false, true } bool;

typedef struct block_s {
    size_t size;
    bool free;
    struct block_s *next;
} block_t;

extern block_t *blk;

#define BLOCK_SIZE sizeof(block_t)
#define PAGE_SIZE getpagesize()

void *malloc(size_t size);
void free(void *ptr);
void *calloc(size_t nmemb, size_t size);
void *realloc(void *ptr, size_t size);
void *reallocarray(void *ptr, size_t nmemb, size_t size);

size_t resize(size_t size);

block_t *alloc_block(block_t *tmp, size_t size);
block_t *find_block(block_t *tmp, size_t size);
block_t *split_block(block_t *block, size_t size);

#endif /* !MALLOC_H_ */
