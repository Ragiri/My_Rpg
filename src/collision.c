/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** collision
*/

#include "my.h"
#include "struct.h"

int check_collision(sfSprite *spr, sfRectangleShape **rectsh)
{
    sfFloatRect rect_spr = sfSprite_getGlobalBounds(spr);
    sfFloatRect rect_rect;

    for (int i = 0; rectsh[i] != NULL; i++) {
        rect_rect = sfRectangleShape_getGlobalBounds(rectsh[i]);
        if (sfFloatRect_intersects(&rect_spr, &rect_rect, NULL))
            return (1);
    }
    return (0);
}

int quest_collision(sfSprite **spr)
{
    sfFloatRect rect_player = sfSprite_getGlobalBounds(spr[1]);
    sfFloatRect rect_pnj = sfSprite_getGlobalBounds(spr[2]);

    if (sfFloatRect_intersects(&rect_player, &rect_pnj, NULL))
        return (1);
    return (0);
}

int check_enemy(sfSprite **spr, sfSprite **enemy)
{
    sfFloatRect rect_player = sfSprite_getGlobalBounds(spr[1]);
    sfFloatRect enemy_pos;

    for (int i = 0; enemy[i] != NULL; i++) {
        enemy_pos = sfSprite_getGlobalBounds(enemy[i]);
        if (sfFloatRect_intersects(&rect_player, &enemy_pos, NULL))
            return (1);
    }
    return (0);
}
