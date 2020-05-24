/*
** EPITECH PROJECT, 2024
** PSU_minishell2_2019
** File description:
** Created by Enzo Ventura
*/

#include "minishell2.h"

int check_already_alias(t_minishell *minishell, char **alias)
{
    for (int i = 0; minishell->aliases[i]; i++) {
        if (my_strcmp(alias[1], extract_alias(minishell->aliases[i])) == 0) {
            minishell->aliases[i] = create_alias(alias);
            return TRUE;
        }
    }
    return FALSE;
}

char *extract_cmd_from_alias(char *str)
{
    char **alias_array = my_str_to_word_array(str, "=", 0);
    char *cmd_alias = my_strdup(alias_array[1]);

    free_array(alias_array);
    return cmd_alias;
}

char *extract_alias(char *str)
{
    char **alias_array = my_str_to_word_array(str, "=", 0);
    char *alias = my_strdup(alias_array[0]);

    free_array(alias_array);
    return alias;
}

