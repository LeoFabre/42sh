/*
** EPITECH PROJECT, 2024
** MUL_my_shell_2019
** File description:
** Created by Leo Fabre
*/
#ifndef LINKEDLISTS_H
#define LINKEDLISTS_H
#include "time.h"

typedef struct s_list t_list;
typedef struct s_elem t_elem;

typedef struct s_elem {
    int hour;
    int min;
    char *cmd;
    t_elem *next;
    t_elem *prev;
} t_elem;

typedef struct s_list {
    t_elem *first;
    t_elem *last;
} t_list;

void debug_print_list(t_list *list);

#endif //LINKEDLISTS_H
