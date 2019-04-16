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
    sfMusic_destroy(game->music);
}

int help(void)
{
    write(1,"A RPG game created with CSFML.\n\n",32);
    return (0);
}

/*int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}

int my_strcomp(char *str, char *dest)
{
    int len = my_strlen(str);
    int i = 0;

    for (int k = 0; dest[k] != '\0'; k++)
        if (str[i] == dest[i])
            i++;
    if (i == len)
        return (1);
    else
        return (2);
}

int check_env(char **env)
{
    for (int i = 0; env[i] != NULL; i++)
        if (my_strcomp("DISPLAY=:0", env[i]) == 1)
            return (1);
    write(1, "You need 'DISPLAY=:0' in your ENV\n", 34);
    return (0);
    }*/

int main(int arc, char **arg, char **env)
{
    object_t *obj = malloc(sizeof(object_t) * 30);
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
