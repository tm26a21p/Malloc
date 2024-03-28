/*
** EPITECH PROJECT, 2022
** malloc
** File description:
** malloc
*/
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "mem.h"

void *add_mem(void *addr, size_t prev_size, size_t size)
{
    block_t new = addr;
    size_t end_block_size = prev_size + align_brk(size) - size - BLOCK_SIZE;

    if (extend_heap(size) == NULL)
        return NULL;
    new->free = false;
    new->size = size;
    new->data = new + 1;
    new->next = end_block(new->data + size, end_block_size);
    return new;
}

static void *get_mem(void *start, size_t size)
{
    block_t tmp = start;

    for (; tmp->next; tmp = tmp->next) {
        if (tmp->free == true && tmp->size == size) {
            tmp->free = false;
            return tmp->data;
        }
    }
    if (tmp->size <= size + BLOCK_SIZE) {
        tmp = add_mem(tmp, tmp->size, size);
        if (tmp == NULL)
            return NULL;
        return tmp->data;
    }
    tmp->free = false;
    tmp->data = tmp + 1;
    tmp->next = end_block(tmp->data + size, tmp->size - size - BLOCK_SIZE);
    tmp->size = size;
    return tmp->data;
}

void *malloc(size_t size)
{
    void *heap_start = get_heap_start();
    const void *current_break = sbrk(0);
    block_t tmp;

    size = align(size);
    if (current_break == heap_start) {
        if (size == 0) {
            size = align(1);
            tmp = extend_heap(size);
            tmp = end_block(tmp, align_brk(size) - BLOCK_SIZE - align(1));
            return NULL;
        }
        tmp = extend_heap(size);
        tmp = end_block(tmp, align_brk(size) - BLOCK_SIZE);
    }
    return get_mem(heap_start, size);
}

