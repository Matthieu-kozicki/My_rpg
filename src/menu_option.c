/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** option in menu
*/

#include "my_rpg.h"

void music_volume(game_t *game, float vol)
{
    sfMusic_setVolume(game->music, vol);
    sfMusic_setVolume(game->step, vol);
    sfMusic_setVolume(game->inv, vol);
    sfMusic_setVolume(game->click, vol);
    sfMusic_setVolume(game->bad, vol);
    sfMusic_setVolume(game->dmg, vol);
    sfMusic_setVolume(game->buy, vol);
    sfMusic_setVolume(game->fight, vol);
}

void menu_option2(game_t *game, object_t *obj)
{
    if (mouse_is_on(game, (sfVector2f){945, 520}, 20, 20) == 1) {
        if (obj->moused == 1 && game->volume < 100) {
            game->volume += 10;
            obj[27].rect.left += 123;
            sfSprite_setTextureRect(obj[27].spr, obj[27].rect);
            music_volume(game, game->volume);
            sfSleep((sfTime){150000});
        }
    }
    sfRenderWindow_drawSprite(game->window, obj[23].spr, NULL);
    sfRenderWindow_drawSprite(game->window, obj[30].spr, NULL);
    keybinding(game, obj);
    if (mouse_is_on(game, (sfVector2f){1480, 800}, 120, 100) == 1
    && obj->moused == 1)
        sfMusic_setVolume(game->music, 0);
}

void menu_option(game_t *game, object_t *obj)
{
    sfRenderWindow_drawSprite(game->window, obj[26].spr, NULL);
    sfRenderWindow_drawSprite(game->window, obj[27].spr, NULL);
    if (mouse_is_on(game, (sfVector2f){725, 800}, 160, 80) == 1) {
        sfRenderWindow_drawSprite(game->window, obj[24].spr, NULL);
        if (obj->moused == 1)
            sfRenderWindow_drawSprite(game->window, obj[25].spr, NULL);
        if (obj->clicked == 1) {
            game->screen = 3;
            sfSleep((sfTime){150000});
        }
    }
    if (mouse_is_on(game, (sfVector2f){660, 520}, 20, 20) == 1) {
        if (obj->moused == 1 && game->volume > 0) {
            game->volume -= 10;
            obj[27].rect.left -= 123;
            sfSprite_setTextureRect(obj[27].spr, obj[27].rect);
            music_volume(game, game->volume);
            sfSleep((sfTime){150000});
        }
    }
    menu_option2(game, obj);
}
