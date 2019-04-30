/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"

void destroy_game(game_t *game)
{
    free_array(102, game->tab);
    sfRenderWindow_destroy(game->window);
    sfMusic_destroy(game->music);
}

int help(void)
{
    write(1,"A RPG game created with CSFML.\n\n\n",33);
    write(1,"Z on keyboard : to move foreward\n",33);
    write(1,"S on keyboard : to move backward\n",33);
    write(1,"Q on keyboard : to move on the left\n",36);
    write(1,"D on keyboard : to move on the right\n",37);
    write(1,"I on keyboard : to open the inventory\n",38);
    return (0);
}

int main(int arc, char **arg, char **env)
{
    object_t *obj = malloc(sizeof(object_t) * 42);
    game_t *game = malloc(sizeof(game_t));

    if (arc == 2 && arg[1][0] == '-' && arg[1][1] == 'h' && !arg[1][2])
        return (help());
    if (arc != 1 || env[0] == NULL) {
        write(2, "Bad Argument\n", 13);
	return (84);
    }
    if (check_env(env) == 0)
        return (84);
    load_window(game);
    obj = load_object(obj);
    init_game_variables(game, obj);
    game_loop(game, obj);
    destroy_game(game);
    return (0);
}
