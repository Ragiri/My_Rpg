/*
** EPITECH PROJECT, 2019
** anim_ally
** File description:
** anim_ally
*/

#include "my.h"
#include "struct.h"

player_t **anim_ally(player_t **ally, enum status_e status)
{
    static clocks_t *clock = NULL;

    if (clock == NULL)
        clock = init_clock_p();
    clock->time = sfClock_getElapsedTime(clock->clock);
    clock->seconds = clock->time.microseconds / 1000000.0;
    if (clock->seconds < 0.15)
        return (ally);
    anim_sora(ally[0], status);
    sfClock_restart(clock->clock);
    return (ally);
}
