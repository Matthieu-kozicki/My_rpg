/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** option in menu
*/

#include "my_rpg.h"

void menu_option2(game_t *game, object_t *obj)
{
    if (mouse_is_on(game, (sfVector2f){725, 500}, 160, 80) == 1) {
        sfRenderWindow_drawSprite(game->window, obj[10].spr, NULL);
        if (obj->moused == 1 && game->volume < 100) {
            sfRenderWindow_drawSprite(game->window, obj[11].spr, NULL);
            game->volume += 20;
            sfMusic_setVolume(game->music, game->volume);
            sfSleep((sfTime){300000});
        }
    }
}

void menu_option(game_t *game, object_t *obj)
{
    sfRenderWindow_drawSprite(game->window, obj[26].spr, NULL);
    sfRenderWindow_drawSprite(game->window, obj[27].spr, NULL);
    sfRenderWindow_drawSprite(game->window, obj[23].spr, NULL);
    if (mouse_is_on(game, (sfVector2f){725, 800}, 160, 80) == 1) {
        sfRenderWindow_drawSprite(game->window, obj[24].spr, NULL);
        if (obj->moused == 1)
            sfRenderWindow_drawSprite(game->window, obj[25].spr, NULL);
        if (obj->clicked == 1) {
            game->screen = 3;
            sfSleep((sfTime){300000});
        }
    }
    if (mouse_is_on(game, (sfVector2f){725, 700}, 160, 80) == 1) {
        sfRenderWindow_drawSprite(game->window, obj[19].spr, NULL);
        if (obj->moused == 1 && game->volume > 0) {
            sfRenderWindow_drawSprite(game->window, obj[20].spr, NULL);
            game->volume -= 20;
            sfMusic_setVolume(game->music, game->volume);
            sfSleep((sfTime){300000});
        }
    }
    menu_option2(game, obj);
}
