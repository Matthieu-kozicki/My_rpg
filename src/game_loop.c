/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** looping
*/

#include "my_rpg.h"

void game_loop(game_t *game, object_t *obj)
{
    int i = 0;

    while (sfRenderWindow_isOpen(game->window)) {
        manage_events(game, obj);
        sfRenderWindow_clear(game->window, sfBlack);
        if (game->screen == 1)
            play_game(game, obj);
        if (game->screen == 2)
            pause_menu(game, obj);
        if (game->screen == 3)
            i = i;//lose screen
        if (game->screen == 0)
            animation(game, obj);
        if (game->screen == 4) combat_loop(game, obj);
        sfRenderWindow_display(game->window);
    }

}
