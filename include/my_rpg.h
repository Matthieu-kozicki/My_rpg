/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** header
*/

#ifndef MY_RPG_
#define MY_RPG_

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>

typedef struct game_s {
    sfRenderWindow *window;
    sfVector2i mouse;
    sfView *view;
    sfView *view_2;
    int screen;
    sfClock *clock;
    sfTime time;
    float second;
} game_t;

typedef struct object_s {
    sfVector2f vector;
    sfVector2f pos;
    sfIntRect rect;
    sfSprite *spr;
    int moused;
} object_t;

//add_functions.c
void move_rect(sfIntRect *rect, int offset, int max_value);

//init.c
void load_window(game_t *game);
void init_game_variables(game_t *game, object_t *obj);

//game_loop.c
void game_loop(game_t *game, object_t *obj);

//manage_event.c
void manage_events(game_t *game, object_t *obj);

//mouve_hero.c
void move_hero_1(sfEvent event, object_t *obj);

//pause.c
void pause_menu(game_t *game, object_t *obj);

//load_resource.c
object_t create_object(const char *path, sfVector2f pos);
object_t *load_object(object_t *obj);

//animation.c
void animation(game_t *game, object_t *obj);

//test.c
void play_game(game_t *game, object_t *obj);

#endif
