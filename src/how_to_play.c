/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** how_to_play
*/

#include "my.h"
#include "struct.h"

int anim_htp(menu_t *menu, game_t *game)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window);

    if (button_is_clicked(menu->htp, mouse, vectorf(330, 40)) == 1) {
        sfText_setColor(menu->htp, (sfColor){0, 0, 0, 255});
        if (sfMouse_isButtonPressed(sfMouseLeft))
            game->scene = HOW_TO_PLAY;
    }
}

static htp_t *init_htp(void)
{
    htp_t *htp = malloc(sizeof(*htp));

    htp->spr = sprite_create("ressources/assets/guide.png",
    (sfIntRect){0, 0, 1920, 1080}, vectorf(0, 0));
    htp->txt = txt_menu(55, (sfColor){0, 0, 0, 100},
    vectorf(0, 0), "Quit");
    return (htp);
}

static void print_htp(sfRenderWindow *window, htp_t *htp)
{
    sfRenderWindow_drawSprite(window, htp->spr, NULL);
    sfRenderWindow_drawText(window, htp->txt, NULL);
    sfText_setColor(htp->txt, (sfColor){0, 0, 0, 100});
}

static int anim_but(game_t *game, htp_t *htp)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window);

    if (button_is_clicked(htp->txt, mouse, vectorf(115, 55)) == 1) {
        sfText_setColor(htp->txt, (sfColor){0, 0, 0, 255});
        if (sfMouse_isButtonPressed(sfMouseLeft))
            return (1);
    }
    return (0);
}

void htp_loop(game_t *game)
{
    static htp_t *htp = NULL;

    if (htp == NULL)
        htp = init_htp();
    if (game->scene == HOW_TO_PLAY) {
        print_htp(game->window, htp);
        if (anim_but(game, htp) == 1)
            game->scene = MENU;
        sfRenderWindow_display(game->window);
    }
}