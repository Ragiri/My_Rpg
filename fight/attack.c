/*
** EPITECH PROJECT, 2019
** attack
** File description:
** attack
*/

#include "my.h"
#include "struct.h"

static sfIntRect *init_rect_target(player_t *target)
{
    sfIntRect *rect = malloc(sizeof(*rect));

    if (my_strcmp(target->str_name, "groboulet") == 0)
        *rect = (sfIntRect){-100, 80, 100, 80};
    if (my_strcmp(target->str_name, "soldier") == 0)
        *rect = (sfIntRect){-50, 60, 50, 49};
    if (my_strcmp(target->str_name, "Sora") == 0)
        *rect = (sfIntRect){-60, 44, 60, 48};
    return (rect);
}

static sfIntRect *init_rect_player(player_t *player)
{
    sfIntRect *rect = malloc(sizeof(*rect));

    if (my_strcmp(player->str_name, "Sora") == 0)
        *rect = (sfIntRect){-70, 92, 70, 60};
    if (my_strcmp(player->str_name, "soldier") == 0)
        *rect = (sfIntRect){-60, 109, 60, 64};
    if (my_strcmp(player->str_name, "groboulet") == 0)
        *rect = (sfIntRect){-100, 160, 100, 86};
    return (rect);
}

void do_anim_enemy(player_t **enemy, sfIntRect *t, fight_t *fight,
void (*anim[6])(player_t *, enum status_e, sfIntRect))
{
    if (my_strcmp(fight->target_p->str_name, "groboulet") == 0 && t->top != 0)
        anim[4](fight->target_p, HIT, *t);
    if (my_strcmp(fight->target_p->str_name, "soldier") == 0 && t->top != 0)
        anim[3](fight->target_p, HIT, *t);
    if (my_strcmp(fight->target_p->str_name, "Sora") == 0 && t->top != 0)
        anim[SORA](fight->target_p, HIT, *t);
}

void do_anim(player_t **ally, player_t **enemy, fight_t *fight)
{
    static void (*anim_sprite[6])(player_t *, enum status_e, sfIntRect) = {
    anim_sora_move, anim_sora_move, anim_sora_move, anim_soldier,
    anim_groboulet, anim_soldier};
    static sfIntRect *t = NULL;
    static sfIntRect *p = NULL;

    if (p == NULL)
        p = init_rect_player(fight->actual_p);
    if (t == NULL)
        t = init_rect_target(fight->target_p);
    if (p->top != 0)
        anim_sprite[fight->actual_player](fight->actual_p, ATTACKING, *p);
    *p = sfSprite_getTextureRect(fight->actual_p->player_s);
    do_anim_enemy(enemy, t, fight, anim_sprite);
    *t = sfSprite_getTextureRect(fight->target_p->player_s);
    if (t->top == 0 && p->top == 0) {
        fight->a_step = DAMAGE;
        t = NULL;
        p = NULL;
    }
}

fight_t *manage_attack(fight_t **fight, game_t **game)
{
    static clocks_t *clock = NULL;

    if (clock == NULL)
        clock = init_clock_p();
    clock->time = sfClock_getElapsedTime(clock->clock);
    clock->seconds = clock->time.microseconds / 1000000.0;
    if ((*fight)->a_step == SELECTION)
        *fight = manage_selection(fight, game);
    else if ((*fight)->a_step == ANIMATION && clock->seconds > 0.20) {
        do_anim((*game)->ally, (*fight)->enemy, *fight);
        sfClock_restart(clock->clock);
    }
    if ((*fight)->a_step == DAMAGE) {
        (*fight)->step = NEXT_TURN;
        damage_step(*fight, *game);
        (*fight)->a_step = SELECTION;
    }
    return (*fight);
}
