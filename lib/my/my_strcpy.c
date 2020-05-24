/*
** EPITECH PROJECT, 2019
** my_strcpy.c
** File description:
** Task01
*/

#include "minishell2.h"

char *my_strcpy(char *src)
{
    char *res = my_malloc(sizeof(char) * (my_strlen(src) + 1));
    int i = 0;

    for (; src[i]; i++)
        res[i] = src[i];
    res[i] = '\0';
    return (res);
}
