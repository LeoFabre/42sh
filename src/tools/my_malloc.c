/*
** EPITECH PROJECT, 2024
** PSU_42sh_2019
** File description:
** Created by Leo Fabre
*/
#include <stdlib.h>

//error handling wrapper for malloc()
void *my_malloc(size_t size)
{
    void *ptr;

    ptr = malloc(size);
    if (!ptr)
        exit(84);
    return (ptr);
}