/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** pause
*/

#include "my.h"
#include "struct.h"

pause_t *init_pause(void)
{
    pause_t *pause = malloc(sizeof(*pause) * 4);

    pause->txt = txt_pause(80, (sfColor){255, 255, 255, 255},
    (sfVector2f){755, 400}, "Pause");
    pause[1].txt = txt_menu(60, (sfColor){255, 255, 255, 255},
    (sfVector2f){810, 550}, "Continue");
    pause[2].txt = txt_menu(60, (sfColor){255, 255, 255, 255},
    (sfVector2f){870, 650}, "Menu");
    pause[3].txt = txt_menu(60, (sfColor){255, 255, 255, 255},
    (sfVector2f){870, 750}, "Quit");
    pause->spr = sprite_create("ressources/assets/black_screen.png",
    (sfIntRect){0, 0, 1920, 1080}, (sfVector2f){0, 0});
    pause[1].spr = sprite_create("ressources/assets/yellow_b.png",
    (sfIntRect){0, 0, 1920, 1}, (sfVector2f){0, 500});
    sfSprite_setColor(pause->spr, (sfColor){0, 0, 0, 150});
    return (pause);
}

void print_pause(sfRenderWindow *window, pause_t *pause)
{
    sfRenderWindow_drawSprite(window, pause->spr, NULL);
    sfRenderWindow_drawSprite(window, pause[1].spr, NULL);
    sfRenderWindow_drawText(window, pause->txt, NULL);
    sfRenderWindow_drawText(window, pause[1].txt, NULL);
    sfRenderWindow_drawText(window, pause[2].txt, NULL);
    sfRenderWindow_drawText(window, pause[3].txt, NULL);
    sfText_setColor(pause[1].txt, (sfColor){255, 255, 255, 255});
    sfText_setColor(pause[2].txt, (sfColor){255, 255, 255, 255});
    sfText_setColor(pause[3].txt, (sfColor){255, 255, 255, 255});
}

int but_pause(pause_t *pause, game_t *game)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window);

    if (button_is_clicked(pause[1].txt, mouse, vectorf(255, 65)) == 1) {
        sfText_setColor(pause[1].txt, (sfColor){255, 0, 0, 255});
        if (sfMouse_isButtonPressed(sfMouseLeft))
            game->scene = GAME;
    }
    if (button_is_clicked(pause[2].txt, mouse, vectorf(132, 65)) == 1) {
        sfText_setColor(pause[2].txt, (sfColor){255, 0, 0, 255});
        if (sfMouse_isButtonPressed(sfMouseLeft))
            return (12);
    }
    if (button_is_clicked(pause[3].txt, mouse, vectorf(132, 65)) == 1) {
        sfText_setColor(pause[3].txt, (sfColor){255, 0, 0, 255});
        if (sfMouse_isButtonPressed(sfMouseLeft))
            game->scene = EXIT;
    }
}

int pause_l(game_t *game, play_t *play)
{
    static pause_t *pause = NULL;

    if (pause == NULL)
        pause = init_pause();
    if (game->scene == PAUSE) {
        if (sfKeyboard_isKeyPressed(sfKeyReturn))
            game->scene = GAME;
        if (but_pause(pause, game) == 12) {
            sfMusic_stop(play->music_g);
            game->scene = MENU;
            sfMusic_play(game->music);
        }
        print_game(game->window, play);
        print_pause(game->window, pause);
        sfRenderWindow_display(game->window);
        sfRenderWindow_clear(game->window, sfBlack);
    }
}