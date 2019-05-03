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
#include <sys/types.h>
#include <dirent.h>

enum stats {
    TYPE = 0,
    HP,
    ATK,
    DEF,
    COST,
    ACTUAL_HP,
};

enum info {
    NAME = 0,
    ATK_NAME,
    PATH_TO_SPRITE,
    PATH_TO_ATK
};

typedef struct object_s {
    sfVector2f vector;
    sfVector2f pos;
    sfIntRect rect;
    sfSprite *spr;
    int clicked;
    int moused;
    int quest;
} object_t;

typedef struct poke_s {
    int stats[6];
    char *info[4];
    object_t *spr;
    sfText *inv;
    sfText *number;
    sfText *name;
    sfText *attack_name;
    sfText *hp;
    sfText *attack;
    sfText *defense;
    sfText *cost;
    struct poke_s *next;
} poke_t;

typedef struct combat_s {
    sfSprite *spr[2];
    sfText *texts[4];
    sfFont *font;
    int money;
    sfText *cash;
    sfClock *clock[3];
    sfTime time[3];
    float seconds[3];
    float difficulty;
    poke_t poke[2];
    poke_t *inv;
    poke_t *tmp2;
    poke_t *tmp;
    poke_t *list;
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

typedef struct button_s
{
    sfRectangleShape *rect;
    sfFont *font;
    sfText *text;
    sfTexture *texture;
    sfSprite *but;
    char *but_text;
} button_t;

//math_function.c
void move_rect(sfIntRect *rect, int offset, int max_value);
char *my_strcat(char *dest, char const *src);
float randfloat(float min, float max);
long randint(long min, long max);
int my_getnbr(char const *str);

//array.c
char **make_array(int x, int y);
char **fill_array(char **tab, char *str);
void free_array(int y, char **tab);
char **map(int count, char **tab);
void display_array(int y, char **tab);

//shop.c
void shopping(game_t *game, object_t *obj);

//combat.c
void attack(int attacker, game_t *game);
void combat_loop(game_t *game, object_t *obj);
combat_t *init_combat_sprites(char **player_team, char **enmy_team);
char **alloc_2d_array(int nb_rows, int nb_cols);
int check_pokefile(char *path, poke_t *poke);
void init_combat(combat_t *combat);
void load_poke_sprites(combat_t *combat);
int poke_init(poke_t *list);
long randint(long min, long max);
char *my_strdup(char *src);

//combat_ia.c
void combat_ia(game_t *game, float difficulty);
int calculate_atk(int attacker, combat_t *combat);

//list.c
poke_t *add_to_list(poke_t *list);
int size_list(poke_t *list);
void create_spr_list(poke_t *list);
void find_randpoke(game_t *game);

//keybinding.c
void keybinding(game_t *game, object_t *obj);

//clocks.c
void manage_clock(combat_t *combat);

//putinstr.c
char *intstr(int nb, int digits);
long long my_digits(int nb);

//error.c
int my_strlen(char *str);
int my_strcomp(char *str, char *dest);
int check_env(char **env);

//init.c
void load_window(game_t *game);
void init_game_variables(game_t *game, object_t *obj);

//quest.c
void quest(game_t *game, object_t *obj);
void dialogue(game_t *game, object_t *obj);
int nb_digits(int nb);
char *int_to_char(int nb);

//game_loop.c
void game_loop(game_t *game, object_t *obj);
int mouse_is_on(game_t *game, sfVector2f position, int x_max, int y_max);

//load_resource.c
object_t create_object(const char *path, sfVector2f pos);
object_t *load_object(object_t *obj);
object_t *load_object2(object_t *obj);
object_t *load_object3(object_t *obj);

//inventory.c
void inventory(game_t *game, object_t *obj);
void dup_poke(poke_t *origin, poke_t *dup);
sfText *texted(sfText *text, sfVector2f pos, char *str);

//manag_map.c
int check_pos(game_t *game);
int test_block(int space_y, int space_x, game_t *game);
char last_pos(char c, int space_y, int space_x, game_t *game);

//manage_event.c
void manage_events(game_t *game, object_t *obj);
void rand_combat(game_t *game, object_t *obj);

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
