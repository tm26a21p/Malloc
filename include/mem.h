/*
** EPITECH PROJECT, 2022
** mem.h
** File description:
** malloc
*/

#ifndef MEM_H_
    #define MEM_H_
    #include <stdbool.h>
    #include <stddef.h>
    #include <unistd.h>
    #include <string.h>
    #include <stdio.h>
    #include <stdint.h>
    #include <stdlib.h>
    #define BLOCK_SIZE sizeof(struct block_s)
    #define UNUSED __attribute__((unused))

    typedef struct block_s *block_t;

    struct block_s {
        block_t next;
        int free;
        size_t size;
        void *data;
    };

    void *malloc(size_t size);

    void free(void *ptr);

    void *realloc(void *ptr, size_t size);

    void *reallocarray(void *ptr, size_t nmemb, size_t size);

    size_t align(size_t actual);

    void *get_heap_start(void);

    void *extend_heap(size_t size);

    void *end_block(void *addr, size_t size);

    size_t align_brk(size_t requested);

    void print(char const *str);

    void paddr(void *addr);

    int pnbr(int nb);

    size_t punbr(size_t nb);

    void pchar(char x);

    void show_meta(block_t x);

#endif
