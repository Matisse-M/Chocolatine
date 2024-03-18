##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile to compil the -lmy
##

SRC		=	main.c					\
			src/structure.c 		\
			src/fill_structure.c	\
			src/toolbar.c			\
			src/hover_toolbar.c		\
			src/scenes_toolbar.c	\
			src/save.c				\
			src/drawing.c			\
			src/my_paint.c			\
			src/paint_two.c			\
			src/paint_three.c		\
			src/exit_menu.c			\
			src/shader.c			\
			src/rename.c			\
			src/alphabet.c			\
			src/my_alpha.c 			\
			src/my_alpha_maj.c 		\
			src/my_num.c			\
			src/opening.c			\
			src/open_struct.c		\
			src/help_menu.c			\
			src/file_btn.c 	   		\
			src/edit_btn.c 	   		\
			src/help_btn.c 	   		\
			src/destroys.c			\
			src/about.c				\
			src/layers.c			\
			src/shapes.c			\
			src/stamps.c			\
			src/get_files.c

NAME	= 	my_paint

INCLUDE =	-I ./include

LIB 	=	-L ./lib -lcsfml -L ./lib -lmy

CSFML	=	-lcsfml-window -lcsfml-graphics -lcsfml-system -lcsfml-audio \
			-lcsfml-network -lm

all:	$(NAME)

$(NAME):
		@make -C ./lib/csfml
		@make -C ./lib/my
		@cp -f ./lib/csfml/csfml.h ./include
		@cp -f ./lib/my/my.h ./include
		@gcc -g -o $(NAME) $(SRC) $(INCLUDE) $(LIB) $(CSFML)
		@echo -e "\e[1;36m{ Binary ready !! }\e[00;37m"

clean:
		@rm -f *~
		@make clean -C ./lib/csfml
		@make clean -C ./lib/my
		@echo -e "\e[1;33m[ Useless files have been deleted ]\e[00;37m"

fclean: clean
		@rm -f $(NAME)
		@rm -rf lib/libcsfml.a lib/libmy.a
		@make fclean -C ./lib/csfml
		@make fclean -C ./lib/my
		@echo -e "\e[1;33m[ Binary has been deleted ]\e[00;37m"

norm:
	@make clean
	@make fclean
	@coding-style . .
	@cat coding-style-reports.log

re: fclean all
