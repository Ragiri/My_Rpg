/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** anim_up
*/

#include "my.h"
#include "struct.h"

sfIntRect time_anim_u(float timer, sfIntRect rect)
{
    if (timer >= 0.01)
        rect = rect_transform(rect, 3070 + 100, 114);
    if (timer >= 0.25 / 2)
        rect = rect_transform(rect, 3248 + 100, 97);
    if (timer >= 0.5 / 2)
        rect = rect_transform(rect, 3412 + 100, 88);
    if (timer >= 0.75 / 2)
        rect = rect_transform(rect, 3598 + 100, 102);
    if (timer >= 1.0 / 2)
        rect = rect_transform(rect, 3775 + 100, 111);
    if (timer >= 1.25 / 2)
        rect = rect_transform(rect, 3954 + 100, 101);
    if (timer >= 1.5 / 2)
        rect = rect_transform(rect, 4125 + 100, 95);
    if (timer >= 1.75 / 2)
        rect = rect_transform(rect, 4293 + 100, 89);
    return (rect);
}

sfIntRect right_anim_u(sfIntRect rect, sfSprite *spr)
{
    static clocks_t *timer = NULL;

    if (!sfKeyboard_isKeyPressed(sfKeyZ)) {
        timer = NULL;
        return (rect);
    }
    if (timer == NULL)
        timer = init_clock_p();
    timer->time = sfClock_getElapsedTime(timer->clock);
    timer->seconds = timer->time.microseconds / 1000000.0;
    rect = time_anim_u(timer->seconds, rect);
    if (timer->seconds >= 2.0 / 2)
        sfClock_restart(timer->clock);
    return (rect);
}
