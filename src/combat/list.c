/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** list
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include "my_rpg.h"

poke_t *add_to_list(poke_t *list)
{
    poke_t *tmp = list;

    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = malloc(sizeof(poke_t));
    tmp->next->spr = malloc(sizeof(object_t));
    tmp->next->next = NULL;
    return (tmp);
}

sfText *texted(sfText *text, sfVector2f pos, char *str)
{
    sfFont *font;

    font = sfFont_createFromFile("police/font.ttf");
    text = sfText_create();
    sfText_setPosition(text, pos);
    sfText_setString(text, str);
    sfText_setFont(text, font);
    sfText_setColor(text, sfBlack);
    sfText_setCharacterSize(text, 28);
    return (text);
}

void create_spr_list(poke_t *list)
{
    char *str;
    poke_t *tmp = list;

    str = "Attack name :\n\nHealth Point :\n\nAttack :\n\nDef"
        "ense :\n\nCost :\n\nMoney :";
    while (tmp->next != NULL) {
        *tmp->spr = create_object(tmp->info[PATH_TO_SPRITE],
                                  (sfVector2f){150, 285});
        tmp->inv = texted(tmp->inv, (sfVector2f) {600, 75}, str);
        tmp->name = texted(tmp->name, (sfVector2f) {90, 50}, tmp->info[NAME]);
        tmp->attack_name = texted(tmp->attack_name, (sfVector2f) {950, 75},
                                  tmp->info[ATK_NAME]);
        tmp->hp = texted(tmp->hp, (sfVector2f) {950, 170},
                        intstr(tmp->stats[HP],nb_digits(tmp->stats[HP])));
        tmp->attack = texted(tmp->attack, (sfVector2f) {840,
                    260},intstr(tmp->stats[ATK],nb_digits(tmp->stats[ATK])));
        tmp->defense = texted(tmp->defense, (sfVector2f) {865,
                    350},intstr(tmp->stats[DEF],nb_digits(tmp->stats[DEF])));
        tmp->cost = texted(tmp->cost, (sfVector2f) {820, 440},
                           intstr(tmp->stats[COST],nb_digits(tmp->stats[COST])));
        tmp = tmp->next;
    }
}

int size_list(poke_t *list)
{
    poke_t *tmp = list;
    int i = 0;

    while (tmp->next != NULL) {
        tmp = tmp->next;
        i++;
    }
    return (i);
}

void find_randpoke(game_t *game)
{
    int random = randint(1, size_list(game->combat->list));
    poke_t *tmp = game->combat->list;

    for (int i = 1; tmp->next != NULL && i != random; i++)
        tmp = tmp->next;
    dup_poke(tmp, &game->combat->poke[0]);
    game->combat->difficulty = randfloat(3, 7);
    game->combat->poke[0].stats[HP] = randint(20, 80);
    game->combat->poke[0].stats[DEF] = randint(0, 10);   
    game->combat->poke[0].stats[ATK] = randint(0, 10);   
}