/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** pause.c
*/

#include "my_rpg.h"

void pause_menu(game_t *game, object_t *obj)
{
    sfRenderWindow_drawSprite(game->window, obj[5].spr, NULL);
}
