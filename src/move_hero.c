/*
** EPITECH PROJECT, 2019
** .c
** File description:
** ...
*/

#include "my_rpg.h"

void move_hero_2(sfEvent event, object_t *obj, game_t *game)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyS) {
        obj[4].rect.top = 0;
        if (test_block(1, 0, game) == 1 || test_block(1, 0, game) == 2) {
            sfSprite_move(obj[4].spr, (sfVector2f){0, 16});
            sfSprite_move(obj[31].spr, (sfVector2f){0, 16});
            sfView_move (game->view, (sfVector2f){0, 16});
            game->tab[game->pos_y][game->pos_x] = game->stock;
            game->stock = last_pos(game->stock, 1, 0, game);
            game->tab[game->pos_y + 1][game->pos_x] = 'P';
        }
    }
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyD) {
        obj[4].rect.top = 150;
        if (test_block(0, 1, game) == 1) {
            sfSprite_move(obj[4].spr, (sfVector2f){16, 0});
            sfSprite_move(obj[31].spr, (sfVector2f){16, 0});
            sfView_move (game->view, (sfVector2f){16, 0});
            game->tab[game->pos_y][game->pos_x] = game->stock;
            game->stock = last_pos(game->stock, 0, 1, game);
            game->tab[game->pos_y][game->pos_x + 1] = 'P';
        }
    }
}

void move_hero_1(sfEvent event, object_t *obj, game_t *game)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyZ) {
        obj[4].rect.top = 50;
        if (test_block(-1, 0, game) == 1) {
            sfSprite_move(obj[4].spr, (sfVector2f){0, -16});
            sfSprite_move(obj[31].spr, (sfVector2f){0, -16});
            sfView_move (game->view, (sfVector2f){0, -16});
            game->tab[game->pos_y][game->pos_x] = game->stock;
            game->stock = last_pos(game->stock, -1, 0, game);
            game->tab[game->pos_y - 1][game->pos_x] = 'P';
        }
    }
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyQ) {
        obj[4].rect.top = 100;
        if (test_block(0, -1, game) == 1) {
            sfSprite_move(obj[4].spr, (sfVector2f){-16, 0});
            sfSprite_move(obj[31].spr, (sfVector2f){-16, 0});
            sfView_move (game->view, (sfVector2f){-16, 0});
            game->tab[game->pos_y][game->pos_x] = game->stock;
            game->stock = last_pos(game->stock, 0, -1, game);
            game->tab[game->pos_y][game->pos_x - 1] = 'P';
        }
    }
    move_hero_2(event, obj, game);
}
