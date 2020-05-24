/*
** EPITECH PROJECT, 2024
** PSU_42sh_2019
** File description:
** Created by Leo Fabre
*/
#include "minishell2.h"
#include <unistd.h>
#include <stdlib.h>

char *get_clean_path()
{
    char *temp = getcwd(NULL, 0);
    char *result = NULL;
    int i = 0;

    if (!temp)
        return NULL;
    result = my_strdup(temp);
    for (i = my_strlen(temp); temp[i] != '/' ; --i);
    free(temp);
    return result + i + 1;
}

//Prints a Jah-approved prompt.
//newline: TRUE if needs to be printed on a new line, FALSE otherwise.
void print_prompt(int newline)
{
    char *my_cwd = NULL;

    if (isatty(0) == TRUE) {
        if (newline == TRUE)
            my_putchar('\n');
        my_cwd = get_clean_path();
        if (!my_cwd)
            exit(84);
        my_printf("%s42%s$#%s %s %s➜ ", KRED, KYEL, KGRN, my_cwd, KWHT);
    }
}