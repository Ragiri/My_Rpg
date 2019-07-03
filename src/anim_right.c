/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** anim_right
*/

#include "my.h"
#include "struct.h"

sfIntRect time_anim_r(float timer, sfIntRect rect)
{
    if (timer >= 0.01)
        rect = rect_transform(rect, 1373 - 171 / 2, 163);
    if (timer >= 0.25 / 2)
        rect = rect_transform(rect, 1200 - 171 / 2, 163);
    if (timer >= 0.5 / 2)
        rect = rect_transform(rect, 1020 - 171 / 2, 163);
    if (timer >= 0.75 / 2)
        rect = rect_transform(rect, 840 - 171 / 2, 163);
    if (timer >= 1.0 / 2)
        rect = rect_transform(rect, 660 - 171 / 2, 163);
    if (timer >= 1.25 / 2)
        rect = rect_transform(rect, 480 - 171 / 2, 163);
    if (timer >= 1.5 / 2)
        rect = rect_transform(rect, 300 - 171 / 2, 163);
    if (timer >= 1.75 / 2)
        rect = rect_transform(rect, 0, 163);
    return (rect);
}

sfIntRect right_anim_r(sfIntRect rect, sfSprite *spr)
{
    static clocks_t *timer = NULL;

    if (!sfKeyboard_isKeyPressed(sfKeyD)) {
        timer = NULL;
        return (rect);
    }
    if (timer == NULL)
        timer = init_clock_p();
    timer->time = sfClock_getElapsedTime(timer->clock);
    timer->seconds = timer->time.microseconds / 1000000.0;
    rect = time_anim_r(timer->seconds, rect);
    if (timer->seconds >= 2.0 / 2)
        sfClock_restart(timer->clock);
    return (rect);
}
