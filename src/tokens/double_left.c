/*
** EPITECH PROJECT, 2024
** PSU_42sh_2019
** File description:
** Created by Leo Fabre
*/
#include <fcntl.h>
#include "minishell2.h"
#include "stdio.h"

void get_temp_content(char *delimiter, int fd, char **buff, size_t *size)
{
    while (420) {
        my_putstr("? ");
        (*buff) = NULL;
        (*size) = 0;
        getline(buff, size, stdin);
        if (my_strcmp((*buff), delimiter) == 0 ||
            my_strcmp(clean_str((*buff)), clean_str(delimiter)) == 0) {
            break;
        }
        write(fd, (*buff), my_strlen((*buff)));
    }
}

void process_double_left(t_minishell *minishell, char *cmd, int fdin, int fdout)
{
    (void)(fdin);
    char **split_cmd = my_str_to_word_array(cmd, "<", 0);
    char *actual_cmd = split_cmd[0];
    char *delimiter = split_cmd[1];
    char *buff = NULL;
    size_t size = 0;
    int pipefd[2];

    pipe(pipefd);
    get_temp_content(delimiter, pipefd[1], &buff, &size);
    close(pipefd[1]);
    process_cmd(minishell, actual_cmd, pipefd[0], fdout);
}