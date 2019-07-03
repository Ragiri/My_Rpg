/*
** EPITECH PROJECT, 2019
** select_target
** File description:
** select_target
*/

#include "my.h"
#include "struct.h"

player_t *swap(player_t **ally, player_t **enemy, enum player_e target)
{
    if (target == SORA)
        return (ally[0]);
    if (target == DINGO)
        return (ally[1]);
    if (target == DONALD)
        return (ally[2]);
    if (target == ENEMY_1)
        return (enemy[0]);
    if (target == ENEMY_2)
        return (enemy[1]);
    if (target == ENEMY_3)
        return (enemy[2]);
}

static void move_arrow_target(enum player_e target, fight_t *fight)
{
    if (target == SORA)
        sfSprite_setPosition(fight->arrow_2, vectorf(380, 230));
    if (target == DINGO)
        sfSprite_setPosition(fight->arrow_2, vectorf(410, 430));
    if (target == DONALD)
        sfSprite_setPosition(fight->arrow_2, vectorf(440, 630));
    if (target == ENEMY_1)
        sfSprite_setPosition(fight->arrow_2, vectorf(1590, 140));
    if (target == ENEMY_2)
        sfSprite_setPosition(fight->arrow_2, vectorf(1590 - 30, 140 + 200));
    if (target == ENEMY_3)
        sfSprite_setPosition(fight->arrow_2, vectorf(1590 - 60, 140 + 400));
}

static enum player_e move_target(enum player_e target)
{
    if ((sfKeyboard_isKeyPressed(sfKeyRight) && target == SORA) ||
    (sfKeyboard_isKeyPressed(sfKeyUp) && target == ENEMY_2)) return (ENEMY_1);
    if ((sfKeyboard_isKeyPressed(sfKeyLeft) && target == ENEMY_1) ||
    (sfKeyboard_isKeyPressed(sfKeyUp) && target == DINGO))
        return (SORA);
    if ((sfKeyboard_isKeyPressed(sfKeyDown) && target == SORA) ||
    (sfKeyboard_isKeyPressed(sfKeyUp) && target == DONALD) ||
    (sfKeyboard_isKeyPressed(sfKeyLeft) && target == ENEMY_2))
        return (DINGO);
    if ((sfKeyboard_isKeyPressed(sfKeyDown) && target == ENEMY_1) ||
    (sfKeyboard_isKeyPressed(sfKeyUp) && target == ENEMY_3) ||
    (sfKeyboard_isKeyPressed(sfKeyRight) && target == DINGO))
        return (ENEMY_2);
    if ((sfKeyboard_isKeyPressed(sfKeyLeft) && target == ENEMY_3) ||
    (sfKeyboard_isKeyPressed(sfKeyDown) && target == DINGO))
        return (DONALD);
    if ((sfKeyboard_isKeyPressed(sfKeyRight) && target == DONALD) ||
    (sfKeyboard_isKeyPressed(sfKeyDown) && target == ENEMY_2))
        return (ENEMY_3);
    return (target);
}

void manage_target(player_t **ally, player_t **enemy, fight_t *fight)
{
    static int lock = 0;
    static enum player_e prev = SORA;
    int len = 0;

    if (lock == 0) {
        prev = fight->target_player;
        fight->target_player = move_target(fight->target_player);
    }
    if (sfKeyboard_isKeyPressed(sfKeyUp) || sfKeyboard_isKeyPressed(sfKeyLeft)
    || sfKeyboard_isKeyPressed(sfKeyDown) ||
    sfKeyboard_isKeyPressed(sfKeyRight))
        lock = 1;
    else
        lock = 0;
    for (len = 0; enemy[len] != NULL; len += 1);
    if ((fight->target_player == ENEMY_2 && len < 2)
    || (fight->target_player == ENEMY_3 && len < 3))
        fight->target_player = prev;
    move_arrow_target(fight->target_player, fight);
}

player_t *select_target(player_t **ally, player_t **enemy, fight_t *fight)
{
    manage_target(ally, enemy, fight);
    if (sfKeyboard_isKeyPressed(sfKeyReturn)) {
        if (fight->target_player == fight->actual_player)
            return (NULL);
        else {
            fight->a_step = ANIMATION;
            sfSprite_setPosition(fight->arrow_2, vectorf(0, 0));
            return (swap(ally, enemy, fight->target_player));
        }
    }
    return (NULL);
}
