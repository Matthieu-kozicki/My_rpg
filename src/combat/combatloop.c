/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** INSERT DESCRIPTION
*/

#include "my_rpg.h"

long randomiser(long min, long max)
{
    srand(time(NULL));
    return((rand() % (max - min + 1)) + min);
}

combat_t *init_combat_sprites(char **player_team, char **enmy_team)
{
    combat_t *tmp = malloc(sizeof(combat_t *));
    sfTexture *text;

    tmp->turn = randomiser(1, 2);
    tmp->player_pkmn = malloc(sizeof(sfSprite *) * 6);
    tmp->enmy_pkmn = malloc(sizeof(sfSprite *) * 6);
    for (int i = 0; player_team[i] != NULL; i++) {
        tmp->player_pkmn[i] = sfSprite_create();
        text = sfTexture_createFromFile(player_team[i], NULL);
    }
    for (int i = 0; enmy_team[i] != NULL; i++) {
        tmp->enmy_pkmn[i] = sfSprite_create();
        text = sfTexture_createFromFile(enmy_team[i], NULL);
    }
}

void combat_loop(game_t *game, object_t *obj)
{
    //init scene sprites
    int i = randomiser(1, 2);
    printf("%d <-\n", i);
    /*while (1) {

    }*/
}