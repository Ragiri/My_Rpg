/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** move_anim
*/

#include "my.h"
#include "struct.h"

sfIntRect rect_transform(sfIntRect rect, int left, int width)
{
    rect.left = left;
    rect.width = width;
    return (rect);
}

sfIntRect still_pos(sfIntRect rect, sfSprite *spr)
{
    if (!sfKeyboard_isKeyPressed(sfKeyD) &&
    !sfKeyboard_isKeyPressed(sfKeyQ) &&
    !sfKeyboard_isKeyPressed(sfKeyZ) &&
    !sfKeyboard_isKeyPressed(sfKeyS)) {
        rect.left = 4408 + 100;
        rect.width = 100;
    }
    return (rect);
}

sfIntRect animation(sfIntRect rect, sfSprite *spr)
{
    static int i = 0;

    rect = still_pos(rect, spr);
    rect = right_anim_u(rect, spr);
    rect = right_anim_d(rect, spr);
    rect = right_anim_r(rect, spr);
    rect = right_anim_l(rect, spr);
    sfSprite_setTextureRect(spr, rect);
    return (rect);
}
