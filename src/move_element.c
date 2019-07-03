/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** move_element
*/

#include "my.h"
#include "struct.h"

void move_element_spr(sfVector2f move, sfSprite **spr)
{
    sfSprite_move(spr[0], move);
    sfSprite_move(spr[2], move);
}

void move_enemy(sfVector2f move, sfSprite **spr)
{
    for (int i = 0; spr[i] != NULL; i++)
        sfSprite_move(spr[i], move);
}

void move_rect_sh(sfVector2f move, sfRectangleShape **rect)
{
    for (int i = 0; rect[i] != NULL; i++)
        sfRectangleShape_move(rect[i], move);
}

void move_all_col(int x, int y, sfRectangleShape **rect)
{
    sfVector2f pos;

    pos.x = x;
    pos.y = y;
    for (int i = 0; rect[i] != NULL; i++)
        sfRectangleShape_move(rect[i], pos);
}

void move_all_obj(sfVector2f move, sfSprite **spr, sfSprite **en,
sfRectangleShape **rect)
{
    move_enemy(move, en);
    move_element_spr(move, spr);
    move_rect_sh(move, rect);
}