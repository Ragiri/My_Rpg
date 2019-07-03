/*
** EPITECH PROJECT, 2019
** titlescreen
** File description:
** titlescreen
*/

#include "my.h"
#include "struct.h"

titlescreen_t *init_titlescreen(void)
{
    titlescreen_t *title = malloc(sizeof(*title));

    title->title = sprite_create("ressources/assets/title.png",
    (sfIntRect){0, 0, 822, 446}, (sfVector2f){711, 263});
    title->bg = sprite_create("./ressources/assets/bg_titlescreen.jpg",
    (sfIntRect){0, 0, 1929, 1085}, (sfVector2f){0, 0});
    title->white = sprite_create("./ressources/assets/White screen.jpg",
    (sfIntRect){0, 0, 1920, 1080}, (sfVector2f){0, 0});
    title->text = txt_create(180, (sfColor){255, 255, 255, 5},
    (sfVector2f){400, 900}, "Press enter key to continue");
    sfSprite_setColor(title->white, (sfColor){255, 255, 255, 0});
    sfSprite_setOrigin(title->title, (sfVector2f){822 / 2, 446 / 2});
    sfSprite_setColor(title->title, (sfColor){255, 255, 255, 0});
    sfSprite_setScale(title->title, (sfVector2f){10.0, 10.0});
    return (title);
}

static void print_all(sfRenderWindow *window, titlescreen_t *title)
{
    sfVector2f scale = sfSprite_getScale(title->title);
    sfColor color = sfSprite_getColor(title->white);
    sfColor color2 = sfText_getColor(title->text);

    if (scale.x < 4)
        sfSprite_setColor(title->title, (sfColor){255, 255, 255, 255});
    if (color.a < 7 && color.a > 4 && color2.a < 255)
        sfText_setColor(title->text, (sfColor){255, 255, 255, color2.a + 10});
    sfRenderWindow_drawSprite(window, title->bg, NULL);
    sfRenderWindow_drawSprite(window, title->title, NULL);
    sfRenderWindow_drawText(window, title->text, NULL);
    sfRenderWindow_drawSprite(window, title->white, NULL);
    sfRenderWindow_display(window);
    sfRenderWindow_clear(window, sfBlack);
}

static void anim_titlescreen(sfSprite *bg, sfSprite *title, sfSprite *white)
{
    sfVector2f scale = sfSprite_getScale(title);
    static float i = 0;
    float acc = 0.4;
    static sfColor color = {255, 255, 255, 4};

    acc *= i;
    i += 0.0005;
    if (scale.x >= 1.05 && color.a == 4)
        sfSprite_setScale(title, (sfVector2f){scale.x - acc, scale.y - acc});
    else if (scale.x < 1.2 && color.a == 4)
        sfSprite_setScale(title, (sfVector2f){1, 1});
    if (scale.x == 1 && color.a != 254) {
        color.a += 50;
        sfSprite_setColor(white, color);
    } else if (scale.x >= 1.0 && color.a > 6) {
        sfSprite_setScale(title, (sfVector2f){1.01, 1.01});
        color.a -= 2;
        sfSprite_setColor(white, color);
    }
}

static void press_return(sfMusic *title, sfRenderWindow *win, titlescreen_t *t)
{
    sfMusic *music = music_create("ressources/music/Start.ogg", 100.0);
    static sfVector2f scale = {0.999999, 1};
    static int color = 0;
    static float modif = 0.020;

    sfMusic_setLoop(music, sfFalse);
    sfMusic_pause(title);
    while (sfMusic_getStatus(music) == sfPlaying) {
        print_all(win, t);
        if (scale.x > 1.0 || scale.x <= -1.0)
            modif *= -1;
        if (color != 255)
            color += 1;
        sfSprite_setScale(t->title, (sfVector2f){scale.x + modif, scale.y});
        sfSprite_setColor(t->white, (sfColor){255, 255, 255, color});
        scale.x += modif;
    }
    scale = (sfVector2f){1, 1};
    sfMusic_destroy(music);
    sfMusic_play(title);
}

int titlescreen(game_t *game, titlescreen_t *title)
{
    sfColor color;

    if (game->scene == TITLESCREEN) {
        game->fps.time = sfClock_getElapsedTime(game->fps.clock);
        if (game->fps.time.microseconds / 1000000.0 > 1 / 60) {
            print_all(game->window, title);
            anim_titlescreen(title->bg, title->title, title->white);
            color = sfText_getColor(title->text);
            sfClock_restart(game->fps.clock);
        }
        if (sfKeyboard_isKeyPressed(sfKeyReturn) && color.a != 255)
            game->scene = MENU;
        if (sfKeyboard_isKeyPressed(sfKeyReturn) && color.a == 255) {
            press_return(game->music, game->window, title);
            game->scene = MENU;
        }
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            game->scene = EXIT;
    }
}
