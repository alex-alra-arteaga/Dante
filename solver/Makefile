##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile that compiles
##

SRC =	$(wildcard ../lib/my/utils/*.c) \
		$(wildcard *.c)

OBJ = 	$(SRC:.c=.o)

NAME = solver

CFLAGS = -I ../includes/ -g3

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -g3 -W -Werror -Wall -Wextra -o $(NAME) $(OBJ) $(CFLAGS)

lib:
	make -C -lmy

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
