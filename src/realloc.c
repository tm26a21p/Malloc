/*
** EPITECH PROJECT, 2022
** malloc
** File description:
** malloc
*/
#include "mem.h"

void *realloc(void *ptr, size_t size)
{
    block_t x = ptr;
    void *result;

    if (!ptr)
        return malloc(size);
    if (ptr && size == 0) {
        free(ptr);
        return NULL;
    }
    x = x - 1;
    if (x->size >= align(size)) {
        return ptr;
    }
    result = malloc(size);
    memcpy(result, ptr, x->size);
    free(ptr);
    return result;
}

