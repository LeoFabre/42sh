/*
** EPITECH PROJECT, 2024
** PSU_minishell1_2019
** File description:
** Created by Enzo Ventura
*/

#include "my.h"
#include "minishell2.h"
#include <stdlib.h>

char *my_strdup(char *str)
{
    char *dest = my_malloc(sizeof(char) * (my_strlen(str) + 1));

    dest = my_strcpy(str);
    return (dest);
}