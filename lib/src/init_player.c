/*
** EPITECH PROJECT, 2019
** init_player
** File description:
** init_player
*/

#include "my.h"
#include "struct.h"

player_t *init_player(char *sprite, char *art, char *name, sfIntRect rect)
{
    player_t *player = malloc(sizeof(*player));

    player->str_name = my_strdup(name);
    player->name = txt_create(100, sfWhite, vectorf(0, 0), name);
    player->player_s = sprite_create(sprite, rect, vectorf(0, 0));
    player->art_s = sprite_create(art, rect, vectorf(0, 0));
    player->rect = rect;
    return (player);
}
