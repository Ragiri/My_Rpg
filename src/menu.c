/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** menu
*/

#include "my.h"
#include "struct.h"

menu_t *init_menu(void)
{
    menu_t *menu = malloc(sizeof(*menu));

    menu->bg = malloc(sizeof(sfSprite *) * (2 + 1));
    menu->bg[0] = sprite_create("ressources/assets/menu.png",
    (sfIntRect){0, 0, 1920, 1080}, (sfVector2f){0, 0});
    menu->bg[1] = sprite_create("ressources/assets/how_to_play.png",
    (sfIntRect){0, 0, 100, 100}, (sfVector2f){1750, 20});
    menu->start = txt_menu(55, (sfColor){0, 0, 0, 100},
    (sfVector2f){200, 700}, "Start");
    menu->options = txt_menu(55, (sfColor){0, 0, 0, 100},
    (sfVector2f){200, 800}, "Options");
    menu->quit = txt_menu(55, (sfColor){0, 0, 0, 100},
    (sfVector2f){200, 900}, "Quit");
    menu->htp = txt_menu(40, (sfColor){0, 0, 0, 100},
    (sfVector2f){1510, 50}, "How to play");

    return (menu);
}

static void print_menu(sfRenderWindow *window, menu_t *menu)
{
    sfRenderWindow_drawSprite(window, menu->bg[0], NULL);
    sfRenderWindow_drawSprite(window, menu->bg[1], NULL);
    sfRenderWindow_drawText(window, menu->start, NULL);
    sfRenderWindow_drawText(window, menu->options, NULL);
    sfRenderWindow_drawText(window, menu->quit, NULL);
    sfRenderWindow_drawText(window, menu->htp, NULL);
    sfText_setColor(menu->start, (sfColor){0, 0, 0, 100});
    sfText_setColor(menu->options, (sfColor){0, 0, 0, 100});
    sfText_setColor(menu->quit, (sfColor){0, 0, 0, 100});
    sfText_setColor(menu->htp, (sfColor){0, 0, 0, 100});
}

int button_is_clicked(sfText *text, sfVector2i mouse, sfVector2f size)
{
    sfVector2f pos_but = sfText_getPosition(text);

    if (mouse.x > pos_but.x &&
        mouse.x < pos_but.x + size.x &&
        mouse.y > pos_but.y &&
        mouse.y < pos_but.y + size.y)
        return (1);
    return (0);
}

static int anim_but(menu_t *menu, game_t *game, keyboard_t *key)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window);

    if (button_is_clicked(menu->start, mouse, vectorf(145, 55)) == 1) {
        sfText_setColor(menu->start, (sfColor){0, 0, 0, 255});
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            return (42);
        }
    }
    if (button_is_clicked(menu->options, mouse, vectorf(208, 55)) == 1) {
        sfText_setColor(menu->options, (sfColor){0, 0, 0, 255});
        if (sfMouse_isButtonPressed(sfMouseLeft))
            game->scene = OPTION;
    }
    if (button_is_clicked(menu->quit, mouse, vectorf(115, 55)) == 1) {
        sfText_setColor(menu->quit, (sfColor){0, 0, 0, 255});
        if (sfMouse_isButtonPressed(sfMouseLeft))
            game->scene = EXIT;
    }
}

int menu_l(game_t *game, keyboard_t *key, menu_t *menu)
{
    if (game->scene == MENU) {
        print_menu(game->window, menu);
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            game->scene = EXIT;
        if (anim_but(menu, game, key) == 42) {
            game->scene = GAME;
            sfMusic_stop(game->music);
        }
        anim_htp(menu, game);
        sfRenderWindow_display(game->window);
        sfRenderWindow_clear(game->window, sfBlack);
    }
}