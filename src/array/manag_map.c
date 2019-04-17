/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** manag_map.c
*/

#include "my_rpg.h"
/*
int check_pos(char **tab, pos_t *pos)
{
    int i = 0;
    int j = 0;

    pos->pos_x = 0;
    pos->pos_y = 0;
    while (tab[j][i] != 'P') {
        for (i = i; tab[j][i] != '\0'; i = i + 1) {
            if (tab[j][i] == 'P') {
                pos->pos_x = i;
                pos->pos_y = j;
                return (0);
            }
        }
        j = j + 1;
        i = 0;
    }
    pos->pos_x = i;
    pos->pos_y = j;
    return (0);
}

int test_block(int space_y, int space_x, pos_t *pos, char **tab)
{
    if (tab[pos->pos_y + space_y][pos->pos_x + space_x] == '#')
        return (0);
    if (tab[pos->pos_y + space_y][pos->pos_x + space_x] == 'T')
        return (2);
    return (1);
}

char last_pos(char c, int space_y, int space_x, pos_t *pos, char **tab)
{
    c = tab[pos->pos_y + space_y][pos->pos_x + space_x];
    return (c);
}
*/