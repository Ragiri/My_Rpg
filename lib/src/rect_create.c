/*
** EPITECH PROJECT, 2019
** lib
** File description:
** rectangle create
*/

#include "my.h"

sfIntRect rect_create(int top, int left, int height, int width)
{
    sfIntRect rect;

    rect.top = top;
    rect.left = left;
    rect.height = height;
    rect.width = width;
    return (rect);
}