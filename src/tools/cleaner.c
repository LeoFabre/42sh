/*
** EPITECH PROJECT, 2024
** PSU_42sh_2019
** File description:
** Created by Leo Fabre
*/

#include "minishell2.h"
#include "stdlib.h"

void clean_start_calc_excess(char **str, int *excess)
{
    while (*(*str) == '\n' || *(*str) == ' ' || *(*str) == '\t') {
        (*str)++;
        while (*(*str) == '\\' &&
            ((*(*str) + 1) == 'n' || (*(*str) + 1) == 't'))
            *(*str) += 2;
    }
    for (int j = (my_strlen((*str)) - 1);
        (*str)[j] == '\n' || (*str)[j] == ' ' || (*str)[j] == '\t'; --j) {
        (*excess)++;
        while (j > 1 && ((*str)[j] == 'n' || (*str)[j] == 't') &&
            (*str)[j - 1] == '\\') {
            j -= 2;
            (*excess) += 2;
        }
    }
}

char *clean_str(char *str)
{
    int excess = 0;
    char *res = NULL;

    if (!str)
        return NULL;
    clean_start_calc_excess(&str, &excess);
    res = my_malloc(sizeof(char) * (my_strlen(str) - excess) + 1);
    if (!res)
        exit(84);
    for (int i = 0; i < (my_strlen(str) - excess) + 1; ++i)
        res[i] = str[i];
    res[(my_strlen(str) - excess)] = '\0';
    return res;
}

char **clean_array(char **array)
{
    for (int i = 0; array[i] != NULL; ++i) {
        array[i] = clean_str(array[i]);
    }
    return array;
}