/*
** EPITECH PROJECT, 2019
** play_game.c
** File description:
** ...
*/

#include "my_rpg.h"

void play_game(game_t *game, object_t *obj)
{
    game->time = sfClock_getElapsedTime(game->clock);
    game->second = game->time.microseconds / 100000;
    if (game->second > 1) {
        move_rect(&obj[4].rect, 50, 200);
        sfClock_restart(game->clock);
    }
    sfRenderWindow_drawSprite(game->window, obj[3].spr, NULL);
    sfRenderWindow_setView (game->window, game->view);
    sfRenderWindow_drawSprite(game->window, obj[4].spr, NULL);
    sfRenderWindow_drawSprite(game->window, obj[33].spr, NULL);
    sfRenderWindow_drawSprite(game->window, obj[36].spr, NULL);
    sfRenderWindow_drawSprite(game->window, obj[31].spr, NULL);
    sfSprite_setTextureRect(obj[4].spr, obj[4].rect);
    if (sfKeyboard_isKeyPressed(sfKeyI))
        game->screen = 6;
}
