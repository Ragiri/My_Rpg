/*
** EPITECH PROJECT, 2019
** anim_enemy
** File description:
** anim_enemy
*/

#include "my.h"
#include "struct.h"

void anim_soldier(player_t *soldier, enum status_e status, sfIntRect rect)
{
    if (status == MOVE) {
        sfSprite_setTextureRect(soldier->player_s,
        (sfIntRect){rect.left + 45, 0, 45, 60});
        if (rect.left + 45 >= 360)
            sfSprite_setTextureRect(soldier->player_s, soldier->rect);
    }
    if (status == HIT) {
        sfSprite_setTextureRect(soldier->player_s,
        (sfIntRect){rect.left + 50, 60, 50, 49});
        if (rect.left + 50 >= 300)
            sfSprite_setTextureRect(soldier->player_s, soldier->rect);
    }
    if (status == ATTACKING) {
        sfSprite_setTextureRect(soldier->player_s,
        (sfIntRect){rect.left + 60, 109, 60, 64});
        if (rect.left + 60 >= 480)
            sfSprite_setTextureRect(soldier->player_s, soldier->rect);
    }
}

void anim_groboulet(player_t *groboulet, enum status_e status, sfIntRect rect)
{
    if (status == MOVE) {
        sfSprite_setTextureRect(groboulet->player_s,
        (sfIntRect){rect.left + 90, 0, 90, 80});
        if (rect.left + 90 >= 630)
            sfSprite_setTextureRect(groboulet->player_s, groboulet->rect);
    }
    if (status == HIT) {
        sfSprite_setTextureRect(groboulet->player_s,
        (sfIntRect){rect.left + 100, 80, 100, 80});
        if (rect.left + 100 >= 400)
            sfSprite_setTextureRect(groboulet->player_s, groboulet->rect);
    }
    if (status == ATTACKING) {
        sfSprite_setTextureRect(groboulet->player_s,
        (sfIntRect){rect.left + 100, 160, 100, 86});
        if (rect.left + 100 >= 700)
            sfSprite_setTextureRect(groboulet->player_s, groboulet->rect);
    }
}

player_t **anim_enemy(player_t **enemy, enum status_e status)
{
    static clocks_t *clock = NULL;

    if (clock == NULL)
        clock = init_clock_p();
    clock->time = sfClock_getElapsedTime(clock->clock);
    clock->seconds = clock->time.microseconds / 1000000.0;
    if (clock->seconds < 0.10)
        return (enemy);
    for (int i = 0; enemy[i] != NULL; i += 1) {
        if (my_strcmp(enemy[i]->str_name, "groboulet") == 0)
            anim_groboulet(enemy[i], status,
            sfSprite_getTextureRect(enemy[i]->player_s));
        if (my_strcmp(enemy[i]->str_name, "soldier") == 0)
            anim_soldier(enemy[i], status,
            sfSprite_getTextureRect(enemy[i]->player_s));
    }
    sfClock_restart(clock->clock);
    return (enemy);
}
