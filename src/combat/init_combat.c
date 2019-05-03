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

void init_combat(combat_t *combat)
{
    combat->clock[0] = sfClock_create();
    combat->clock[1] = sfClock_create();
    combat->clock[2] = sfClock_create();
    combat->texts[0] = sfText_create();
    combat->texts[1] = sfText_create();
    combat->texts[2] = sfText_create();
    combat->texts[3] = sfText_create();
    combat->font = sfFont_createFromFile("police/font.ttf");  
    init_text(combat->font, "HP_PLAYER", (sfVector2f){1080, 404}, combat->texts[0]);
    init_text(combat->font, "HP_ENNEMY", (sfVector2f){204, 29}, combat->texts[1]);
    init_text(combat->font, "PLAYER", (sfVector2f){982, 461}, combat->texts[2]);
    init_text(combat->font, "ENNEMY", (sfVector2f){95, 85}, combat->texts[3]);
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
    tmp = sfTexture_createFromFile(combat->tmp->info[PATH_TO_SPRITE], NULL);
    sfSprite_setTexture(combat->spr[1], tmp, sfTrue);
    sfSprite_setScale(combat->spr[1], (sfVector2f){-1.3, 1.3});
    sfSprite_setPosition(combat->spr[1], (sfVector2f){550, 300});
    sfSprite_setPosition(combat->spr[0], (sfVector2f){1080, 150});
    combat->particles = malloc(sizeof(particle_t) * 2);
}
