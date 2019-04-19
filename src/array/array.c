/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** array.c
*/

#include "my_rpg.h"

char **make_array(int x, int y)
{
    int i = 0;
    char **tab = malloc(sizeof(char *) * (y + 2));

    if (tab == NULL)
        return (NULL);
    while (i != y) {
        tab[i] = malloc(sizeof(char) * (x + 2));
        if (tab[i] == NULL)
            return (NULL);
        i = i + 1;
    }
    tab[i] = NULL;
    return (tab);
}

char **fill_array(char **tab, char *str)
{
    int i = 0;
    int j = 0;
    int k = 0;

    for (k = 0; k < 5051; k++) {
        if (str[k] == '\n') {
            tab[j][i] = '\0';
            i = 0;
            j++;
            k++;
        }
        tab[j][i] = str[k];
        i++;
    }
    tab[j][i] = '\0';
    tab[j + 1] = NULL;
    return (tab);
}

void free_array(int y, char **tab)
{
    int i = 0;

    while (i != y) {
        free(tab[i]);
        i++;
    }
    free(tab);
}

char **map(int count, char **tab)
{
    int fd = 0;
    char *buf = malloc(sizeof(char) * (count + 1));

    if (buf == NULL)
        return (NULL);
    fd = open("map/poke_map", O_RDONLY);
    if (fd == -1)
        return (NULL);
    if (read(fd, buf, count) == -1)
        return (NULL);
    close(fd);
    buf[count] = '\0';
    tab = make_array(50, 102);
    fill_array(tab, buf);
    return (tab);
}