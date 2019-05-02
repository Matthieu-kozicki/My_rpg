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
    sfSleep((sfTime) {150000});
    sfRenderWindow_drawSprite(game->window, obj[34].spr, NULL);
    if (game->combat->tmp->next->next != NULL && sfKeyboard_isKeyPressed(sfKeyRight))
        game->combat->tmp = game->combat->tmp->next;
    if (game->combat->tmp->next->next == NULL)
        game->combat->tmp = game->combat->list;
    if (sfKeyboard_isKeyPressed(sfKeyE))
        dup_poke(game->combat->tmp, &game->combat->poke[1]);
    sfRenderWindow_drawSprite(game->window, game->combat->tmp->spr->spr, NULL);
    draw_info(game);
    if (mouse_is_on(game, (sfVector2f){43, 689}, 180, 150) == 1) {
        sfRenderWindow_drawSprite(game->window, obj[35].spr, NULL);
        if (obj->moused == 1)
            game->screen = 1;
    }
}
