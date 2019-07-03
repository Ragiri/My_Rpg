/*
** EPITECH PROJECT, 2019
** damage_step
** File description:
** damage_step
*/

#include "my.h"
#include "struct.h"

void manage_hp(fight_t *fight, game_t *game)
{
    int hp = 0;
    int hp_max = 0;
    float tmp = 0;

    for (int i = 0; i != 3; i += 1) {
        hp = game->ally[i]->stat->hp;
        hp_max = game->ally[i]->stat->hp_max;
        tmp = (float)(hp) / (float)(hp_max) * 100;
        sfSprite_setTextureRect(fight->hud->hp_ally[i],
        (sfIntRect){(int)((100.0 - tmp) / 5) * 441, 0, 441, 422});
    }
}

int victory_condition(fight_t *fight)
{
    for (int i = 0; fight->enemy[i] != NULL; i += 1)
        if (fight->enemy[i]->stat->hp > 0)
            return (0);
    return (1);
}

fight_t *damage_step(fight_t *fight, game_t *game)
{
    int atk = fight->actual_p->stat->atk;
    int def = fight->target_p->stat->def;
    int hp = fight->target_p->stat->hp;

    fight->target_p->stat->hp = hp - atk + (int)(def / 10);
    manage_hp(fight, game);
    if (fight->target_p->stat->hp <= 0)
        sfSprite_setColor(fight->target_p->player_s, sfTransparent);
    if (victory_condition(fight) == 1)
        fight->step = VICTORY;
    if (game->ally[0]->stat->hp <= 0 && game->ally[1]->stat->hp <= 0 &&
    game->ally[2]->stat->hp <= 0)
        fight->step = DEFEAT;
}
