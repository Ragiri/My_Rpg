/*
** EPITECH PROJECT, 2019
** select_action
** File description:
** select_action
*/

#include "my.h"
#include "struct.h"

static enum action_e change_action(fight_t *fight)
{
    if (sfKeyboard_isKeyPressed(sfKeyDown) && fight->action == ATTACK)
        return (SPELL);
    if (sfKeyboard_isKeyPressed(sfKeyDown) && fight->action == SPELL)
        return (OBJECT);
    if (sfKeyboard_isKeyPressed(sfKeyDown) && fight->action == OBJECT)
        return (RUN);
    if (sfKeyboard_isKeyPressed(sfKeyDown) && fight->action == RUN)
        return (ATTACK);
    if (sfKeyboard_isKeyPressed(sfKeyUp) && fight->action == ATTACK)
        return (RUN);
    if (sfKeyboard_isKeyPressed(sfKeyUp) && fight->action == SPELL)
        return (ATTACK);
    if (sfKeyboard_isKeyPressed(sfKeyUp) && fight->action == OBJECT)
        return (SPELL);
    if (sfKeyboard_isKeyPressed(sfKeyUp) && fight->action == RUN)
        return (OBJECT);
    return (fight->action);
}

static void move_selection(fight_t *fight)
{
    if (fight->action == ATTACK) {
        sfText_setColor(fight->hud->comm_name[0], sfWhite);
        sfText_setPosition(fight->hud->comm_name[0], vectorf(60, 876 + 0));
        sfSprite_setPosition(fight->hud->select, vectorf(0, 840));
    }
    if (fight->action == SPELL) {
        sfText_setColor(fight->hud->comm_name[1], sfWhite);
        sfText_setPosition(fight->hud->comm_name[1], vectorf(60, 876 + 39));
        sfSprite_setPosition(fight->hud->select, vectorf(0, 840 + 39));
    }
    if (fight->action == OBJECT) {
        sfText_setColor(fight->hud->comm_name[2], sfWhite);
        sfText_setPosition(fight->hud->comm_name[2], vectorf(60, 876 + 78));
        sfSprite_setPosition(fight->hud->select, vectorf(0, 840 + 78));
    }
    if (fight->action == RUN) {
        sfText_setColor(fight->hud->comm_name[3], sfWhite);
        sfText_setPosition(fight->hud->comm_name[3], vectorf(60, 876 + 117));
        sfSprite_setPosition(fight->hud->select, vectorf(0, 841 + 117));
    }
}

fight_t *select_action(fight_t *fight)
{
    static sfColor color = {220, 220, 220, 255};
    static int lock = 0;

    if (lock == 0)
        fight->action = change_action(fight);
    if (sfKeyboard_isKeyPressed(sfKeyUp) || sfKeyboard_isKeyPressed(sfKeyLeft)
    || sfKeyboard_isKeyPressed(sfKeyRight)
    || sfKeyboard_isKeyPressed(sfKeyDown))
        lock = 1;
    else
        lock = 0;
    for (int i = 0; i != 4; i += 1) {
        sfText_setColor(fight->hud->comm_name[i], color);
        sfText_setPosition(fight->hud->comm_name[i],
        vectorf(30, 876 + 39 * i));
    }
    move_selection(fight);
    return (fight);
}
