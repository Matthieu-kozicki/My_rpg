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
    sfView_setCenter(game->view, (sfVector2f){25 + 271, 25 + 1356});
    game->clock = sfClock_create();
    game->clock_2 = sfClock_create();
    game->music = sfMusic_createFromFile("sound/music.ogg");
    sfMusic_setLoop(game->music, sfTrue);
    sfMusic_play(game->music);
    game->combat = malloc(sizeof(combat_t));
    init_combat(game->combat);
}

void init_game_variables2(game_t *game, object_t *obj)
{
    game->volume = 100;
    sfSprite_setScale(obj[32].spr,(sfVector2f){0.40, 0.5});
    sfSprite_setScale(obj[37].spr,(sfVector2f){0.35, 0.4});
    sfSprite_setScale(obj[38].spr,(sfVector2f){0.35, 0.4});
    sfSprite_setScale(obj[39].spr,(sfVector2f){0.35, 0.4});
    sfSprite_setScale(obj[40].spr,(sfVector2f){0.40, 0.5});
    sfSprite_setScale(obj[41].spr,(sfVector2f){0.40, 0.5});
    obj->quest = 1;
    game->stock = ' ';
    game->combat->tmp = game->combat->list;
    game->combat->money = 2000;
}

void init_game_variables(game_t *game, object_t *obj)
{
    game->screen = 0;
    game->cursor_pos = 0;
    game->tab = map(5051, game->tab);
    sfSprite_setOrigin(obj[0].spr,(sfVector2f){416, 293});
    sfSprite_setOrigin(obj[1].spr,(sfVector2f){416, 293});
    sfSprite_setScale(obj[0].spr,(sfVector2f){0.5, 0.5});
    sfSprite_setScale(obj[1].spr,(sfVector2f){0.5, 0.5});
    for (int i = 6; i < 21; i++)
        sfSprite_setScale(obj[i].spr,(sfVector2f){2.5, 2.5});
    for (int i = 23; i < 26; i++)
        sfSprite_setScale(obj[i].spr,(sfVector2f){2.5, 2.5});
    obj->moused = 0;
    sfSprite_setScale(obj[27].spr,(sfVector2f){2.5, 2.5});
    obj[27].rect.height = 25;
    obj[27].rect.width = 123;
    obj[27].rect.left = 1230;
    sfSprite_setTextureRect(obj[27].spr, obj[27].rect);
    sfSprite_setScale(obj[31].spr,(sfVector2f){0.1, 0.1});
    sfSprite_setScale(obj[30].spr,(sfVector2f){0.45, 0.45});
    init_game_variables2(game, obj);
}
