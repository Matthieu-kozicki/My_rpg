/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** put an in into str
*/

#include "my_rpg.h"

int nb_digits(int nb)
{
    int size = 0;

    if (nb == 0)
        return (1);
    while (nb != 0) {
        nb = nb / 10;
        size = size + 1;
    }
    return (size);
}

char *int_to_char(int nb)
{
    char *str;
    int div = 1;
    int j = 0;

    str = malloc(sizeof(char) * nb_digits(nb) + 1);
    while (nb >= div)
        div = div * 10;
    div = div / 10;
    while (j < 4 - nb_digits(nb)) {
        str[j] = '0';
        j = j + 1;
    }
    while (div > 0) {
        str[j] = nb / div + 48;
        nb = nb % div;
        div = div / 10;
	j = j + 1;
    }
    str[nb_digits(nb)] = '\0';
    return (str);
}
