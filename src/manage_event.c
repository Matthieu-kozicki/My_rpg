/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** manage event
*/

#include "my_rpg.h"

char ***alloc_3d_array(int nb, int rows, int cols)
{
    char ***a = malloc(sizeof(char **) * nb);

    for (int i = 0; i < nb; i++)
        a[i] = alloc_2d_array(rows, cols);
    return (a);
}

void manage_events(game_t *game, object_t *obj)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->window, &event)) {
        game->mouse = sfMouse_getPositionRenderWindow(game->window);
        //printf("x : %d | y : %d\n", game->mouse.x, game->mouse.y);
        if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyDelete))
            sfRenderWindow_close(game->window);
        if (event.type == sfEvtMouseButtonPressed)
            obj->moused = 1;
        else obj->moused = 0;
        if (event.type == sfEvtMouseButtonReleased)
            obj->clicked = 1;
        else obj->clicked = 0;
        if (sfKeyboard_isKeyPressed(sfKeyEscape) && game->screen == 1)
            game->screen = 2;
        if (sfKeyboard_isKeyPressed(sfKeyC)) {
            game->screen = 5;
        }
        if (game->screen == 1)
            move_hero_1(event, obj, game);
    }
}
