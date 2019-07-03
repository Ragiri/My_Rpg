/*
** EPITECH PROJECT, 2019
** init_clock
** File description:
** init_clock
*/

#include "struct.h"

clocks_t init_clock(void)
{
    clocks_t clock;

    clock.clock = sfClock_create();
    clock.time = sfClock_getElapsedTime(clock.clock);
    clock.seconds = clock.time.microseconds / 1000000.0;
    return (clock);
}

clocks_t *init_clock_p(void)
{
    clocks_t *clock = malloc(sizeof(*clock));

    clock->clock = sfClock_create();
    clock->time = sfClock_getElapsedTime(clock->clock);
    clock->seconds = clock->time.microseconds / 1000000.0;
    return (clock);
}
