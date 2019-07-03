/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** display_quest
*/

#include "my.h"
#include "struct.h"

void display_quest(play_t *play, sfRenderWindow *window)
{
    if (sfKeyboard_isKeyPressed(sfKeyL)) {
        if (play->quest == START)
            sfRenderWindow_drawSprite(window, play->spr[5], NULL);
        if (play->quest == F_QUEST)
            sfRenderWindow_drawSprite(window, play->spr[6], NULL);
    }
}