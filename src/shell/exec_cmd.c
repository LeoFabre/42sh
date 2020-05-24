/*
** EPITECH PROJECT, 2024
** PSU_minishell2_2019
** File description:
** Created by Enzo Ventura
*/

#include "minishell2.h"
#include <unistd.h>
#include <wait.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>

void change_fd(int fdin, int fdout)
{
    if (fdin != 0) {
        dup2(fdin, 0);
        close(fdin);
    }
    if (fdout != 1) {
        dup2(fdout, 1);
        close(fdout);
    }
}

void simple_wait(t_minishell *minishell)
{
    if (minishell->pipe == 0) {
        waitpid(minishell->pid, &minishell->status_wait, 0);
        return_value(minishell, minishell->status_wait);
    }
}

void loop_wait(t_minishell *minishell, pid_t pid)
{
    int value = 1;

    while (value > 0)
        value = waitpid(pid, &minishell->status_wait, 0);
    return_value(minishell, minishell->status_wait);
}

void exec_cmd(t_minishell *minishell, char **arg, char *path, int *fds)
{
    if ((minishell->pid = fork()) == 0) {
        change_fd(fds[0], fds[1]);
        execve(path, arg, minishell->envp);
        if (errno == 8) {
            write(2, arg[0], my_strlen(arg[0]));
            write(2, ": Exec format error. Wrong Architecture.\n", 49);
        }
        exit(0);
    }
}