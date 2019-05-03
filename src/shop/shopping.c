/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** buy pokemon
*/

#include "my_rpg.h"

void shopping(game_t *game, object_t *obj)
{
    poke_t *tmp = NULL;

    if (sfKeyboard_isKeyPressed(sfKeyE)
        && game->combat->money > game->combat->tmp->stats[COST]) {
        game->combat->money -= game->combat->tmp->stats[COST];
        sfText_setString(game->combat->cash,
                         intstr(game->combat->money, nb_digits(game->combat->money)));
        tmp = add_to_list(game->combat->inv);
        dup_poke(game->combat->tmp, tmp);
    }
}
