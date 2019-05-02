/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_combat
*/

#include "my_rpg.h"

int calculate_atk(int attacker, poke_t poke[])
{
    int attack_value = 0;

    if (attacker == 0) {
        attack_value = poke[0].stats[ATK] - poke[1].stats[DEF];
        if (attack_value <= 0) return (1);
    }
    if (attacker == 1) {
        attack_value = poke[1].stats[ATK] - poke[0].stats[DEF];
        if (attack_value <= 0) return (1);
    }
    return (attack_value);
}

void combat_ia(game_t *game, float difficulty)
{
    static int attack_time = 2;
    //static float heal_percent = 100;

    if (game->combat->seconds[1] >= attack_time) {
        attack_time = randfloat(0.5, 10 - difficulty);
        attack(0, game);
        sfClock_restart(game->combat->clock[1]);
    }
    /*heal_percent = randfloat(0.1, 100);
    if (randfloat(0.1, difficulty * 10) > heal_percent)
        game->combat->poke[1].stats[HP] += 10;*/
}