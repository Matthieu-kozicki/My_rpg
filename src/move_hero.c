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
        obj[4].vector.x = 0;
        obj[4].vector.y = 2.0;
        sfView_move (game->view, obj[4].vector);
        sfSprite_move(obj[4].spr, obj[4].vector);
    }
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyD) {
        obj[4].rect.top = 150;
        obj[4].vector.x = 2.0;
        obj[4].vector.y = 0;
        sfView_move (game->view, obj[4].vector);
        sfSprite_move(obj[4].spr, obj[4].vector);
    }
}

void move_hero_1(sfEvent event, object_t *obj, game_t *game)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyZ) {
        obj[4].rect.top = 50;
        obj[4].vector.x = 0;
        obj[4].vector.y = -2.0;
        sfView_move (game->view, obj[4].vector);
        sfSprite_move(obj[4].spr, obj[4].vector);
    }
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyQ) {
        obj[4].rect.top = 100;
        obj[4].vector.x = -2.0;
        obj[4].vector.y = 0;
        sfView_move (game->view, obj[4].vector);
        sfSprite_move(obj[4].spr, obj[4].vector);
    }
    move_hero_2(event, obj, game);
}