/*
** EPITECH PROJECT, 2021
** B-PSU-400-RUN-4-1-malloc-tom.hermann
** File description:
** free
*/

#include "malloc.h"

void free(void *ptr)
{
    metadata_t *metadata;

    if (ptr == NULL) return;
    metadata = ((void *)ptr) - sizeof(metadata_t);
    metadata->is_free = true;
    if (metadata->next != NULL && metadata->next->is_free) {
        metadata->size += metadata->next->size + sizeof(metadata_t);
        metadata->next = metadata->next->next;
    }
}