/*
** EPITECH PROJECT, 2024
** PSU_42sh_2019
** File description:
** Created by Achille Bourgault
*/

#include <stdlib.h>
#include <dirent.h>
#include "minishell2.h"

char *get_cmd(char *cmd)
{
    char *res = NULL;
    int to_cpy;

    for (to_cpy = 0; cmd[to_cpy] != ' ' && cmd[to_cpy]; to_cpy++);
    res = my_malloc(sizeof(char) * (to_cpy + 1));
    res = my_strncpy(res, cmd, to_cpy);
    res[to_cpy] = '\0';
    return (res);
}

char *apply_globbings(t_minishell *shell, char *cmd, char globbing)
{
    char *res = NULL;
    char **files = NULL;
    char *label = get_question_label(cmd);
    char *format = get_format(cmd);

    shell->error = NULL;
    if (globbing == '*')
        res = handle_glob_all(shell, files, cmd, format);
    else if (globbing == '?')
        res = handle_glob_question(shell, files, cmd, label);
    else
//        res = handle_glob_brackets(shell, files, cmd, format);
    if (handle_glob_erros(cmd, shell->error) == 84)
        return (res);
    return (res);
}

char *check_globbings(t_minishell *shell, char *cmd)
{
    char c = ' ';
    int g;
    char *globings[4] = {"*", "?", "[", NULL};

    for (int x = 0; cmd[x] != '\0'; x++) {
        for (g = 0; globings[g]; g++) {
            if (cmd[x] == globings[g][0]) {
                c = cmd[x];
                break;
            }
        }
    }
    if (c != ' ')
        return (apply_globbings(shell, cmd, c));
    else
        return (cmd);
}