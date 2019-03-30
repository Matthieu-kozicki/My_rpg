/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** animation at the begin
*/

#include "my_rpg.h"

void animation(game_t *game, object_t *obj)
{
    static int i = 0;

    i++;
    sfRenderWindow_drawSprite(game->window, obj[2].spr, NULL);
    if (i < 120) {
        sfSprite_rotate(obj[0].spr, 3);
        sfSprite_rotate(obj[1].spr, -3);;
        sfSprite_move(obj[0].spr, (sfVector2f){4, 0});
        sfSprite_move(obj[1].spr, (sfVector2f){-4, 0});
        sfRenderWindow_drawSprite(game->window, obj[1].spr, NULL);
    }
    else if (i < 241) {
        sfSprite_rotate(obj[0].spr, 3);
        sfSprite_rotate(obj[1].spr, -3);;
        sfSprite_move(obj[0].spr, (sfVector2f){4, 0});
        sfSprite_move(obj[1].spr, (sfVector2f){-4, 0});
        sfRenderWindow_drawSprite(game->window, obj[1].spr, NULL);
    }
    if (obj->moused == 1)
        game->screen = 1;
    sfRenderWindow_drawSprite(game->window, obj[0].spr, NULL);
}
