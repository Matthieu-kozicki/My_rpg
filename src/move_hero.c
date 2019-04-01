/*
** EPITECH PROJECT, 2019
** .c
** File description:
** ...
*/

#include "my_rpg.h"

void move_hero_2(sfEvent event, object_t *obj)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyS) {
        obj[4].rect.top = 0;
        obj[4].vector.x = 0;
        obj[4].vector.y = 1;
    }
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyD) {
        obj[4].rect.top = 150;
        obj[4].vector.x = 1;
        obj[4].vector.y = 0;
    }
}

void move_hero_1(sfEvent event, object_t *obj)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyZ) {
        obj[4].rect.top = 50;
        obj[4].vector.x = 0;
        obj[4].vector.y = -1;
    }
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyQ) {
        obj[4].rect.top = 100;
        obj[4].vector.x = -1;
        obj[4].vector.y = 0;
    }
    move_hero_2(event, obj);
}