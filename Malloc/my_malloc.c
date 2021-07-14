/*
** EPITECH PROJECT, 2021
** my_malloc.c
** File description:
** Malloc
*/

#include "my_malloc.h"

block_t *blk = NULL;

size_t resize(size_t size)
{
    size_t size_pow = 2;
    size_t twoPage = PAGE_SIZE * 2;
    size_t nb_Twopage = twoPage;

    while (size_pow < size)
        size_pow = size_pow * 2;
    if (size_pow < twoPage)
        size_pow = twoPage;
    else {
        while (nb_Twopage < size_pow)
            nb_Twopage = nb_Twopage + twoPage;
        size_pow = nb_Twopage;
    }
    return size_pow;
}

void *malloc(size_t size)
{
    block_t *tmp = blk;

    size = resize(size);
    if (tmp) {
        tmp = find_block(tmp, size);
        if (tmp && (tmp->size - size) >= (sizeof(tmp) + 4))
            tmp = split_block(tmp, size);
        else
            tmp = alloc_block(tmp, size);
    } else {
        tmp = alloc_block(tmp, size);
        blk = tmp;
    }
    return ((char*)tmp + sizeof(block_t));
}

block_t *alloc_block(block_t *tmp, size_t size)
{
    if ((tmp = sbrk(size)) == (void*)-1)
        return NULL;
    tmp->next = NULL;
    tmp->free = false;
    tmp->size = size - sizeof(tmp);
    return tmp;
}

block_t *find_block(block_t *tmp, size_t size)
{
    block_t *last = NULL;
    size_t blk_size = 0;

    while (tmp) {
        if (tmp->size >= size && tmp->free == true && blk->size > blk_size) {
            blk_size = tmp->size;
            last = tmp;
        }
        tmp = tmp->next;
    }
    return last;
}

block_t *split_block(block_t *block, size_t size)
{
    block_t *new;

    new = (block_t *)((char *)block + size + BLOCK_SIZE);
    new->size = block->size - size - BLOCK_SIZE;
    new->next = block->next;
    new->free = true;
    block->size = size;
    block->next = new;
    block->free = false;
    return block;
}