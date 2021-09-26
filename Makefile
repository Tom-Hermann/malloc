##
## EPITECH PROJECT, 2021
## B-PSU-400-RUN-4-1-malloc-tom.hermann
## File description:
## Makefile
##



SRC				=	malloc.c		\
					free.c			\
					calloc.c 		\
					realloc.c		\
					reallocarray.c	\
					add_size.c

OBJ				=	$(SRC:.c=.o)

INCLUDE			=	-I./include

NAME			=	libmy_malloc.so

CFLAGS			=	-c -fpic -W -Werror -Wall -Wextra -g -I./include

RM				=	rm -rf


all:		$(NAME)

$(NAME): $(OBJ)
		gcc -shared -o $(NAME) $(OBJ)

clean:
		$(RM) *.o

fclean:		clean fclean_ut
		$(RM) $(NAME)
		$(RM) *.gcda *.gcno

fclean_ut:	clean
		$(RM) $(NAME_UT)
		$(RM) *.gcda *.gcno

re:		fclean all
