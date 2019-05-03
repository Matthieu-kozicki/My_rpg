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

long randint(long min, long max)
{
    return((rand() % (max - min + 1)) + min);
}

int my_getnbr(char const *str)
{
    int i = 0;
    int result = 0;
    int nb = 0;
    int neg = 0;

    if (str[i] == '-') {
        neg = 1;
        i++;
    }
    while (str[i] != '\0' && str[i] > 47 && str[i] < 58) {
        result *= 10;
        nb = str[i] - 48;
        result += nb;
        i++;
    }
    if (neg == 1)
        result *= -1;
    return (result);
}
