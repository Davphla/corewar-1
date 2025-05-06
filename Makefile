##
## EPITECH PROJECT, 2025
## Corewar
## File description:
## Makefile
##

SRC	=	src/op.c \
		src/corewar.c \
		src/parsing/init_war.c \
		src/parsing/print_help.c \
		src/parsing/parse_champ.c \
		src/parsing/init_struct.c \
		src/utils/free.c \
		src/utils/utils.c \
		src/utils/change_endian.c \
		src/utils/display_vm.c \
		src/lib/my_strcmp.c \
		src/lib/my_strlen.c	\
		src/lib/my_arrlen.c \
		src/lib/my_getnbr.c \
		src/lib/my_strcpy.c \
		src/lib/my_strdup.c \
		src/linked_list/list_array.c \
		src/linked_list/list.c

MAIN_SRC	=	src/main.c
OBJ	=	$(SRC:.c=.o) $(MAIN_SRC:.c=.o)
NAME	=	corewar
CFLAGS += -Wall -Wextra -pedantic
CPPFLAGS	+= -Iinclude/
ifeq ($(ENV), dev)
	CFLAGS	+=	-g3
endif

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) unit_tests *.gcno *.gcda

re: fclean all

coding_style: fclean
	coding-style . > /dev/null
	cat coding-style-reports.log
	$(RM) coding-style-reports.log

unit_tests: fclean all
	gcc -o unit_tests tests/test_mysh.c $(SRC) -Iinclude/ \
	--coverage -lcriterion
	-./unit_tests

gcovr: unit_tests
	gcovr --exclude tests --gcov-ignore-parse-errors=negative_hits.warn
	$(RM) unit_tests *.gcno *.gcda

.PHONY: all clean fclean re coding_style unit_tests gcovr
