/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** INSERT DESCRIPTION
*/

#include "my_rpg.h"

long randomiser(long min, long max)
{
    srand(time(NULL));
    return((rand() % (max - min + 1)) + min);
}

void draw_combat_sprites(sfRenderWindow *window, object_t *obj)
{
    sfRenderWindow_drawSprite(window, obj[26].spr, NULL);
    sfRenderWindow_drawSprite(window, obj[27].spr, NULL);
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
        sfSprite_setPosition(obj[27].spr, (sfVector2f){848, 662});
    if (game->cursor_pos == 1)
        sfSprite_setPosition(obj[27].spr, (sfVector2f){1235, 662});
    if (game->cursor_pos == 2)
        sfSprite_setPosition(obj[27].spr, (sfVector2f){848, 780});
    if (game->cursor_pos == 3)
        sfSprite_setPosition(obj[27].spr, (sfVector2f){1235, 780});
}

void combat_loop(game_t *game, object_t *obj)
{
    draw_combat_sprites(game->window, obj);
    cursor_conditions(game);
    move_cursor(game, obj);
    if (game->cursor_pos == 3 && sfKeyboard_isKeyPressed(sfKeyReturn)) {
        game->cursor_pos = 0;
        game->screen = 1;
    }
}