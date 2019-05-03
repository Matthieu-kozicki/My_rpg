##
## EPITECH PROJECT, 2019
## my_rpg
## File description:
## Makefile
##

NAME	=	my_rpg

SRC	=	src/main.c			\
		src/add_functions.c		\
		src/game_loop.c 		\
		src/init_game.c 		\
		src/load_object.c		\
		src/menu_start.c 		\
		src/manage_event.c		\
		src/play_game.c			\
		src/combat/combat.c		\
		src/combat/combatloop.c		\
		src/combat/init_combat.c	\
		src/combat/list.c		\
		src/combat/combat_ia.c		\
		src/pause.c			\
		src/menu_option.c		\
		src/move_hero.c			\
		src/error/error.c		\
		src/array/array.c		\
		src/array/manag_map.c		\
		src/keybind/keybinding.c	\
		src/putinstr.c			\
		src/clocks.c			\
		src/inventory.c			\
		src/particles/create.c	\
		src/particles/launch.c	\
		src/particles/mutations.c	\
		src/quest/quest.c		\
		src/quest/int_to_char.c		\
		src/shop/shopping.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra -g3

CPPFLAGS =	-I./include

LDLIB	=	-lcsfml-window -lcsfml-graphics -lcsfml-system -lcsfml-audio -lm

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) $(LDLIB)

debug:		CFLAGS += -g3
debug:		re

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME) rm -f *~  rm *#

re:		fclean all

.PHONY:		all debug clean fclean re
