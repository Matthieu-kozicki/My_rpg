/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** quest system
*/

#include "my_rpg.h"

void quest(game_t *game, object_t *obj)
{
    if (obj->quest == 1)
        sfRenderWindow_drawSprite(game->window, obj[37].spr, NULL);
    if (obj->quest == 2)
        sfRenderWindow_drawSprite(game->window, obj[38].spr, NULL);
}
