/*
** EPITECH PROJECT, 2024
** PSU_42sh_2019
** File description:
** Created by Leo Fabre
*/

#include "minishell2.h"
#include "stdlib.h"

char *my_itoa(int nb)
{
    char *buffer;
    int i;
    int power;

    power = 10;
    i = 0;
    while ((nb / power) > 0) {
        power = power * 10;
        i++;
    }
    if (!(buffer = calloc(10, sizeof(char))))
        return (NULL);
    power = i;
    buffer[i + 1] = '\0';
    while (i >= 0) {
        buffer[i] = (nb - ((nb / 10) * 10) + '0');
        i--;
        nb = nb / 10;
    }
    return (buffer);
}

void print_time(t_elem *elem)
{
    if (elem->hour < 10)
        my_putchar('0');
    my_printf("%d", elem->hour);
    my_putchar(':');
    if (elem->min < 10)
        my_putchar('0');
    my_printf("%d", elem->min);
}

void print_history(t_minishell *shell, char **cmd __attribute__((unused)))
{
    t_elem *current = shell->history->first;

    if (shell->history->first == NULL && shell->history->last == NULL) {
        my_printf("history IS EMPTY !!\n");
        return;
    }
    for (int i = 0; current != NULL; i++, current = current->next) {
        my_printf("     %d\t", i + 1);
        print_time(current);
        my_printf("\t%s\n", current->cmd);
    }
}