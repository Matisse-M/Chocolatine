##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile to compil the -lmy
##

SRC		=	main.c

OBJ 	= 	$(SRC:.c=.o)

NAME	= 	a.out

CFLAGS 	=	-I ./include

CC 		= 	gcc

all:	$(NAME)

$(NAME):	$(OBJ)
		@$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
		@rm -f $(OBJ)

fclean: clean
		@$(RM) $(NAME)

tests_run: all

re: fclean all
