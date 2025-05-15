##
## EPITECH PROJECT, 2025
## Corewar
## File description:
## Makefile
##

SRC	=	src/op.c\
		src/corewar.c\
		\
		src/parsing/init_war.c\
		src/parsing/print_help.c\
		src/parsing/parse_champ.c\
		src/parsing/init_struct.c\
		\
		src/utils/free.c\
		src/utils/utils.c\
		src/utils/change_endian.c\
		src/utils/check_winner.c\
		src/utils/display_winner.c\
		src/utils/get_direct.c\
		src/utils/get_ind.c\
		src/utils/process_dup.c\
		\
		src/corewar/dump.c\
		src/corewar/update_vm.c\
		src/corewar/handle_champ.c\
		src/corewar/handle_process.c\
		src/corewar/instructions/i_live.c\
		src/corewar/instructions/i_ld.c\
		src/corewar/instructions/i_st.c\
		src/corewar/instructions/i_add.c\
		src/corewar/instructions/i_sub.c\
		src/corewar/instructions/i_and.c\
		src/corewar/instructions/i_or.c\
		src/corewar/instructions/i_xor.c\
		src/corewar/instructions/i_zjmp.c\
		src/corewar/instructions/i_ldi.c\
		src/corewar/instructions/i_sti.c\
		src/corewar/instructions/i_fork.c\
		src/corewar/instructions/i_lld.c\
		src/corewar/instructions/i_lldi.c\
		src/corewar/instructions/i_lfork.c\
		src/corewar/instructions/i_aff.c\
		\
		src/lib/my_strcmp.c\
		src/lib/my_strlen.c\
		src/lib/my_arrlen.c\
		src/lib/my_getnbr.c\
		src/lib/my_strcpy.c\
		src/lib/my_strdup.c\
		src/lib/my_putchar.c\
		src/lib/my_putstr.c\
		src/lib/my_calloc.c\
		src/lib/my_putnbr.c\
		src/lib/my_pow.c\
		\
		src/linked_list/list_array.c\
		src/linked_list/list.c\
		\
		src/visual/init_visuals.c\
		src/visual/visuals.c\
		src/visual/events.c

MAIN_SRC	=	src/main.c
OBJ	=	$(SRC:.c=.o) $(MAIN_SRC:.c=.o)
NAME	=	corewar
LIB	=	-lncurses
CFLAGS += -Wall -Wextra -pedantic
CPPFLAGS	+= -Iinclude/
ifeq ($(ENV), dev)
	CFLAGS	+=	-g3
endif

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(LIB)

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
