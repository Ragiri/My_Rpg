/*
** EPITECH PROJECT, 2019
** display_fight
** File description:
** display_fight
*/

#include "my.h"
#include "struct.h"

void display_hud(fight_hud_t *hud, sfRenderWindow *window)
{
    for (int i = 0; i != 3; i += 1) {
        sfRenderWindow_drawSprite(window, hud->hp_ally[i], NULL);
        sfRenderWindow_drawSprite(window, hud->face[i], NULL);
        sfRenderWindow_drawSprite(window, hud->mana[i], NULL);
    }
    sfRenderWindow_drawSprite(window, hud->command, NULL);
    sfRenderWindow_drawSprite(window, hud->select, NULL);
    for (int i = 0; i != 4; i += 1)
        sfRenderWindow_drawText(window, hud->comm_name[i], NULL);
}

void display_fight(fight_t *fight, sfRenderWindow *window, player_t **ally)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, fight->bg, NULL);
    for (int i = 0; i != 3; i += 1)
        sfRenderWindow_drawSprite(window, ally[i]->player_s, NULL);
    display_hud(fight->hud, window);
    for (int i = 0; fight->enemy[i] != NULL; i += 1) {
        sfRenderWindow_drawSprite(window, fight->enemy[i]->player_s, NULL);
    }
    sfRenderWindow_drawSprite(window, fight->arrow_1, NULL);
    sfRenderWindow_drawSprite(window, fight->arrow_2, NULL);
    sfRenderWindow_drawSprite(window, fight->crown, NULL);
    sfRenderWindow_display(window);
}
