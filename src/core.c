/*
** EPITECH PROJECT, 2022
** malloc
** File description:
** malloc
*/
#include "mem.h"

size_t align_brk(size_t requested)
{
    size_t result = 0;

    while (result < requested + BLOCK_SIZE) {
        result += 2 *getpagesize();
    }
    return result;
}

size_t align(size_t actual)
{
    size_t two = 1;

    while (two < actual)
        two *= 2;
    return two == 1 ? 2 : two;
}

void *get_heap_start(void)
{
    static void *heap_start = NULL;
    if (heap_start == NULL)
        heap_start = sbrk(0);
    return heap_start;
}

void *end_block(void *addr, size_t size)
{
    block_t end = addr;

    end->free = true;
    end->size = size;
    end->data = end + 1;
    end->next = NULL;
    return end;
}

void *extend_heap(size_t size)
{
    void *ptr = NULL;

    ptr = sbrk(align_brk(size));
    if (ptr == (void *)-1) {
        return NULL;
    }
    return ptr;
}

