/*
** EPITECH PROJECT, 2019
** lib
** File description:
** sound create
*/

#include "my.h"

sfSound *create_sound(char *str, float vol)
{
    sfSound *sound = sfSound_create();
    sfSoundBuffer *buffer = sfSoundBuffer_createFromFile(str);

    sfSound_setBuffer(sound, buffer);
    sfSound_setLoop(sound, sfFalse);
    sfSound_setVolume(sound, vol);
    return (sound);
}