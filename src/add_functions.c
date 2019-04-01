/*
** EPITECH PROJECT, 2019
** .c
** File description:
** ...
*/

#include "my_rpg.h"

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    rect->left = rect->left + offset;
    if (rect->left >= max_value)
        rect->left = 0;
}