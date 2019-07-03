/*
** EPITECH PROJECT, 2019
** fight
** File description:
** fight
*/

#include "my.h"
#include "struct.h"

static fight_t *init_sprite_fight(fight_t *fight, char *bg)
{
    fight->crown = sprite_create("ressources/assets/crown.png",
    (sfIntRect){0, 0, 464, 387}, vectorf(0, 0));
    fight->bg = sprite_create(bg,
    (sfIntRect){0, 0, 1920, 1080}, vectorf(0, 0));
    fight->black = sprite_create("ressources/assets/Black screen.jpg",
    (sfIntRect){0, 0, 1920, 1080}, vectorf(0, 0));
    sfSprite_setOrigin(fight->crown, vectorf(464 / 2, 387 / 2));
    sfSprite_setPosition(fight->crown, vectorf(1920 / 2 - 100, 1080 / 2));
    sfSprite_setScale(fight->crown, vectorf(0.00001, 0.00001));
    sfSprite_setColor(fight->black, (sfColor){0, 0, 0, 0});
    fight->arrow_1 = sprite_create("ressources/assets/arrow.png",
    (sfIntRect){0, 0, 280, 210}, vectorf(380, 230));
    fight->arrow_2 = sprite_create("ressources/assets/arrow.png",
    (sfIntRect){0, 0, 280, 210}, vectorf(0, 0));
    sfSprite_setRotation(fight->arrow_1, 90);
    sfSprite_setRotation(fight->arrow_2, 90);
    sfSprite_setScale(fight->arrow_1, vectorf(0.2, 0.2));
    sfSprite_setScale(fight->arrow_2, vectorf(0.2, 0.2));
    return (fight);
}

static fight_t *init_fight(char **enemy_str, char *bg)
{
    fight_t *fight = malloc(sizeof(*fight));

    fight = init_sprite_fight(fight, bg);
    fight->actual_player = SORA;
    fight->action = ATTACK;
    fight->step = SELECT;
    fight->a_step = SELECTION;
    fight->target_p = NULL;
    fight->target_player = ENEMY_1;
    fight->enemy = init_enemy(enemy_str);
    fight->music = music_create("ressources/music/battle_music1.ogg", 50);
    sfMusic_stop(fight->music);
    init_hud_fight(fight);
    return (fight);
}

fight_t *free_fight(fight_t *fight)
{
    sfSprite_destroy(fight->crown);
    sfSprite_destroy(fight->bg);
    sfSprite_destroy(fight->black);
    sfMusic_destroy(fight->music);
    for (int i = 0; i != 3; i += 1) {
        sfSprite_destroy(fight->hud->hp_ally[i]);
        sfSprite_destroy(fight->hud->mana[i]);
        sfSprite_destroy(fight->hud->face[i]);
    }
    free(fight);
    return (NULL);
}

enum scene_e scene_manage(fight_t *fight, game_t *game, enum scene_e prev)
{
    if (sfMusic_getStatus(game->music) == sfPlaying)
        sfMusic_stop(game->music);
    if (game->scene == ANIM_FIGHT) {
        fight = start_fight(game, fight);
        return (prev);
    }
    fight = manage_fight(fight, game);
    return (prev);
}

void manage_fight_begin(game_t *game, char **enemy, char *bg)
{
    static fight_t *fight = NULL;
    static enum scene_e previous_scene = NILL;

    if (fight == NULL)
        fight = init_fight(enemy, bg);
    if (game->scene != ANIM_FIGHT && game->scene != FIGHT) {
        previous_scene = game->scene;
        return;
    }
    if (sfMusic_getStatus(fight->music) == sfStopped)
        sfMusic_play(fight->music);
    previous_scene = scene_manage(fight, game, previous_scene);
    if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
        game->scene = GAME;
        previous_scene = NILL;
        fight = free_fight(fight);
        sfMusic_play(game->music);
        while (sfKeyboard_isKeyPressed(sfKeyEscape));
    }
}
