/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** anim_left
*/

#include "my.h"
#include "struct.h"

sfIntRect time_anim_l(float timer, sfIntRect rect)
{
    if (timer >= 0.01)
        rect = rect_transform(rect, 1551 + 100, 121);
    if (timer >= 0.25 / 2)
        rect = rect_transform(rect, 1725 + 100, 151);
    if (timer >= 0.5 / 2)
        rect = rect_transform(rect, 1890 + 100, 170);
    if (timer >= 0.75 / 2)
        rect = rect_transform(rect, 2086 + 100, 145);
    if (timer >= 1.0 / 2)
        rect = rect_transform(rect, 2250 + 100, 115);
    if (timer >= 1.25 / 2)
        rect = rect_transform(rect, 2412 + 100, 151);
    if (timer >= 1.5 / 2)
        rect = rect_transform(rect, 2578 + 100, 169);
    if (timer >= 1.75 / 2)
        rect = rect_transform(rect, 2754 + 100, 124);
    return (rect);
}

sfIntRect right_anim_l(sfIntRect rect, sfSprite *spr)
{
    static clocks_t *timer = NULL;

    if (!sfKeyboard_isKeyPressed(sfKeyQ)) {
        timer = NULL;
        return (rect);
    }
    if (timer == NULL)
        timer = init_clock_p();
    timer->time = sfClock_getElapsedTime(timer->clock);
    timer->seconds = timer->time.microseconds / 1000000.0;
    rect = time_anim_l(timer->seconds, rect);
    if (timer->seconds >= 2.0 / 2)
        sfClock_restart(timer->clock);
    return (rect);
}
