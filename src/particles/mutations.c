/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** mutations
*/

#include "my_rpg.h"

void mu_color(sfColor *color)
{
    *color = (sfColor){randfloat(1, 255), randfloat(1, 255),
    randfloat(1, 255), 255};
}