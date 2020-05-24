/*
** EPITECH PROJECT, 2024
** PSU_42sh_2019
** File description:
** Created by Enzo Ventura
*/

#include "minishell2.h"

int ope_or_process(t_minishell *minishell, int *fds, char **array, int i)
{
    if (i != arr_len(array) - 1) {
        i++;
        process_cmd(minishell, array[i], fds[0], fds[1]);
    }
    return i;
}

void ope_or(t_minishell *minishell, char *cmd, int fdin, int fdout)
{

    char **array = my_str_to_word_array(cmd, "|", 0);
    int status = 1;
    int fds[2] = {fdin, fdout};

    for (int i = 0; i < arr_len(array); i++) {
        process_cmd(minishell, array[i], fdin, fdout);
        status = minishell->status_wait;
        if (status != 0) {
            i = ope_or_process(minishell, fds, array, i);
        }
    }
}

int ope_and_process(t_minishell *minishell, int *fds, char **array, int i)
{
    if (i != arr_len(array) - 1) {
        i++;
        process_cmd(minishell, array[i], fds[0], fds[1]);
    }
    return i;
}

void ope_and(t_minishell *minishell, char *cmd, int fdin, int fdout)
{
    char **array = my_str_to_word_array(cmd, "&", 0);
    int status = 0;
    int fds[2] = {fdin, fdout};

    for (int i = 0; i < arr_len(array); i++) {
        process_cmd(minishell, array[i], fdin, fdout);
        status = minishell->status_wait;
        if (status == 0) {
            i = ope_and_process(minishell, fds, array, i);
        }
    }
}