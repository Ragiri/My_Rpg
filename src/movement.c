/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** movement
*/

#include "my.h"
#include "struct.h"

int movement_down(sfRectangleShape **rect, sfSprite **spr, sfSprite **en)
{
    static clocks_t *timer = NULL;

    if (!sfKeyboard_isKeyPressed(sfKeyS)) {
        timer = NULL;
        return (0);
    }
    if (timer == NULL)
        timer = init_clock_p();
    timer->time = sfClock_getElapsedTime(timer->clock);
    timer->seconds = timer->time.microseconds / 1000000.0;
    if (timer->seconds >= 0.01) {
        move_all_obj(vectorf(0, -10), spr, en, rect);
        if (check_collision(spr[1], rect) == 1) {
            move_all_obj(vectorf(0, 10), spr, en, rect);
        }
        sfClock_restart(timer->clock);
    }
}

int movement_up(sfRectangleShape **rect, sfSprite **spr, sfSprite **en)
{
    static clocks_t *timer = NULL;

    if (!sfKeyboard_isKeyPressed(sfKeyZ)) {
        timer = NULL;
        return (0);
    }
    if (timer == NULL)
        timer = init_clock_p();
    timer->time = sfClock_getElapsedTime(timer->clock);
    timer->seconds = timer->time.microseconds / 1000000.0;
    if (timer->seconds >= 0.01) {
        move_all_obj(vectorf(0, 10), spr, en, rect);
        if (check_collision(spr[1], rect) == 1) {
            move_all_obj(vectorf(0, -10), spr, en, rect);
        }
        sfClock_restart(timer->clock);
    }
}

int movement_right(sfRectangleShape **rect, sfSprite **spr, sfSprite **en)
{
    static clocks_t *timer = NULL;

    if (!sfKeyboard_isKeyPressed(sfKeyD)) {
        timer = NULL;
        return (0);
    }
    if (timer == NULL)
        timer = init_clock_p();
    timer->time = sfClock_getElapsedTime(timer->clock);
    timer->seconds = timer->time.microseconds / 1000000.0;
    if (timer->seconds >= 0.01) {
        move_all_obj(vectorf(-10, 0), spr, en, rect);
        if (check_collision(spr[1], rect) == 1) {
            move_all_obj(vectorf(10, 0), spr, en, rect);
    }
        sfClock_restart(timer->clock);
    }
}

int movement_left(sfRectangleShape **rect, sfSprite **spr, sfSprite **en)
{
    static clocks_t *timer = NULL;

    if (!sfKeyboard_isKeyPressed(sfKeyQ)) {
        timer = NULL;
        return (0);
    }
    if (timer == NULL)
        timer = init_clock_p();
    timer->time = sfClock_getElapsedTime(timer->clock);
    timer->seconds = timer->time.microseconds / 1000000.0;
    if (timer->seconds >= 0.01) {
        move_all_obj(vectorf(10, 0), spr, en, rect);
        if (check_collision(spr[1], rect) == 1) {
            move_all_obj(vectorf(-10, 0), spr, en, rect);
            }
        sfClock_restart(timer->clock);
    }
}

void movement(sfRectangleShape **rect, sfSprite **spr, sfSprite **en)
{
    movement_right(rect, spr, en);
    movement_left(rect, spr, en);
    movement_down(rect, spr, en);
    movement_up(rect, spr, en);
}
