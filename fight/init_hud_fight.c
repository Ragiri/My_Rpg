/*
** EPITECH PROJECT, 2019
** init_hud_fight
** File description:
** init_hud_fight
*/

#include "my.h"
#include "struct.h"

static fight_hud_t *init_stat_hud(fight_hud_t *hud)
{
    hud->hp_ally = malloc(sizeof(sfSprite *) * (3 + 1));
    hud->hp_ally[3] = NULL;
    hud->mana = malloc(sizeof(sfSprite *) * (3 + 1));
    hud->mana[3] = NULL;
    hud->face = malloc(sizeof(sfSprite *) * (3 + 1));
    hud->face[3] = NULL;
    for (int i = 0; i != 3; i += 1) {
        hud->hp_ally[i] = sprite_create("ressources/assets/hp.png",
        (sfIntRect){0, 0, 441, 422}, vectorf(i * 350 + 1040, 850));
        sfSprite_setScale(hud->hp_ally[i], vectorf(0.4, 0.4));
        hud->mana[i] = sprite_create("ressources/assets/mana.png",
        (sfIntRect){0, 0, 626, 46}, vectorf(i * 350 + 890, 975));
        sfSprite_setScale(hud->mana[i], vectorf(0.4, 0.4));
        hud->face[i] = sprite_create("ressources/assets/face.png",
        (sfIntRect){i * 100, 0, 100, 100}, vectorf(i * 350 + 1020, 820));
        sfSprite_setScale(hud->face[i], vectorf(2, 2));
    }
    return (hud);
}

static fight_hud_t *init_action_hud(fight_hud_t *hud)
{
    sfFont *font = sfFont_createFromFile("ressources/font/makisupa.ttf");

    hud->command = sprite_create("ressources/assets/action.png",
    (sfIntRect){0, 0, 180, 153}, vectorf(0, 1080 - 300 + 50));
    sfSprite_setScale(hud->command, vectorf(1.3, 1.3));
    hud->comm_name = malloc(sizeof(*hud->comm_name) * 4);
    hud->comm_name[0] = txt_create(20, (sfColor){220, 220, 220, 255},
    vectorf(30, 1080 - 300 + 46 + 50), "Attack");
    hud->comm_name[1] = txt_create(20, (sfColor){220, 220, 220, 255},
    vectorf(30, 1080 - 300 + 85 + 50), "Spells");
    hud->comm_name[2] = txt_create(20, (sfColor){220, 220, 220, 255},
    vectorf(30, 1080 - 300 + 124 + 50), "Objects");
    hud->comm_name[3] = txt_create(20, (sfColor){220, 220, 220, 255},
    vectorf(30, 1080 - 300 + 163 + 50), "Run !");
    for (int i = 0; i != 4; i += 1)
        sfText_setFont(hud->comm_name[i], font);
    hud->select = sprite_create("ressources/assets/action2.png",
    (sfIntRect){0, 0, 234, 74}, vectorf(0, 1080 - 300 + 50));
    sfSprite_setScale(hud->select, vectorf(1.3, 1.3));
    return (hud);
}

fight_t *init_hud_fight(fight_t *fight)
{
    fight->hud = malloc(sizeof(*fight->hud));
    fight->hud = init_stat_hud(fight->hud);
    fight->hud = init_action_hud(fight->hud);
    return (fight);
}
