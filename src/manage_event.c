/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** manage event
*/

#include "my_rpg.h"

void manage_events(game_t *game, object_t *obj)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->window, &event)) {
        game->mouse = sfMouse_getPositionRenderWindow(game->window);
        if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyDelete))
            sfRenderWindow_close(game->window);
        if (event.type == sfEvtMouseButtonPressed)
            obj->moused = 1;
        else
            obj->moused = 0;
        if (event.type == sfEvtMouseButtonReleased)
            obj->clicked = 1;
        else
            obj->clicked = 0;
        if (sfKeyboard_isKeyPressed(sfKeyEscape) && game->screen == 1) {
            game->screen = 2;
        }
        if (sfKeyboard_isKeyPressed(sfKeyC)) {
            game->screen = 4;
            game->combat = init_combat_sprites();
        }
        if (game->screen == 1)
            move_hero_1(event, obj);
    }
}
