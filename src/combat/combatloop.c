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
        game->combat->tmp2->stats[ACTUAL_HP] -=
        calculate_atk(attacker, game->combat);
    }
    if (attacker == 1) {
        game->combat->poke[0].stats[ACTUAL_HP] -=
        calculate_atk(attacker, game->combat);
    }
}

void draw_combat_sprites(sfRenderWindow *window, object_t *obj, game_t *game)
{
    char *ppkminfo = malloc(sizeof(char) * 4 +
    getmallocsize(game->combat->tmp2) +
    getmallocsize(&game->combat->poke[0]) + 1);

    sfRenderWindow_drawSprite(window, obj[28].spr, NULL);
    sfRenderWindow_drawSprite(window, obj[29].spr, NULL);
    sfRenderWindow_drawSprite(window, game->combat->spr[0], NULL);
    sfRenderWindow_drawSprite(window, game->combat->spr[1], NULL);
    draw_combat_texts(game);
    sfText_setString(game->combat->texts[2], game->combat->tmp2->info[NAME]);
    sfText_setString(game->combat->texts[3], game->combat->poke[0].info[NAME]);
    for (int i = 0; i != 8; i++)
        sfRenderWindow_drawText(window, game->combat->texts[i], NULL);
    memset(ppkminfo, '\0',
    getmallocsize(game->combat->tmp2) +
    getmallocsize(&game->combat->poke[0]) + 3);
    my_strcat(ppkminfo, game->combat->tmp2->info[ATK_NAME]);
    my_strcat(ppkminfo, "\nVS\n");
    my_strcat(ppkminfo, game->combat->poke[0].info[ATK_NAME]);
    sfText_setString(game->combat->texts[6], ppkminfo);
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
    static int test = 0;

    test++;
    draw_combat_sprites(game->window, obj, game);
    cursor_conditions(game);
    move_cursor(game, obj);
    combat_ia(game, game->combat->difficulty);
    if (test > 100)
        particle_update(&game->combat->particles[1], game->combat->clock[3],
        0.001);
    particle_update(&game->combat->particles[0], game->combat->clock[4], 0.001);
    particle_draw(game, &game->combat->particles[1]);
    particle_draw(game, &game->combat->particles[0]);
    combat_loop_next(game, obj);
}
