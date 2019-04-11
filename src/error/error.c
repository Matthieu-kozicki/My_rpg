/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** check some error
*/

#include "my_rpg.h"

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}

int my_strcomp(char *str, char *dest)
{
    int len = my_strlen(str);
    int i = 0;

    for (int k = 0; dest[k] != '\0'; k++)
        if (str[i] == dest[i])
            i++;
    if (i == len)
        return (1);
    else
        return (2);
}

int check_env(char **env)
{
    for (int i = 0; env[i] != NULL; i++)
        if (my_strcomp("DISPLAY=:0", env[i]) == 1)
            return (1);
    write(1, "You need 'DISPLAY=:0' in your ENV\n", 34);
    return (0);
}
