/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_combat
*/

#include "my_rpg.h"

void init_text(sfFont *font, char *str, sfVector2f pos, sfText *text)
{
    sfText_setFont(text, font);
    sfText_setString(text, str);
    sfText_setCharacterSize(text, 40);
    sfText_setColor(text, sfBlack);
    sfText_setPosition(text, pos);
}

int getmallocsize(poke_t *poke)
{
    int i = 0;

    i += my_strlen(poke->info[NAME]);
    i += my_strlen(poke->info[ATK_NAME]);
    i += my_digits(poke->stats[ATK]);
    i += my_digits(poke->stats[DEF]); 
    return (i);
}

void init_c_text(combat_t *combat)
{
    init_text(combat->font, "HP_PLAYER", (sfVector2f){1080, 404}, combat->texts[0]);
    init_text(combat->font, "MHP_PLAYER", (sfVector2f){1080, 450}, combat->texts[4]);
    init_text(combat->font, "PLAYER", (sfVector2f){982, 500}, combat->texts[2]);
    init_text(combat->font, "HP_ENNEMY", (sfVector2f){204, 29}, combat->texts[1]);
    init_text(combat->font, "MHP_ENNEMY", (sfVector2f){204, 80}, combat->texts[5]);
    init_text(combat->font, "ENNEMY", (sfVector2f){95, 110}, combat->texts[3]);
    init_text(combat->font, "PLAYERPKMNINFO", (sfVector2f){63, 636}, combat->texts[6]);
    init_text(combat->font, "PLAYERPKMNINFO", (sfVector2f){63, 760}, combat->texts[7]);
}

void init_combat(combat_t *combat)
{
    for (int i = 0; i != 5; i++)
        combat->clock[i] = sfClock_create();
    for (int i = 0; i != 8; i++)
        combat->texts[i] = sfText_create();
    combat->font = sfFont_createFromFile("police/font.ttf");
    init_c_text(combat);  
    sfText_setColor(combat->texts[0], sfGreen);
    sfText_setColor(combat->texts[1], sfRed);
    combat->list = malloc(sizeof(poke_t));
    combat->list->spr = malloc(sizeof(object_t));
    combat->list->next = NULL;
    if (poke_init(combat->list) != 0) write(1, "Err loading poke\n", 17);
    create_spr_list(combat->list);
}

void load_poke_sprites(combat_t *combat)
{
    sfTexture *tmp;

    combat->spr[0] = sfSprite_create();
    tmp = sfTexture_createFromFile(combat->poke[0].info[PATH_TO_SPRITE], NULL);
    sfSprite_setTexture(combat->spr[0], tmp, sfTrue);
    combat->spr[1] = sfSprite_create();
    tmp = sfTexture_createFromFile(combat->tmp2->info[PATH_TO_SPRITE], NULL);
    sfSprite_setTexture(combat->spr[1], tmp, sfTrue);
    sfSprite_setScale(combat->spr[1], (sfVector2f){-1.3, 1.3});
    sfSprite_setPosition(combat->spr[1], (sfVector2f){550, 300});
    sfSprite_setPosition(combat->spr[0], (sfVector2f){1080, 150});
    particle_create(&combat->particles[0], randint(30, 500), WATER, randfloat(3, 3.5));
    particle_create(&combat->particles[1], randint(30, 500), ELECT, randfloat(3, 3.5));
    /*char *ppkminfo = malloc(sizeof(char) * 1 + getmallocsize(combat->tmp2));
    char *epkminfo = malloc(sizeof(char) * 24 + getmallocsize(&combat->poke[0]));
    memset(ppkminfo, '\0', 23 + getmallocsize(combat->tmp2));
    //ppkminfo[23 + getmallocsize(combat->tmp2)] = '\0';
    ppkminfo[23 + getmallocsize(&combat->poke[0])] = '\0';
    my_strcat(ppkminfo, combat->tmp2->info[NAME]);
    my_strcat(ppkminfo, "\n");
    my_strcat(ppkminfo, combat->tmp2->info[ATK_NAME]);
    my_strcat(ppkminfo, "\n");
    my_strcat(ppkminfo, intstr(combat->tmp2->stats[ATK],
    my_digits(combat->tmp2->stats[ATK])));
    my_strcat(ppkminfo, "\n");
    my_strcat(ppkminfo, intstr(combat->tmp2->stats[DEF],
    my_digits(combat->tmp2->stats[DEF])));
    sfText_setString(combat->texts[6], ppkminfo);
    sfText_setString(combat->texts[7], "");*/
}
