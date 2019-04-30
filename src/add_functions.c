/*
** EPITECH PROJECT, 2019
** .c
** File description:
** ...
*/

#include "my_rpg.h"

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    rect->left = rect->left + offset;
    if (rect->left >= max_value)
        rect->left = 0;
}

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int z = my_strlen(dest);

    for (; src[i] != '\0'; i++) {
        dest[z] = src[i];
        z++;
    }
    dest[z] = '\0';
    return (dest);
}

float randfloat(float min, float max)
{
    return (min + ((float)rand()/(float)(RAND_MAX)) * max);
}

long randomiser(long min, long max)
{
    return((rand() % (max - min + 1)) + min);
}