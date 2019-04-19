/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** looping
*/

#include "my_rpg.h"

int mouse_is_on(game_t *game, sfVector2f position, int x_max, int y_max)
{
    if (game->mouse.x <= position.x + x_max
        && game->mouse.y <= position.y + y_max
        && game->mouse.x >= position.x
        && game->mouse.y >= position.y) {
        return (1);
    }
    return (0);
}

void game_loop(game_t *game, object_t *obj)
{
    while (sfRenderWindow_isOpen(game->window)) {
        check_pos(game);
        manage_clock(game->combat);
        manage_events(game, obj);
        sfRenderWindow_clear(game->window, sfBlack);
        if (game->screen != 1)
            sfRenderWindow_setView (game->window, game->view_2);
        if (game->screen == 1)
            play_game(game, obj);
        if (game->screen == 2)
            pause_menu(game, obj);
        if (game->screen == 3)
            menu(game, obj);
        if (game->screen == 0)
            animation(game, obj);
        if (game->screen == 5) combat_loop(game, obj);
        if (game->screen == 4) menu_option(game, obj);
        if (game->screen == 6) inventory(game, obj);
        sfRenderWindow_display(game->window);
    }
}
