/*
** EPITECH PROJECT, 2021
** B-PSU-400-RUN-4-1-malloc-tom.hermann
** File description:
** realloc
*/

#include "malloc.h"

void *realloc(void *ptr, size_t size)
{
    if (ptr == NULL)
        return malloc(size);
    else if (size == 0) {
        free(ptr);
        return ptr;
    }
    free(ptr);
    return malloc(size);
}