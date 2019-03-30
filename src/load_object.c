/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** create all sprites needed
*/

#include "my_rpg.h"

object_t create_object(const char *path, sfVector2f pos)
{
    sfTexture *texture;
    object_t obj;

    texture = sfTexture_createFromFile(path, NULL);
    obj.spr = sfSprite_create();
    sfSprite_setTexture(obj.spr, texture, sfTrue);
    obj.pos = pos;
    sfSprite_setPosition(obj.spr, obj.pos);
    obj.rect.top = 0;
    obj.rect.left = 0;
    obj.rect.width = 50;
    obj.rect.height = 50;
    obj.vector.x = 0;
    obj.vector.y = 0;
    return (obj);
}

object_t *load_object(object_t *obj)
{
    obj[0] = create_object("pictures/logo.png", (sfVector2f){-170, 280});
    obj[1] = create_object("pictures/logo.png", (sfVector2f){1750, 280});
    obj[2] = create_object("pictures/intro2.jpg", (sfVector2f){0, 0});
    obj[3] = create_object("pictures/background.png", (sfVector2f){0, 0});
    obj[4] = create_object("pictures/character.png", (sfVector2f){0, 0});
    return (obj);
}
