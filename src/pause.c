/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** pause.c
*/

#include "my_rpg.h"

void pause_menu2(game_t *game, object_t *obj)
{
    if (mouse_is_on(game, (sfVector2f){1025, 700}, 160, 80) == 1) {
        sfRenderWindow_drawSprite(game->window, obj[10].spr, NULL);
        if (obj->moused == 1)
            sfRenderWindow_drawSprite(game->window, obj[11].spr, NULL);
        if (obj->clicked == 1)
            game->screen = 3;
    }
}

void pause_menu(game_t *game, object_t *obj)
{
    sfRenderWindow_drawSprite(game->window, obj[21].spr, NULL);
    sfRenderWindow_drawSprite(game->window, obj[6].spr, NULL);
    sfRenderWindow_drawSprite(game->window, obj[9].spr, NULL);
    sfRenderWindow_drawSprite(game->window, obj[18].spr, NULL);
    if (mouse_is_on(game, (sfVector2f){725, 700}, 160, 80) == 1) {
        sfRenderWindow_drawSprite(game->window, obj[7].spr, NULL);
        if (obj->moused == 1)
            sfRenderWindow_drawSprite(game->window, obj[8].spr, NULL);
        if (obj->clicked == 1)
            sfRenderWindow_close(game->window);
    }
    if (mouse_is_on(game, (sfVector2f){425, 700}, 160, 80) == 1) {
        sfRenderWindow_drawSprite(game->window, obj[19].spr, NULL);
        if (obj->moused == 1)
            sfRenderWindow_drawSprite(game->window, obj[20].spr, NULL);
        if (obj->clicked == 1)
            game->screen = 1;
    }
    pause_menu2(game, obj);
}
