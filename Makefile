##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile <3
##

NAME		=	navy

CC		=	cc

CFLAGS		+=	-Wall -Wextra -I include/ -g

SRCS_PREFIX	=	src/

FILES		=	lib/my/my_putchar.c		\
			lib/my/my_strlen.c		\
			lib/my/my_putstr.c		\
			lib/my/my_put_nbr.c		\
			lib/my/my_puterror.c		\
			lib/my/my_getnbr.c		\
			lib/my/my_strcmp.c		\
			lib/my/str_to_word_array.c	\
			connect.c			\
			create_map.c			\
			box.c				\
			display.c			\
			game.c				\
			error.c				\
			file.c				\
			get_next_line.c			\
			start.c				\
			attack.c			\
			wait_attack.c			\
			win.c

MAIN		=	$(addprefix $(SRCS_PREFIX), main.c)

SRCS		=	$(addprefix $(SRCS_PREFIX), $(FILES))

OBJ		=	$(MAIN:.c=.o) $(SRCS:.c=.o)

OBJ_T		=	$(SRCS:.c=.o) $(TESTS:.c=.o)

all:			$(NAME)


.PHONY: fclean clean all re tests_run

# sed 0 by 1 -> bold
RED		=	\033[0;31m
GREEN		=	\033[0;32m
NC		=	\033[0m
GREY		=	\033[90m
BLUE		=	\033[0;94m
PURPLE		=	\033[0;95m
BG_COLOR	=	\033[46m####\033[m
IRED		=	\033[0;91m

ifndef VERBOSE
	MAKEFLAGS += --no-print-directory
endif

$(NAME):	$(OBJ)
	@echo -e '${NC}${BG_COLOR}Libs: $(LDFLAGS)${NC}'
	@echo -e '${BG_COLOR}Flags: $(CFLAGS)${NC}'
	@$(CC) $(OBJ) -o $(NAME) $(LDFLAGS) 2>>errors_build.txt\
		&& echo -e '${BLUE}Create${NC}: ${GREY}./$(NAME)${NC}'\
		|| echo -e '${RED}[ FAILED ]${NC}: __Create__${GREY} ./$(NAME)${NC}'

%.o:		%.c
	@-$(CC) -o $@ -c $< $(CFLAGS) 2>>errors_build.txt\
		&& echo -e '${GREEN} [ OK ]${NC} Build $<'\
		|| echo -e '${RED}[ FAILED ]${NC} __Build__ $<'\
		&& echo -ne '${PURPLE}' && grep  $< errors_build.txt |\
		grep warning |cut -d':' -f2- |cut -d'[' -f-1\
		&& echo -ne '${IRED}' && grep  $< errors_build.txt |\
		grep error |cut -d':' -f2-\
		||:

need:		$(OBJ)
	@make && echo "mkdir test ; cd test ; ls -a ; ls | cat | wc -c > tutu ; cat tutu" | ./mysh

debug:	clean
	$(eval CFLAGS += -D DEBUG)
	$(MAKE)

clean:
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_T)
	@rm -rf vgcore.*
	@rm -f gmon.out
	@rm -rf a.out
	@find . -name *.gc* -delete
	@rm -f errors_build.txt
	@echo -e '${BLUE}Clean${NC} : OK'

fclean:		clean
	@rm -rf errors_build.txt 2>/dev/null
	@rm -rf $(NAME)
	@echo -e '${BLUE}Fclean${NC}: ./$(NAME) removed'

re:	fclean all
