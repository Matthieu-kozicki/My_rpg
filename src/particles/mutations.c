/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** mutations
*/

#include "my_rpg.h"

void mu_color(sfColor *color, particle_t *particle)
{
    if (particle->type == ELECT) {
        if (color->g <= 190) color->g += 5 + randint(5, 20);
        if (color->g - randint(-5, 5) <= 190) color->g += 5 +randint(5, 20);
        else color->g += randint(190 - color->g, 20);
    }
    if (particle->type == WATER) {
        if (color->b <= 100) color->b += 5 + randint(5, 20);
        if (color->b - randint(-5, 5) <= 100) color->b += 5 +randint(5, 20);
        else color->b += randint(100 - color->b, 20);
    }
}

void mu_size(int i, particle_t *particle)
{
    if (particle->type == WATER) {

    }
}