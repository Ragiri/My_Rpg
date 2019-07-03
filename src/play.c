/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** play
*/

#include "my.h"
#include "struct.h"

play_t *init_play_two(play_t *play)
{
    play->spr[2] = sprite_create("ressources/assets/mickey.png",
    (sfIntRect){0, 0, 110, 185}, vectorf(500, 500));
    play->spr[3] = sprite_create("ressources/assets/text.png",
    (sfIntRect){0, 0, 1920, 1080}, vectorf(0, 0));
    play->spr[4] = sprite_create("ressources/assets/text2.png",
    (sfIntRect){0, 0, 1920, 1080}, vectorf(0, 0));
    play->txt = txt_menu(70, sfRed, vectorf(700, 800), "Press e to talk");
    play->spr[5] = sprite_create("ressources/assets/quest.png",
    (sfIntRect){0, 0, 800, 600}, vectorf(600, 300));
    play->spr[6] = sprite_create("ressources/assets/quest_2.png",
    (sfIntRect){0, 0, 800, 600}, vectorf(600, 300));
}

play_t *init_play(void)
{
    play_t *play = malloc(sizeof(*play));
    sfIntRect temp = {100, 0, 0, 185};

    play->rectsh = malloc(sizeof(*play->rectsh) * (50 + 1));
    play->spr = malloc(sizeof(sfSprite *) * (7 + 1));
    play->rect = temp;
    play->rectsh[50] = NULL;
    play->spr[0] = sprite_create("ressources/assets/map.jpg",
    (sfIntRect){0, 0, 7680, 4320}, (sfVector2f){-2000, -1400});
    play->spr[1] = sprite_create("ressources/assets/sora.png",
    play->rect, (sfVector2f){1000, 500});
    play->music_g = music_create("ressources/music/Game theme.ogg", 70.0);
    init_play_two(play);
    create_enemy(play);
    init_all_col(play);
    return (play);
}

void print_game(sfRenderWindow *window, play_t *play)
{
    sfRenderWindow_drawSprite(window, play->spr[0], NULL);
    sfRenderWindow_drawSprite(window, play->spr[2], NULL);
    sfRenderWindow_drawSprite(window, play->spr[1], NULL);
    for (int i = 0; play->enemy[i] != NULL; i++)
        sfRenderWindow_drawSprite(window, play->enemy[i], NULL);
    for (int i = 0; play->rectsh[i] != NULL; i++)
        sfRenderWindow_drawRectangleShape(window, play->rectsh[i], NULL);
}

int play_l(game_t *game, play_t *play)
{
    if (game->scene == GAME) {
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            game->scene = PAUSE;
        if (sfKeyboard_isKeyPressed(sfKeyI))
            game->scene = INVENTORY;
        if (check_enemy(play->spr, play->enemy) == 1 &&
        game->scene != ANIM_FIGHT) {
            game->scene = ANIM_FIGHT;
            sfMusic_stop(play->music_g);
        }
        if (sfKeyboard_isKeyPressed(sfKeyN))
            game->scene = GAME_OVER;
        print_game(game->window, play);
        display_quest(play, game->window);
        play->rect = animation(play->rect, play->spr[1]);
        movement(play->rectsh, play->spr, play->enemy);
        manage_quest(play, game->window);
        sfRenderWindow_display(game->window);
        sfRenderWindow_clear(game->window, sfBlack);
    }
}
