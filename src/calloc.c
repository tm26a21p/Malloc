/*
** EPITECH PROJECT, 2022
** malloc
** File description:
** malloc
*/
#include "mem.h"

void *calloc(size_t nmemb, size_t size)
{
    void *a = NULL;

    if (nmemb == 0 || size == 0)
        return NULL;
    a = malloc(nmemb * size);
    if (!a) {
        return NULL;
    }
    memset(a, 0, nmemb * size);
    return a;
}

