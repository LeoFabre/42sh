/*
** EPITECH PROJECT, 2024
** PSU_42sh_2019
** File description:
** Created by Achille Bourgault
*/

#include <stdlib.h>
#include "minishell2.h"

char *get_all_files(char *cmd, char *end, char **files)
{
    int to_alloc = 0;
    int y;
    int x;
    char *res;

    for (y = 0; files[y] != NULL; y++)
        to_alloc += my_strlen(files[y]);
    for (x = 0; cmd[x + 1] != '*' && cmd[x + 1]; x++, end++);
    res = my_malloc(sizeof(char) * (to_alloc + (x + 1) + y + my_strlen(end) + 1));
    res = my_strncpy(res, cmd, x);
    res[x] = '\0';
    res = my_strncat(res, " ", 1);
    for (y = 0; files[y] != NULL; y++) {
        res = my_strncat(res, files[y], my_strlen(files[y]));
        if (files[y + 1] != NULL)
            res = my_strncat(res, " ", 1);
    }
    for (int c = 0; c < 2; end++, c++);
    res = my_strcat(res, end);
    return (res);
}

char *get_all_files_format(char *cmd, char *end, char **files, char *format)
{
    int to_alloc = 0;
    int y;
    int x;
    char *res;

    for (y = 0; files[y] != NULL; y++)
        to_alloc += my_strlen(files[y]);
    for (x = 0; cmd[x + 1] != '*' && cmd[x + 1]; x++, end++);
    res = my_malloc(sizeof(char) * (to_alloc + (x + 1) + y + my_strlen(end) + 1));
    res = my_strncpy(res, cmd, x);
    res[x] = '\0';
    res = my_strncat(res, " ", 1);
    for (y = 0; files[y] != NULL; y++) {
        res = my_strncat(res, files[y], my_strlen(files[y]));
        if (files[y + 1] != NULL)
            res = my_strncat(res, " ", 1);
    }
    for (int c = 0; c < (my_strlen(format) + 2) && end[0] != '\0'; end++, c++);
    res = my_strcat(res, end);
    return (res);
}

char *get_question_label(char *cmd)
{
    char *res;
    int x;
    int to_alloc;
    int cpt = 0;

    for (x = 0; cmd[x] != '?' && cmd[x]; x++);
    if (x == my_strlen(cmd))
        return (NULL);
    cmd--;
    if (cmd[x] == ' ')
        return (NULL);
    for (to_alloc = 0; cmd[x - 1] != ' ' && cmd[x]; x--, to_alloc++);
    res = my_malloc(sizeof(char) * (to_alloc + 2));
    for (int cpta = x; cmd[cpta] != '?' && cmd[cpta]; cpta++, cpt++)
        res[cpt] = cmd[cpta];
    res[cpt] = '\0';
    return (res);
}

char *get_format(char *cmd)
{
    char *res;
    int x;
    int x2;
    int cpt = 0;

    for (x = 0; cmd[x] != '.' && cmd[x] != '\0'; x++);
    if (x == my_strlen(cmd))
        return (NULL);
    for (x2 = x; cmd[x2] != '\0' && cmd[x2] != ' '; x2++);
    res = my_malloc(sizeof(char) * (x2 - x + 1));
    for (x2 = x; cmd[x2] != '\0' && cmd[x2] != ' '; x2++, cpt++)
        res[cpt] = cmd[x2];
    res[cpt] = '\0';
    return (res);
}