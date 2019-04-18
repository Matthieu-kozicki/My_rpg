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
        printf("Up button\n");
    if (mouse_is_on(game, (sfVector2f){712, 220}, 80, 60) == 1
        && obj->moused == 1)
        printf("Down button\n");
    if (mouse_is_on(game, (sfVector2f){845, 220}, 80, 60) == 1
        && obj->moused == 1)
        printf("Left button\n");
    if (mouse_is_on(game, (sfVector2f){959, 220}, 80, 60) == 1
        && obj->moused == 1)
        printf("Right button\n");
}
