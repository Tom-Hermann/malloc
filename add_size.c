/*
** EPITECH PROJECT, 2021
** B-PSU-400-RUN-4-1-malloc-tom.hermann
** File description:
** init_malloc
*/

#include "malloc.h"

void *add_size(metadata_t *current, size_t size)
{
    int i = 2;

    for (; (size + (sizeof(metadata_t) * 2)) > (size_t)(PAGESIZE * i); i += 2);
    sbrk(i * PAGESIZE);
    current->is_free = false;
    current->size = size;
    current->next = ((void *)current) + sizeof(metadata_t) + size;
    current->next->is_free = true;
    current->next->size = (PAGESIZE * i) - (size + (sizeof(metadata_t) * 2));
    current->next->next = NULL;
    return ((void *)current) + sizeof(metadata_t);
}
