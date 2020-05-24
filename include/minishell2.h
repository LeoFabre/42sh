/*
** EPITECH PROJECT, 2024
** PSU_minishell2_2019
** File description:
** Created by Enzo Ventura
*/
#ifndef PSU_MINISHELL2_2019_MINISHELL2_H
#define PSU_MINISHELL2_2019_MINISHELL2_H

#include "my.h"
#include "my_printf.h"
#include "linkedlists.h"
#include <unistd.h>
#define TRUE 1
#define FALSE 0

#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KWHT  "\x1B[37m"

typedef struct s_set_minishell {
    t_list *history;
    char **envp;
    char **path;
    char **aliases;
    int count_cd;
    int return_value;
    pid_t pid;
    int pipe;
    int status_wait;
    char *error;
} t_minishell;

//initialisation
void init_struct(t_minishell *minishell);

//errors
int errors(int ac);
void *my_malloc(size_t size);

//return value
void return_value(t_minishell *minishell, int value);

//paths
char *find_path(char *cmd, t_minishell *minishell);
char **fill_tab(t_minishell *minishell, char **tab);
char **new_get_path(t_minishell *minishell);
char **my_get_paths(t_minishell *minishell);

//process
void process_cmd(t_minishell *minishell, char *cmd, int fdin, int fdout);

//semicolons
void process_semicolons(t_minishell *minishell, char *cmd, int fdin, int fdout);

//pipes
void process_pipes(t_minishell *minishell, char *cmd, int fdin, int fdout);

//right redir
void process_right_redir(t_minishell *minishell, char *cmd, int fdout,
    int fdin);
int create_file(char *name, int flags);
void process_double_left(t_minishell *minishell, char *cmd, int fdin,
    int fdout);

//left redir
void process_left_redir(t_minishell *minishell, char *cmd, int fdin, int fdout);

//exec cmd
void exec_cmd(t_minishell *minishell, char **arg, char *path, int *fds);
void loop_wait(t_minishell *minishell, pid_t pid);
void simple_wait(t_minishell *minishell);

//getenv
void my_get_env(t_minishell *minishell, char **env);
char *my_get_line_env(t_minishell *minishell, char *name);

//env
void env(t_minishell *minishell, char **input);

//exit
void exit_shell(t_minishell *minishell, char **input);

//setenv
void set_env(t_minishell *minishell, char *name, char *value);
char *set_env_already(char *name, char *value);

//unsetenv
char **unset_env(t_minishell *minishell, char *name);
void unset_env_redir(t_minishell *minishell, char **input);

//cd
void cd_builtin(t_minishell *minishell, char *dir);
void cd_wtout_arg(t_minishell *minishell);
void cd_tiret(t_minishell *minishell);
void cd_slash(t_minishell *minishell);

//aliases
void process_alias(t_minishell *minishell, char *cmd, int fdin, int fdout);
char *find_alias(t_minishell *minishell, char *cmd);
char *extract_cmd_from_alias(char *str);
char *extract_alias(char *str);
int check_already_alias(t_minishell *minishell, char **alias);
char *create_alias(char **array);

//globbings
char *check_globbings(t_minishell *shell, char *cmd);
char **get_files(t_minishell *shell, char *format);
char **get_files_with_label(t_minishell *shell, char *label);
char *get_all_files(char *cmd, char *end, char **files);
char *get_all_files_label(char *cmd, char *end, char **files, char *format);
char *get_all_files_format(char *cmd, char *end, char **files, char *format);
char *get_format(char *cmd);
char *get_question_label(char *cmd);
int is_format(const char *buff, char *ext);
int get_total_nb_files(t_minishell *shell);
int handle_glob_erros(char *cmd, char *error);
char *handle_glob_all(t_minishell *shell, char **files, char *cmd,
    char *format);
char *handle_glob_question(t_minishell *shell, char **files, char *cmd,
    char *label);
char *handle_glob_brackets(t_minishell *shell, char **files, char *cmd,
    char *format);

//redirections
void set_env_redir(t_minishell *minishell, char **input);
void redirect_cd(t_minishell *minishell, char **input);
void redirect_cd_two(t_minishell *minishell, char **input, int i);
void fptr_builtins(t_minishell *minishell, char **input, int fdin, int fdout);

//operators
void ope_and(t_minishell *minishell, char *cmd, int fdin, int fdout);
void ope_or(t_minishell *minishell, char *cmd, int fdin, int fdout);

//tools
char *get_cmd(char *cmd);
char *get_value(t_minishell *shell, char *key);
void free_all(t_minishell *minishell);
int my_str_is_equal(char *s1, char *s2);
int search_var(t_minishell *minishell, char *name);
char *pars_arg(char *cmd);
char *rm_name_var(char *str);
int check_arr(char **input, char *path);
int check_cmd(char *cmd);
int check_input(char *input);
int check_char(char *str, char c);
int size_tab(char **tab);
int check_just_tokens(char *cmd);
int check_right_redir(char *cmd);
char *useless_spaces(char *str);
char **clean_array(char **array);
char *clean_str(char *str);

//prompt
void print_prompt(int newline);

//lists and history
void add_elem_to_start(t_elem *new, t_minishell *shell);
void add_elem_to_end(t_elem *new, t_minishell *shell);
int list_len(t_list *list);
t_list *init_list(void);
void free_list(t_list *list);
void rm_last(t_list *list);
void rm_first(t_list *list);
void add_to_start(t_list *list, char *cmd);
void add_hist_entry(t_list *list, char *cmd);
void print_history(t_minishell *shell, char **cmd __attribute__((unused)));
#endif
