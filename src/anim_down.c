/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** anim_down
*/

#include "my.h"
#include "struct.h"

sfIntRect time_anim_d(float timer, sfIntRect rect)
{
    if (timer >= 0.01)
        rect = rect_transform(rect, 4578 + 100, 100);
    if (timer >= 0.25 / 2)
        rect = rect_transform(rect, 4726 + 100, 90);
    if (timer >= 0.5 / 2)
        rect = rect_transform(rect, 4888 + 100, 86);
    if (timer >= 0.75 / 2)
        rect = rect_transform(rect, 5052 + 100, 97);
    if (timer >= 1.0 / 2)
        rect = rect_transform(rect, 5212 + 100, 99);
    if (timer >= 1.25 / 2)
        rect = rect_transform(rect, 5378 + 100, 90);
    if (timer >= 1.5 / 2)
        rect = rect_transform(rect, 5540 + 100, 87);
    if (timer >= 1.75 / 2)
        rect = rect_transform(rect, 5693 + 100, 95);
    return (rect);
}

sfIntRect right_anim_d(sfIntRect rect, sfSprite *spr)
{
    static clocks_t *timer = NULL;

    if (!sfKeyboard_isKeyPressed(sfKeyS)) {
        timer = NULL;
        return (rect);
    }
    if (timer == NULL)
        timer = init_clock_p();
    timer->time = sfClock_getElapsedTime(timer->clock);
    timer->seconds = timer->time.microseconds / 1000000.0;
    rect = time_anim_d(timer->seconds, rect);
    if (timer->seconds >= 2.0 / 2)
        sfClock_restart(timer->clock);
    return (rect);
}
