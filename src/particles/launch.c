/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** launch
*/

#include "my_rpg.h"

void particle_setparam(particle_t *particle, sfVector2f start, sfVector2f end, float spacing)
{
    particle->spacing = spacing;
    particle->pos[0] = start;
    particle->pos[1] = end;
}

void particle_launch(particle_t *particle, float speed, sfVector2f scale, float time)
{
    particle->speed = speed;
    particle->time = time;
    for (int i = 0; i != particle->size; i++) {
        sfCircleShape_setScale(particle->pixels[i], scale);
        sfCircleShape_setPosition(particle->pixels[i], particle->pos[0]);
    }
    particle->started = 1;
}

sfVector2f mvect(sfVector2f *tmp, particle_t *particle, float radius)
{
    if (tmp->x > particle->pos[1].x)
        tmp->x -= particle->speed + radius*2;
    else if (tmp->x < particle->pos[1].x)
        tmp->x += particle->speed + radius*2;
    else tmp->x = particle->pos[1].x;
    if (tmp->y > particle->pos[1].y)
        tmp->y -= particle->speed + radius*2;
    else if (tmp->y < particle->pos[1].y)
        tmp->y += particle->speed + radius*2;
    else tmp->y = particle->pos[1].y;
    return (*tmp);
}

void mutation(int i, sfVector2f *pos, particle_t *particle)
{
    sfColor tmp = sfCircleShape_getFillColor(particle->pixels[i]);;

    if (particle->started == 0) return;
    if (particle->type == ROCK)
        sfCircleShape_rotate(particle->pixels[i], randfloat(-10.0, 10.0));
    if (particle->type == ELECT) {
        sfCircleShape_rotate(particle->pixels[i], randfloat(-30.0, 30.0));
        sfCircleShape_setPointCount(particle->pixels[i], randint(3, 10));
        mu_color(&tmp, particle);
        sfCircleShape_setFillColor(particle->pixels[i], tmp);
    }
    if (particle->type == WATER) {
        sfCircleShape_rotate(particle->pixels[i], randfloat(-30.0, 30.0));
        mu_color(&tmp, particle);

    }
    particle_end(particle, i, pos, &tmp);
}

void particle_update(particle_t *particle, sfClock *clock, float time)
{
    sfVector2f tmp;

    if (time < particle->time || particle->started != 1) return;
    for (int i = 0; i != particle->size; i++) {
        tmp = sfCircleShape_getPosition(particle->pixels[i]);
        if (tmp.x == particle->pos[0].x && tmp.y == particle->pos[0].y) {
            mvect(&tmp, particle, particle->spacing);
            tmp.x += randfloat(-30.0, 30.0);
            tmp.y += randfloat(-30.0, 30.0);
            sfCircleShape_setPosition(particle->pixels[i], tmp);
            mutation(i, &tmp, particle);
            return;
        } else if (time >= particle->time) {
            sfCircleShape_setPosition(particle->pixels[i], mvect(&tmp, particle, particle->spacing));
            mutation(i, &tmp, particle);
            sfClock_restart(clock);
        }
    }
}