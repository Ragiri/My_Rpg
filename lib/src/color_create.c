/*
** EPITECH PROJECT, 2019
** lib
** File description:
** color_create
*/

#include "my.h"

sfColor color_create(int r, int g, int b, int a)
{
    sfColor color = {r, g, b, a};

    return (color);
}