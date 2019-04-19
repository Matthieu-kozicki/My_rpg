/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** clocks
*/

#include "my_rpg.h"

void manage_clock(combat_t *combat)
{
    combat->time[0] = sfClock_getElapsedTime(combat->clock[0]);
    combat->time[1] = sfClock_getElapsedTime(combat->clock[1]);
    combat->seconds[0] = combat->time[0].microseconds / 1000000.0;
    combat->seconds[1] = combat->time[1].microseconds / 1000000.0;
}