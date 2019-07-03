/*
** EPITECH PROJECT, 2019
** lib
** File description:
** create sprite
*/

#include "my.h"

sfSprite *sprite_create(char *str, sfIntRect rect, sfVector2f pos)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *text = sfTexture_createFromFile(str, NULL);

    sfSprite_setTexture(sprite, text, sfTrue);
    sfSprite_setTextureRect(sprite, rect);
    sfSprite_setPosition(sprite, pos);
    return (sprite);
}
