/*
** EPITECH PROJECT, 2021
** B-PSU-400-RUN-4-1-malloc-tom.hermann
** File description:
** malloc
*/

#ifndef MALLOC_H_
#define MALLOC_H_

#include <unistd.h>
#include <stdio.h>

#define PAGESIZE        getpagesize()
#define false           0
#define true            1


typedef struct metadata_s
{
    int is_free;
    struct metadata_s *next;
    size_t size;
} metadata_t;

void *add_size(metadata_t *current, size_t size);

void free(void *ptr);
void *malloc(size_t size);
void *calloc(size_t nmemb, size_t size);
void *realloc(void * ptr, size_t size);
void *reallocarray(void *ptr, size_t nmemb, size_t size);

#endif /* !MALLOC_H_ */
