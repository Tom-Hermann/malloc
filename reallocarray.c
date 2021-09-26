/*
** EPITECH PROJECT, 2021
** B-PSU-400-RUN-4-1-malloc-tom.hermann
** File description:
** reallocarray
*/

#include "malloc.h"

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    return realloc(ptr, nmemb * size);
}