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
    sfText_setCharacterSize(text, 40);
    return (text);
}

void create_spr_list(poke_t *list)
{
    char *str;
    poke_t *tmp = list;

    str = "Name :\n\nAttack name :\n\nHealth Point :\n\nAttack :\n\nDefense :";
    while (tmp->next != NULL) {
        *tmp->spr = create_object(tmp->info[PATH_TO_SPRITE],
                                  (sfVector2f){20, 340});
        tmp->inv = texted(tmp->inv, (sfVector2f) {300, 150}, str);
        tmp->name = texted(tmp->name, (sfVector2f) {530, 150}, tmp->info[NAME]);
        tmp->attack_name = texted(tmp->attack_name, (sfVector2f) {750, 280}, tmp->info[ATK_NAME]);
        tmp = tmp->next;
    }
}

void print_list(poke_t *list)
{
    poke_t *tmp = list;

    while (tmp->next != NULL) {
        printf("%s\n", tmp->info[NAME]);
        tmp = tmp->next;
    }
}
