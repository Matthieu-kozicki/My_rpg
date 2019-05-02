/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** animation at the begin
*/

#include "my_rpg.h"

void menu2(game_t *game, object_t *obj)
{
    if (mouse_is_on(game, (sfVector2f){725, 300}, 160, 80) == 1) {
        sfRenderWindow_drawSprite(game->window, obj[16].spr, NULL);
        if (obj->moused == 1)
            sfRenderWindow_drawSprite(game->window, obj[17].spr, NULL);
        if (obj->clicked == 1)
            game->screen = 1;
    }
}

void menu(game_t *game, object_t *obj)
{
    sfRenderWindow_drawSprite(game->window, obj[22].spr, NULL);
    sfRenderWindow_drawSprite(game->window, obj[6].spr, NULL);
    sfRenderWindow_drawSprite(game->window, obj[12].spr, NULL);
    sfRenderWindow_drawSprite(game->window, obj[15].spr, NULL);
    if (mouse_is_on(game, (sfVector2f){725, 700}, 160, 80) == 1) {
        sfRenderWindow_drawSprite(game->window, obj[7].spr, NULL);
        if (obj->moused == 1)
            sfRenderWindow_drawSprite(game->window, obj[8].spr, NULL);
        if (obj->clicked == 1)
            sfRenderWindow_close(game->window);
    }
    if (mouse_is_on(game, (sfVector2f){725, 500}, 160, 80) == 1) {
        sfRenderWindow_drawSprite(game->window, obj[13].spr, NULL);
        if (obj->moused == 1)
            sfRenderWindow_drawSprite(game->window, obj[14].spr, NULL);
        if (obj->clicked == 1) {
            game->screen = 4;
        }
    }
    menu2(game, obj);
}

void animation_next(game_t *game, object_t *obj, int i)
{
    if (obj->moused == 1 || i > 280)
        game->screen = 3;
    sfRenderWindow_drawSprite(game->window, obj[0].spr, NULL);
}

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
    animation_next(game, obj, i);
}
