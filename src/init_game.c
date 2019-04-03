/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** initialize game variables
*/

#include "my_rpg.h"

void load_window(game_t *game)
{
    sfVideoMode mode = {1600, 900, 32};

    game->window = sfRenderWindow_create
    (mode, "my_rpg", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(game->window, 60);
    game->view = sfView_createFromRect((sfFloatRect) {0, 0, 192, 152});
    game->view_2 = sfView_createFromRect((sfFloatRect) {0, 0, 1600, 900});
    sfView_setCenter(game->view, (sfVector2f){25 + 0, 25 + 0});
    game->clock = sfClock_create();

}

void init_game_variables(game_t *game, object_t *obj)
{
    game->screen = 0;
    sfSprite_setOrigin(obj[0].spr,(sfVector2f){416, 293});
    sfSprite_setOrigin(obj[1].spr,(sfVector2f){416, 293});
    sfSprite_setScale(obj[0].spr,(sfVector2f){0.5, 0.5});
    sfSprite_setScale(obj[1].spr,(sfVector2f){0.5, 0.5});
    obj->moused = 0;
}
