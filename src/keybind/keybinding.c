/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** handling keybind
*/

#include "my_rpg.h"

void keybinding(game_t *game, object_t *obj)
{
    if (mouse_is_on(game, (sfVector2f){590, 220}, 80, 60) == 1
        && obj->moused == 1)
        write(1, "Up button\n", 10);
    if (mouse_is_on(game, (sfVector2f){712, 220}, 80, 60) == 1
        && obj->moused == 1)
        write(1, "Down button\n", 12);
    if (mouse_is_on(game, (sfVector2f){845, 220}, 80, 60) == 1
        && obj->moused == 1)
        write(1, "Left button\n", 12);
    if (mouse_is_on(game, (sfVector2f){959, 220}, 80, 60) == 1
        && obj->moused == 1)
        write(1, "Right button\n", 13);
}