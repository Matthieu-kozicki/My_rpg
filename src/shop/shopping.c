/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** buy pokemon
*/

#include "my_rpg.h"

void dup_info(poke_t *tmp, poke_t *origin)
{
    tmp->spr = malloc(sizeof(object_t));
    tmp->spr->spr = sfSprite_copy(origin->spr->spr);
    tmp->inv = sfText_copy(origin->inv);
    tmp->name = sfText_copy(origin->name);
    tmp->attack_name = sfText_copy(origin->attack_name);
    tmp->hp = sfText_copy(origin->hp);
    tmp->attack = sfText_copy(origin->attack);
    tmp->defense = sfText_copy(origin->defense);
    tmp->cost = sfText_copy(origin->cost);
}

void shopping(game_t *game)
{
    poke_t *tmp = NULL;

    if (sfKeyboard_isKeyPressed(sfKeyE)
        && game->combat->money < game->combat->tmp->stats[COST])
        sfMusic_play(game->bad);
    if (sfKeyboard_isKeyPressed(sfKeyE)
        && game->combat->money >= game->combat->tmp->stats[COST]) {
        game->combat->money -= game->combat->tmp->stats[COST];
        sfText_setString(game->combat->cash,
        intstr(game->combat->money, nb_digits(game->combat->money)));
        tmp = add_to_list(game->combat->inv);
        dup_poke(game->combat->tmp, tmp);
        dup_info(tmp, game->combat->tmp);
    }
}
