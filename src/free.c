/*
** EPITECH PROJECT, 2022
** malloc
** File description:
** malloc
*/
#include "mem.h"

void free(void *ptr)
{
    block_t f = ptr;

    if (!ptr)
        return;
    f = f - 1;
    if (f)
        f->free = true;
}

