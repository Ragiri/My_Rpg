/*
** EPITECH PROJECT, 2019
** fight.c
** File description:
** fight.c
*/

#include "my.h"
#include "struct.h"

enum player_e next_player(enum player_e actual, int nb_enemy)
{
    if (actual == SORA)
        return (DINGO);
    if (actual == DINGO)
        return (DONALD);
    if (actual == DONALD)
        return (ENEMY_1);
    if (actual == ENEMY_1 && nb_enemy >= 2)
        return (ENEMY_2);
    if (actual == ENEMY_1)
        return (SORA);
    if (actual == ENEMY_2 && nb_enemy > 2)
        return (ENEMY_3);
    if (actual == ENEMY_2)
        return (SORA);
    if (actual == ENEMY_3)
        return (SORA);
    return (actual);
}

player_t *select_p(player_t **ally, player_t **ene, enum player_e act)
{
    if (act == SORA)
        return (ally[0]);
    if (act == DINGO)
        return (ally[1]);
    if (act == DONALD)
        return (ally[2]);
    if (act == ENEMY_1)
        return (ene[0]);
    if (act == ENEMY_2)
        return (ene[1]);
    if (act == ENEMY_3)
        return (ene[2]);
}

static void move_arrow(enum player_e actual, fight_t *fight)
{
    if (actual == SORA)
        sfSprite_setPosition(fight->arrow_1, vectorf(380, 230));
    if (actual == DINGO)
        sfSprite_setPosition(fight->arrow_1, vectorf(410, 430));
    if (actual == DONALD)
        sfSprite_setPosition(fight->arrow_1, vectorf(440, 630));
    if (actual == ENEMY_1)
        sfSprite_setPosition(fight->arrow_1, vectorf(1590, 140));
    if (actual == ENEMY_2)
        sfSprite_setPosition(fight->arrow_1, vectorf(1590 - 30, 140 + 200));
    if (actual == ENEMY_3)
        sfSprite_setPosition(fight->arrow_1, vectorf(1590 - 60, 140 + 400));
}

fight_t *manage_fight(fight_t *fight, game_t *game)
{
    int len = 0;

    display_fight(fight, game->window, game->ally);
    fight->actual_p = select_p(game->ally, fight->enemy, fight->actual_player);
    move_arrow(fight->actual_player, fight);
    if (fight->actual_p->stat->hp <= 0)
        fight->step == NEXT_TURN;
    if (fight->step == SELECT)
        selection(fight, game);
    if (fight->step == DO_ACTION)
        fight = exec_action(&fight, &game);
    if (fight->step == NEXT_TURN) {
        for (len = 0; fight->enemy[len] != NULL; len += 1);
        fight->actual_player = next_player(fight->actual_player, len);
        fight->step = SELECT;
    }
    return (fight);
}
