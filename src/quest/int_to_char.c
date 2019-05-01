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
