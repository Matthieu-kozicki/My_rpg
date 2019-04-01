##
## EPITECH PROJECT, 2019
## my_rpg
## File description:
## Makefile
##

CC	=	gcc

SRC	=	src/main.c		\
		src/game_loop.c 	\
		src/init_game.c 	\
		src/load_object.c	\
		src/animation.c 	\
		src/manage_event.c	\
		src/play_game.c		\
		src/combat/combat.c	\
		src/pause.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_rpg

CFLAGS	=	-I./include -Wall -Wextra -g3

LDLIB	=	-lcsfml-window -lcsfml-graphics -lcsfml-system -lcsfml-audio -lm

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc $(OBJ) -o $(NAME) $(LDLIB)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
