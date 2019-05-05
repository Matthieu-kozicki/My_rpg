/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** handling keybind
*/

#include "my_rpg.h"

void init_keys(game_t *game)
{
    game->inputs[UP] = sfKeyZ;
    game->inputs[DOWN] = sfKeyS;
    game->inputs[LEFT] = sfKeyQ;
    game->inputs[RIGHT] = sfKeyD;
}

void bind_key(sfEvent *event, game_t *game, int key_nb)
{
    while (sfRenderWindow_waitEvent(game->window, event) == sfFalse)
    if (event->type != sfEvtKeyPressed)
        write(1, "Please enter a key !\n", 22);
    game->inputs[key_nb] = event->key.code;
}

void keybinding(game_t *game, object_t *obj)
{
    sfEvent event;

    if (mouse_is_on(game, (sfVector2f){590, 220}, 80, 60) == 1
        && obj->moused == 1)
        bind_key(&event, game, UP);
    if (mouse_is_on(game, (sfVector2f){712, 220}, 80, 60) == 1
        && obj->moused == 1)
        bind_key(&event, game, DOWN);
    if (mouse_is_on(game, (sfVector2f){845, 220}, 80, 60) == 1
        && obj->moused == 1)
        bind_key(&event, game, LEFT);
    if (mouse_is_on(game, (sfVector2f){959, 220}, 80, 60) == 1
        && obj->moused == 1)
        bind_key(&event, game, RIGHT);
}
