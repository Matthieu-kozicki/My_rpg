/*
** EPITECH PROJECT, 2018
** INSERT NAME
** File description:
** INSERT DESCRIPTION
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include "my_rpg.h"

char *my_strdup(char const *src)
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
    if (index == 5) poke->stats[0] = atoi(line);
    if (index == 6) poke->stats[1] = atoi(line);
    if (index == 7) poke->stats[2] = atoi(line);
    if (index == 8) poke->stats[3] = atoi(line);
    if (index == 9) poke->stats[4] = atoi(line);
    if (index == 10 && (cmp_str("[END]", line, 5) != 1)) return (84);
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
    return (0);
}
