/*
** EPITECH PROJECT, 2024
** PSU_42sh_2019
** File description:
** Created by Achille Bourgault
*/

#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include "my.h"
#include "minishell2.h"

int is_label(const char *buff, char *ext)
{
    int cpt;

    if (ext == NULL)
        return (0);
    cpt = 0;
    for (int x = 0; buff[x] != '\0'; x++) {
        if (buff[x] == ext[cpt])
            cpt++;
        else if (cpt == my_strlen(ext))
            return (0);
        else
            cpt = 0;
    }
    if (cpt == my_strlen(ext))
        return (0);
    else
        return (1);
}

void remove_label(char *s1, char const *s2)
{
    int i = 0, j, k;
    while (s1[i]) {
        for (j = 0; s2[j] && s2[j] == s1[i + j]; j++);
        if (!s2[j]) {
            for (k = i; s1[k + j]; k++)
                s1[k] = s1[k + j];
            s1[k] = 0;
        } else
            i++;
    }
}

char *get_all_files_label(char *cmd, char *end, char **files, char *format)
{
    int to_alloc = 0;
    int y;
    int x;
    char *res;

    for (y = 0; files[y] != NULL; y++)
        to_alloc += my_strlen(files[y]);
    for (x = 0; cmd[x] != '?' && cmd[x]; x++, end++);
    end++;
    res = my_malloc(sizeof(char) * (to_alloc + (x + 1) + y + my_strlen(end) + 1));
    res = my_strncpy(res, cmd, x - my_strlen(format));
    res[x] = '\0';
    remove_label(res, format);
    res = my_strncat(res, " ", 1);
    for (y = 0; files[y] != NULL; y++) {
        res = my_strncat(res, files[y], my_strlen(files[y]));
        if (files[y + 1])
            res = my_strncat(res, " ", 1);
    }
    res = my_strcat(res, end);
    return (res);
}

char **get_files_extend_label(t_minishell *shell, DIR *folder, int files,
    char *label)
{
    char **res = my_malloc(sizeof(char *) * (get_total_nb_files(shell) + 1));
    struct stat *buf;
    struct dirent *entry;

    (void)buf;
    for (files = 0; (entry = readdir(folder));) {
        if ((my_strcmp(entry->d_name, ".") != 0 &&
            my_strcmp(entry->d_name, "..") != 0) &&
            (is_label(entry->d_name, label) == 0 &&
                my_strlen(entry->d_name) - 1 == my_strlen(label))) {
            res[files] = my_malloc(sizeof(char) * (my_strlen(entry->d_name) + 1));
            res[files] = entry->d_name;
            res[files][my_strlen(entry->d_name)] = '\0';
            files++;
        }
    }
    res[files] = NULL;
    return (res);
}

char **get_files_with_label(t_minishell *shell, char *label)
{
    DIR *folder = opendir(get_value(shell, "PWD="));
    char **res;
    int cpt = 0;

    if (folder == NULL)
        return (NULL);
    else {
        res = get_files_extend_label(shell, folder, cpt, label);
        return (res);
    }
}