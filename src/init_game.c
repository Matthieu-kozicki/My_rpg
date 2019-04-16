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
    game->music = sfMusic_createFromFile("sound/music.ogg");
    sfMusic_setLoop(game->music, sfTrue);
    sfMusic_play(game->music);
    //game->test = alloc_2d_array(10, 100);
    //check_pokefile("src/combat/tortank.pokefile", game->test);
}

void init_game_variables(game_t *game, object_t *obj)
{
    game->volume = 100;
    game->screen = 0;
    game->cursor_pos = 0;
    sfSprite_setOrigin(obj[0].spr,(sfVector2f){416, 293});
    sfSprite_setOrigin(obj[1].spr,(sfVector2f){416, 293});
    sfSprite_setScale(obj[0].spr,(sfVector2f){0.5, 0.5});
    sfSprite_setScale(obj[1].spr,(sfVector2f){0.5, 0.5});
    for (int i = 6; i < 21; i++)
        sfSprite_setScale(obj[i].spr,(sfVector2f){2.5, 2.5});
    for (int i = 23; i < 26; i++)
        sfSprite_setScale(obj[i].spr,(sfVector2f){2.5, 2.5});
    obj->moused = 0;
}
