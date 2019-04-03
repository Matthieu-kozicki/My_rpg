/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** textbox
*/

#include <my_rpg.h>

char key_to_char(int key)
{
    int i = key;
    char conv = 96;

    if (key >= 97 && key <= 122) {
        while (i != key) {
            i++;
        }
        return ((conv*-1)+i+96);
    } else if (key >= 65 && key <= 90) {
        i = key;
        conv = 64;
        while (i != key) {
            i++;
        }
        return ((conv*-1)+i+64);
    }
    return (-1);
}

void create_text_box(button_t *new, sfVector2f position, sfColor color)
{
    new->rect = sfRectangleShape_create();
    sfRectangleShape_setSize(new->rect, (sfVector2f){500, 100});
    sfRectangleShape_setPosition(new->rect, position);
    sfRectangleShape_setFillColor(new->rect, color);
    new->font = sfFont_createFromFile("bonus/ressources/font.ttf");
    new->text = sfText_create();
    sfText_setColor(new->text, sfWhite);
    sfText_setFont(new->text, new->font);
    sfText_setString(new->text, "Enter the path to your custom map here");
    sfText_setPosition(new->text, position);
    new->but_text = malloc(sizeof(char) * 30);
    new->but_text[29] = '\0';
}

int textbox_is_focused(button_t *button, sfVector2i click_position)
{
    sfVector2f pos_but = sfRectangleShape_getPosition(button->rect);
    sfVector2f size = sfRectangleShape_getSize(button->rect);

    if (click_position.x > pos_but.x &&
        click_position.x < pos_but.x + size.x &&
        click_position.y > pos_but.y &&
        click_position.y < pos_but.y + size.y)
        return (1);
    return (0);
}

void text_box_manager(button_t *box, sfRenderWindow *window, sfEvent *event)
{
    static int index = 0;
    int input = 0;

    if (textbox_is_focused(box, sfMouse_getPositionRenderWindow(window))) {
        input = key_to_char(event->key.code);
        if (input != -1 && index != 30) {
            box->but_text[index] = input;
            box->but_text[index+1] = '\0';
            index++;
        } else if (event->key.code == 8 && index > 0) {
            box->but_text[index-1] = '\0';
            index--;
            sfText_setString(box->text, box->but_text);
            return;
        }
        box->but_text[29] = '\0';
        sfText_setString(box->text, box->but_text);
    }
}