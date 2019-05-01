/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** inventory
*/

#include "my_rpg.h"

void inventory(game_t *game, object_t *obj)
{
    poke_t *tmp = game->combat->list;

    sfRenderWindow_drawSprite(game->window, obj[34].spr, NULL);
    while (tmp->next != NULL) {
        sfRenderWindow_drawSprite(game->window, tmp->spr->spr, NULL);
        sfRenderWindow_drawText(game->window, tmp->inv, NULL);
        tmp = tmp->next;
    }
    if (mouse_is_on(game, (sfVector2f){1475, 8}, 100, 95) == 1) {
        sfRenderWindow_drawSprite(game->window, obj[35].spr, NULL);
        if (obj->moused == 1)
            game->screen = 1;
    }
}
