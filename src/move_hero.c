/*
** EPITECH PROJECT, 2019
** .c
** File description:
** ...
*/

#include "my_rpg.h"

void move_ui(object_t *obj, sfVector2f vector, game_t *game)
{
    sfSprite_move(obj[4].spr, vector);
    sfSprite_move(obj[31].spr, vector);
    sfSprite_move(obj[37].spr, vector);
    sfSprite_move(obj[38].spr, vector);
    sfSprite_move(obj[39].spr, vector);
    sfView_move (game->view, vector);
    move_rect(&obj[4].rect, 50, 200);
}

void move_hero_2(sfEvent event, object_t *obj, game_t *game)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyS
        && obj->quest % 2 != 0) {
        obj[4].rect.top = 0;
        if (test_block(1, 0, game) == 1 || test_block(1, 0, game) == 2) {
            move_ui(obj, (sfVector2f){0, 16}, game);
            game->tab[game->pos_y][game->pos_x] = game->stock;
            game->stock = last_pos(game->stock, 1, 0, game);
            game->tab[game->pos_y + 1][game->pos_x] = 'P';
        }
    }
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyD
        && obj->quest % 2 != 0) {
        obj[4].rect.top = 150;
        if (test_block(0, 1, game) == 1) {
            move_ui(obj, (sfVector2f){16, 0}, game);
            game->tab[game->pos_y][game->pos_x] = game->stock;
            game->stock = last_pos(game->stock, 0, 1, game);
            game->tab[game->pos_y][game->pos_x + 1] = 'P';
        }
    }
}

void move_hero_1(sfEvent event, object_t *obj, game_t *game)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyZ
        && obj->quest % 2 != 0) {
        obj[4].rect.top = 50;
        if (game->combat->inv->next == NULL &&
        game->tab[game->pos_y - 1][game->pos_x + 0] == 'B') {
            return;
        }
        if (test_block(-1, 0, game) == 1) {
            move_ui(obj, (sfVector2f){0, -16}, game);
            game->tab[game->pos_y][game->pos_x] = game->stock;
            game->stock = last_pos(game->stock, -1, 0, game);
            game->tab[game->pos_y - 1][game->pos_x] = 'P';
        }
    }
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyQ
        && obj->quest % 2 != 0) {
        obj[4].rect.top = 100;
        if (test_block(0, -1, game) == 1) {
            move_ui(obj, (sfVector2f){-16, 0}, game);
            game->tab[game->pos_y][game->pos_x] = game->stock;
            game->stock = last_pos(game->stock, 0, -1, game);
            game->tab[game->pos_y][game->pos_x - 1] = 'P';
        }
    }
    move_hero_2(event, obj, game);
}
