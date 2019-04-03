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

char **alloc_2d_array(int nb_rows, int nb_cols)
{
    char **a = malloc(sizeof(char *) * nb_rows);

    for (int y = 0;y < nb_rows;y = y + 1) {
        a[y] = malloc(sizeof(char) * nb_cols + 1);
        a[y][nb_cols] = '\0';
    }
    return (a);
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

int checker(int index, char *line, char **info)
{
    static int i = 0;

    if (index == 0 && (cmp_str("[START]", line, 7) != 1)) {
        printf("Error at line %d\n", index);
        return (84);
    }
    if (index == 10 && (cmp_str("[END]", line, 5) != 1)) {
        printf("Error at line %d\n", index);
        return (84);
    }
    info[i] = strdup(line);
    i++;
    return (0);
}

int check_pokefile(char *path, char **info)
{
    FILE *stream = fopen(path, "r");
    char *line = NULL;
    size_t len = 100;
    int i = 0;

    if (stream == NULL) return (84);
    while (i != 11) {
        if (getline(&line, &len, stream) == -1 && i != 11) {
            printf("Error in Pokefile : Missing line(s)\n");
            return (84);
        }
        if (checker(i, line, info) == 84) return (84);
        i++;
    }
    free(info[9]);
    info[9] = NULL;
    return (0);
}
