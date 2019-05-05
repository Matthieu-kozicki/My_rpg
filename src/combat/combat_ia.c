/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_combat
*/

#include "my_rpg.h"

int calculate_atk(int attacker, combat_t *combat)
{
    int attack_value = 0;

    if (attacker == 0) {
        attack_value = combat->poke[0].stats[ATK] -
        combat->tmp->stats[DEF];
        if (attack_value <= 0) return (1);
    }
    if (attacker == 1) {
        attack_value = combat->tmp->stats[ATK] -
        combat->poke[0].stats[DEF];
        if (attack_value <= 0) return (1);
    }
    return (attack_value);
}

void combat_ia(game_t *game, float difficulty)
{
    static int attack_time = 2;

    if (game->combat->seconds[1] >= attack_time) {
        attack_time = randfloat(0.5, 10 - difficulty);
        attack(0, game);
        particle_setparam(&game->combat->particles[0],
        (sfVector2f){1085, 245}, (sfVector2f){400, 510}, 2);
        particle_launch(&game->combat->particles[0],
        randfloat(6, 10), (sfVector2f){randfloat(0.5, 1.5),
        randfloat(0.5, 1.5)}, 0.001);
        sfClock_restart(game->combat->clock[1]);
    }
}

void combat_loop_next(game_t *game, object_t *obj)
{
    if (game->screen == 5 && game->cursor_pos == 3 &&
        sfKeyboard_isKeyPressed(sfKeyReturn)) {
        game->screen = 1;
        game->cursor_pos = 0;
    }
    if (game->screen == 5 && game->cursor_pos == 0 &&
        sfKeyboard_isKeyPressed(sfKeyReturn)) {
        if (game->combat->seconds[0] >= 0.2) {
            sfMusic_play(game->dmg);
            attack(1, game);
            particle_setparam(&game->combat->particles[1],
            (sfVector2f){532, 414}, (sfVector2f){1120, 245}, 2);
            particle_launch(&game->combat->particles[1],
            randfloat(6, 10), (sfVector2f){randfloat(0.5, 1.5),
            randfloat(0.5, 1.5)}, 0.001);
            sfClock_restart(game->combat->clock[0]);
        }
    }
    check_win(game, obj);
}

void draw_combat_texts(game_t *game)
{
    sfText_setString(game->combat->texts[1],
    intstr(game->combat->poke[0].stats[ACTUAL_HP],
    nb_digits(game->combat->poke[0].stats[ACTUAL_HP])));
    sfText_setString(game->combat->texts[0],
    intstr(game->combat->tmp2->stats[ACTUAL_HP],
    nb_digits(game->combat->tmp2->stats[ACTUAL_HP])));
    sfText_setString(game->combat->texts[4],
    intstr(game->combat->tmp2->stats[HP],
    nb_digits(game->combat->tmp2->stats[HP])));
    sfText_setString(game->combat->tmp2->hp,
    intstr(game->combat->tmp2->stats[ACTUAL_HP],
    nb_digits(game->combat->tmp2->stats[ACTUAL_HP])));
    sfText_setString(game->combat->texts[5],
    intstr(game->combat->poke[0].stats[HP],
    nb_digits(game->combat->poke[0].stats[HP])));
}
