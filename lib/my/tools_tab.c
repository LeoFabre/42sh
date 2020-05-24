/*
** EPITECH PROJECT, 2024
** PSU_minishell2_2019
** File description:
** Created by Enzo Ventura
*/

#include "my.h"
#include "minishell2.h"
#include <stdlib.h>

char *my_atos(char **array)
{
    char *res = "";

    for (int i = 0; array[i]; i++) {
        res = my_strcat(res, " ");
        res = my_strcat(res, array[i]);
    }
    return res;
}

int arr_len(char **array)
{
    int nb_lines = 0;

    if (array != NULL)
        for (; array[nb_lines] != NULL; nb_lines++);
    return nb_lines;
}

char **add_line_to_array(char **array, char *str)
{
    int i = 0;
    int nb_lines = 0;
    char **result_tab = NULL;

    if (array != NULL) {
        nb_lines = arr_len(array);
        result_tab = my_malloc(sizeof(char *) * (nb_lines + 2));
        for (; array[i]; i++) {
            if (array[i] != NULL) {
                result_tab[i] = my_strdup(array[i]);
            } else
                continue;
        }
        result_tab[i] = my_strdup(str);
        result_tab[i + 1] = NULL;
    }
    return result_tab;
}

void free_array(char **array)
{
    for (int i = 0; array[i]; i++)
        free(array[i]);
}

void print_array(char **array)
{
    for (int i = 0; array[i]; i++)
        my_printf("tab[%i] = (%s)\n", i, array[i]);
}