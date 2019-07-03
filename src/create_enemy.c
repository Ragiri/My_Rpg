/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** create_enemy
*/

#include "my.h"
#include "struct.h"

play_t *create_enemy(play_t *play)
{
    play->enemy = malloc(sizeof(sfSprite *) * (3 + 1));
    play->enemy[0] = sprite_create("ressources/assets/enemy_map1.png",
    (sfIntRect){0, 0, 72, 80}, vectorf(0, 1000));
    play->enemy[1] = sprite_create("ressources/assets/enemy_map2.png",
    (sfIntRect){0, 0, 33, 47}, vectorf(3180 - 2000, 2595 - 1400));
    play->enemy[2] = sprite_create("ressources/assets/enemy_map1.png",
    (sfIntRect){0, 0, 72, 80}, vectorf(2958 - 2000, 3600 - 1400));
    play->enemy[3] = NULL;
    for (int i = 0; play->enemy[i] != NULL; i++)
        sfSprite_setScale(play->enemy[i], vectorf(3, 3));
}