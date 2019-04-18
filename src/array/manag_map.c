/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** manag_map.c
*/

#include "my_rpg.h"

int check_pos(game_t *game)
{
    int i = 0;
    int j = 0;

    game->pos_x = 0;
    game->pos_y = 0;
    while (game->tab[j][i] != 'P') {
        for (; i < 50; i = i + 1) {
            if (game->tab[j][i] == 'P') {
                game->pos_x = i;
                game->pos_y = j;
                return (0);
            }
        }
        j = j + 1;
        i = 0;
    }
    game->pos_x = i;
    game->pos_y = j;
    return (0);
}

int test_block(int space_y, int space_x, game_t *game)
{
    if (game->tab[game->pos_y + space_y][game->pos_x + space_x] == '#')
        return (0);
    if (game->tab[game->pos_y + space_y][game->pos_x + space_x] == 'T')
        return (2);
    return (1);
}

char last_pos(char c, int space_y, int space_x, game_t *game)
{
    c = game->tab[game->pos_y + space_y][game->pos_x + space_x];
    return (c);
}
