/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** combat
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include "my_rpg.h"

char *my_strdup(char *src)
{
    int str_len = my_strlen(src);
    int i = 0;
    char *duplicate = malloc(sizeof(char) * (str_len + 1));

    while (src[i] != '\0') {
        if (src[i] == '\n') {
            duplicate[i] = '\0';
            return (duplicate);
        }
        duplicate[i] = src[i];
        i = i + 1;
    }
    duplicate[str_len] = '\0';
    return (duplicate);
}

int cmp_str(char *str1, char *str2, int n)
{
    int x = 0;

    for (; x != n && str1[x] != '\0' && str2[x] != '\0'; x++) {
        if (str1[x] != str2[x])
            return (-1);
    }
    return (1);
}

int checker(int index, char *line, poke_t *poke)
{
    if (index == 0 && (cmp_str("[START]", line, 7) != 1)) return (84);
    if (index == 1) poke->info[0] = my_strdup(line);
    if (index == 2) poke->info[1] = my_strdup(line);
    if (index == 3) poke->info[2] = my_strdup(line);
    if (index == 4) poke->info[3] = my_strdup(line);
    if (index == 5) poke->stats[0] = my_getnbr(line);
    if (index == 6) poke->stats[1] = my_getnbr(line);
    if (index == 7) poke->stats[2] = my_getnbr(line);
    if (index == 8) poke->stats[3] = my_getnbr(line);
    if (index == 9) poke->stats[4] = my_getnbr(line);
    if (index == 10 && (cmp_str("[END]", line, 5) != 1)) return (184);
    return (0);
}

int check_pokefile(char *path, poke_t *poke)
{
    FILE *stream = fopen(path, "r");
    char *line = NULL;
    size_t len = 100;
    int i = 0;

    if (stream == NULL) return (84);
    while (i != 10) {
        if (getline(&line, &len, stream) == -1 && i != 10)
            return (84);
        if (checker(i, line, poke) == 84) return (84);
        i++;
    }
    poke->stats[ACTUAL_HP] = poke->stats[HP];
    return (0);
}

int poke_init(poke_t *list)
{
    DIR *dir = opendir("pokemons");
    struct dirent *tmp;
    int rv = 0;
    char *name;

    if (dir == NULL) return (84);
    tmp = readdir(dir);
    if (tmp == NULL) return (84);
    while (tmp != NULL) {
        if (tmp->d_name[0] != '.') {
            name = malloc(sizeof(char) * 10 + 256);
            name[0] = '\0';
            name = my_strcat(name, "pokemons/");
            name = my_strcat(name, tmp->d_name);
            rv = check_pokefile(name, add_to_list(list));
            free(name);
        }
        if (rv != 0) return (84);
        tmp = readdir(dir);
    }
    return (0);
}
