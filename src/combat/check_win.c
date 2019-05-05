/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** check who win
*/

#include "my_rpg.h"

void check_win(game_t *game, object_t *obj)
{
    if (game->combat->tmp2->stats[ACTUAL_HP] <= 0) {
        game->screen = 8;
        game->cursor_pos = 0;
        sfMusic_stop(game->fight);
    }
    if (game->combat->poke[0].stats[ACTUAL_HP] <= 0 &&
        obj->quest < 8) {
        game->screen = 1;
        game->cursor_pos = 0;
        game->combat->money += game->combat->difficulty * 100;
        sfText_setString(game->combat->cash,
        intstr(game->combat->money, nb_digits(game->combat->money)));
        sfMusic_stop(game->fight);
    }
    if (game->combat->poke[0].stats[ACTUAL_HP] <= 0 &&
        obj->quest == 8) {
        game->screen = 8;
        obj->quest = 9;
        sfMusic_stop(game->fight);
    }
}
