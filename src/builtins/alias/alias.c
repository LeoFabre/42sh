/*
** EPITECH PROJECT, 2024
** PSU_minishell2_2019
** File description:
** Created by Enzo Ventura
*/

#include "minishell2.h"

int change_in_alias(t_minishell *minishell, char **cmd_array, int i, int j)
{
    int alias = 0;

    if (my_strcmp(cmd_array[i], extract_alias(minishell->aliases[j])) == 0) {
        cmd_array[i] = my_strdup(extract_cmd_from_alias(minishell->aliases[j]));
        alias++;
    }
    if (alias != 0)
        return TRUE;
    return FALSE;
}

char *find_alias(t_minishell *minishell, char *cmd)
{
    char **cmd_array = my_str_to_word_array(cmd, " \n\t", 0);
    int alias = 0;

    for (int i = 0; cmd_array[i]; i++) {
        for (int j = 0; minishell->aliases[j]; j++) {
            alias = change_in_alias(minishell, cmd_array, i, j);
        }
    }
    if (alias != 0)
        return my_atos(cmd_array);
    return cmd;
}

char *create_alias(char **array)
{
    char *str;

    str = my_strcat(array[1], my_strcat("=", array[2]));
    for (int i =3; array[i]; i++) {
        str = my_strcat(str, " ");
        str = my_strcat(str, array[i]);
    }
    return str;
}

void process_alias(t_minishell *minishell, char *cmd, int fdin, int fdout)
{
    (void)(fdin);
    (void)(fdout);
    char **array = my_str_to_word_array(cmd, " ", 0);
    char *alias = NULL;

    if (arr_len(array) < 3)
        return;
    if (check_already_alias(minishell, array) == TRUE)
        return;
    alias = create_alias(array);
    minishell->aliases = add_line_to_array(minishell->aliases, alias);
}