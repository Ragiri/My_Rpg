/*
** EPITECH PROJECT, 2019
** lib
** File description:
** rectangle_shape create
*/

#include "my.h"

sfRectangleShape *rectsh_create(sfColor f, sfColor o, sfIntRect r, float i)
{
    sfRectangleShape *rectsh = sfRectangleShape_create();
    sfVector2f pos = {r.top, r.left};
    sfVector2f size = {r.width, r.height};

    sfRectangleShape_setFillColor(rectsh, f);
    sfRectangleShape_setOutlineColor(rectsh, o);
    sfRectangleShape_setOutlineThickness(rectsh, i);
    sfRectangleShape_setSize(rectsh, size);
    sfRectangleShape_setPosition(rectsh, pos);
    return (rectsh);
}

sfRectangleShape *col_c(sfColor f, sfColor o, sfIntRect r, float i)
{
    sfRectangleShape *rectsh = sfRectangleShape_create();
    sfVector2f pos = {r.left, r.top};
    sfVector2f size = {r.width, r.height};

    sfRectangleShape_setFillColor(rectsh, f);
    sfRectangleShape_setOutlineColor(rectsh, o);
    sfRectangleShape_setOutlineThickness(rectsh, i);
    sfRectangleShape_setSize(rectsh, size);
    sfRectangleShape_setPosition(rectsh, pos);
    return (rectsh);
}