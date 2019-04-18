/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** header
*/

#ifndef MY_RPG_
#define MY_RPG_

#include <SFML/System/Export.h>
#include <SFML/System/Types.h>
#include <SFML/System/Time.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <sys/types.h>
#include <inttypes.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
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
    sfClock *clock_2;
    sfTime time_2;
    float second_2;
    combat_t *combat;
    char **test;
    int cursor_pos;
    char **tab;
    int pos_x;
    int pos_y;
    char stock;
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

//add_functions.c
void move_rect(sfIntRect *rect, int offset, int max_value);

//array.c
char **make_array(int x, int y);
char **fill_array(char **tab, char *str);
void free_array(int y, char **tab);
char **map(int count, char **tab);
void display_array(int y, char **tab);

//combat.c
void combat_loop(game_t *game, object_t *obj);
combat_t *init_combat_sprites(char **player_team, char **enmy_team);
char **alloc_2d_array(int nb_rows, int nb_cols);
int check_pokefile(char *path, char **info);

//error.c
int my_strlen(char *str);
int my_strcomp(char *str, char *dest);
int check_env(char **env);

//init.c
void load_window(game_t *game);
void init_game_variables(game_t *game, object_t *obj);

//keybinding.c
void keybinding(game_t *game, object_t *obj);

//game_loop.c
void game_loop(game_t *game, object_t *obj);
int mouse_is_on(game_t *game, sfVector2f position, int x_max, int y_max);

//load_resource.c
object_t create_object(const char *path, sfVector2f pos);
object_t *load_object(object_t *obj);
object_t *load_object2(object_t *obj);

//manag_map.c
int check_pos(game_t *game);
int test_block(int space_y, int space_x, game_t *game);
char last_pos(char c, int space_y, int space_x, game_t *game);

//manage_event.c
void manage_events(game_t *game, object_t *obj);

//mouve_hero.c
void move_hero_1(sfEvent event, object_t *obj, game_t *game);

//menu.c
void menu(game_t *game, object_t *obj);
void animation(game_t *game, object_t *obj);

//Menu_option.c
void menu_option(game_t *game, object_t *obj);

//pause.c
void pause_menu(game_t *game, object_t *obj);

//play_game.c
void play_game(game_t *game, object_t *obj);

#endif
