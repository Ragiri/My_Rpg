/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** game_over
*/

#include "my.h"
#include "struct.h"

static lose_t *init_lose(void)
{
    lose_t *lose = malloc(sizeof(*lose));

    lose->spr = sprite_create("ressources/assets/game_over_screen.png",
    (sfIntRect){0, 0, 1920, 1080}, vectorf(0, 0));
    lose->restart = txt_menu(40, (sfColor){255, 255, 255, 255},
    vectorf(880, 800), "Restart");
    lose->menu = txt_menu(40, (sfColor){255, 255, 255, 255},
    vectorf(900, 900), "Menu");
    lose->quit = txt_menu(40, (sfColor){255, 255, 255, 255},
    vectorf(900, 1000), "Quit");
    return (lose);
}

static void print_lose(sfRenderWindow *window, lose_t *lose)
{
    sfRenderWindow_drawSprite(window, lose->spr, NULL);
    sfRenderWindow_drawText(window, lose->restart, NULL);
    sfRenderWindow_drawText(window, lose->menu, NULL);
    sfRenderWindow_drawText(window, lose->quit, NULL);
    sfText_setColor(lose->restart, (sfColor){255, 255, 255, 255});
    sfText_setColor(lose->menu, (sfColor){255, 255, 255, 255});
    sfText_setColor(lose->quit, (sfColor){255, 255, 255, 255});
}

void reset_game(play_t *play, game_t *game)
{
    game->ally = init_ally();
    play->quest == START;
    play = NULL;
}

static void anim_but(lose_t *lose, game_t *game, play_t *play)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window);

    if (button_is_clicked(lose->restart, mouse, vectorf(155, 40)) == 1) {
        sfText_setColor(lose->restart, (sfColor){255, 0, 0, 255});
        if (sfMouse_isButtonPressed(sfMouseLeft))
            game->scene = GAME;
    }
    if (button_is_clicked(lose->menu, mouse, vectorf(100, 40)) == 1) {
        sfText_setColor(lose->menu, (sfColor){255, 0, 0, 255});
        if (sfMouse_isButtonPressed(sfMouseLeft))
            game->scene = MENU;
    }
    if (button_is_clicked(lose->quit, mouse, vectorf(100, 40)) == 1) {
        sfText_setColor(lose->quit, (sfColor){255, 0, 0, 255});
        if (sfMouse_isButtonPressed(sfMouseLeft))
            game->scene = EXIT;
    }
}

void game_over_l(game_t *game, play_t *play)
{
    static lose_t *lose = NULL;

    if (lose == NULL)
        lose = init_lose();
    if (game->scene == GAME_OVER) {
        print_lose(game->window, lose);
        anim_but(lose, game, play);
        sfRenderWindow_display(game->window);
    }
}