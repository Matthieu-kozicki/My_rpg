/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** inventory
*/

#include "my_rpg.h"

void dup_poke(poke_t *origin, poke_t *dup)
{
    dup->stats[TYPE] = origin->stats[TYPE];
    dup->stats[HP] = origin->stats[HP];
    dup->stats[ACTUAL_HP] = origin->stats[ACTUAL_HP];
    dup->stats[ATK] = origin->stats[ATK];
    dup->stats[DEF] = origin->stats[DEF];
    dup->stats[COST] = origin->stats[COST];
    dup->info[NAME] = my_strdup(origin->info[NAME]);
    dup->info[ATK_NAME] = my_strdup(origin->info[ATK_NAME]);
    dup->info[PATH_TO_SPRITE] = my_strdup(origin->info[PATH_TO_SPRITE]);
    dup->info[PATH_TO_ATK] = my_strdup(origin->info[PATH_TO_ATK]);
}

void draw_info_inv(game_t *game)
{
    sfRenderWindow_drawText(game->window, game->combat->tmp2->inv, NULL);
    sfRenderWindow_drawText(game->window, game->combat->tmp2->name, NULL);
    sfRenderWindow_drawText(game->window,
    game->combat->tmp2->attack_name, NULL);
    sfRenderWindow_drawText(game->window, game->combat->tmp2->hp, NULL);
    sfRenderWindow_drawText(game->window, game->combat->tmp2->attack, NULL);
    sfRenderWindow_drawText(game->window, game->combat->tmp2->defense, NULL);
    sfRenderWindow_drawText(game->window, game->combat->tmp2->cost, NULL);
    sfRenderWindow_drawText(game->window, game->combat->cash, NULL);
}

void draw_info(game_t *game)
{
    sfRenderWindow_drawText(game->window, game->combat->tmp->inv, NULL);
    sfRenderWindow_drawText(game->window, game->combat->tmp->name, NULL);
    sfRenderWindow_drawText(game->window, game->combat->tmp->attack_name, NULL);
    sfRenderWindow_drawText(game->window, game->combat->tmp->hp, NULL);
    sfRenderWindow_drawText(game->window, game->combat->tmp->attack, NULL);
    sfRenderWindow_drawText(game->window, game->combat->tmp->defense, NULL);
    sfRenderWindow_drawText(game->window, game->combat->tmp->cost, NULL);
    sfRenderWindow_drawText(game->window, game->combat->cash, NULL);
}

void inventory(game_t *game, object_t *obj)
{
    sfSleep((sfTime) {100000});
    sfRenderWindow_drawSprite(game->window, obj[34].spr, NULL);
    if (game->combat->inv->next == NULL)
        sfRenderWindow_drawSprite(game->window, obj[43].spr, NULL);
    else {
        if (game->combat->tmp2->next != NULL
        && sfKeyboard_isKeyPressed(sfKeySpace))
            game->combat->tmp2 = game->combat->tmp2->next;
        if (game->combat->tmp2->next == NULL)
            game->combat->tmp2 = game->combat->inv;
        draw_info_inv(game);
        sfRenderWindow_drawSprite(game->window,
        game->combat->tmp2->spr->spr, NULL);
    }
    if (mouse_is_on(game, (sfVector2f){43, 689}, 180, 150) == 1) {
        sfRenderWindow_drawSprite(game->window, obj[35].spr, NULL);
        if (obj->moused == 1) {
            game->screen = 1;
            sfMusic_play(game->inv);
        }
    }
}

void shop(game_t *game, object_t *obj)
{
    sfSleep((sfTime) {100000});
    sfRenderWindow_drawSprite(game->window, obj[42].spr, NULL);
    if (game->combat->tmp->next->next != NULL
    && sfKeyboard_isKeyPressed(sfKeySpace))
        game->combat->tmp = game->combat->tmp->next;
    if (game->combat->tmp->next->next == NULL)
        game->combat->tmp = game->combat->list;
    sfRenderWindow_drawSprite(game->window, game->combat->tmp->spr->spr, NULL);
    draw_info(game);
    shopping(game);
    if (mouse_is_on(game, (sfVector2f){43, 689}, 180, 150) == 1) {
        sfRenderWindow_drawSprite(game->window, obj[35].spr, NULL);
        if (obj->moused == 1)
            game->screen = 1;
    }
}
