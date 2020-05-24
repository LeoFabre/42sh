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

int is_format(const char *buff, char *ext)
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

char *get_value(t_minishell *shell, char *key)
{
    char *result;
    int cpt;

    cpt = 0;
    for (int x = 0; shell->envp[x]; x++) {
        if (my_strncmp(key, shell->envp[x], my_strlen(key)) == 0) {
            result = my_malloc(sizeof(char) *
                (my_strlen(shell->envp[x]) - my_strlen(key) + 1));
            for (int i = my_strlen(key); shell->envp[x][i] != '\0'; i++, cpt++)
                result[cpt] = shell->envp[x][i];
            result[cpt] = '\0';
            return (result);
        }
    }
    return (NULL);
}

int get_total_nb_files(t_minishell *shell)
{
    DIR *folder = opendir(get_value(shell, "PWD="));
    struct dirent *entry;
    int files = 0;

    if (folder == NULL)
        return (84);
    while ((entry = readdir(folder))) {
        if (my_strcmp(entry->d_name, ".") != 0 &&
            my_strcmp(entry->d_name, "..") != 0)
            files++;
    }
    closedir(folder);
    return (files);
}

char **get_files_extend(t_minishell *shell, DIR *folder, int files,
    char *format)
{
    char **res = my_malloc(sizeof(char *) * (get_total_nb_files(shell) + 1));
    struct stat *buf;
    struct dirent *entry;

    (void)buf;
    for (files = 0; (entry = readdir(folder));) {
        if ((my_strcmp(entry->d_name, ".") != 0 &&
            my_strcmp(entry->d_name, "..") != 0) &&
            is_format(entry->d_name, format) == 0) {
            res[files] = my_malloc(sizeof(char) * (my_strlen(entry->d_name) + 1));
            res[files] = entry->d_name;
            res[files][my_strlen(entry->d_name)] = '\0';
            files++;
        }
    }
    res[files] = NULL;
    return (res);
}

char **get_files(t_minishell *shell, char *format)
{
    DIR *folder = opendir(get_value(shell, "PWD="));
    char **res;
    int cpt = 0;

    if (folder == NULL)
        return (NULL);
    else {
        res = get_files_extend(shell, folder, cpt, format);
        return (res);
    }
}