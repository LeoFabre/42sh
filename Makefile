##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC		=		src/main.c									\
				src/init.c									\
				src/tools/cleaner.c							\
				src/tools/my_malloc.c						\
				src/tools/tools.c							\
				src/tools/tools_bis.c						\
				src/tools/tools_ter.c						\
				src/path.c									\
				src/globbings/globbings.c					\
				src/globbings/all_files.c					\
				src/globbings/question_mark.c				\
				src/globbings/globs_manager.c				\
				src/globbings/utils.c						\
				src/get_data.c								\
				src/shell/return_value.c					\
				src/shell/errors.c							\
				src/shell/prompt.c							\
				src/shell/redirect.c						\
				src/shell/process.c							\
				src/shell/shell.c							\
				src/shell/exec_cmd.c						\
				src/builtins/alias/alias.c					\
				src/builtins/alias/alias_parsing.c			\
				src/builtins/env.c							\
				src/builtins/setenv.c						\
				src/builtins/unsetenv.c						\
				src/builtins/exit.c							\
				src/builtins/cd.c							\
				src/tokens/semicolons.c	 					\
				src/tokens/pipes.c							\
				src/tokens/right_redir.c 					\
				src/tokens/left_redir.c 					\
				src/tokens/double_left.c					\
				src/tokens/operators.c						\
				src/linkedlists/create_rm_free_elems.c		\
				src/linkedlists/list_tools.c				\
				src/linkedlists/history.c					\

OBJ		=		$(SRC:.c=.o)

CFLAGS	=		-g -L lib/my -lmy -I include/ -Wextra -Wall

DFLAGS	+=		-g

NAME	=		42sh

ECHO	+=		echo -e

all:		$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	gcc -o $(NAME) $(OBJ) $(CFLAGS)
	@$(ECHO) '\033[01;34m---------------\033[01;34m->\033[01;32mAll compiled\033[01;34m<-\033[01;34m---------------\033[01;00m'

clean:
	rm	-f 	$(OBJ)
	make clean -C lib/my
	@$(ECHO) '\033[01;31m-----------------\033[01;31m->\033[01;33mAll clean\033[01;31m<-\033[01;31m----------------\033[01;00m'

fclean: clean
	rm 	-f 	$(NAME)
	make fclean -C lib/my
	@$(ECHO) '\033[01;36m---------------\033[01;36m->\033[01;36mBinary clean\033[01;36m<-\033[01;36m---------------\033[01;00m'

re:	fclean	all

valgrind: re
		valgrind --leak-check=full --track-origins=yes ./$(NAME)

debug: fclean all
	gcc -o $(NAME) $(OBJ) $(DFLAGS) $(CFLAGS)
	@$(ECHO) '\033[01;34m---------------\033[01;34m->\033[01;32mAll compiled on debug mode\033[01;34m<-\033[01;34m---------------\033[01;00m'
