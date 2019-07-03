/*
** EPITECH PROJECT, 2019
** my rpg
** File description:
** option menu
*/

#include "my.h"
#include "struct.h"

option_t *init_opt(void)
{
    option_t *opt = malloc(sizeof(option_t));

    opt->sound = create_sound("ressources/sounds/get_item.ogg", 50);
    opt->s = sprite_create("ressources/assets/menu_option_bg.jpg",
    rect_create(0, 0, 1080, 1920), vectorf(0, 0));
    return (opt);
}

void music_button(sfRenderWindow *window, sfVector2f vect, sfMusic *music)
{
    sfText *txt = txt_create(90, sfWhite, vectorf(300, -5), "Music");
    static sfVector2f size = {210, 30};
    static sfIntRect rect = {100, 150, 420, 30};
    sfRectangleShape *rect_sh = rectsh_create(color_create(169, 169, 169, 255),
    sfTransparent, rect, 5);
    sfRectangleShape *rect_sh_bis = rectsh_create(sfTransparent,
    color_create(145, 145, 145, 255), rect_create(150, 100, 30, 420), 1);

    if (vect.x <= 570 && vect.x >= 149 && vect.y >= 90 && vect.y <= 140)
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            size.x = vect.x - 150;
            sfMusic_setVolume(music, (vect.x - 150) * 0.1);
        }
    sfRectangleShape_setSize(rect_sh, size);
    sfRenderWindow_drawRectangleShape(window, rect_sh_bis, NULL);
    sfRenderWindow_drawRectangleShape(window, rect_sh, NULL);
    sfRenderWindow_drawText(window, txt, NULL);
}

void sound_button(sfRenderWindow *window, sfVector2f vect, sfSound *sound)
{
    sfText *txt = txt_create(90, sfWhite, vectorf(300, 120), "Sound");
    static sfVector2f size = {210, 30};
    static sfIntRect rect = {220, 150, 420, 30};
    sfRectangleShape *rect_sh = rectsh_create(color_create(169, 169, 169, 255),
    sfTransparent, rect, 5);
    sfRectangleShape *rect_sh_bis = rectsh_create(sfTransparent,
    color_create(145, 145, 145, 255), rect_create(150, 220, 30, 420), 1);

    if (vect.x <= 570 && vect.x >= 149 && vect.y >= 220 && vect.y <= 260)
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            size.x = vect.x - 150;
            sfSound_setVolume(sound, (vect.x - 150) * 0.1);
            sfSound_play(sound);
        }
    sfRectangleShape_setSize(rect_sh, size);
    sfRenderWindow_drawRectangleShape(window, rect_sh_bis, NULL);
    sfRenderWindow_drawRectangleShape(window, rect_sh, NULL);
    sfRenderWindow_drawText(window, txt, NULL);
}

void but_opt(game_t *game)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window);
    sfText *back = txt_menu(80, sfWhite, vectorf(20, 850), "Back");

    if (button_is_clicked(back, mouse, vectorf(150, 80)) == 1) {
        sfText_setColor(back, (sfColor){255, 0, 0, 255});
        if (sfMouse_isButtonPressed(sfMouseLeft))
            game->scene = MENU;
    }
    sfRenderWindow_drawText(game->window, back, NULL);
    sfText_setColor(back, sfWhite);
}

void option_menu(game_t *game, option_t *opt, sfMusic *music,
keyboard_t *key)
{
    sfVector2f vect;

    if (game->scene == OPTION) {
        sfRenderWindow_drawSprite(game->window, opt->s, NULL);
        vect.x = sfMouse_getPositionRenderWindow(game->window).x;
        vect.y = sfMouse_getPositionRenderWindow(game->window).y;
        music_button(game->window, vect, music);
        sound_button(game->window, vect, opt->sound);
        key_name_print(game->window);
        key_print(game->window, key);
        but_opt(game);
        sfRenderWindow_display(game->window);
        sfRenderWindow_clear(game->window, sfBlack);
        if (sfKeyboard_isKeyPressed(sfKeyReturn))
            game->scene = MENU;
    }
}
