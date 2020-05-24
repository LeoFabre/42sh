/*
** EPITECH PROJECT, 2024
** my_project
** File description:
** Created by Leo Fabre
*/

#include "minishell2.h"
#include <my.h>
#include <time.h>
#include "stdlib.h"

void add_hist_entry(t_list *list, char *cmd)
{
    t_elem *new = my_malloc(sizeof(t_elem));
    time_t rawtime;
    struct tm *s_time;

    time(&rawtime);
    s_time = localtime(&rawtime);
    new->hour = s_time->tm_hour;
    new->min = s_time->tm_min;
    new->cmd = my_strdup(cmd);
    new->next = NULL;
    if (list->first == NULL && list->last == NULL) {
        list->first = new;
        list->last = new;
        new->prev = NULL;
    } else {
        list->last->next = new;
        new->prev = list->last;
        list->last = new;
    }
}

void add_to_start(t_list *list, char *cmd)
{
    t_elem *new = my_malloc(sizeof(t_elem));

    new->cmd = my_strdup(cmd);
    new->prev = NULL;
    if (list->first == NULL && list->last == NULL) {
        list->first = new;
        list->last = new;
        new->next = NULL;
    } else {
        new->next = list->first;
        list->first->prev = new;
        list->first = new;
    }
}

void rm_first(t_list *list)
{
    if (list->first == NULL || list->last == NULL)
        return;
    if (list_len(list) == 1) {
        free(list->first);
        list->first = NULL;
        list->last = NULL;
        return;
    } else {
        list->first = list->first->next;
        free(list->first->prev);
        list->first->prev = NULL;
        if (list_len(list) == 1)
            list->last = list->first;
    }
}

void rm_last(t_list *list)
{
    if (list->first == NULL || list->last == NULL)
        return;
    if (list_len(list) == 1) {
        free(list->first);
        list->first = NULL;
        list->last = NULL;
        return;
    } else {
        list->last = list->last->prev;
        free(list->last->next);
        list->last->next = NULL;
        if (list_len(list) == 1)
            list->last = list->first;
    }
}

void free_list(t_list *list)
{
    while (list->first != NULL)
        rm_first(list);
    free(list);
}