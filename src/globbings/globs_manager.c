/*
** EPITECH PROJECT, 2024
** PSU_42sh_2019
** File description:
** Created by Achille Bourgault
*/

#include "minishell2.h"

int handle_glob_erros(char *cmd, char *error)
{
    char *label = get_cmd(cmd);

    if (error != NULL && my_strcmp(error, "GLOB_?_missing") == 0) {
        my_printf("%s: No match.\n", label);
        return (84);
    }
    return (0);
}

char *handle_glob_all(t_minishell *shell, char **files, char *cmd, char *format)
{
    char *res;

    files = get_files(shell, format);
    if (format == NULL)
        res = get_all_files(cmd, cmd, files);
    else
        res = get_all_files_format(cmd, cmd, files, format);
    return (res);
}

char *handle_glob_question(t_minishell *shell, char **files, char *cmd,
    char *label)
{
    char *res;

    if (label != NULL) {
        files = get_files_with_label(shell, label);
        res = get_all_files_label(cmd, cmd, files, label);
    } else {
        res = my_strdup(cmd);
        for (int x = 0; x < (my_strlen(get_cmd(cmd))); x++, res++);
        for (int x = 0; ((res[x] < 'A' || res[x] > 'Z') &&
            (res[x] < 'a' || res[x] > 'z')) && res[x]; x++, res++);
        res++;
        if (res[0] != '\0')
            res[0] = ' ';
        shell->error = "GLOB_?_missing";
    }
    return (res);
}

char *handle_glob_brackets(t_minishell *shell, char **files, char *cmd, char *format)
{
    char *res;

    files = get_files(shell, format);
    if (format == NULL)
        res = get_all_files(cmd, cmd, files);
    else
        res = get_all_files_format(cmd, cmd, files, format);
    return (res);
}