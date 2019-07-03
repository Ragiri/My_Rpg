/*
** EPITECH PROJECT, 2019
** lib
** File description:
** create txt
*/

#include "my.h"

sfText *txt_create(int size, sfColor color, sfVector2f pos, char *n)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("./ressources/font/KH_Font.ttf");

    sfText_setFont(text, font);
    sfText_setString(text, n);
    sfText_setColor(text, color);
    sfText_setPosition(text, pos);
    sfText_setCharacterSize(text, size);
    return (text);
}

sfText *txt_menu(int size, sfColor color, sfVector2f pos, char *n)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("./ressources/font/makisupa.ttf");

    sfText_setFont(text, font);
    sfText_setString(text, n);
    sfText_setColor(text, color);
    sfText_setPosition(text, pos);
    sfText_setCharacterSize(text, size);
    return (text);
}

sfText *txt_pause(int size, sfColor color, sfVector2f pos, char *n)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("./ressources/font/ARCADE_R.TTF");

    sfText_setFont(text, font);
    sfText_setString(text, n);
    sfText_setColor(text, color);
    sfText_setPosition(text, pos);
    sfText_setCharacterSize(text, size);
    return (text);
}