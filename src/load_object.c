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
    obj[4] = create_object("pictures/character.png", (sfVector2f){111, 94});
    obj[5] = create_object("pictures/pause.jpg", (sfVector2f){0, 0});
    obj[6] = create_object("pictures/exit1.png", (sfVector2f){725, 700});
    obj[7] = create_object("pictures/exit2.png", (sfVector2f){725, 700});
    obj[8] = create_object("pictures/exit3.png", (sfVector2f){725, 700});
    obj[9] = create_object("pictures/menu1.png", (sfVector2f){1025, 700});
    obj[10] = create_object("pictures/menu2.png", (sfVector2f){1025, 700});
    obj[11] = create_object("pictures/menu3.png", (sfVector2f){1025, 700});
    obj[12] = create_object("pictures/option1.png", (sfVector2f){725, 500});
    obj[13] = create_object("pictures/option2.png", (sfVector2f){725, 500});
    obj[14] = create_object("pictures/option3.png", (sfVector2f){725, 500});
    obj[15] = create_object("pictures/play1.png", (sfVector2f){725, 300});
    obj[16] = create_object("pictures/play2.png", (sfVector2f){725, 300});
    obj[17] = create_object("pictures/play3.png", (sfVector2f){725, 300});
    return (load_object2(obj));
}

object_t *load_object2(object_t *obj)
{
    obj[18] = create_object("pictures/resume1.png", (sfVector2f){425, 700});
    obj[19] = create_object("pictures/resume2.png", (sfVector2f){425, 700});
    obj[20] = create_object("pictures/resume3.png", (sfVector2f){425, 700});
    obj[21] = create_object("pictures/pause.jpg", (sfVector2f){0, 0});
    obj[22] = create_object("pictures/menu.png", (sfVector2f){0, 0});
    obj[23] = create_object("pictures/back1.png", (sfVector2f){725, 800});
    obj[24] = create_object("pictures/back2.png", (sfVector2f){725, 800});
    obj[25] = create_object("pictures/back3.png", (sfVector2f){725, 800});
    obj[26] = create_object("pictures/option.png", (sfVector2f){0, 0});
    obj[27] = create_object("pictures/sound.png", (sfVector2f){660, 500});
    obj[28] = create_object("pictures/battle.png", (sfVector2f){0, 0});
    obj[29] = create_object("pictures/cursor.png", (sfVector2f){848, 662});
    obj[30] = create_object("pictures/key.png", (sfVector2f){575, 200});
    obj[31] = create_object("pictures/bag.png", (sfVector2f){205, 50});
    obj[32] = create_object("pictures/text.png", (sfVector2f){0, 0});
    obj[33] = create_object("pictures/3d_effect.png", (sfVector2f){0, 0});
    return (obj);
}
