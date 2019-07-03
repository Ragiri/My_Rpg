/*
** EPITECH PROJECT, 2019
** lib
** File description:
** music create
*/

#include "my.h"

sfMusic *music_create(char *str, float vol)
{
    sfMusic *music = sfMusic_createFromFile(str);

    sfMusic_setLoop(music, sfTrue);
    sfMusic_setVolume(music, vol);
    sfMusic_play(music);
    return (music);
}