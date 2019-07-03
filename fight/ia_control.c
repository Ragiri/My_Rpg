/*
** EPITECH PROJECT, 2019
** ia_control
** File description:
** ia_control
*/

#include "my.h"
#include "struct.h"

fight_t *manage_selection(fight_t **fight, game_t **game)
{
    int random = 0;

    if ((*fight)->actual_player <= DONALD)
        (*fight)->target_p = select_target((*game)->ally,
        (*fight)->enemy, (*fight));
    else {
        random = rand() % 3;
        while ((*game)->ally[random]->stat->hp <= 0)
            random = rand() % 3;
        (*fight)->target_p = (*game)->ally[random];
        (*fight)->a_step = ANIMATION;
    }
    return (*fight);
}

fight_t *selection(fight_t *fight, game_t *game)
{
    if (fight->actual_player <= DONALD) {
        fight = select_action(fight);
        game->ally = anim_ally(game->ally, MOVE);
        if (sfKeyboard_isKeyPressed(sfKeyReturn) && fight->action == ATTACK)
            fight->step = DO_ACTION;
        while (sfKeyboard_isKeyPressed(sfKeyReturn));
    } else {
        fight->action = ATTACK;
        fight->step = DO_ACTION;
    }
    return (fight);
}
