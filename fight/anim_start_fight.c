/*
** EPITECH PROJECT, 2019
** start_fight
** File description:
** start_fight
*/

#include "my.h"
#include "struct.h"

static void display_start(sfRenderWindow *window, fight_t *fight)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, fight->bg, NULL);
    sfRenderWindow_drawSprite(window, fight->crown, NULL);
    sfRenderWindow_drawSprite(window, fight->black, NULL);
    sfRenderWindow_display(window);
}

fight_t *start_fight(game_t *game, fight_t *fight)
{
    sfVector2f scale = sfSprite_getScale(fight->crown);
    static float acc = 0.001;
    static sfColor color = {0, 0, 0, 255};

    display_start(game->window, fight);
    acc *= 1.07;
    sfSprite_setScale(fight->crown, vectorf(scale.x + acc, scale.x + acc));
    if (scale.x > 20) {
        sfSprite_setColor(fight->crown, (sfColor){0, 0, 0, 0});
        sfSprite_setColor(fight->black, color);
        color.a -= 5;
    }
    if (color.a == 0) {
        game->scene = FIGHT;
        acc = 0.001;
        color = (sfColor){0, 0, 0, 255};
    }
    return (fight);
}
