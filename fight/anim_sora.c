/*
** EPITECH PROJECT, 2019
** anim_sora
** File description:
** anim_sora
*/

#include "my.h"
#include "struct.h"

void anim_sora_move(player_t *sora, enum status_e status, sfIntRect rect)
{
    if (status == MOVE) {
        sfSprite_setTextureRect(sora->player_s,
        (sfIntRect){rect.left + 40, 0, 40, 44});
        if (rect.left + 40 >= 240)
            sfSprite_setTextureRect(sora->player_s, sora->rect);
    }
    if (status == HIT) {
        sfSprite_setTextureRect(sora->player_s,
        (sfIntRect){rect.left + 60, 44, 60, 48});
        if (rect.left + 40 >= 240)
            sfSprite_setTextureRect(sora->player_s, sora->rect);
    }
    if (status == ATTACKING) {
        sfSprite_setTextureRect(sora->player_s,
        (sfIntRect){rect.left + 70, 92, 70, 60});
        if (rect.left + 40 >= 240)
            sfSprite_setTextureRect(sora->player_s, sora->rect);
    }
}

void anim_sora(player_t *sora, enum status_e status)
{
    if (status == MOVE || status == HIT || status == ATTACKING)
        anim_sora_move(sora, status, sfSprite_getTextureRect(sora->player_s));
}
