/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** inventory
*/

#include "my_rpg.h"

void draw_info(game_t *game)
{
    sfRenderWindow_drawText(game->window, game->combat->tmp->inv, NULL);
    sfRenderWindow_drawText(game->window, game->combat->tmp->name, NULL);
    sfRenderWindow_drawText(game->window, game->combat->tmp->attack_name, NULL);
    sfRenderWindow_drawText(game->window, game->combat->tmp->hp, NULL);
    sfRenderWindow_drawText(game->window, game->combat->tmp->attack, NULL);
    sfRenderWindow_drawText(game->window, game->combat->tmp->defense, NULL);
    sfRenderWindow_drawText(game->window, game->combat->tmp->cost, NULL);
}

void inventory(game_t *game, object_t *obj)
{
    sfSleep((sfTime) {100000});
    sfRenderWindow_drawSprite(game->window, obj[34].spr, NULL);
    if (game->combat->tmp->next->next != NULL && sfKeyboard_isKeyPressed(sfKeyRight))
        game->combat->tmp = game->combat->tmp->next;
    if (game->combat->tmp->next->next == NULL)
        game->combat->tmp = game->combat->list;
        
    sfRenderWindow_drawSprite(game->window, game->combat->tmp->spr->spr, NULL);
    draw_info(game);
    if (mouse_is_on(game, (sfVector2f){43, 689}, 180, 150) == 1) {
        sfRenderWindow_drawSprite(game->window, obj[35].spr, NULL);
        if (obj->moused == 1)
            game->screen = 1;
    }
}
