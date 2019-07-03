/*
** EPITECH PROJECT, 2019
** exec_action
** File description:
** exec_action
*/

#include "my.h"
#include "struct.h"

fight_t *exec_action(fight_t **fight, game_t **game)
{
    if ((*fight)->action == ATTACK)
        *fight = manage_attack(fight, game);
    return (*fight);
}
