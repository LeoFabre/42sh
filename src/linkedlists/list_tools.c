/*
** EPITECH PROJECT, 2023
** shell
** File description:
** Created by Leo Fabre
*/

#include "minishell2.h"
#include "stdlib.h"

int list_len(t_list *list)
{
    t_elem *current = list->first;
    int i = 0;

    if (list->first != NULL && list->last != NULL)
        for (; current != NULL; i++, current = current->next);
    return i;
}

void debug_print_list(t_list *list)
{
    t_elem *current = list->first;
    int i = 0;

    my_printf("--== DEBUG ==--\n");
    if (list->first == NULL && list->last == NULL) {
        my_printf("LIST IS EMPTY !!\n");
        my_printf("--== END DEBUG ==--\n");
        return;
    }
    for (; current != NULL; i++, current = current->next) {
        my_printf("cmd : {%s}\n", current->cmd);
    }
    my_printf("--== END DEBUG ==--\n");
}

t_list *init_list(void)
{
    t_list *list = my_malloc(sizeof(t_list));

    list->first = NULL;
    list->last = NULL;
    return list;
}

void add_elem_to_end(t_elem *new, t_minishell *shell)
{
    new->next = NULL;
    if (shell->history->first == NULL &&
        shell->history->last == NULL) {
        shell->history->first = new;
        shell->history->last = new;
        new->prev = NULL;
    } else {
        shell->history->last->next = new;
        new->prev = shell->history->last;
        shell->history->last = new;
    }
}

void add_elem_to_start(t_elem *new, t_minishell *shell)
{
    new->prev = NULL;
    if (shell->history->first == NULL &&
        shell->history->last == NULL) {
        shell->history->first = new;
        shell->history->last = new;
        new->next = NULL;
    } else {
        new->next = shell->history->first;
        shell->history->first->prev = new;
        shell->history->first = new;
    }
}