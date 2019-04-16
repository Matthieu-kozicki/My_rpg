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
#include <time.h>

typedef struct combat_s {
    sfText **texts;
} combat_t;

typedef struct game_s {
    sfRenderWindow *window;
    sfVector2i mouse;
    sfView *view;
    sfView *view_2;
    sfMusic *music;
    float volume;
    int screen;
    sfClock *clock;
    sfTime time;
    float second;
    combat_t *combat;
    char **test;
    int cursor_pos;
} game_t;

typedef struct object_s {
    sfVector2f vector;
    sfVector2f pos;
    sfIntRect rect;
    sfSprite *spr;
    int clicked;
    int moused;
} object_t;

typedef struct button_s
{
    sfRectangleShape *rect;
    sfFont *font;
    sfText *text;
    sfTexture *texture;
    sfSprite *but;
    char *but_text;
}button_t;

//combat.c
void combat_loop(game_t *game, object_t *obj);
combat_t *init_combat_sprites(char **player_team, char **enmy_team);
char **alloc_2d_array(int nb_rows, int nb_cols);
int check_pokefile(char *path, char **info);

//add_functions.c
void move_rect(sfIntRect *rect, int offset, int max_value);

//init.c
void load_window(game_t *game);
void init_game_variables(game_t *game, object_t *obj);

//game_loop.c
void game_loop(game_t *game, object_t *obj);
int mouse_is_on(game_t *game, sfVector2f position, int x_max, int y_max);

//manage_event.c
void manage_events(game_t *game, object_t *obj);

//mouve_hero.c
void move_hero_1(sfEvent event, object_t *obj, game_t *game);

//pause.c
void pause_menu(game_t *game, object_t *obj);

//load_resource.c
object_t create_object(const char *path, sfVector2f pos);
object_t *load_object(object_t *obj);
object_t *load_object2(object_t *obj);

//menu.c
void menu(game_t *game, object_t *obj);
void animation(game_t *game, object_t *obj);

//Menu_option.c
void menu_option(game_t *game, object_t *obj);

//error.c
int my_strlen(char *str);
int my_strcomp(char *str, char *dest);
int check_env(char **env);

//test.c
void play_game(game_t *game, object_t *obj);

#endif
