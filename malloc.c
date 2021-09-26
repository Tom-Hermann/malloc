/*
** EPITECH PROJECT, 2021
** B-PSU-400-RUN-4-1-malloc-tom.hermann
** File description:
** malloc
*/

#include "malloc.h"

static void *get_head(void *adresse)
{
    static void *head = NULL;

    if (head == NULL && adresse == NULL)
        return NULL;
    if (head == NULL && adresse != NULL)
        head = adresse;
    return head;
}

void *init_size(size_t size)
{
    int i = 2;
    metadata_t *metadata;

    for (; (size + (sizeof(metadata_t) * 2)) > (size_t)(PAGESIZE * i); i += 2);
    metadata = get_head(sbrk(i * PAGESIZE));
    metadata->is_free = false;
    metadata->size = size;
    metadata->next = ((void *)metadata) + size + sizeof(metadata_t);
    metadata->next->is_free = true;
    metadata->next->size = (PAGESIZE * i) - (size + (sizeof(metadata_t) * 2));
    metadata->next->next = NULL;
    return ((void *)metadata) + sizeof(metadata_t);
}

void *add_block(metadata_t *current, size_t size)
{
    size_t size_save  = current->size;
    metadata_t *save = current->next;
    metadata_t *return_value = ((void *)current) + sizeof(metadata_t);

    current->is_free = false;
    current->size = size;
    current->next = ((void*)current) + size + sizeof(metadata_t);
    current->next->is_free = true;
    current->next->size = size_save - (size + sizeof(metadata_t));
    current->next->next = save;
    return return_value;
}

void *bestfit(metadata_t *head, size_t size)
{
    metadata_t *save = NULL;
    metadata_t *tmp = head;

    for (int i = 0; tmp->next != NULL; tmp = tmp->next, i++) {
        if (tmp->is_free && tmp->size >= size + sizeof(metadata_t)) {
            if (save == NULL || (save->size > tmp->size)) {
                save = tmp;
            }
        }
    }
    if (tmp->is_free && tmp->size >= size + sizeof(metadata_t)) {
        if (save == NULL || (save->size > tmp->size)) {
            write(1, "last", 5);
            save = tmp;
        }
    }
    if (save == NULL)
        return add_size(tmp, size);
    else
        return add_block(save, size);
}

void *malloc(size_t size)
{
    void *head = get_head(NULL);

    if (head == NULL) {
        return init_size(size);
    }
    return bestfit(head, size);
}