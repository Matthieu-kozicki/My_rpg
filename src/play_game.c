/*
** EPITECH PROJECT, 2019
** play_game.c
** File description:
** ...
*/

#include "my_rpg.h"

void play_game(game_t *game, object_t *obj)
{
    sfRenderWindow_drawSprite(game->window, obj[3].spr, NULL);
    sfRenderWindow_drawSprite(game->window, obj[4].spr, NULL);
    sfSprite_setTextureRect(obj[4].spr, obj[4].rect);
    sfSprite_move(obj[4].spr, obj[4].vector);
}