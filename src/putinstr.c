/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** putinstr
*/

#include "my_rpg.h"

long long my_digits(int nb)
{
    long long i = 1;
    int z = 0;

    z = nb;
    while (z != 0) {
        z /= 10;
        i++;
    }
    return (i);
}

char *zero(void)
{
    char *result = malloc(sizeof(char) * 2);

    result[0] = '0';
    result[1] = '\0';
    return (result);
}

char *intstr(int nb, int digits)
{
    int digi = 1;
    int print = 0;
    char *result = malloc(sizeof(char) * digits + 1);

    if (nb < 0) {
        result[print] = '-';
        print = print + 1;
    }
    if (nb == 0) return(zero());
    while (nb/digi >= 10)
        digi = digi * 10;
    for (int count = 0; digi >= 1; count++) {
        result[count] = nb / digi + 48;
        nb = nb % digi;
        digi = digi / 10;
    }
    result[digits] = '\0';
    return (result);
}
