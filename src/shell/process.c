/*
** EPITECH PROJECT, 2024
** PSU_minishell2_2019
** File description:
** Created by Enzo Ventura
*/

#include <minishell2.h>
#include <unistd.h>
#include <string.h>

void basic_process(t_minishell *minishell, char *cmd, int fdin, int fdout)
{
    char **arg;

    cmd = find_alias(minishell, cmd);
    if ((arg = my_str_to_word_array(cmd, " \t\n", 0)) == NULL)
        return;
    fptr_builtins(minishell, arg, fdin, fdout);
    free_array(arg);
}

void process_cmd(t_minishell *minishell, char *cmd, int fdin, int fdout)
{
    void ((*tab[9])(t_minishell *, char *, int, int)) = {&process_semicolons,
        &ope_and, &process_pipes, &process_double_left, &process_right_redir,
        &process_left_redir, &ope_or, &process_alias, &basic_process};
    char *separators[9] = {";", "&&", "|","<<", ">", "<", "||","alias", NULL};
    int nb_sep = 0;
    int i = 0;

    cmd = clean_str(check_globbings(minishell, cmd));
    if (cmd[0] == '\0')
        return;
    minishell->path = new_get_path(minishell);
    for (; separators[i]; i++) {
        if (strstr(cmd, separators[i]) != NULL) {
            nb_sep += 1;
            (tab[i])(minishell, cmd, fdin, fdout);
            break;
        }
    }
    if (nb_sep == 0)
        (tab[8])(minishell, cmd, fdin, fdout);
}
