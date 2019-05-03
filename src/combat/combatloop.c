/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** INSERT DESCRIPTION
*/

#include "my_rpg.h"

void attack(int attacker, game_t *game)
{
    if (attacker == 0) {
        game->combat->tmp->stats[HP] -=
        calculate_atk(attacker, game->combat);
    }
    if (attacker == 1) {
        game->combat->poke[0].stats[HP] -=
        calculate_atk(attacker, game->combat);
    } 
}

void draw_combat_sprites(sfRenderWindow *window, object_t *obj, game_t *game)
{
    sfRenderWindow_drawSprite(window, obj[28].spr, NULL);
    sfRenderWindow_drawSprite(window, obj[29].spr, NULL);
    sfRenderWindow_drawSprite(window, game->combat->spr[0], NULL);
    sfRenderWindow_drawSprite(window, game->combat->spr[1], NULL);
    sfText_setString(game->combat->texts[1],
        intstr(game->combat->poke[0].stats[HP], nb_digits(game->combat->poke[0].stats[HP])));
    sfText_setString(game->combat->texts[0],
        intstr(game->combat->tmp->stats[HP], nb_digits(game->combat->tmp->stats[HP])));
    sfText_setString(game->combat->texts[2], game->combat->tmp->info[NAME]);
    sfText_setString(game->combat->texts[3], game->combat->poke[0].info[NAME]);
    sfRenderWindow_drawText(window, game->combat->texts[0], NULL);
    sfRenderWindow_drawText(window, game->combat->texts[1], NULL);
    sfRenderWindow_drawText(window, game->combat->texts[2], NULL);
    sfRenderWindow_drawText(window, game->combat->texts[3], NULL);
}

void cursor_conditions(game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ) && (game->cursor_pos == 2 ||
        game->cursor_pos == 3))
        game->cursor_pos -= 2;
    if (sfKeyboard_isKeyPressed(sfKeyS) && (game->cursor_pos == 0 ||
        game->cursor_pos == 1))
        game->cursor_pos += 2;
    if (sfKeyboard_isKeyPressed(sfKeyD) && (game->cursor_pos == 0 ||
        game->cursor_pos == 2))
        game->cursor_pos += 1;
    if (sfKeyboard_isKeyPressed(sfKeyQ) && (game->cursor_pos == 1 ||
        game->cursor_pos == 3))
        game->cursor_pos -= 1;
}

void move_cursor(game_t *game, object_t *obj)
{
    if (game->cursor_pos == 0)
        sfSprite_setPosition(obj[29].spr, (sfVector2f){848, 662});
    if (game->cursor_pos == 1)
        sfSprite_setPosition(obj[29].spr, (sfVector2f){1235, 662});
    if (game->cursor_pos == 2)
        sfSprite_setPosition(obj[29].spr, (sfVector2f){848, 780});
    if (game->cursor_pos == 3)
        sfSprite_setPosition(obj[29].spr, (sfVector2f){1235, 780});
}

void combat_loop(game_t *game, object_t *obj)
{
    draw_combat_sprites(game->window, obj, game);
    cursor_conditions(game);
    move_cursor(game, obj);
    combat_ia(game, game->combat->difficulty);
    particle_update(&game->combat->particles[1], game->combat->clock[3], 0.001);
    particle_update(&game->combat->particles[0], game->combat->clock[4], 0.001);
    particle_draw(game, &game->combat->particles[1]);
    particle_draw(game, &game->combat->particles[0]);
    if (game->screen == 5 && game->cursor_pos == 3 &&
        sfKeyboard_isKeyPressed(sfKeyReturn)) {
        game->screen = 1;
        game->cursor_pos = 0;
    }
    if (game->screen == 5 && game->cursor_pos == 0 &&
        sfKeyboard_isKeyPressed(sfKeyReturn)) {
        if (game->combat->seconds[0] >= 0.2) {
            attack(1, game);
            particle_setparam(&game->combat->particles[1],
            (sfVector2f){532, 414}, (sfVector2f){1085, 245}, 2);
            particle_launch(&game->combat->particles[1],
            randfloat(1, 5), (sfVector2f){3, 3}, 0.001);
            sfClock_restart(game->combat->clock[0]);
        }
    }
    if (game->combat->poke[0].stats[HP] <= 0 ||
        game->combat->tmp->stats[HP]<= 0) {
        game->screen = 1;
        game->cursor_pos = 0;
    }
}