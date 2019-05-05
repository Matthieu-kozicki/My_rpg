/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** clocks
*/

#include "my_rpg.h"

void manage_clock(combat_t *combat, game_t *game)
{
    combat->time[0] = sfClock_getElapsedTime(combat->clock[0]);
    combat->time[1] = sfClock_getElapsedTime(combat->clock[1]);
    combat->time[2] = sfClock_getElapsedTime(combat->clock[2]);
    combat->time[3] = sfClock_getElapsedTime(combat->clock[3]);
    combat->time[4] = sfClock_getElapsedTime(combat->clock[4]);
    game->timea = sfClock_getElapsedTime(game->clocka);
    game->seconda = game->timea.microseconds / 10000;
    combat->seconds[0] = combat->time[0].microseconds / 1000000.0;
    combat->seconds[1] = combat->time[1].microseconds / 1000000.0;
    combat->seconds[2] = combat->time[2].microseconds / 1000000.0;
    combat->seconds[3] = combat->time[3].microseconds / 10000;
    combat->seconds[4] = combat->time[4].microseconds / 10000;
}