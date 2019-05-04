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

void win_lose(game_t *game, object_t *obj)
{
    if (obj->quest <= 8)
        sfRenderWindow_drawSprite(game->window, obj[44].spr, NULL);
    else {
        //set spr
       sfRenderWindow_drawSprite(game->window, obj[45].spr, NULL);
       sfRenderWindow_drawSprite(game->window,
       game->combat->tmp2->spr->spr, NULL);
    }
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
        if (game->screen == 1) play_game(game, obj);
        if (game->screen == 2) pause_menu(game, obj);
        if (game->screen == 3) menu(game, obj);
        if (game->screen == 0) animation(game, obj);
        if (game->screen == 5) combat_loop(game, obj);
        if (game->screen == 4) menu_option(game, obj);
        if (game->screen == 6) shop(game, obj);
        if (game->screen == 7) inventory(game, obj);
        if (game->screen == 8) win_lose(game, obj);
        sfRenderWindow_display(game->window);
    }
}
