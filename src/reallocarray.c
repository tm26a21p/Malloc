/*
** EPITECH PROJECT, 2022
** malloc
** File description:
** malloc
*/
#include "mem.h"

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    return realloc(ptr, nmemb * size);
}

