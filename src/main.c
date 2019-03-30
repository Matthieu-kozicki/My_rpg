/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"

void destroy_game(game_t *game)
{
    sfRenderWindow_destroy(game->window);
    //destroy array of sprite
}

int help(void)
{
    write(1,"A RPG game created with CSFML.\n\n",32);
    return (0);
}

int main(int arc, char **arg, char **env)
{
    object_t *obj = malloc(sizeof(object_t) * 12); //nbr of sprite
    game_t *game = malloc(sizeof(game_t));

    if (arc == 2 && arg[1][0] == '-' && arg[1][1] == 'h' && !arg[1][2])
        return (help());
    if (arc != 1 || env[0] == NULL) {
        write(2, "Bad Argument\n", 13);
	return (84);
    }
    load_window(game);
    obj = load_object(obj);
    init_game_variables(game, obj);
    game_loop(game, obj);
    destroy_game(game);
    //free struct..
    return (0);
}
