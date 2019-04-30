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

void create_spr_list(poke_t *list)
{
    poke_t *tmp = list;
    int i = 0;

    while (tmp->next != NULL) {
        i++;
        *tmp->spr = create_object(tmp->info[PATH_TO_SPRITE], (sfVector2f){0, 0});
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