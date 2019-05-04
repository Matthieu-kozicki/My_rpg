/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** create
*/

#include "my_rpg.h"

int particle_getpoints(enum type type)
{
    if (type == FIRE || type == ROCK || type == NORMAL) return (4);
    if (type == WATER) return (500);
    if (type == LEAF) return (5);
    if (type == ELECT) return (6);
    return (4);
}

sfColor particle_getcolor(enum type type)
{
    if (type == FIRE) return ((sfColor){255, 102, 0, 255});
    if (type == ROCK) return ((sfColor){102, 51, 0, 255});
    if (type == NORMAL) return (sfWhite);
    if (type == WATER) return ((sfColor){0, 102, 255, 255});
    if (type == LEAF) return ((sfColor){51, 204, 51, 255});
    if (type == ELECT) return ((sfColor){255, 255, 0, 255});
    return (sfWhite);
}

void particle_draw(game_t *game, particle_t *particles)
{
    for (int i = 0; i != particles->size && particles->started == 1; i++) {
        sfRenderWindow_drawCircleShape(game->window, particles->pixels[i],
        NULL);
    }
}

void particle_create(particle_t *particle, int size, enum type type, float radius)
{
    particle->type = type;
    particle->size = size;
    particle->pixels = malloc(sizeof(sfCircleShape*) * size);
    for (int i = 0; i != size; i++) {
        particle->pixels[i] = sfCircleShape_create();
        sfCircleShape_setRadius(particle->pixels[i], radius);
        sfCircleShape_setPointCount(particle->pixels[i],
        particle_getpoints(type));
        sfCircleShape_setFillColor(particle->pixels[i],
        particle_getcolor(type));
        sfCircleShape_setPosition(particle->pixels[i], (sfVector2f){-99999, 99999});
    }
}

void particle_end(particle_t *particle, int i, sfVector2f *tmp, sfColor *col)
{
    if (tmp->x >= particle->pos[1].x && tmp->x <= particle->pos[1].x + particle->size*4 &&
    tmp->y <= particle->pos[1].y + particle->size*4 && tmp->y >= particle->pos[1].y) {
        col->a = 0;
    }
    if (i == particle->size - 1 && col->a <= 0) {
        particle->started = 0;
    }
}
/* PARTICLES TEST
    game->particles[0] = sfVertexArray_create();
    create_my_vertex(game->particles[0], 3, sfTriangles);
    sfVertex test[4];
    test[0].color = sfRed;
    test[0].position = (sfVector2f){10, 10};
    test[1].color = sfBlue;
    test[1].position = (sfVector2f){100, 10};
    test[2].color = sfGreen;
    test[2].position = (sfVector2f){100, 150};
    test[3].color = sfYellow;
    test[3].position = (sfVector2f){0, 100};
    sfVertexArray_append(game->particles[0], test[0]);
    sfVertexArray_append(game->particles[0], test[1]);
    sfVertexArray_append(game->particles[0], test[2]);
*/
