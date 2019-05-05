/*
** EPITECH PROJECT, 2019
** play_game.c
** File description:
** ...
*/

#include "my_rpg.h"

void quest_next(game_t *game, object_t *obj)
{
    if (game->pos_x == 28 && game->pos_y == 87
        && sfKeyboard_isKeyPressed(sfKeyE) && obj->quest >= 3) {
        game->screen = 6;
        sfSleep((sfTime) {200000});
    }
    if (obj->quest == 7) {
        find_randpoke(game);
        game->combat->difficulty = 6;
        game->combat->poke[0].info[NAME] = "A S T E K";
        game->combat->poke[0].info[ATK_NAME] = "Man Google !";
        game->combat->poke[0].stats[HP] = randint(90, 200);
        game->combat->poke[0].stats[ACTUAL_HP] = game->combat->poke[0].stats[HP];
        game->combat->poke[0].stats[DEF] = randint(5, 20);
        game->combat->poke[0].stats[ATK] = randint(10, 35);
        load_poke_sprites(game->combat);
        obj->quest = 8;
        game->screen = 5;
    }
}

void play_quest(game_t *game, object_t *obj)
{
    if (game->pos_x == 27 && game->pos_y == 94
        && sfKeyboard_isKeyPressed(sfKeyE) && obj->quest == 1) {
        obj->quest = 2;
        sfSleep((sfTime) {200000});
    }
    if (game->pos_x == 19 && game->pos_y == 47
        && sfKeyboard_isKeyPressed(sfKeyE) && obj->quest == 3) {
        obj->quest = 4;
        sfSleep((sfTime) {200000});
    }
    if (game->pos_x == 36 && game->pos_y == 12
        && sfKeyboard_isKeyPressed(sfKeyE) && obj->quest == 5) {
        obj->quest = 6;
        sfSleep((sfTime) {200000});
    }
    quest_next(game, obj);

}

void play_game(game_t *game, object_t *obj)
{
    game->time = sfClock_getElapsedTime(game->clock);
    game->second = game->time.microseconds / 100000;
    if (game->second > 5) {
        rand_combat(game, obj);
        sfClock_restart(game->clock);
    }
    sfRenderWindow_drawSprite(game->window, obj[36].spr, NULL);
    sfRenderWindow_drawSprite(game->window, obj[3].spr, NULL);
    sfRenderWindow_setView (game->window, game->view);
    sfRenderWindow_drawSprite(game->window, obj[4].spr, NULL);
    sfRenderWindow_drawSprite(game->window, obj[33].spr, NULL);
    sfRenderWindow_drawSprite(game->window, obj[31].spr, NULL);
    sfSprite_setTextureRect(obj[4].spr, obj[4].rect);
    if (sfKeyboard_isKeyPressed(sfKeyI)) {
        game->screen = 7;
        sfMusic_play(game->inv);
    }
    if (sfKeyboard_isKeyPressed(sfKeyP))
        quest(game, obj);
    play_quest(game, obj);
    dialogue(game, obj);
}
