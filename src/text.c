/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** sftext
*/

#include "my_rpg.h"

void update_score(game_t *game)
{
    char *str;

    game->cash++;
    str = int_to_string(game->cash);
    sfText_setString(game->money, str);
}

sfText *texted(sfText *text, sfVector2f position, char *str)
{
    sfFont *font;

    font = sfFont_createFromFile("police/police.ttf");
    text = sfText_create();
    sfText_setPosition(text, position);
    sfText_setString(text, str);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 50);
    return (text);
}
