/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** quest
*/

#include "my.h"
#include "struct.h"

//int init_quest(play_t *play)

int trigger_quest(play_t *play, sfRenderWindow *window)
{
    static int check = 0;

    if (check == 0 && sfKeyboard_isKeyPressed(sfKeyE) &&
        quest_collision(play->spr) == 1)
        check = 1;
    for (int i = 0; check == 1;) {
        sfSprite_setTextureRect(play->spr[1], (sfIntRect){4508, 0, 100, 185});
        print_game(window, play);
        sfRenderWindow_drawSprite(window, play->spr[3], NULL);
        sfRenderWindow_display(window);
        if (!sfKeyboard_isKeyPressed(sfKeyE))
            i = 1;
        if (i == 1 && sfKeyboard_isKeyPressed(sfKeyE)) {
            sfSleep((sfTime){120000});
            check = 0;
            play->quest = F_QUEST;
        }
    }
}

void first_quest(play_t *play, sfRenderWindow *window)
{
    static int check = 0;

    if (check == 0 && sfKeyboard_isKeyPressed(sfKeyE) &&
        quest_collision(play->spr) == 1)
        check = 1;
    for (int i = 0; check == 1;) {
        sfSprite_setTextureRect(play->spr[1], (sfIntRect){4508, 0, 100, 185});
        print_game(window, play);
        sfRenderWindow_drawSprite(window, play->spr[4], NULL);
        sfRenderWindow_display(window);
        if (!sfKeyboard_isKeyPressed(sfKeyE))
            i = 1;
        if (i == 1 && sfKeyboard_isKeyPressed(sfKeyE)) {
            sfSleep((sfTime){120000});
            check = 0;
        }
    }
}

void manage_quest(play_t *play, sfRenderWindow *window)
{
    if (quest_collision(play->spr) == 1)
        sfRenderWindow_drawText(window, play->txt, NULL);
    if (play->quest == START) {
        trigger_quest(play, window);

    }
    if (play->quest == F_QUEST)
        first_quest(play, window);
}