/*
** EPITECH PROJECT, 2024
** PSU_minishell2_2019
** File description:
** Created by Enzo Ventura
*/

#include "minishell2.h"
#include "stdlib.h"

void init_struct(t_minishell *minishell)
{
    minishell->path = NULL;
    minishell->envp = NULL;
    minishell->count_cd = 0;
    minishell->return_value = 0;
    minishell->pid = 0;
    minishell->pipe = 0;
    minishell->aliases = my_malloc(sizeof(char *) * 1);
    minishell->aliases[0] = NULL;
    minishell->status_wait = 0;
    minishell->history = init_list();
}