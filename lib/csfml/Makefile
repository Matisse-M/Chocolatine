##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile to compil the -lmy
##

SRC		=	my_close_button.c		\
			my_custom_rectangle.c 	\
			my_custom_text.c 		\
			my_framebuffer.c 		\
			my_hover_effect.c 		\
			my_put_pixel.c 			\
			my_set_circle.c 		\
			my_set_music.c 			\
			my_set_rectangle.c 		\
			my_set_sprite.c 		\
			my_set_text.c 			\
			my_set_window.c

OBJ 	= 	$(SRC:.c=.o)

NAME	= 	libcsfml.a

CSFML 	= 	-lcsfml-window -lcsfml-graphics -lcsfml-system -lcsfml-audio \
			-lcsfml-network

all:	$(NAME)

$(NAME):	$(OBJ)
		@$(AR) rc $(NAME) $(OBJ)
		@cp -f $(NAME) ..
		@echo -e "\e[1;36m{ libcsfml.a ready and .h duplicated !! }\e[00;37m"

clean:
		@$(RM) $(OBJ) *~
		@echo -e "\e[1;33m[ Useless files have been deleted ]\e[00;37m"

fclean: clean
		@$(RM) $(NAME)
		@echo -e "\e[1;33m[ libcsfml.a has been deleted ]\e[00;37m"

re: fclean all
