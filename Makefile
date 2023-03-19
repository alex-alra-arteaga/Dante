##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile that compiles
##

all:
	make -C generator
	make -C solver

clean:
	rm -rf $(OBJ)

fclean: clean
	make -C generator fclean
	make -C solver fclean
	rm -rf $(NAME)

re: fclean all
